#ifndef BOOLEXPR_H_
#define BOOLEXPR_H_

#include "Expr.h"
#include "Text.h"

namespace frontend {

struct BoolExpr : public Text, public Expr {
};

typedef std::unique_ptr<BoolExpr> BoolExprPtr;

} // namespace frontend

#endif /* BOOLEXPR_H_ */
