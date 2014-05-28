#ifndef CONVERTER_H_
#define CONVERTER_H_

#include "ndfa.h"
#include "dfa.h"

namespace lexing {

Dfa convert(Ndfa &ndfa);

} // namespace lexing

#endif /* CONVERTER_H_ */
