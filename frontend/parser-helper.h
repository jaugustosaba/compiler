#ifndef PARSERHELPER_H_
#define PARSERHELPER_H_

#include <stack>
#include <memory>
#include <utility>
#include <stdexcept>

namespace frontend {

struct ParserHelper {
    struct SyntaxError : public std::exception {
        SyntaxError() {
        }
        const char* what() const noexcept override {
            return "syntax error";
        }
        ~SyntaxError() noexcept override {
        }
    };

    enum class TokenType {
        Eof = 0,
        MODULE = 1,
        PROCEDURE = 2,
        FUNCTION = 3,
        BEGIN = 4,
        END = 5,
        TYPE = 6,
        RECORD = 7,
        VAR = 8,
        IF = 9,
        ELSEIF = 10,
        THEN = 11,
        ELSE = 12,
        WHILE = 13,
        DO = 14,
        COLON = 15,
        ID = 16,
        EQ = 17,
        SEMI = 18,
        COMMA = 19,
        LPAREN = 20,
        RPAREN = 21,
    };

    template <class Token, class Result>
    class Symbol {
        typedef std::shared_ptr<Token> TokenPtr;
        typedef std::shared_ptr<Result> ResultPtr;

        TokenPtr   m_token;
        ResultPtr  m_result;

    public:
        Symbol(const Token &token)
            : m_token(new Token(token)), m_result()
        {
        }
        Symbol(const Result &result)
            : m_token(), m_result(new Result(result))
        {
        }
        Symbol()
            : Symbol(Result()) 
        {
        }
        bool isToken() const {
            return m_token.get() != nullptr;
        }
        bool isResult() const {
            return m_result.get() != nullptr;
        }
        Result result() const {
            if (!isResult()) {
                throw std::logic_error("not a result");
            }
            return *m_result;
        }
        Token token() const {
            if (!isToken()) {
                throw std::logic_error("not a token");
            }
            return *m_token;
        }
    };

    template <class Lexer, class Semantic>
    static typename Semantic::Result parse(Lexer &lexer, Semantic &semantic) {
        Helper<Lexer, Semantic> helper(lexer, semantic);
        return helper.parse();
    }

private:
    enum class ActionType {
        Shift,
        Reduce,
        Accept,
        Error,
    };

    struct Action {
        ActionType  type;
        size_t      value;
    };

    template <class Lexer, class Semantic>
    struct Helper {
        typedef typename Semantic::Result Result;
        typedef decltype(std::declval<Lexer>().peekAsToken()) Token;
        typedef std::pair<size_t, Result> Reduction;

        Helper(Lexer &lexer, Semantic &semantic)
            : m_lexer(lexer), m_semantic(semantic), m_stack({ State(0) })
        {
        }
        Result parse() {
            while (true) {
                const State &state = m_stack.top();
                TokenType tokenType = m_lexer.peek();
                const Action &action = getAction(state.id, tokenType);
                switch (action.type) {
                    case ActionType::Shift:
                        m_stack.emplace(action.value, m_lexer.peekAsToken());
                        m_lexer.next();
                        break;
                    case ActionType::Reduce: {
                        Reduction reduction = reduce(action.value);
                        size_t nextState = getGoto(m_stack.top().id, reduction.first);
                        m_stack.emplace(nextState, reduction.second);
                        break;
                    }
                    case ActionType::Accept:
                        return state.symbol.result();
                    case ActionType::Error:
                        throw SyntaxError();
                }
            }
            throw std::logic_error("unexpected code");
        }

    private:
        typedef Symbol<Token, Result> SymbolT;

        struct State {
            size_t   id;
            SymbolT  symbol;

            State(size_t id, const SymbolT &symbol)
                : id(id), symbol(symbol)
            {
            }
            State(size_t id)
                : State(id, SymbolT())
            {
            }
        };

        typedef std::stack<State> Stack;

        Lexer&     m_lexer;
        Semantic&  m_semantic;
        Stack      m_stack;

