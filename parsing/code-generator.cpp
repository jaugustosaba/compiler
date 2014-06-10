#include <sstream>

#include "code-generator.h"
#include "../util/idented-writer.h"

namespace parsing {

namespace {

using util::IdentedWriter;
using util::endl;

class GeneratorHelper {
    const ParserTable&  m_table;
    const Spec&         m_spec;
    IdentedWriter       m_out;
public:
    GeneratorHelper(const ParserTable &table, const Spec& spec, std::ostream &out)
        : m_table(table), m_spec(spec), m_out(out)
    {
    }
    void generate() {
    	auto &nameSpace = m_spec.options.nameSpace;
    	auto &className = m_spec.options.className;
    	auto guard = m_spec.options.guard;
    	if (guard.empty()) {
    		std::ostringstream out;
    		for (size_t i=0; i<className.size(); ++i) {
    			out << char(std::toupper(className[i]));
    		}
    		out << "_H_";
    		guard = out.str();
    	}
    	m_out << "#ifndef " << guard << endl;
    	m_out << "#define " << guard << endl << endl;
    	m_out << "#include <stack>" << endl;
    	m_out << "#include <memory>" << endl;
    	m_out << "#include <utility>" << endl;
    	m_out << "#include <stdexcept>" << endl << endl;
    	if (!nameSpace.empty()) {
    		m_out << "namespace " << nameSpace << " {" << endl << endl;
    	}
        m_out << "struct " << className << " {" << endl;
        m_out.increaseIdent();
        generateSyntaxError();
        generateTokenType();
        generateSymbol();
        generateParseFun();
        m_out.decreaseIdent();
        m_out << "private:" << endl;
        m_out.increaseIdent();
        generateActionType();
        generateAction();
        generateParserInstance();
        generateGetAction();
        generateGetGoto();
        m_out.decreaseIdent();
        m_out << "};" << endl << endl;
    	if (!nameSpace.empty()) {
    		m_out << "} // namespace " << nameSpace << endl << endl;
    	}
        m_out << "#endif" << endl;
    }
private:
    void generateSyntaxError() {
        m_out << "struct SyntaxError : public std::exception {" << endl;
        m_out.increaseIdent();
        m_out << "SyntaxError() {" << endl;
        m_out << "}" << endl;
        m_out << "const char* what() const noexcept override {" << endl;
        m_out.increaseIdent();
        m_out << "return \"syntax error\";" << endl;
        m_out.decreaseIdent();
        m_out << "}" << endl;
        m_out << "~SyntaxError() noexcept override {" << endl;
        m_out << "}" << endl;
        m_out.decreaseIdent();
        m_out << "};" << endl << endl;
    }
    void generateTokenType() {
        m_out << "enum class TokenType {" << endl;
        m_out.increaseIdent();
        const auto &tokens = m_table.tokens;
        for (size_t token=0; token < tokens.size(); ++token) {
            m_out << tokens[token] << " = " << token << "," << endl;
        }
        m_out.decreaseIdent();
        m_out << "};" << endl << endl;
    }
    void generateSymbol() {
        m_out << "template <class Token, class Result>" << endl;
        m_out << "class Symbol {" << endl;
        m_out.increaseIdent();
        m_out << "typedef std::shared_ptr<Token> TokenPtr;" << endl;
        m_out << "typedef std::shared_ptr<Result> ResultPtr;" << endl << endl;
        m_out << "TokenPtr   m_token;" << endl;
        m_out << "ResultPtr  m_result;" << endl << endl;
        m_out.decreaseIdent();
        m_out << "public:" << endl;
        m_out.increaseIdent();
        m_out << "Symbol(const Token &token)" << endl;
        m_out.increaseIdent();
        m_out << ": m_token(new Token(token)), m_result()" << endl;
        m_out.decreaseIdent();
        m_out << "{" << endl;
        m_out << "}" << endl;
        m_out << "Symbol(const Result &result)" << endl;
        m_out.increaseIdent();
        m_out << ": m_token(), m_result(new Result(result))" << endl;
        m_out.decreaseIdent();
        m_out << "{" << endl;
        m_out << "}" << endl;
        m_out << "Symbol()" << endl;
        m_out.increaseIdent();
        m_out << ": Symbol(Result()) " << endl;
        m_out.decreaseIdent();
        m_out << "{" << endl;
        m_out << "}" << endl;
        m_out << "bool isToken() const {" << endl;
        m_out.increaseIdent();
        m_out << "return m_token.get() != nullptr;" << endl;
        m_out.decreaseIdent();
        m_out << "}" << endl;
        m_out << "bool isResult() const {" << endl;
        m_out.increaseIdent();
        m_out << "return m_result.get() != nullptr;" << endl;
        m_out.decreaseIdent();
        m_out << "}" << endl;
        m_out << "Result result() const {" << endl;
        m_out.increaseIdent();
        m_out << "if (!isResult()) {" << endl;
        m_out.increaseIdent();
        m_out << "throw std::logic_error(\"not a result\");" << endl;
        m_out.decreaseIdent();
        m_out << "}" << endl;
        m_out << "return *m_result;" << endl;
        m_out.decreaseIdent();
        m_out << "}" << endl;
        m_out << "Token token() const {" << endl;
        m_out.increaseIdent();
        m_out << "if (!isToken()) {" << endl;
        m_out.increaseIdent();
        m_out << "throw std::logic_error(\"not a token\");" << endl;
        m_out.decreaseIdent();
        m_out << "}" << endl;
        m_out << "return *m_token;" << endl;
        m_out.decreaseIdent();
        m_out << "}" << endl;
        m_out.decreaseIdent();
        m_out << "};" << endl << endl;
    }
    void generateParseFun() {
        m_out << "template <class Lexer, class Semantic>" << endl;
        m_out << "static typename Semantic::Result parse(Lexer &lexer, Semantic &semantic) {" << endl;
        m_out.increaseIdent();
        m_out << "Helper<Lexer, Semantic> helper(lexer, semantic);" << endl;
        m_out << "return helper.parse();" << endl;
        m_out.decreaseIdent();
        m_out << "}" << endl << endl;
    }
    void generateActionType() {
        m_out << "enum class ActionType {" << endl;
        m_out.increaseIdent();
        m_out << "Shift," << endl;
        m_out << "Reduce," << endl;
        m_out << "Accept," << endl;
        m_out << "Error," << endl;
        m_out.decreaseIdent();
        m_out << "};" << endl << endl;
    }
    void generateAction() {
        m_out << "struct Action {" << endl;
        m_out.increaseIdent();
        m_out << "ActionType  type;" << endl;
        m_out << "size_t      value;" << endl;
        m_out.decreaseIdent();
        m_out << "};" << endl << endl;
    }
    void generateParserInstance() {
        m_out << "template <class Lexer, class Semantic>" << endl;
        m_out << "struct Helper {" << endl;
        m_out.increaseIdent();
        m_out << "typedef typename Semantic::Result Result;" << endl;
        m_out << "typedef decltype(std::declval<Lexer>().peekAsToken()) Token;" << endl;
        m_out << "typedef std::pair<size_t, Result> Reduction;" << endl << endl;
        m_out << "Helper(Lexer &lexer, Semantic &semantic)" << endl;
        m_out.increaseIdent();
        m_out << ": m_lexer(lexer), m_semantic(semantic), m_stack({ State(0) })" << endl;
        m_out.decreaseIdent();
        m_out << "{" << endl;
        m_out << "}" << endl;
        generateParse();
        m_out.decreaseIdent();
        m_out << "private:" << endl;
        m_out.increaseIdent();
        m_out << "typedef Symbol<Token, Result> SymbolT;" << endl << endl;
        generateState();
        m_out << "typedef std::stack<State> Stack;" << endl << endl;
        m_out << "Lexer&     m_lexer;" << endl;
        m_out << "Semantic&  m_semantic;" << endl;
        m_out << "Stack      m_stack;" << endl << endl;
        generateRaiseError();
        generateReduce();
        m_out.decreaseIdent();
        m_out << "};" << endl;
    }

