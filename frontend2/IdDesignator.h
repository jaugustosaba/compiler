#ifndef IDDESIGNATOR_H_
#define IDDESIGNATOR_H_

#include "Designator.h"
#include "Text.h"

namespace frontend {

struct IdDesignator : public Designator {
	std::string value;
};

typedef std::unique_ptr<IdDesignator> IdDesignatorPtr;

} // namespace frontend

#endif /* IDDESIGNATOR_H_ */
