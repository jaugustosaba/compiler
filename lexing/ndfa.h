#ifndef NDFA_H_
#define NDFA_H_

#include <memory>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <string>

#include "action.h"

namespace lexing {

struct NdfaState;

typedef std::unordered_set<NdfaState*> NdfaStateSet;

const int EmptySymbol = 0;

struct NdfaState {
	size_t  id;
	bool    isFinal;
	ActionPtr action;
	std::unordered_map<int, NdfaStateSet> transitions;
};

typedef std::unique_ptr<NdfaState> NdfaStatePtr;

struct Ndfa {
	NdfaState* root;
	std::vector<NdfaStatePtr> states;

	inline NdfaState* createState() {
		NdfaStatePtr ptr(new NdfaState{
			states.size(),
			false
		});
		auto p = ptr.get();
		states.push_back(std::move(ptr));
		return p;
	}
};

} // namespace lexing

#endif /* NDFA_H_ */