    void generateState() {
        m_out << "struct State {" << endl;
        m_out.increaseIdent();
        m_out << "size_t   id;" << endl;
        m_out << "SymbolT  symbol;" << endl << endl;
        m_out << "State(size_t id, const SymbolT &symbol)" << endl;
        m_out.increaseIdent();
        m_out << ": id(id), symbol(symbol)" << endl;
        m_out.decreaseIdent();
        m_out << "{" << endl;
        m_out << "}" << endl;
        m_out << "State(size_t id)" << endl;
        m_out.increaseIdent();
        m_out << ": State(id, SymbolT())" << endl;
        m_out.decreaseIdent();
        m_out << "{" << endl;
        m_out << "}" << endl;
        m_out.decreaseIdent();
        m_out << "};" << endl << endl;
    }
    void generateParse() {
        m_out << "Result parse() {" << endl;
        m_out.increaseIdent();
        m_out << "while (true) {" << endl;
        m_out.increaseIdent();
        m_out << "const State &state = m_stack.top();" << endl;
        m_out << "TokenType tokenType = m_lexer.peek();" << endl;
        m_out << "const Action &action = getAction(state.id, tokenType);" << endl;
        m_out << "switch (action.type) {" << endl;
        m_out.increaseIdent();
        m_out << "case ActionType::Shift:" << endl;
        m_out.increaseIdent();
        m_out << "m_stack.emplace(action.value, m_lexer.peekAsToken());" << endl;
        m_out << "m_lexer.next();" << endl;
        m_out << "break;" << endl;
        m_out.decreaseIdent();
        m_out << "case ActionType::Reduce: {" << endl;
        m_out.increaseIdent();
        m_out << "Reduction reduction = reduce(action.value);" << endl;
        m_out << "size_t nextState = getGoto(m_stack.top().id, reduction.first);" << endl;
        m_out << "m_stack.emplace(nextState, reduction.second);" << endl;
        m_out << "break;" << endl;
        m_out.decreaseIdent();
        m_out << "}" << endl;
        m_out << "case ActionType::Accept:" << endl;
        m_out.increaseIdent();
        m_out << "return state.symbol.result();" << endl;
        m_out.decreaseIdent();
        m_out << "case ActionType::Error:" << endl;
        m_out.increaseIdent();
        m_out << "raiseError();" << endl;
        m_out.decreaseIdent();
        m_out.decreaseIdent();
        m_out << "}" << endl;
        m_out.decreaseIdent();
        m_out << "}" << endl;
        m_out << "throw std::logic_error(\"unexpected code\");" << endl;
        m_out.decreaseIdent();
        m_out << "}" << endl << endl;
    }