        Reduction reduce(size_t reduction) {
            switch (reduction) {
                case 0: {
                    return Reduction(7, Result());
                }
                case 1: {
                    return Reduction(13, Result());
                }
                case 2: {
                    return Reduction(2, Result());
                }
                case 3: {
                    return Reduction(8, Result());
                }
                case 4: {
                    auto s2 = m_stack.top().symbol; m_stack.pop();
                    auto s1 = m_stack.top().symbol; m_stack.pop();
                    return Reduction(7, m_semantic.handleTypes(s1, s2));
                }
                case 5: {
                    return Reduction(8, Result());
                }
                case 6: {
                    return Reduction(19, Result());
                }
                case 7: {
                    auto s2 = m_stack.top().symbol; m_stack.pop();
                    auto s1 = m_stack.top().symbol; m_stack.pop();
                    return Reduction(13, m_semantic.handleOptStmt(s1, s2));
                }
                case 8: {
                    return Reduction(24, Result());
                }
                case 9: {
                    return Reduction(24, Result());
                }
                case 10: {
                    return Reduction(19, Result());
                }
                case 11: {
                    return Reduction(21, Result());
                }
                case 12: {
                    return Reduction(23, Result());
                }
                case 13: {
                    return Reduction(21, Result());
                }
                case 14: {
                    return Reduction(24, Result());
                }
                case 15: {
                    return Reduction(19, Result());
                }
                case 16: {
                    auto s4 = m_stack.top().symbol; m_stack.pop();
                    auto s3 = m_stack.top().symbol; m_stack.pop();
                    auto s2 = m_stack.top().symbol; m_stack.pop();
                    auto s1 = m_stack.top().symbol; m_stack.pop();
                    return Reduction(22, m_semantic.handleElseif(s1, s2, s3, s4));
                }
                case 17: {
                    auto s2 = m_stack.top().symbol; m_stack.pop();
                    auto s1 = m_stack.top().symbol; m_stack.pop();
                    return Reduction(8, m_semantic.handleAppendTypeDecl(s1, s2));
                }
                case 18: {
                    return Reduction(19, Result());
                }
                case 19: {
                    auto s3 = m_stack.top().symbol; m_stack.pop();
                    auto s2 = m_stack.top().symbol; m_stack.pop();
                    auto s1 = m_stack.top().symbol; m_stack.pop();
                    return Reduction(19, m_semantic.handleAppendStmt(s1, s2, s3));
                }
                case 20: {
                    return Reduction(11, Result());
                }
                case 21: {
                    return Reduction(11, Result());
                }
                case 22: {
                    return Reduction(5, Result());
                }
                case 23: {
                    auto s2 = m_stack.top().symbol; m_stack.pop();
                    auto s1 = m_stack.top().symbol; m_stack.pop();
                    return Reduction(4, m_semantic.handleIdentList(s1, s2));
                }
                case 24: {
                    auto s4 = m_stack.top().symbol; m_stack.pop();
                    auto s3 = m_stack.top().symbol; m_stack.pop();
                    auto s2 = m_stack.top().symbol; m_stack.pop();
                    auto s1 = m_stack.top().symbol; m_stack.pop();
                    return Reduction(12, m_semantic.handleField(s1, s2, s3, s4));
                }
                case 25: {
                    auto s2 = m_stack.top().symbol; m_stack.pop();
                    auto s1 = m_stack.top().symbol; m_stack.pop();
                    return Reduction(11, m_semantic.handleAppendField(s1, s2));
                }
                case 26: {
                    auto s3 = m_stack.top().symbol; m_stack.pop();
                    auto s2 = m_stack.top().symbol; m_stack.pop();
                    auto s1 = m_stack.top().symbol; m_stack.pop();
                    return Reduction(10, m_semantic.handleRecord(s1, s2, s3));
                }
                case 27: {
                    auto s4 = m_stack.top().symbol; m_stack.pop();
                    auto s3 = m_stack.top().symbol; m_stack.pop();
                    auto s2 = m_stack.top().symbol; m_stack.pop();
                    auto s1 = m_stack.top().symbol; m_stack.pop();
                    return Reduction(9, m_semantic.handleTypeDecl(s1, s2, s3, s4));
                }
                case 28: {
                    return Reduction(19, Result());
                }
                case 29: {
                    auto s2 = m_stack.top().symbol; m_stack.pop();
                    auto s1 = m_stack.top().symbol; m_stack.pop();
                    return Reduction(23, m_semantic.handleOptElse(s1, s2));
                }
                case 30: {
                    auto s7 = m_stack.top().symbol; m_stack.pop();
                    auto s6 = m_stack.top().symbol; m_stack.pop();
                    auto s5 = m_stack.top().symbol; m_stack.pop();
                    auto s4 = m_stack.top().symbol; m_stack.pop();
                    auto s3 = m_stack.top().symbol; m_stack.pop();
                    auto s2 = m_stack.top().symbol; m_stack.pop();
                    auto s1 = m_stack.top().symbol; m_stack.pop();
                    return Reduction(20, m_semantic.handleIfStmt(s1, s2, s3, s4, s5, s6, s7));
                }
                case 31: {
                    return Reduction(19, Result());
                }
                case 32: {
                    auto s5 = m_stack.top().symbol; m_stack.pop();
                    auto s4 = m_stack.top().symbol; m_stack.pop();
                    auto s3 = m_stack.top().symbol; m_stack.pop();
                    auto s2 = m_stack.top().symbol; m_stack.pop();
                    auto s1 = m_stack.top().symbol; m_stack.pop();
                    return Reduction(20, m_semantic.handleWhile(s1, s2, s3, s4, s5));
                }
                case 33: {
                    return Reduction(5, Result());
                }
                case 34: {
                    auto s3 = m_stack.top().symbol; m_stack.pop();
                    auto s2 = m_stack.top().symbol; m_stack.pop();
                    auto s1 = m_stack.top().symbol; m_stack.pop();
                    return Reduction(5, m_semantic.handleAppendIdent(s1, s2, s3));
                }
                case 35: {
                    auto s8 = m_stack.top().symbol; m_stack.pop();
                    auto s7 = m_stack.top().symbol; m_stack.pop();
                    auto s6 = m_stack.top().symbol; m_stack.pop();
                    auto s5 = m_stack.top().symbol; m_stack.pop();
                    auto s4 = m_stack.top().symbol; m_stack.pop();
                    auto s3 = m_stack.top().symbol; m_stack.pop();
                    auto s2 = m_stack.top().symbol; m_stack.pop();
                    auto s1 = m_stack.top().symbol; m_stack.pop();
                    return Reduction(0, m_semantic.handleModule(s1, s2, s3, s4, s5, s6, s7, s8));
                }
                case 36: {
                    return Reduction(14, m_semantic.handleEmptyProcDecls());
                }
                case 37: {
                    return Reduction(3, Result());
                }
                case 38: {
                    auto s2 = m_stack.top().symbol; m_stack.pop();
                    auto s1 = m_stack.top().symbol; m_stack.pop();
                    return Reduction(2, m_semantic.handleVars(s1, s2));
                }
                case 39: {
                    return Reduction(3, Result());
                }
                case 40: {
                    auto s2 = m_stack.top().symbol; m_stack.pop();
                    auto s1 = m_stack.top().symbol; m_stack.pop();
                    return Reduction(3, m_semantic.handleAppendVarDecl(s1, s2));
                }
                case 41: {
                    auto s3 = m_stack.top().symbol; m_stack.pop();
                    auto s2 = m_stack.top().symbol; m_stack.pop();
                    auto s1 = m_stack.top().symbol; m_stack.pop();
                    return Reduction(1, m_semantic.handleDecls(s1, s2, s3));
                }
                case 42: {
                    return Reduction(14, m_semantic.handleEmptyProcDecls());
                }
                case 43: {
                    return Reduction(16, Result());
                }
                case 44: {
                    return Reduction(7, Result());
                }
                case 45: {
                    return Reduction(19, Result());
                }
                case 46: {
                    return Reduction(16, Result());
                }
                case 47: {
                    return Reduction(7, Result());
                }
                case 48: {
                    return Reduction(19, Result());
                }
                case 49: {
                    auto s10 = m_stack.top().symbol; m_stack.pop();
                    auto s9 = m_stack.top().symbol; m_stack.pop();
                    auto s8 = m_stack.top().symbol; m_stack.pop();
                    auto s7 = m_stack.top().symbol; m_stack.pop();
                    auto s6 = m_stack.top().symbol; m_stack.pop();
                    auto s5 = m_stack.top().symbol; m_stack.pop();
                    auto s4 = m_stack.top().symbol; m_stack.pop();
                    auto s3 = m_stack.top().symbol; m_stack.pop();
                    auto s2 = m_stack.top().symbol; m_stack.pop();
                    auto s1 = m_stack.top().symbol; m_stack.pop();
                    return Reduction(15, m_semantic.handleProcedure(s1, s2, s3, s4, s5, s6, s7, s8, s9, s10));
                }
                case 50: {
                    m_stack.pop();
                    m_stack.pop();
                    return Reduction(16, Result());
                }
                case 51: {
                    return Reduction(17, Result());
                }
                case 52: {
                    auto s3 = m_stack.top().symbol; m_stack.pop();
                    auto s2 = m_stack.top().symbol; m_stack.pop();
                    auto s1 = m_stack.top().symbol; m_stack.pop();
                    return Reduction(18, m_semantic.handleFParam(s1, s2, s3));
                }
                case 53: {
                    auto s2 = m_stack.top().symbol; m_stack.pop();
                    auto s1 = m_stack.top().symbol; m_stack.pop();
                    return Reduction(14, m_semantic.handleAppendProcDecl(s1, s2));
                }
                case 54: {
                    auto s4 = m_stack.top().symbol; m_stack.pop();
                    auto s3 = m_stack.top().symbol; m_stack.pop();
                    auto s2 = m_stack.top().symbol; m_stack.pop();
                    auto s1 = m_stack.top().symbol; m_stack.pop();
                    return Reduction(18, m_semantic.handleVarFParam(s1, s2, s3, s4));
                }
                case 55: {
                    return Reduction(17, Result());
                }
                case 56: {
                    auto s3 = m_stack.top().symbol; m_stack.pop();
                    auto s2 = m_stack.top().symbol; m_stack.pop();
                    auto s1 = m_stack.top().symbol; m_stack.pop();
                    return Reduction(17, m_semantic.handleAppendFParam(s1, s2, s3));
                }
                case 57: {
                    auto s4 = m_stack.top().symbol; m_stack.pop();
                    auto s3 = m_stack.top().symbol; m_stack.pop();
                    auto s2 = m_stack.top().symbol; m_stack.pop();
                    auto s1 = m_stack.top().symbol; m_stack.pop();
                    return Reduction(16, m_semantic.handleFParams(s1, s2, s3, s4));
                }
                case 58: {
                    auto s12 = m_stack.top().symbol; m_stack.pop();
                    auto s11 = m_stack.top().symbol; m_stack.pop();
                    auto s10 = m_stack.top().symbol; m_stack.pop();
                    auto s9 = m_stack.top().symbol; m_stack.pop();
                    auto s8 = m_stack.top().symbol; m_stack.pop();
                    auto s7 = m_stack.top().symbol; m_stack.pop();
                    auto s6 = m_stack.top().symbol; m_stack.pop();
                    auto s5 = m_stack.top().symbol; m_stack.pop();
                    auto s4 = m_stack.top().symbol; m_stack.pop();
                    auto s3 = m_stack.top().symbol; m_stack.pop();
                    auto s2 = m_stack.top().symbol; m_stack.pop();
                    auto s1 = m_stack.top().symbol; m_stack.pop();
                    return Reduction(15, m_semantic.handleFunction(s1, s2, s3, s4, s5, s6, s7, s8, s9, s10, s11, s12));
                }
                case 59: {
                    auto s4 = m_stack.top().symbol; m_stack.pop();
                    auto s3 = m_stack.top().symbol; m_stack.pop();
                    auto s2 = m_stack.top().symbol; m_stack.pop();
                    auto s1 = m_stack.top().symbol; m_stack.pop();
                    return Reduction(6, m_semantic.handleVarDecl(s1, s2, s3, s4));
                }
                case 60: {
                    auto s2 = m_stack.top().symbol; m_stack.pop();
                    auto s1 = m_stack.top().symbol; m_stack.pop();
                    return Reduction(21, m_semantic.handleAppendElseif(s1, s2));
                }
            }
            throw std::logic_error("bad reduction");
        }

    };
    static const Action& getAction(size_t state, TokenType lookahead) {
        const static Action ACTION[107][22] = {
            {{ ActionType::Error, 0 }, { ActionType::Shift, 2 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Accept, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Shift, 3 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Shift, 4 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Reduce, 0 }, { ActionType::Reduce, 0 }, { ActionType::Reduce, 0 }, { ActionType::Reduce, 0 }, { ActionType::Shift, 7 }, { ActionType::Error, 0 }, { ActionType::Reduce, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Shift, 12 }, { ActionType::Reduce, 1 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Reduce, 2 }, { ActionType::Reduce, 2 }, { ActionType::Reduce, 2 }, { ActionType::Reduce, 2 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Shift, 58 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Reduce, 3 }, { ActionType::Reduce, 3 }, { ActionType::Reduce, 3 }, { ActionType::Reduce, 3 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Reduce, 3 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Shift, 10 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Reduce, 4 }, { ActionType::Reduce, 4 }, { ActionType::Reduce, 4 }, { ActionType::Reduce, 4 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Reduce, 4 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Reduce, 5 }, { ActionType::Reduce, 5 }, { ActionType::Reduce, 5 }, { ActionType::Reduce, 5 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Reduce, 5 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Shift, 10 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Shift, 30 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Shift, 23 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Reduce, 6 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Shift, 16 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Shift, 15 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Reduce, 7 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Shift, 28 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Reduce, 8 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Reduce, 9 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Shift, 18 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Reduce, 10 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Shift, 16 }, { ActionType::Reduce, 10 }, { ActionType::Error, 0 }, { ActionType::Reduce, 10 }, { ActionType::Shift, 15 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Reduce, 11 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Shift, 22 }, { ActionType::Error, 0 }, { ActionType::Reduce, 11 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Reduce, 12 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Shift, 47 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Reduce, 13 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Shift, 22 }, { ActionType::Error, 0 }, { ActionType::Reduce, 13 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Reduce, 14 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Shift, 55 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Shift, 25 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Reduce, 15 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Shift, 16 }, { ActionType::Reduce, 15 }, { ActionType::Error, 0 }, { ActionType::Reduce, 15 }, { ActionType::Shift, 15 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Reduce, 16 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Reduce, 16 }, { ActionType::Error, 0 }, { ActionType::Reduce, 16 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Reduce, 17 }, { ActionType::Reduce, 17 }, { ActionType::Reduce, 17 }, { ActionType::Reduce, 17 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Reduce, 17 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Reduce, 18 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Shift, 16 }, { ActionType::Reduce, 18 }, { ActionType::Error, 0 }, { ActionType::Reduce, 18 }, { ActionType::Shift, 15 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Reduce, 19 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Reduce, 19 }, { ActionType::Error, 0 }, { ActionType::Reduce, 19 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Shift, 32 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Shift, 44 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Reduce, 20 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Shift, 36 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Shift, 43 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Reduce, 21 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Shift, 36 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Shift, 39 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Reduce, 22 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Shift, 38 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Reduce, 23 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Shift, 53 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Shift, 40 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Shift, 41 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Reduce, 24 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Reduce, 24 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Reduce, 25 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Reduce, 26 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Reduce, 27 }, { ActionType::Reduce, 27 }, { ActionType::Reduce, 27 }, { ActionType::Reduce, 27 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Reduce, 27 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Reduce, 27 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Shift, 50 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Shift, 49 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Reduce, 28 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Shift, 16 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Shift, 15 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Reduce, 29 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Reduce, 30 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Reduce, 31 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Shift, 16 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Shift, 15 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Shift, 52 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Reduce, 32 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Reduce, 33 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Shift, 38 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Reduce, 34 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Shift, 56 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Reduce, 35 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Shift, 66 }, { ActionType::Shift, 65 }, { ActionType::Reduce, 36 }, { ActionType::Reduce, 36 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Reduce, 37 }, { ActionType::Reduce, 37 }, { ActionType::Reduce, 37 }, { ActionType::Reduce, 37 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Shift, 36 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Reduce, 38 }, { ActionType::Reduce, 38 }, { ActionType::Reduce, 38 }, { ActionType::Reduce, 38 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Reduce, 39 }, { ActionType::Reduce, 39 }, { ActionType::Reduce, 39 }, { ActionType::Reduce, 39 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Shift, 36 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Shift, 103 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Reduce, 40 }, { ActionType::Reduce, 40 }, { ActionType::Reduce, 40 }, { ActionType::Reduce, 40 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Reduce, 41 }, { ActionType::Reduce, 41 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Shift, 66 }, { ActionType::Shift, 65 }, { ActionType::Reduce, 42 }, { ActionType::Reduce, 42 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Shift, 75 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Shift, 67 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Reduce, 43 }, { ActionType::Error, 0 }, { ActionType::Shift, 69 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Shift, 70 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Shift, 89 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Shift, 36 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Shift, 86 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Reduce, 44 }, { ActionType::Reduce, 44 }, { ActionType::Reduce, 44 }, { ActionType::Error, 0 }, { ActionType::Shift, 7 }, { ActionType::Error, 0 }, { ActionType::Reduce, 44 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Shift, 72 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Reduce, 45 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Shift, 16 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Shift, 15 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Shift, 74 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Shift, 84 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Reduce, 46 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Shift, 69 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Shift, 77 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Shift, 78 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Shift, 79 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Reduce, 47 }, { ActionType::Reduce, 47 }, { ActionType::Reduce, 47 }, { ActionType::Error, 0 }, { ActionType::Shift, 7 }, { ActionType::Error, 0 }, { ActionType::Reduce, 47 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Shift, 81 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Reduce, 48 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Shift, 16 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Shift, 15 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Shift, 83 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Shift, 101 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Shift, 85 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Reduce, 49 }, { ActionType::Reduce, 49 }, { ActionType::Reduce, 49 }, { ActionType::Reduce, 49 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Reduce, 50 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Reduce, 50 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Shift, 97 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Reduce, 51 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Shift, 90 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Shift, 36 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Shift, 91 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Reduce, 52 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Reduce, 52 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Reduce, 53 }, { ActionType::Reduce, 53 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Shift, 94 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Shift, 95 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Reduce, 54 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Reduce, 54 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Shift, 100 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Shift, 89 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Shift, 36 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Shift, 97 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Reduce, 55 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Reduce, 56 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Reduce, 57 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Reduce, 57 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Shift, 102 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Reduce, 58 }, { ActionType::Reduce, 58 }, { ActionType::Reduce, 58 }, { ActionType::Reduce, 58 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Shift, 104 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Shift, 105 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Reduce, 59 }, { ActionType::Reduce, 59 }, { ActionType::Reduce, 59 }, { ActionType::Reduce, 59 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Reduce, 59 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Reduce, 60 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Reduce, 60 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }}
        };
        return ACTION[state][static_cast<size_t>(lookahead)];
    }
    static size_t getGoto(size_t state, size_t rule) {
        const size_t GOTO[107][25] = {
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 5, 0, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 57, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 8, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 27, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 14, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 45},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 17},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 19, 14, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 20, 21, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 46, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 106, 21, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 24},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26, 14, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 29, 14, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 31, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 35, 0, 0, 0, 0, 0, 0, 33, 34, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 35, 0, 0, 0, 0, 0, 0, 42, 34, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 37, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 48, 14, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 51, 14, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 54, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 63, 64, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 59, 61, 0, 60, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 62, 61, 0, 60, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 92, 64, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 68, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 88, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 87, 0, 0, 0, 0, 0, 0},
            {0, 71, 0, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 73, 14, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 76, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 80, 0, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 82, 14, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 96, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 93, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 88, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 98, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 99, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
        };
        return GOTO[state][rule];
    }
};

} // namespace frontend

#endif
