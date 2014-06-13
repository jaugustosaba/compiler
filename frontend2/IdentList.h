#ifndef IDENTLIST_H_
#define IDENTLIST_H_

#include <vector>
#include <memory>

#include "Node.h"

namespace frontend {

struct Ident;

struct IdentList : public Node {
	typedef std::unique_ptr<Ident> IdentPtr;
	typedef std::vector<IdentPtr> IdentVect;

	IdentVect  idents;

	IdentList();
	~IdentList();
};

} // namespace frontend

#endif /* IDENTLIST_H_ */
