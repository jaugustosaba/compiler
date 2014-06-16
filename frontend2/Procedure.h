#ifndef PROCEDURE_H_
#define PROCEDURE_H_

#include "Ident.h"
#include "Decl.h"
#include "Decls.h"
#include "FParam.h"
#include "StmtList.h"
#include "Node.h"
#include "SymbolTable.h"

namespace frontend {

struct Procedure : public Node, public Decl {
	typedef std::vector<FParamPtr> FParamVect;

	Ident        id;
	FParamVect   fparams;
	Decls        decls;
	StmtList     stmts;
	SymbolTable  st;
};

} // namespace frontend

#endif /* PROCEDURE_H_ */
