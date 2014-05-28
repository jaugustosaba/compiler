#ifndef NDFA_BUILDER_H_
#define NDFA_BUILDER_H_

#include "ndfa.h"
#include "spec.h"

namespace lexing {

Ndfa buildNdfa(const Spec &spec);

} // namespace lexing

#endif /* NDFA_BUILDER_H_ */
