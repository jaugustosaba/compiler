#ifndef BOOLEXPR_H_
#define BOOLEXPR_H_

#include "Expr.h"

namespace frontend {

struct BoolExpr : public Expr {
};

typedef std::unique_ptr<BoolExpr> BoolExprPtr;

} // namespace frontend

#endif /* BOOLEXPR_H_ */
