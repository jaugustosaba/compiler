#ifndef PROCEDURE_H_
#define PROCEDURE_H_

#include "Node.h"
#include "Ident.h"
#include "Decls.h"

namespace frontend {

struct FParam;

struct Procedure : public Node {
	typedef std::unique_ptr<FParam> FParamPtr;
	typedef std::vector<FParamPtr> FParamVect;

	Ident       id;
	FParamVect  fparams;
	Decls       decls;

	Procedure();
	~Procedure();
};

} // namespace frontend

#endif /* PROCEDURE_H_ */
