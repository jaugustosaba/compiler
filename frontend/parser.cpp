#include "parser.h"
#include "lexer.h"

namespace frontend {

namespace {

typedef ParserHelper::Symbol<TokenPtr, ExprPtr> Symbol;

struct Semantic {
	typedef ExprPtr Result;
	/*
	expr : expr PLUS expr  ~> {add}
	     | expr TIMES expr ~> {times}
	     | expr POW expr   ~> {power}
	     | expr LT expr    ~> {compare}
	     | ID              ~> {id} */

	inline
	ExprPtr add(const Symbol &expr1, const Symbol &plus, const Symbol &expr2) {
		return ExprPtr(new BinExpr(BinOp::Add, expr1.result(), expr2.result()));
	}
	ExprPtr times(const Symbol &expr1, const Symbol &times, const Symbol &expr2) {
		return ExprPtr(new BinExpr(BinOp::Mul, expr1.result(), expr2.result()));
	}
	ExprPtr power(const Symbol &expr1, const Symbol &power, const Symbol &expr2) {
		return ExprPtr(new BinExpr(BinOp::Pow, expr1.result(), expr2.result()));
	}
	ExprPtr compare(const Symbol &expr1, const Symbol &lt, const Symbol &expr2) {
		return ExprPtr(new BinExpr(BinOp::Lt, expr1.result(), expr2.result()));
	}
	ExprPtr id(const Symbol &id) {
		return ExprPtr(new IdExpr(id.token()->lexeme()));
	}
};

} // anonymous namespace

ExprPtr parse(std::istream &input) {
	Lexer lexer(input);
	lexer.next();
	Semantic semantic;
	return ParserHelper::parse(lexer, semantic);
}

} // namespace frontend



