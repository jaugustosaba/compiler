#ifndef DFA_H_
#define DFA_H_

#include <string>
#include <vector>
#include <memory>
#include <unordered_map>

#include "action.h"

namespace lexing {

struct DfaState {
	size_t id;
	bool isFinal;
	ActionPtr action;
	std::unordered_map<int, DfaState*> transitions;
};

typedef std::unique_ptr<DfaState> DfaStatePtr;

struct Dfa {
	DfaState* root;
	std::vector<DfaStatePtr> states;

	inline DfaState* createState() {
		DfaStatePtr ptr(new DfaState{
			states.size(),
			false
		});
		auto p = ptr.get();
		states.push_back(std::move(ptr));
		return p;
	}
};

}

#endif /* DFA_H_ */
