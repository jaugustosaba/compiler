#ifndef EXPR_H_
#define EXPR_H_

#include <memory>

#include "Node.h"

namespace frontend {

struct Expr : public Node {
	typedef std::unique_ptr<Expr> ExprPtr;
};

} // namespace frontend

#endif /* EXPR_H_ */
