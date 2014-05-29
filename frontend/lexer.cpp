#include "lexer.h"
#include "lexer-helper.h"

namespace frontend {

namespace {

struct Semantic {
	Input&    input;
	TokenPtr  result;
	Position  start;

	inline void id(const std::string &lexeme) {
		result = newToken(TokenType::ID, lexeme);
	}
	inline void add(const std::string &lexeme) {
		result = newToken(TokenType::PLUS, lexeme);
	}
	inline void mul(const std::string &lexeme) {
		result = newToken(TokenType::TIMES, lexeme);
	}
	inline void pow(const std::string &lexeme) {
		result = newToken(TokenType::POW, lexeme);
	}
	inline void lt(const std::string &lexeme) {
		result = newToken(TokenType::LT, lexeme);
	}
private:
	inline TokenPtr newToken(TokenType type, const std::string &lexeme) {
		TokenPtr ptr(new Token(type, lexeme, start, input.position()));
		return std::move(ptr);
	}
};

} // anonymous namespace

void Input::next() {
	auto c = m_input.get();
	if (c == '\n') {
		m_line++;
		m_column = 1;
	} else {
		m_column++;
	}
}

void Lexer::next() {
	Semantic semantic{m_input};
	bool actionTriggered = false;
	while (!actionTriggered && (m_input.peek() != -1)) {
		semantic.start = m_input.position();
		actionTriggered = LexerHelper::lex(m_input, semantic);
	}
	if (actionTriggered) {
		m_buffer = semantic.result;
	} else {
		m_buffer = TokenPtr(new Token(TokenType::Eof, "", m_input.position(), m_input.position()));
	}
}

} // namespace frontend



