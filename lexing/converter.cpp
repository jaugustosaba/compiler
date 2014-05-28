#include <set>
#include <map>

#include "converter.h"

namespace lexing {

namespace {

struct Converter {
	Ndfa&  ndfa;
	Dfa&   dfa;

	void convert() {
        simplifyEmptyTransitions();
        unifyMultipleTargets();
        buildDfa();
	}
private:
	void buildDfa() {
        std::unordered_map<NdfaState*, DfaState*> map;
        for (auto state : getReachableStates()) {
        	auto dfaState = dfa.createState();
			map[state] = dfaState;
			if (state == ndfa.root) {
				dfa.root = dfaState;
			}
        }
        for (const auto &statepair : map) {
        	auto ndfaState = statepair.first;
            auto dfaState = statepair.second;
            for (const auto &tspair : ndfaState->transitions) {
                auto symbol = tspair.first;
                auto dfaNextState = map[*tspair.second.begin()];
                dfaState->transitions[symbol] = dfaNextState;
            }
            if (ndfaState->isFinal) {
            	dfaState->isFinal = true;
            	dfaState->action = ndfaState->action;
            }
        }
	}
    bool copyStateBehaviour(NdfaState* dest, NdfaState* src) {
        bool destUpdated = false;
        for (const auto &pair : src->transitions) {
            auto &nextStates = dest->transitions[pair.first];
            for (auto state : pair.second) {
                if (nextStates.insert(state).second) {
                    destUpdated = true;
                }
            }
        }
        if (src->isFinal && (!dest->isFinal || (dest->action->priority < src->action->priority))) {
            dest->isFinal = true;
            dest->action = src->action;
        }
        return destUpdated;
    }
    void simplifyEmptyTransitions() {
        bool updated;
        do {
            updated = false;
            for (auto &state : ndfa.states) {
                auto it = state->transitions.find(EmptySymbol);
                if (it != state->transitions.end()) {
                	NdfaStateSet nextStates(it->second.begin(), it->second.end());
                    for (auto nextState : nextStates) {
                        if (copyStateBehaviour(state.get(), nextState)) {
                            updated = true;
                        }
                    }
                }
            }
        } while (updated);
        for (auto &state : ndfa.states) {
            state->transitions.erase(EmptySymbol);
        }
    }
    void unifyMultipleTargets() {
        typedef std::set<NdfaState*> OrdStateSet;
        typedef std::map<OrdStateSet, NdfaState*> OrdStateMap;

        OrdStateMap stateMap;
        for (size_t i=0; i < ndfa.states.size(); ++i) {
        	auto state = ndfa.states[i].get();
            std::unordered_set<int> symbols;
            for (const auto &pair : state->transitions) {
                symbols.insert(pair.first);
            }
            for (auto symbol : symbols) {
                auto &nextStates = state->transitions[symbol];
                if (nextStates.size() > 1) {
                    OrdStateSet ordNextStates(nextStates.begin(), nextStates.end());
                    auto it = stateMap.find(ordNextStates);
                    if (it != stateMap.end()) {
                        nextStates.clear();
                        nextStates.insert(it->second);
                    } else {
                        auto newState = ndfa.createState();
                        for (auto nextState : nextStates) {
                            copyStateBehaviour(newState, nextState);
                        }
                        stateMap[std::move(ordNextStates)] = newState;
                        nextStates.clear();
                        nextStates.insert(newState);
                    }
                }
            }
        }
    }
    NdfaStateSet getReachableStates() const {
        NdfaStateSet reachable;
        NdfaStateSet frontier = { ndfa.root };
        while (!frontier.empty()) {
            auto state = *frontier.begin();
            frontier.erase(frontier.begin());
            reachable.insert(state);
            for (const auto &pair : state->transitions) {
                for (auto nextState : pair.second) {
                    if (reachable.find(nextState) == reachable.end()) {
                        frontier.insert(nextState);
                    }
                }
            }
        }
        return reachable;
    }
};

} // anonymous namespace

Dfa convert(Ndfa &ndfa) {
	Dfa dfa;
	Converter converter{ndfa, dfa};
	converter.convert();
	return dfa;
}

} // namespace lexing
