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
	const size_t KEYWORD_COUNT = 19;
	const static Keyword KEYWORDS[KEYWORD_COUNT] = {
		{"module", TokenType::Module},
		{"if", TokenType::If},
		{"then", TokenType::Then},
		{"else", TokenType::Else},
		{"elseif", TokenType::Elseif},
		{"while", TokenType::While},
		{"do", TokenType::Do},
		{"end", TokenType::End},
		{"var", TokenType::Var},
		{"not", TokenType::Not},
		{"or", TokenType::Or},
		{"and", TokenType::And},
		{"div", TokenType::Div},
		{"mod", TokenType::Mod},
		{"true", TokenType::True},
		{"false", TokenType::False},
		{"procedure", TokenType::Procedure},
		{"return", TokenType::Return},
		{"begin", TokenType::Begin}
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
	switch (c) {
	case -1:
		m_buffer = TokenType::Eof;
		break;
	case ';':
		m_buffer = TokenType::Semi;
		nextChar();
		break;
	case '.':
		m_buffer = TokenType::Dot;
		nextChar();
		break;
	case ',':
		m_buffer = TokenType::Comma;
		nextChar();
		break;
	case '=':
		m_buffer = TokenType::Eq;
		nextChar();
		break;
	case '<':
		nextChar();
		c = peekChar();
		if (c == '>') {
			nextChar();
			m_buffer = TokenType::Ne;
		} else if (c == '=') {
			nextChar();
			m_buffer = TokenType::Le;
		} else {
			m_buffer = TokenType::Lt;
		}
		break;
	case '>':
		nextChar();
		c = peekChar();
		if (c == '=') {
			nextChar();
			m_buffer = TokenType::Ge;
		} else {
			m_buffer = TokenType::Gt;
		}
		break;
	case ':':
		nextChar();
		c = peekChar();
		if (c == '=') {
			nextChar();
			m_buffer = TokenType::Assign;
		} else {
			m_buffer = TokenType::Colon;
		}
		break;
	case '(':
		m_buffer = TokenType::LParen;
		nextChar();
		break;
	case ')':
		m_buffer = TokenType::RParen;
		nextChar();
		break;
	case '+':
		m_buffer = TokenType::Add;
		nextChar();
		break;
	case '-':
		m_buffer = TokenType::Sub;
		nextChar();
		break;
	case '*':
		m_buffer = TokenType::Mul;
		nextChar();
		break;
	case '/':
		m_buffer = TokenType::RealDiv;
		nextChar();
		break;
	default:
		if (std::isdigit(c)) {
			lexInt();
		} else {
			lexId();
		}
	}
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
	m_buffer = lookupKeyword(lexeme);
	if (m_buffer == TokenType::Id) {
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
	m_buffer = TokenType::Int;
}

} // namespace frontend



