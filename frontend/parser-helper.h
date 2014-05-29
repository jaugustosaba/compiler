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
        LT = 1,
        PLUS = 2,
        TIMES = 3,
        POW = 4,
        ID = 5,
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
                    auto s1 = m_stack.top().symbol; m_stack.pop();
                    return Reduction(0, m_semantic.id(s1));
                }
                case 1: {
                    auto s3 = m_stack.top().symbol; m_stack.pop();
                    auto s2 = m_stack.top().symbol; m_stack.pop();
                    auto s1 = m_stack.top().symbol; m_stack.pop();
                    return Reduction(0, m_semantic.add(s1, s2, s3));
                }
                case 2: {
                    auto s3 = m_stack.top().symbol; m_stack.pop();
                    auto s2 = m_stack.top().symbol; m_stack.pop();
                    auto s1 = m_stack.top().symbol; m_stack.pop();
                    return Reduction(0, m_semantic.times(s1, s2, s3));
                }
                case 3: {
                    auto s3 = m_stack.top().symbol; m_stack.pop();
                    auto s2 = m_stack.top().symbol; m_stack.pop();
                    auto s1 = m_stack.top().symbol; m_stack.pop();
                    return Reduction(0, m_semantic.power(s1, s2, s3));
                }
                case 4: {
                    auto s3 = m_stack.top().symbol; m_stack.pop();
                    auto s2 = m_stack.top().symbol; m_stack.pop();
                    auto s1 = m_stack.top().symbol; m_stack.pop();
                    return Reduction(0, m_semantic.compare(s1, s2, s3));
                }
            }
            throw std::logic_error("bad reduction");
        }

    };
    static const Action& getAction(size_t state, TokenType lookahead) {
        const static Action ACTION[11][6] = {
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Shift, 1 }},
            {{ ActionType::Reduce, 0 }, { ActionType::Reduce, 0 }, { ActionType::Reduce, 0 }, { ActionType::Reduce, 0 }, { ActionType::Reduce, 0 }, { ActionType::Error, 0 }},
            {{ ActionType::Accept, 0 }, { ActionType::Shift, 5 }, { ActionType::Shift, 6 }, { ActionType::Shift, 3 }, { ActionType::Shift, 4 }, { ActionType::Error, 0 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Shift, 1 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Shift, 1 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Shift, 1 }},
            {{ ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Error, 0 }, { ActionType::Shift, 1 }},
            {{ ActionType::Reduce, 1 }, { ActionType::Reduce, 1 }, { ActionType::Reduce, 1 }, { ActionType::Shift, 3 }, { ActionType::Shift, 4 }, { ActionType::Error, 0 }},
            {{ ActionType::Reduce, 2 }, { ActionType::Reduce, 2 }, { ActionType::Reduce, 2 }, { ActionType::Reduce, 2 }, { ActionType::Shift, 4 }, { ActionType::Error, 0 }},
            {{ ActionType::Reduce, 3 }, { ActionType::Reduce, 3 }, { ActionType::Reduce, 3 }, { ActionType::Reduce, 3 }, { ActionType::Shift, 4 }, { ActionType::Error, 0 }},
            {{ ActionType::Reduce, 4 }, { ActionType::Error, 0 }, { ActionType::Shift, 6 }, { ActionType::Shift, 3 }, { ActionType::Shift, 4 }, { ActionType::Error, 0 }}
        };
        return ACTION[state][static_cast<size_t>(lookahead)];
    }
    static size_t getGoto(size_t state, size_t rule) {
        const size_t GOTO[11][1] = {
            {2},
            {0},
            {0},
            {8},
            {9},
            {10},
            {7},
            {0},
            {0},
            {0},
            {0}
        };
        return GOTO[state][rule];
    }
};

} // namespace frontend

#endif
