#ifndef ACTION_H_
#define ACTION_H_

#include <string>
#include <memory>

namespace lexing {

struct Action {
	int          priority;
	std::string  name;
};

typedef std::shared_ptr<Action> ActionPtr;

} // namespace lexing

#endif /* ACTION_H_ */
