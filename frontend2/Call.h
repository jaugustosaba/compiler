#ifndef CALL_H_
#define CALL_H_

#include <vector>
#include <memory>

#include "Expr.h"
#include "Designator.h"

namespace frontend {

struct Expr;

struct Call {
	typedef std::unique_ptr<Expr> ExprPtr;
	typedef std::vector<ExprPtr> ExprVect;

	DesignatorPtr  designator;
	ExprVect       aparams;

	~Call();
};

} // namespace frontend

#endif /* CALL_H_ */
