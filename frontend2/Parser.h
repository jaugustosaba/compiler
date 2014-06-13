#ifndef PARSER_H_
#define PARSER_H_

#include <vector>
#include <memory>

#include "Lexer.h"

namespace frontend {

class Ident;
struct Module;
struct Decls;
struct Var;
struct Procedure;

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
	std::unique_ptr<Module> parseModule();
	void parseIdent(Ident &ident);
	void parseDecls(Decls &decls);
	void parseVars(std::vector<std::unique_ptr<Var>> &vars);
	void parseIdentList();
	void parseProcs(std::vector<std::unique_ptr<Procedure>> &procs);
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
