#ifndef BINEXPR_H_
#define BINEXPR_H_

#include "Expr.h"

namespace frontend {

enum class BinOp {
	Eq,
	Ne,
	Lt,
	Le,
	Gt,
	Ge,
	Add,
	Sub,
	Mul,
	RealDiv,
	Div,
	Mod,
	And,
	Or
};

struct BinExpr : public Expr {
	BinOp   op;
	ExprPtr left;
	ExprPtr right;
};

typedef std::unique_ptr<BinExpr> BinExprPtr;

} // namespace frontend

#endif /* BINEXPR_H_ */
