#ifndef INTEXPR_H_
#define INTEXPR_H_

#include "Expr.h"

namespace frontend {

struct IntExpr : public Expr {

};

typedef std::unique_ptr<IntExpr> IntExprPtr;

} // namespace frontend

#endif /* INTEXPR_H_ */
