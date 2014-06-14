#ifndef PROCEDURE_H_
#define PROCEDURE_H_

#include "Ident.h"
#include "Decls.h"
#include "FParam.h"
#include "StmtList.h"
#include "Node.h"

namespace frontend {

struct Procedure : public Node {
	typedef std::vector<FParamPtr> FParamVect;

	Ident       id;
	FParamVect  fparams;
	Decls       decls;
	StmtList    stmts;
};

} // namespace frontend

#endif /* PROCEDURE_H_ */
