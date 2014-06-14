#ifndef CALLEXPR_H_
#define CALLEXPR_H_

#include "Expr.h"
#include "Call.h"

namespace frontend {

struct CallExpr : public Call, public Expr {

};

typedef std::unique_ptr<CallExpr> CallExprPtr;

} // namespace frontend

#endif /* CALLEXPR_H_ */
