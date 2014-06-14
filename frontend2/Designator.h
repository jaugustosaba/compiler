#ifndef DESIGNATOR_H_
#define DESIGNATOR_H_

#include <memory>

#include "Node.h"

namespace frontend {

struct Designator : public Node {

};

typedef std::unique_ptr<Designator> DesignatorPtr;

} // namespace frontend

#endif /* DESIGNATOR_H_ */
