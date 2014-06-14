#ifndef TEXT_H_
#define TEXT_H_

#include <string>

#include "Node.h"

namespace frontend {

struct Text : public Node {
	std::string  value;
protected:
	Text() = default;
};

} // namespace frontend

#endif /* TEXT_H_ */