    void generateRaiseError() {
    	m_out << "void raiseError() {" << endl;
    	m_out.increaseIdent();
    	m_out << "while (!m_stack.empty()) {" << endl;
    	m_out.increaseIdent();
    	m_out << "const auto &state = m_stack.top();" << endl;
    	m_out << "const auto &action = getAction(state.id, TokenType::ERROR);" << endl;
    	m_out << "if (action.type == ActionType::Shift) {" << endl;
    	m_out.increaseIdent();
    	m_out << "m_stack.emplace(action.value, Token());" << endl;
    	m_out << "break;" << endl;
    	m_out.decreaseIdent();
    	m_out << "} else {" << endl;
    	m_out.increaseIdent();
    	m_out << "m_stack.pop();" << endl;
    	m_out.decreaseIdent();
    	m_out << "}" << endl;
    	m_out.decreaseIdent();
    	m_out << "}" << endl;
    	m_out << "if (m_stack.empty()) {" << endl;
    	m_out.increaseIdent();
    	m_out << "throw SyntaxError();" << endl;
    	m_out.decreaseIdent();
    	m_out << "}" << endl;
    	m_out << "while (getAction(m_stack.top().id, m_lexer.peek()).type == ActionType::Error) {" << endl;
    	m_out.increaseIdent();
    	m_out << "if (m_lexer.peek() == TokenType::EOFF) {" << endl;
    	m_out.increaseIdent();
    	m_out << "break;" << endl;
    	m_out.decreaseIdent();
    	m_out << "}" << endl;
    	m_out << "m_lexer.next();" << endl;
    	m_out.decreaseIdent();
    	m_out << "}" << endl;
    	m_out.decreaseIdent();
    	m_out << "}" << endl << endl;
    }

