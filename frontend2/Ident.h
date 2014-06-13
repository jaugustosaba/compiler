#ifndef IDENT_H_
#define IDENT_H_

#include "Node.h"

namespace frontend {

struct Ident : public Node {
	Position     from;
	Position     to;
	std::string  text;
};

} // namespace frontend

#endif /* IDENT_H_ */
