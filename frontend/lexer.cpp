#include "lexer.h"
#include "lexer-helper.h"

namespace frontend {

namespace {

struct Semantic {
	Input&    input;
	TokenPtr  result;
	Position  start;

	inline void procedure(const std::string &lexeme) {
		result = newToken(TokenType::PROCEDURE, lexeme);
	}
	inline void function(const std::string &lexeme) {
		result = newToken(TokenType::FUNCTION, lexeme);
	}
	inline void module(const std::string &lexeme) {
		result = newToken(TokenType::MODULE, lexeme);
	}
	inline void begin(const std::string &lexeme) {
		result = newToken(TokenType::BEGIN, lexeme);
	}
	inline void end(const std::string &lexeme) {
		result = newToken(TokenType::END, lexeme);
	}
	inline void id(const std::string &lexeme) {
		result = newToken(TokenType::ID, lexeme);
	}
	inline void semi(const std::string &lexeme) {
		result = newToken(TokenType::SEMI, lexeme);
	}
	inline void type(const std::string &lexeme) {
		result = newToken(TokenType::TYPE, lexeme);
	}
	inline void record(const std::string &lexeme) {
		result = newToken(TokenType::RECORD, lexeme);
	}
	inline void eq(const std::string &lexeme) {
		result = newToken(TokenType::EQ, lexeme);
	}
	inline void colon(const std::string &lexeme) {
		result = newToken(TokenType::COLON, lexeme);
	}
	inline void var(const std::string &lexeme) {
		result = newToken(TokenType::VAR, lexeme);
	}
	inline void comma(const std::string &lexeme) {
		result = newToken(TokenType::COMMA, lexeme);
	}
	inline void lparen(const std::string &lexeme) {
		result = newToken(TokenType::LPAREN, lexeme);
	}
	inline void rparen(const std::string &lexeme) {
		result = newToken(TokenType::RPAREN, lexeme);
	}
	inline void iff(const std::string &lexeme) {
		result = newToken(TokenType::IF, lexeme);
	}
	inline void elsee(const std::string &lexeme) {
		result = newToken(TokenType::ELSE, lexeme);
	}
	inline void elseif(const std::string &lexeme) {
		result = newToken(TokenType::ELSEIF, lexeme);
	}
	inline void then(const std::string &lexeme) {
		result = newToken(TokenType::THEN, lexeme);
	}
	inline void whilee(const std::string &lexeme) {
		result = newToken(TokenType::WHILE, lexeme);
	}
	inline void doo(const std::string &lexeme) {
		result = newToken(TokenType::DO, lexeme);
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



