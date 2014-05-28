#include "lalr.h"

namespace parsing {

namespace {

struct KernelSetComparator {
	inline bool operator()(const KernelSet* ks1, const KernelSet* ks2) const {
		if (ks1->size() != ks2->size()) {
			return false;
		}
		for (const Kernel &kernel : *ks1) {
			auto it = ks2->find(kernel);
			if (it == ks2->end()) {
				return false;
			}
		}
		return true;
	}
};

struct KernelSetHasher {
	inline size_t operator()(const KernelSet* ks) const {
		Kernel::Hasher hkern;
		size_t h = 1;
		for (const Kernel &kernel : *ks) {
			h += 17 * hkern(kernel);
		}
		return h;
	}
};

typedef std::unordered_map<
		KernelSet*,
		State*,
		KernelSetHasher,
		KernelSetComparator
> KernelStateMap;

typedef std::unordered_set<State*> StateSet;

typedef std::unordered_map<Symbol*, StatePtr> TransMap;

struct LALRBuilder {
	const Spec* spec;
	LALR* lalr;

	bool mergeStates(State *dest, const State *src) {
		bool updated = false;
		for (const auto &pair : src->items) {
			auto &lookaheads = dest->items[pair.first];
			auto n = lookaheads.size();
			lookaheads.insert(pair.second.begin(), pair.second.end());
			if (lookaheads.size() > n) {
				updated = true;
			}
		}
		return updated;
	}

	void build() {
		auto root = setupRootState();
		KernelStateMap map;
		StateSet frontier = { root };
		while (!frontier.empty()) {
			State *state = *frontier.begin();
			frontier.erase(frontier.begin());
			map[&state->kernels] = state;
			closure(state);
			for (auto &pair : computeTransitions(state)) {
				Symbol* symbol = pair.first;
				StatePtr &nextState = pair.second;
				State* ns = nextState.get();
				auto it = state->transitions.find(symbol);
				if (it == state->transitions.end()) {
					auto it2 = map.find(&nextState->kernels);
					if (it2 == map.end()) {
						map[&nextState->kernels] = ns;
						frontier.insert(ns);
						state->transitions[symbol] = ns;
						nextState->id = lalr->states.size();
						lalr->states.push_back(std::move(nextState));
					} else {
						State *existingState = it2->second;
						state->transitions[symbol] = existingState;
						if (mergeStates(existingState, ns)) {
							frontier.insert(existingState);
						}
					}
				} else {
					State *existingNextState = it->second;
					state->transitions[symbol] = existingNextState;
					if (mergeStates(existingNextState, ns)) {
						frontier.insert(existingNextState);
					}
				}
			}
		}
	}

	TransMap computeTransitions(State* state) {
		TransMap rs;
		for (const auto &pair : state->items) {
			const Kernel &kernel = pair.first;
			if (kernel.isReduction()) {
				continue;
			}
			Symbol *symbol = kernel.production->symbols[kernel.position];
			Kernel newKernel = { kernel.production, kernel.position+1 };
			State* nextState;
			auto it = rs.find(symbol);
			if (it == rs.end()) {
				StatePtr ptr(new State);
				nextState = ptr.get();
				rs[symbol] = std::move(ptr);
			} else {
				nextState = it->second.get();
			}
			nextState->kernels.insert(newKernel);
			nextState->items[newKernel] = pair.second;
		}
		return rs;
	}

	TokenSet computeLookaheads(const Kernel &kernel, const TokenSet &lookaheads) {
		TokenSet rs;
		auto i = kernel.position + 1;
		bool empty = true;
		for (; empty && (i < kernel.production->symbols.size()); i++) {
			empty = false;
			auto symbol = kernel.production->symbols[i];
			for (auto token : symbol->firstSet) {
				if (token == nullptr) {
					empty = true;
				} else {
					rs.insert(token);
				}
			}
		}
		if (empty) {
			rs.insert(lookaheads.begin(), lookaheads.end());
		}
		return rs;
	}

	void closure(State* state) {
		bool updated;
		do {
			ItemMap newItems;
			for (const auto &pair : state->items) {
				const Kernel &kernel = pair.first;
				if (kernel.isReduction()) {
					continue;
				}
				Symbol *symbol = kernel.production->symbols[kernel.position];
				Rule *rule = dynamic_cast<Rule*>(symbol);
				if (rule != nullptr) {
					auto looakeads = computeLookaheads(kernel, pair.second);
					for (auto &production : rule->productions) {
						Kernel newKernel = { production.get(), 0 };
						newItems[newKernel].insert(looakeads.begin(), looakeads.end());
					}
				}
			}
			updated = false;
			for (const auto &pair : newItems) {
				auto it = state->items.find(pair.first);
				if (it == state->items.end()) {
					updated = true;
					state->items[pair.first] = pair.second;
				} else {
					auto n = it->second.size();
					it->second.insert(pair.second.begin(), pair.second.end());
					if (it->second.size() > n) {
						updated = true;
					}
				}
			}
		} while (updated);
	}

	State* createState() {
		auto id = lalr->states.size();
		StatePtr ptr(new State);
		State* p = ptr.get();
		p->id = id;
		lalr->states.push_back(std::move(ptr));
		return p;
	}

	State* setupRootState() {
		auto rootprod = setupRootProduction();
		auto state = createState();
		Kernel rootKernel = {rootprod, 0};
		state->kernels.insert(rootKernel);
		state->items[rootKernel].insert(spec->eof);
		lalr->root = state;
		return state;
	}

	Production* setupRootProduction() {
		ProductionPtr ptr(new Production{nullptr, {spec->root}, "", {}});
		Production* p = ptr.get();
		lalr->rootProduction = std::move(ptr);
		return p;
	}
};

} // anonymous namespace



LALR makeLALR(const Spec &spec) {
	LALR result;
	LALRBuilder builder{ &spec, &result };
	builder.build();
	return result;
}

} // namespace parsing
