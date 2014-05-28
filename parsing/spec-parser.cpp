#include <sstream>
#include <stdexcept>
#include <unordered_map>

#include "spec-parser.h"

namespace parsing {

namespace {

typedef SpecError::PosType PosType;

enum class TokenType {
    Eof,
    Colon,
    Semi,
    Pipe,
    Separator,
    Id,
    Option,
    Action,
    Arrow,
};

inline
const char* tokenName(TokenType type) {
    switch (type) {
        case TokenType::Eof:
            return "Eof";
        case TokenType::Colon:
            return "Colon";
        case TokenType::Semi:
            return "Semi";
        case TokenType::Pipe:
            return "Pipe";
        case TokenType::Separator:
            return "Separator";
        case TokenType::Id:
            return "Id";
        case TokenType::Option:
            return "Option";
        case TokenType::Action:
            return "Action";
        case TokenType::Arrow:
            return "Arrow";
        default:
            throw std::logic_error("unknown token");
    }
}

inline
std::ostream& operator<<(std::ostream &out, TokenType type) {
    return out << tokenName(type);
}

class Input {
    std::istream&  m_input;
    int            m_buffer;
    PosType        m_line;
    PosType        m_column;
public:
    inline
    Input(std::istream &input)
        : m_input(input), m_buffer(0), m_line(1), m_column(1)
    {
        next();
    }
    inline int peek() const {
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
    inline PosType line() const {
    	return m_line;
    }
    inline PosType column() const {
    	return m_column;
    }
};

struct Tk {
	TokenType    tokenType;
	std::string  lexeme;
	PosType      line;
	PosType      column;
};

typedef std::unique_ptr<Tk> TkPtr;

class Lexer {
    Input           m_input;
    TokenType       m_type;
    std::string     m_lexeme;
    PosType         m_line;
    PosType         m_column;
public:
    inline
    Lexer(std::istream &input)
        : m_input(input), m_type(), m_lexeme(),
          m_line(), m_column()
    {
        next();
    }
    inline
    TokenType peek() const {
        return m_type;
    }
    TkPtr peekAsToken() const {
    	TkPtr ptr(new Tk);
    	ptr->tokenType = m_type;
    	ptr->lexeme = m_lexeme;
    	ptr->line = m_line;
    	ptr->column = m_column;
    	return std::move(ptr);
    }
    inline
    const std::string& lexeme() const {
        return m_lexeme;
    }
    inline PosType line() const {
    	return m_line;
    }
    inline PosType column() const {
    	return m_column;
    }
    void next() {
        int c = m_input.peek();
        while (isspace(c)) {
            m_input.next();
            c = m_input.peek();
        }
        m_lexeme.clear();
        m_line = m_input.line();
        m_column = m_input.column();
        switch (c) {
        case -1:
            m_type = TokenType::Eof;
            break;
        case ':':
            m_input.next();
            m_type = TokenType::Colon;
            break;
        case ';':
            m_input.next();
            m_type = TokenType::Semi;
            break;
        case '%':
            m_input.next();
            if (m_input.peek() == '%') {
                m_input.next();
                m_type = TokenType::Separator;
            } else if (isalpha(m_input.peek())) {
                c = m_input.peek();
                m_input.next();
                m_lexeme = lexId(c);
                m_type = TokenType::Option;
            } else {
                lexError();
            }
            break;
        case '|':
            m_input.next();
            m_type = TokenType::Pipe;
            break;
        case '~':
            m_input.next();
            if (m_input.peek() != '>') {
                lexError();
            }
            m_input.next();
            m_type = TokenType::Arrow;
            break;
        case '{':
            m_input.next();
            c = m_input.peek();
            if (!isalpha(c)) {
                lexError();
            }
            m_input.next();
            m_lexeme = lexId(c);
            c = m_input.peek();
            if (c != '}') {
                lexError();
            }
            m_input.next();
            m_type = TokenType::Action;
            break;
        default:
            if (!isalpha(c)) {
                lexError();
            }
            m_input.next();
            m_lexeme = lexId(c);
            m_type = TokenType::Id;
        }
    }
private:
    std::string lexId(char alpha) {
        std::ostringstream lexeme;
        lexeme << alpha;
        int c = m_input.peek();
        while (isalnum(c) || (c == '_')) {
            lexeme << char(c);
            m_input.next();
            c = m_input.peek();
        }
        return lexeme.str();
    }
    inline void lexError() {
    	throw SpecError("bad word", m_line, m_column);
    }
};

struct RawOption {
	TkPtr               name;
	std::vector<TkPtr>  params;
};

typedef std::unique_ptr<RawOption> RawOptionPtr;

struct RawProduction {
	std::vector<TkPtr>  symbols;
	TkPtr               action;
};

typedef std::unique_ptr<RawProduction> RawProductionPtr;

struct RawRule {
	TkPtr                          name;
	std::vector<RawProductionPtr>  productions;
};

typedef std::unique_ptr<RawRule> RawRulePtr;

struct RawSpec {
	std::vector<RawOptionPtr>  options;
	std::vector<RawRulePtr>    rules;
};

class Parser {
    Lexer     m_lexer;
    RawSpec   m_rawSpec;
public:
    Parser(std::istream &input)
        : m_lexer(input)
    {
    }
    RawSpec parse() {
        parseRoot();
        return std::move(m_rawSpec);
    }
private:
    void parseRoot() {
        consume(TokenType::Separator);
        while (m_lexer.peek() != TokenType::Separator) {
            parseOption();
        }
        m_lexer.next();
        while (m_lexer.peek() != TokenType::Eof) {
            parseRule();
        }
    }
    void parseOption() {
    	RawOptionPtr option(new RawOption);
    	option->name = consumeAsToken(TokenType::Option);
        do {
        	option->params.push_back(consumeAsToken(TokenType::Id));
        } while (m_lexer.peek() != TokenType::Semi);
        m_lexer.next();
        m_rawSpec.options.push_back(std::move(option));
    }
    void parseRule() {
    	RawRulePtr rule(new RawRule);
    	rule->name = consumeAsToken(TokenType::Id);
        consume(TokenType::Colon);
        parseProductions(rule);
        consume(TokenType::Semi);
        m_rawSpec.rules.push_back(std::move(rule));
    }
    void parseProductions(const RawRulePtr &rule) {
        parseProduction(rule);
        while (m_lexer.peek() == TokenType::Pipe) {
            m_lexer.next();
            parseProduction(rule);
        }
    }
    void parseProduction(const RawRulePtr &rule) {
    	RawProductionPtr production(new RawProduction);
        while (m_lexer.peek() == TokenType::Id) {
        	production->symbols.push_back(m_lexer.peekAsToken());
            m_lexer.next();
        }
        if (m_lexer.peek() == TokenType::Arrow) {
            m_lexer.next();
            production->action = consumeAsToken(TokenType::Action);
        }
        rule->productions.push_back(std::move(production));
    }
    void consume(TokenType type) {
        if (m_lexer.peek() != type) {
            syntaxError({type});
        }
        m_lexer.next();
    }
    TkPtr consumeAsToken(TokenType type) {
        if (m_lexer.peek() != type) {
            syntaxError({type});
        }
        auto token = m_lexer.peekAsToken();
        m_lexer.next();
        return token;
    }
    void syntaxError(const std::initializer_list<TokenType> &expecting) {
        std::ostringstream out;
        out << "syntax error: expecting ";
        auto n = expecting.size();
        for (const auto &type : expecting) {
            out << type;
            if (--n > 0) {
                out << ", ";
            }
        }
        out << " but found " << m_lexer.peek();
        throw SpecError(out.str(), m_lexer.line(), m_lexer.column());
    }
};

class SpecBuilder {

