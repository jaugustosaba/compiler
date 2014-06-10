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
	inline void ne(const std::string &lexeme) {
		result = newToken(TokenType::NE, lexeme);
	}
	inline void lt(const std::string &lexeme) {
		result = newToken(TokenType::LT, lexeme);
	}
	inline void le(const std::string &lexeme) {
		result = newToken(TokenType::LE, lexeme);
	}
	inline void gt(const std::string &lexeme) {
		result = newToken(TokenType::GT, lexeme);
	}
	inline void ge(const std::string &lexeme) {
		result = newToken(TokenType::GE, lexeme);
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
	inline void add(const std::string &lexeme) {
		result = newToken(TokenType::ADD, lexeme);
	}
	inline void sub(const std::string &lexeme) {
		result = newToken(TokenType::SUB, lexeme);
	}
	inline void mul(const std::string &lexeme) {
		result = newToken(TokenType::MUL, lexeme);
	}
	inline void realdiv(const std::string &lexeme) {
		result = newToken(TokenType::REALDIV, lexeme);
	}
	inline void div(const std::string &lexeme) {
		result = newToken(TokenType::DIV, lexeme);
	}
	inline void mod(const std::string &lexeme) {
		result = newToken(TokenType::MOD, lexeme);
	}
	inline void orr(const std::string &lexeme) {
		result = newToken(TokenType::OR, lexeme);
	}
	inline void andd(const std::string &lexeme) {
		result = newToken(TokenType::AND, lexeme);
	}
	inline void dot(const std::string &lexeme) {
		result = newToken(TokenType::DOT, lexeme);
	}
	inline void nott(const std::string &lexeme) {
		result = newToken(TokenType::NOT, lexeme);
	}
	inline void assign(const std::string &lexeme) {
		result = newToken(TokenType::ASSIGN, lexeme);
	}
	inline void intlit(const std::string &lexeme) {
		result = newToken(TokenType::INTLIT, lexeme);
	}
	inline void pointer(const std::string &lexeme) {
		result = newToken(TokenType::POINTER, lexeme);
	}
	inline void to(const std::string &lexeme) {
		result = newToken(TokenType::TO, lexeme);
	}
	inline void array(const std::string &lexeme) {
		result = newToken(TokenType::ARRAY, lexeme);
	}
	inline void of(const std::string &lexeme) {
		result = newToken(TokenType::OF, lexeme);
	}
	inline void deref(const std::string &lexeme) {
		result = newToken(TokenType::DEREF, lexeme);
	}
	inline void lsquare(const std::string &lexeme) {
		result = newToken(TokenType::LSQUARE, lexeme);
	}
	inline void rsquare(const std::string &lexeme) {
		result = newToken(TokenType::RSQUARE, lexeme);
	}
	inline void constt(const std::string &lexeme) {
		result = newToken(TokenType::CONST, lexeme);
	}
	inline void truee(const std::string &lexeme) {
		result = newToken(TokenType::TRUE, lexeme);
	}
	inline void falsee(const std::string &lexeme) {
		result = newToken(TokenType::FALSE, lexeme);
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
		m_buffer = TokenPtr(new Token(TokenType::EOFF, "", m_input.position(), m_input.position()));
	}
}

} // namespace frontend



