#include "Parser.h"

namespace frontend {

const char* SyntaxError::what() const noexcept {
	return "syntax error";
}

SyntaxError::~SyntaxError() noexcept {
}

void Parser::parse() {
	m_lexer.next();
	parseModule();
}

void Parser::parseModule() {
	consume(TokenType::Module);
	consume(TokenType::Id);
	consume(TokenType::Semi);
	parseDecls();
	if (m_lexer.peek() == TokenType::Begin) {
		m_lexer.next();
		parseStmts();
	}
	consume(TokenType::End);
	consume(TokenType::Id);
	consume(TokenType::Dot);
}

void Parser::parseDecls() {
	parseVars();
	parseProcs();
}

void Parser::parseVars() {
	while (m_lexer.peek() == TokenType::Var) {
		m_lexer.next();
		while (m_lexer.peek() == TokenType::Id) {
			parseIdentList();
			consume(TokenType::Colon);
			consume(TokenType::Id);
			consume(TokenType::Semi);
		}
	}
}

void Parser::parseIdentList() {
	consume(TokenType::Id);
	while (m_lexer.peek() == TokenType::Comma) {
		m_lexer.next();
		consume(TokenType::Id);
	}
}

void Parser::parseProcs() {
	while (m_lexer.peek() == TokenType::Procedure) {
		m_lexer.next();
		consume(TokenType::Id);
		if (m_lexer.peek() == TokenType::LParen) {
			m_lexer.next();
			parseFParams();
			consume(TokenType::RParen);
		}
		if (m_lexer.peek() == TokenType::Colon) {
			m_lexer.next();
			consume(TokenType::Id);
		}
		consume(TokenType::Semi);
		if ((m_lexer.peek() != TokenType::Procedure)
			&& (m_lexer.peek() != TokenType::End))
		{
			parseDecls();
			consume(TokenType::Begin);
			parseStmts();
			consume(TokenType::End);
			consume(TokenType::Id);
			consume(TokenType::Semi);
		}
	}
}

void Parser::parseFParams() {
	parseFParam();
	while (m_lexer.peek() == TokenType::Semi) {
		m_lexer.next();
		parseFParam();
	}
}

void Parser::parseFParam() {
	if (m_lexer.peek() == TokenType::Var) {
		m_lexer.next();
	}
	parseIdentList();
	consume(TokenType::Colon);
	consume(TokenType::Id);
}

void Parser::parseStmts() {
	while (m_lexer.peek() != TokenType::End) {
		switch (m_lexer.peek()) {
		case TokenType::If:
			parseIf();
			break;
		case TokenType::While:
			parseWhile();
			break;
		case TokenType::Return:
			parseReturn();
			break;
		default:
			parseDesignator();
			if (m_lexer.peek() == TokenType::Assign) {
				parseAssign();
			} else {
				parseCall();
			}
		}
		consume(TokenType::Semi);
	}
}

void Parser::parseIf() {
	m_lexer.next();
	parseExpr();
	consume(TokenType::Then);
	parseStmts();
	while (m_lexer.peek() == TokenType::Elseif) {
		m_lexer.next();
		parseExpr();
		consume(TokenType::Then);
		parseStmts();
	}
	if (m_lexer.peek() == TokenType::Else) {
		m_lexer.next();
		parseStmts();
	}
	consume(TokenType::End);
}

void Parser::parseWhile() {
	m_lexer.next();
	parseExpr();
	consume(TokenType::Do);
	parseStmts();
	consume(TokenType::End);
}

void Parser::parseReturn() {
	m_lexer.next();
	if (m_lexer.peek() != TokenType::Semi) {
		parseExpr();
	}
}

void Parser::parseDesignator() {
	consume(TokenType::Id);
}

void Parser::parseAssign() {
	m_lexer.next();
	parseExpr();
}

void Parser::parseCall() {
	parseAParams();
}

void Parser::parseAParams() {
	if (m_lexer.peek() == TokenType::LParen) {
		m_lexer.next();
		if (m_lexer.peek() != TokenType::RParen) {
			parseExpr();
			while (m_lexer.peek() == TokenType::Comma) {
				m_lexer.next();
				parseExpr();
			}
		}
		m_lexer.next();
	}
}

void Parser::parseExpr() {
	parseAddExpr();
	switch (m_lexer.peek()) {
	case TokenType::Eq:
	case TokenType::Ne:
	case TokenType::Le:
	case TokenType::Lt:
	case TokenType::Ge:
	case TokenType::Gt:
		m_lexer.next();
		parseAddExpr();
		break;
	default:
		break;
	}
}

void Parser::parseAddExpr() {
	parseMulExpr();
	switch (m_lexer.peek()) {
	case TokenType::Add:
	case TokenType::Sub:
	case TokenType::Or:
		m_lexer.next();
		parseMulExpr();
		break;
	default:
		break;
	}
}

void Parser::parseMulExpr() {
	parseSingleExpr();
	switch (m_lexer.peek()) {
	case TokenType::Mul:
	case TokenType::RealDiv:
	case TokenType::Div:
	case TokenType::Mod:
	case TokenType::And:
		m_lexer.next();
		parseSingleExpr();
		break;
	default:
		break;
	}
}

void Parser::parseSingleExpr() {
	switch (m_lexer.peek()) {
	case TokenType::Not:
	case TokenType::Add:
	case TokenType::Sub:
		m_lexer.next();
		parseSingleExpr();
		break;
	case TokenType::LParen:
		m_lexer.next();
		parseExpr();
		consume(TokenType::RParen);
		break;
	case TokenType::Int:
		m_lexer.next();
		break;
	case TokenType::True:
	case TokenType::False:
		m_lexer.next();
		break;
	default:
		parseDesignator();
		parseAParams();
	}
}

void Parser::consume(TokenType tt) {
	auto tk = m_lexer.peek();
	if (tk != tt) {
		syntaxError({tt});
	}
	m_lexer.next();
}

void Parser::syntaxError(std::initializer_list<TokenType> expecting) {
	throw SyntaxError();
}

} // namespace frontend



