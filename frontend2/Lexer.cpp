#include <sstream>
#include <cctype>

#include "Lexer.h"

namespace frontend {

namespace {

struct Keyword {
	const char*  id;
	TokenType    tt;
};

TokenType lookupKeyword(const std::string &id) {
	const size_t KEYWORD_COUNT = 17;
	const static Keyword KEYWORDS[KEYWORD_COUNT] = {
		{"MODULE", TokenType::Module},
		{"IF", TokenType::If},
		{"THEN", TokenType::Then},
		{"ELSE", TokenType::Else},
		{"ELSIF", TokenType::Elsif},
		{"WHILE", TokenType::While},
		{"DO", TokenType::Do},
		{"END", TokenType::End},
		{"VAR", TokenType::Var},
		{"OR", TokenType::Or},
		{"DIV", TokenType::Div},
		{"MOD", TokenType::Mod},
		{"TRUE", TokenType::True},
		{"FALSE", TokenType::False},
		{"PROCEDURE", TokenType::Procedure},
		{"RETURN", TokenType::Return},
		{"BEGIN", TokenType::Begin}
	};
	for (size_t i=0; i<KEYWORD_COUNT; ++i) {
		const auto &KEYWORD = KEYWORDS[i];
		if (id.compare(KEYWORD.id) == 0) {
			return KEYWORD.tt;
		}
	}
	return TokenType::Id;
}

} // anonymous namespace

const char* LexError::what() const noexcept {
	return "bad token";
}

LexError::~LexError() noexcept {
}

int Lexer::peekChar() {
	return m_input.peek();
}

void Lexer::nextChar() {
	auto c = m_input.get();
	if (c == '\n') {
		m_line++;
		m_column = 1;
	} else {
		m_column++;
	}
}

void Lexer::next() {
	auto c = peekChar();
	while (std::isspace(c)) {
		nextChar();
		c = peekChar();
	}
	m_lexeme.clear();
	m_from = m_to;
	switch (c) {
	case -1:
		m_tt = TokenType::Eof;
		break;
	case ';':
		m_tt = TokenType::Semi;
		nextChar();
		break;
	case '.':
		m_tt = TokenType::Dot;
		nextChar();
		break;
	case ',':
		m_tt = TokenType::Comma;
		nextChar();
		break;
	case '=':
		m_tt = TokenType::Eq;
		nextChar();
		break;
	case '#':
		m_tt = TokenType::Ne;
		nextChar();
		break;
	case '&':
		m_tt = TokenType::And;
		nextChar();
		break;
	case '~':
		m_tt = TokenType::Not;
		nextChar();
		break;
	case '<':
		nextChar();
		c = peekChar();
		if (c == '=') {
			nextChar();
			m_tt = TokenType::Le;
		} else {
			m_tt = TokenType::Lt;
		}
		break;
	case '>':
		nextChar();
		c = peekChar();
		if (c == '=') {
			nextChar();
			m_tt = TokenType::Ge;
		} else {
			m_tt = TokenType::Gt;
		}
		break;
	case ':':
		nextChar();
		c = peekChar();
		if (c == '=') {
			nextChar();
			m_tt = TokenType::Assign;
		} else {
			m_tt = TokenType::Colon;
		}
		break;
	case '(':
		m_tt = TokenType::LParen;
		nextChar();
		break;
	case ')':
		m_tt = TokenType::RParen;
		nextChar();
		break;
	case '+':
		m_tt = TokenType::Add;
		nextChar();
		break;
	case '-':
		m_tt = TokenType::Sub;
		nextChar();
		break;
	case '*':
		m_tt = TokenType::Mul;
		nextChar();
		break;
	case '/':
		m_tt = TokenType::RealDiv;
		nextChar();
		break;
	default:
		if (std::isdigit(c)) {
			lexInt();
		} else {
			lexId();
		}
	}
	m_to = Position(m_line, m_column, m_input.tellg());
}

void Lexer::lexId() {
	std::ostringstream sstr;
	auto c = peekChar();
	if (!std::isalpha(c)) {
		throw LexError();
	}
	sstr << char(c);
	nextChar();
	c = peekChar();
	while (std::isalnum(c)) {
		sstr << char(c);
		nextChar();
		c = peekChar();
	}
	auto lexeme = sstr.str();
	m_tt = lookupKeyword(lexeme);
	if (m_tt == TokenType::Id) {
		m_lexeme = lexeme;
	}
}

void Lexer::lexInt() {
	std::ostringstream sstr;
	auto c = peekChar();
	while (std::isdigit(c)) {
		sstr << char(c);
		nextChar();
		c = peekChar();
	}
	m_lexeme = sstr.str();
	m_tt = TokenType::Int;
}

} // namespace frontend



