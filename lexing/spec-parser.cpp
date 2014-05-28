#include <cctype>
#include <sstream>
#include <limits>

#include "spec-parser.h"
#include "regex-parser.h"

namespace lexing {

namespace {

typedef typename BadSpec::PosType PosType;

enum class Token {
    Eof,
    Separator,
    Option,
    Arrow,
    Semi,
    String,
    Id,
};

inline
const char* tokenName(Token token) {
    switch (token) {
        case Token::Eof:
            return "Eof";
        case Token::Separator:
            return "Separator";
        case Token::Option:
        	return "Option";
        case Token::Arrow:
            return "Arrow";
        case Token::Semi:
            return "Semi";
        case Token::String:
            return "String";
        case Token::Id:
            return "Id";
        default:
            throw std::invalid_argument("unknown token");
    }
}

inline
std::ostream& operator<<(std::ostream &out, Token token) {
    return out << tokenName(token);
}

class Input {
    std::istream&    m_input;
    PosType          m_line;
    PosType          m_column;
    int              m_buffer;
public:
    Input(std::istream &input)
        : m_input(input), m_line(1), m_column(1), m_buffer(m_input.get())
    {
    }
    PosType line() const {
        return m_line;
    }
    PosType column() const {
        return m_column;
    }
    int peek() {
        return m_buffer;
    }
    void next() {
        m_buffer = m_input.get();
        if (m_buffer == '\n') {
            m_line++;
            m_column = 1;
        } else {
            m_column++;
        }
    }
};

class Lexer {
    Input        m_input;
    Token        m_token;
    std::string  m_lexeme;
public:
    Lexer(std::istream &input)
        : m_input(input), m_token(Token::Eof), m_lexeme()
    {
        next();
    }
    inline
    Token token() const {
        return m_token;
    }
    inline
    const std::string& lexeme() const {
        return m_lexeme;
    }
    inline
    Input& input() {
        return m_input;
    }
    void next() {
        int c = m_input.peek();
        while ((c != -1) && isspace(c)) {
            m_input.next();
            c = m_input.peek();
        }
        switch (c) {
            case -1:
                m_lexeme.clear();
                m_token = Token::Eof;
                break;
            case ';':
                m_input.next();
                m_lexeme.clear();
                m_token = Token::Semi;
                break;
            case '~':
                m_input.next();
                m_lexeme.clear();
                c = m_input.peek();
                if (c != '>') {
                    lexerError("expecting Arrow");
                }
                m_input.next();
                m_token = Token::Arrow;
                break;
            case '%':
                m_input.next();
                m_lexeme.clear();
                c = m_input.peek();
                if (c == '%') {
                	m_input.next();
                	m_token = Token::Separator;
                } else if (isalpha(c)) {
                	m_lexeme = readWord();
                	m_token = Token::Option;
                } else {
                	lexerError("expecting Separator");
                }
                break;
            case '"':
                m_lexeme = readString();
                m_token = Token::String;
                break;
            default:
                if (!isalpha(c)) {
                    lexerError("expecting Id");
                }
                m_lexeme = readWord();
                m_token = Token::Id;
                break;
        }
    }
private:
    std::string readString() {
        std::ostringstream str;
        m_input.next();
        int c = m_input.peek();
        while ((c != -1) && (c != '"')) {
            if (c == '\\') {
                m_input.next();
                c = m_input.peek();
                if (c != '"') {
                	str << '\\';
                }
            }
            str << char(c);
            m_input.next();
            c = m_input.peek();
        }
        if (c == -1) {
            lexerError("expecting end of string");
        }
        m_input.next();
        return str.str();
    }
    std::string readWord() {
        std::ostringstream str;
        str << char(m_input.peek());
        m_input.next();
        int c = m_input.peek();
        while (isalnum(c)) {
            str << char(c);
            m_input.next();
            c = m_input.peek();
        }
        return str.str();
    }
    void lexerError(const std::string &message) {
        throw BadSpec(message, m_input.line(), m_input.column());
    }
};

class Parser {
	Spec& m_spec;
    Lexer m_lexer;
public:
    Parser(Spec &spec, std::istream &input)
        : m_spec(spec), m_lexer(input)
    {
    }
    void parse() {
        doParse();
    }
private:
    void doParse() {
        consume(Token::Separator);
        while (m_lexer.token() != Token::Separator) {
        	std::string option = consume(Token::Option);
        	std::string param = consume(Token::Id);
        	consume(Token::Semi);
        	if (option == "class") {
        		m_spec.options.className = param;
        	} else if (option == "namespace") {
        		m_spec.options.nameSpace = param;
        	} else if (option == "guard") {
        		m_spec.options.guard = param;
        	} else {
        		std::ostringstream out;
        		out << "unknown option '" << option << "'";
        		syntaxError(out.str());
        	}
        }
        m_lexer.next();
        int priority = std::numeric_limits<int>::max();
        while (m_lexer.token() != Token::Eof) {
            std::string regex = consume(Token::String);
            std::string action;
            if (m_lexer.token() == Token::Arrow) {
                m_lexer.next();
                action = consume(Token::Id);
            }
            consume(Token::Semi);
            pushRule(regex, action, priority--);
        }
    }
    void pushRule(const std::string &regex, const std::string &id, int priority) {
        try {
			ActionPtr action(new Action);
			action->name = id;
			action->priority = priority;
        	Rule rule;
        	rule.regex = parseRegex(regex);
        	rule.action = std::move(action);
        	m_spec.rules.push_back(std::move(rule));
        } catch (const BadRegex &regex) {
        	std::string message(regex.what());
            syntaxError(message);
        }
    }
    std::string consume(Token token) {
        if (m_lexer.token() != token) {
            syntaxError({token});
        }
        std::string lexeme = m_lexer.lexeme();
        m_lexer.next();
        return lexeme;
    }
    void syntaxError(std::initializer_list<Token> expecting) {
        std::ostringstream out;
        out << "expecting ";
        size_t n = expecting.size();
        for (Token token : expecting) {
            out << token;
            if (--n > 0) {
                out << ", ";
            }
        }
        out << " but found " << m_lexer.token();
        syntaxError(out.str());
    }
    void syntaxError(const std::string &message) {
        throw BadSpec(message, m_lexer.input().line(), m_lexer.input().column());
    }
};

} // anonymous namespace

Spec parseSpec(std::istream &input) {
	Spec spec;
	Parser parser(spec, input);
	parser.parse();
	return spec;
}

} // namespace lexing



