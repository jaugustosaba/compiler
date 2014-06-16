#ifndef MODULE_H_
#define MODULE_H_

#include "Decls.h"
#include "Ident.h"
#include "StmtList.h"
#include "SymbolTable.h"

namespace frontend {

struct Module : public Node {
	Ident        id;
	Decls        decls;
	StmtList     stmts;
	SymbolTable  st;
};

typedef std::unique_ptr<Module> ModulePtr;

} // namespace frontend

#endif /* MODULE_H_ */
