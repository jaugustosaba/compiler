#ifndef STMT_H_
#define STMT_H_

#include <memory>

#include "Node.h"

namespace frontend {

struct Stmt : public Node {

};

typedef std::unique_ptr<Stmt> StmtPtr;

} // namespace frontend

#endif /* STMT_H_ */