	struct Hasher {
		size_t operator()(const TkPtr &token) const {
			std::hash<std::string> h;
			return h(token->lexeme);
		}
	};

	struct Comparator {
		bool operator()(const TkPtr &t1, const TkPtr &t2) const {
			return t1->lexeme == t2->lexeme;
		}
	};

    typedef std::unordered_map<
    		TkPtr,
    		Symbol*,
    		Hasher,
    		Comparator
    > SymbolMap;

    const RawSpec&  m_rawSpec;
    Spec&           m_spec;
    SymbolMap       m_symbolMap;
    TkPtr           m_root;
public:
    SpecBuilder(const RawSpec &rawSpec, Spec &spec)
        : m_rawSpec(rawSpec), m_spec(spec), m_symbolMap(), m_root()
    {
    }
    void build() {
        processOptions();
        processRules();
        checkRoot();
    }
private:
    void processOptions() {
    	int priority = 1;
        for (const auto &option : m_rawSpec.options) {
            const auto &name = option->name->lexeme;
            if (name == "token") {
                processTokenOpt(option, Associativity::Right, 0);
            } else if (name == "left") {
            	processTokenOpt(option, Associativity::Left, priority++);
            } else if (name == "right") {
            	processTokenOpt(option, Associativity::Right, priority++);
            } else if (name == "nonassoc") {
            	processTokenOpt(option, Associativity::NoAssoc, priority++);
            } else if (name == "root") {
                processRootOpt(option);
            } else if (name == "namespace") {
            	processNamespace(option);
            } else if (name == "class") {
            	processClassName(option);
            } else if (name == "guard") {
            	processGuardName(option);
            }
        }
    }
    void assertOnlyOneParam(const RawOptionPtr &option) {
    	if (option->params.size() > 1) {
    		auto &tk = option->name;
    		throw SpecError("expecting only one parameter", tk->line, tk->column);
    	}
    }
    void processNamespace(const RawOptionPtr &option) {
    	assertOnlyOneParam(option);
    	m_spec.options.nameSpace = option->params.front()->lexeme;
    }
    void processClassName(const RawOptionPtr &option) {
    	assertOnlyOneParam(option);
    	m_spec.options.className = option->params.front()->lexeme;
    }
    void processGuardName(const RawOptionPtr &option) {
    	assertOnlyOneParam(option);
    	m_spec.options.guard = option->params.front()->lexeme;
    }
    void processTokenOpt(const RawOptionPtr &option, Associativity assoc, int priority) {
        for (auto &tk : option->params) {
        	auto it = m_symbolMap.find(tk);
        	if (it != m_symbolMap.end()) {
        		std::ostringstream out;
        		out << "symbol '" << tk->lexeme
        			<< "' already declared at (" << it->first->line
        			<< ", " << it->first->column << ")";
        		throw SpecError(out.str(), tk->line, tk->column);
        	}
        	TokenPtr ptr(new Token);
        	ptr->id = m_spec.tokens.size();
        	ptr->name = tk->lexeme;
        	ptr->assoc = assoc;
        	ptr->priority = priority;
        	m_symbolMap[TkPtr(new Tk(*tk))] = ptr.get();
        	m_spec.tokens.push_back(std::move(ptr));
        }
    }
    void processRootOpt(const RawOptionPtr &option) {
        const auto &params = option->params;
        if (params.size() > 1) {
            auto &t = option->name;
            throw SpecError("only one symbol can be root", t->line, t->column);
        }
        m_root = TkPtr(new Tk(*params.front()));
    }
    void processRules() {
        const auto &rules = m_rawSpec.rules;
        for (const auto &rule : rules) {
            auto &name = rule->name;
            auto it = m_symbolMap.find(name);
            if (it != m_symbolMap.end()) {
                std::ostringstream out;
                out << "'" << name->lexeme << "' already declared as ";
                if (dynamic_cast<Rule*>(it->second) != nullptr) {
                    out << "rule";
                } else {
                    out << "token";
                }
                int l = it->first->line;
                int c = it->first->column;
                out << " at (" << l << ", " << c << ")";
                throw SpecError(out.str(), name->line, name->column);
            }
            RulePtr ptr(new Rule);
            ptr->id = m_spec.rules.size();
            ptr->name = name->lexeme;
            m_symbolMap[TkPtr(new Tk(*name))] = ptr.get();
            m_spec.rules.push_back(std::move(ptr));
        }
        for (const auto &rule : rules) {
            processRule(rule);
        }
    }
    void processRule(const RawRulePtr &rule) {
    	auto it1 = m_symbolMap.find(rule->name);
    	auto specRule = dynamic_cast<Rule*>(it1->second);
        for (const auto &prod : rule->productions) {
        	ProductionPtr specProd(new Production);
        	specProd->rule = specRule;
            for (const auto &symbol : prod->symbols) {
                auto it2 = m_symbolMap.find(symbol);
                if (it2 == m_symbolMap.end()) {
                    std::ostringstream out;
                    out << "unknown rule or token '"
                        << symbol->lexeme << "'";
                    throw SpecError(out.str(), symbol->line, symbol->column);
                }
                specProd->symbols.push_back(it2->second);
            }
            if (prod->action != nullptr) {
            	specProd->action = prod->action->lexeme;
            }
            specRule->productions.push_back(std::move(specProd));
        }
    }
    void checkRoot() {
        if (m_root == nullptr) {
        	PosType line = 0;
        	PosType column = 0;
            throw SpecError("no root defined", line, column);
        }
        auto it = m_symbolMap.find(m_root);
        if (it == m_symbolMap.end()) {
            std::ostringstream out;
            out << "no rule named '" << m_root->lexeme << "' to be root";
            throw SpecError(out.str(), m_root->line, m_root->column);
        }
        m_spec.root = dynamic_cast<Rule*>(it->second);
        if (m_spec.root == nullptr) {
            std::ostringstream out;
            out << "'" << m_root->lexeme << "' must be rule not token";
            throw SpecError(out.str(), m_root->line, m_root->column);
        }
    }
};

void createEofToken(Spec &spec) {
	TokenPtr ptr(new Token);
	ptr->id = 0;
	ptr->name = "Eof";
	ptr->priority = 0;
	ptr->assoc = Associativity::Left;
	spec.eof = ptr.get();
	spec.tokens.push_back(std::move(ptr));
}

} // anonymous namespace

Spec parse(std::istream &input) {
	Spec rs;
	createEofToken(rs);
	Parser parser(input);
	RawSpec rawSpec = parser.parse();
	SpecBuilder builder(rawSpec, rs);
	builder.build();
	return rs;
}

} // namespace parsing
