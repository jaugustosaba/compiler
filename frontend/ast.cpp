#include "ast.h"

namespace frontend {

void IdExpr::print(std::ostream &out) const {
	out << id;
}

void BinExpr::print(std::ostream &out) const {
	out << "(";
	switch (op) {
	case BinOp::Add:
		out << "+ ";
		break;
	case BinOp::Lt:
		out << "< ";
		break;
	case BinOp::Mul:
		out << "* ";
		break;
	case BinOp::Pow:
		out << "^ ";
		break;
	}
	left->print(out);
	out << " ";
	right->print(out);
	out << ")";
}

} // namespace frontend



