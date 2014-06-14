#ifndef NODE_H_
#define NODE_H_

#include "Position.h"

namespace frontend {

struct Node {
	Position from;
	Position to;

	virtual ~Node() {
	}
protected:
	Node() = default;
};

} // namespace frontend

#endif /* NODE_H_ */
