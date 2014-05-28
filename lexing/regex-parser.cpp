#include <sstream>
#include <limits>
#include <stdexcept>

#include "regex-parser.h"

namespace lexing {

namespace {

enum class Token {
    Eof,
    Star,
    Opt,
    Plus,
    Or,
    LParen,
    RParen,
    RBracket,
    LBracket,
    Sep,
    Caret,
    Char,
};

inline
const char* tokenName(Token token) {
    switch (token) {
        case Token::Eof:
            return "Eof";
        case Token::Star:
            return "Star";
        case Token::Opt:
            return "Opt";
        case Token::Plus:
            return "Plus";
        case Token::Or:
            return "Or";
        case Token::LParen:
            return "LParen";
        case Token::RParen:
            return "RParen";
        case Token::RBracket:
            return "RBracket";
        case Token::LBracket:
            return "RBracket";
        case Token::Sep:
            return "Sep";
        case Token::Caret:
            return "Caret";
        case Token::Char:
            return "Char";
        default:
            throw std::invalid_argument("unknown token");
    }
}

inline
std::ostream& operator<<(std::ostream& out, Token token) {
    return out << tokenName(token);
}

class Lexer {
    Token          m_token;
    std::istream&  m_input;
    char           m_lexeme;
public:
    Lexer(std::istream &input)
        : m_token(Token::Eof), m_input(input), m_lexeme(0)
    {
        next();
    }
    inline Token token() const {
        return m_token;
    }
    inline char lexeme() const {
        return m_lexeme;
    }
    inline std::istream& input() {
        return m_input;
    }
    void next() {
        m_lexeme = m_input.get();
        switch (m_lexeme) {
            case -1:
                m_token = Token::Eof;
                break;
            case '*':
                m_token = Token::Star;
                break;
            case '?':
                m_token = Token::Opt;
                break;
            case '+':
                m_token = Token::Plus;
                break;
            case '|':
                m_token = Token::Or;
                break;
            case '(':
                m_token = Token::LParen;
                break;
            case ')':
                m_token = Token::RParen;
                break;
            case '[':
                m_token = Token::LBracket;
                break;
            case ']':
                m_token = Token::RBracket;
                break;
            case '-':
                m_token = Token::Sep;
                break;
            case '\\':
                m_lexeme = m_input.get();
                if (m_lexeme == -1) {
                    throw BadRegex("unexpected eof", m_input.tellg());
                }
                switch (m_lexeme) {
                case 'n':
                	m_lexeme = '\n';
                	break;
                case 't':
                	m_lexeme = '\t';
                	break;
                case 'f':
                	m_lexeme = '\f';
                	break;
                case 'r':
                	m_lexeme = '\r';
                	break;
                }
                m_token = Token::Char;
                break;
            default:
                m_token = Token::Char;
        }
    }
};

class Parser {
    Lexer     m_lexer;
    RegexPtr  m_regex;
public:
    Parser(std::istream &input)
        : m_lexer(input), m_regex()
    {
    }
    void parse() {
        m_regex = parseOrRegex();
    }
    RegexPtr regex() const {
        return m_regex;
    }
private:
    typedef std::tuple<char, char>  RangeT;
    typedef std::vector<RangeT>     RangeVectT;

    bool stopOrRegex() {
        Token t = m_lexer.token();
        return (t == Token::Eof) || (t == Token::RParen);
    }
    RegexPtr parseOrRegex() {
        RegexPtr orRegex = parseCatRegex();
        while (!stopOrRegex()) {
            consume(Token::Or);
            RegexPtr right = parseCatRegex();
            orRegex = RegexPtr(new OrRegex(orRegex, right));
        }
        return orRegex;
    }
    bool stopCatRegex() {
        Token t = m_lexer.token();
        return (t == Token::Eof) || (t == Token::RParen) || (t == Token::Or);
    }
    RegexPtr parseCatRegex() {
        RegexPtr catRegex = parseSingleRegex();
        while (!stopCatRegex()) {
            RegexPtr right = parseSingleRegex();
            catRegex = RegexPtr(new CatRegex(catRegex, right));
        }
        return catRegex;
    }
    RegexPtr parseSingleRegex() {
        RegexPtr sregex = parseAtomRegex();
        switch (m_lexer.token()) {
            case Token::Star:
                m_lexer.next();
                sregex = RegexPtr(new StarRegex(sregex));
                break;
            case Token::Opt:
                m_lexer.next();
                sregex = RegexPtr(new OptRegex(sregex));
                break;
            case Token::Plus: {
                m_lexer.next();
                RegexPtr starregex(new StarRegex(sregex));
                sregex = RegexPtr(new CatRegex(sregex, starregex));
                break;
            }
            default:
            	break;
        }
        return sregex;
    }
    RegexPtr parseAtomRegex() {
        switch (m_lexer.token()) {
            case Token::Char: {
                char symbol = m_lexer.lexeme();
                m_lexer.next();
                return RegexPtr(new CharRegex(symbol));
            }
            case Token::LParen: {
                m_lexer.next();
                RegexPtr regex = parseOrRegex();
                consume(Token::RParen);
                return regex;
            }
            case Token::LBracket: {
                m_lexer.next();
                bool exclusion = false;
                if (m_lexer.token() == Token::Caret) {
                    m_lexer.next();
                    exclusion = true;
                }
                std::vector<RangeT> ranges;
                do {
                    ranges.push_back(parseRange());
                } while (m_lexer.token() != Token::RBracket);
                consume(Token::RBracket);
                return rangeRegex(exclusion, ranges);
            }
            default:
                syntaxError({Token::Char, Token::LParen, Token::LBracket});
        }
        return nullptr;
    }
    RegexPtr rangeRegex(bool exclusion, const RangeVectT &ranges) {
        std::unordered_set<char> symbols;
        if (exclusion) {
            const char minChar = std::numeric_limits<char>::min();
            const char maxChar = std::numeric_limits<char>::max();
            for (char c = minChar; c <= maxChar; ++c) {
                symbols.insert(c);
            }
            for (const RangeT &range : ranges) {
                char from = std::get<0>(range);
                char to = std::get<1>(range);
                for (char c = from; c <= to; ++c) {
                    symbols.erase(c);
                }
            }
        } else {
            for (const RangeT &range : ranges) {
                char from = std::get<0>(range);
                char to = std::get<1>(range);
                for (char c = from; c <= to; ++c) {
                    symbols.insert(c);
                }
            }
        }
        auto it = symbols.begin();
        RegexPtr regex(new CharRegex(*it));
        for (++it; it != symbols.end(); ++it) {
            RegexPtr symbolRegex(new CharRegex(*it));
            regex = RegexPtr(new OrRegex{regex, symbolRegex});
        }
        return regex;
    }
    RangeT parseRange() {
        char from = consume(Token::Char);
        char to = from;
        if (m_lexer.token() == Token::Sep) {
            m_lexer.next();
            to = consume(Token::Char);
        }
        return RangeT(from, to);
    }
    char consume(Token token) {
        if (token != m_lexer.token()) {
            syntaxError({token});
        }
        char lexeme = m_lexer.lexeme();
        m_lexer.next();
        return lexeme;
    }
    void syntaxError(const std::initializer_list<Token> expecting) {
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
        throw BadRegex(out.str(), m_lexer.input().tellg());
    }
};

} // anonymous namespace

RegexPtr parseRegex(std::istream &input) {
    Parser parser(input);
    parser.parse();
    return parser.regex();
}

RegexPtr parseRegex(const std::string &regex) {
    std::istringstream input(regex);
    return parseRegex(input);
}

} // namespace lexing
