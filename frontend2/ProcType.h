#ifndef PROCTYPE_H_
#define PROCTYPE_H_

#include <vector>

#include "Type.h"

namespace frontend {

struct FPType {
	bool         isVar;
	const Type*  type;
};

struct ProcType : public Type {
	std::vector<FPType>  fparams;
	const Type*          returnType;
};

} // namespace frontend

#endif /* PROCEDURETYPE_H_ */
