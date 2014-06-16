#ifndef FPARAM_H_
#define FPARAM_H_

#include "Decl.h"
#include "Var.h"

namespace frontend {

struct FParam : public Var {
	bool isVar;
};

typedef std::unique_ptr<FParam> FParamPtr;

} // namespace frontend

#endif /* FPARAM_H_ */
