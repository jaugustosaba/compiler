#ifndef CALLSTMT_H_
#define CALLSTMT_H_

#include "Stmt.h"
#include "Call.h"

namespace frontend {

struct CallStmt : public Call, public Stmt {

};

typedef std::unique_ptr<CallStmt> CallStmtPtr;

} // namespace frontend

#endif /* CALLSTMT_H_ */
