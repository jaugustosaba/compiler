#ifndef PROCEDURE_H_
#define PROCEDURE_H_

#include "Decls.h"
#include "Ident.h"

namespace frontend {

struct Procedure {
	Ident id;
	Decls decls;

	inline Procedure()
		: id(), decls()
	{
	}
};

} // namespace frontend

#endif /* PROCEDURE_H_ */
