#ifndef PARSER_H_
#define PARSER_H_

#include <memory>

#include "Lexer.h"
#include "Module.h"

namespace frontend {

class SyntaxError : public std::exception {
public:
	inline SyntaxError() {
	}
	const char* what() const noexcept override;
	~SyntaxError() noexcept override;
};

class Parser {
	class Helper;

	Lexer m_lexer;
public:
	inline Parser(std::istream &input)
		: m_lexer(input)
	{
	}
	ModulePtr parse();
};

} // namespace frontend

#endif /* PARSER_H_ */
