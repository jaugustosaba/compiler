#ifndef DECLS_H_
#define DECLS_H_

#include <vector>
#include <memory>

namespace frontend {

struct Var;
struct Procedure;

struct Decls {
	std::vector<std::unique_ptr<Var>> vars;
	std::vector<std::unique_ptr<Procedure>> procedures;

	inline Decls()
		: vars(), procedures()
	{
	}
};

} // namespace frontend

#endif /* DECLS_H_ */
