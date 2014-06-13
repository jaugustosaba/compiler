#ifndef LEXER_H_
#define LEXER_H_

#include <istream>
#include <exception>

#include "Position.h"
#include "TokenType.h"

namespace frontend {

class LexError : public std::exception {
public:
	inline LexError() {
	}
	const char* what() const noexcept override;
	~LexError() noexcept override;
};

class Lexer {
	std::istream&   m_input;
	Position::UInt  m_line;
	Position::UInt  m_column;
	Position        m_from;
	Position        m_to;
	std::string     m_lexeme;
	TokenType       m_tt;
public:
	inline Lexer(std::istream &input)
		: m_input(input), m_line(1), m_column(1), m_from(),
		  m_to(), m_lexeme(), m_tt(TokenType::Eof)
	{
	}
	inline const Position& from() const {
		return m_from;
	}
	inline const Position& to() const {
		return m_to;
	}
	inline const std::string& lexeme() const {
		return m_lexeme;
	}
	inline TokenType peek() const {
		return m_tt;
	}
	void next();
private:
	inline int peekChar();
	inline void nextChar();
	void lexId();
	void lexInt();
};

} // namespace frontend

#endif /* LEXER_H_ */
