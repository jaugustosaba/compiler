#ifndef WHILESTMT_H_
#define WHILESTMT_H_

#include "Expr.h"
#include "StmtList.h"

namespace frontend {

struct WhileStmt : public Stmt {
	ExprPtr   condition;
	StmtList  stmts;
};

typedef std::unique_ptr<WhileStmt> WhileStmtPtr;

} // namespace frontend

#endif /* WHILESTMT_H_ */
