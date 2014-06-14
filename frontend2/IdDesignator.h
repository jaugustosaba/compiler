#ifndef IDDESIGNATOR_H_
#define IDDESIGNATOR_H_

#include "Designator.h"
#include "Ident.h"

namespace frontend {

struct IdDesignator : public Designator {
	Ident ident;
};

typedef std::unique_ptr<IdDesignator> IdDesignatorPtr;

} // namespace frontend

#endif /* IDDESIGNATOR_H_ */
