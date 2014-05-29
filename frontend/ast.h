#ifndef AST_H_
#define AST_H_

#include <ostream>
#include <string>
#include <memory>

namespace frontend {

struct Expr {
	virtual void print(std::ostream &out) const = 0;
	virtual ~Expr() {
	}
};

typedef std::shared_ptr<Expr> ExprPtr;

struct IdExpr : public Expr {
	std::string id;

	inline IdExpr(const std::string &id)
		: id(id)
	{
	}
	void print(std::ostream &out) const override;
};

enum class BinOp {
	Add,
	Mul,
	Pow,
	Lt,
};

struct BinExpr : public Expr {
	BinOp    op;
	ExprPtr  left;
	ExprPtr  right;

	inline BinExpr(BinOp op, const ExprPtr &left, const ExprPtr &right)
		: op(op), left(left), right(right)
	{
	}
	void print(std::ostream &out) const override;
};

inline std::ostream& operator<<(std::ostream &out, const ExprPtr &expr) {
	expr->print(out);
	return out;
}

} // namespace frontend

#endif /* AST_H_ */
