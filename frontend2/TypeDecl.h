#ifndef TYPEDECL_H_
#define TYPEDECL_H_

#include "Node.h"
#include "Decl.h"
#include "Type.h"

namespace frontend {

struct TypeDecl : public Node, public Decl {
	const Type *type;
};

} // namespace frontend

#endif /* TYPEDECL_H_ */
