#ifndef UNEXPR_H_
#define UNEXPR_H_

#include "Expr.h"

namespace frontend {

enum class UnOp {
	Not,
	Neg,
};

struct UnExpr : public Expr {
	UnOp    op;
	ExprPtr expr;
};

typedef std::unique_ptr<UnExpr> UnExprPtr;

} // namespace frontend

#endif /* UNEXPR_H_ */
