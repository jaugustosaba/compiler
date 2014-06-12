#ifndef LEXER_H_
#define LEXER_H_

#include <istream>
#include <exception>

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
	std::istream&  m_input;
	size_t         m_line;
	size_t         m_column;
	std::string    m_lexeme;
	TokenType      m_buffer;
public:
	inline Lexer(std::istream &input)
		: m_input(input), m_line(1), m_column(1),
		  m_lexeme(), m_buffer(TokenType::Eof)
	{
	}
	inline TokenType peek() const {
		return m_buffer;
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
