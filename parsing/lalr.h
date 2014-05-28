#ifndef LALR_H_
#define LALR_H_

#include <unordered_set>
#include <unordered_map>

#include "spec.h"

namespace parsing {

struct Kernel {
	Production* production;
	size_t position;

	struct Hasher {
		inline size_t operator()(const Kernel &kernel) const {
			std::hash<Production*> hptr;
			std::hash<size_t> hsizet;
			return hptr(kernel.production) + hsizet(kernel.position);
		}
	};

	inline bool isReduction() const {
		return position >= production->symbols.size();
	}

	inline bool operator==(const Kernel &other) const {
		return (production == other.production)
				&& (position == other.position);
	}
};

typedef std::unordered_set<Kernel, Kernel::Hasher> KernelSet;
typedef std::unordered_map<Kernel, TokenSet, Kernel::Hasher> ItemMap;

struct State {
	size_t id;
	KernelSet kernels;
	ItemMap items;
	std::unordered_map<Symbol*, State*> transitions;
};

typedef std::unique_ptr<State> StatePtr;

struct LALR {
	State* root;
	std::vector<StatePtr> states;
	ProductionPtr rootProduction;
};

LALR makeLALR(const Spec &spec);

} // namespace parsing

#endif /* LALR_H_ */
