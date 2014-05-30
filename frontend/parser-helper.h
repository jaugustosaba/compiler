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
        BEGIN = 3,
        END = 4,
        TYPE = 5,
        RECORD = 6,
        VAR = 7,
        COLON = 8,
        ID = 9,
        EQ = 10,
        SEMI = 11,
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
                    return Reduction(5, Result());
                }
                case 1: {
                    return Reduction(9, Result());
                }
                case 2: {
                    return Reduction(2, Result());
                }
                case 3: {
                    return Reduction(6, Result());
                }
                case 4: {
                    auto s2 = m_stack.top().symbol; m_stack.pop();
                    auto s1 = m_stack.top().symbol; m_stack.pop();
                    return Reduction(5, m_semantic.handleTypes(s1, s2));
                }
                case 5: {
                    return Reduction(6, Result());
                }
                case 6: {
                    auto s2 = m_stack.top().symbol; m_stack.pop();
                    auto s1 = m_stack.top().symbol; m_stack.pop();
                    return Reduction(6, m_semantic.handleAppendTypeDecl(s1, s2));
                }
                case 7: {
                    m_stack.pop();
                    return Reduction(9, Result());
                }
                case 8: {
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
                case 9: {
                    return Reduction(10, m_semantic.handleEmptyProcDecls());
                }
                case 10: {
                    return Reduction(3, Result());
                }
                case 11: {
                    auto s2 = m_stack.top().symbol; m_stack.pop();
                    auto s1 = m_stack.top().symbol; m_stack.pop();
                    return Reduction(2, m_semantic.handleVars(s1, s2));
                }
                case 12: {
                    return Reduction(3, Result());
                }
                case 13: {
                    auto s2 = m_stack.top().symbol; m_stack.pop();
                    auto s1 = m_stack.top().symbol; m_stack.pop();
                    return Reduction(3, m_semantic.handleAppendVarDecl(s1, s2));
                }
                case 14: {
                    auto s4 = m_stack.top().symbol; m_stack.pop();
                    auto s3 = m_stack.top().symbol; m_stack.pop();
                    auto s2 = m_stack.top().symbol; m_stack.pop();
                    auto s1 = m_stack.top().symbol; m_stack.pop();
                    return Reduction(4, m_semantic.handleVarDecl(s1, s2, s3, s4));
                }
                case 15: {
                    auto s3 = m_stack.top().symbol; m_stack.pop();
                    auto s2 = m_stack.top().symbol; m_stack.pop();
                    auto s1 = m_stack.top().symbol; m_stack.pop();
                    return Reduction(1, m_semantic.handleDecls(s1, s2, s3));
                }
                case 16: {
                    return Reduction(10, m_semantic.handleEmptyProcDecls());
                }
                case 17: {
                    auto s2 = m_stack.top().symbol; m_stack.pop();
                    auto s1 = m_stack.top().symbol; m_stack.pop();
                    return Reduction(10, m_semantic.handleAppendProcDecl(s1, s2));
                }
                case 18: {
                    return Reduction(5, Result());
                }
                case 19: {
                    auto s8 = m_stack.top().symbol; m_stack.pop();
                    auto s7 = m_stack.top().symbol; m_stack.pop();
                    auto s6 = m_stack.top().symbol; m_stack.pop();
                    auto s5 = m_stack.top().symbol; m_stack.pop();
                    auto s4 = m_stack.top().symbol; m_stack.pop();
                    auto s3 = m_stack.top().symbol; m_stack.pop();
                    auto s2 = m_stack.top().symbol; m_stack.pop();
                    auto s1 = m_stack.top().symbol; m_stack.pop();
                    return Reduction(11, m_semantic.handleProcedure(s1, s2, s3, s4, s5, s6, s7, s8));
                }
                case 20: {
                    auto s2 = m_stack.top().symbol; m_stack.pop();
                    auto s1 = m_stack.top().symbol; m_stack.pop();
                    return Reduction(8, m_semantic.handleRecord(s1, s2));
                }
                case 21: {
                    auto s4 = m_stack.top().symbol; m_stack.pop();
                    auto s3 = m_stack.top().symbol; m_stack.pop();
                    auto s2 = m_stack.top().symbol; m_stack.pop();
                    auto s1 = m_stack.top().symbol; m_stack.pop();
                    return Reduction(7, m_semantic.handleTypeDecl(s1, s2, s3, s4));
                }
            }
            throw std::logic_error("bad reduction");
        }

    };
    static const Action& getAction(size_t state, TokenType lookahead) {
        const static Action ACTION[42][12] = {
            {{ ActionType::Error, 0 }, { ActionType::Shift, 2 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Accept, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Shift, 3 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Shift, 4 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Reduce, 0 }, { ActionType::Reduce, 0 }, { ActionType::Reduce, 0 }, { ActionType::Shift, 7 }, { ActionType::Error, 0 }, { ActionType::Reduce, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Shift, 13 }, { ActionType::Reduce, 1 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Reduce, 2 }, { ActionType::Reduce, 2 }, { ActionType::Reduce, 2 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Shift, 18 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Reduce, 3 }, { ActionType::Reduce, 3 }, { ActionType::Reduce, 3 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Reduce, 3 }, { ActionType::Error, 0 }, { ActionType::Shift, 10 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Reduce, 4 }, { ActionType::Reduce, 4 }, { ActionType::Reduce, 4 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Reduce, 4 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Reduce, 5 }, { ActionType::Reduce, 5 }, { ActionType::Reduce, 5 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Reduce, 5 }, { ActionType::Error, 0 }, { ActionType::Shift, 10 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Shift, 37 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Reduce, 6 }, { ActionType::Reduce, 6 }, { ActionType::Reduce, 6 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Reduce, 6 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Shift, 14 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Reduce, 7 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Shift, 15 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Shift, 16 }},
            {{ ActionType::Reduce, 8 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Shift, 28 }, { ActionType::Reduce, 9 }, { ActionType::Reduce, 9 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Reduce, 10 }, { ActionType::Reduce, 10 }, { ActionType::Reduce, 10 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Shift, 21 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Reduce, 11 }, { ActionType::Reduce, 11 }, { ActionType::Reduce, 11 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Reduce, 12 }, { ActionType::Reduce, 12 }, { ActionType::Reduce, 12 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Shift, 21 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Shift, 23 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Reduce, 13 }, { ActionType::Reduce, 13 }, { ActionType::Reduce, 13 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Shift, 24 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Shift, 25 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Reduce, 14 }, { ActionType::Reduce, 14 }, { ActionType::Reduce, 14 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Reduce, 14 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Reduce, 15 }, { ActionType::Reduce, 15 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Shift, 28 }, { ActionType::Reduce, 16 }, { ActionType::Reduce, 16 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Shift, 30 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Reduce, 17 }, { ActionType::Reduce, 17 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Shift, 31 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Reduce, 18 }, { ActionType::Reduce, 18 }, { ActionType::Error, 0 }, { ActionType::Shift, 7 }, { ActionType::Error, 0 }, { ActionType::Reduce, 18 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Shift, 33 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Shift, 34 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Shift, 35 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Shift, 36 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Reduce, 19 }, { ActionType::Reduce, 19 }, { ActionType::Reduce, 19 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Shift, 39 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Shift, 41 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Shift, 40 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Reduce, 20 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Reduce, 21 }, { ActionType::Reduce, 21 }, { ActionType::Reduce, 21 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Reduce, 21 }, { ActionType::Error, 0 }, { ActionType::Reduce, 21 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }}
        };
        return ACTION[state][static_cast<size_t>(lookahead)];
    }
    static size_t getGoto(size_t state, size_t rule) {
        const size_t GOTO[42][12] = {
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 5, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0},
            {0, 0, 17, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 8, 9, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 11, 9, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26, 27},
            {0, 0, 0, 19, 20, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 22, 20, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 29, 27},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 32, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 38, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
        };
        return GOTO[state][rule];
    }
};

} // namespace frontend

#endif
