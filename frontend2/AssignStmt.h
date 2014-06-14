#ifndef ASSIGNSTMT_H_
#define ASSIGNSTMT_H_

#include "Expr.h"
#include "Stmt.h"
#include "Designator.h"

namespace frontend {

struct AssignStmt : public Stmt {
	DesignatorPtr  designator;
	ExprPtr        expr;
};

typedef std::unique_ptr<AssignStmt> AssignStmtPtr;

} // namespace frontend

#endif /* ASSIGNSTMT_H_ */
