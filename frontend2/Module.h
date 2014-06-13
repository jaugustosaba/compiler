#ifndef MODULE_H_
#define MODULE_H_

#include "Decls.h"
#include "Ident.h"

namespace frontend {

struct Module {
	Ident id;
	Decls decls;

	inline Module()
		: id(), decls()
	{
	}
};

} // namespace frontend

#endif /* MODULE_H_ */
