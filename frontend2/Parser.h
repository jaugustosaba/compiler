#ifndef PARSER_H_
#define PARSER_H_

#include "Lexer.h"

namespace frontend {

class SyntaxError : public std::exception {
public:
	inline SyntaxError() {
	}
	const char* what() const noexcept override;
	~SyntaxError() noexcept override;
};

class Parser {
	Lexer m_lexer;
public:
	inline Parser(std::istream &input)
		: m_lexer(input)
	{
	}
	void parse();
private:
	void parseModule();
	void parseDecls();
	void parseVars();
	void parseIdentList();
	void parseProcs();
	void parseFParams();
	void parseFParam();
	void parseStmts();
	void parseIf();
	void parseWhile();
	void parseReturn();
	void parseDesignator();
	void parseAssign();
	void parseCall();
	void parseAParams();
	void parseExpr();
	void parseAddExpr();
	void parseMulExpr();
	void parseSingleExpr();
	void consume(TokenType tt);
	void syntaxError(std::initializer_list<TokenType> expecting);
};

} // namespace frontend

#endif /* PARSER_H_ */
