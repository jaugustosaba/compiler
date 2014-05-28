#ifndef ACTION_H_
#define ACTION_H_

#include <string>
#include <memory>

namespace lexing {

struct Action {
	int          priority;
	std::string  action;
};

typedef std::shared_ptr<Action> ActionPtr;

} // namespace lexing

#endif /* ACTION_H_ */
