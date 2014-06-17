#ifndef VAR_H_
#define VAR_H_

#include "IdentList.h"
#include "Ident.h"
#include "Decl.h"

namespace frontend {

struct Var : public Node, public Decl {
	IdentList  identList;
	Ident      typeName;
};

} // namespace frontend

#endif /* VAR_H_ */
