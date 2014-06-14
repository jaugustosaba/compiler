#ifndef RETURNSTMT_H_
#define RETURNSTMT_H_

#include "Expr.h"
#include "Stmt.h"

namespace frontend {

struct ReturnStmt : public Stmt {
	ExprPtr expr;
};

typedef std::unique_ptr<ReturnStmt> ReturnStmtPtr;

} // namespace frontend

#endif /* RETURNSTMT_H_ */
