#ifndef IFSTMT_H_
#define IFSTMT_H_

#include "StmtList.h"
#include "Expr.h"

namespace frontend {

struct Elseif : public Node {
	ExprPtr  condition;
	StmtList stmts;
};

typedef std::unique_ptr<Elseif> ElseifPtr;

struct IfStmt : public Stmt {
	typedef std::vector<ElseifPtr> ElseifVect;

	ExprPtr     condition;
	StmtList    stmts;
	ElseifVect  elseifs;
	StmtList    elseStmts;
};

typedef std::unique_ptr<IfStmt> IfStmtPtr;

} // namespace frontend

#endif /* IFSTMT_H_ */
