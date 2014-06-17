#ifndef CALL_H_
#define CALL_H_

#include <vector>
#include <memory>

#include "Expr.h"
#include "Designator.h"

namespace frontend {

struct Call {
	typedef std::vector<ExprPtr> ExprVect;

	DesignatorPtr  designator;
	ExprVect       aparams;
};

} // namespace frontend

#endif /* CALL_H_ */