    void generateReduce() {
        m_out << "Reduction reduce(size_t reduction) {" << endl;
        m_out.increaseIdent();
        m_out << "switch (reduction) {" << endl;
        m_out.increaseIdent();
        const auto &reductions = m_table.reductions;
        for (size_t i=0; i < reductions.size(); ++i) {
            const auto &reduction = reductions[i];
            m_out << "case " << i << ": {" << endl;
            m_out.increaseIdent();
            bool hasAction = !reduction.action.empty();
            for (size_t j=reduction.symbolCount; j >= 1 ; --j) {
                if (hasAction) {
                    m_out << "auto s" << j << " = m_stack.top().symbol; ";
                }
                m_out << "m_stack.pop();" << endl;
            }
            m_out << "return Reduction(" << reduction.rule << ", ";
            if (hasAction) {
                m_out << "m_semantic." << reduction.action << "(";
                for (size_t j=1; j <= reduction.symbolCount; ++j) {
                    m_out << "s" << j;
                    if (j+1 <= reduction.symbolCount) {
                        m_out << ", ";
                    }
                }
                m_out << ")";
            } else {
                m_out << "Result()";
            }
            m_out << ");" << endl;
            m_out.decreaseIdent();
            m_out << "}" << endl;
        }
        m_out.decreaseIdent();
        m_out << "}" << endl;
        m_out << "throw std::logic_error(\"bad reduction\");" << endl;
        m_out.decreaseIdent();
        m_out << "}" << endl << endl;
    }
    void generateGetAction() {
        m_out << "static const Action& getAction(size_t state, TokenType lookahead) {" << endl;
        m_out.increaseIdent();
        auto stateCount = m_table.actions.size();
        auto tokenCount = m_table.tokens.size();
        m_out << "const static Action ACTION[" << stateCount << "][" << tokenCount << "] = {" << endl;
        m_out.increaseIdent();
        for (size_t state=0; state < stateCount; ++state) {
            m_out << "{";
            for (size_t token=0; token < tokenCount; ++token) {
                const auto &action = m_table.actions[state][token];
                m_out << "{ ";
                switch (action.actionType) {
                    case ActionType::Shift:
                        m_out << "ActionType::Shift";
                        break;
                    case ActionType::Reduce:
                        m_out << "ActionType::Reduce";
                        break;
                    case ActionType::Error:
                        m_out << "ActionType::Error";
                        break;
                    case ActionType::Accept:
                        m_out << "ActionType::Accept";
                        break;
                }
                m_out << ", " << action.value << " }";
                if (token+1 < tokenCount) {
                    m_out << ", ";
                }
            }
            m_out << "}";
            if (state+1 < stateCount) {
                m_out << ",";
            }
            m_out << endl;
        }
        m_out.decreaseIdent();
        m_out << "};" << endl;
        m_out << "return ACTION[state][static_cast<size_t>(lookahead)];" << endl;
        m_out.decreaseIdent();
        m_out << "}" << endl;
    }
    void generateGetGoto() {
        m_out << "static size_t getGoto(size_t state, size_t rule) {" << endl;
        m_out.increaseIdent();
        auto stateCount = m_table.actions.size();
        auto ruleCount = m_table.rules.size();
        m_out << "const size_t GOTO[" << stateCount << "][" << ruleCount << "] = {" << endl;
        m_out.increaseIdent();
        for (size_t state=0; state < stateCount; ++state) {
            m_out << "{";
            for (size_t rule=0; rule < ruleCount; ++rule) {
                m_out << m_table.gotos[state][rule];
                if (rule+1 < ruleCount) {
                    m_out << ", ";
                }
            }
            m_out << "}";
            if (state+1 < stateCount) {
                m_out << ",";
            }
            m_out << endl;
        }
        m_out.decreaseIdent();
        m_out << "};" << endl;
        m_out << "return GOTO[state][rule];" << endl;
        m_out.decreaseIdent();
        m_out << "}" << endl;
    }
};

} // anonymous namespace

void CodeGenerator::generate(std::ostream &out) const {
    GeneratorHelper helper(m_table, m_spec, out);
    helper.generate();
}

} // namespace parsing
