#ifndef IDENT_H_
#define IDENT_H_

#include <memory>

#include "Text.h"

namespace frontend {

struct Ident : public Text {
};

typedef std::unique_ptr<Ident> IdentPtr;

} // namespace frontend

#endif /* IDENT_H_ */
