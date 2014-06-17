#ifndef IDENTLIST_H_
#define IDENTLIST_H_

#include <vector>
#include <memory>

#include "Node.h"
#include "Ident.h"

namespace frontend {


struct IdentList : public Node {
	typedef std::vector<IdentPtr> IdentVect;

	IdentVect  idents;
};

} // namespace frontend

#endif /* IDENTLIST_H_ */
