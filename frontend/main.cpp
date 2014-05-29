#include <iostream>
#include <sstream>

//#include "lexer.h"
#include "parser.h"

/*
inline std::ostream& operator<<(std::ostream& out, const frontend::Position &pos) {
	out << "(" << pos.line() << ", " << pos.column() << ")";
	return out;
}

inline std::ostream& operator<<(std::ostream& out, const frontend::TokenType type) {
	switch (type) {
	case frontend::TokenType::Eof:
		out << "Eof";
		break;
	case frontend::TokenType::ID:
		out << "ID";
		break;
	case frontend::TokenType::LT:
		out << "LT";
		break;
	case frontend::TokenType::PLUS:
		out << "PLUS";
		break;
	case frontend::TokenType::POW:
		out << "POW";
		break;
	case frontend::TokenType::TIMES:
		out << "TIMES";
		break;
	default:
		throw std::logic_error("bad token");
	}
	return out;
}

inline std::ostream& operator<<(std::ostream& out, const frontend::TokenPtr &tk) {
	out
		<< "Token(" << tk->type() << ", \"" << tk->lexeme() << "\", "
		<< tk->from() << ", " << tk->to() << ")";
	return out;

}
*/
const char* INPUT = R"(
xbc + k + a * x * y ^ z ^ w
)";

int main(int argc, char **argv) {
	std::istringstream input(INPUT);
/*
	frontend::Lexer lexer(input);
	lexer.next();
	while (lexer.peek() != frontend::TokenType::Eof) {
		std::cout << lexer.peekAsToken() << std::endl;
		lexer.next();
	}
*/
	auto expr = frontend::parse(input);
	std::cout << expr << std::endl;
	return EXIT_SUCCESS;
}
