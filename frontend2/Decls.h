#ifndef DECLS_H_
#define DECLS_H_

#include <vector>
#include <memory>

#include "Node.h"

namespace frontend {

struct Var;
struct Procedure;

struct Decls : public Node {
	typedef std::unique_ptr<Var> VarPtr;
	typedef std::unique_ptr<Procedure> ProcedurePtr;

	typedef std::vector<VarPtr> VarVect;
	typedef std::vector<ProcedurePtr> ProcedureVect;

	VarVect        vars;
	ProcedureVect  procedures;

	~Decls();
};

} // namespace frontend

#endif /* DECLS_H_ */
