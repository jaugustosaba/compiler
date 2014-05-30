#ifndef LEXERHELPER_H_
#define LEXERHELPER_H_

#include <sstream>
#include <stdexcept>

namespace frontend {

struct LexerHelper {
    struct LexError : public std::exception {
        LexError() {
        }
        const char* what() const noexcept override {
            return "lex error";
        }
        ~LexError() noexcept override {
        }
    };

    template <class Input, class Semantic>
    static bool lex(Input& input, Semantic& semantic) {
        Helper<Input, Semantic> helper(input, semantic);
        return helper.lex();
    }
private:
    template <class Input, class Semantic>
    class Helper {
        Input&              m_input;
        Semantic&           m_semantic;
        std::ostringstream  m_lexeme;
    public:
        Helper(Input& input, Semantic& semantic)
            : m_input(input), m_semantic(semantic), m_lexeme()
        {
        }
        bool lex() {
            m_lexeme.str("");
            int c = peek();
            if (c == -1) {
                return false;
            }
            size_t state = 8;
            while (true) {
                c = peek();
                switch (state) {
                    case 0:
                        switch (c) {
                            case 104:
                                next();
                                state = 0;
                                break;
                            case 103:
                                next();
                                state = 0;
                                break;
                            case 102:
                                next();
                                state = 0;
                                break;
                            case 101:
                                next();
                                state = 0;
                                break;
                            case 100:
                                next();
                                state = 0;
                                break;
                            case 99:
                                next();
                                state = 0;
                                break;
                            case 98:
                                next();
                                state = 0;
                                break;
                            case 76:
                                next();
                                state = 0;
                                break;
                            case 70:
                                next();
                                state = 0;
                                break;
                            case 117:
                                next();
                                state = 0;
                                break;
                            case 81:
                                next();
                                state = 0;
                                break;
                            case 80:
                                next();
                                state = 0;
                                break;
                            case 79:
                                next();
                                state = 0;
                                break;
                            case 78:
                                next();
                                state = 0;
                                break;
                            case 77:
                                next();
                                state = 0;
                                break;
                            case 65:
                                next();
                                state = 0;
                                break;
                            case 112:
                                next();
                                state = 0;
                                break;
                            case 111:
                                next();
                                state = 0;
                                break;
                            case 110:
                                next();
                                state = 0;
                                break;
                            case 109:
                                next();
                                state = 0;
                                break;
                            case 108:
                                next();
                                state = 0;
                                break;
                            case 84:
                                next();
                                state = 0;
                                break;
                            case 107:
                                next();
                                state = 0;
                                break;
                            case 83:
                                next();
                                state = 0;
                                break;
                            case 106:
                                next();
                                state = 0;
                                break;
                            case 82:
                                next();
                                state = 0;
                                break;
                            case 105:
                                next();
                                state = 0;
                                break;
                            case 113:
                                next();
                                state = 0;
                                break;
                            case 66:
                                next();
                                state = 0;
                                break;
                            case 122:
                                next();
                                state = 0;
                                break;
                            case 75:
                                next();
                                state = 0;
                                break;
                            case 121:
                                next();
                                state = 0;
                                break;
                            case 74:
                                next();
                                state = 0;
                                break;
                            case 120:
                                next();
                                state = 0;
                                break;
                            case 73:
                                next();
                                state = 0;
                                break;
                            case 119:
                                next();
                                state = 0;
                                break;
                            case 72:
                                next();
                                state = 0;
                                break;
                            case 86:
                                next();
                                state = 0;
                                break;
                            case 95:
                                next();
                                state = 0;
                                break;
                            case 118:
                                next();
                                state = 0;
                                break;
                            case 71:
                                next();
                                state = 0;
                                break;
                            case 85:
                                next();
                                state = 0;
                                break;
                            case 67:
                                next();
                                state = 0;
                                break;
                            case 114:
                                next();
                                state = 0;
                                break;
                            case 68:
                                next();
                                state = 0;
                                break;
                            case 115:
                                next();
                                state = 0;
                                break;
                            case 69:
                                next();
                                state = 0;
                                break;
                            case 116:
                                next();
                                state = 0;
                                break;
                            case 87:
                                next();
                                state = 0;
                                break;
                            case 88:
                                next();
                                state = 0;
                                break;
                            case 89:
                                next();
                                state = 0;
                                break;
                            case 90:
                                next();
                                state = 0;
                                break;
                            case 97:
                                next();
                                state = 0;
                                break;
                            default:
                                m_semantic.id(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 1:
                        m_semantic.mul(m_lexeme.str());
                        return true;
                    case 2:
                        switch (c) {
                            case 90:
                                next();
                                state = 0;
                                break;
                            case 89:
                                next();
                                state = 0;
                                break;
                            case 88:
                                next();
                                state = 0;
                                break;
                            case 87:
                                next();
                                state = 0;
                                break;
                            case 116:
                                next();
                                state = 0;
                                break;
                            case 69:
                                next();
                                state = 0;
                                break;
                            case 115:
                                next();
                                state = 0;
                                break;
                            case 109:
                                next();
                                state = 0;
                                break;
                            case 113:
                                next();
                                state = 0;
                                break;
                            case 66:
                                next();
                                state = 0;
                                break;
                            case 111:
                                next();
                                state = 0;
                                break;
                            case 65:
                                next();
                                state = 0;
                                break;
                            case 112:
                                next();
                                state = 0;
                                break;
                            case 110:
                                next();
                                state = 0;
                                break;
                            case 97:
                                next();
                                state = 0;
                                break;
                            case 80:
                                next();
                                state = 0;
                                break;
                            case 103:
                                next();
                                state = 0;
                                break;
                            case 70:
                                next();
                                state = 0;
                                break;
                            case 117:
                                next();
                                state = 0;
                                break;
                            case 104:
                                next();
                                state = 0;
                                break;
                            case 81:
                                next();
                                state = 0;
                                break;
                            case 79:
                                next();
                                state = 0;
                                break;
                            case 102:
                                next();
                                state = 0;
                                break;
                            case 78:
                                next();
                                state = 0;
                                break;
                            case 101:
                                next();
                                state = 0;
                                break;
                            case 77:
                                next();
                                state = 0;
                                break;
                            case 100:
                                next();
                                state = 0;
                                break;
                            case 99:
                                next();
                                state = 0;
                                break;
                            case 98:
                                next();
                                state = 0;
                                break;
                            case 108:
                                next();
                                state = 0;
                                break;
                            case 84:
                                next();
                                state = 0;
                                break;
                            case 107:
                                next();
                                state = 0;
                                break;
                            case 83:
                                next();
                                state = 0;
                                break;
                            case 106:
                                next();
                                state = 0;
                                break;
                            case 82:
                                next();
                                state = 0;
                                break;
                            case 105:
                                next();
                                state = 0;
                                break;
                            case 76:
                                next();
                                state = 0;
                                break;
                            case 122:
                                next();
                                state = 0;
                                break;
                            case 75:
                                next();
                                state = 0;
                                break;
                            case 121:
                                next();
                                state = 0;
                                break;
                            case 74:
                                next();
                                state = 0;
                                break;
                            case 120:
                                next();
                                state = 0;
                                break;
                            case 73:
                                next();
                                state = 0;
                                break;
                            case 119:
                                next();
                                state = 0;
                                break;
                            case 72:
                                next();
                                state = 0;
                                break;
                            case 86:
                                next();
                                state = 0;
                                break;
                            case 95:
                                next();
                                state = 0;
                                break;
                            case 118:
                                next();
                                state = 0;
                                break;
                            case 71:
                                next();
                                state = 0;
                                break;
                            case 85:
                                next();
                                state = 0;
                                break;
                            case 67:
                                next();
                                state = 0;
                                break;
                            case 114:
                                next();
                                state = 0;
                                break;
                            case 68:
                                next();
                                state = 0;
                                break;
                            default:
                                m_semantic.id(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 3:
                        m_semantic.pow(m_lexeme.str());
                        return true;
                    case 4:
                        switch (c) {
                            case 9:
                                next();
                                state = 4;
                                break;
                            case 32:
                                next();
                                state = 4;
                                break;
                            case 10:
                                next();
                                state = 4;
                                break;
                            default:
                                return false;
                        }
                        break;
                    case 5:
                        switch (c) {
                            case 10:
                                next();
                                state = 4;
                                break;
                            case 32:
                                next();
                                state = 4;
                                break;
                            case 9:
                                next();
                                state = 4;
                                break;
                            default:
                                return false;
                        }
                        break;
                    case 6:
                        m_semantic.add(m_lexeme.str());
                        return true;
                    case 7:
                        m_semantic.lt(m_lexeme.str());
                        return true;
                    case 8:
                        switch (c) {
                            case 104:
                                next();
                                state = 2;
                                break;
                            case 103:
                                next();
                                state = 2;
                                break;
                            case 102:
                                next();
                                state = 2;
                                break;
                            case 101:
                                next();
                                state = 2;
                                break;
                            case 100:
                                next();
                                state = 2;
                                break;
                            case 99:
                                next();
                                state = 2;
                                break;
                            case 98:
                                next();
                                state = 2;
                                break;
                            case 97:
                                next();
                                state = 2;
                                break;
                            case 90:
                                next();
                                state = 2;
                                break;
                            case 89:
                                next();
                                state = 2;
                                break;
                            case 88:
                                next();
                                state = 2;
                                break;
                            case 87:
                                next();
                                state = 2;
                                break;
                            case 116:
                                next();
                                state = 2;
                                break;
                            case 69:
                                next();
                                state = 2;
                                break;
                            case 80:
                                next();
                                state = 2;
                                break;
                            case 77:
                                next();
                                state = 2;
                                break;
                            case 113:
                                next();
                                state = 2;
                                break;
                            case 66:
                                next();
                                state = 2;
                                break;
                            case 105:
                                next();
                                state = 2;
                                break;
                            case 60:
                                next();
                                state = 7;
                                break;
                            case 78:
                                next();
                                state = 2;
                                break;
                            case 32:
                                next();
                                state = 5;
                                break;
                            case 79:
                                next();
                                state = 2;
                                break;
                            case 112:
                                next();
                                state = 2;
                                break;
                            case 65:
                                next();
                                state = 2;
                                break;
                            case 43:
                                next();
                                state = 6;
                                break;
                            case 109:
                                next();
                                state = 2;
                                break;
                            case 107:
                                next();
                                state = 2;
                                break;
                            case 10:
                                next();
                                state = 5;
                                break;
                            case 9:
                                next();
                                state = 5;
                                break;
                            case 106:
                                next();
                                state = 2;
                                break;
                            case 94:
                                next();
                                state = 3;
                                break;
                            case 108:
                                next();
                                state = 2;
                                break;
                            case 42:
                                next();
                                state = 1;
                                break;
                            case 111:
                                next();
                                state = 2;
                                break;
                            case 110:
                                next();
                                state = 2;
                                break;
                            case 81:
                                next();
                                state = 2;
                                break;
                            case 82:
                                next();
                                state = 2;
                                break;
                            case 83:
                                next();
                                state = 2;
                                break;
                            case 117:
                                next();
                                state = 2;
                                break;
                            case 70:
                                next();
                                state = 2;
                                break;
                            case 84:
                                next();
                                state = 2;
                                break;
                            case 76:
                                next();
                                state = 2;
                                break;
                            case 122:
                                next();
                                state = 2;
                                break;
                            case 75:
                                next();
                                state = 2;
                                break;
                            case 121:
                                next();
                                state = 2;
                                break;
                            case 74:
                                next();
                                state = 2;
                                break;
                            case 120:
                                next();
                                state = 2;
                                break;
                            case 73:
                                next();
                                state = 2;
                                break;
                            case 119:
                                next();
                                state = 2;
                                break;
                            case 72:
                                next();
                                state = 2;
                                break;
                            case 86:
                                next();
                                state = 2;
                                break;
                            case 95:
                                next();
                                state = 2;
                                break;
                            case 118:
                                next();
                                state = 2;
                                break;
                            case 71:
                                next();
                                state = 2;
                                break;
                            case 85:
                                next();
                                state = 2;
                                break;
                            case 67:
                                next();
                                state = 2;
                                break;
                            case 114:
                                next();
                                state = 2;
                                break;
                            case 68:
                                next();
                                state = 2;
                                break;
                            case 115:
                                next();
                                state = 2;
                                break;
                            default:
                                throw LexError();
                        }
                        break;
                }
            }
            throw std::logic_error("unexpect code");
        }
        inline int peek() {
            return m_input.peek();
        }
        inline void next() {
            int c = m_input.peek();
            if (c != -1) {
                m_lexeme << char(c);
            }
            m_input.next();
        }
    };
};

} // namespace frontend

#endif
