#ifndef STMTLIST_H_
#define STMTLIST_H_

#include <vector>

#include "Node.h"
#include "Stmt.h"

namespace frontend {

struct StmtList : public Node {
	typedef std::vector<StmtPtr> StmtVect;

	StmtVect stmts;
};

} // namespace frontend

#endif /* STMTLIST_H_ */
