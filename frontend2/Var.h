#ifndef VAR_H_
#define VAR_H_

#include "IdentList.h"

namespace frontend {

struct Var : public Node {
	IdentList  identList;
	Ident      typeName;
};

} // namespace frontend

#endif /* VAR_H_ */
