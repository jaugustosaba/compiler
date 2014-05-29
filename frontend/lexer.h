#ifndef LEXER_H_
#define LEXER_H_

#include <istream>
#include <string>
#include <memory>

#include "parser-helper.h"

namespace frontend {

typedef ParserHelper::TokenType TokenType;

struct Position {
	typedef uint32_t PosType;

	inline Position()
		: m_line(),
		  m_column()
	{
	}
	inline Position(PosType line, PosType column)
		: m_line(line),
		  m_column(column)
	{
	}
	inline PosType line() const {
		return m_line;
	}
	inline PosType column() const {
		return m_column;
	}
private:
	PosType m_line;
	PosType m_column;
};

class Token {
	TokenType    m_type;
	std::string  m_lexeme;
	Position     m_from;
	Position     m_to;
public:
	inline
	Token(TokenType type,
		const std::string &lexeme,
		const Position &from,
		const Position &to)
		: m_type(type), m_lexeme(lexeme), m_from(from), m_to(to)
	{
	}
	inline TokenType type() const {
		return m_type;
	}
	inline const std::string& lexeme() const {
		return m_lexeme;
	}
	inline const Position& from() const {
		return m_from;
	}
	inline const Position& to() const {
		return m_to;
	}
};

typedef std::shared_ptr<Token> TokenPtr;

class Input {
	std::istream&      m_input;
	Position::PosType  m_line;
	Position::PosType  m_column;
public:
	inline Input(std::istream &input)
		: m_input(input), m_line(1), m_column(1)
	{
	}
	Input(const Input&) = delete;
	Input& operator=(const Input&) = delete;

	inline Position position() const {
		return Position(m_line, m_column);
	}
	inline int peek() const {
		return m_input.peek();
	}
	void next();
};

class Lexer {
	Input     m_input;
	TokenPtr  m_buffer;
public:
	inline
	Lexer(std::istream &input)
		: m_input(input),
		  m_buffer()
	{
	}
	Lexer(const Lexer&) = delete;
	Lexer& operator=(const Lexer&) = delete;

	inline
	TokenType peek() const {
		return m_buffer->type();
	}
	inline
	TokenPtr peekAsToken() const {
		return m_buffer;
	}
	void next();
};

}

#endif /* LEXER_H_ */
