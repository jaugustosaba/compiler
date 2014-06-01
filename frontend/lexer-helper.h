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
            size_t state = 30;
            while (true) {
                c = peek();
                switch (state) {
                    case 0:
                        m_semantic.comma(m_lexeme.str());
                        return true;
                    case 1:
                        switch (c) {
                            case 81:
                                next();
                                state = 79;
                                break;
                            case 49:
                                next();
                                state = 79;
                                break;
                            case 71:
                                next();
                                state = 79;
                                break;
                            case 118:
                                next();
                                state = 79;
                                break;
                            case 72:
                                next();
                                state = 79;
                                break;
                            case 119:
                                next();
                                state = 79;
                                break;
                            case 74:
                                next();
                                state = 79;
                                break;
                            case 121:
                                next();
                                state = 79;
                                break;
                            case 75:
                                next();
                                state = 79;
                                break;
                            case 122:
                                next();
                                state = 79;
                                break;
                            case 73:
                                next();
                                state = 79;
                                break;
                            case 120:
                                next();
                                state = 79;
                                break;
                            case 95:
                                next();
                                state = 79;
                                break;
                            case 48:
                                next();
                                state = 79;
                                break;
                            case 70:
                                next();
                                state = 79;
                                break;
                            case 117:
                                next();
                                state = 79;
                                break;
                            case 55:
                                next();
                                state = 79;
                                break;
                            case 98:
                                next();
                                state = 79;
                                break;
                            case 51:
                                next();
                                state = 79;
                                break;
                            case 50:
                                next();
                                state = 79;
                                break;
                            case 97:
                                next();
                                state = 79;
                                break;
                            case 80:
                                next();
                                state = 79;
                                break;
                            case 79:
                                next();
                                state = 79;
                                break;
                            case 78:
                                next();
                                state = 79;
                                break;
                            case 77:
                                next();
                                state = 79;
                                break;
                            case 76:
                                next();
                                state = 79;
                                break;
                            case 65:
                                next();
                                state = 79;
                                break;
                            case 112:
                                next();
                                state = 79;
                                break;
                            case 88:
                                next();
                                state = 79;
                                break;
                            case 89:
                                next();
                                state = 79;
                                break;
                            case 66:
                                next();
                                state = 79;
                                break;
                            case 113:
                                next();
                                state = 79;
                                break;
                            case 87:
                                next();
                                state = 79;
                                break;
                            case 116:
                                next();
                                state = 79;
                                break;
                            case 69:
                                next();
                                state = 79;
                                break;
                            case 115:
                                next();
                                state = 79;
                                break;
                            case 68:
                                next();
                                state = 79;
                                break;
                            case 114:
                                next();
                                state = 17;
                                break;
                            case 67:
                                next();
                                state = 79;
                                break;
                            case 90:
                                next();
                                state = 79;
                                break;
                            case 99:
                                next();
                                state = 79;
                                break;
                            case 52:
                                next();
                                state = 79;
                                break;
                            case 100:
                                next();
                                state = 79;
                                break;
                            case 53:
                                next();
                                state = 79;
                                break;
                            case 101:
                                next();
                                state = 79;
                                break;
                            case 54:
                                next();
                                state = 79;
                                break;
                            case 111:
                                next();
                                state = 79;
                                break;
                            case 110:
                                next();
                                state = 79;
                                break;
                            case 86:
                                next();
                                state = 79;
                                break;
                            case 109:
                                next();
                                state = 79;
                                break;
                            case 85:
                                next();
                                state = 79;
                                break;
                            case 108:
                                next();
                                state = 79;
                                break;
                            case 84:
                                next();
                                state = 79;
                                break;
                            case 107:
                                next();
                                state = 79;
                                break;
                            case 83:
                                next();
                                state = 79;
                                break;
                            case 106:
                                next();
                                state = 79;
                                break;
                            case 82:
                                next();
                                state = 79;
                                break;
                            case 105:
                                next();
                                state = 79;
                                break;
                            case 104:
                                next();
                                state = 79;
                                break;
                            case 57:
                                next();
                                state = 79;
                                break;
                            case 103:
                                next();
                                state = 79;
                                break;
                            case 56:
                                next();
                                state = 79;
                                break;
                            case 102:
                                next();
                                state = 79;
                                break;
                            default:
                                m_semantic.id(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 2:
                        switch (c) {
                            case 81:
                                next();
                                state = 79;
                                break;
                            case 49:
                                next();
                                state = 79;
                                break;
                            case 71:
                                next();
                                state = 79;
                                break;
                            case 118:
                                next();
                                state = 79;
                                break;
                            case 72:
                                next();
                                state = 79;
                                break;
                            case 119:
                                next();
                                state = 79;
                                break;
                            case 74:
                                next();
                                state = 79;
                                break;
                            case 121:
                                next();
                                state = 79;
                                break;
                            case 75:
                                next();
                                state = 79;
                                break;
                            case 122:
                                next();
                                state = 79;
                                break;
                            case 73:
                                next();
                                state = 79;
                                break;
                            case 120:
                                next();
                                state = 79;
                                break;
                            case 95:
                                next();
                                state = 79;
                                break;
                            case 48:
                                next();
                                state = 79;
                                break;
                            case 70:
                                next();
                                state = 79;
                                break;
                            case 117:
                                next();
                                state = 79;
                                break;
                            case 56:
                                next();
                                state = 79;
                                break;
                            case 98:
                                next();
                                state = 79;
                                break;
                            case 51:
                                next();
                                state = 79;
                                break;
                            case 50:
                                next();
                                state = 79;
                                break;
                            case 97:
                                next();
                                state = 79;
                                break;
                            case 80:
                                next();
                                state = 79;
                                break;
                            case 79:
                                next();
                                state = 79;
                                break;
                            case 78:
                                next();
                                state = 79;
                                break;
                            case 77:
                                next();
                                state = 79;
                                break;
                            case 76:
                                next();
                                state = 79;
                                break;
                            case 65:
                                next();
                                state = 79;
                                break;
                            case 112:
                                next();
                                state = 79;
                                break;
                            case 88:
                                next();
                                state = 79;
                                break;
                            case 89:
                                next();
                                state = 79;
                                break;
                            case 66:
                                next();
                                state = 79;
                                break;
                            case 113:
                                next();
                                state = 79;
                                break;
                            case 87:
                                next();
                                state = 79;
                                break;
                            case 116:
                                next();
                                state = 79;
                                break;
                            case 69:
                                next();
                                state = 79;
                                break;
                            case 115:
                                next();
                                state = 79;
                                break;
                            case 68:
                                next();
                                state = 79;
                                break;
                            case 114:
                                next();
                                state = 79;
                                break;
                            case 67:
                                next();
                                state = 79;
                                break;
                            case 90:
                                next();
                                state = 79;
                                break;
                            case 99:
                                next();
                                state = 79;
                                break;
                            case 52:
                                next();
                                state = 79;
                                break;
                            case 100:
                                next();
                                state = 79;
                                break;
                            case 53:
                                next();
                                state = 79;
                                break;
                            case 102:
                                next();
                                state = 79;
                                break;
                            case 55:
                                next();
                                state = 79;
                                break;
                            case 101:
                                next();
                                state = 91;
                                break;
                            case 54:
                                next();
                                state = 79;
                                break;
                            case 111:
                                next();
                                state = 79;
                                break;
                            case 110:
                                next();
                                state = 79;
                                break;
                            case 86:
                                next();
                                state = 79;
                                break;
                            case 109:
                                next();
                                state = 79;
                                break;
                            case 85:
                                next();
                                state = 79;
                                break;
                            case 108:
                                next();
                                state = 79;
                                break;
                            case 84:
                                next();
                                state = 79;
                                break;
                            case 107:
                                next();
                                state = 79;
                                break;
                            case 83:
                                next();
                                state = 79;
                                break;
                            case 106:
                                next();
                                state = 79;
                                break;
                            case 82:
                                next();
                                state = 79;
                                break;
                            case 105:
                                next();
                                state = 79;
                                break;
                            case 104:
                                next();
                                state = 79;
                                break;
                            case 57:
                                next();
                                state = 79;
                                break;
                            case 103:
                                next();
                                state = 79;
                                break;
                            default:
                                m_semantic.id(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 3:
                        switch (c) {
                            case 81:
                                next();
                                state = 79;
                                break;
                            case 49:
                                next();
                                state = 79;
                                break;
                            case 71:
                                next();
                                state = 79;
                                break;
                            case 118:
                                next();
                                state = 79;
                                break;
                            case 72:
                                next();
                                state = 79;
                                break;
                            case 119:
                                next();
                                state = 79;
                                break;
                            case 74:
                                next();
                                state = 79;
                                break;
                            case 121:
                                next();
                                state = 79;
                                break;
                            case 75:
                                next();
                                state = 79;
                                break;
                            case 122:
                                next();
                                state = 79;
                                break;
                            case 73:
                                next();
                                state = 79;
                                break;
                            case 120:
                                next();
                                state = 79;
                                break;
                            case 95:
                                next();
                                state = 79;
                                break;
                            case 48:
                                next();
                                state = 79;
                                break;
                            case 70:
                                next();
                                state = 79;
                                break;
                            case 117:
                                next();
                                state = 79;
                                break;
                            case 55:
                                next();
                                state = 79;
                                break;
                            case 98:
                                next();
                                state = 79;
                                break;
                            case 51:
                                next();
                                state = 79;
                                break;
                            case 50:
                                next();
                                state = 79;
                                break;
                            case 97:
                                next();
                                state = 79;
                                break;
                            case 80:
                                next();
                                state = 79;
                                break;
                            case 79:
                                next();
                                state = 79;
                                break;
                            case 78:
                                next();
                                state = 79;
                                break;
                            case 77:
                                next();
                                state = 79;
                                break;
                            case 76:
                                next();
                                state = 79;
                                break;
                            case 65:
                                next();
                                state = 79;
                                break;
                            case 112:
                                next();
                                state = 79;
                                break;
                            case 88:
                                next();
                                state = 79;
                                break;
                            case 89:
                                next();
                                state = 79;
                                break;
                            case 66:
                                next();
                                state = 79;
                                break;
                            case 113:
                                next();
                                state = 79;
                                break;
                            case 87:
                                next();
                                state = 79;
                                break;
                            case 116:
                                next();
                                state = 79;
                                break;
                            case 69:
                                next();
                                state = 79;
                                break;
                            case 115:
                                next();
                                state = 79;
                                break;
                            case 68:
                                next();
                                state = 79;
                                break;
                            case 114:
                                next();
                                state = 79;
                                break;
                            case 67:
                                next();
                                state = 79;
                                break;
                            case 90:
                                next();
                                state = 79;
                                break;
                            case 99:
                                next();
                                state = 79;
                                break;
                            case 52:
                                next();
                                state = 79;
                                break;
                            case 100:
                                next();
                                state = 79;
                                break;
                            case 53:
                                next();
                                state = 79;
                                break;
                            case 101:
                                next();
                                state = 79;
                                break;
                            case 54:
                                next();
                                state = 79;
                                break;
                            case 111:
                                next();
                                state = 68;
                                break;
                            case 110:
                                next();
                                state = 79;
                                break;
                            case 86:
                                next();
                                state = 79;
                                break;
                            case 109:
                                next();
                                state = 79;
                                break;
                            case 85:
                                next();
                                state = 79;
                                break;
                            case 108:
                                next();
                                state = 79;
                                break;
                            case 84:
                                next();
                                state = 79;
                                break;
                            case 107:
                                next();
                                state = 79;
                                break;
                            case 83:
                                next();
                                state = 79;
                                break;
                            case 106:
                                next();
                                state = 79;
                                break;
                            case 82:
                                next();
                                state = 79;
                                break;
                            case 105:
                                next();
                                state = 79;
                                break;
                            case 104:
                                next();
                                state = 79;
                                break;
                            case 57:
                                next();
                                state = 79;
                                break;
                            case 103:
                                next();
                                state = 79;
                                break;
                            case 56:
                                next();
                                state = 79;
                                break;
                            case 102:
                                next();
                                state = 79;
                                break;
                            default:
                                m_semantic.id(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 4:
                        switch (c) {
                            case 49:
                                next();
                                state = 79;
                                break;
                            case 71:
                                next();
                                state = 79;
                                break;
                            case 118:
                                next();
                                state = 79;
                                break;
                            case 72:
                                next();
                                state = 79;
                                break;
                            case 119:
                                next();
                                state = 79;
                                break;
                            case 74:
                                next();
                                state = 79;
                                break;
                            case 121:
                                next();
                                state = 79;
                                break;
                            case 75:
                                next();
                                state = 79;
                                break;
                            case 122:
                                next();
                                state = 79;
                                break;
                            case 73:
                                next();
                                state = 79;
                                break;
                            case 120:
                                next();
                                state = 79;
                                break;
                            case 95:
                                next();
                                state = 79;
                                break;
                            case 48:
                                next();
                                state = 79;
                                break;
                            case 70:
                                next();
                                state = 79;
                                break;
                            case 117:
                                next();
                                state = 79;
                                break;
                            case 86:
                                next();
                                state = 79;
                                break;
                            case 57:
                                next();
                                state = 79;
                                break;
                            case 98:
                                next();
                                state = 79;
                                break;
                            case 51:
                                next();
                                state = 79;
                                break;
                            case 50:
                                next();
                                state = 79;
                                break;
                            case 97:
                                next();
                                state = 79;
                                break;
                            case 81:
                                next();
                                state = 79;
                                break;
                            case 80:
                                next();
                                state = 79;
                                break;
                            case 79:
                                next();
                                state = 79;
                                break;
                            case 78:
                                next();
                                state = 79;
                                break;
                            case 77:
                                next();
                                state = 79;
                                break;
                            case 76:
                                next();
                                state = 79;
                                break;
                            case 65:
                                next();
                                state = 79;
                                break;
                            case 112:
                                next();
                                state = 79;
                                break;
                            case 88:
                                next();
                                state = 79;
                                break;
                            case 87:
                                next();
                                state = 79;
                                break;
                            case 116:
                                next();
                                state = 79;
                                break;
                            case 69:
                                next();
                                state = 79;
                                break;
                            case 115:
                                next();
                                state = 79;
                                break;
                            case 68:
                                next();
                                state = 79;
                                break;
                            case 89:
                                next();
                                state = 79;
                                break;
                            case 66:
                                next();
                                state = 79;
                                break;
                            case 113:
                                next();
                                state = 79;
                                break;
                            case 90:
                                next();
                                state = 79;
                                break;
                            case 67:
                                next();
                                state = 79;
                                break;
                            case 114:
                                next();
                                state = 92;
                                break;
                            case 99:
                                next();
                                state = 79;
                                break;
                            case 52:
                                next();
                                state = 79;
                                break;
                            case 100:
                                next();
                                state = 79;
                                break;
                            case 53:
                                next();
                                state = 79;
                                break;
                            case 101:
                                next();
                                state = 79;
                                break;
                            case 54:
                                next();
                                state = 79;
                                break;
                            case 102:
                                next();
                                state = 79;
                                break;
                            case 55:
                                next();
                                state = 79;
                                break;
                            case 103:
                                next();
                                state = 79;
                                break;
                            case 56:
                                next();
                                state = 79;
                                break;
                            case 111:
                                next();
                                state = 79;
                                break;
                            case 110:
                                next();
                                state = 79;
                                break;
                            case 109:
                                next();
                                state = 79;
                                break;
                            case 85:
                                next();
                                state = 79;
                                break;
                            case 108:
                                next();
                                state = 79;
                                break;
                            case 84:
                                next();
                                state = 79;
                                break;
                            case 107:
                                next();
                                state = 79;
                                break;
                            case 83:
                                next();
                                state = 79;
                                break;
                            case 106:
                                next();
                                state = 79;
                                break;
                            case 82:
                                next();
                                state = 79;
                                break;
                            case 105:
                                next();
                                state = 79;
                                break;
                            case 104:
                                next();
                                state = 79;
                                break;
                            default:
                                m_semantic.id(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 5:
                        switch (c) {
                            case 81:
                                next();
                                state = 79;
                                break;
                            case 49:
                                next();
                                state = 79;
                                break;
                            case 71:
                                next();
                                state = 79;
                                break;
                            case 118:
                                next();
                                state = 79;
                                break;
                            case 72:
                                next();
                                state = 79;
                                break;
                            case 119:
                                next();
                                state = 79;
                                break;
                            case 74:
                                next();
                                state = 79;
                                break;
                            case 121:
                                next();
                                state = 79;
                                break;
                            case 75:
                                next();
                                state = 79;
                                break;
                            case 122:
                                next();
                                state = 79;
                                break;
                            case 73:
                                next();
                                state = 79;
                                break;
                            case 120:
                                next();
                                state = 79;
                                break;
                            case 95:
                                next();
                                state = 79;
                                break;
                            case 48:
                                next();
                                state = 79;
                                break;
                            case 70:
                                next();
                                state = 79;
                                break;
                            case 117:
                                next();
                                state = 79;
                                break;
                            case 55:
                                next();
                                state = 79;
                                break;
                            case 98:
                                next();
                                state = 79;
                                break;
                            case 51:
                                next();
                                state = 79;
                                break;
                            case 50:
                                next();
                                state = 79;
                                break;
                            case 97:
                                next();
                                state = 79;
                                break;
                            case 80:
                                next();
                                state = 79;
                                break;
                            case 79:
                                next();
                                state = 79;
                                break;
                            case 78:
                                next();
                                state = 79;
                                break;
                            case 77:
                                next();
                                state = 79;
                                break;
                            case 76:
                                next();
                                state = 79;
                                break;
                            case 65:
                                next();
                                state = 79;
                                break;
                            case 112:
                                next();
                                state = 79;
                                break;
                            case 88:
                                next();
                                state = 79;
                                break;
                            case 89:
                                next();
                                state = 79;
                                break;
                            case 66:
                                next();
                                state = 79;
                                break;
                            case 113:
                                next();
                                state = 79;
                                break;
                            case 87:
                                next();
                                state = 79;
                                break;
                            case 116:
                                next();
                                state = 79;
                                break;
                            case 69:
                                next();
                                state = 79;
                                break;
                            case 115:
                                next();
                                state = 79;
                                break;
                            case 68:
                                next();
                                state = 79;
                                break;
                            case 114:
                                next();
                                state = 79;
                                break;
                            case 67:
                                next();
                                state = 79;
                                break;
                            case 90:
                                next();
                                state = 79;
                                break;
                            case 99:
                                next();
                                state = 79;
                                break;
                            case 52:
                                next();
                                state = 79;
                                break;
                            case 100:
                                next();
                                state = 79;
                                break;
                            case 53:
                                next();
                                state = 79;
                                break;
                            case 101:
                                next();
                                state = 4;
                                break;
                            case 54:
                                next();
                                state = 79;
                                break;
                            case 111:
                                next();
                                state = 79;
                                break;
                            case 110:
                                next();
                                state = 79;
                                break;
                            case 86:
                                next();
                                state = 79;
                                break;
                            case 109:
                                next();
                                state = 79;
                                break;
                            case 85:
                                next();
                                state = 79;
                                break;
                            case 108:
                                next();
                                state = 79;
                                break;
                            case 84:
                                next();
                                state = 79;
                                break;
                            case 107:
                                next();
                                state = 79;
                                break;
                            case 83:
                                next();
                                state = 79;
                                break;
                            case 106:
                                next();
                                state = 79;
                                break;
                            case 82:
                                next();
                                state = 79;
                                break;
                            case 105:
                                next();
                                state = 79;
                                break;
                            case 104:
                                next();
                                state = 79;
                                break;
                            case 57:
                                next();
                                state = 79;
                                break;
                            case 103:
                                next();
                                state = 79;
                                break;
                            case 56:
                                next();
                                state = 79;
                                break;
                            case 102:
                                next();
                                state = 79;
                                break;
                            default:
                                m_semantic.id(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 6:
                        switch (c) {
                            case 49:
                                next();
                                state = 79;
                                break;
                            case 71:
                                next();
                                state = 79;
                                break;
                            case 118:
                                next();
                                state = 79;
                                break;
                            case 72:
                                next();
                                state = 79;
                                break;
                            case 119:
                                next();
                                state = 79;
                                break;
                            case 74:
                                next();
                                state = 79;
                                break;
                            case 121:
                                next();
                                state = 79;
                                break;
                            case 75:
                                next();
                                state = 79;
                                break;
                            case 122:
                                next();
                                state = 79;
                                break;
                            case 73:
                                next();
                                state = 79;
                                break;
                            case 120:
                                next();
                                state = 79;
                                break;
                            case 95:
                                next();
                                state = 79;
                                break;
                            case 48:
                                next();
                                state = 79;
                                break;
                            case 70:
                                next();
                                state = 79;
                                break;
                            case 117:
                                next();
                                state = 79;
                                break;
                            case 86:
                                next();
                                state = 79;
                                break;
                            case 56:
                                next();
                                state = 79;
                                break;
                            case 98:
                                next();
                                state = 79;
                                break;
                            case 51:
                                next();
                                state = 79;
                                break;
                            case 50:
                                next();
                                state = 79;
                                break;
                            case 97:
                                next();
                                state = 79;
                                break;
                            case 81:
                                next();
                                state = 79;
                                break;
                            case 80:
                                next();
                                state = 79;
                                break;
                            case 79:
                                next();
                                state = 79;
                                break;
                            case 78:
                                next();
                                state = 79;
                                break;
                            case 77:
                                next();
                                state = 79;
                                break;
                            case 76:
                                next();
                                state = 79;
                                break;
                            case 65:
                                next();
                                state = 79;
                                break;
                            case 112:
                                next();
                                state = 79;
                                break;
                            case 88:
                                next();
                                state = 79;
                                break;
                            case 87:
                                next();
                                state = 79;
                                break;
                            case 69:
                                next();
                                state = 79;
                                break;
                            case 116:
                                next();
                                state = 5;
                                break;
                            case 115:
                                next();
                                state = 79;
                                break;
                            case 68:
                                next();
                                state = 79;
                                break;
                            case 89:
                                next();
                                state = 79;
                                break;
                            case 66:
                                next();
                                state = 79;
                                break;
                            case 113:
                                next();
                                state = 79;
                                break;
                            case 114:
                                next();
                                state = 79;
                                break;
                            case 67:
                                next();
                                state = 79;
                                break;
                            case 90:
                                next();
                                state = 79;
                                break;
                            case 99:
                                next();
                                state = 79;
                                break;
                            case 52:
                                next();
                                state = 79;
                                break;
                            case 100:
                                next();
                                state = 79;
                                break;
                            case 53:
                                next();
                                state = 79;
                                break;
                            case 101:
                                next();
                                state = 79;
                                break;
                            case 54:
                                next();
                                state = 79;
                                break;
                            case 102:
                                next();
                                state = 79;
                                break;
                            case 55:
                                next();
                                state = 79;
                                break;
                            case 82:
                                next();
                                state = 79;
                                break;
                            case 105:
                                next();
                                state = 79;
                                break;
                            case 111:
                                next();
                                state = 79;
                                break;
                            case 110:
                                next();
                                state = 79;
                                break;
                            case 109:
                                next();
                                state = 79;
                                break;
                            case 85:
                                next();
                                state = 79;
                                break;
                            case 108:
                                next();
                                state = 79;
                                break;
                            case 84:
                                next();
                                state = 79;
                                break;
                            case 107:
                                next();
                                state = 79;
                                break;
                            case 83:
                                next();
                                state = 79;
                                break;
                            case 106:
                                next();
                                state = 79;
                                break;
                            case 104:
                                next();
                                state = 79;
                                break;
                            case 57:
                                next();
                                state = 79;
                                break;
                            case 103:
                                next();
                                state = 79;
                                break;
                            default:
                                m_semantic.id(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 7:
                        switch (c) {
                            case 81:
                                next();
                                state = 79;
                                break;
                            case 49:
                                next();
                                state = 79;
                                break;
                            case 71:
                                next();
                                state = 79;
                                break;
                            case 118:
                                next();
                                state = 79;
                                break;
                            case 72:
                                next();
                                state = 79;
                                break;
                            case 119:
                                next();
                                state = 79;
                                break;
                            case 74:
                                next();
                                state = 79;
                                break;
                            case 121:
                                next();
                                state = 79;
                                break;
                            case 75:
                                next();
                                state = 79;
                                break;
                            case 122:
                                next();
                                state = 79;
                                break;
                            case 73:
                                next();
                                state = 79;
                                break;
                            case 120:
                                next();
                                state = 79;
                                break;
                            case 95:
                                next();
                                state = 79;
                                break;
                            case 48:
                                next();
                                state = 79;
                                break;
                            case 70:
                                next();
                                state = 79;
                                break;
                            case 117:
                                next();
                                state = 79;
                                break;
                            case 55:
                                next();
                                state = 79;
                                break;
                            case 98:
                                next();
                                state = 79;
                                break;
                            case 51:
                                next();
                                state = 79;
                                break;
                            case 50:
                                next();
                                state = 79;
                                break;
                            case 97:
                                next();
                                state = 79;
                                break;
                            case 80:
                                next();
                                state = 79;
                                break;
                            case 79:
                                next();
                                state = 79;
                                break;
                            case 78:
                                next();
                                state = 79;
                                break;
                            case 77:
                                next();
                                state = 79;
                                break;
                            case 76:
                                next();
                                state = 79;
                                break;
                            case 65:
                                next();
                                state = 79;
                                break;
                            case 112:
                                next();
                                state = 79;
                                break;
                            case 88:
                                next();
                                state = 79;
                                break;
                            case 89:
                                next();
                                state = 79;
                                break;
                            case 66:
                                next();
                                state = 79;
                                break;
                            case 113:
                                next();
                                state = 79;
                                break;
                            case 87:
                                next();
                                state = 79;
                                break;
                            case 116:
                                next();
                                state = 79;
                                break;
                            case 69:
                                next();
                                state = 79;
                                break;
                            case 115:
                                next();
                                state = 79;
                                break;
                            case 68:
                                next();
                                state = 79;
                                break;
                            case 114:
                                next();
                                state = 79;
                                break;
                            case 67:
                                next();
                                state = 79;
                                break;
                            case 90:
                                next();
                                state = 79;
                                break;
                            case 99:
                                next();
                                state = 79;
                                break;
                            case 52:
                                next();
                                state = 79;
                                break;
                            case 100:
                                next();
                                state = 79;
                                break;
                            case 53:
                                next();
                                state = 79;
                                break;
                            case 101:
                                next();
                                state = 79;
                                break;
                            case 54:
                                next();
                                state = 79;
                                break;
                            case 82:
                                next();
                                state = 79;
                                break;
                            case 105:
                                next();
                                state = 64;
                                break;
                            case 111:
                                next();
                                state = 79;
                                break;
                            case 110:
                                next();
                                state = 79;
                                break;
                            case 86:
                                next();
                                state = 79;
                                break;
                            case 109:
                                next();
                                state = 79;
                                break;
                            case 85:
                                next();
                                state = 79;
                                break;
                            case 108:
                                next();
                                state = 79;
                                break;
                            case 84:
                                next();
                                state = 79;
                                break;
                            case 107:
                                next();
                                state = 79;
                                break;
                            case 83:
                                next();
                                state = 79;
                                break;
                            case 106:
                                next();
                                state = 79;
                                break;
                            case 104:
                                next();
                                state = 79;
                                break;
                            case 57:
                                next();
                                state = 79;
                                break;
                            case 103:
                                next();
                                state = 79;
                                break;
                            case 56:
                                next();
                                state = 79;
                                break;
                            case 102:
                                next();
                                state = 79;
                                break;
                            default:
                                m_semantic.id(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 8:
                        switch (c) {
                            case 103:
                                next();
                                state = 79;
                                break;
                            case 57:
                                next();
                                state = 79;
                                break;
                            case 104:
                                next();
                                state = 79;
                                break;
                            case 105:
                                next();
                                state = 79;
                                break;
                            case 82:
                                next();
                                state = 79;
                                break;
                            case 106:
                                next();
                                state = 79;
                                break;
                            case 83:
                                next();
                                state = 79;
                                break;
                            case 107:
                                next();
                                state = 79;
                                break;
                            case 84:
                                next();
                                state = 79;
                                break;
                            case 108:
                                next();
                                state = 79;
                                break;
                            case 85:
                                next();
                                state = 79;
                                break;
                            case 109:
                                next();
                                state = 79;
                                break;
                            case 111:
                                next();
                                state = 7;
                                break;
                            case 110:
                                next();
                                state = 79;
                                break;
                            case 55:
                                next();
                                state = 79;
                                break;
                            case 102:
                                next();
                                state = 79;
                                break;
                            case 54:
                                next();
                                state = 79;
                                break;
                            case 81:
                                next();
                                state = 79;
                                break;
                            case 56:
                                next();
                                state = 79;
                                break;
                            case 86:
                                next();
                                state = 79;
                                break;
                            case 70:
                                next();
                                state = 79;
                                break;
                            case 117:
                                next();
                                state = 79;
                                break;
                            case 48:
                                next();
                                state = 79;
                                break;
                            case 95:
                                next();
                                state = 79;
                                break;
                            case 71:
                                next();
                                state = 79;
                                break;
                            case 118:
                                next();
                                state = 79;
                                break;
                            case 97:
                                next();
                                state = 79;
                                break;
                            case 50:
                                next();
                                state = 79;
                                break;
                            case 51:
                                next();
                                state = 79;
                                break;
                            case 98:
                                next();
                                state = 79;
                                break;
                            case 120:
                                next();
                                state = 79;
                                break;
                            case 73:
                                next();
                                state = 79;
                                break;
                            case 74:
                                next();
                                state = 79;
                                break;
                            case 121:
                                next();
                                state = 79;
                                break;
                            case 49:
                                next();
                                state = 79;
                                break;
                            case 72:
                                next();
                                state = 79;
                                break;
                            case 119:
                                next();
                                state = 79;
                                break;
                            case 75:
                                next();
                                state = 79;
                                break;
                            case 122:
                                next();
                                state = 79;
                                break;
                            case 80:
                                next();
                                state = 79;
                                break;
                            case 79:
                                next();
                                state = 79;
                                break;
                            case 78:
                                next();
                                state = 79;
                                break;
                            case 77:
                                next();
                                state = 79;
                                break;
                            case 76:
                                next();
                                state = 79;
                                break;
                            case 65:
                                next();
                                state = 79;
                                break;
                            case 112:
                                next();
                                state = 79;
                                break;
                            case 88:
                                next();
                                state = 79;
                                break;
                            case 89:
                                next();
                                state = 79;
                                break;
                            case 66:
                                next();
                                state = 79;
                                break;
                            case 113:
                                next();
                                state = 79;
                                break;
                            case 87:
                                next();
                                state = 79;
                                break;
                            case 116:
                                next();
                                state = 79;
                                break;
                            case 69:
                                next();
                                state = 79;
                                break;
                            case 115:
                                next();
                                state = 79;
                                break;
                            case 68:
                                next();
                                state = 79;
                                break;
                            case 114:
                                next();
                                state = 3;
                                break;
                            case 67:
                                next();
                                state = 79;
                                break;
                            case 90:
                                next();
                                state = 79;
                                break;
                            case 99:
                                next();
                                state = 79;
                                break;
                            case 52:
                                next();
                                state = 79;
                                break;
                            case 100:
                                next();
                                state = 79;
                                break;
                            case 53:
                                next();
                                state = 79;
                                break;
                            case 101:
                                next();
                                state = 79;
                                break;
                            default:
                                m_semantic.id(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 9:
                        switch (c) {
                            case 81:
                                next();
                                state = 79;
                                break;
                            case 49:
                                next();
                                state = 79;
                                break;
                            case 71:
                                next();
                                state = 79;
                                break;
                            case 118:
                                next();
                                state = 79;
                                break;
                            case 72:
                                next();
                                state = 79;
                                break;
                            case 119:
                                next();
                                state = 79;
                                break;
                            case 74:
                                next();
                                state = 79;
                                break;
                            case 121:
                                next();
                                state = 79;
                                break;
                            case 75:
                                next();
                                state = 79;
                                break;
                            case 122:
                                next();
                                state = 79;
                                break;
                            case 73:
                                next();
                                state = 79;
                                break;
                            case 120:
                                next();
                                state = 79;
                                break;
                            case 95:
                                next();
                                state = 79;
                                break;
                            case 48:
                                next();
                                state = 79;
                                break;
                            case 70:
                                next();
                                state = 79;
                                break;
                            case 117:
                                next();
                                state = 79;
                                break;
                            case 55:
                                next();
                                state = 79;
                                break;
                            case 98:
                                next();
                                state = 79;
                                break;
                            case 51:
                                next();
                                state = 79;
                                break;
                            case 50:
                                next();
                                state = 79;
                                break;
                            case 97:
                                next();
                                state = 79;
                                break;
                            case 80:
                                next();
                                state = 79;
                                break;
                            case 79:
                                next();
                                state = 79;
                                break;
                            case 78:
                                next();
                                state = 79;
                                break;
                            case 77:
                                next();
                                state = 79;
                                break;
                            case 76:
                                next();
                                state = 79;
                                break;
                            case 65:
                                next();
                                state = 79;
                                break;
                            case 112:
                                next();
                                state = 79;
                                break;
                            case 88:
                                next();
                                state = 79;
                                break;
                            case 89:
                                next();
                                state = 79;
                                break;
                            case 66:
                                next();
                                state = 79;
                                break;
                            case 113:
                                next();
                                state = 79;
                                break;
                            case 87:
                                next();
                                state = 79;
                                break;
                            case 116:
                                next();
                                state = 79;
                                break;
                            case 69:
                                next();
                                state = 79;
                                break;
                            case 115:
                                next();
                                state = 79;
                                break;
                            case 68:
                                next();
                                state = 79;
                                break;
                            case 114:
                                next();
                                state = 79;
                                break;
                            case 67:
                                next();
                                state = 79;
                                break;
                            case 90:
                                next();
                                state = 79;
                                break;
                            case 99:
                                next();
                                state = 79;
                                break;
                            case 52:
                                next();
                                state = 79;
                                break;
                            case 100:
                                next();
                                state = 79;
                                break;
                            case 53:
                                next();
                                state = 79;
                                break;
                            case 101:
                                next();
                                state = 79;
                                break;
                            case 54:
                                next();
                                state = 79;
                                break;
                            case 111:
                                next();
                                state = 79;
                                break;
                            case 110:
                                next();
                                state = 79;
                                break;
                            case 86:
                                next();
                                state = 79;
                                break;
                            case 109:
                                next();
                                state = 79;
                                break;
                            case 85:
                                next();
                                state = 79;
                                break;
                            case 108:
                                next();
                                state = 79;
                                break;
                            case 84:
                                next();
                                state = 79;
                                break;
                            case 107:
                                next();
                                state = 79;
                                break;
                            case 83:
                                next();
                                state = 79;
                                break;
                            case 106:
                                next();
                                state = 79;
                                break;
                            case 82:
                                next();
                                state = 79;
                                break;
                            case 105:
                                next();
                                state = 79;
                                break;
                            case 104:
                                next();
                                state = 79;
                                break;
                            case 57:
                                next();
                                state = 79;
                                break;
                            case 103:
                                next();
                                state = 79;
                                break;
                            case 56:
                                next();
                                state = 79;
                                break;
                            case 102:
                                next();
                                state = 79;
                                break;
                            default:
                                m_semantic.type(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 10:
                        switch (c) {
                            case 49:
                                next();
                                state = 79;
                                break;
                            case 71:
                                next();
                                state = 79;
                                break;
                            case 118:
                                next();
                                state = 79;
                                break;
                            case 72:
                                next();
                                state = 79;
                                break;
                            case 119:
                                next();
                                state = 79;
                                break;
                            case 74:
                                next();
                                state = 79;
                                break;
                            case 121:
                                next();
                                state = 79;
                                break;
                            case 75:
                                next();
                                state = 79;
                                break;
                            case 122:
                                next();
                                state = 79;
                                break;
                            case 73:
                                next();
                                state = 79;
                                break;
                            case 120:
                                next();
                                state = 79;
                                break;
                            case 95:
                                next();
                                state = 79;
                                break;
                            case 48:
                                next();
                                state = 79;
                                break;
                            case 70:
                                next();
                                state = 79;
                                break;
                            case 117:
                                next();
                                state = 79;
                                break;
                            case 86:
                                next();
                                state = 79;
                                break;
                            case 56:
                                next();
                                state = 79;
                                break;
                            case 98:
                                next();
                                state = 79;
                                break;
                            case 51:
                                next();
                                state = 79;
                                break;
                            case 50:
                                next();
                                state = 79;
                                break;
                            case 97:
                                next();
                                state = 79;
                                break;
                            case 81:
                                next();
                                state = 79;
                                break;
                            case 80:
                                next();
                                state = 79;
                                break;
                            case 79:
                                next();
                                state = 79;
                                break;
                            case 78:
                                next();
                                state = 79;
                                break;
                            case 77:
                                next();
                                state = 79;
                                break;
                            case 76:
                                next();
                                state = 79;
                                break;
                            case 65:
                                next();
                                state = 79;
                                break;
                            case 112:
                                next();
                                state = 28;
                                break;
                            case 88:
                                next();
                                state = 79;
                                break;
                            case 66:
                                next();
                                state = 79;
                                break;
                            case 113:
                                next();
                                state = 79;
                                break;
                            case 87:
                                next();
                                state = 79;
                                break;
                            case 116:
                                next();
                                state = 79;
                                break;
                            case 69:
                                next();
                                state = 79;
                                break;
                            case 115:
                                next();
                                state = 79;
                                break;
                            case 68:
                                next();
                                state = 79;
                                break;
                            case 114:
                                next();
                                state = 79;
                                break;
                            case 67:
                                next();
                                state = 79;
                                break;
                            case 90:
                                next();
                                state = 79;
                                break;
                            case 99:
                                next();
                                state = 79;
                                break;
                            case 52:
                                next();
                                state = 79;
                                break;
                            case 100:
                                next();
                                state = 79;
                                break;
                            case 53:
                                next();
                                state = 79;
                                break;
                            case 101:
                                next();
                                state = 79;
                                break;
                            case 54:
                                next();
                                state = 79;
                                break;
                            case 102:
                                next();
                                state = 79;
                                break;
                            case 55:
                                next();
                                state = 79;
                                break;
                            case 89:
                                next();
                                state = 79;
                                break;
                            case 111:
                                next();
                                state = 79;
                                break;
                            case 110:
                                next();
                                state = 79;
                                break;
                            case 109:
                                next();
                                state = 79;
                                break;
                            case 85:
                                next();
                                state = 79;
                                break;
                            case 108:
                                next();
                                state = 79;
                                break;
                            case 84:
                                next();
                                state = 79;
                                break;
                            case 107:
                                next();
                                state = 79;
                                break;
                            case 83:
                                next();
                                state = 79;
                                break;
                            case 106:
                                next();
                                state = 79;
                                break;
                            case 82:
                                next();
                                state = 79;
                                break;
                            case 105:
                                next();
                                state = 79;
                                break;
                            case 104:
                                next();
                                state = 79;
                                break;
                            case 57:
                                next();
                                state = 79;
                                break;
                            case 103:
                                next();
                                state = 79;
                                break;
                            default:
                                m_semantic.id(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 11:
                        m_semantic.lsquare(m_lexeme.str());
                        return true;
                    case 12:
                        switch (c) {
                            case 49:
                                next();
                                state = 79;
                                break;
                            case 71:
                                next();
                                state = 79;
                                break;
                            case 118:
                                next();
                                state = 79;
                                break;
                            case 72:
                                next();
                                state = 79;
                                break;
                            case 119:
                                next();
                                state = 79;
                                break;
                            case 74:
                                next();
                                state = 79;
                                break;
                            case 121:
                                next();
                                state = 79;
                                break;
                            case 75:
                                next();
                                state = 79;
                                break;
                            case 122:
                                next();
                                state = 79;
                                break;
                            case 73:
                                next();
                                state = 79;
                                break;
                            case 120:
                                next();
                                state = 79;
                                break;
                            case 95:
                                next();
                                state = 79;
                                break;
                            case 48:
                                next();
                                state = 79;
                                break;
                            case 70:
                                next();
                                state = 79;
                                break;
                            case 117:
                                next();
                                state = 79;
                                break;
                            case 86:
                                next();
                                state = 79;
                                break;
                            case 57:
                                next();
                                state = 79;
                                break;
                            case 98:
                                next();
                                state = 79;
                                break;
                            case 51:
                                next();
                                state = 79;
                                break;
                            case 50:
                                next();
                                state = 79;
                                break;
                            case 97:
                                next();
                                state = 79;
                                break;
                            case 81:
                                next();
                                state = 79;
                                break;
                            case 80:
                                next();
                                state = 79;
                                break;
                            case 79:
                                next();
                                state = 79;
                                break;
                            case 78:
                                next();
                                state = 79;
                                break;
                            case 77:
                                next();
                                state = 79;
                                break;
                            case 76:
                                next();
                                state = 79;
                                break;
                            case 65:
                                next();
                                state = 79;
                                break;
                            case 112:
                                next();
                                state = 79;
                                break;
                            case 88:
                                next();
                                state = 79;
                                break;
                            case 87:
                                next();
                                state = 79;
                                break;
                            case 116:
                                next();
                                state = 79;
                                break;
                            case 69:
                                next();
                                state = 79;
                                break;
                            case 115:
                                next();
                                state = 79;
                                break;
                            case 68:
                                next();
                                state = 79;
                                break;
                            case 89:
                                next();
                                state = 79;
                                break;
                            case 66:
                                next();
                                state = 79;
                                break;
                            case 113:
                                next();
                                state = 79;
                                break;
                            case 90:
                                next();
                                state = 79;
                                break;
                            case 67:
                                next();
                                state = 79;
                                break;
                            case 114:
                                next();
                                state = 38;
                                break;
                            case 99:
                                next();
                                state = 79;
                                break;
                            case 52:
                                next();
                                state = 79;
                                break;
                            case 100:
                                next();
                                state = 79;
                                break;
                            case 53:
                                next();
                                state = 79;
                                break;
                            case 101:
                                next();
                                state = 79;
                                break;
                            case 54:
                                next();
                                state = 79;
                                break;
                            case 102:
                                next();
                                state = 79;
                                break;
                            case 55:
                                next();
                                state = 79;
                                break;
                            case 103:
                                next();
                                state = 79;
                                break;
                            case 56:
                                next();
                                state = 79;
                                break;
                            case 111:
                                next();
                                state = 79;
                                break;
                            case 110:
                                next();
                                state = 79;
                                break;
                            case 109:
                                next();
                                state = 79;
                                break;
                            case 85:
                                next();
                                state = 79;
                                break;
                            case 108:
                                next();
                                state = 79;
                                break;
                            case 84:
                                next();
                                state = 79;
                                break;
                            case 107:
                                next();
                                state = 79;
                                break;
                            case 83:
                                next();
                                state = 79;
                                break;
                            case 106:
                                next();
                                state = 79;
                                break;
                            case 82:
                                next();
                                state = 79;
                                break;
                            case 105:
                                next();
                                state = 79;
                                break;
                            case 104:
                                next();
                                state = 79;
                                break;
                            default:
                                m_semantic.id(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 13:
                        m_semantic.rparen(m_lexeme.str());
                        return true;
                    case 14:
                        switch (c) {
                            case 103:
                                next();
                                state = 79;
                                break;
                            case 57:
                                next();
                                state = 79;
                                break;
                            case 104:
                                next();
                                state = 79;
                                break;
                            case 105:
                                next();
                                state = 79;
                                break;
                            case 82:
                                next();
                                state = 79;
                                break;
                            case 106:
                                next();
                                state = 79;
                                break;
                            case 83:
                                next();
                                state = 79;
                                break;
                            case 107:
                                next();
                                state = 79;
                                break;
                            case 84:
                                next();
                                state = 79;
                                break;
                            case 108:
                                next();
                                state = 79;
                                break;
                            case 85:
                                next();
                                state = 79;
                                break;
                            case 109:
                                next();
                                state = 79;
                                break;
                            case 111:
                                next();
                                state = 79;
                                break;
                            case 110:
                                next();
                                state = 79;
                                break;
                            case 55:
                                next();
                                state = 79;
                                break;
                            case 102:
                                next();
                                state = 79;
                                break;
                            case 54:
                                next();
                                state = 79;
                                break;
                            case 81:
                                next();
                                state = 79;
                                break;
                            case 56:
                                next();
                                state = 79;
                                break;
                            case 86:
                                next();
                                state = 79;
                                break;
                            case 70:
                                next();
                                state = 79;
                                break;
                            case 117:
                                next();
                                state = 79;
                                break;
                            case 48:
                                next();
                                state = 79;
                                break;
                            case 95:
                                next();
                                state = 79;
                                break;
                            case 71:
                                next();
                                state = 79;
                                break;
                            case 118:
                                next();
                                state = 79;
                                break;
                            case 97:
                                next();
                                state = 12;
                                break;
                            case 50:
                                next();
                                state = 79;
                                break;
                            case 51:
                                next();
                                state = 79;
                                break;
                            case 98:
                                next();
                                state = 79;
                                break;
                            case 120:
                                next();
                                state = 79;
                                break;
                            case 73:
                                next();
                                state = 79;
                                break;
                            case 74:
                                next();
                                state = 79;
                                break;
                            case 121:
                                next();
                                state = 79;
                                break;
                            case 49:
                                next();
                                state = 79;
                                break;
                            case 72:
                                next();
                                state = 79;
                                break;
                            case 119:
                                next();
                                state = 79;
                                break;
                            case 75:
                                next();
                                state = 79;
                                break;
                            case 122:
                                next();
                                state = 79;
                                break;
                            case 80:
                                next();
                                state = 79;
                                break;
                            case 79:
                                next();
                                state = 79;
                                break;
                            case 78:
                                next();
                                state = 79;
                                break;
                            case 77:
                                next();
                                state = 79;
                                break;
                            case 76:
                                next();
                                state = 79;
                                break;
                            case 65:
                                next();
                                state = 79;
                                break;
                            case 112:
                                next();
                                state = 79;
                                break;
                            case 88:
                                next();
                                state = 79;
                                break;
                            case 89:
                                next();
                                state = 79;
                                break;
                            case 66:
                                next();
                                state = 79;
                                break;
                            case 113:
                                next();
                                state = 79;
                                break;
                            case 87:
                                next();
                                state = 79;
                                break;
                            case 116:
                                next();
                                state = 79;
                                break;
                            case 69:
                                next();
                                state = 79;
                                break;
                            case 115:
                                next();
                                state = 79;
                                break;
                            case 68:
                                next();
                                state = 79;
                                break;
                            case 114:
                                next();
                                state = 79;
                                break;
                            case 67:
                                next();
                                state = 79;
                                break;
                            case 90:
                                next();
                                state = 79;
                                break;
                            case 99:
                                next();
                                state = 79;
                                break;
                            case 52:
                                next();
                                state = 79;
                                break;
                            case 100:
                                next();
                                state = 79;
                                break;
                            case 53:
                                next();
                                state = 79;
                                break;
                            case 101:
                                next();
                                state = 79;
                                break;
                            default:
                                m_semantic.id(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 15:
                        m_semantic.sub(m_lexeme.str());
                        return true;
                    case 16:
                        switch (c) {
                            case 81:
                                next();
                                state = 79;
                                break;
                            case 49:
                                next();
                                state = 79;
                                break;
                            case 71:
                                next();
                                state = 79;
                                break;
                            case 118:
                                next();
                                state = 79;
                                break;
                            case 72:
                                next();
                                state = 79;
                                break;
                            case 119:
                                next();
                                state = 79;
                                break;
                            case 74:
                                next();
                                state = 79;
                                break;
                            case 121:
                                next();
                                state = 79;
                                break;
                            case 75:
                                next();
                                state = 79;
                                break;
                            case 122:
                                next();
                                state = 79;
                                break;
                            case 73:
                                next();
                                state = 79;
                                break;
                            case 120:
                                next();
                                state = 79;
                                break;
                            case 95:
                                next();
                                state = 79;
                                break;
                            case 48:
                                next();
                                state = 79;
                                break;
                            case 70:
                                next();
                                state = 79;
                                break;
                            case 117:
                                next();
                                state = 79;
                                break;
                            case 55:
                                next();
                                state = 79;
                                break;
                            case 98:
                                next();
                                state = 79;
                                break;
                            case 51:
                                next();
                                state = 79;
                                break;
                            case 50:
                                next();
                                state = 79;
                                break;
                            case 97:
                                next();
                                state = 79;
                                break;
                            case 80:
                                next();
                                state = 79;
                                break;
                            case 79:
                                next();
                                state = 79;
                                break;
                            case 78:
                                next();
                                state = 79;
                                break;
                            case 77:
                                next();
                                state = 79;
                                break;
                            case 76:
                                next();
                                state = 79;
                                break;
                            case 65:
                                next();
                                state = 79;
                                break;
                            case 112:
                                next();
                                state = 79;
                                break;
                            case 88:
                                next();
                                state = 79;
                                break;
                            case 89:
                                next();
                                state = 79;
                                break;
                            case 66:
                                next();
                                state = 79;
                                break;
                            case 113:
                                next();
                                state = 79;
                                break;
                            case 87:
                                next();
                                state = 79;
                                break;
                            case 116:
                                next();
                                state = 79;
                                break;
                            case 69:
                                next();
                                state = 79;
                                break;
                            case 115:
                                next();
                                state = 79;
                                break;
                            case 68:
                                next();
                                state = 79;
                                break;
                            case 114:
                                next();
                                state = 79;
                                break;
                            case 67:
                                next();
                                state = 79;
                                break;
                            case 90:
                                next();
                                state = 79;
                                break;
                            case 99:
                                next();
                                state = 79;
                                break;
                            case 52:
                                next();
                                state = 79;
                                break;
                            case 100:
                                next();
                                state = 79;
                                break;
                            case 53:
                                next();
                                state = 79;
                                break;
                            case 101:
                                next();
                                state = 79;
                                break;
                            case 54:
                                next();
                                state = 79;
                                break;
                            case 111:
                                next();
                                state = 79;
                                break;
                            case 110:
                                next();
                                state = 79;
                                break;
                            case 86:
                                next();
                                state = 79;
                                break;
                            case 109:
                                next();
                                state = 79;
                                break;
                            case 85:
                                next();
                                state = 79;
                                break;
                            case 108:
                                next();
                                state = 79;
                                break;
                            case 84:
                                next();
                                state = 79;
                                break;
                            case 107:
                                next();
                                state = 79;
                                break;
                            case 83:
                                next();
                                state = 79;
                                break;
                            case 106:
                                next();
                                state = 79;
                                break;
                            case 82:
                                next();
                                state = 79;
                                break;
                            case 105:
                                next();
                                state = 79;
                                break;
                            case 104:
                                next();
                                state = 79;
                                break;
                            case 57:
                                next();
                                state = 79;
                                break;
                            case 103:
                                next();
                                state = 79;
                                break;
                            case 56:
                                next();
                                state = 79;
                                break;
                            case 102:
                                next();
                                state = 79;
                                break;
                            default:
                                m_semantic.constt(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 17:
                        switch (c) {
                            case 81:
                                next();
                                state = 79;
                                break;
                            case 49:
                                next();
                                state = 79;
                                break;
                            case 71:
                                next();
                                state = 79;
                                break;
                            case 118:
                                next();
                                state = 79;
                                break;
                            case 72:
                                next();
                                state = 79;
                                break;
                            case 119:
                                next();
                                state = 79;
                                break;
                            case 74:
                                next();
                                state = 79;
                                break;
                            case 121:
                                next();
                                state = 79;
                                break;
                            case 75:
                                next();
                                state = 79;
                                break;
                            case 122:
                                next();
                                state = 79;
                                break;
                            case 73:
                                next();
                                state = 79;
                                break;
                            case 120:
                                next();
                                state = 79;
                                break;
                            case 95:
                                next();
                                state = 79;
                                break;
                            case 48:
                                next();
                                state = 79;
                                break;
                            case 70:
                                next();
                                state = 79;
                                break;
                            case 117:
                                next();
                                state = 79;
                                break;
                            case 56:
                                next();
                                state = 79;
                                break;
                            case 98:
                                next();
                                state = 79;
                                break;
                            case 51:
                                next();
                                state = 79;
                                break;
                            case 50:
                                next();
                                state = 79;
                                break;
                            case 97:
                                next();
                                state = 79;
                                break;
                            case 80:
                                next();
                                state = 79;
                                break;
                            case 79:
                                next();
                                state = 79;
                                break;
                            case 78:
                                next();
                                state = 79;
                                break;
                            case 77:
                                next();
                                state = 79;
                                break;
                            case 76:
                                next();
                                state = 79;
                                break;
                            case 65:
                                next();
                                state = 79;
                                break;
                            case 112:
                                next();
                                state = 79;
                                break;
                            case 88:
                                next();
                                state = 79;
                                break;
                            case 89:
                                next();
                                state = 79;
                                break;
                            case 66:
                                next();
                                state = 79;
                                break;
                            case 113:
                                next();
                                state = 79;
                                break;
                            case 87:
                                next();
                                state = 79;
                                break;
                            case 116:
                                next();
                                state = 79;
                                break;
                            case 69:
                                next();
                                state = 79;
                                break;
                            case 115:
                                next();
                                state = 79;
                                break;
                            case 68:
                                next();
                                state = 79;
                                break;
                            case 114:
                                next();
                                state = 79;
                                break;
                            case 67:
                                next();
                                state = 79;
                                break;
                            case 90:
                                next();
                                state = 79;
                                break;
                            case 99:
                                next();
                                state = 79;
                                break;
                            case 52:
                                next();
                                state = 79;
                                break;
                            case 100:
                                next();
                                state = 79;
                                break;
                            case 53:
                                next();
                                state = 79;
                                break;
                            case 102:
                                next();
                                state = 79;
                                break;
                            case 55:
                                next();
                                state = 79;
                                break;
                            case 101:
                                next();
                                state = 45;
                                break;
                            case 54:
                                next();
                                state = 79;
                                break;
                            case 111:
                                next();
                                state = 79;
                                break;
                            case 110:
                                next();
                                state = 79;
                                break;
                            case 86:
                                next();
                                state = 79;
                                break;
                            case 109:
                                next();
                                state = 79;
                                break;
                            case 85:
                                next();
                                state = 79;
                                break;
                            case 108:
                                next();
                                state = 79;
                                break;
                            case 84:
                                next();
                                state = 79;
                                break;
                            case 107:
                                next();
                                state = 79;
                                break;
                            case 83:
                                next();
                                state = 79;
                                break;
                            case 106:
                                next();
                                state = 79;
                                break;
                            case 82:
                                next();
                                state = 79;
                                break;
                            case 105:
                                next();
                                state = 79;
                                break;
                            case 104:
                                next();
                                state = 79;
                                break;
                            case 57:
                                next();
                                state = 79;
                                break;
                            case 103:
                                next();
                                state = 79;
                                break;
                            default:
                                m_semantic.id(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 18:
                        switch (c) {
                            case 81:
                                next();
                                state = 79;
                                break;
                            case 49:
                                next();
                                state = 79;
                                break;
                            case 71:
                                next();
                                state = 79;
                                break;
                            case 118:
                                next();
                                state = 79;
                                break;
                            case 72:
                                next();
                                state = 79;
                                break;
                            case 119:
                                next();
                                state = 79;
                                break;
                            case 74:
                                next();
                                state = 79;
                                break;
                            case 121:
                                next();
                                state = 79;
                                break;
                            case 75:
                                next();
                                state = 79;
                                break;
                            case 122:
                                next();
                                state = 79;
                                break;
                            case 73:
                                next();
                                state = 79;
                                break;
                            case 120:
                                next();
                                state = 79;
                                break;
                            case 95:
                                next();
                                state = 79;
                                break;
                            case 48:
                                next();
                                state = 79;
                                break;
                            case 70:
                                next();
                                state = 79;
                                break;
                            case 117:
                                next();
                                state = 79;
                                break;
                            case 55:
                                next();
                                state = 79;
                                break;
                            case 98:
                                next();
                                state = 79;
                                break;
                            case 51:
                                next();
                                state = 79;
                                break;
                            case 50:
                                next();
                                state = 79;
                                break;
                            case 97:
                                next();
                                state = 79;
                                break;
                            case 80:
                                next();
                                state = 79;
                                break;
                            case 79:
                                next();
                                state = 79;
                                break;
                            case 78:
                                next();
                                state = 79;
                                break;
                            case 77:
                                next();
                                state = 79;
                                break;
                            case 76:
                                next();
                                state = 79;
                                break;
                            case 65:
                                next();
                                state = 79;
                                break;
                            case 112:
                                next();
                                state = 79;
                                break;
                            case 88:
                                next();
                                state = 79;
                                break;
                            case 89:
                                next();
                                state = 79;
                                break;
                            case 66:
                                next();
                                state = 79;
                                break;
                            case 113:
                                next();
                                state = 79;
                                break;
                            case 87:
                                next();
                                state = 79;
                                break;
                            case 116:
                                next();
                                state = 79;
                                break;
                            case 69:
                                next();
                                state = 79;
                                break;
                            case 115:
                                next();
                                state = 79;
                                break;
                            case 68:
                                next();
                                state = 79;
                                break;
                            case 114:
                                next();
                                state = 79;
                                break;
                            case 67:
                                next();
                                state = 79;
                                break;
                            case 90:
                                next();
                                state = 79;
                                break;
                            case 99:
                                next();
                                state = 31;
                                break;
                            case 52:
                                next();
                                state = 79;
                                break;
                            case 100:
                                next();
                                state = 79;
                                break;
                            case 53:
                                next();
                                state = 79;
                                break;
                            case 101:
                                next();
                                state = 79;
                                break;
                            case 54:
                                next();
                                state = 79;
                                break;
                            case 111:
                                next();
                                state = 79;
                                break;
                            case 110:
                                next();
                                state = 79;
                                break;
                            case 86:
                                next();
                                state = 79;
                                break;
                            case 109:
                                next();
                                state = 79;
                                break;
                            case 85:
                                next();
                                state = 79;
                                break;
                            case 108:
                                next();
                                state = 79;
                                break;
                            case 84:
                                next();
                                state = 79;
                                break;
                            case 107:
                                next();
                                state = 79;
                                break;
                            case 83:
                                next();
                                state = 79;
                                break;
                            case 106:
                                next();
                                state = 79;
                                break;
                            case 82:
                                next();
                                state = 79;
                                break;
                            case 105:
                                next();
                                state = 79;
                                break;
                            case 104:
                                next();
                                state = 79;
                                break;
                            case 57:
                                next();
                                state = 79;
                                break;
                            case 103:
                                next();
                                state = 79;
                                break;
                            case 56:
                                next();
                                state = 79;
                                break;
                            case 102:
                                next();
                                state = 79;
                                break;
                            default:
                                m_semantic.id(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 19:
                        switch (c) {
                            case 103:
                                next();
                                state = 79;
                                break;
                            case 57:
                                next();
                                state = 79;
                                break;
                            case 104:
                                next();
                                state = 79;
                                break;
                            case 105:
                                next();
                                state = 79;
                                break;
                            case 82:
                                next();
                                state = 79;
                                break;
                            case 106:
                                next();
                                state = 79;
                                break;
                            case 83:
                                next();
                                state = 79;
                                break;
                            case 107:
                                next();
                                state = 79;
                                break;
                            case 84:
                                next();
                                state = 79;
                                break;
                            case 108:
                                next();
                                state = 79;
                                break;
                            case 85:
                                next();
                                state = 79;
                                break;
                            case 109:
                                next();
                                state = 79;
                                break;
                            case 111:
                                next();
                                state = 79;
                                break;
                            case 110:
                                next();
                                state = 79;
                                break;
                            case 55:
                                next();
                                state = 79;
                                break;
                            case 102:
                                next();
                                state = 79;
                                break;
                            case 54:
                                next();
                                state = 79;
                                break;
                            case 81:
                                next();
                                state = 79;
                                break;
                            case 56:
                                next();
                                state = 79;
                                break;
                            case 86:
                                next();
                                state = 79;
                                break;
                            case 70:
                                next();
                                state = 79;
                                break;
                            case 117:
                                next();
                                state = 43;
                                break;
                            case 48:
                                next();
                                state = 79;
                                break;
                            case 95:
                                next();
                                state = 79;
                                break;
                            case 71:
                                next();
                                state = 79;
                                break;
                            case 118:
                                next();
                                state = 79;
                                break;
                            case 97:
                                next();
                                state = 79;
                                break;
                            case 50:
                                next();
                                state = 79;
                                break;
                            case 51:
                                next();
                                state = 79;
                                break;
                            case 98:
                                next();
                                state = 79;
                                break;
                            case 120:
                                next();
                                state = 79;
                                break;
                            case 73:
                                next();
                                state = 79;
                                break;
                            case 74:
                                next();
                                state = 79;
                                break;
                            case 121:
                                next();
                                state = 79;
                                break;
                            case 49:
                                next();
                                state = 79;
                                break;
                            case 72:
                                next();
                                state = 79;
                                break;
                            case 119:
                                next();
                                state = 79;
                                break;
                            case 75:
                                next();
                                state = 79;
                                break;
                            case 122:
                                next();
                                state = 79;
                                break;
                            case 80:
                                next();
                                state = 79;
                                break;
                            case 79:
                                next();
                                state = 79;
                                break;
                            case 78:
                                next();
                                state = 79;
                                break;
                            case 77:
                                next();
                                state = 79;
                                break;
                            case 76:
                                next();
                                state = 79;
                                break;
                            case 65:
                                next();
                                state = 79;
                                break;
                            case 112:
                                next();
                                state = 79;
                                break;
                            case 88:
                                next();
                                state = 79;
                                break;
                            case 89:
                                next();
                                state = 79;
                                break;
                            case 66:
                                next();
                                state = 79;
                                break;
                            case 113:
                                next();
                                state = 79;
                                break;
                            case 87:
                                next();
                                state = 79;
                                break;
                            case 116:
                                next();
                                state = 79;
                                break;
                            case 69:
                                next();
                                state = 79;
                                break;
                            case 115:
                                next();
                                state = 79;
                                break;
                            case 68:
                                next();
                                state = 79;
                                break;
                            case 114:
                                next();
                                state = 79;
                                break;
                            case 67:
                                next();
                                state = 79;
                                break;
                            case 90:
                                next();
                                state = 79;
                                break;
                            case 99:
                                next();
                                state = 79;
                                break;
                            case 52:
                                next();
                                state = 79;
                                break;
                            case 100:
                                next();
                                state = 79;
                                break;
                            case 53:
                                next();
                                state = 79;
                                break;
                            case 101:
                                next();
                                state = 79;
                                break;
                            default:
                                m_semantic.id(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 20:
                        switch (c) {
                            case 81:
                                next();
                                state = 79;
                                break;
                            case 49:
                                next();
                                state = 79;
                                break;
                            case 71:
                                next();
                                state = 79;
                                break;
                            case 118:
                                next();
                                state = 79;
                                break;
                            case 72:
                                next();
                                state = 79;
                                break;
                            case 119:
                                next();
                                state = 79;
                                break;
                            case 75:
                                next();
                                state = 79;
                                break;
                            case 122:
                                next();
                                state = 79;
                                break;
                            case 73:
                                next();
                                state = 79;
                                break;
                            case 120:
                                next();
                                state = 79;
                                break;
                            case 95:
                                next();
                                state = 79;
                                break;
                            case 48:
                                next();
                                state = 79;
                                break;
                            case 70:
                                next();
                                state = 79;
                                break;
                            case 117:
                                next();
                                state = 79;
                                break;
                            case 86:
                                next();
                                state = 79;
                                break;
                            case 56:
                                next();
                                state = 79;
                                break;
                            case 103:
                                next();
                                state = 79;
                                break;
                            case 50:
                                next();
                                state = 79;
                                break;
                            case 97:
                                next();
                                state = 79;
                                break;
                            case 80:
                                next();
                                state = 79;
                                break;
                            case 79:
                                next();
                                state = 79;
                                break;
                            case 78:
                                next();
                                state = 79;
                                break;
                            case 77:
                                next();
                                state = 79;
                                break;
                            case 99:
                                next();
                                state = 79;
                                break;
                            case 52:
                                next();
                                state = 79;
                                break;
                            case 76:
                                next();
                                state = 79;
                                break;
                            case 65:
                                next();
                                state = 79;
                                break;
                            case 112:
                                next();
                                state = 79;
                                break;
                            case 88:
                                next();
                                state = 79;
                                break;
                            case 89:
                                next();
                                state = 79;
                                break;
                            case 66:
                                next();
                                state = 79;
                                break;
                            case 113:
                                next();
                                state = 79;
                                break;
                            case 87:
                                next();
                                state = 79;
                                break;
                            case 116:
                                next();
                                state = 79;
                                break;
                            case 69:
                                next();
                                state = 79;
                                break;
                            case 115:
                                next();
                                state = 79;
                                break;
                            case 68:
                                next();
                                state = 79;
                                break;
                            case 114:
                                next();
                                state = 79;
                                break;
                            case 67:
                                next();
                                state = 79;
                                break;
                            case 90:
                                next();
                                state = 79;
                                break;
                            case 100:
                                next();
                                state = 79;
                                break;
                            case 53:
                                next();
                                state = 79;
                                break;
                            case 101:
                                next();
                                state = 79;
                                break;
                            case 54:
                                next();
                                state = 79;
                                break;
                            case 102:
                                next();
                                state = 79;
                                break;
                            case 55:
                                next();
                                state = 79;
                                break;
                            case 98:
                                next();
                                state = 79;
                                break;
                            case 51:
                                next();
                                state = 79;
                                break;
                            case 121:
                                next();
                                state = 26;
                                break;
                            case 74:
                                next();
                                state = 79;
                                break;
                            case 110:
                                next();
                                state = 79;
                                break;
                            case 111:
                                next();
                                state = 79;
                                break;
                            case 109:
                                next();
                                state = 79;
                                break;
                            case 85:
                                next();
                                state = 79;
                                break;
                            case 108:
                                next();
                                state = 79;
                                break;
                            case 84:
                                next();
                                state = 79;
                                break;
                            case 107:
                                next();
                                state = 79;
                                break;
                            case 83:
                                next();
                                state = 79;
                                break;
                            case 106:
                                next();
                                state = 79;
                                break;
                            case 82:
                                next();
                                state = 79;
                                break;
                            case 105:
                                next();
                                state = 79;
                                break;
                            case 104:
                                next();
                                state = 79;
                                break;
                            case 57:
                                next();
                                state = 79;
                                break;
                            default:
                                m_semantic.id(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 21:
                        switch (c) {
                            case 81:
                                next();
                                state = 79;
                                break;
                            case 49:
                                next();
                                state = 79;
                                break;
                            case 71:
                                next();
                                state = 79;
                                break;
                            case 118:
                                next();
                                state = 79;
                                break;
                            case 72:
                                next();
                                state = 79;
                                break;
                            case 119:
                                next();
                                state = 79;
                                break;
                            case 74:
                                next();
                                state = 79;
                                break;
                            case 121:
                                next();
                                state = 79;
                                break;
                            case 75:
                                next();
                                state = 79;
                                break;
                            case 122:
                                next();
                                state = 79;
                                break;
                            case 73:
                                next();
                                state = 79;
                                break;
                            case 120:
                                next();
                                state = 79;
                                break;
                            case 95:
                                next();
                                state = 79;
                                break;
                            case 48:
                                next();
                                state = 79;
                                break;
                            case 70:
                                next();
                                state = 79;
                                break;
                            case 117:
                                next();
                                state = 79;
                                break;
                            case 56:
                                next();
                                state = 79;
                                break;
                            case 98:
                                next();
                                state = 79;
                                break;
                            case 51:
                                next();
                                state = 79;
                                break;
                            case 50:
                                next();
                                state = 79;
                                break;
                            case 97:
                                next();
                                state = 79;
                                break;
                            case 80:
                                next();
                                state = 79;
                                break;
                            case 79:
                                next();
                                state = 79;
                                break;
                            case 78:
                                next();
                                state = 79;
                                break;
                            case 77:
                                next();
                                state = 79;
                                break;
                            case 76:
                                next();
                                state = 79;
                                break;
                            case 65:
                                next();
                                state = 79;
                                break;
                            case 112:
                                next();
                                state = 79;
                                break;
                            case 88:
                                next();
                                state = 79;
                                break;
                            case 89:
                                next();
                                state = 79;
                                break;
                            case 66:
                                next();
                                state = 79;
                                break;
                            case 113:
                                next();
                                state = 79;
                                break;
                            case 87:
                                next();
                                state = 79;
                                break;
                            case 116:
                                next();
                                state = 79;
                                break;
                            case 69:
                                next();
                                state = 79;
                                break;
                            case 115:
                                next();
                                state = 79;
                                break;
                            case 68:
                                next();
                                state = 79;
                                break;
                            case 114:
                                next();
                                state = 79;
                                break;
                            case 67:
                                next();
                                state = 79;
                                break;
                            case 90:
                                next();
                                state = 79;
                                break;
                            case 100:
                                next();
                                state = 79;
                                break;
                            case 53:
                                next();
                                state = 79;
                                break;
                            case 101:
                                next();
                                state = 79;
                                break;
                            case 54:
                                next();
                                state = 79;
                                break;
                            case 102:
                                next();
                                state = 79;
                                break;
                            case 55:
                                next();
                                state = 79;
                                break;
                            case 99:
                                next();
                                state = 97;
                                break;
                            case 52:
                                next();
                                state = 79;
                                break;
                            case 110:
                                next();
                                state = 79;
                                break;
                            case 111:
                                next();
                                state = 79;
                                break;
                            case 86:
                                next();
                                state = 79;
                                break;
                            case 109:
                                next();
                                state = 79;
                                break;
                            case 85:
                                next();
                                state = 79;
                                break;
                            case 108:
                                next();
                                state = 79;
                                break;
                            case 84:
                                next();
                                state = 79;
                                break;
                            case 107:
                                next();
                                state = 79;
                                break;
                            case 83:
                                next();
                                state = 79;
                                break;
                            case 106:
                                next();
                                state = 79;
                                break;
                            case 82:
                                next();
                                state = 79;
                                break;
                            case 105:
                                next();
                                state = 79;
                                break;
                            case 104:
                                next();
                                state = 79;
                                break;
                            case 57:
                                next();
                                state = 79;
                                break;
                            case 103:
                                next();
                                state = 79;
                                break;
                            default:
                                m_semantic.id(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 22:
                        m_semantic.mul(m_lexeme.str());
                        return true;
                    case 23:
                        switch (c) {
                            case 103:
                                next();
                                state = 79;
                                break;
                            case 57:
                                next();
                                state = 79;
                                break;
                            case 104:
                                next();
                                state = 79;
                                break;
                            case 105:
                                next();
                                state = 79;
                                break;
                            case 82:
                                next();
                                state = 79;
                                break;
                            case 106:
                                next();
                                state = 79;
                                break;
                            case 83:
                                next();
                                state = 79;
                                break;
                            case 107:
                                next();
                                state = 79;
                                break;
                            case 84:
                                next();
                                state = 79;
                                break;
                            case 108:
                                next();
                                state = 79;
                                break;
                            case 85:
                                next();
                                state = 79;
                                break;
                            case 109:
                                next();
                                state = 79;
                                break;
                            case 111:
                                next();
                                state = 79;
                                break;
                            case 110:
                                next();
                                state = 52;
                                break;
                            case 55:
                                next();
                                state = 79;
                                break;
                            case 102:
                                next();
                                state = 79;
                                break;
                            case 54:
                                next();
                                state = 79;
                                break;
                            case 81:
                                next();
                                state = 79;
                                break;
                            case 56:
                                next();
                                state = 79;
                                break;
                            case 86:
                                next();
                                state = 79;
                                break;
                            case 70:
                                next();
                                state = 79;
                                break;
                            case 117:
                                next();
                                state = 79;
                                break;
                            case 48:
                                next();
                                state = 79;
                                break;
                            case 95:
                                next();
                                state = 79;
                                break;
                            case 71:
                                next();
                                state = 79;
                                break;
                            case 118:
                                next();
                                state = 79;
                                break;
                            case 97:
                                next();
                                state = 79;
                                break;
                            case 50:
                                next();
                                state = 79;
                                break;
                            case 51:
                                next();
                                state = 79;
                                break;
                            case 98:
                                next();
                                state = 79;
                                break;
                            case 120:
                                next();
                                state = 79;
                                break;
                            case 73:
                                next();
                                state = 79;
                                break;
                            case 74:
                                next();
                                state = 79;
                                break;
                            case 121:
                                next();
                                state = 79;
                                break;
                            case 49:
                                next();
                                state = 79;
                                break;
                            case 72:
                                next();
                                state = 79;
                                break;
                            case 119:
                                next();
                                state = 79;
                                break;
                            case 75:
                                next();
                                state = 79;
                                break;
                            case 122:
                                next();
                                state = 79;
                                break;
                            case 80:
                                next();
                                state = 79;
                                break;
                            case 79:
                                next();
                                state = 79;
                                break;
                            case 78:
                                next();
                                state = 79;
                                break;
                            case 77:
                                next();
                                state = 79;
                                break;
                            case 76:
                                next();
                                state = 79;
                                break;
                            case 65:
                                next();
                                state = 79;
                                break;
                            case 112:
                                next();
                                state = 79;
                                break;
                            case 88:
                                next();
                                state = 79;
                                break;
                            case 89:
                                next();
                                state = 79;
                                break;
                            case 66:
                                next();
                                state = 79;
                                break;
                            case 113:
                                next();
                                state = 79;
                                break;
                            case 87:
                                next();
                                state = 79;
                                break;
                            case 116:
                                next();
                                state = 79;
                                break;
                            case 69:
                                next();
                                state = 79;
                                break;
                            case 115:
                                next();
                                state = 79;
                                break;
                            case 68:
                                next();
                                state = 79;
                                break;
                            case 114:
                                next();
                                state = 113;
                                break;
                            case 67:
                                next();
                                state = 79;
                                break;
                            case 90:
                                next();
                                state = 79;
                                break;
                            case 99:
                                next();
                                state = 79;
                                break;
                            case 52:
                                next();
                                state = 79;
                                break;
                            case 100:
                                next();
                                state = 79;
                                break;
                            case 53:
                                next();
                                state = 79;
                                break;
                            case 101:
                                next();
                                state = 79;
                                break;
                            default:
                                m_semantic.id(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 24:
                        switch (c) {
                            case 103:
                                next();
                                state = 79;
                                break;
                            case 57:
                                next();
                                state = 79;
                                break;
                            case 104:
                                next();
                                state = 79;
                                break;
                            case 105:
                                next();
                                state = 79;
                                break;
                            case 82:
                                next();
                                state = 79;
                                break;
                            case 106:
                                next();
                                state = 79;
                                break;
                            case 83:
                                next();
                                state = 79;
                                break;
                            case 107:
                                next();
                                state = 79;
                                break;
                            case 84:
                                next();
                                state = 79;
                                break;
                            case 108:
                                next();
                                state = 79;
                                break;
                            case 85:
                                next();
                                state = 79;
                                break;
                            case 109:
                                next();
                                state = 79;
                                break;
                            case 111:
                                next();
                                state = 79;
                                break;
                            case 110:
                                next();
                                state = 79;
                                break;
                            case 55:
                                next();
                                state = 79;
                                break;
                            case 102:
                                next();
                                state = 40;
                                break;
                            case 54:
                                next();
                                state = 79;
                                break;
                            case 81:
                                next();
                                state = 79;
                                break;
                            case 56:
                                next();
                                state = 79;
                                break;
                            case 86:
                                next();
                                state = 79;
                                break;
                            case 70:
                                next();
                                state = 79;
                                break;
                            case 117:
                                next();
                                state = 79;
                                break;
                            case 48:
                                next();
                                state = 79;
                                break;
                            case 95:
                                next();
                                state = 79;
                                break;
                            case 71:
                                next();
                                state = 79;
                                break;
                            case 118:
                                next();
                                state = 79;
                                break;
                            case 97:
                                next();
                                state = 79;
                                break;
                            case 50:
                                next();
                                state = 79;
                                break;
                            case 51:
                                next();
                                state = 79;
                                break;
                            case 98:
                                next();
                                state = 79;
                                break;
                            case 120:
                                next();
                                state = 79;
                                break;
                            case 73:
                                next();
                                state = 79;
                                break;
                            case 74:
                                next();
                                state = 79;
                                break;
                            case 121:
                                next();
                                state = 79;
                                break;
                            case 49:
                                next();
                                state = 79;
                                break;
                            case 72:
                                next();
                                state = 79;
                                break;
                            case 119:
                                next();
                                state = 79;
                                break;
                            case 75:
                                next();
                                state = 79;
                                break;
                            case 122:
                                next();
                                state = 79;
                                break;
                            case 80:
                                next();
                                state = 79;
                                break;
                            case 79:
                                next();
                                state = 79;
                                break;
                            case 78:
                                next();
                                state = 79;
                                break;
                            case 77:
                                next();
                                state = 79;
                                break;
                            case 76:
                                next();
                                state = 79;
                                break;
                            case 65:
                                next();
                                state = 79;
                                break;
                            case 112:
                                next();
                                state = 79;
                                break;
                            case 88:
                                next();
                                state = 79;
                                break;
                            case 89:
                                next();
                                state = 79;
                                break;
                            case 66:
                                next();
                                state = 79;
                                break;
                            case 113:
                                next();
                                state = 79;
                                break;
                            case 87:
                                next();
                                state = 79;
                                break;
                            case 116:
                                next();
                                state = 79;
                                break;
                            case 69:
                                next();
                                state = 79;
                                break;
                            case 115:
                                next();
                                state = 79;
                                break;
                            case 68:
                                next();
                                state = 79;
                                break;
                            case 114:
                                next();
                                state = 79;
                                break;
                            case 67:
                                next();
                                state = 79;
                                break;
                            case 90:
                                next();
                                state = 79;
                                break;
                            case 99:
                                next();
                                state = 79;
                                break;
                            case 52:
                                next();
                                state = 79;
                                break;
                            case 100:
                                next();
                                state = 79;
                                break;
                            case 53:
                                next();
                                state = 79;
                                break;
                            case 101:
                                next();
                                state = 79;
                                break;
                            default:
                                m_semantic.id(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 25:
                        switch (c) {
                            case 81:
                                next();
                                state = 79;
                                break;
                            case 49:
                                next();
                                state = 79;
                                break;
                            case 71:
                                next();
                                state = 79;
                                break;
                            case 118:
                                next();
                                state = 79;
                                break;
                            case 72:
                                next();
                                state = 79;
                                break;
                            case 119:
                                next();
                                state = 79;
                                break;
                            case 74:
                                next();
                                state = 79;
                                break;
                            case 121:
                                next();
                                state = 79;
                                break;
                            case 75:
                                next();
                                state = 79;
                                break;
                            case 122:
                                next();
                                state = 79;
                                break;
                            case 73:
                                next();
                                state = 79;
                                break;
                            case 120:
                                next();
                                state = 79;
                                break;
                            case 95:
                                next();
                                state = 79;
                                break;
                            case 48:
                                next();
                                state = 79;
                                break;
                            case 70:
                                next();
                                state = 79;
                                break;
                            case 117:
                                next();
                                state = 79;
                                break;
                            case 55:
                                next();
                                state = 79;
                                break;
                            case 98:
                                next();
                                state = 79;
                                break;
                            case 51:
                                next();
                                state = 79;
                                break;
                            case 50:
                                next();
                                state = 79;
                                break;
                            case 97:
                                next();
                                state = 79;
                                break;
                            case 80:
                                next();
                                state = 79;
                                break;
                            case 79:
                                next();
                                state = 79;
                                break;
                            case 78:
                                next();
                                state = 79;
                                break;
                            case 77:
                                next();
                                state = 79;
                                break;
                            case 76:
                                next();
                                state = 79;
                                break;
                            case 65:
                                next();
                                state = 79;
                                break;
                            case 112:
                                next();
                                state = 79;
                                break;
                            case 88:
                                next();
                                state = 79;
                                break;
                            case 89:
                                next();
                                state = 79;
                                break;
                            case 66:
                                next();
                                state = 79;
                                break;
                            case 113:
                                next();
                                state = 79;
                                break;
                            case 87:
                                next();
                                state = 79;
                                break;
                            case 116:
                                next();
                                state = 79;
                                break;
                            case 69:
                                next();
                                state = 79;
                                break;
                            case 115:
                                next();
                                state = 79;
                                break;
                            case 68:
                                next();
                                state = 79;
                                break;
                            case 114:
                                next();
                                state = 79;
                                break;
                            case 67:
                                next();
                                state = 79;
                                break;
                            case 90:
                                next();
                                state = 79;
                                break;
                            case 99:
                                next();
                                state = 79;
                                break;
                            case 52:
                                next();
                                state = 79;
                                break;
                            case 100:
                                next();
                                state = 79;
                                break;
                            case 53:
                                next();
                                state = 79;
                                break;
                            case 101:
                                next();
                                state = 79;
                                break;
                            case 54:
                                next();
                                state = 79;
                                break;
                            case 85:
                                next();
                                state = 79;
                                break;
                            case 108:
                                next();
                                state = 37;
                                break;
                            case 111:
                                next();
                                state = 79;
                                break;
                            case 110:
                                next();
                                state = 79;
                                break;
                            case 86:
                                next();
                                state = 79;
                                break;
                            case 109:
                                next();
                                state = 79;
                                break;
                            case 84:
                                next();
                                state = 79;
                                break;
                            case 107:
                                next();
                                state = 79;
                                break;
                            case 83:
                                next();
                                state = 79;
                                break;
                            case 106:
                                next();
                                state = 79;
                                break;
                            case 82:
                                next();
                                state = 79;
                                break;
                            case 105:
                                next();
                                state = 79;
                                break;
                            case 104:
                                next();
                                state = 79;
                                break;
                            case 57:
                                next();
                                state = 79;
                                break;
                            case 103:
                                next();
                                state = 79;
                                break;
                            case 56:
                                next();
                                state = 79;
                                break;
                            case 102:
                                next();
                                state = 79;
                                break;
                            default:
                                m_semantic.id(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 26:
                        switch (c) {
                            case 81:
                                next();
                                state = 79;
                                break;
                            case 49:
                                next();
                                state = 79;
                                break;
                            case 71:
                                next();
                                state = 79;
                                break;
                            case 118:
                                next();
                                state = 79;
                                break;
                            case 72:
                                next();
                                state = 79;
                                break;
                            case 119:
                                next();
                                state = 79;
                                break;
                            case 74:
                                next();
                                state = 79;
                                break;
                            case 121:
                                next();
                                state = 79;
                                break;
                            case 75:
                                next();
                                state = 79;
                                break;
                            case 122:
                                next();
                                state = 79;
                                break;
                            case 73:
                                next();
                                state = 79;
                                break;
                            case 120:
                                next();
                                state = 79;
                                break;
                            case 95:
                                next();
                                state = 79;
                                break;
                            case 48:
                                next();
                                state = 79;
                                break;
                            case 70:
                                next();
                                state = 79;
                                break;
                            case 117:
                                next();
                                state = 79;
                                break;
                            case 55:
                                next();
                                state = 79;
                                break;
                            case 98:
                                next();
                                state = 79;
                                break;
                            case 51:
                                next();
                                state = 79;
                                break;
                            case 50:
                                next();
                                state = 79;
                                break;
                            case 97:
                                next();
                                state = 79;
                                break;
                            case 80:
                                next();
                                state = 79;
                                break;
                            case 79:
                                next();
                                state = 79;
                                break;
                            case 78:
                                next();
                                state = 79;
                                break;
                            case 77:
                                next();
                                state = 79;
                                break;
                            case 76:
                                next();
                                state = 79;
                                break;
                            case 65:
                                next();
                                state = 79;
                                break;
                            case 112:
                                next();
                                state = 79;
                                break;
                            case 88:
                                next();
                                state = 79;
                                break;
                            case 89:
                                next();
                                state = 79;
                                break;
                            case 66:
                                next();
                                state = 79;
                                break;
                            case 113:
                                next();
                                state = 79;
                                break;
                            case 87:
                                next();
                                state = 79;
                                break;
                            case 116:
                                next();
                                state = 79;
                                break;
                            case 69:
                                next();
                                state = 79;
                                break;
                            case 115:
                                next();
                                state = 79;
                                break;
                            case 68:
                                next();
                                state = 79;
                                break;
                            case 114:
                                next();
                                state = 79;
                                break;
                            case 67:
                                next();
                                state = 79;
                                break;
                            case 90:
                                next();
                                state = 79;
                                break;
                            case 99:
                                next();
                                state = 79;
                                break;
                            case 52:
                                next();
                                state = 79;
                                break;
                            case 100:
                                next();
                                state = 79;
                                break;
                            case 53:
                                next();
                                state = 79;
                                break;
                            case 101:
                                next();
                                state = 79;
                                break;
                            case 54:
                                next();
                                state = 79;
                                break;
                            case 111:
                                next();
                                state = 79;
                                break;
                            case 110:
                                next();
                                state = 79;
                                break;
                            case 86:
                                next();
                                state = 79;
                                break;
                            case 109:
                                next();
                                state = 79;
                                break;
                            case 85:
                                next();
                                state = 79;
                                break;
                            case 108:
                                next();
                                state = 79;
                                break;
                            case 84:
                                next();
                                state = 79;
                                break;
                            case 107:
                                next();
                                state = 79;
                                break;
                            case 83:
                                next();
                                state = 79;
                                break;
                            case 106:
                                next();
                                state = 79;
                                break;
                            case 82:
                                next();
                                state = 79;
                                break;
                            case 105:
                                next();
                                state = 79;
                                break;
                            case 104:
                                next();
                                state = 79;
                                break;
                            case 57:
                                next();
                                state = 79;
                                break;
                            case 103:
                                next();
                                state = 79;
                                break;
                            case 56:
                                next();
                                state = 79;
                                break;
                            case 102:
                                next();
                                state = 79;
                                break;
                            default:
                                m_semantic.array(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 27:
                        switch (c) {
                            case 49:
                                next();
                                state = 79;
                                break;
                            case 71:
                                next();
                                state = 79;
                                break;
                            case 118:
                                next();
                                state = 79;
                                break;
                            case 72:
                                next();
                                state = 79;
                                break;
                            case 119:
                                next();
                                state = 79;
                                break;
                            case 74:
                                next();
                                state = 79;
                                break;
                            case 121:
                                next();
                                state = 79;
                                break;
                            case 75:
                                next();
                                state = 79;
                                break;
                            case 122:
                                next();
                                state = 79;
                                break;
                            case 73:
                                next();
                                state = 79;
                                break;
                            case 120:
                                next();
                                state = 79;
                                break;
                            case 95:
                                next();
                                state = 79;
                                break;
                            case 48:
                                next();
                                state = 79;
                                break;
                            case 70:
                                next();
                                state = 79;
                                break;
                            case 117:
                                next();
                                state = 79;
                                break;
                            case 86:
                                next();
                                state = 79;
                                break;
                            case 56:
                                next();
                                state = 79;
                                break;
                            case 98:
                                next();
                                state = 79;
                                break;
                            case 51:
                                next();
                                state = 79;
                                break;
                            case 50:
                                next();
                                state = 79;
                                break;
                            case 97:
                                next();
                                state = 79;
                                break;
                            case 81:
                                next();
                                state = 79;
                                break;
                            case 80:
                                next();
                                state = 79;
                                break;
                            case 79:
                                next();
                                state = 79;
                                break;
                            case 78:
                                next();
                                state = 79;
                                break;
                            case 77:
                                next();
                                state = 79;
                                break;
                            case 76:
                                next();
                                state = 79;
                                break;
                            case 65:
                                next();
                                state = 79;
                                break;
                            case 112:
                                next();
                                state = 79;
                                break;
                            case 88:
                                next();
                                state = 79;
                                break;
                            case 87:
                                next();
                                state = 79;
                                break;
                            case 116:
                                next();
                                state = 79;
                                break;
                            case 69:
                                next();
                                state = 79;
                                break;
                            case 89:
                                next();
                                state = 79;
                                break;
                            case 66:
                                next();
                                state = 79;
                                break;
                            case 113:
                                next();
                                state = 79;
                                break;
                            case 68:
                                next();
                                state = 79;
                                break;
                            case 115:
                                next();
                                state = 77;
                                break;
                            case 114:
                                next();
                                state = 79;
                                break;
                            case 67:
                                next();
                                state = 79;
                                break;
                            case 90:
                                next();
                                state = 79;
                                break;
                            case 99:
                                next();
                                state = 79;
                                break;
                            case 52:
                                next();
                                state = 79;
                                break;
                            case 100:
                                next();
                                state = 79;
                                break;
                            case 53:
                                next();
                                state = 79;
                                break;
                            case 101:
                                next();
                                state = 79;
                                break;
                            case 54:
                                next();
                                state = 79;
                                break;
                            case 102:
                                next();
                                state = 79;
                                break;
                            case 55:
                                next();
                                state = 79;
                                break;
                            case 104:
                                next();
                                state = 79;
                                break;
                            case 57:
                                next();
                                state = 79;
                                break;
                            case 111:
                                next();
                                state = 79;
                                break;
                            case 110:
                                next();
                                state = 79;
                                break;
                            case 109:
                                next();
                                state = 79;
                                break;
                            case 85:
                                next();
                                state = 79;
                                break;
                            case 108:
                                next();
                                state = 79;
                                break;
                            case 84:
                                next();
                                state = 79;
                                break;
                            case 107:
                                next();
                                state = 79;
                                break;
                            case 83:
                                next();
                                state = 79;
                                break;
                            case 106:
                                next();
                                state = 79;
                                break;
                            case 82:
                                next();
                                state = 79;
                                break;
                            case 105:
                                next();
                                state = 79;
                                break;
                            case 103:
                                next();
                                state = 79;
                                break;
                            default:
                                m_semantic.id(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 28:
                        switch (c) {
                            case 81:
                                next();
                                state = 79;
                                break;
                            case 49:
                                next();
                                state = 79;
                                break;
                            case 71:
                                next();
                                state = 79;
                                break;
                            case 118:
                                next();
                                state = 79;
                                break;
                            case 72:
                                next();
                                state = 79;
                                break;
                            case 119:
                                next();
                                state = 79;
                                break;
                            case 74:
                                next();
                                state = 79;
                                break;
                            case 121:
                                next();
                                state = 79;
                                break;
                            case 75:
                                next();
                                state = 79;
                                break;
                            case 122:
                                next();
                                state = 79;
                                break;
                            case 73:
                                next();
                                state = 79;
                                break;
                            case 120:
                                next();
                                state = 79;
                                break;
                            case 95:
                                next();
                                state = 79;
                                break;
                            case 48:
                                next();
                                state = 79;
                                break;
                            case 70:
                                next();
                                state = 79;
                                break;
                            case 117:
                                next();
                                state = 79;
                                break;
                            case 55:
                                next();
                                state = 79;
                                break;
                            case 98:
                                next();
                                state = 79;
                                break;
                            case 51:
                                next();
                                state = 79;
                                break;
                            case 50:
                                next();
                                state = 79;
                                break;
                            case 97:
                                next();
                                state = 79;
                                break;
                            case 80:
                                next();
                                state = 79;
                                break;
                            case 79:
                                next();
                                state = 79;
                                break;
                            case 78:
                                next();
                                state = 79;
                                break;
                            case 77:
                                next();
                                state = 79;
                                break;
                            case 76:
                                next();
                                state = 79;
                                break;
                            case 65:
                                next();
                                state = 79;
                                break;
                            case 112:
                                next();
                                state = 79;
                                break;
                            case 88:
                                next();
                                state = 79;
                                break;
                            case 89:
                                next();
                                state = 79;
                                break;
                            case 66:
                                next();
                                state = 79;
                                break;
                            case 113:
                                next();
                                state = 79;
                                break;
                            case 87:
                                next();
                                state = 79;
                                break;
                            case 116:
                                next();
                                state = 79;
                                break;
                            case 69:
                                next();
                                state = 79;
                                break;
                            case 115:
                                next();
                                state = 79;
                                break;
                            case 68:
                                next();
                                state = 79;
                                break;
                            case 114:
                                next();
                                state = 79;
                                break;
                            case 67:
                                next();
                                state = 79;
                                break;
                            case 90:
                                next();
                                state = 79;
                                break;
                            case 99:
                                next();
                                state = 79;
                                break;
                            case 52:
                                next();
                                state = 79;
                                break;
                            case 100:
                                next();
                                state = 79;
                                break;
                            case 53:
                                next();
                                state = 79;
                                break;
                            case 101:
                                next();
                                state = 9;
                                break;
                            case 54:
                                next();
                                state = 79;
                                break;
                            case 111:
                                next();
                                state = 79;
                                break;
                            case 110:
                                next();
                                state = 79;
                                break;
                            case 86:
                                next();
                                state = 79;
                                break;
                            case 109:
                                next();
                                state = 79;
                                break;
                            case 85:
                                next();
                                state = 79;
                                break;
                            case 108:
                                next();
                                state = 79;
                                break;
                            case 84:
                                next();
                                state = 79;
                                break;
                            case 107:
                                next();
                                state = 79;
                                break;
                            case 83:
                                next();
                                state = 79;
                                break;
                            case 106:
                                next();
                                state = 79;
                                break;
                            case 82:
                                next();
                                state = 79;
                                break;
                            case 105:
                                next();
                                state = 79;
                                break;
                            case 104:
                                next();
                                state = 79;
                                break;
                            case 57:
                                next();
                                state = 79;
                                break;
                            case 103:
                                next();
                                state = 79;
                                break;
                            case 56:
                                next();
                                state = 79;
                                break;
                            case 102:
                                next();
                                state = 79;
                                break;
                            default:
                                m_semantic.id(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 29:
                        switch (c) {
                            case 81:
                                next();
                                state = 79;
                                break;
                            case 49:
                                next();
                                state = 79;
                                break;
                            case 71:
                                next();
                                state = 79;
                                break;
                            case 118:
                                next();
                                state = 79;
                                break;
                            case 72:
                                next();
                                state = 79;
                                break;
                            case 119:
                                next();
                                state = 79;
                                break;
                            case 74:
                                next();
                                state = 79;
                                break;
                            case 121:
                                next();
                                state = 79;
                                break;
                            case 75:
                                next();
                                state = 79;
                                break;
                            case 122:
                                next();
                                state = 79;
                                break;
                            case 73:
                                next();
                                state = 79;
                                break;
                            case 120:
                                next();
                                state = 79;
                                break;
                            case 95:
                                next();
                                state = 79;
                                break;
                            case 48:
                                next();
                                state = 79;
                                break;
                            case 70:
                                next();
                                state = 79;
                                break;
                            case 117:
                                next();
                                state = 79;
                                break;
                            case 56:
                                next();
                                state = 79;
                                break;
                            case 98:
                                next();
                                state = 79;
                                break;
                            case 51:
                                next();
                                state = 79;
                                break;
                            case 50:
                                next();
                                state = 79;
                                break;
                            case 97:
                                next();
                                state = 79;
                                break;
                            case 80:
                                next();
                                state = 79;
                                break;
                            case 79:
                                next();
                                state = 79;
                                break;
                            case 78:
                                next();
                                state = 79;
                                break;
                            case 77:
                                next();
                                state = 79;
                                break;
                            case 76:
                                next();
                                state = 79;
                                break;
                            case 65:
                                next();
                                state = 79;
                                break;
                            case 112:
                                next();
                                state = 79;
                                break;
                            case 88:
                                next();
                                state = 79;
                                break;
                            case 89:
                                next();
                                state = 79;
                                break;
                            case 66:
                                next();
                                state = 79;
                                break;
                            case 113:
                                next();
                                state = 79;
                                break;
                            case 87:
                                next();
                                state = 79;
                                break;
                            case 116:
                                next();
                                state = 79;
                                break;
                            case 69:
                                next();
                                state = 79;
                                break;
                            case 115:
                                next();
                                state = 79;
                                break;
                            case 68:
                                next();
                                state = 79;
                                break;
                            case 114:
                                next();
                                state = 79;
                                break;
                            case 67:
                                next();
                                state = 79;
                                break;
                            case 90:
                                next();
                                state = 79;
                                break;
                            case 99:
                                next();
                                state = 79;
                                break;
                            case 52:
                                next();
                                state = 79;
                                break;
                            case 101:
                                next();
                                state = 79;
                                break;
                            case 54:
                                next();
                                state = 79;
                                break;
                            case 102:
                                next();
                                state = 79;
                                break;
                            case 55:
                                next();
                                state = 79;
                                break;
                            case 100:
                                next();
                                state = 35;
                                break;
                            case 53:
                                next();
                                state = 79;
                                break;
                            case 111:
                                next();
                                state = 79;
                                break;
                            case 110:
                                next();
                                state = 79;
                                break;
                            case 86:
                                next();
                                state = 79;
                                break;
                            case 109:
                                next();
                                state = 79;
                                break;
                            case 85:
                                next();
                                state = 79;
                                break;
                            case 108:
                                next();
                                state = 79;
                                break;
                            case 84:
                                next();
                                state = 79;
                                break;
                            case 107:
                                next();
                                state = 79;
                                break;
                            case 83:
                                next();
                                state = 79;
                                break;
                            case 106:
                                next();
                                state = 79;
                                break;
                            case 82:
                                next();
                                state = 79;
                                break;
                            case 105:
                                next();
                                state = 79;
                                break;
                            case 104:
                                next();
                                state = 79;
                                break;
                            case 57:
                                next();
                                state = 79;
                                break;
                            case 103:
                                next();
                                state = 79;
                                break;
                            default:
                                m_semantic.id(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 30:
                        switch (c) {
                            case 86:
                                next();
                                state = 105;
                                break;
                            case 117:
                                next();
                                state = 105;
                                break;
                            case 120:
                                next();
                                state = 105;
                                break;
                            case 121:
                                next();
                                state = 105;
                                break;
                            case 122:
                                next();
                                state = 105;
                                break;
                            case 95:
                                next();
                                state = 105;
                                break;
                            case 49:
                                next();
                                state = 95;
                                break;
                            case 56:
                                next();
                                state = 95;
                                break;
                            case 57:
                                next();
                                state = 95;
                                break;
                            case 52:
                                next();
                                state = 95;
                                break;
                            case 99:
                                next();
                                state = 69;
                                break;
                            case 110:
                                next();
                                state = 58;
                                break;
                            case 50:
                                next();
                                state = 95;
                                break;
                            case 97:
                                next();
                                state = 23;
                                break;
                            case 111:
                                next();
                                state = 42;
                                break;
                            case 53:
                                next();
                                state = 95;
                                break;
                            case 100:
                                next();
                                state = 60;
                                break;
                            case 119:
                                next();
                                state = 48;
                                break;
                            case 114:
                                next();
                                state = 66;
                                break;
                            case 118:
                                next();
                                state = 14;
                                break;
                            case 40:
                                next();
                                state = 67;
                                break;
                            case 42:
                                next();
                                state = 22;
                                break;
                            case 45:
                                next();
                                state = 15;
                                break;
                            case 43:
                                next();
                                state = 47;
                                break;
                            case 112:
                                next();
                                state = 8;
                                break;
                            case 91:
                                next();
                                state = 11;
                                break;
                            case 44:
                                next();
                                state = 0;
                                break;
                            case 116:
                                next();
                                state = 110;
                                break;
                            case 105:
                                next();
                                state = 24;
                                break;
                            case 58:
                                next();
                                state = 71;
                                break;
                            case 59:
                                next();
                                state = 73;
                                break;
                            case 61:
                                next();
                                state = 109;
                                break;
                            case 93:
                                next();
                                state = 51;
                                break;
                            case 46:
                                next();
                                state = 81;
                                break;
                            case 41:
                                next();
                                state = 13;
                                break;
                            case 68:
                                next();
                                state = 105;
                                break;
                            case 115:
                                next();
                                state = 105;
                                break;
                            case 69:
                                next();
                                state = 105;
                                break;
                            case 70:
                                next();
                                state = 105;
                                break;
                            case 71:
                                next();
                                state = 105;
                                break;
                            case 72:
                                next();
                                state = 105;
                                break;
                            case 73:
                                next();
                                state = 105;
                                break;
                            case 74:
                                next();
                                state = 105;
                                break;
                            case 87:
                                next();
                                state = 105;
                                break;
                            case 88:
                                next();
                                state = 105;
                                break;
                            case 104:
                                next();
                                state = 105;
                                break;
                            case 108:
                                next();
                                state = 105;
                                break;
                            case 32:
                                next();
                                state = 93;
                                break;
                            case 79:
                                next();
                                state = 105;
                                break;
                            case 103:
                                next();
                                state = 105;
                                break;
                            case 10:
                                next();
                                state = 93;
                                break;
                            case 107:
                                next();
                                state = 105;
                                break;
                            case 60:
                                next();
                                state = 90;
                                break;
                            case 9:
                                next();
                                state = 93;
                                break;
                            case 106:
                                next();
                                state = 105;
                                break;
                            case 113:
                                next();
                                state = 105;
                                break;
                            case 66:
                                next();
                                state = 105;
                                break;
                            case 67:
                                next();
                                state = 105;
                                break;
                            case 90:
                                next();
                                state = 105;
                                break;
                            case 89:
                                next();
                                state = 105;
                                break;
                            case 65:
                                next();
                                state = 105;
                                break;
                            case 75:
                                next();
                                state = 105;
                                break;
                            case 76:
                                next();
                                state = 105;
                                break;
                            case 77:
                                next();
                                state = 105;
                                break;
                            case 78:
                                next();
                                state = 105;
                                break;
                            case 80:
                                next();
                                state = 105;
                                break;
                            case 81:
                                next();
                                state = 105;
                                break;
                            case 82:
                                next();
                                state = 105;
                                break;
                            case 83:
                                next();
                                state = 105;
                                break;
                            case 84:
                                next();
                                state = 105;
                                break;
                            case 85:
                                next();
                                state = 105;
                                break;
                            case 101:
                                next();
                                state = 76;
                                break;
                            case 54:
                                next();
                                state = 95;
                                break;
                            case 98:
                                next();
                                state = 101;
                                break;
                            case 51:
                                next();
                                state = 95;
                                break;
                            case 102:
                                next();
                                state = 19;
                                break;
                            case 55:
                                next();
                                state = 95;
                                break;
                            case 62:
                                next();
                                state = 33;
                                break;
                            case 109:
                                next();
                                state = 39;
                                break;
                            case 94:
                                next();
                                state = 87;
                                break;
                            case 47:
                                next();
                                state = 108;
                                break;
                            default:
                                throw LexError();
                        }
                        break;
                    case 31:
                        switch (c) {
                            case 49:
                                next();
                                state = 79;
                                break;
                            case 71:
                                next();
                                state = 79;
                                break;
                            case 118:
                                next();
                                state = 79;
                                break;
                            case 72:
                                next();
                                state = 79;
                                break;
                            case 119:
                                next();
                                state = 79;
                                break;
                            case 74:
                                next();
                                state = 79;
                                break;
                            case 121:
                                next();
                                state = 79;
                                break;
                            case 75:
                                next();
                                state = 79;
                                break;
                            case 122:
                                next();
                                state = 79;
                                break;
                            case 73:
                                next();
                                state = 79;
                                break;
                            case 120:
                                next();
                                state = 79;
                                break;
                            case 95:
                                next();
                                state = 79;
                                break;
                            case 48:
                                next();
                                state = 79;
                                break;
                            case 70:
                                next();
                                state = 79;
                                break;
                            case 117:
                                next();
                                state = 79;
                                break;
                            case 86:
                                next();
                                state = 79;
                                break;
                            case 56:
                                next();
                                state = 79;
                                break;
                            case 98:
                                next();
                                state = 79;
                                break;
                            case 51:
                                next();
                                state = 79;
                                break;
                            case 50:
                                next();
                                state = 79;
                                break;
                            case 97:
                                next();
                                state = 79;
                                break;
                            case 81:
                                next();
                                state = 79;
                                break;
                            case 80:
                                next();
                                state = 79;
                                break;
                            case 79:
                                next();
                                state = 79;
                                break;
                            case 78:
                                next();
                                state = 79;
                                break;
                            case 77:
                                next();
                                state = 79;
                                break;
                            case 76:
                                next();
                                state = 79;
                                break;
                            case 65:
                                next();
                                state = 79;
                                break;
                            case 112:
                                next();
                                state = 79;
                                break;
                            case 88:
                                next();
                                state = 79;
                                break;
                            case 87:
                                next();
                                state = 79;
                                break;
                            case 69:
                                next();
                                state = 79;
                                break;
                            case 116:
                                next();
                                state = 72;
                                break;
                            case 115:
                                next();
                                state = 79;
                                break;
                            case 68:
                                next();
                                state = 79;
                                break;
                            case 89:
                                next();
                                state = 79;
                                break;
                            case 66:
                                next();
                                state = 79;
                                break;
                            case 113:
                                next();
                                state = 79;
                                break;
                            case 114:
                                next();
                                state = 79;
                                break;
                            case 67:
                                next();
                                state = 79;
                                break;
                            case 90:
                                next();
                                state = 79;
                                break;
                            case 99:
                                next();
                                state = 79;
                                break;
                            case 52:
                                next();
                                state = 79;
                                break;
                            case 100:
                                next();
                                state = 79;
                                break;
                            case 53:
                                next();
                                state = 79;
                                break;
                            case 101:
                                next();
                                state = 79;
                                break;
                            case 54:
                                next();
                                state = 79;
                                break;
                            case 102:
                                next();
                                state = 79;
                                break;
                            case 55:
                                next();
                                state = 79;
                                break;
                            case 82:
                                next();
                                state = 79;
                                break;
                            case 105:
                                next();
                                state = 79;
                                break;
                            case 111:
                                next();
                                state = 79;
                                break;
                            case 110:
                                next();
                                state = 79;
                                break;
                            case 109:
                                next();
                                state = 79;
                                break;
                            case 85:
                                next();
                                state = 79;
                                break;
                            case 108:
                                next();
                                state = 79;
                                break;
                            case 84:
                                next();
                                state = 79;
                                break;
                            case 107:
                                next();
                                state = 79;
                                break;
                            case 83:
                                next();
                                state = 79;
                                break;
                            case 106:
                                next();
                                state = 79;
                                break;
                            case 104:
                                next();
                                state = 79;
                                break;
                            case 57:
                                next();
                                state = 79;
                                break;
                            case 103:
                                next();
                                state = 79;
                                break;
                            default:
                                m_semantic.id(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 32:
                        switch (c) {
                            case 49:
                                next();
                                state = 79;
                                break;
                            case 71:
                                next();
                                state = 79;
                                break;
                            case 118:
                                next();
                                state = 79;
                                break;
                            case 72:
                                next();
                                state = 79;
                                break;
                            case 119:
                                next();
                                state = 79;
                                break;
                            case 74:
                                next();
                                state = 79;
                                break;
                            case 121:
                                next();
                                state = 79;
                                break;
                            case 75:
                                next();
                                state = 79;
                                break;
                            case 122:
                                next();
                                state = 79;
                                break;
                            case 73:
                                next();
                                state = 79;
                                break;
                            case 120:
                                next();
                                state = 79;
                                break;
                            case 95:
                                next();
                                state = 79;
                                break;
                            case 48:
                                next();
                                state = 79;
                                break;
                            case 70:
                                next();
                                state = 79;
                                break;
                            case 117:
                                next();
                                state = 79;
                                break;
                            case 86:
                                next();
                                state = 79;
                                break;
                            case 57:
                                next();
                                state = 79;
                                break;
                            case 98:
                                next();
                                state = 79;
                                break;
                            case 51:
                                next();
                                state = 79;
                                break;
                            case 50:
                                next();
                                state = 79;
                                break;
                            case 97:
                                next();
                                state = 79;
                                break;
                            case 81:
                                next();
                                state = 79;
                                break;
                            case 80:
                                next();
                                state = 79;
                                break;
                            case 79:
                                next();
                                state = 79;
                                break;
                            case 78:
                                next();
                                state = 79;
                                break;
                            case 77:
                                next();
                                state = 79;
                                break;
                            case 76:
                                next();
                                state = 79;
                                break;
                            case 65:
                                next();
                                state = 79;
                                break;
                            case 112:
                                next();
                                state = 79;
                                break;
                            case 88:
                                next();
                                state = 79;
                                break;
                            case 87:
                                next();
                                state = 79;
                                break;
                            case 116:
                                next();
                                state = 79;
                                break;
                            case 69:
                                next();
                                state = 79;
                                break;
                            case 115:
                                next();
                                state = 79;
                                break;
                            case 68:
                                next();
                                state = 79;
                                break;
                            case 89:
                                next();
                                state = 79;
                                break;
                            case 66:
                                next();
                                state = 79;
                                break;
                            case 113:
                                next();
                                state = 79;
                                break;
                            case 90:
                                next();
                                state = 79;
                                break;
                            case 67:
                                next();
                                state = 79;
                                break;
                            case 114:
                                next();
                                state = 99;
                                break;
                            case 99:
                                next();
                                state = 79;
                                break;
                            case 52:
                                next();
                                state = 79;
                                break;
                            case 100:
                                next();
                                state = 79;
                                break;
                            case 53:
                                next();
                                state = 79;
                                break;
                            case 101:
                                next();
                                state = 79;
                                break;
                            case 54:
                                next();
                                state = 79;
                                break;
                            case 102:
                                next();
                                state = 79;
                                break;
                            case 55:
                                next();
                                state = 79;
                                break;
                            case 103:
                                next();
                                state = 79;
                                break;
                            case 56:
                                next();
                                state = 79;
                                break;
                            case 111:
                                next();
                                state = 79;
                                break;
                            case 110:
                                next();
                                state = 79;
                                break;
                            case 109:
                                next();
                                state = 79;
                                break;
                            case 85:
                                next();
                                state = 79;
                                break;
                            case 108:
                                next();
                                state = 79;
                                break;
                            case 84:
                                next();
                                state = 79;
                                break;
                            case 107:
                                next();
                                state = 79;
                                break;
                            case 83:
                                next();
                                state = 79;
                                break;
                            case 106:
                                next();
                                state = 79;
                                break;
                            case 82:
                                next();
                                state = 79;
                                break;
                            case 105:
                                next();
                                state = 79;
                                break;
                            case 104:
                                next();
                                state = 79;
                                break;
                            default:
                                m_semantic.id(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 33:
                        switch (c) {
                            case 61:
                                next();
                                state = 34;
                                break;
                            default:
                                m_semantic.gt(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 34:
                        m_semantic.ge(m_lexeme.str());
                        return true;
                    case 35:
                        switch (c) {
                            case 81:
                                next();
                                state = 79;
                                break;
                            case 49:
                                next();
                                state = 79;
                                break;
                            case 71:
                                next();
                                state = 79;
                                break;
                            case 118:
                                next();
                                state = 79;
                                break;
                            case 72:
                                next();
                                state = 79;
                                break;
                            case 119:
                                next();
                                state = 79;
                                break;
                            case 74:
                                next();
                                state = 79;
                                break;
                            case 121:
                                next();
                                state = 79;
                                break;
                            case 75:
                                next();
                                state = 79;
                                break;
                            case 122:
                                next();
                                state = 79;
                                break;
                            case 73:
                                next();
                                state = 79;
                                break;
                            case 120:
                                next();
                                state = 79;
                                break;
                            case 95:
                                next();
                                state = 79;
                                break;
                            case 48:
                                next();
                                state = 79;
                                break;
                            case 70:
                                next();
                                state = 79;
                                break;
                            case 117:
                                next();
                                state = 25;
                                break;
                            case 55:
                                next();
                                state = 79;
                                break;
                            case 98:
                                next();
                                state = 79;
                                break;
                            case 51:
                                next();
                                state = 79;
                                break;
                            case 50:
                                next();
                                state = 79;
                                break;
                            case 97:
                                next();
                                state = 79;
                                break;
                            case 80:
                                next();
                                state = 79;
                                break;
                            case 79:
                                next();
                                state = 79;
                                break;
                            case 78:
                                next();
                                state = 79;
                                break;
                            case 77:
                                next();
                                state = 79;
                                break;
                            case 76:
                                next();
                                state = 79;
                                break;
                            case 65:
                                next();
                                state = 79;
                                break;
                            case 112:
                                next();
                                state = 79;
                                break;
                            case 88:
                                next();
                                state = 79;
                                break;
                            case 89:
                                next();
                                state = 79;
                                break;
                            case 66:
                                next();
                                state = 79;
                                break;
                            case 113:
                                next();
                                state = 79;
                                break;
                            case 87:
                                next();
                                state = 79;
                                break;
                            case 116:
                                next();
                                state = 79;
                                break;
                            case 69:
                                next();
                                state = 79;
                                break;
                            case 115:
                                next();
                                state = 79;
                                break;
                            case 68:
                                next();
                                state = 79;
                                break;
                            case 114:
                                next();
                                state = 79;
                                break;
                            case 67:
                                next();
                                state = 79;
                                break;
                            case 90:
                                next();
                                state = 79;
                                break;
                            case 99:
                                next();
                                state = 79;
                                break;
                            case 52:
                                next();
                                state = 79;
                                break;
                            case 100:
                                next();
                                state = 79;
                                break;
                            case 53:
                                next();
                                state = 79;
                                break;
                            case 101:
                                next();
                                state = 79;
                                break;
                            case 54:
                                next();
                                state = 79;
                                break;
                            case 111:
                                next();
                                state = 79;
                                break;
                            case 110:
                                next();
                                state = 79;
                                break;
                            case 86:
                                next();
                                state = 79;
                                break;
                            case 109:
                                next();
                                state = 79;
                                break;
                            case 85:
                                next();
                                state = 79;
                                break;
                            case 108:
                                next();
                                state = 79;
                                break;
                            case 84:
                                next();
                                state = 79;
                                break;
                            case 107:
                                next();
                                state = 79;
                                break;
                            case 83:
                                next();
                                state = 79;
                                break;
                            case 106:
                                next();
                                state = 79;
                                break;
                            case 82:
                                next();
                                state = 79;
                                break;
                            case 105:
                                next();
                                state = 79;
                                break;
                            case 104:
                                next();
                                state = 79;
                                break;
                            case 57:
                                next();
                                state = 79;
                                break;
                            case 103:
                                next();
                                state = 79;
                                break;
                            case 56:
                                next();
                                state = 79;
                                break;
                            case 102:
                                next();
                                state = 79;
                                break;
                            default:
                                m_semantic.mod(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 36:
                        switch (c) {
                            case 81:
                                next();
                                state = 79;
                                break;
                            case 49:
                                next();
                                state = 79;
                                break;
                            case 71:
                                next();
                                state = 79;
                                break;
                            case 118:
                                next();
                                state = 79;
                                break;
                            case 72:
                                next();
                                state = 79;
                                break;
                            case 119:
                                next();
                                state = 79;
                                break;
                            case 74:
                                next();
                                state = 79;
                                break;
                            case 121:
                                next();
                                state = 79;
                                break;
                            case 75:
                                next();
                                state = 79;
                                break;
                            case 122:
                                next();
                                state = 79;
                                break;
                            case 73:
                                next();
                                state = 79;
                                break;
                            case 120:
                                next();
                                state = 79;
                                break;
                            case 95:
                                next();
                                state = 79;
                                break;
                            case 48:
                                next();
                                state = 79;
                                break;
                            case 70:
                                next();
                                state = 79;
                                break;
                            case 117:
                                next();
                                state = 79;
                                break;
                            case 55:
                                next();
                                state = 79;
                                break;
                            case 98:
                                next();
                                state = 79;
                                break;
                            case 51:
                                next();
                                state = 79;
                                break;
                            case 50:
                                next();
                                state = 79;
                                break;
                            case 97:
                                next();
                                state = 79;
                                break;
                            case 80:
                                next();
                                state = 79;
                                break;
                            case 79:
                                next();
                                state = 79;
                                break;
                            case 78:
                                next();
                                state = 79;
                                break;
                            case 77:
                                next();
                                state = 79;
                                break;
                            case 76:
                                next();
                                state = 79;
                                break;
                            case 65:
                                next();
                                state = 79;
                                break;
                            case 112:
                                next();
                                state = 79;
                                break;
                            case 88:
                                next();
                                state = 79;
                                break;
                            case 89:
                                next();
                                state = 79;
                                break;
                            case 66:
                                next();
                                state = 79;
                                break;
                            case 113:
                                next();
                                state = 79;
                                break;
                            case 87:
                                next();
                                state = 79;
                                break;
                            case 116:
                                next();
                                state = 79;
                                break;
                            case 69:
                                next();
                                state = 79;
                                break;
                            case 115:
                                next();
                                state = 79;
                                break;
                            case 68:
                                next();
                                state = 79;
                                break;
                            case 114:
                                next();
                                state = 79;
                                break;
                            case 67:
                                next();
                                state = 79;
                                break;
                            case 90:
                                next();
                                state = 79;
                                break;
                            case 99:
                                next();
                                state = 79;
                                break;
                            case 52:
                                next();
                                state = 79;
                                break;
                            case 100:
                                next();
                                state = 79;
                                break;
                            case 53:
                                next();
                                state = 79;
                                break;
                            case 101:
                                next();
                                state = 79;
                                break;
                            case 54:
                                next();
                                state = 79;
                                break;
                            case 111:
                                next();
                                state = 79;
                                break;
                            case 110:
                                next();
                                state = 79;
                                break;
                            case 86:
                                next();
                                state = 79;
                                break;
                            case 109:
                                next();
                                state = 79;
                                break;
                            case 85:
                                next();
                                state = 79;
                                break;
                            case 108:
                                next();
                                state = 79;
                                break;
                            case 84:
                                next();
                                state = 79;
                                break;
                            case 107:
                                next();
                                state = 79;
                                break;
                            case 83:
                                next();
                                state = 79;
                                break;
                            case 106:
                                next();
                                state = 79;
                                break;
                            case 82:
                                next();
                                state = 79;
                                break;
                            case 105:
                                next();
                                state = 79;
                                break;
                            case 104:
                                next();
                                state = 79;
                                break;
                            case 57:
                                next();
                                state = 79;
                                break;
                            case 103:
                                next();
                                state = 79;
                                break;
                            case 56:
                                next();
                                state = 79;
                                break;
                            case 102:
                                next();
                                state = 79;
                                break;
                            default:
                                m_semantic.function(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 37:
                        switch (c) {
                            case 81:
                                next();
                                state = 79;
                                break;
                            case 49:
                                next();
                                state = 79;
                                break;
                            case 71:
                                next();
                                state = 79;
                                break;
                            case 118:
                                next();
                                state = 79;
                                break;
                            case 72:
                                next();
                                state = 79;
                                break;
                            case 119:
                                next();
                                state = 79;
                                break;
                            case 74:
                                next();
                                state = 79;
                                break;
                            case 121:
                                next();
                                state = 79;
                                break;
                            case 75:
                                next();
                                state = 79;
                                break;
                            case 122:
                                next();
                                state = 79;
                                break;
                            case 73:
                                next();
                                state = 79;
                                break;
                            case 120:
                                next();
                                state = 79;
                                break;
                            case 95:
                                next();
                                state = 79;
                                break;
                            case 48:
                                next();
                                state = 79;
                                break;
                            case 70:
                                next();
                                state = 79;
                                break;
                            case 117:
                                next();
                                state = 79;
                                break;
                            case 55:
                                next();
                                state = 79;
                                break;
                            case 98:
                                next();
                                state = 79;
                                break;
                            case 51:
                                next();
                                state = 79;
                                break;
                            case 50:
                                next();
                                state = 79;
                                break;
                            case 97:
                                next();
                                state = 79;
                                break;
                            case 80:
                                next();
                                state = 79;
                                break;
                            case 79:
                                next();
                                state = 79;
                                break;
                            case 78:
                                next();
                                state = 79;
                                break;
                            case 77:
                                next();
                                state = 79;
                                break;
                            case 76:
                                next();
                                state = 79;
                                break;
                            case 65:
                                next();
                                state = 79;
                                break;
                            case 112:
                                next();
                                state = 79;
                                break;
                            case 88:
                                next();
                                state = 79;
                                break;
                            case 89:
                                next();
                                state = 79;
                                break;
                            case 66:
                                next();
                                state = 79;
                                break;
                            case 113:
                                next();
                                state = 79;
                                break;
                            case 87:
                                next();
                                state = 79;
                                break;
                            case 116:
                                next();
                                state = 79;
                                break;
                            case 69:
                                next();
                                state = 79;
                                break;
                            case 115:
                                next();
                                state = 79;
                                break;
                            case 68:
                                next();
                                state = 79;
                                break;
                            case 114:
                                next();
                                state = 79;
                                break;
                            case 67:
                                next();
                                state = 79;
                                break;
                            case 90:
                                next();
                                state = 79;
                                break;
                            case 99:
                                next();
                                state = 79;
                                break;
                            case 52:
                                next();
                                state = 79;
                                break;
                            case 100:
                                next();
                                state = 79;
                                break;
                            case 53:
                                next();
                                state = 79;
                                break;
                            case 101:
                                next();
                                state = 98;
                                break;
                            case 54:
                                next();
                                state = 79;
                                break;
                            case 111:
                                next();
                                state = 79;
                                break;
                            case 110:
                                next();
                                state = 79;
                                break;
                            case 86:
                                next();
                                state = 79;
                                break;
                            case 109:
                                next();
                                state = 79;
                                break;
                            case 85:
                                next();
                                state = 79;
                                break;
                            case 108:
                                next();
                                state = 79;
                                break;
                            case 84:
                                next();
                                state = 79;
                                break;
                            case 107:
                                next();
                                state = 79;
                                break;
                            case 83:
                                next();
                                state = 79;
                                break;
                            case 106:
                                next();
                                state = 79;
                                break;
                            case 82:
                                next();
                                state = 79;
                                break;
                            case 105:
                                next();
                                state = 79;
                                break;
                            case 104:
                                next();
                                state = 79;
                                break;
                            case 57:
                                next();
                                state = 79;
                                break;
                            case 103:
                                next();
                                state = 79;
                                break;
                            case 56:
                                next();
                                state = 79;
                                break;
                            case 102:
                                next();
                                state = 79;
                                break;
                            default:
                                m_semantic.id(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 38:
                        switch (c) {
                            case 81:
                                next();
                                state = 79;
                                break;
                            case 49:
                                next();
                                state = 79;
                                break;
                            case 71:
                                next();
                                state = 79;
                                break;
                            case 118:
                                next();
                                state = 79;
                                break;
                            case 72:
                                next();
                                state = 79;
                                break;
                            case 119:
                                next();
                                state = 79;
                                break;
                            case 74:
                                next();
                                state = 79;
                                break;
                            case 121:
                                next();
                                state = 79;
                                break;
                            case 75:
                                next();
                                state = 79;
                                break;
                            case 122:
                                next();
                                state = 79;
                                break;
                            case 73:
                                next();
                                state = 79;
                                break;
                            case 120:
                                next();
                                state = 79;
                                break;
                            case 95:
                                next();
                                state = 79;
                                break;
                            case 48:
                                next();
                                state = 79;
                                break;
                            case 70:
                                next();
                                state = 79;
                                break;
                            case 117:
                                next();
                                state = 79;
                                break;
                            case 55:
                                next();
                                state = 79;
                                break;
                            case 98:
                                next();
                                state = 79;
                                break;
                            case 51:
                                next();
                                state = 79;
                                break;
                            case 50:
                                next();
                                state = 79;
                                break;
                            case 97:
                                next();
                                state = 79;
                                break;
                            case 80:
                                next();
                                state = 79;
                                break;
                            case 79:
                                next();
                                state = 79;
                                break;
                            case 78:
                                next();
                                state = 79;
                                break;
                            case 77:
                                next();
                                state = 79;
                                break;
                            case 76:
                                next();
                                state = 79;
                                break;
                            case 65:
                                next();
                                state = 79;
                                break;
                            case 112:
                                next();
                                state = 79;
                                break;
                            case 88:
                                next();
                                state = 79;
                                break;
                            case 89:
                                next();
                                state = 79;
                                break;
                            case 66:
                                next();
                                state = 79;
                                break;
                            case 113:
                                next();
                                state = 79;
                                break;
                            case 87:
                                next();
                                state = 79;
                                break;
                            case 116:
                                next();
                                state = 79;
                                break;
                            case 69:
                                next();
                                state = 79;
                                break;
                            case 115:
                                next();
                                state = 79;
                                break;
                            case 68:
                                next();
                                state = 79;
                                break;
                            case 114:
                                next();
                                state = 79;
                                break;
                            case 67:
                                next();
                                state = 79;
                                break;
                            case 90:
                                next();
                                state = 79;
                                break;
                            case 99:
                                next();
                                state = 79;
                                break;
                            case 52:
                                next();
                                state = 79;
                                break;
                            case 100:
                                next();
                                state = 79;
                                break;
                            case 53:
                                next();
                                state = 79;
                                break;
                            case 101:
                                next();
                                state = 79;
                                break;
                            case 54:
                                next();
                                state = 79;
                                break;
                            case 111:
                                next();
                                state = 79;
                                break;
                            case 110:
                                next();
                                state = 79;
                                break;
                            case 86:
                                next();
                                state = 79;
                                break;
                            case 109:
                                next();
                                state = 79;
                                break;
                            case 85:
                                next();
                                state = 79;
                                break;
                            case 108:
                                next();
                                state = 79;
                                break;
                            case 84:
                                next();
                                state = 79;
                                break;
                            case 107:
                                next();
                                state = 79;
                                break;
                            case 83:
                                next();
                                state = 79;
                                break;
                            case 106:
                                next();
                                state = 79;
                                break;
                            case 82:
                                next();
                                state = 79;
                                break;
                            case 105:
                                next();
                                state = 79;
                                break;
                            case 104:
                                next();
                                state = 79;
                                break;
                            case 57:
                                next();
                                state = 79;
                                break;
                            case 103:
                                next();
                                state = 79;
                                break;
                            case 56:
                                next();
                                state = 79;
                                break;
                            case 102:
                                next();
                                state = 79;
                                break;
                            default:
                                m_semantic.var(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 39:
                        switch (c) {
                            case 103:
                                next();
                                state = 79;
                                break;
                            case 57:
                                next();
                                state = 79;
                                break;
                            case 104:
                                next();
                                state = 79;
                                break;
                            case 105:
                                next();
                                state = 79;
                                break;
                            case 82:
                                next();
                                state = 79;
                                break;
                            case 106:
                                next();
                                state = 79;
                                break;
                            case 83:
                                next();
                                state = 79;
                                break;
                            case 107:
                                next();
                                state = 79;
                                break;
                            case 84:
                                next();
                                state = 79;
                                break;
                            case 108:
                                next();
                                state = 79;
                                break;
                            case 85:
                                next();
                                state = 79;
                                break;
                            case 109:
                                next();
                                state = 79;
                                break;
                            case 111:
                                next();
                                state = 29;
                                break;
                            case 110:
                                next();
                                state = 79;
                                break;
                            case 55:
                                next();
                                state = 79;
                                break;
                            case 102:
                                next();
                                state = 79;
                                break;
                            case 54:
                                next();
                                state = 79;
                                break;
                            case 81:
                                next();
                                state = 79;
                                break;
                            case 56:
                                next();
                                state = 79;
                                break;
                            case 86:
                                next();
                                state = 79;
                                break;
                            case 70:
                                next();
                                state = 79;
                                break;
                            case 117:
                                next();
                                state = 79;
                                break;
                            case 48:
                                next();
                                state = 79;
                                break;
                            case 95:
                                next();
                                state = 79;
                                break;
                            case 71:
                                next();
                                state = 79;
                                break;
                            case 118:
                                next();
                                state = 79;
                                break;
                            case 97:
                                next();
                                state = 79;
                                break;
                            case 50:
                                next();
                                state = 79;
                                break;
                            case 51:
                                next();
                                state = 79;
                                break;
                            case 98:
                                next();
                                state = 79;
                                break;
                            case 120:
                                next();
                                state = 79;
                                break;
                            case 73:
                                next();
                                state = 79;
                                break;
                            case 74:
                                next();
                                state = 79;
                                break;
                            case 121:
                                next();
                                state = 79;
                                break;
                            case 49:
                                next();
                                state = 79;
                                break;
                            case 72:
                                next();
                                state = 79;
                                break;
                            case 119:
                                next();
                                state = 79;
                                break;
                            case 75:
                                next();
                                state = 79;
                                break;
                            case 122:
                                next();
                                state = 79;
                                break;
                            case 80:
                                next();
                                state = 79;
                                break;
                            case 79:
                                next();
                                state = 79;
                                break;
                            case 78:
                                next();
                                state = 79;
                                break;
                            case 77:
                                next();
                                state = 79;
                                break;
                            case 76:
                                next();
                                state = 79;
                                break;
                            case 65:
                                next();
                                state = 79;
                                break;
                            case 112:
                                next();
                                state = 79;
                                break;
                            case 88:
                                next();
                                state = 79;
                                break;
                            case 89:
                                next();
                                state = 79;
                                break;
                            case 66:
                                next();
                                state = 79;
                                break;
                            case 113:
                                next();
                                state = 79;
                                break;
                            case 87:
                                next();
                                state = 79;
                                break;
                            case 116:
                                next();
                                state = 79;
                                break;
                            case 69:
                                next();
                                state = 79;
                                break;
                            case 115:
                                next();
                                state = 79;
                                break;
                            case 68:
                                next();
                                state = 79;
                                break;
                            case 114:
                                next();
                                state = 79;
                                break;
                            case 67:
                                next();
                                state = 79;
                                break;
                            case 90:
                                next();
                                state = 79;
                                break;
                            case 99:
                                next();
                                state = 79;
                                break;
                            case 52:
                                next();
                                state = 79;
                                break;
                            case 100:
                                next();
                                state = 79;
                                break;
                            case 53:
                                next();
                                state = 79;
                                break;
                            case 101:
                                next();
                                state = 79;
                                break;
                            default:
                                m_semantic.id(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 40:
                        switch (c) {
                            case 81:
                                next();
                                state = 79;
                                break;
                            case 49:
                                next();
                                state = 79;
                                break;
                            case 71:
                                next();
                                state = 79;
                                break;
                            case 118:
                                next();
                                state = 79;
                                break;
                            case 72:
                                next();
                                state = 79;
                                break;
                            case 119:
                                next();
                                state = 79;
                                break;
                            case 74:
                                next();
                                state = 79;
                                break;
                            case 121:
                                next();
                                state = 79;
                                break;
                            case 75:
                                next();
                                state = 79;
                                break;
                            case 122:
                                next();
                                state = 79;
                                break;
                            case 73:
                                next();
                                state = 79;
                                break;
                            case 120:
                                next();
                                state = 79;
                                break;
                            case 95:
                                next();
                                state = 79;
                                break;
                            case 48:
                                next();
                                state = 79;
                                break;
                            case 70:
                                next();
                                state = 79;
                                break;
                            case 117:
                                next();
                                state = 79;
                                break;
                            case 55:
                                next();
                                state = 79;
                                break;
                            case 98:
                                next();
                                state = 79;
                                break;
                            case 51:
                                next();
                                state = 79;
                                break;
                            case 50:
                                next();
                                state = 79;
                                break;
                            case 97:
                                next();
                                state = 79;
                                break;
                            case 80:
                                next();
                                state = 79;
                                break;
                            case 79:
                                next();
                                state = 79;
                                break;
                            case 78:
                                next();
                                state = 79;
                                break;
                            case 77:
                                next();
                                state = 79;
                                break;
                            case 76:
                                next();
                                state = 79;
                                break;
                            case 65:
                                next();
                                state = 79;
                                break;
                            case 112:
                                next();
                                state = 79;
                                break;
                            case 88:
                                next();
                                state = 79;
                                break;
                            case 89:
                                next();
                                state = 79;
                                break;
                            case 66:
                                next();
                                state = 79;
                                break;
                            case 113:
                                next();
                                state = 79;
                                break;
                            case 87:
                                next();
                                state = 79;
                                break;
                            case 116:
                                next();
                                state = 79;
                                break;
                            case 69:
                                next();
                                state = 79;
                                break;
                            case 115:
                                next();
                                state = 79;
                                break;
                            case 68:
                                next();
                                state = 79;
                                break;
                            case 114:
                                next();
                                state = 79;
                                break;
                            case 67:
                                next();
                                state = 79;
                                break;
                            case 90:
                                next();
                                state = 79;
                                break;
                            case 99:
                                next();
                                state = 79;
                                break;
                            case 52:
                                next();
                                state = 79;
                                break;
                            case 100:
                                next();
                                state = 79;
                                break;
                            case 53:
                                next();
                                state = 79;
                                break;
                            case 101:
                                next();
                                state = 79;
                                break;
                            case 54:
                                next();
                                state = 79;
                                break;
                            case 111:
                                next();
                                state = 79;
                                break;
                            case 110:
                                next();
                                state = 79;
                                break;
                            case 86:
                                next();
                                state = 79;
                                break;
                            case 109:
                                next();
                                state = 79;
                                break;
                            case 85:
                                next();
                                state = 79;
                                break;
                            case 108:
                                next();
                                state = 79;
                                break;
                            case 84:
                                next();
                                state = 79;
                                break;
                            case 107:
                                next();
                                state = 79;
                                break;
                            case 83:
                                next();
                                state = 79;
                                break;
                            case 106:
                                next();
                                state = 79;
                                break;
                            case 82:
                                next();
                                state = 79;
                                break;
                            case 105:
                                next();
                                state = 79;
                                break;
                            case 104:
                                next();
                                state = 79;
                                break;
                            case 57:
                                next();
                                state = 79;
                                break;
                            case 103:
                                next();
                                state = 79;
                                break;
                            case 56:
                                next();
                                state = 79;
                                break;
                            case 102:
                                next();
                                state = 79;
                                break;
                            default:
                                m_semantic.iff(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 41:
                        switch (c) {
                            case 81:
                                next();
                                state = 79;
                                break;
                            case 49:
                                next();
                                state = 79;
                                break;
                            case 71:
                                next();
                                state = 79;
                                break;
                            case 118:
                                next();
                                state = 79;
                                break;
                            case 72:
                                next();
                                state = 79;
                                break;
                            case 119:
                                next();
                                state = 79;
                                break;
                            case 74:
                                next();
                                state = 79;
                                break;
                            case 121:
                                next();
                                state = 79;
                                break;
                            case 75:
                                next();
                                state = 79;
                                break;
                            case 122:
                                next();
                                state = 79;
                                break;
                            case 73:
                                next();
                                state = 79;
                                break;
                            case 120:
                                next();
                                state = 79;
                                break;
                            case 95:
                                next();
                                state = 79;
                                break;
                            case 48:
                                next();
                                state = 79;
                                break;
                            case 70:
                                next();
                                state = 79;
                                break;
                            case 117:
                                next();
                                state = 79;
                                break;
                            case 55:
                                next();
                                state = 79;
                                break;
                            case 98:
                                next();
                                state = 79;
                                break;
                            case 51:
                                next();
                                state = 79;
                                break;
                            case 50:
                                next();
                                state = 79;
                                break;
                            case 97:
                                next();
                                state = 79;
                                break;
                            case 80:
                                next();
                                state = 79;
                                break;
                            case 79:
                                next();
                                state = 79;
                                break;
                            case 78:
                                next();
                                state = 79;
                                break;
                            case 77:
                                next();
                                state = 79;
                                break;
                            case 76:
                                next();
                                state = 79;
                                break;
                            case 65:
                                next();
                                state = 79;
                                break;
                            case 112:
                                next();
                                state = 79;
                                break;
                            case 88:
                                next();
                                state = 79;
                                break;
                            case 89:
                                next();
                                state = 79;
                                break;
                            case 66:
                                next();
                                state = 79;
                                break;
                            case 113:
                                next();
                                state = 79;
                                break;
                            case 87:
                                next();
                                state = 79;
                                break;
                            case 116:
                                next();
                                state = 79;
                                break;
                            case 69:
                                next();
                                state = 79;
                                break;
                            case 115:
                                next();
                                state = 79;
                                break;
                            case 68:
                                next();
                                state = 79;
                                break;
                            case 114:
                                next();
                                state = 79;
                                break;
                            case 67:
                                next();
                                state = 79;
                                break;
                            case 90:
                                next();
                                state = 79;
                                break;
                            case 99:
                                next();
                                state = 79;
                                break;
                            case 52:
                                next();
                                state = 79;
                                break;
                            case 100:
                                next();
                                state = 79;
                                break;
                            case 53:
                                next();
                                state = 79;
                                break;
                            case 101:
                                next();
                                state = 79;
                                break;
                            case 54:
                                next();
                                state = 79;
                                break;
                            case 111:
                                next();
                                state = 79;
                                break;
                            case 110:
                                next();
                                state = 79;
                                break;
                            case 86:
                                next();
                                state = 79;
                                break;
                            case 109:
                                next();
                                state = 79;
                                break;
                            case 85:
                                next();
                                state = 79;
                                break;
                            case 108:
                                next();
                                state = 79;
                                break;
                            case 84:
                                next();
                                state = 79;
                                break;
                            case 107:
                                next();
                                state = 79;
                                break;
                            case 83:
                                next();
                                state = 79;
                                break;
                            case 106:
                                next();
                                state = 79;
                                break;
                            case 82:
                                next();
                                state = 79;
                                break;
                            case 105:
                                next();
                                state = 79;
                                break;
                            case 104:
                                next();
                                state = 79;
                                break;
                            case 57:
                                next();
                                state = 79;
                                break;
                            case 103:
                                next();
                                state = 79;
                                break;
                            case 56:
                                next();
                                state = 79;
                                break;
                            case 102:
                                next();
                                state = 79;
                                break;
                            default:
                                m_semantic.of(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 42:
                        switch (c) {
                            case 103:
                                next();
                                state = 79;
                                break;
                            case 57:
                                next();
                                state = 79;
                                break;
                            case 104:
                                next();
                                state = 79;
                                break;
                            case 105:
                                next();
                                state = 79;
                                break;
                            case 82:
                                next();
                                state = 79;
                                break;
                            case 106:
                                next();
                                state = 79;
                                break;
                            case 83:
                                next();
                                state = 79;
                                break;
                            case 107:
                                next();
                                state = 79;
                                break;
                            case 84:
                                next();
                                state = 79;
                                break;
                            case 108:
                                next();
                                state = 79;
                                break;
                            case 85:
                                next();
                                state = 79;
                                break;
                            case 109:
                                next();
                                state = 79;
                                break;
                            case 111:
                                next();
                                state = 79;
                                break;
                            case 110:
                                next();
                                state = 79;
                                break;
                            case 55:
                                next();
                                state = 79;
                                break;
                            case 102:
                                next();
                                state = 41;
                                break;
                            case 54:
                                next();
                                state = 79;
                                break;
                            case 81:
                                next();
                                state = 79;
                                break;
                            case 56:
                                next();
                                state = 79;
                                break;
                            case 86:
                                next();
                                state = 79;
                                break;
                            case 70:
                                next();
                                state = 79;
                                break;
                            case 117:
                                next();
                                state = 79;
                                break;
                            case 48:
                                next();
                                state = 79;
                                break;
                            case 95:
                                next();
                                state = 79;
                                break;
                            case 71:
                                next();
                                state = 79;
                                break;
                            case 118:
                                next();
                                state = 79;
                                break;
                            case 97:
                                next();
                                state = 79;
                                break;
                            case 50:
                                next();
                                state = 79;
                                break;
                            case 51:
                                next();
                                state = 79;
                                break;
                            case 98:
                                next();
                                state = 79;
                                break;
                            case 120:
                                next();
                                state = 79;
                                break;
                            case 73:
                                next();
                                state = 79;
                                break;
                            case 74:
                                next();
                                state = 79;
                                break;
                            case 121:
                                next();
                                state = 79;
                                break;
                            case 49:
                                next();
                                state = 79;
                                break;
                            case 72:
                                next();
                                state = 79;
                                break;
                            case 119:
                                next();
                                state = 79;
                                break;
                            case 75:
                                next();
                                state = 79;
                                break;
                            case 122:
                                next();
                                state = 79;
                                break;
                            case 80:
                                next();
                                state = 79;
                                break;
                            case 79:
                                next();
                                state = 79;
                                break;
                            case 78:
                                next();
                                state = 79;
                                break;
                            case 77:
                                next();
                                state = 79;
                                break;
                            case 76:
                                next();
                                state = 79;
                                break;
                            case 65:
                                next();
                                state = 79;
                                break;
                            case 112:
                                next();
                                state = 79;
                                break;
                            case 88:
                                next();
                                state = 79;
                                break;
                            case 89:
                                next();
                                state = 79;
                                break;
                            case 66:
                                next();
                                state = 79;
                                break;
                            case 113:
                                next();
                                state = 79;
                                break;
                            case 87:
                                next();
                                state = 79;
                                break;
                            case 116:
                                next();
                                state = 79;
                                break;
                            case 69:
                                next();
                                state = 79;
                                break;
                            case 115:
                                next();
                                state = 79;
                                break;
                            case 68:
                                next();
                                state = 79;
                                break;
                            case 114:
                                next();
                                state = 59;
                                break;
                            case 67:
                                next();
                                state = 79;
                                break;
                            case 90:
                                next();
                                state = 79;
                                break;
                            case 99:
                                next();
                                state = 79;
                                break;
                            case 52:
                                next();
                                state = 79;
                                break;
                            case 100:
                                next();
                                state = 79;
                                break;
                            case 53:
                                next();
                                state = 79;
                                break;
                            case 101:
                                next();
                                state = 79;
                                break;
                            default:
                                m_semantic.id(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 43:
                        switch (c) {
                            case 81:
                                next();
                                state = 79;
                                break;
                            case 49:
                                next();
                                state = 79;
                                break;
                            case 71:
                                next();
                                state = 79;
                                break;
                            case 118:
                                next();
                                state = 79;
                                break;
                            case 72:
                                next();
                                state = 79;
                                break;
                            case 119:
                                next();
                                state = 79;
                                break;
                            case 74:
                                next();
                                state = 79;
                                break;
                            case 121:
                                next();
                                state = 79;
                                break;
                            case 75:
                                next();
                                state = 79;
                                break;
                            case 122:
                                next();
                                state = 79;
                                break;
                            case 73:
                                next();
                                state = 79;
                                break;
                            case 120:
                                next();
                                state = 79;
                                break;
                            case 95:
                                next();
                                state = 79;
                                break;
                            case 48:
                                next();
                                state = 79;
                                break;
                            case 70:
                                next();
                                state = 79;
                                break;
                            case 117:
                                next();
                                state = 79;
                                break;
                            case 55:
                                next();
                                state = 79;
                                break;
                            case 98:
                                next();
                                state = 79;
                                break;
                            case 51:
                                next();
                                state = 79;
                                break;
                            case 50:
                                next();
                                state = 79;
                                break;
                            case 97:
                                next();
                                state = 79;
                                break;
                            case 80:
                                next();
                                state = 79;
                                break;
                            case 79:
                                next();
                                state = 79;
                                break;
                            case 78:
                                next();
                                state = 79;
                                break;
                            case 77:
                                next();
                                state = 79;
                                break;
                            case 76:
                                next();
                                state = 79;
                                break;
                            case 65:
                                next();
                                state = 79;
                                break;
                            case 112:
                                next();
                                state = 79;
                                break;
                            case 88:
                                next();
                                state = 79;
                                break;
                            case 89:
                                next();
                                state = 79;
                                break;
                            case 66:
                                next();
                                state = 79;
                                break;
                            case 113:
                                next();
                                state = 79;
                                break;
                            case 87:
                                next();
                                state = 79;
                                break;
                            case 116:
                                next();
                                state = 79;
                                break;
                            case 69:
                                next();
                                state = 79;
                                break;
                            case 115:
                                next();
                                state = 79;
                                break;
                            case 68:
                                next();
                                state = 79;
                                break;
                            case 114:
                                next();
                                state = 79;
                                break;
                            case 67:
                                next();
                                state = 79;
                                break;
                            case 90:
                                next();
                                state = 79;
                                break;
                            case 99:
                                next();
                                state = 79;
                                break;
                            case 52:
                                next();
                                state = 79;
                                break;
                            case 100:
                                next();
                                state = 79;
                                break;
                            case 53:
                                next();
                                state = 79;
                                break;
                            case 101:
                                next();
                                state = 79;
                                break;
                            case 54:
                                next();
                                state = 79;
                                break;
                            case 110:
                                next();
                                state = 18;
                                break;
                            case 111:
                                next();
                                state = 79;
                                break;
                            case 86:
                                next();
                                state = 79;
                                break;
                            case 109:
                                next();
                                state = 79;
                                break;
                            case 85:
                                next();
                                state = 79;
                                break;
                            case 108:
                                next();
                                state = 79;
                                break;
                            case 84:
                                next();
                                state = 79;
                                break;
                            case 107:
                                next();
                                state = 79;
                                break;
                            case 83:
                                next();
                                state = 79;
                                break;
                            case 106:
                                next();
                                state = 79;
                                break;
                            case 82:
                                next();
                                state = 79;
                                break;
                            case 105:
                                next();
                                state = 79;
                                break;
                            case 104:
                                next();
                                state = 79;
                                break;
                            case 57:
                                next();
                                state = 79;
                                break;
                            case 103:
                                next();
                                state = 79;
                                break;
                            case 56:
                                next();
                                state = 79;
                                break;
                            case 102:
                                next();
                                state = 79;
                                break;
                            default:
                                m_semantic.id(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 44:
                        switch (c) {
                            case 81:
                                next();
                                state = 79;
                                break;
                            case 49:
                                next();
                                state = 79;
                                break;
                            case 71:
                                next();
                                state = 79;
                                break;
                            case 118:
                                next();
                                state = 79;
                                break;
                            case 72:
                                next();
                                state = 79;
                                break;
                            case 119:
                                next();
                                state = 79;
                                break;
                            case 74:
                                next();
                                state = 79;
                                break;
                            case 121:
                                next();
                                state = 79;
                                break;
                            case 75:
                                next();
                                state = 79;
                                break;
                            case 122:
                                next();
                                state = 79;
                                break;
                            case 73:
                                next();
                                state = 79;
                                break;
                            case 120:
                                next();
                                state = 79;
                                break;
                            case 95:
                                next();
                                state = 79;
                                break;
                            case 48:
                                next();
                                state = 79;
                                break;
                            case 70:
                                next();
                                state = 79;
                                break;
                            case 117:
                                next();
                                state = 79;
                                break;
                            case 56:
                                next();
                                state = 79;
                                break;
                            case 98:
                                next();
                                state = 79;
                                break;
                            case 51:
                                next();
                                state = 79;
                                break;
                            case 50:
                                next();
                                state = 79;
                                break;
                            case 97:
                                next();
                                state = 79;
                                break;
                            case 80:
                                next();
                                state = 79;
                                break;
                            case 79:
                                next();
                                state = 79;
                                break;
                            case 78:
                                next();
                                state = 79;
                                break;
                            case 77:
                                next();
                                state = 79;
                                break;
                            case 76:
                                next();
                                state = 79;
                                break;
                            case 65:
                                next();
                                state = 79;
                                break;
                            case 112:
                                next();
                                state = 79;
                                break;
                            case 88:
                                next();
                                state = 79;
                                break;
                            case 89:
                                next();
                                state = 79;
                                break;
                            case 66:
                                next();
                                state = 79;
                                break;
                            case 113:
                                next();
                                state = 79;
                                break;
                            case 87:
                                next();
                                state = 79;
                                break;
                            case 116:
                                next();
                                state = 79;
                                break;
                            case 69:
                                next();
                                state = 79;
                                break;
                            case 115:
                                next();
                                state = 79;
                                break;
                            case 68:
                                next();
                                state = 79;
                                break;
                            case 114:
                                next();
                                state = 79;
                                break;
                            case 67:
                                next();
                                state = 79;
                                break;
                            case 90:
                                next();
                                state = 79;
                                break;
                            case 99:
                                next();
                                state = 79;
                                break;
                            case 52:
                                next();
                                state = 79;
                                break;
                            case 100:
                                next();
                                state = 79;
                                break;
                            case 53:
                                next();
                                state = 79;
                                break;
                            case 102:
                                next();
                                state = 79;
                                break;
                            case 55:
                                next();
                                state = 79;
                                break;
                            case 101:
                                next();
                                state = 83;
                                break;
                            case 54:
                                next();
                                state = 79;
                                break;
                            case 111:
                                next();
                                state = 79;
                                break;
                            case 110:
                                next();
                                state = 79;
                                break;
                            case 86:
                                next();
                                state = 79;
                                break;
                            case 109:
                                next();
                                state = 79;
                                break;
                            case 85:
                                next();
                                state = 79;
                                break;
                            case 108:
                                next();
                                state = 79;
                                break;
                            case 84:
                                next();
                                state = 79;
                                break;
                            case 107:
                                next();
                                state = 79;
                                break;
                            case 83:
                                next();
                                state = 79;
                                break;
                            case 106:
                                next();
                                state = 79;
                                break;
                            case 82:
                                next();
                                state = 79;
                                break;
                            case 105:
                                next();
                                state = 79;
                                break;
                            case 104:
                                next();
                                state = 79;
                                break;
                            case 57:
                                next();
                                state = 79;
                                break;
                            case 103:
                                next();
                                state = 79;
                                break;
                            default:
                                m_semantic.id(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 45:
                        switch (c) {
                            case 81:
                                next();
                                state = 79;
                                break;
                            case 49:
                                next();
                                state = 79;
                                break;
                            case 71:
                                next();
                                state = 79;
                                break;
                            case 118:
                                next();
                                state = 79;
                                break;
                            case 72:
                                next();
                                state = 79;
                                break;
                            case 119:
                                next();
                                state = 79;
                                break;
                            case 74:
                                next();
                                state = 79;
                                break;
                            case 121:
                                next();
                                state = 79;
                                break;
                            case 75:
                                next();
                                state = 79;
                                break;
                            case 122:
                                next();
                                state = 79;
                                break;
                            case 73:
                                next();
                                state = 79;
                                break;
                            case 120:
                                next();
                                state = 79;
                                break;
                            case 95:
                                next();
                                state = 79;
                                break;
                            case 48:
                                next();
                                state = 79;
                                break;
                            case 70:
                                next();
                                state = 79;
                                break;
                            case 117:
                                next();
                                state = 79;
                                break;
                            case 55:
                                next();
                                state = 79;
                                break;
                            case 98:
                                next();
                                state = 79;
                                break;
                            case 51:
                                next();
                                state = 79;
                                break;
                            case 50:
                                next();
                                state = 79;
                                break;
                            case 97:
                                next();
                                state = 79;
                                break;
                            case 80:
                                next();
                                state = 79;
                                break;
                            case 79:
                                next();
                                state = 79;
                                break;
                            case 78:
                                next();
                                state = 79;
                                break;
                            case 77:
                                next();
                                state = 79;
                                break;
                            case 76:
                                next();
                                state = 79;
                                break;
                            case 65:
                                next();
                                state = 79;
                                break;
                            case 112:
                                next();
                                state = 79;
                                break;
                            case 88:
                                next();
                                state = 79;
                                break;
                            case 89:
                                next();
                                state = 79;
                                break;
                            case 66:
                                next();
                                state = 79;
                                break;
                            case 113:
                                next();
                                state = 79;
                                break;
                            case 87:
                                next();
                                state = 79;
                                break;
                            case 116:
                                next();
                                state = 79;
                                break;
                            case 69:
                                next();
                                state = 79;
                                break;
                            case 115:
                                next();
                                state = 79;
                                break;
                            case 68:
                                next();
                                state = 79;
                                break;
                            case 114:
                                next();
                                state = 79;
                                break;
                            case 67:
                                next();
                                state = 79;
                                break;
                            case 90:
                                next();
                                state = 79;
                                break;
                            case 99:
                                next();
                                state = 79;
                                break;
                            case 52:
                                next();
                                state = 79;
                                break;
                            case 100:
                                next();
                                state = 79;
                                break;
                            case 53:
                                next();
                                state = 79;
                                break;
                            case 101:
                                next();
                                state = 79;
                                break;
                            case 54:
                                next();
                                state = 79;
                                break;
                            case 111:
                                next();
                                state = 79;
                                break;
                            case 110:
                                next();
                                state = 79;
                                break;
                            case 86:
                                next();
                                state = 79;
                                break;
                            case 109:
                                next();
                                state = 79;
                                break;
                            case 85:
                                next();
                                state = 79;
                                break;
                            case 108:
                                next();
                                state = 79;
                                break;
                            case 84:
                                next();
                                state = 79;
                                break;
                            case 107:
                                next();
                                state = 79;
                                break;
                            case 83:
                                next();
                                state = 79;
                                break;
                            case 106:
                                next();
                                state = 79;
                                break;
                            case 82:
                                next();
                                state = 79;
                                break;
                            case 105:
                                next();
                                state = 79;
                                break;
                            case 104:
                                next();
                                state = 79;
                                break;
                            case 57:
                                next();
                                state = 79;
                                break;
                            case 103:
                                next();
                                state = 79;
                                break;
                            case 56:
                                next();
                                state = 79;
                                break;
                            case 102:
                                next();
                                state = 79;
                                break;
                            default:
                                m_semantic.procedure(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 46:
                        switch (c) {
                            case 49:
                                next();
                                state = 79;
                                break;
                            case 71:
                                next();
                                state = 79;
                                break;
                            case 118:
                                next();
                                state = 79;
                                break;
                            case 72:
                                next();
                                state = 79;
                                break;
                            case 119:
                                next();
                                state = 79;
                                break;
                            case 74:
                                next();
                                state = 79;
                                break;
                            case 121:
                                next();
                                state = 79;
                                break;
                            case 75:
                                next();
                                state = 79;
                                break;
                            case 122:
                                next();
                                state = 79;
                                break;
                            case 73:
                                next();
                                state = 79;
                                break;
                            case 120:
                                next();
                                state = 79;
                                break;
                            case 95:
                                next();
                                state = 79;
                                break;
                            case 48:
                                next();
                                state = 79;
                                break;
                            case 70:
                                next();
                                state = 79;
                                break;
                            case 117:
                                next();
                                state = 79;
                                break;
                            case 86:
                                next();
                                state = 79;
                                break;
                            case 56:
                                next();
                                state = 79;
                                break;
                            case 98:
                                next();
                                state = 79;
                                break;
                            case 51:
                                next();
                                state = 79;
                                break;
                            case 50:
                                next();
                                state = 79;
                                break;
                            case 97:
                                next();
                                state = 79;
                                break;
                            case 81:
                                next();
                                state = 79;
                                break;
                            case 80:
                                next();
                                state = 79;
                                break;
                            case 79:
                                next();
                                state = 79;
                                break;
                            case 78:
                                next();
                                state = 79;
                                break;
                            case 77:
                                next();
                                state = 79;
                                break;
                            case 76:
                                next();
                                state = 79;
                                break;
                            case 65:
                                next();
                                state = 79;
                                break;
                            case 112:
                                next();
                                state = 79;
                                break;
                            case 88:
                                next();
                                state = 79;
                                break;
                            case 87:
                                next();
                                state = 79;
                                break;
                            case 69:
                                next();
                                state = 79;
                                break;
                            case 116:
                                next();
                                state = 16;
                                break;
                            case 115:
                                next();
                                state = 79;
                                break;
                            case 68:
                                next();
                                state = 79;
                                break;
                            case 89:
                                next();
                                state = 79;
                                break;
                            case 66:
                                next();
                                state = 79;
                                break;
                            case 113:
                                next();
                                state = 79;
                                break;
                            case 114:
                                next();
                                state = 79;
                                break;
                            case 67:
                                next();
                                state = 79;
                                break;
                            case 90:
                                next();
                                state = 79;
                                break;
                            case 99:
                                next();
                                state = 79;
                                break;
                            case 52:
                                next();
                                state = 79;
                                break;
                            case 100:
                                next();
                                state = 79;
                                break;
                            case 53:
                                next();
                                state = 79;
                                break;
                            case 101:
                                next();
                                state = 79;
                                break;
                            case 54:
                                next();
                                state = 79;
                                break;
                            case 102:
                                next();
                                state = 79;
                                break;
                            case 55:
                                next();
                                state = 79;
                                break;
                            case 82:
                                next();
                                state = 79;
                                break;
                            case 105:
                                next();
                                state = 79;
                                break;
                            case 111:
                                next();
                                state = 79;
                                break;
                            case 110:
                                next();
                                state = 79;
                                break;
                            case 109:
                                next();
                                state = 79;
                                break;
                            case 85:
                                next();
                                state = 79;
                                break;
                            case 108:
                                next();
                                state = 79;
                                break;
                            case 84:
                                next();
                                state = 79;
                                break;
                            case 107:
                                next();
                                state = 79;
                                break;
                            case 83:
                                next();
                                state = 79;
                                break;
                            case 106:
                                next();
                                state = 79;
                                break;
                            case 104:
                                next();
                                state = 79;
                                break;
                            case 57:
                                next();
                                state = 79;
                                break;
                            case 103:
                                next();
                                state = 79;
                                break;
                            default:
                                m_semantic.id(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 47:
                        m_semantic.add(m_lexeme.str());
                        return true;
                    case 48:
                        switch (c) {
                            case 103:
                                next();
                                state = 79;
                                break;
                            case 57:
                                next();
                                state = 79;
                                break;
                            case 104:
                                next();
                                state = 84;
                                break;
                            case 105:
                                next();
                                state = 79;
                                break;
                            case 82:
                                next();
                                state = 79;
                                break;
                            case 106:
                                next();
                                state = 79;
                                break;
                            case 83:
                                next();
                                state = 79;
                                break;
                            case 107:
                                next();
                                state = 79;
                                break;
                            case 84:
                                next();
                                state = 79;
                                break;
                            case 108:
                                next();
                                state = 79;
                                break;
                            case 85:
                                next();
                                state = 79;
                                break;
                            case 109:
                                next();
                                state = 79;
                                break;
                            case 111:
                                next();
                                state = 79;
                                break;
                            case 110:
                                next();
                                state = 79;
                                break;
                            case 55:
                                next();
                                state = 79;
                                break;
                            case 102:
                                next();
                                state = 79;
                                break;
                            case 54:
                                next();
                                state = 79;
                                break;
                            case 81:
                                next();
                                state = 79;
                                break;
                            case 56:
                                next();
                                state = 79;
                                break;
                            case 86:
                                next();
                                state = 79;
                                break;
                            case 70:
                                next();
                                state = 79;
                                break;
                            case 117:
                                next();
                                state = 79;
                                break;
                            case 48:
                                next();
                                state = 79;
                                break;
                            case 95:
                                next();
                                state = 79;
                                break;
                            case 71:
                                next();
                                state = 79;
                                break;
                            case 118:
                                next();
                                state = 79;
                                break;
                            case 97:
                                next();
                                state = 79;
                                break;
                            case 50:
                                next();
                                state = 79;
                                break;
                            case 51:
                                next();
                                state = 79;
                                break;
                            case 98:
                                next();
                                state = 79;
                                break;
                            case 120:
                                next();
                                state = 79;
                                break;
                            case 73:
                                next();
                                state = 79;
                                break;
                            case 74:
                                next();
                                state = 79;
                                break;
                            case 121:
                                next();
                                state = 79;
                                break;
                            case 49:
                                next();
                                state = 79;
                                break;
                            case 72:
                                next();
                                state = 79;
                                break;
                            case 119:
                                next();
                                state = 79;
                                break;
                            case 75:
                                next();
                                state = 79;
                                break;
                            case 122:
                                next();
                                state = 79;
                                break;
                            case 80:
                                next();
                                state = 79;
                                break;
                            case 79:
                                next();
                                state = 79;
                                break;
                            case 78:
                                next();
                                state = 79;
                                break;
                            case 77:
                                next();
                                state = 79;
                                break;
                            case 76:
                                next();
                                state = 79;
                                break;
                            case 65:
                                next();
                                state = 79;
                                break;
                            case 112:
                                next();
                                state = 79;
                                break;
                            case 88:
                                next();
                                state = 79;
                                break;
                            case 89:
                                next();
                                state = 79;
                                break;
                            case 66:
                                next();
                                state = 79;
                                break;
                            case 113:
                                next();
                                state = 79;
                                break;
                            case 87:
                                next();
                                state = 79;
                                break;
                            case 116:
                                next();
                                state = 79;
                                break;
                            case 69:
                                next();
                                state = 79;
                                break;
                            case 115:
                                next();
                                state = 79;
                                break;
                            case 68:
                                next();
                                state = 79;
                                break;
                            case 114:
                                next();
                                state = 79;
                                break;
                            case 67:
                                next();
                                state = 79;
                                break;
                            case 90:
                                next();
                                state = 79;
                                break;
                            case 99:
                                next();
                                state = 79;
                                break;
                            case 52:
                                next();
                                state = 79;
                                break;
                            case 100:
                                next();
                                state = 79;
                                break;
                            case 53:
                                next();
                                state = 79;
                                break;
                            case 101:
                                next();
                                state = 79;
                                break;
                            default:
                                m_semantic.id(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 49:
                        switch (c) {
                            case 81:
                                next();
                                state = 79;
                                break;
                            case 49:
                                next();
                                state = 79;
                                break;
                            case 71:
                                next();
                                state = 79;
                                break;
                            case 118:
                                next();
                                state = 79;
                                break;
                            case 72:
                                next();
                                state = 79;
                                break;
                            case 119:
                                next();
                                state = 79;
                                break;
                            case 74:
                                next();
                                state = 79;
                                break;
                            case 121:
                                next();
                                state = 79;
                                break;
                            case 75:
                                next();
                                state = 79;
                                break;
                            case 122:
                                next();
                                state = 79;
                                break;
                            case 73:
                                next();
                                state = 79;
                                break;
                            case 120:
                                next();
                                state = 79;
                                break;
                            case 95:
                                next();
                                state = 79;
                                break;
                            case 48:
                                next();
                                state = 79;
                                break;
                            case 86:
                                next();
                                state = 79;
                                break;
                            case 56:
                                next();
                                state = 79;
                                break;
                            case 103:
                                next();
                                state = 79;
                                break;
                            case 98:
                                next();
                                state = 79;
                                break;
                            case 51:
                                next();
                                state = 79;
                                break;
                            case 50:
                                next();
                                state = 79;
                                break;
                            case 97:
                                next();
                                state = 79;
                                break;
                            case 80:
                                next();
                                state = 79;
                                break;
                            case 79:
                                next();
                                state = 79;
                                break;
                            case 78:
                                next();
                                state = 79;
                                break;
                            case 77:
                                next();
                                state = 79;
                                break;
                            case 76:
                                next();
                                state = 79;
                                break;
                            case 65:
                                next();
                                state = 79;
                                break;
                            case 112:
                                next();
                                state = 79;
                                break;
                            case 88:
                                next();
                                state = 79;
                                break;
                            case 89:
                                next();
                                state = 79;
                                break;
                            case 66:
                                next();
                                state = 79;
                                break;
                            case 113:
                                next();
                                state = 79;
                                break;
                            case 87:
                                next();
                                state = 79;
                                break;
                            case 116:
                                next();
                                state = 79;
                                break;
                            case 69:
                                next();
                                state = 79;
                                break;
                            case 115:
                                next();
                                state = 79;
                                break;
                            case 68:
                                next();
                                state = 79;
                                break;
                            case 114:
                                next();
                                state = 79;
                                break;
                            case 67:
                                next();
                                state = 79;
                                break;
                            case 90:
                                next();
                                state = 79;
                                break;
                            case 99:
                                next();
                                state = 79;
                                break;
                            case 52:
                                next();
                                state = 79;
                                break;
                            case 100:
                                next();
                                state = 79;
                                break;
                            case 53:
                                next();
                                state = 79;
                                break;
                            case 101:
                                next();
                                state = 79;
                                break;
                            case 54:
                                next();
                                state = 79;
                                break;
                            case 102:
                                next();
                                state = 79;
                                break;
                            case 55:
                                next();
                                state = 79;
                                break;
                            case 117:
                                next();
                                state = 1;
                                break;
                            case 70:
                                next();
                                state = 79;
                                break;
                            case 83:
                                next();
                                state = 79;
                                break;
                            case 106:
                                next();
                                state = 79;
                                break;
                            case 111:
                                next();
                                state = 79;
                                break;
                            case 110:
                                next();
                                state = 79;
                                break;
                            case 109:
                                next();
                                state = 79;
                                break;
                            case 85:
                                next();
                                state = 79;
                                break;
                            case 108:
                                next();
                                state = 79;
                                break;
                            case 84:
                                next();
                                state = 79;
                                break;
                            case 107:
                                next();
                                state = 79;
                                break;
                            case 82:
                                next();
                                state = 79;
                                break;
                            case 105:
                                next();
                                state = 79;
                                break;
                            case 104:
                                next();
                                state = 79;
                                break;
                            case 57:
                                next();
                                state = 79;
                                break;
                            default:
                                m_semantic.id(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 50:
                        switch (c) {
                            case 81:
                                next();
                                state = 79;
                                break;
                            case 49:
                                next();
                                state = 79;
                                break;
                            case 71:
                                next();
                                state = 79;
                                break;
                            case 118:
                                next();
                                state = 79;
                                break;
                            case 72:
                                next();
                                state = 79;
                                break;
                            case 119:
                                next();
                                state = 79;
                                break;
                            case 74:
                                next();
                                state = 79;
                                break;
                            case 121:
                                next();
                                state = 79;
                                break;
                            case 75:
                                next();
                                state = 79;
                                break;
                            case 122:
                                next();
                                state = 79;
                                break;
                            case 73:
                                next();
                                state = 79;
                                break;
                            case 120:
                                next();
                                state = 79;
                                break;
                            case 95:
                                next();
                                state = 79;
                                break;
                            case 48:
                                next();
                                state = 79;
                                break;
                            case 70:
                                next();
                                state = 79;
                                break;
                            case 117:
                                next();
                                state = 79;
                                break;
                            case 56:
                                next();
                                state = 79;
                                break;
                            case 98:
                                next();
                                state = 79;
                                break;
                            case 51:
                                next();
                                state = 79;
                                break;
                            case 50:
                                next();
                                state = 79;
                                break;
                            case 97:
                                next();
                                state = 79;
                                break;
                            case 80:
                                next();
                                state = 79;
                                break;
                            case 79:
                                next();
                                state = 79;
                                break;
                            case 78:
                                next();
                                state = 79;
                                break;
                            case 77:
                                next();
                                state = 79;
                                break;
                            case 76:
                                next();
                                state = 79;
                                break;
                            case 65:
                                next();
                                state = 79;
                                break;
                            case 112:
                                next();
                                state = 79;
                                break;
                            case 88:
                                next();
                                state = 79;
                                break;
                            case 89:
                                next();
                                state = 79;
                                break;
                            case 66:
                                next();
                                state = 79;
                                break;
                            case 113:
                                next();
                                state = 79;
                                break;
                            case 87:
                                next();
                                state = 79;
                                break;
                            case 116:
                                next();
                                state = 79;
                                break;
                            case 69:
                                next();
                                state = 79;
                                break;
                            case 115:
                                next();
                                state = 79;
                                break;
                            case 68:
                                next();
                                state = 79;
                                break;
                            case 114:
                                next();
                                state = 79;
                                break;
                            case 67:
                                next();
                                state = 79;
                                break;
                            case 90:
                                next();
                                state = 79;
                                break;
                            case 99:
                                next();
                                state = 79;
                                break;
                            case 52:
                                next();
                                state = 79;
                                break;
                            case 101:
                                next();
                                state = 79;
                                break;
                            case 54:
                                next();
                                state = 79;
                                break;
                            case 102:
                                next();
                                state = 79;
                                break;
                            case 55:
                                next();
                                state = 79;
                                break;
                            case 100:
                                next();
                                state = 54;
                                break;
                            case 53:
                                next();
                                state = 79;
                                break;
                            case 111:
                                next();
                                state = 79;
                                break;
                            case 110:
                                next();
                                state = 79;
                                break;
                            case 86:
                                next();
                                state = 79;
                                break;
                            case 109:
                                next();
                                state = 79;
                                break;
                            case 85:
                                next();
                                state = 79;
                                break;
                            case 108:
                                next();
                                state = 79;
                                break;
                            case 84:
                                next();
                                state = 79;
                                break;
                            case 107:
                                next();
                                state = 79;
                                break;
                            case 83:
                                next();
                                state = 79;
                                break;
                            case 106:
                                next();
                                state = 79;
                                break;
                            case 82:
                                next();
                                state = 79;
                                break;
                            case 105:
                                next();
                                state = 79;
                                break;
                            case 104:
                                next();
                                state = 79;
                                break;
                            case 57:
                                next();
                                state = 79;
                                break;
                            case 103:
                                next();
                                state = 79;
                                break;
                            default:
                                m_semantic.id(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 51:
                        m_semantic.rsquare(m_lexeme.str());
                        return true;
                    case 52:
                        switch (c) {
                            case 81:
                                next();
                                state = 79;
                                break;
                            case 49:
                                next();
                                state = 79;
                                break;
                            case 71:
                                next();
                                state = 79;
                                break;
                            case 118:
                                next();
                                state = 79;
                                break;
                            case 72:
                                next();
                                state = 79;
                                break;
                            case 119:
                                next();
                                state = 79;
                                break;
                            case 74:
                                next();
                                state = 79;
                                break;
                            case 121:
                                next();
                                state = 79;
                                break;
                            case 75:
                                next();
                                state = 79;
                                break;
                            case 122:
                                next();
                                state = 79;
                                break;
                            case 73:
                                next();
                                state = 79;
                                break;
                            case 120:
                                next();
                                state = 79;
                                break;
                            case 95:
                                next();
                                state = 79;
                                break;
                            case 48:
                                next();
                                state = 79;
                                break;
                            case 70:
                                next();
                                state = 79;
                                break;
                            case 117:
                                next();
                                state = 79;
                                break;
                            case 56:
                                next();
                                state = 79;
                                break;
                            case 98:
                                next();
                                state = 79;
                                break;
                            case 51:
                                next();
                                state = 79;
                                break;
                            case 50:
                                next();
                                state = 79;
                                break;
                            case 97:
                                next();
                                state = 79;
                                break;
                            case 80:
                                next();
                                state = 79;
                                break;
                            case 79:
                                next();
                                state = 79;
                                break;
                            case 78:
                                next();
                                state = 79;
                                break;
                            case 77:
                                next();
                                state = 79;
                                break;
                            case 76:
                                next();
                                state = 79;
                                break;
                            case 65:
                                next();
                                state = 79;
                                break;
                            case 112:
                                next();
                                state = 79;
                                break;
                            case 88:
                                next();
                                state = 79;
                                break;
                            case 89:
                                next();
                                state = 79;
                                break;
                            case 66:
                                next();
                                state = 79;
                                break;
                            case 113:
                                next();
                                state = 79;
                                break;
                            case 87:
                                next();
                                state = 79;
                                break;
                            case 116:
                                next();
                                state = 79;
                                break;
                            case 69:
                                next();
                                state = 79;
                                break;
                            case 115:
                                next();
                                state = 79;
                                break;
                            case 68:
                                next();
                                state = 79;
                                break;
                            case 114:
                                next();
                                state = 79;
                                break;
                            case 67:
                                next();
                                state = 79;
                                break;
                            case 90:
                                next();
                                state = 79;
                                break;
                            case 99:
                                next();
                                state = 79;
                                break;
                            case 52:
                                next();
                                state = 79;
                                break;
                            case 101:
                                next();
                                state = 79;
                                break;
                            case 54:
                                next();
                                state = 79;
                                break;
                            case 102:
                                next();
                                state = 79;
                                break;
                            case 55:
                                next();
                                state = 79;
                                break;
                            case 100:
                                next();
                                state = 106;
                                break;
                            case 53:
                                next();
                                state = 79;
                                break;
                            case 111:
                                next();
                                state = 79;
                                break;
                            case 110:
                                next();
                                state = 79;
                                break;
                            case 86:
                                next();
                                state = 79;
                                break;
                            case 109:
                                next();
                                state = 79;
                                break;
                            case 85:
                                next();
                                state = 79;
                                break;
                            case 108:
                                next();
                                state = 79;
                                break;
                            case 84:
                                next();
                                state = 79;
                                break;
                            case 107:
                                next();
                                state = 79;
                                break;
                            case 83:
                                next();
                                state = 79;
                                break;
                            case 106:
                                next();
                                state = 79;
                                break;
                            case 82:
                                next();
                                state = 79;
                                break;
                            case 105:
                                next();
                                state = 79;
                                break;
                            case 104:
                                next();
                                state = 79;
                                break;
                            case 57:
                                next();
                                state = 79;
                                break;
                            case 103:
                                next();
                                state = 79;
                                break;
                            default:
                                m_semantic.id(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 53:
                        switch (c) {
                            case 81:
                                next();
                                state = 79;
                                break;
                            case 49:
                                next();
                                state = 79;
                                break;
                            case 71:
                                next();
                                state = 79;
                                break;
                            case 118:
                                next();
                                state = 79;
                                break;
                            case 72:
                                next();
                                state = 79;
                                break;
                            case 119:
                                next();
                                state = 79;
                                break;
                            case 74:
                                next();
                                state = 79;
                                break;
                            case 121:
                                next();
                                state = 79;
                                break;
                            case 75:
                                next();
                                state = 79;
                                break;
                            case 122:
                                next();
                                state = 79;
                                break;
                            case 73:
                                next();
                                state = 79;
                                break;
                            case 120:
                                next();
                                state = 79;
                                break;
                            case 95:
                                next();
                                state = 79;
                                break;
                            case 48:
                                next();
                                state = 79;
                                break;
                            case 70:
                                next();
                                state = 79;
                                break;
                            case 117:
                                next();
                                state = 79;
                                break;
                            case 55:
                                next();
                                state = 79;
                                break;
                            case 98:
                                next();
                                state = 79;
                                break;
                            case 51:
                                next();
                                state = 79;
                                break;
                            case 50:
                                next();
                                state = 79;
                                break;
                            case 97:
                                next();
                                state = 79;
                                break;
                            case 80:
                                next();
                                state = 79;
                                break;
                            case 79:
                                next();
                                state = 79;
                                break;
                            case 78:
                                next();
                                state = 79;
                                break;
                            case 77:
                                next();
                                state = 79;
                                break;
                            case 76:
                                next();
                                state = 79;
                                break;
                            case 65:
                                next();
                                state = 79;
                                break;
                            case 112:
                                next();
                                state = 79;
                                break;
                            case 88:
                                next();
                                state = 79;
                                break;
                            case 89:
                                next();
                                state = 79;
                                break;
                            case 66:
                                next();
                                state = 79;
                                break;
                            case 113:
                                next();
                                state = 79;
                                break;
                            case 87:
                                next();
                                state = 79;
                                break;
                            case 116:
                                next();
                                state = 79;
                                break;
                            case 69:
                                next();
                                state = 79;
                                break;
                            case 115:
                                next();
                                state = 46;
                                break;
                            case 68:
                                next();
                                state = 79;
                                break;
                            case 114:
                                next();
                                state = 79;
                                break;
                            case 67:
                                next();
                                state = 79;
                                break;
                            case 90:
                                next();
                                state = 79;
                                break;
                            case 99:
                                next();
                                state = 79;
                                break;
                            case 52:
                                next();
                                state = 79;
                                break;
                            case 100:
                                next();
                                state = 79;
                                break;
                            case 53:
                                next();
                                state = 79;
                                break;
                            case 101:
                                next();
                                state = 79;
                                break;
                            case 54:
                                next();
                                state = 79;
                                break;
                            case 111:
                                next();
                                state = 79;
                                break;
                            case 110:
                                next();
                                state = 79;
                                break;
                            case 86:
                                next();
                                state = 79;
                                break;
                            case 109:
                                next();
                                state = 79;
                                break;
                            case 85:
                                next();
                                state = 79;
                                break;
                            case 108:
                                next();
                                state = 79;
                                break;
                            case 84:
                                next();
                                state = 79;
                                break;
                            case 107:
                                next();
                                state = 79;
                                break;
                            case 83:
                                next();
                                state = 79;
                                break;
                            case 106:
                                next();
                                state = 79;
                                break;
                            case 82:
                                next();
                                state = 79;
                                break;
                            case 105:
                                next();
                                state = 79;
                                break;
                            case 104:
                                next();
                                state = 79;
                                break;
                            case 57:
                                next();
                                state = 79;
                                break;
                            case 103:
                                next();
                                state = 79;
                                break;
                            case 56:
                                next();
                                state = 79;
                                break;
                            case 102:
                                next();
                                state = 79;
                                break;
                            default:
                                m_semantic.id(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 54:
                        switch (c) {
                            case 81:
                                next();
                                state = 79;
                                break;
                            case 49:
                                next();
                                state = 79;
                                break;
                            case 71:
                                next();
                                state = 79;
                                break;
                            case 118:
                                next();
                                state = 79;
                                break;
                            case 72:
                                next();
                                state = 79;
                                break;
                            case 119:
                                next();
                                state = 79;
                                break;
                            case 74:
                                next();
                                state = 79;
                                break;
                            case 121:
                                next();
                                state = 79;
                                break;
                            case 75:
                                next();
                                state = 79;
                                break;
                            case 122:
                                next();
                                state = 79;
                                break;
                            case 73:
                                next();
                                state = 79;
                                break;
                            case 120:
                                next();
                                state = 79;
                                break;
                            case 95:
                                next();
                                state = 79;
                                break;
                            case 48:
                                next();
                                state = 79;
                                break;
                            case 70:
                                next();
                                state = 79;
                                break;
                            case 117:
                                next();
                                state = 79;
                                break;
                            case 55:
                                next();
                                state = 79;
                                break;
                            case 98:
                                next();
                                state = 79;
                                break;
                            case 51:
                                next();
                                state = 79;
                                break;
                            case 50:
                                next();
                                state = 79;
                                break;
                            case 97:
                                next();
                                state = 79;
                                break;
                            case 80:
                                next();
                                state = 79;
                                break;
                            case 79:
                                next();
                                state = 79;
                                break;
                            case 78:
                                next();
                                state = 79;
                                break;
                            case 77:
                                next();
                                state = 79;
                                break;
                            case 76:
                                next();
                                state = 79;
                                break;
                            case 65:
                                next();
                                state = 79;
                                break;
                            case 112:
                                next();
                                state = 79;
                                break;
                            case 88:
                                next();
                                state = 79;
                                break;
                            case 89:
                                next();
                                state = 79;
                                break;
                            case 66:
                                next();
                                state = 79;
                                break;
                            case 113:
                                next();
                                state = 79;
                                break;
                            case 87:
                                next();
                                state = 79;
                                break;
                            case 116:
                                next();
                                state = 79;
                                break;
                            case 69:
                                next();
                                state = 79;
                                break;
                            case 115:
                                next();
                                state = 79;
                                break;
                            case 68:
                                next();
                                state = 79;
                                break;
                            case 114:
                                next();
                                state = 79;
                                break;
                            case 67:
                                next();
                                state = 79;
                                break;
                            case 90:
                                next();
                                state = 79;
                                break;
                            case 99:
                                next();
                                state = 79;
                                break;
                            case 52:
                                next();
                                state = 79;
                                break;
                            case 100:
                                next();
                                state = 79;
                                break;
                            case 53:
                                next();
                                state = 79;
                                break;
                            case 101:
                                next();
                                state = 79;
                                break;
                            case 54:
                                next();
                                state = 79;
                                break;
                            case 111:
                                next();
                                state = 79;
                                break;
                            case 110:
                                next();
                                state = 79;
                                break;
                            case 86:
                                next();
                                state = 79;
                                break;
                            case 109:
                                next();
                                state = 79;
                                break;
                            case 85:
                                next();
                                state = 79;
                                break;
                            case 108:
                                next();
                                state = 79;
                                break;
                            case 84:
                                next();
                                state = 79;
                                break;
                            case 107:
                                next();
                                state = 79;
                                break;
                            case 83:
                                next();
                                state = 79;
                                break;
                            case 106:
                                next();
                                state = 79;
                                break;
                            case 82:
                                next();
                                state = 79;
                                break;
                            case 105:
                                next();
                                state = 79;
                                break;
                            case 104:
                                next();
                                state = 79;
                                break;
                            case 57:
                                next();
                                state = 79;
                                break;
                            case 103:
                                next();
                                state = 79;
                                break;
                            case 56:
                                next();
                                state = 79;
                                break;
                            case 102:
                                next();
                                state = 79;
                                break;
                            default:
                                m_semantic.end(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 55:
                        switch (c) {
                            case 81:
                                next();
                                state = 79;
                                break;
                            case 49:
                                next();
                                state = 79;
                                break;
                            case 71:
                                next();
                                state = 79;
                                break;
                            case 118:
                                next();
                                state = 79;
                                break;
                            case 72:
                                next();
                                state = 79;
                                break;
                            case 119:
                                next();
                                state = 79;
                                break;
                            case 74:
                                next();
                                state = 79;
                                break;
                            case 121:
                                next();
                                state = 79;
                                break;
                            case 75:
                                next();
                                state = 79;
                                break;
                            case 122:
                                next();
                                state = 79;
                                break;
                            case 73:
                                next();
                                state = 79;
                                break;
                            case 120:
                                next();
                                state = 79;
                                break;
                            case 95:
                                next();
                                state = 79;
                                break;
                            case 48:
                                next();
                                state = 79;
                                break;
                            case 70:
                                next();
                                state = 79;
                                break;
                            case 117:
                                next();
                                state = 79;
                                break;
                            case 55:
                                next();
                                state = 79;
                                break;
                            case 98:
                                next();
                                state = 79;
                                break;
                            case 51:
                                next();
                                state = 79;
                                break;
                            case 50:
                                next();
                                state = 79;
                                break;
                            case 97:
                                next();
                                state = 20;
                                break;
                            case 80:
                                next();
                                state = 79;
                                break;
                            case 79:
                                next();
                                state = 79;
                                break;
                            case 78:
                                next();
                                state = 79;
                                break;
                            case 77:
                                next();
                                state = 79;
                                break;
                            case 76:
                                next();
                                state = 79;
                                break;
                            case 65:
                                next();
                                state = 79;
                                break;
                            case 112:
                                next();
                                state = 79;
                                break;
                            case 88:
                                next();
                                state = 79;
                                break;
                            case 89:
                                next();
                                state = 79;
                                break;
                            case 66:
                                next();
                                state = 79;
                                break;
                            case 113:
                                next();
                                state = 79;
                                break;
                            case 87:
                                next();
                                state = 79;
                                break;
                            case 116:
                                next();
                                state = 79;
                                break;
                            case 69:
                                next();
                                state = 79;
                                break;
                            case 115:
                                next();
                                state = 79;
                                break;
                            case 68:
                                next();
                                state = 79;
                                break;
                            case 114:
                                next();
                                state = 79;
                                break;
                            case 67:
                                next();
                                state = 79;
                                break;
                            case 90:
                                next();
                                state = 79;
                                break;
                            case 99:
                                next();
                                state = 79;
                                break;
                            case 52:
                                next();
                                state = 79;
                                break;
                            case 100:
                                next();
                                state = 79;
                                break;
                            case 53:
                                next();
                                state = 79;
                                break;
                            case 101:
                                next();
                                state = 79;
                                break;
                            case 54:
                                next();
                                state = 79;
                                break;
                            case 111:
                                next();
                                state = 79;
                                break;
                            case 110:
                                next();
                                state = 79;
                                break;
                            case 86:
                                next();
                                state = 79;
                                break;
                            case 109:
                                next();
                                state = 79;
                                break;
                            case 85:
                                next();
                                state = 79;
                                break;
                            case 108:
                                next();
                                state = 79;
                                break;
                            case 84:
                                next();
                                state = 79;
                                break;
                            case 107:
                                next();
                                state = 79;
                                break;
                            case 83:
                                next();
                                state = 79;
                                break;
                            case 106:
                                next();
                                state = 79;
                                break;
                            case 82:
                                next();
                                state = 79;
                                break;
                            case 105:
                                next();
                                state = 79;
                                break;
                            case 104:
                                next();
                                state = 79;
                                break;
                            case 57:
                                next();
                                state = 79;
                                break;
                            case 103:
                                next();
                                state = 79;
                                break;
                            case 56:
                                next();
                                state = 79;
                                break;
                            case 102:
                                next();
                                state = 79;
                                break;
                            default:
                                m_semantic.id(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 56:
                        switch (c) {
                            case 49:
                                next();
                                state = 79;
                                break;
                            case 71:
                                next();
                                state = 79;
                                break;
                            case 118:
                                next();
                                state = 79;
                                break;
                            case 72:
                                next();
                                state = 79;
                                break;
                            case 119:
                                next();
                                state = 79;
                                break;
                            case 74:
                                next();
                                state = 79;
                                break;
                            case 121:
                                next();
                                state = 79;
                                break;
                            case 75:
                                next();
                                state = 79;
                                break;
                            case 122:
                                next();
                                state = 79;
                                break;
                            case 73:
                                next();
                                state = 79;
                                break;
                            case 120:
                                next();
                                state = 79;
                                break;
                            case 95:
                                next();
                                state = 79;
                                break;
                            case 48:
                                next();
                                state = 79;
                                break;
                            case 70:
                                next();
                                state = 79;
                                break;
                            case 117:
                                next();
                                state = 79;
                                break;
                            case 86:
                                next();
                                state = 79;
                                break;
                            case 56:
                                next();
                                state = 79;
                                break;
                            case 98:
                                next();
                                state = 79;
                                break;
                            case 51:
                                next();
                                state = 79;
                                break;
                            case 50:
                                next();
                                state = 79;
                                break;
                            case 97:
                                next();
                                state = 79;
                                break;
                            case 81:
                                next();
                                state = 79;
                                break;
                            case 80:
                                next();
                                state = 79;
                                break;
                            case 79:
                                next();
                                state = 79;
                                break;
                            case 78:
                                next();
                                state = 79;
                                break;
                            case 77:
                                next();
                                state = 79;
                                break;
                            case 76:
                                next();
                                state = 79;
                                break;
                            case 65:
                                next();
                                state = 79;
                                break;
                            case 112:
                                next();
                                state = 79;
                                break;
                            case 88:
                                next();
                                state = 79;
                                break;
                            case 87:
                                next();
                                state = 79;
                                break;
                            case 69:
                                next();
                                state = 79;
                                break;
                            case 116:
                                next();
                                state = 62;
                                break;
                            case 115:
                                next();
                                state = 79;
                                break;
                            case 68:
                                next();
                                state = 79;
                                break;
                            case 89:
                                next();
                                state = 79;
                                break;
                            case 66:
                                next();
                                state = 79;
                                break;
                            case 113:
                                next();
                                state = 79;
                                break;
                            case 114:
                                next();
                                state = 79;
                                break;
                            case 67:
                                next();
                                state = 79;
                                break;
                            case 90:
                                next();
                                state = 79;
                                break;
                            case 99:
                                next();
                                state = 79;
                                break;
                            case 52:
                                next();
                                state = 79;
                                break;
                            case 100:
                                next();
                                state = 79;
                                break;
                            case 53:
                                next();
                                state = 79;
                                break;
                            case 101:
                                next();
                                state = 79;
                                break;
                            case 54:
                                next();
                                state = 79;
                                break;
                            case 102:
                                next();
                                state = 79;
                                break;
                            case 55:
                                next();
                                state = 79;
                                break;
                            case 82:
                                next();
                                state = 79;
                                break;
                            case 105:
                                next();
                                state = 79;
                                break;
                            case 111:
                                next();
                                state = 79;
                                break;
                            case 110:
                                next();
                                state = 79;
                                break;
                            case 109:
                                next();
                                state = 79;
                                break;
                            case 85:
                                next();
                                state = 79;
                                break;
                            case 108:
                                next();
                                state = 79;
                                break;
                            case 84:
                                next();
                                state = 79;
                                break;
                            case 107:
                                next();
                                state = 79;
                                break;
                            case 83:
                                next();
                                state = 79;
                                break;
                            case 106:
                                next();
                                state = 79;
                                break;
                            case 104:
                                next();
                                state = 79;
                                break;
                            case 57:
                                next();
                                state = 79;
                                break;
                            case 103:
                                next();
                                state = 79;
                                break;
                            default:
                                m_semantic.id(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 57:
                        switch (c) {
                            case 81:
                                next();
                                state = 79;
                                break;
                            case 49:
                                next();
                                state = 79;
                                break;
                            case 71:
                                next();
                                state = 79;
                                break;
                            case 118:
                                next();
                                state = 79;
                                break;
                            case 72:
                                next();
                                state = 79;
                                break;
                            case 119:
                                next();
                                state = 79;
                                break;
                            case 74:
                                next();
                                state = 79;
                                break;
                            case 121:
                                next();
                                state = 79;
                                break;
                            case 75:
                                next();
                                state = 79;
                                break;
                            case 122:
                                next();
                                state = 79;
                                break;
                            case 73:
                                next();
                                state = 79;
                                break;
                            case 120:
                                next();
                                state = 79;
                                break;
                            case 95:
                                next();
                                state = 79;
                                break;
                            case 48:
                                next();
                                state = 79;
                                break;
                            case 70:
                                next();
                                state = 79;
                                break;
                            case 117:
                                next();
                                state = 79;
                                break;
                            case 55:
                                next();
                                state = 79;
                                break;
                            case 98:
                                next();
                                state = 79;
                                break;
                            case 51:
                                next();
                                state = 79;
                                break;
                            case 50:
                                next();
                                state = 79;
                                break;
                            case 97:
                                next();
                                state = 79;
                                break;
                            case 80:
                                next();
                                state = 79;
                                break;
                            case 79:
                                next();
                                state = 79;
                                break;
                            case 78:
                                next();
                                state = 79;
                                break;
                            case 77:
                                next();
                                state = 79;
                                break;
                            case 76:
                                next();
                                state = 79;
                                break;
                            case 65:
                                next();
                                state = 79;
                                break;
                            case 112:
                                next();
                                state = 79;
                                break;
                            case 88:
                                next();
                                state = 79;
                                break;
                            case 89:
                                next();
                                state = 79;
                                break;
                            case 66:
                                next();
                                state = 79;
                                break;
                            case 113:
                                next();
                                state = 79;
                                break;
                            case 87:
                                next();
                                state = 79;
                                break;
                            case 116:
                                next();
                                state = 79;
                                break;
                            case 69:
                                next();
                                state = 79;
                                break;
                            case 115:
                                next();
                                state = 79;
                                break;
                            case 68:
                                next();
                                state = 79;
                                break;
                            case 114:
                                next();
                                state = 79;
                                break;
                            case 67:
                                next();
                                state = 79;
                                break;
                            case 90:
                                next();
                                state = 79;
                                break;
                            case 99:
                                next();
                                state = 79;
                                break;
                            case 52:
                                next();
                                state = 79;
                                break;
                            case 100:
                                next();
                                state = 79;
                                break;
                            case 53:
                                next();
                                state = 79;
                                break;
                            case 101:
                                next();
                                state = 79;
                                break;
                            case 54:
                                next();
                                state = 79;
                                break;
                            case 110:
                                next();
                                state = 53;
                                break;
                            case 111:
                                next();
                                state = 79;
                                break;
                            case 86:
                                next();
                                state = 79;
                                break;
                            case 109:
                                next();
                                state = 79;
                                break;
                            case 85:
                                next();
                                state = 79;
                                break;
                            case 108:
                                next();
                                state = 79;
                                break;
                            case 84:
                                next();
                                state = 79;
                                break;
                            case 107:
                                next();
                                state = 79;
                                break;
                            case 83:
                                next();
                                state = 79;
                                break;
                            case 106:
                                next();
                                state = 79;
                                break;
                            case 82:
                                next();
                                state = 79;
                                break;
                            case 105:
                                next();
                                state = 79;
                                break;
                            case 104:
                                next();
                                state = 79;
                                break;
                            case 57:
                                next();
                                state = 79;
                                break;
                            case 103:
                                next();
                                state = 79;
                                break;
                            case 56:
                                next();
                                state = 79;
                                break;
                            case 102:
                                next();
                                state = 79;
                                break;
                            default:
                                m_semantic.id(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 58:
                        switch (c) {
                            case 103:
                                next();
                                state = 79;
                                break;
                            case 57:
                                next();
                                state = 79;
                                break;
                            case 104:
                                next();
                                state = 79;
                                break;
                            case 105:
                                next();
                                state = 79;
                                break;
                            case 82:
                                next();
                                state = 79;
                                break;
                            case 106:
                                next();
                                state = 79;
                                break;
                            case 83:
                                next();
                                state = 79;
                                break;
                            case 107:
                                next();
                                state = 79;
                                break;
                            case 84:
                                next();
                                state = 79;
                                break;
                            case 108:
                                next();
                                state = 79;
                                break;
                            case 85:
                                next();
                                state = 79;
                                break;
                            case 109:
                                next();
                                state = 79;
                                break;
                            case 111:
                                next();
                                state = 56;
                                break;
                            case 110:
                                next();
                                state = 79;
                                break;
                            case 55:
                                next();
                                state = 79;
                                break;
                            case 102:
                                next();
                                state = 79;
                                break;
                            case 54:
                                next();
                                state = 79;
                                break;
                            case 81:
                                next();
                                state = 79;
                                break;
                            case 56:
                                next();
                                state = 79;
                                break;
                            case 86:
                                next();
                                state = 79;
                                break;
                            case 70:
                                next();
                                state = 79;
                                break;
                            case 117:
                                next();
                                state = 79;
                                break;
                            case 48:
                                next();
                                state = 79;
                                break;
                            case 95:
                                next();
                                state = 79;
                                break;
                            case 71:
                                next();
                                state = 79;
                                break;
                            case 118:
                                next();
                                state = 79;
                                break;
                            case 97:
                                next();
                                state = 79;
                                break;
                            case 50:
                                next();
                                state = 79;
                                break;
                            case 51:
                                next();
                                state = 79;
                                break;
                            case 98:
                                next();
                                state = 79;
                                break;
                            case 120:
                                next();
                                state = 79;
                                break;
                            case 73:
                                next();
                                state = 79;
                                break;
                            case 74:
                                next();
                                state = 79;
                                break;
                            case 121:
                                next();
                                state = 79;
                                break;
                            case 49:
                                next();
                                state = 79;
                                break;
                            case 72:
                                next();
                                state = 79;
                                break;
                            case 119:
                                next();
                                state = 79;
                                break;
                            case 75:
                                next();
                                state = 79;
                                break;
                            case 122:
                                next();
                                state = 79;
                                break;
                            case 80:
                                next();
                                state = 79;
                                break;
                            case 79:
                                next();
                                state = 79;
                                break;
                            case 78:
                                next();
                                state = 79;
                                break;
                            case 77:
                                next();
                                state = 79;
                                break;
                            case 76:
                                next();
                                state = 79;
                                break;
                            case 65:
                                next();
                                state = 79;
                                break;
                            case 112:
                                next();
                                state = 79;
                                break;
                            case 88:
                                next();
                                state = 79;
                                break;
                            case 89:
                                next();
                                state = 79;
                                break;
                            case 66:
                                next();
                                state = 79;
                                break;
                            case 113:
                                next();
                                state = 79;
                                break;
                            case 87:
                                next();
                                state = 79;
                                break;
                            case 116:
                                next();
                                state = 79;
                                break;
                            case 69:
                                next();
                                state = 79;
                                break;
                            case 115:
                                next();
                                state = 79;
                                break;
                            case 68:
                                next();
                                state = 79;
                                break;
                            case 114:
                                next();
                                state = 79;
                                break;
                            case 67:
                                next();
                                state = 79;
                                break;
                            case 90:
                                next();
                                state = 79;
                                break;
                            case 99:
                                next();
                                state = 79;
                                break;
                            case 52:
                                next();
                                state = 79;
                                break;
                            case 100:
                                next();
                                state = 79;
                                break;
                            case 53:
                                next();
                                state = 79;
                                break;
                            case 101:
                                next();
                                state = 79;
                                break;
                            default:
                                m_semantic.id(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 59:
                        switch (c) {
                            case 81:
                                next();
                                state = 79;
                                break;
                            case 49:
                                next();
                                state = 79;
                                break;
                            case 71:
                                next();
                                state = 79;
                                break;
                            case 118:
                                next();
                                state = 79;
                                break;
                            case 72:
                                next();
                                state = 79;
                                break;
                            case 119:
                                next();
                                state = 79;
                                break;
                            case 74:
                                next();
                                state = 79;
                                break;
                            case 121:
                                next();
                                state = 79;
                                break;
                            case 75:
                                next();
                                state = 79;
                                break;
                            case 122:
                                next();
                                state = 79;
                                break;
                            case 73:
                                next();
                                state = 79;
                                break;
                            case 120:
                                next();
                                state = 79;
                                break;
                            case 95:
                                next();
                                state = 79;
                                break;
                            case 48:
                                next();
                                state = 79;
                                break;
                            case 70:
                                next();
                                state = 79;
                                break;
                            case 117:
                                next();
                                state = 79;
                                break;
                            case 55:
                                next();
                                state = 79;
                                break;
                            case 98:
                                next();
                                state = 79;
                                break;
                            case 51:
                                next();
                                state = 79;
                                break;
                            case 50:
                                next();
                                state = 79;
                                break;
                            case 97:
                                next();
                                state = 79;
                                break;
                            case 80:
                                next();
                                state = 79;
                                break;
                            case 79:
                                next();
                                state = 79;
                                break;
                            case 78:
                                next();
                                state = 79;
                                break;
                            case 77:
                                next();
                                state = 79;
                                break;
                            case 76:
                                next();
                                state = 79;
                                break;
                            case 65:
                                next();
                                state = 79;
                                break;
                            case 112:
                                next();
                                state = 79;
                                break;
                            case 88:
                                next();
                                state = 79;
                                break;
                            case 89:
                                next();
                                state = 79;
                                break;
                            case 66:
                                next();
                                state = 79;
                                break;
                            case 113:
                                next();
                                state = 79;
                                break;
                            case 87:
                                next();
                                state = 79;
                                break;
                            case 116:
                                next();
                                state = 79;
                                break;
                            case 69:
                                next();
                                state = 79;
                                break;
                            case 115:
                                next();
                                state = 79;
                                break;
                            case 68:
                                next();
                                state = 79;
                                break;
                            case 114:
                                next();
                                state = 79;
                                break;
                            case 67:
                                next();
                                state = 79;
                                break;
                            case 90:
                                next();
                                state = 79;
                                break;
                            case 99:
                                next();
                                state = 79;
                                break;
                            case 52:
                                next();
                                state = 79;
                                break;
                            case 100:
                                next();
                                state = 79;
                                break;
                            case 53:
                                next();
                                state = 79;
                                break;
                            case 101:
                                next();
                                state = 79;
                                break;
                            case 54:
                                next();
                                state = 79;
                                break;
                            case 111:
                                next();
                                state = 79;
                                break;
                            case 110:
                                next();
                                state = 79;
                                break;
                            case 86:
                                next();
                                state = 79;
                                break;
                            case 109:
                                next();
                                state = 79;
                                break;
                            case 85:
                                next();
                                state = 79;
                                break;
                            case 108:
                                next();
                                state = 79;
                                break;
                            case 84:
                                next();
                                state = 79;
                                break;
                            case 107:
                                next();
                                state = 79;
                                break;
                            case 83:
                                next();
                                state = 79;
                                break;
                            case 106:
                                next();
                                state = 79;
                                break;
                            case 82:
                                next();
                                state = 79;
                                break;
                            case 105:
                                next();
                                state = 79;
                                break;
                            case 104:
                                next();
                                state = 79;
                                break;
                            case 57:
                                next();
                                state = 79;
                                break;
                            case 103:
                                next();
                                state = 79;
                                break;
                            case 56:
                                next();
                                state = 79;
                                break;
                            case 102:
                                next();
                                state = 79;
                                break;
                            default:
                                m_semantic.orr(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 60:
                        switch (c) {
                            case 103:
                                next();
                                state = 79;
                                break;
                            case 57:
                                next();
                                state = 79;
                                break;
                            case 104:
                                next();
                                state = 79;
                                break;
                            case 105:
                                next();
                                state = 89;
                                break;
                            case 82:
                                next();
                                state = 79;
                                break;
                            case 106:
                                next();
                                state = 79;
                                break;
                            case 83:
                                next();
                                state = 79;
                                break;
                            case 107:
                                next();
                                state = 79;
                                break;
                            case 84:
                                next();
                                state = 79;
                                break;
                            case 108:
                                next();
                                state = 79;
                                break;
                            case 85:
                                next();
                                state = 79;
                                break;
                            case 109:
                                next();
                                state = 79;
                                break;
                            case 111:
                                next();
                                state = 65;
                                break;
                            case 110:
                                next();
                                state = 79;
                                break;
                            case 55:
                                next();
                                state = 79;
                                break;
                            case 102:
                                next();
                                state = 79;
                                break;
                            case 54:
                                next();
                                state = 79;
                                break;
                            case 81:
                                next();
                                state = 79;
                                break;
                            case 56:
                                next();
                                state = 79;
                                break;
                            case 86:
                                next();
                                state = 79;
                                break;
                            case 70:
                                next();
                                state = 79;
                                break;
                            case 117:
                                next();
                                state = 79;
                                break;
                            case 48:
                                next();
                                state = 79;
                                break;
                            case 95:
                                next();
                                state = 79;
                                break;
                            case 71:
                                next();
                                state = 79;
                                break;
                            case 118:
                                next();
                                state = 79;
                                break;
                            case 97:
                                next();
                                state = 79;
                                break;
                            case 50:
                                next();
                                state = 79;
                                break;
                            case 51:
                                next();
                                state = 79;
                                break;
                            case 98:
                                next();
                                state = 79;
                                break;
                            case 120:
                                next();
                                state = 79;
                                break;
                            case 73:
                                next();
                                state = 79;
                                break;
                            case 74:
                                next();
                                state = 79;
                                break;
                            case 121:
                                next();
                                state = 79;
                                break;
                            case 49:
                                next();
                                state = 79;
                                break;
                            case 72:
                                next();
                                state = 79;
                                break;
                            case 119:
                                next();
                                state = 79;
                                break;
                            case 75:
                                next();
                                state = 79;
                                break;
                            case 122:
                                next();
                                state = 79;
                                break;
                            case 80:
                                next();
                                state = 79;
                                break;
                            case 79:
                                next();
                                state = 79;
                                break;
                            case 78:
                                next();
                                state = 79;
                                break;
                            case 77:
                                next();
                                state = 79;
                                break;
                            case 76:
                                next();
                                state = 79;
                                break;
                            case 65:
                                next();
                                state = 79;
                                break;
                            case 112:
                                next();
                                state = 79;
                                break;
                            case 88:
                                next();
                                state = 79;
                                break;
                            case 89:
                                next();
                                state = 79;
                                break;
                            case 66:
                                next();
                                state = 79;
                                break;
                            case 113:
                                next();
                                state = 79;
                                break;
                            case 87:
                                next();
                                state = 79;
                                break;
                            case 116:
                                next();
                                state = 79;
                                break;
                            case 69:
                                next();
                                state = 79;
                                break;
                            case 115:
                                next();
                                state = 79;
                                break;
                            case 68:
                                next();
                                state = 79;
                                break;
                            case 114:
                                next();
                                state = 79;
                                break;
                            case 67:
                                next();
                                state = 79;
                                break;
                            case 90:
                                next();
                                state = 79;
                                break;
                            case 99:
                                next();
                                state = 79;
                                break;
                            case 52:
                                next();
                                state = 79;
                                break;
                            case 100:
                                next();
                                state = 79;
                                break;
                            case 53:
                                next();
                                state = 79;
                                break;
                            case 101:
                                next();
                                state = 79;
                                break;
                            default:
                                m_semantic.id(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 61:
                        switch (c) {
                            case 81:
                                next();
                                state = 79;
                                break;
                            case 49:
                                next();
                                state = 79;
                                break;
                            case 71:
                                next();
                                state = 79;
                                break;
                            case 118:
                                next();
                                state = 79;
                                break;
                            case 72:
                                next();
                                state = 79;
                                break;
                            case 119:
                                next();
                                state = 79;
                                break;
                            case 74:
                                next();
                                state = 79;
                                break;
                            case 121:
                                next();
                                state = 79;
                                break;
                            case 75:
                                next();
                                state = 79;
                                break;
                            case 122:
                                next();
                                state = 79;
                                break;
                            case 73:
                                next();
                                state = 79;
                                break;
                            case 120:
                                next();
                                state = 79;
                                break;
                            case 95:
                                next();
                                state = 79;
                                break;
                            case 48:
                                next();
                                state = 79;
                                break;
                            case 70:
                                next();
                                state = 79;
                                break;
                            case 117:
                                next();
                                state = 79;
                                break;
                            case 55:
                                next();
                                state = 79;
                                break;
                            case 98:
                                next();
                                state = 79;
                                break;
                            case 51:
                                next();
                                state = 79;
                                break;
                            case 50:
                                next();
                                state = 79;
                                break;
                            case 97:
                                next();
                                state = 79;
                                break;
                            case 80:
                                next();
                                state = 79;
                                break;
                            case 79:
                                next();
                                state = 79;
                                break;
                            case 78:
                                next();
                                state = 79;
                                break;
                            case 77:
                                next();
                                state = 79;
                                break;
                            case 76:
                                next();
                                state = 79;
                                break;
                            case 65:
                                next();
                                state = 79;
                                break;
                            case 112:
                                next();
                                state = 79;
                                break;
                            case 88:
                                next();
                                state = 79;
                                break;
                            case 89:
                                next();
                                state = 79;
                                break;
                            case 66:
                                next();
                                state = 79;
                                break;
                            case 113:
                                next();
                                state = 79;
                                break;
                            case 87:
                                next();
                                state = 79;
                                break;
                            case 116:
                                next();
                                state = 79;
                                break;
                            case 69:
                                next();
                                state = 79;
                                break;
                            case 115:
                                next();
                                state = 79;
                                break;
                            case 68:
                                next();
                                state = 79;
                                break;
                            case 114:
                                next();
                                state = 79;
                                break;
                            case 67:
                                next();
                                state = 79;
                                break;
                            case 90:
                                next();
                                state = 79;
                                break;
                            case 99:
                                next();
                                state = 79;
                                break;
                            case 52:
                                next();
                                state = 79;
                                break;
                            case 100:
                                next();
                                state = 79;
                                break;
                            case 53:
                                next();
                                state = 79;
                                break;
                            case 101:
                                next();
                                state = 79;
                                break;
                            case 54:
                                next();
                                state = 79;
                                break;
                            case 111:
                                next();
                                state = 79;
                                break;
                            case 110:
                                next();
                                state = 79;
                                break;
                            case 86:
                                next();
                                state = 79;
                                break;
                            case 109:
                                next();
                                state = 79;
                                break;
                            case 85:
                                next();
                                state = 79;
                                break;
                            case 108:
                                next();
                                state = 44;
                                break;
                            case 84:
                                next();
                                state = 79;
                                break;
                            case 107:
                                next();
                                state = 79;
                                break;
                            case 83:
                                next();
                                state = 79;
                                break;
                            case 106:
                                next();
                                state = 79;
                                break;
                            case 82:
                                next();
                                state = 79;
                                break;
                            case 105:
                                next();
                                state = 79;
                                break;
                            case 104:
                                next();
                                state = 79;
                                break;
                            case 57:
                                next();
                                state = 79;
                                break;
                            case 103:
                                next();
                                state = 79;
                                break;
                            case 56:
                                next();
                                state = 79;
                                break;
                            case 102:
                                next();
                                state = 79;
                                break;
                            default:
                                m_semantic.id(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 62:
                        switch (c) {
                            case 81:
                                next();
                                state = 79;
                                break;
                            case 49:
                                next();
                                state = 79;
                                break;
                            case 71:
                                next();
                                state = 79;
                                break;
                            case 118:
                                next();
                                state = 79;
                                break;
                            case 72:
                                next();
                                state = 79;
                                break;
                            case 119:
                                next();
                                state = 79;
                                break;
                            case 74:
                                next();
                                state = 79;
                                break;
                            case 121:
                                next();
                                state = 79;
                                break;
                            case 75:
                                next();
                                state = 79;
                                break;
                            case 122:
                                next();
                                state = 79;
                                break;
                            case 73:
                                next();
                                state = 79;
                                break;
                            case 120:
                                next();
                                state = 79;
                                break;
                            case 95:
                                next();
                                state = 79;
                                break;
                            case 48:
                                next();
                                state = 79;
                                break;
                            case 70:
                                next();
                                state = 79;
                                break;
                            case 117:
                                next();
                                state = 79;
                                break;
                            case 55:
                                next();
                                state = 79;
                                break;
                            case 98:
                                next();
                                state = 79;
                                break;
                            case 51:
                                next();
                                state = 79;
                                break;
                            case 50:
                                next();
                                state = 79;
                                break;
                            case 97:
                                next();
                                state = 79;
                                break;
                            case 80:
                                next();
                                state = 79;
                                break;
                            case 79:
                                next();
                                state = 79;
                                break;
                            case 78:
                                next();
                                state = 79;
                                break;
                            case 77:
                                next();
                                state = 79;
                                break;
                            case 76:
                                next();
                                state = 79;
                                break;
                            case 65:
                                next();
                                state = 79;
                                break;
                            case 112:
                                next();
                                state = 79;
                                break;
                            case 88:
                                next();
                                state = 79;
                                break;
                            case 89:
                                next();
                                state = 79;
                                break;
                            case 66:
                                next();
                                state = 79;
                                break;
                            case 113:
                                next();
                                state = 79;
                                break;
                            case 87:
                                next();
                                state = 79;
                                break;
                            case 116:
                                next();
                                state = 79;
                                break;
                            case 69:
                                next();
                                state = 79;
                                break;
                            case 115:
                                next();
                                state = 79;
                                break;
                            case 68:
                                next();
                                state = 79;
                                break;
                            case 114:
                                next();
                                state = 79;
                                break;
                            case 67:
                                next();
                                state = 79;
                                break;
                            case 90:
                                next();
                                state = 79;
                                break;
                            case 99:
                                next();
                                state = 79;
                                break;
                            case 52:
                                next();
                                state = 79;
                                break;
                            case 100:
                                next();
                                state = 79;
                                break;
                            case 53:
                                next();
                                state = 79;
                                break;
                            case 101:
                                next();
                                state = 79;
                                break;
                            case 54:
                                next();
                                state = 79;
                                break;
                            case 111:
                                next();
                                state = 79;
                                break;
                            case 110:
                                next();
                                state = 79;
                                break;
                            case 86:
                                next();
                                state = 79;
                                break;
                            case 109:
                                next();
                                state = 79;
                                break;
                            case 85:
                                next();
                                state = 79;
                                break;
                            case 108:
                                next();
                                state = 79;
                                break;
                            case 84:
                                next();
                                state = 79;
                                break;
                            case 107:
                                next();
                                state = 79;
                                break;
                            case 83:
                                next();
                                state = 79;
                                break;
                            case 106:
                                next();
                                state = 79;
                                break;
                            case 82:
                                next();
                                state = 79;
                                break;
                            case 105:
                                next();
                                state = 79;
                                break;
                            case 104:
                                next();
                                state = 79;
                                break;
                            case 57:
                                next();
                                state = 79;
                                break;
                            case 103:
                                next();
                                state = 79;
                                break;
                            case 56:
                                next();
                                state = 79;
                                break;
                            case 102:
                                next();
                                state = 79;
                                break;
                            default:
                                m_semantic.nott(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 63:
                        switch (c) {
                            case 9:
                                next();
                                state = 63;
                                break;
                            case 32:
                                next();
                                state = 63;
                                break;
                            case 10:
                                next();
                                state = 63;
                                break;
                            default:
                                return false;
                        }
                        break;
                    case 64:
                        switch (c) {
                            case 81:
                                next();
                                state = 79;
                                break;
                            case 49:
                                next();
                                state = 79;
                                break;
                            case 71:
                                next();
                                state = 79;
                                break;
                            case 118:
                                next();
                                state = 79;
                                break;
                            case 72:
                                next();
                                state = 79;
                                break;
                            case 119:
                                next();
                                state = 79;
                                break;
                            case 74:
                                next();
                                state = 79;
                                break;
                            case 121:
                                next();
                                state = 79;
                                break;
                            case 75:
                                next();
                                state = 79;
                                break;
                            case 122:
                                next();
                                state = 79;
                                break;
                            case 73:
                                next();
                                state = 79;
                                break;
                            case 120:
                                next();
                                state = 79;
                                break;
                            case 95:
                                next();
                                state = 79;
                                break;
                            case 48:
                                next();
                                state = 79;
                                break;
                            case 70:
                                next();
                                state = 79;
                                break;
                            case 117:
                                next();
                                state = 79;
                                break;
                            case 55:
                                next();
                                state = 79;
                                break;
                            case 98:
                                next();
                                state = 79;
                                break;
                            case 51:
                                next();
                                state = 79;
                                break;
                            case 50:
                                next();
                                state = 79;
                                break;
                            case 97:
                                next();
                                state = 79;
                                break;
                            case 80:
                                next();
                                state = 79;
                                break;
                            case 79:
                                next();
                                state = 79;
                                break;
                            case 78:
                                next();
                                state = 79;
                                break;
                            case 77:
                                next();
                                state = 79;
                                break;
                            case 76:
                                next();
                                state = 79;
                                break;
                            case 65:
                                next();
                                state = 79;
                                break;
                            case 112:
                                next();
                                state = 79;
                                break;
                            case 88:
                                next();
                                state = 79;
                                break;
                            case 89:
                                next();
                                state = 79;
                                break;
                            case 66:
                                next();
                                state = 79;
                                break;
                            case 113:
                                next();
                                state = 79;
                                break;
                            case 87:
                                next();
                                state = 79;
                                break;
                            case 116:
                                next();
                                state = 79;
                                break;
                            case 69:
                                next();
                                state = 79;
                                break;
                            case 115:
                                next();
                                state = 79;
                                break;
                            case 68:
                                next();
                                state = 79;
                                break;
                            case 114:
                                next();
                                state = 79;
                                break;
                            case 67:
                                next();
                                state = 79;
                                break;
                            case 90:
                                next();
                                state = 79;
                                break;
                            case 99:
                                next();
                                state = 79;
                                break;
                            case 52:
                                next();
                                state = 79;
                                break;
                            case 100:
                                next();
                                state = 79;
                                break;
                            case 53:
                                next();
                                state = 79;
                                break;
                            case 101:
                                next();
                                state = 79;
                                break;
                            case 54:
                                next();
                                state = 79;
                                break;
                            case 111:
                                next();
                                state = 79;
                                break;
                            case 110:
                                next();
                                state = 6;
                                break;
                            case 86:
                                next();
                                state = 79;
                                break;
                            case 109:
                                next();
                                state = 79;
                                break;
                            case 85:
                                next();
                                state = 79;
                                break;
                            case 108:
                                next();
                                state = 79;
                                break;
                            case 84:
                                next();
                                state = 79;
                                break;
                            case 107:
                                next();
                                state = 79;
                                break;
                            case 83:
                                next();
                                state = 79;
                                break;
                            case 106:
                                next();
                                state = 79;
                                break;
                            case 82:
                                next();
                                state = 79;
                                break;
                            case 105:
                                next();
                                state = 79;
                                break;
                            case 104:
                                next();
                                state = 79;
                                break;
                            case 57:
                                next();
                                state = 79;
                                break;
                            case 103:
                                next();
                                state = 79;
                                break;
                            case 56:
                                next();
                                state = 79;
                                break;
                            case 102:
                                next();
                                state = 79;
                                break;
                            default:
                                m_semantic.id(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 65:
                        switch (c) {
                            case 81:
                                next();
                                state = 79;
                                break;
                            case 49:
                                next();
                                state = 79;
                                break;
                            case 71:
                                next();
                                state = 79;
                                break;
                            case 118:
                                next();
                                state = 79;
                                break;
                            case 72:
                                next();
                                state = 79;
                                break;
                            case 119:
                                next();
                                state = 79;
                                break;
                            case 74:
                                next();
                                state = 79;
                                break;
                            case 121:
                                next();
                                state = 79;
                                break;
                            case 75:
                                next();
                                state = 79;
                                break;
                            case 122:
                                next();
                                state = 79;
                                break;
                            case 73:
                                next();
                                state = 79;
                                break;
                            case 120:
                                next();
                                state = 79;
                                break;
                            case 95:
                                next();
                                state = 79;
                                break;
                            case 48:
                                next();
                                state = 79;
                                break;
                            case 70:
                                next();
                                state = 79;
                                break;
                            case 117:
                                next();
                                state = 79;
                                break;
                            case 55:
                                next();
                                state = 79;
                                break;
                            case 98:
                                next();
                                state = 79;
                                break;
                            case 51:
                                next();
                                state = 79;
                                break;
                            case 50:
                                next();
                                state = 79;
                                break;
                            case 97:
                                next();
                                state = 79;
                                break;
                            case 80:
                                next();
                                state = 79;
                                break;
                            case 79:
                                next();
                                state = 79;
                                break;
                            case 78:
                                next();
                                state = 79;
                                break;
                            case 77:
                                next();
                                state = 79;
                                break;
                            case 76:
                                next();
                                state = 79;
                                break;
                            case 65:
                                next();
                                state = 79;
                                break;
                            case 112:
                                next();
                                state = 79;
                                break;
                            case 88:
                                next();
                                state = 79;
                                break;
                            case 89:
                                next();
                                state = 79;
                                break;
                            case 66:
                                next();
                                state = 79;
                                break;
                            case 113:
                                next();
                                state = 79;
                                break;
                            case 87:
                                next();
                                state = 79;
                                break;
                            case 116:
                                next();
                                state = 79;
                                break;
                            case 69:
                                next();
                                state = 79;
                                break;
                            case 115:
                                next();
                                state = 79;
                                break;
                            case 68:
                                next();
                                state = 79;
                                break;
                            case 114:
                                next();
                                state = 79;
                                break;
                            case 67:
                                next();
                                state = 79;
                                break;
                            case 90:
                                next();
                                state = 79;
                                break;
                            case 99:
                                next();
                                state = 79;
                                break;
                            case 52:
                                next();
                                state = 79;
                                break;
                            case 100:
                                next();
                                state = 79;
                                break;
                            case 53:
                                next();
                                state = 79;
                                break;
                            case 101:
                                next();
                                state = 79;
                                break;
                            case 54:
                                next();
                                state = 79;
                                break;
                            case 111:
                                next();
                                state = 79;
                                break;
                            case 110:
                                next();
                                state = 79;
                                break;
                            case 86:
                                next();
                                state = 79;
                                break;
                            case 109:
                                next();
                                state = 79;
                                break;
                            case 85:
                                next();
                                state = 79;
                                break;
                            case 108:
                                next();
                                state = 79;
                                break;
                            case 84:
                                next();
                                state = 79;
                                break;
                            case 107:
                                next();
                                state = 79;
                                break;
                            case 83:
                                next();
                                state = 79;
                                break;
                            case 106:
                                next();
                                state = 79;
                                break;
                            case 82:
                                next();
                                state = 79;
                                break;
                            case 105:
                                next();
                                state = 79;
                                break;
                            case 104:
                                next();
                                state = 79;
                                break;
                            case 57:
                                next();
                                state = 79;
                                break;
                            case 103:
                                next();
                                state = 79;
                                break;
                            case 56:
                                next();
                                state = 79;
                                break;
                            case 102:
                                next();
                                state = 79;
                                break;
                            default:
                                m_semantic.doo(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 66:
                        switch (c) {
                            case 103:
                                next();
                                state = 79;
                                break;
                            case 57:
                                next();
                                state = 79;
                                break;
                            case 104:
                                next();
                                state = 79;
                                break;
                            case 105:
                                next();
                                state = 79;
                                break;
                            case 82:
                                next();
                                state = 79;
                                break;
                            case 106:
                                next();
                                state = 79;
                                break;
                            case 83:
                                next();
                                state = 79;
                                break;
                            case 107:
                                next();
                                state = 79;
                                break;
                            case 84:
                                next();
                                state = 79;
                                break;
                            case 108:
                                next();
                                state = 79;
                                break;
                            case 85:
                                next();
                                state = 79;
                                break;
                            case 109:
                                next();
                                state = 79;
                                break;
                            case 111:
                                next();
                                state = 79;
                                break;
                            case 110:
                                next();
                                state = 79;
                                break;
                            case 55:
                                next();
                                state = 79;
                                break;
                            case 102:
                                next();
                                state = 79;
                                break;
                            case 54:
                                next();
                                state = 79;
                                break;
                            case 81:
                                next();
                                state = 79;
                                break;
                            case 56:
                                next();
                                state = 79;
                                break;
                            case 86:
                                next();
                                state = 79;
                                break;
                            case 70:
                                next();
                                state = 79;
                                break;
                            case 117:
                                next();
                                state = 79;
                                break;
                            case 48:
                                next();
                                state = 79;
                                break;
                            case 95:
                                next();
                                state = 79;
                                break;
                            case 71:
                                next();
                                state = 79;
                                break;
                            case 118:
                                next();
                                state = 79;
                                break;
                            case 97:
                                next();
                                state = 79;
                                break;
                            case 50:
                                next();
                                state = 79;
                                break;
                            case 51:
                                next();
                                state = 79;
                                break;
                            case 98:
                                next();
                                state = 79;
                                break;
                            case 120:
                                next();
                                state = 79;
                                break;
                            case 73:
                                next();
                                state = 79;
                                break;
                            case 74:
                                next();
                                state = 79;
                                break;
                            case 121:
                                next();
                                state = 79;
                                break;
                            case 49:
                                next();
                                state = 79;
                                break;
                            case 72:
                                next();
                                state = 79;
                                break;
                            case 119:
                                next();
                                state = 79;
                                break;
                            case 75:
                                next();
                                state = 79;
                                break;
                            case 122:
                                next();
                                state = 79;
                                break;
                            case 80:
                                next();
                                state = 79;
                                break;
                            case 79:
                                next();
                                state = 79;
                                break;
                            case 78:
                                next();
                                state = 79;
                                break;
                            case 77:
                                next();
                                state = 79;
                                break;
                            case 76:
                                next();
                                state = 79;
                                break;
                            case 65:
                                next();
                                state = 79;
                                break;
                            case 112:
                                next();
                                state = 79;
                                break;
                            case 88:
                                next();
                                state = 79;
                                break;
                            case 89:
                                next();
                                state = 79;
                                break;
                            case 66:
                                next();
                                state = 79;
                                break;
                            case 113:
                                next();
                                state = 79;
                                break;
                            case 87:
                                next();
                                state = 79;
                                break;
                            case 116:
                                next();
                                state = 79;
                                break;
                            case 69:
                                next();
                                state = 79;
                                break;
                            case 115:
                                next();
                                state = 79;
                                break;
                            case 68:
                                next();
                                state = 79;
                                break;
                            case 114:
                                next();
                                state = 79;
                                break;
                            case 67:
                                next();
                                state = 79;
                                break;
                            case 90:
                                next();
                                state = 79;
                                break;
                            case 99:
                                next();
                                state = 79;
                                break;
                            case 52:
                                next();
                                state = 79;
                                break;
                            case 100:
                                next();
                                state = 79;
                                break;
                            case 53:
                                next();
                                state = 79;
                                break;
                            case 101:
                                next();
                                state = 21;
                                break;
                            default:
                                m_semantic.id(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 67:
                        m_semantic.lparen(m_lexeme.str());
                        return true;
                    case 68:
                        switch (c) {
                            case 81:
                                next();
                                state = 79;
                                break;
                            case 49:
                                next();
                                state = 79;
                                break;
                            case 71:
                                next();
                                state = 79;
                                break;
                            case 118:
                                next();
                                state = 79;
                                break;
                            case 72:
                                next();
                                state = 79;
                                break;
                            case 119:
                                next();
                                state = 79;
                                break;
                            case 74:
                                next();
                                state = 79;
                                break;
                            case 121:
                                next();
                                state = 79;
                                break;
                            case 75:
                                next();
                                state = 79;
                                break;
                            case 122:
                                next();
                                state = 79;
                                break;
                            case 73:
                                next();
                                state = 79;
                                break;
                            case 120:
                                next();
                                state = 79;
                                break;
                            case 95:
                                next();
                                state = 79;
                                break;
                            case 48:
                                next();
                                state = 79;
                                break;
                            case 70:
                                next();
                                state = 79;
                                break;
                            case 117:
                                next();
                                state = 79;
                                break;
                            case 55:
                                next();
                                state = 79;
                                break;
                            case 98:
                                next();
                                state = 79;
                                break;
                            case 51:
                                next();
                                state = 79;
                                break;
                            case 50:
                                next();
                                state = 79;
                                break;
                            case 97:
                                next();
                                state = 79;
                                break;
                            case 80:
                                next();
                                state = 79;
                                break;
                            case 79:
                                next();
                                state = 79;
                                break;
                            case 78:
                                next();
                                state = 79;
                                break;
                            case 77:
                                next();
                                state = 79;
                                break;
                            case 76:
                                next();
                                state = 79;
                                break;
                            case 65:
                                next();
                                state = 79;
                                break;
                            case 112:
                                next();
                                state = 79;
                                break;
                            case 88:
                                next();
                                state = 79;
                                break;
                            case 89:
                                next();
                                state = 79;
                                break;
                            case 66:
                                next();
                                state = 79;
                                break;
                            case 113:
                                next();
                                state = 79;
                                break;
                            case 87:
                                next();
                                state = 79;
                                break;
                            case 116:
                                next();
                                state = 79;
                                break;
                            case 69:
                                next();
                                state = 79;
                                break;
                            case 115:
                                next();
                                state = 79;
                                break;
                            case 68:
                                next();
                                state = 79;
                                break;
                            case 114:
                                next();
                                state = 79;
                                break;
                            case 67:
                                next();
                                state = 79;
                                break;
                            case 90:
                                next();
                                state = 79;
                                break;
                            case 99:
                                next();
                                state = 2;
                                break;
                            case 52:
                                next();
                                state = 79;
                                break;
                            case 100:
                                next();
                                state = 79;
                                break;
                            case 53:
                                next();
                                state = 79;
                                break;
                            case 101:
                                next();
                                state = 79;
                                break;
                            case 54:
                                next();
                                state = 79;
                                break;
                            case 111:
                                next();
                                state = 79;
                                break;
                            case 110:
                                next();
                                state = 79;
                                break;
                            case 86:
                                next();
                                state = 79;
                                break;
                            case 109:
                                next();
                                state = 79;
                                break;
                            case 85:
                                next();
                                state = 79;
                                break;
                            case 108:
                                next();
                                state = 79;
                                break;
                            case 84:
                                next();
                                state = 79;
                                break;
                            case 107:
                                next();
                                state = 79;
                                break;
                            case 83:
                                next();
                                state = 79;
                                break;
                            case 106:
                                next();
                                state = 79;
                                break;
                            case 82:
                                next();
                                state = 79;
                                break;
                            case 105:
                                next();
                                state = 79;
                                break;
                            case 104:
                                next();
                                state = 79;
                                break;
                            case 57:
                                next();
                                state = 79;
                                break;
                            case 103:
                                next();
                                state = 79;
                                break;
                            case 56:
                                next();
                                state = 79;
                                break;
                            case 102:
                                next();
                                state = 79;
                                break;
                            default:
                                m_semantic.id(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 69:
                        switch (c) {
                            case 103:
                                next();
                                state = 79;
                                break;
                            case 57:
                                next();
                                state = 79;
                                break;
                            case 104:
                                next();
                                state = 79;
                                break;
                            case 105:
                                next();
                                state = 79;
                                break;
                            case 82:
                                next();
                                state = 79;
                                break;
                            case 106:
                                next();
                                state = 79;
                                break;
                            case 83:
                                next();
                                state = 79;
                                break;
                            case 107:
                                next();
                                state = 79;
                                break;
                            case 84:
                                next();
                                state = 79;
                                break;
                            case 108:
                                next();
                                state = 79;
                                break;
                            case 85:
                                next();
                                state = 79;
                                break;
                            case 109:
                                next();
                                state = 79;
                                break;
                            case 111:
                                next();
                                state = 57;
                                break;
                            case 110:
                                next();
                                state = 79;
                                break;
                            case 55:
                                next();
                                state = 79;
                                break;
                            case 102:
                                next();
                                state = 79;
                                break;
                            case 54:
                                next();
                                state = 79;
                                break;
                            case 81:
                                next();
                                state = 79;
                                break;
                            case 56:
                                next();
                                state = 79;
                                break;
                            case 86:
                                next();
                                state = 79;
                                break;
                            case 70:
                                next();
                                state = 79;
                                break;
                            case 117:
                                next();
                                state = 79;
                                break;
                            case 48:
                                next();
                                state = 79;
                                break;
                            case 95:
                                next();
                                state = 79;
                                break;
                            case 71:
                                next();
                                state = 79;
                                break;
                            case 118:
                                next();
                                state = 79;
                                break;
                            case 97:
                                next();
                                state = 79;
                                break;
                            case 50:
                                next();
                                state = 79;
                                break;
                            case 51:
                                next();
                                state = 79;
                                break;
                            case 98:
                                next();
                                state = 79;
                                break;
                            case 120:
                                next();
                                state = 79;
                                break;
                            case 73:
                                next();
                                state = 79;
                                break;
                            case 74:
                                next();
                                state = 79;
                                break;
                            case 121:
                                next();
                                state = 79;
                                break;
                            case 49:
                                next();
                                state = 79;
                                break;
                            case 72:
                                next();
                                state = 79;
                                break;
                            case 119:
                                next();
                                state = 79;
                                break;
                            case 75:
                                next();
                                state = 79;
                                break;
                            case 122:
                                next();
                                state = 79;
                                break;
                            case 80:
                                next();
                                state = 79;
                                break;
                            case 79:
                                next();
                                state = 79;
                                break;
                            case 78:
                                next();
                                state = 79;
                                break;
                            case 77:
                                next();
                                state = 79;
                                break;
                            case 76:
                                next();
                                state = 79;
                                break;
                            case 65:
                                next();
                                state = 79;
                                break;
                            case 112:
                                next();
                                state = 79;
                                break;
                            case 88:
                                next();
                                state = 79;
                                break;
                            case 89:
                                next();
                                state = 79;
                                break;
                            case 66:
                                next();
                                state = 79;
                                break;
                            case 113:
                                next();
                                state = 79;
                                break;
                            case 87:
                                next();
                                state = 79;
                                break;
                            case 116:
                                next();
                                state = 79;
                                break;
                            case 69:
                                next();
                                state = 79;
                                break;
                            case 115:
                                next();
                                state = 79;
                                break;
                            case 68:
                                next();
                                state = 79;
                                break;
                            case 114:
                                next();
                                state = 79;
                                break;
                            case 67:
                                next();
                                state = 79;
                                break;
                            case 90:
                                next();
                                state = 79;
                                break;
                            case 99:
                                next();
                                state = 79;
                                break;
                            case 52:
                                next();
                                state = 79;
                                break;
                            case 100:
                                next();
                                state = 79;
                                break;
                            case 53:
                                next();
                                state = 79;
                                break;
                            case 101:
                                next();
                                state = 79;
                                break;
                            default:
                                m_semantic.id(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 70:
                        switch (c) {
                            case 81:
                                next();
                                state = 79;
                                break;
                            case 49:
                                next();
                                state = 79;
                                break;
                            case 71:
                                next();
                                state = 79;
                                break;
                            case 118:
                                next();
                                state = 79;
                                break;
                            case 72:
                                next();
                                state = 79;
                                break;
                            case 119:
                                next();
                                state = 79;
                                break;
                            case 74:
                                next();
                                state = 79;
                                break;
                            case 121:
                                next();
                                state = 79;
                                break;
                            case 75:
                                next();
                                state = 79;
                                break;
                            case 122:
                                next();
                                state = 79;
                                break;
                            case 73:
                                next();
                                state = 79;
                                break;
                            case 120:
                                next();
                                state = 79;
                                break;
                            case 95:
                                next();
                                state = 79;
                                break;
                            case 48:
                                next();
                                state = 79;
                                break;
                            case 70:
                                next();
                                state = 79;
                                break;
                            case 117:
                                next();
                                state = 79;
                                break;
                            case 55:
                                next();
                                state = 79;
                                break;
                            case 98:
                                next();
                                state = 79;
                                break;
                            case 51:
                                next();
                                state = 79;
                                break;
                            case 50:
                                next();
                                state = 79;
                                break;
                            case 97:
                                next();
                                state = 79;
                                break;
                            case 80:
                                next();
                                state = 79;
                                break;
                            case 79:
                                next();
                                state = 79;
                                break;
                            case 78:
                                next();
                                state = 79;
                                break;
                            case 77:
                                next();
                                state = 79;
                                break;
                            case 76:
                                next();
                                state = 79;
                                break;
                            case 65:
                                next();
                                state = 79;
                                break;
                            case 112:
                                next();
                                state = 79;
                                break;
                            case 88:
                                next();
                                state = 79;
                                break;
                            case 89:
                                next();
                                state = 79;
                                break;
                            case 66:
                                next();
                                state = 79;
                                break;
                            case 113:
                                next();
                                state = 79;
                                break;
                            case 87:
                                next();
                                state = 79;
                                break;
                            case 116:
                                next();
                                state = 79;
                                break;
                            case 69:
                                next();
                                state = 79;
                                break;
                            case 115:
                                next();
                                state = 79;
                                break;
                            case 68:
                                next();
                                state = 79;
                                break;
                            case 114:
                                next();
                                state = 79;
                                break;
                            case 67:
                                next();
                                state = 79;
                                break;
                            case 90:
                                next();
                                state = 79;
                                break;
                            case 99:
                                next();
                                state = 79;
                                break;
                            case 52:
                                next();
                                state = 79;
                                break;
                            case 100:
                                next();
                                state = 79;
                                break;
                            case 53:
                                next();
                                state = 79;
                                break;
                            case 101:
                                next();
                                state = 79;
                                break;
                            case 54:
                                next();
                                state = 79;
                                break;
                            case 111:
                                next();
                                state = 74;
                                break;
                            case 110:
                                next();
                                state = 79;
                                break;
                            case 86:
                                next();
                                state = 79;
                                break;
                            case 109:
                                next();
                                state = 79;
                                break;
                            case 85:
                                next();
                                state = 79;
                                break;
                            case 108:
                                next();
                                state = 79;
                                break;
                            case 84:
                                next();
                                state = 79;
                                break;
                            case 107:
                                next();
                                state = 79;
                                break;
                            case 83:
                                next();
                                state = 79;
                                break;
                            case 106:
                                next();
                                state = 79;
                                break;
                            case 82:
                                next();
                                state = 79;
                                break;
                            case 105:
                                next();
                                state = 79;
                                break;
                            case 104:
                                next();
                                state = 79;
                                break;
                            case 57:
                                next();
                                state = 79;
                                break;
                            case 103:
                                next();
                                state = 79;
                                break;
                            case 56:
                                next();
                                state = 79;
                                break;
                            case 102:
                                next();
                                state = 79;
                                break;
                            default:
                                m_semantic.id(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 71:
                        switch (c) {
                            case 61:
                                next();
                                state = 86;
                                break;
                            default:
                                m_semantic.colon(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 72:
                        switch (c) {
                            case 81:
                                next();
                                state = 79;
                                break;
                            case 49:
                                next();
                                state = 79;
                                break;
                            case 71:
                                next();
                                state = 79;
                                break;
                            case 118:
                                next();
                                state = 79;
                                break;
                            case 72:
                                next();
                                state = 79;
                                break;
                            case 119:
                                next();
                                state = 79;
                                break;
                            case 74:
                                next();
                                state = 79;
                                break;
                            case 121:
                                next();
                                state = 79;
                                break;
                            case 75:
                                next();
                                state = 79;
                                break;
                            case 122:
                                next();
                                state = 79;
                                break;
                            case 73:
                                next();
                                state = 79;
                                break;
                            case 120:
                                next();
                                state = 79;
                                break;
                            case 95:
                                next();
                                state = 79;
                                break;
                            case 48:
                                next();
                                state = 79;
                                break;
                            case 70:
                                next();
                                state = 79;
                                break;
                            case 117:
                                next();
                                state = 79;
                                break;
                            case 55:
                                next();
                                state = 79;
                                break;
                            case 98:
                                next();
                                state = 79;
                                break;
                            case 51:
                                next();
                                state = 79;
                                break;
                            case 50:
                                next();
                                state = 79;
                                break;
                            case 97:
                                next();
                                state = 79;
                                break;
                            case 80:
                                next();
                                state = 79;
                                break;
                            case 79:
                                next();
                                state = 79;
                                break;
                            case 78:
                                next();
                                state = 79;
                                break;
                            case 77:
                                next();
                                state = 79;
                                break;
                            case 76:
                                next();
                                state = 79;
                                break;
                            case 65:
                                next();
                                state = 79;
                                break;
                            case 112:
                                next();
                                state = 79;
                                break;
                            case 88:
                                next();
                                state = 79;
                                break;
                            case 89:
                                next();
                                state = 79;
                                break;
                            case 66:
                                next();
                                state = 79;
                                break;
                            case 113:
                                next();
                                state = 79;
                                break;
                            case 87:
                                next();
                                state = 79;
                                break;
                            case 116:
                                next();
                                state = 79;
                                break;
                            case 69:
                                next();
                                state = 79;
                                break;
                            case 115:
                                next();
                                state = 79;
                                break;
                            case 68:
                                next();
                                state = 79;
                                break;
                            case 114:
                                next();
                                state = 79;
                                break;
                            case 67:
                                next();
                                state = 79;
                                break;
                            case 90:
                                next();
                                state = 79;
                                break;
                            case 99:
                                next();
                                state = 79;
                                break;
                            case 52:
                                next();
                                state = 79;
                                break;
                            case 100:
                                next();
                                state = 79;
                                break;
                            case 53:
                                next();
                                state = 79;
                                break;
                            case 101:
                                next();
                                state = 79;
                                break;
                            case 54:
                                next();
                                state = 79;
                                break;
                            case 111:
                                next();
                                state = 79;
                                break;
                            case 110:
                                next();
                                state = 79;
                                break;
                            case 86:
                                next();
                                state = 79;
                                break;
                            case 109:
                                next();
                                state = 79;
                                break;
                            case 85:
                                next();
                                state = 79;
                                break;
                            case 108:
                                next();
                                state = 79;
                                break;
                            case 84:
                                next();
                                state = 79;
                                break;
                            case 107:
                                next();
                                state = 79;
                                break;
                            case 83:
                                next();
                                state = 79;
                                break;
                            case 106:
                                next();
                                state = 79;
                                break;
                            case 82:
                                next();
                                state = 79;
                                break;
                            case 105:
                                next();
                                state = 70;
                                break;
                            case 104:
                                next();
                                state = 79;
                                break;
                            case 57:
                                next();
                                state = 79;
                                break;
                            case 103:
                                next();
                                state = 79;
                                break;
                            case 56:
                                next();
                                state = 79;
                                break;
                            case 102:
                                next();
                                state = 79;
                                break;
                            default:
                                m_semantic.id(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 73:
                        m_semantic.semi(m_lexeme.str());
                        return true;
                    case 74:
                        switch (c) {
                            case 81:
                                next();
                                state = 79;
                                break;
                            case 49:
                                next();
                                state = 79;
                                break;
                            case 71:
                                next();
                                state = 79;
                                break;
                            case 118:
                                next();
                                state = 79;
                                break;
                            case 72:
                                next();
                                state = 79;
                                break;
                            case 119:
                                next();
                                state = 79;
                                break;
                            case 74:
                                next();
                                state = 79;
                                break;
                            case 121:
                                next();
                                state = 79;
                                break;
                            case 75:
                                next();
                                state = 79;
                                break;
                            case 122:
                                next();
                                state = 79;
                                break;
                            case 73:
                                next();
                                state = 79;
                                break;
                            case 120:
                                next();
                                state = 79;
                                break;
                            case 95:
                                next();
                                state = 79;
                                break;
                            case 48:
                                next();
                                state = 79;
                                break;
                            case 70:
                                next();
                                state = 79;
                                break;
                            case 117:
                                next();
                                state = 79;
                                break;
                            case 55:
                                next();
                                state = 79;
                                break;
                            case 98:
                                next();
                                state = 79;
                                break;
                            case 51:
                                next();
                                state = 79;
                                break;
                            case 50:
                                next();
                                state = 79;
                                break;
                            case 97:
                                next();
                                state = 79;
                                break;
                            case 80:
                                next();
                                state = 79;
                                break;
                            case 79:
                                next();
                                state = 79;
                                break;
                            case 78:
                                next();
                                state = 79;
                                break;
                            case 77:
                                next();
                                state = 79;
                                break;
                            case 76:
                                next();
                                state = 79;
                                break;
                            case 65:
                                next();
                                state = 79;
                                break;
                            case 112:
                                next();
                                state = 79;
                                break;
                            case 88:
                                next();
                                state = 79;
                                break;
                            case 89:
                                next();
                                state = 79;
                                break;
                            case 66:
                                next();
                                state = 79;
                                break;
                            case 113:
                                next();
                                state = 79;
                                break;
                            case 87:
                                next();
                                state = 79;
                                break;
                            case 116:
                                next();
                                state = 79;
                                break;
                            case 69:
                                next();
                                state = 79;
                                break;
                            case 115:
                                next();
                                state = 79;
                                break;
                            case 68:
                                next();
                                state = 79;
                                break;
                            case 114:
                                next();
                                state = 79;
                                break;
                            case 67:
                                next();
                                state = 79;
                                break;
                            case 90:
                                next();
                                state = 79;
                                break;
                            case 99:
                                next();
                                state = 79;
                                break;
                            case 52:
                                next();
                                state = 79;
                                break;
                            case 100:
                                next();
                                state = 79;
                                break;
                            case 53:
                                next();
                                state = 79;
                                break;
                            case 101:
                                next();
                                state = 79;
                                break;
                            case 54:
                                next();
                                state = 79;
                                break;
                            case 111:
                                next();
                                state = 79;
                                break;
                            case 110:
                                next();
                                state = 36;
                                break;
                            case 86:
                                next();
                                state = 79;
                                break;
                            case 109:
                                next();
                                state = 79;
                                break;
                            case 85:
                                next();
                                state = 79;
                                break;
                            case 108:
                                next();
                                state = 79;
                                break;
                            case 84:
                                next();
                                state = 79;
                                break;
                            case 107:
                                next();
                                state = 79;
                                break;
                            case 83:
                                next();
                                state = 79;
                                break;
                            case 106:
                                next();
                                state = 79;
                                break;
                            case 82:
                                next();
                                state = 79;
                                break;
                            case 105:
                                next();
                                state = 79;
                                break;
                            case 104:
                                next();
                                state = 79;
                                break;
                            case 57:
                                next();
                                state = 79;
                                break;
                            case 103:
                                next();
                                state = 79;
                                break;
                            case 56:
                                next();
                                state = 79;
                                break;
                            case 102:
                                next();
                                state = 79;
                                break;
                            default:
                                m_semantic.id(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 75:
                        switch (c) {
                            case 81:
                                next();
                                state = 79;
                                break;
                            case 49:
                                next();
                                state = 79;
                                break;
                            case 71:
                                next();
                                state = 79;
                                break;
                            case 118:
                                next();
                                state = 79;
                                break;
                            case 72:
                                next();
                                state = 79;
                                break;
                            case 119:
                                next();
                                state = 79;
                                break;
                            case 74:
                                next();
                                state = 79;
                                break;
                            case 121:
                                next();
                                state = 79;
                                break;
                            case 75:
                                next();
                                state = 79;
                                break;
                            case 122:
                                next();
                                state = 79;
                                break;
                            case 73:
                                next();
                                state = 79;
                                break;
                            case 120:
                                next();
                                state = 79;
                                break;
                            case 95:
                                next();
                                state = 79;
                                break;
                            case 48:
                                next();
                                state = 79;
                                break;
                            case 70:
                                next();
                                state = 79;
                                break;
                            case 117:
                                next();
                                state = 79;
                                break;
                            case 55:
                                next();
                                state = 79;
                                break;
                            case 98:
                                next();
                                state = 79;
                                break;
                            case 51:
                                next();
                                state = 79;
                                break;
                            case 50:
                                next();
                                state = 79;
                                break;
                            case 97:
                                next();
                                state = 79;
                                break;
                            case 80:
                                next();
                                state = 79;
                                break;
                            case 79:
                                next();
                                state = 79;
                                break;
                            case 78:
                                next();
                                state = 79;
                                break;
                            case 77:
                                next();
                                state = 79;
                                break;
                            case 76:
                                next();
                                state = 79;
                                break;
                            case 65:
                                next();
                                state = 79;
                                break;
                            case 112:
                                next();
                                state = 79;
                                break;
                            case 88:
                                next();
                                state = 79;
                                break;
                            case 89:
                                next();
                                state = 79;
                                break;
                            case 66:
                                next();
                                state = 79;
                                break;
                            case 113:
                                next();
                                state = 79;
                                break;
                            case 87:
                                next();
                                state = 79;
                                break;
                            case 116:
                                next();
                                state = 79;
                                break;
                            case 69:
                                next();
                                state = 79;
                                break;
                            case 115:
                                next();
                                state = 79;
                                break;
                            case 68:
                                next();
                                state = 79;
                                break;
                            case 114:
                                next();
                                state = 79;
                                break;
                            case 67:
                                next();
                                state = 79;
                                break;
                            case 90:
                                next();
                                state = 79;
                                break;
                            case 99:
                                next();
                                state = 79;
                                break;
                            case 52:
                                next();
                                state = 79;
                                break;
                            case 100:
                                next();
                                state = 79;
                                break;
                            case 53:
                                next();
                                state = 79;
                                break;
                            case 101:
                                next();
                                state = 79;
                                break;
                            case 54:
                                next();
                                state = 79;
                                break;
                            case 82:
                                next();
                                state = 79;
                                break;
                            case 105:
                                next();
                                state = 78;
                                break;
                            case 111:
                                next();
                                state = 79;
                                break;
                            case 110:
                                next();
                                state = 79;
                                break;
                            case 86:
                                next();
                                state = 79;
                                break;
                            case 109:
                                next();
                                state = 79;
                                break;
                            case 85:
                                next();
                                state = 79;
                                break;
                            case 108:
                                next();
                                state = 79;
                                break;
                            case 84:
                                next();
                                state = 79;
                                break;
                            case 107:
                                next();
                                state = 79;
                                break;
                            case 83:
                                next();
                                state = 79;
                                break;
                            case 106:
                                next();
                                state = 79;
                                break;
                            case 104:
                                next();
                                state = 79;
                                break;
                            case 57:
                                next();
                                state = 79;
                                break;
                            case 103:
                                next();
                                state = 79;
                                break;
                            case 56:
                                next();
                                state = 79;
                                break;
                            case 102:
                                next();
                                state = 79;
                                break;
                            default:
                                m_semantic.elsee(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 76:
                        switch (c) {
                            case 103:
                                next();
                                state = 79;
                                break;
                            case 57:
                                next();
                                state = 79;
                                break;
                            case 104:
                                next();
                                state = 79;
                                break;
                            case 105:
                                next();
                                state = 79;
                                break;
                            case 82:
                                next();
                                state = 79;
                                break;
                            case 106:
                                next();
                                state = 79;
                                break;
                            case 83:
                                next();
                                state = 79;
                                break;
                            case 107:
                                next();
                                state = 79;
                                break;
                            case 84:
                                next();
                                state = 79;
                                break;
                            case 108:
                                next();
                                state = 27;
                                break;
                            case 85:
                                next();
                                state = 79;
                                break;
                            case 109:
                                next();
                                state = 79;
                                break;
                            case 111:
                                next();
                                state = 79;
                                break;
                            case 110:
                                next();
                                state = 50;
                                break;
                            case 55:
                                next();
                                state = 79;
                                break;
                            case 102:
                                next();
                                state = 79;
                                break;
                            case 54:
                                next();
                                state = 79;
                                break;
                            case 81:
                                next();
                                state = 79;
                                break;
                            case 56:
                                next();
                                state = 79;
                                break;
                            case 86:
                                next();
                                state = 79;
                                break;
                            case 70:
                                next();
                                state = 79;
                                break;
                            case 117:
                                next();
                                state = 79;
                                break;
                            case 48:
                                next();
                                state = 79;
                                break;
                            case 95:
                                next();
                                state = 79;
                                break;
                            case 71:
                                next();
                                state = 79;
                                break;
                            case 118:
                                next();
                                state = 79;
                                break;
                            case 97:
                                next();
                                state = 79;
                                break;
                            case 50:
                                next();
                                state = 79;
                                break;
                            case 51:
                                next();
                                state = 79;
                                break;
                            case 98:
                                next();
                                state = 79;
                                break;
                            case 120:
                                next();
                                state = 79;
                                break;
                            case 73:
                                next();
                                state = 79;
                                break;
                            case 74:
                                next();
                                state = 79;
                                break;
                            case 121:
                                next();
                                state = 79;
                                break;
                            case 49:
                                next();
                                state = 79;
                                break;
                            case 72:
                                next();
                                state = 79;
                                break;
                            case 119:
                                next();
                                state = 79;
                                break;
                            case 75:
                                next();
                                state = 79;
                                break;
                            case 122:
                                next();
                                state = 79;
                                break;
                            case 80:
                                next();
                                state = 79;
                                break;
                            case 79:
                                next();
                                state = 79;
                                break;
                            case 78:
                                next();
                                state = 79;
                                break;
                            case 77:
                                next();
                                state = 79;
                                break;
                            case 76:
                                next();
                                state = 79;
                                break;
                            case 65:
                                next();
                                state = 79;
                                break;
                            case 112:
                                next();
                                state = 79;
                                break;
                            case 88:
                                next();
                                state = 79;
                                break;
                            case 89:
                                next();
                                state = 79;
                                break;
                            case 66:
                                next();
                                state = 79;
                                break;
                            case 113:
                                next();
                                state = 79;
                                break;
                            case 87:
                                next();
                                state = 79;
                                break;
                            case 116:
                                next();
                                state = 79;
                                break;
                            case 69:
                                next();
                                state = 79;
                                break;
                            case 115:
                                next();
                                state = 79;
                                break;
                            case 68:
                                next();
                                state = 79;
                                break;
                            case 114:
                                next();
                                state = 79;
                                break;
                            case 67:
                                next();
                                state = 79;
                                break;
                            case 90:
                                next();
                                state = 79;
                                break;
                            case 99:
                                next();
                                state = 79;
                                break;
                            case 52:
                                next();
                                state = 79;
                                break;
                            case 100:
                                next();
                                state = 79;
                                break;
                            case 53:
                                next();
                                state = 79;
                                break;
                            case 101:
                                next();
                                state = 79;
                                break;
                            default:
                                m_semantic.id(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 77:
                        switch (c) {
                            case 81:
                                next();
                                state = 79;
                                break;
                            case 49:
                                next();
                                state = 79;
                                break;
                            case 71:
                                next();
                                state = 79;
                                break;
                            case 118:
                                next();
                                state = 79;
                                break;
                            case 72:
                                next();
                                state = 79;
                                break;
                            case 119:
                                next();
                                state = 79;
                                break;
                            case 74:
                                next();
                                state = 79;
                                break;
                            case 121:
                                next();
                                state = 79;
                                break;
                            case 75:
                                next();
                                state = 79;
                                break;
                            case 122:
                                next();
                                state = 79;
                                break;
                            case 73:
                                next();
                                state = 79;
                                break;
                            case 120:
                                next();
                                state = 79;
                                break;
                            case 95:
                                next();
                                state = 79;
                                break;
                            case 48:
                                next();
                                state = 79;
                                break;
                            case 70:
                                next();
                                state = 79;
                                break;
                            case 117:
                                next();
                                state = 79;
                                break;
                            case 55:
                                next();
                                state = 79;
                                break;
                            case 98:
                                next();
                                state = 79;
                                break;
                            case 51:
                                next();
                                state = 79;
                                break;
                            case 50:
                                next();
                                state = 79;
                                break;
                            case 97:
                                next();
                                state = 79;
                                break;
                            case 80:
                                next();
                                state = 79;
                                break;
                            case 79:
                                next();
                                state = 79;
                                break;
                            case 78:
                                next();
                                state = 79;
                                break;
                            case 77:
                                next();
                                state = 79;
                                break;
                            case 76:
                                next();
                                state = 79;
                                break;
                            case 65:
                                next();
                                state = 79;
                                break;
                            case 112:
                                next();
                                state = 79;
                                break;
                            case 88:
                                next();
                                state = 79;
                                break;
                            case 89:
                                next();
                                state = 79;
                                break;
                            case 66:
                                next();
                                state = 79;
                                break;
                            case 113:
                                next();
                                state = 79;
                                break;
                            case 87:
                                next();
                                state = 79;
                                break;
                            case 116:
                                next();
                                state = 79;
                                break;
                            case 69:
                                next();
                                state = 79;
                                break;
                            case 115:
                                next();
                                state = 79;
                                break;
                            case 68:
                                next();
                                state = 79;
                                break;
                            case 114:
                                next();
                                state = 79;
                                break;
                            case 67:
                                next();
                                state = 79;
                                break;
                            case 90:
                                next();
                                state = 79;
                                break;
                            case 99:
                                next();
                                state = 79;
                                break;
                            case 52:
                                next();
                                state = 79;
                                break;
                            case 100:
                                next();
                                state = 79;
                                break;
                            case 53:
                                next();
                                state = 79;
                                break;
                            case 101:
                                next();
                                state = 75;
                                break;
                            case 54:
                                next();
                                state = 79;
                                break;
                            case 111:
                                next();
                                state = 79;
                                break;
                            case 110:
                                next();
                                state = 79;
                                break;
                            case 86:
                                next();
                                state = 79;
                                break;
                            case 109:
                                next();
                                state = 79;
                                break;
                            case 85:
                                next();
                                state = 79;
                                break;
                            case 108:
                                next();
                                state = 79;
                                break;
                            case 84:
                                next();
                                state = 79;
                                break;
                            case 107:
                                next();
                                state = 79;
                                break;
                            case 83:
                                next();
                                state = 79;
                                break;
                            case 106:
                                next();
                                state = 79;
                                break;
                            case 82:
                                next();
                                state = 79;
                                break;
                            case 105:
                                next();
                                state = 79;
                                break;
                            case 104:
                                next();
                                state = 79;
                                break;
                            case 57:
                                next();
                                state = 79;
                                break;
                            case 103:
                                next();
                                state = 79;
                                break;
                            case 56:
                                next();
                                state = 79;
                                break;
                            case 102:
                                next();
                                state = 79;
                                break;
                            default:
                                m_semantic.id(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 78:
                        switch (c) {
                            case 81:
                                next();
                                state = 79;
                                break;
                            case 49:
                                next();
                                state = 79;
                                break;
                            case 71:
                                next();
                                state = 79;
                                break;
                            case 118:
                                next();
                                state = 79;
                                break;
                            case 72:
                                next();
                                state = 79;
                                break;
                            case 119:
                                next();
                                state = 79;
                                break;
                            case 74:
                                next();
                                state = 79;
                                break;
                            case 121:
                                next();
                                state = 79;
                                break;
                            case 75:
                                next();
                                state = 79;
                                break;
                            case 122:
                                next();
                                state = 79;
                                break;
                            case 73:
                                next();
                                state = 79;
                                break;
                            case 120:
                                next();
                                state = 79;
                                break;
                            case 95:
                                next();
                                state = 79;
                                break;
                            case 48:
                                next();
                                state = 79;
                                break;
                            case 70:
                                next();
                                state = 79;
                                break;
                            case 117:
                                next();
                                state = 79;
                                break;
                            case 55:
                                next();
                                state = 79;
                                break;
                            case 98:
                                next();
                                state = 79;
                                break;
                            case 51:
                                next();
                                state = 79;
                                break;
                            case 50:
                                next();
                                state = 79;
                                break;
                            case 97:
                                next();
                                state = 79;
                                break;
                            case 80:
                                next();
                                state = 79;
                                break;
                            case 79:
                                next();
                                state = 79;
                                break;
                            case 78:
                                next();
                                state = 79;
                                break;
                            case 77:
                                next();
                                state = 79;
                                break;
                            case 76:
                                next();
                                state = 79;
                                break;
                            case 65:
                                next();
                                state = 79;
                                break;
                            case 112:
                                next();
                                state = 79;
                                break;
                            case 88:
                                next();
                                state = 79;
                                break;
                            case 89:
                                next();
                                state = 79;
                                break;
                            case 66:
                                next();
                                state = 79;
                                break;
                            case 113:
                                next();
                                state = 79;
                                break;
                            case 87:
                                next();
                                state = 79;
                                break;
                            case 116:
                                next();
                                state = 79;
                                break;
                            case 69:
                                next();
                                state = 79;
                                break;
                            case 115:
                                next();
                                state = 79;
                                break;
                            case 68:
                                next();
                                state = 79;
                                break;
                            case 114:
                                next();
                                state = 79;
                                break;
                            case 67:
                                next();
                                state = 79;
                                break;
                            case 90:
                                next();
                                state = 79;
                                break;
                            case 99:
                                next();
                                state = 79;
                                break;
                            case 52:
                                next();
                                state = 79;
                                break;
                            case 100:
                                next();
                                state = 79;
                                break;
                            case 53:
                                next();
                                state = 79;
                                break;
                            case 101:
                                next();
                                state = 79;
                                break;
                            case 54:
                                next();
                                state = 79;
                                break;
                            case 111:
                                next();
                                state = 79;
                                break;
                            case 110:
                                next();
                                state = 79;
                                break;
                            case 86:
                                next();
                                state = 79;
                                break;
                            case 109:
                                next();
                                state = 79;
                                break;
                            case 85:
                                next();
                                state = 79;
                                break;
                            case 108:
                                next();
                                state = 79;
                                break;
                            case 84:
                                next();
                                state = 79;
                                break;
                            case 107:
                                next();
                                state = 79;
                                break;
                            case 83:
                                next();
                                state = 79;
                                break;
                            case 106:
                                next();
                                state = 79;
                                break;
                            case 82:
                                next();
                                state = 79;
                                break;
                            case 105:
                                next();
                                state = 79;
                                break;
                            case 104:
                                next();
                                state = 79;
                                break;
                            case 57:
                                next();
                                state = 79;
                                break;
                            case 103:
                                next();
                                state = 79;
                                break;
                            case 56:
                                next();
                                state = 79;
                                break;
                            case 102:
                                next();
                                state = 80;
                                break;
                            default:
                                m_semantic.id(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 79:
                        switch (c) {
                            case 88:
                                next();
                                state = 79;
                                break;
                            case 87:
                                next();
                                state = 79;
                                break;
                            case 116:
                                next();
                                state = 79;
                                break;
                            case 69:
                                next();
                                state = 79;
                                break;
                            case 115:
                                next();
                                state = 79;
                                break;
                            case 68:
                                next();
                                state = 79;
                                break;
                            case 114:
                                next();
                                state = 79;
                                break;
                            case 67:
                                next();
                                state = 79;
                                break;
                            case 113:
                                next();
                                state = 79;
                                break;
                            case 66:
                                next();
                                state = 79;
                                break;
                            case 112:
                                next();
                                state = 79;
                                break;
                            case 65:
                                next();
                                state = 79;
                                break;
                            case 76:
                                next();
                                state = 79;
                                break;
                            case 77:
                                next();
                                state = 79;
                                break;
                            case 78:
                                next();
                                state = 79;
                                break;
                            case 79:
                                next();
                                state = 79;
                                break;
                            case 80:
                                next();
                                state = 79;
                                break;
                            case 89:
                                next();
                                state = 79;
                                break;
                            case 90:
                                next();
                                state = 79;
                                break;
                            case 97:
                                next();
                                state = 79;
                                break;
                            case 50:
                                next();
                                state = 79;
                                break;
                            case 98:
                                next();
                                state = 79;
                                break;
                            case 51:
                                next();
                                state = 79;
                                break;
                            case 99:
                                next();
                                state = 79;
                                break;
                            case 52:
                                next();
                                state = 79;
                                break;
                            case 100:
                                next();
                                state = 79;
                                break;
                            case 53:
                                next();
                                state = 79;
                                break;
                            case 101:
                                next();
                                state = 79;
                                break;
                            case 54:
                                next();
                                state = 79;
                                break;
                            case 111:
                                next();
                                state = 79;
                                break;
                            case 110:
                                next();
                                state = 79;
                                break;
                            case 86:
                                next();
                                state = 79;
                                break;
                            case 109:
                                next();
                                state = 79;
                                break;
                            case 85:
                                next();
                                state = 79;
                                break;
                            case 108:
                                next();
                                state = 79;
                                break;
                            case 84:
                                next();
                                state = 79;
                                break;
                            case 107:
                                next();
                                state = 79;
                                break;
                            case 83:
                                next();
                                state = 79;
                                break;
                            case 106:
                                next();
                                state = 79;
                                break;
                            case 82:
                                next();
                                state = 79;
                                break;
                            case 105:
                                next();
                                state = 79;
                                break;
                            case 104:
                                next();
                                state = 79;
                                break;
                            case 57:
                                next();
                                state = 79;
                                break;
                            case 103:
                                next();
                                state = 79;
                                break;
                            case 56:
                                next();
                                state = 79;
                                break;
                            case 102:
                                next();
                                state = 79;
                                break;
                            case 55:
                                next();
                                state = 79;
                                break;
                            case 117:
                                next();
                                state = 79;
                                break;
                            case 70:
                                next();
                                state = 79;
                                break;
                            case 48:
                                next();
                                state = 79;
                                break;
                            case 95:
                                next();
                                state = 79;
                                break;
                            case 120:
                                next();
                                state = 79;
                                break;
                            case 73:
                                next();
                                state = 79;
                                break;
                            case 122:
                                next();
                                state = 79;
                                break;
                            case 75:
                                next();
                                state = 79;
                                break;
                            case 121:
                                next();
                                state = 79;
                                break;
                            case 74:
                                next();
                                state = 79;
                                break;
                            case 119:
                                next();
                                state = 79;
                                break;
                            case 72:
                                next();
                                state = 79;
                                break;
                            case 118:
                                next();
                                state = 79;
                                break;
                            case 71:
                                next();
                                state = 79;
                                break;
                            case 49:
                                next();
                                state = 79;
                                break;
                            case 81:
                                next();
                                state = 79;
                                break;
                            default:
                                m_semantic.id(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 80:
                        switch (c) {
                            case 81:
                                next();
                                state = 79;
                                break;
                            case 49:
                                next();
                                state = 79;
                                break;
                            case 71:
                                next();
                                state = 79;
                                break;
                            case 118:
                                next();
                                state = 79;
                                break;
                            case 72:
                                next();
                                state = 79;
                                break;
                            case 119:
                                next();
                                state = 79;
                                break;
                            case 74:
                                next();
                                state = 79;
                                break;
                            case 121:
                                next();
                                state = 79;
                                break;
                            case 75:
                                next();
                                state = 79;
                                break;
                            case 122:
                                next();
                                state = 79;
                                break;
                            case 73:
                                next();
                                state = 79;
                                break;
                            case 120:
                                next();
                                state = 79;
                                break;
                            case 95:
                                next();
                                state = 79;
                                break;
                            case 48:
                                next();
                                state = 79;
                                break;
                            case 70:
                                next();
                                state = 79;
                                break;
                            case 117:
                                next();
                                state = 79;
                                break;
                            case 55:
                                next();
                                state = 79;
                                break;
                            case 98:
                                next();
                                state = 79;
                                break;
                            case 51:
                                next();
                                state = 79;
                                break;
                            case 50:
                                next();
                                state = 79;
                                break;
                            case 97:
                                next();
                                state = 79;
                                break;
                            case 80:
                                next();
                                state = 79;
                                break;
                            case 79:
                                next();
                                state = 79;
                                break;
                            case 78:
                                next();
                                state = 79;
                                break;
                            case 77:
                                next();
                                state = 79;
                                break;
                            case 76:
                                next();
                                state = 79;
                                break;
                            case 65:
                                next();
                                state = 79;
                                break;
                            case 112:
                                next();
                                state = 79;
                                break;
                            case 88:
                                next();
                                state = 79;
                                break;
                            case 89:
                                next();
                                state = 79;
                                break;
                            case 66:
                                next();
                                state = 79;
                                break;
                            case 113:
                                next();
                                state = 79;
                                break;
                            case 87:
                                next();
                                state = 79;
                                break;
                            case 116:
                                next();
                                state = 79;
                                break;
                            case 69:
                                next();
                                state = 79;
                                break;
                            case 115:
                                next();
                                state = 79;
                                break;
                            case 68:
                                next();
                                state = 79;
                                break;
                            case 114:
                                next();
                                state = 79;
                                break;
                            case 67:
                                next();
                                state = 79;
                                break;
                            case 90:
                                next();
                                state = 79;
                                break;
                            case 99:
                                next();
                                state = 79;
                                break;
                            case 52:
                                next();
                                state = 79;
                                break;
                            case 100:
                                next();
                                state = 79;
                                break;
                            case 53:
                                next();
                                state = 79;
                                break;
                            case 101:
                                next();
                                state = 79;
                                break;
                            case 54:
                                next();
                                state = 79;
                                break;
                            case 111:
                                next();
                                state = 79;
                                break;
                            case 110:
                                next();
                                state = 79;
                                break;
                            case 86:
                                next();
                                state = 79;
                                break;
                            case 109:
                                next();
                                state = 79;
                                break;
                            case 85:
                                next();
                                state = 79;
                                break;
                            case 108:
                                next();
                                state = 79;
                                break;
                            case 84:
                                next();
                                state = 79;
                                break;
                            case 107:
                                next();
                                state = 79;
                                break;
                            case 83:
                                next();
                                state = 79;
                                break;
                            case 106:
                                next();
                                state = 79;
                                break;
                            case 82:
                                next();
                                state = 79;
                                break;
                            case 105:
                                next();
                                state = 79;
                                break;
                            case 104:
                                next();
                                state = 79;
                                break;
                            case 57:
                                next();
                                state = 79;
                                break;
                            case 103:
                                next();
                                state = 79;
                                break;
                            case 56:
                                next();
                                state = 79;
                                break;
                            case 102:
                                next();
                                state = 79;
                                break;
                            default:
                                m_semantic.elseif(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 81:
                        m_semantic.dot(m_lexeme.str());
                        return true;
                    case 82:
                        m_semantic.le(m_lexeme.str());
                        return true;
                    case 83:
                        switch (c) {
                            case 81:
                                next();
                                state = 79;
                                break;
                            case 49:
                                next();
                                state = 79;
                                break;
                            case 71:
                                next();
                                state = 79;
                                break;
                            case 118:
                                next();
                                state = 79;
                                break;
                            case 72:
                                next();
                                state = 79;
                                break;
                            case 119:
                                next();
                                state = 79;
                                break;
                            case 74:
                                next();
                                state = 79;
                                break;
                            case 121:
                                next();
                                state = 79;
                                break;
                            case 75:
                                next();
                                state = 79;
                                break;
                            case 122:
                                next();
                                state = 79;
                                break;
                            case 73:
                                next();
                                state = 79;
                                break;
                            case 120:
                                next();
                                state = 79;
                                break;
                            case 95:
                                next();
                                state = 79;
                                break;
                            case 48:
                                next();
                                state = 79;
                                break;
                            case 70:
                                next();
                                state = 79;
                                break;
                            case 117:
                                next();
                                state = 79;
                                break;
                            case 55:
                                next();
                                state = 79;
                                break;
                            case 98:
                                next();
                                state = 79;
                                break;
                            case 51:
                                next();
                                state = 79;
                                break;
                            case 50:
                                next();
                                state = 79;
                                break;
                            case 97:
                                next();
                                state = 79;
                                break;
                            case 80:
                                next();
                                state = 79;
                                break;
                            case 79:
                                next();
                                state = 79;
                                break;
                            case 78:
                                next();
                                state = 79;
                                break;
                            case 77:
                                next();
                                state = 79;
                                break;
                            case 76:
                                next();
                                state = 79;
                                break;
                            case 65:
                                next();
                                state = 79;
                                break;
                            case 112:
                                next();
                                state = 79;
                                break;
                            case 88:
                                next();
                                state = 79;
                                break;
                            case 89:
                                next();
                                state = 79;
                                break;
                            case 66:
                                next();
                                state = 79;
                                break;
                            case 113:
                                next();
                                state = 79;
                                break;
                            case 87:
                                next();
                                state = 79;
                                break;
                            case 116:
                                next();
                                state = 79;
                                break;
                            case 69:
                                next();
                                state = 79;
                                break;
                            case 115:
                                next();
                                state = 79;
                                break;
                            case 68:
                                next();
                                state = 79;
                                break;
                            case 114:
                                next();
                                state = 79;
                                break;
                            case 67:
                                next();
                                state = 79;
                                break;
                            case 90:
                                next();
                                state = 79;
                                break;
                            case 99:
                                next();
                                state = 79;
                                break;
                            case 52:
                                next();
                                state = 79;
                                break;
                            case 100:
                                next();
                                state = 79;
                                break;
                            case 53:
                                next();
                                state = 79;
                                break;
                            case 101:
                                next();
                                state = 79;
                                break;
                            case 54:
                                next();
                                state = 79;
                                break;
                            case 111:
                                next();
                                state = 79;
                                break;
                            case 110:
                                next();
                                state = 79;
                                break;
                            case 86:
                                next();
                                state = 79;
                                break;
                            case 109:
                                next();
                                state = 79;
                                break;
                            case 85:
                                next();
                                state = 79;
                                break;
                            case 108:
                                next();
                                state = 79;
                                break;
                            case 84:
                                next();
                                state = 79;
                                break;
                            case 107:
                                next();
                                state = 79;
                                break;
                            case 83:
                                next();
                                state = 79;
                                break;
                            case 106:
                                next();
                                state = 79;
                                break;
                            case 82:
                                next();
                                state = 79;
                                break;
                            case 105:
                                next();
                                state = 79;
                                break;
                            case 104:
                                next();
                                state = 79;
                                break;
                            case 57:
                                next();
                                state = 79;
                                break;
                            case 103:
                                next();
                                state = 79;
                                break;
                            case 56:
                                next();
                                state = 79;
                                break;
                            case 102:
                                next();
                                state = 79;
                                break;
                            default:
                                m_semantic.whilee(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 84:
                        switch (c) {
                            case 81:
                                next();
                                state = 79;
                                break;
                            case 49:
                                next();
                                state = 79;
                                break;
                            case 71:
                                next();
                                state = 79;
                                break;
                            case 118:
                                next();
                                state = 79;
                                break;
                            case 72:
                                next();
                                state = 79;
                                break;
                            case 119:
                                next();
                                state = 79;
                                break;
                            case 74:
                                next();
                                state = 79;
                                break;
                            case 121:
                                next();
                                state = 79;
                                break;
                            case 75:
                                next();
                                state = 79;
                                break;
                            case 122:
                                next();
                                state = 79;
                                break;
                            case 73:
                                next();
                                state = 79;
                                break;
                            case 120:
                                next();
                                state = 79;
                                break;
                            case 95:
                                next();
                                state = 79;
                                break;
                            case 48:
                                next();
                                state = 79;
                                break;
                            case 70:
                                next();
                                state = 79;
                                break;
                            case 117:
                                next();
                                state = 79;
                                break;
                            case 55:
                                next();
                                state = 79;
                                break;
                            case 98:
                                next();
                                state = 79;
                                break;
                            case 51:
                                next();
                                state = 79;
                                break;
                            case 50:
                                next();
                                state = 79;
                                break;
                            case 97:
                                next();
                                state = 79;
                                break;
                            case 80:
                                next();
                                state = 79;
                                break;
                            case 79:
                                next();
                                state = 79;
                                break;
                            case 78:
                                next();
                                state = 79;
                                break;
                            case 77:
                                next();
                                state = 79;
                                break;
                            case 76:
                                next();
                                state = 79;
                                break;
                            case 65:
                                next();
                                state = 79;
                                break;
                            case 112:
                                next();
                                state = 79;
                                break;
                            case 88:
                                next();
                                state = 79;
                                break;
                            case 89:
                                next();
                                state = 79;
                                break;
                            case 66:
                                next();
                                state = 79;
                                break;
                            case 113:
                                next();
                                state = 79;
                                break;
                            case 87:
                                next();
                                state = 79;
                                break;
                            case 116:
                                next();
                                state = 79;
                                break;
                            case 69:
                                next();
                                state = 79;
                                break;
                            case 115:
                                next();
                                state = 79;
                                break;
                            case 68:
                                next();
                                state = 79;
                                break;
                            case 114:
                                next();
                                state = 79;
                                break;
                            case 67:
                                next();
                                state = 79;
                                break;
                            case 90:
                                next();
                                state = 79;
                                break;
                            case 99:
                                next();
                                state = 79;
                                break;
                            case 52:
                                next();
                                state = 79;
                                break;
                            case 100:
                                next();
                                state = 79;
                                break;
                            case 53:
                                next();
                                state = 79;
                                break;
                            case 101:
                                next();
                                state = 79;
                                break;
                            case 54:
                                next();
                                state = 79;
                                break;
                            case 82:
                                next();
                                state = 79;
                                break;
                            case 105:
                                next();
                                state = 61;
                                break;
                            case 111:
                                next();
                                state = 79;
                                break;
                            case 110:
                                next();
                                state = 79;
                                break;
                            case 86:
                                next();
                                state = 79;
                                break;
                            case 109:
                                next();
                                state = 79;
                                break;
                            case 85:
                                next();
                                state = 79;
                                break;
                            case 108:
                                next();
                                state = 79;
                                break;
                            case 84:
                                next();
                                state = 79;
                                break;
                            case 107:
                                next();
                                state = 79;
                                break;
                            case 83:
                                next();
                                state = 79;
                                break;
                            case 106:
                                next();
                                state = 79;
                                break;
                            case 104:
                                next();
                                state = 79;
                                break;
                            case 57:
                                next();
                                state = 79;
                                break;
                            case 103:
                                next();
                                state = 79;
                                break;
                            case 56:
                                next();
                                state = 79;
                                break;
                            case 102:
                                next();
                                state = 79;
                                break;
                            default:
                                m_semantic.id(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 85:
                        switch (c) {
                            case 81:
                                next();
                                state = 79;
                                break;
                            case 49:
                                next();
                                state = 79;
                                break;
                            case 71:
                                next();
                                state = 79;
                                break;
                            case 118:
                                next();
                                state = 79;
                                break;
                            case 72:
                                next();
                                state = 79;
                                break;
                            case 119:
                                next();
                                state = 79;
                                break;
                            case 74:
                                next();
                                state = 79;
                                break;
                            case 121:
                                next();
                                state = 79;
                                break;
                            case 75:
                                next();
                                state = 79;
                                break;
                            case 122:
                                next();
                                state = 79;
                                break;
                            case 73:
                                next();
                                state = 79;
                                break;
                            case 120:
                                next();
                                state = 79;
                                break;
                            case 95:
                                next();
                                state = 79;
                                break;
                            case 48:
                                next();
                                state = 79;
                                break;
                            case 70:
                                next();
                                state = 79;
                                break;
                            case 117:
                                next();
                                state = 79;
                                break;
                            case 55:
                                next();
                                state = 79;
                                break;
                            case 98:
                                next();
                                state = 79;
                                break;
                            case 51:
                                next();
                                state = 79;
                                break;
                            case 50:
                                next();
                                state = 79;
                                break;
                            case 97:
                                next();
                                state = 79;
                                break;
                            case 80:
                                next();
                                state = 79;
                                break;
                            case 79:
                                next();
                                state = 79;
                                break;
                            case 78:
                                next();
                                state = 79;
                                break;
                            case 77:
                                next();
                                state = 79;
                                break;
                            case 76:
                                next();
                                state = 79;
                                break;
                            case 65:
                                next();
                                state = 79;
                                break;
                            case 112:
                                next();
                                state = 79;
                                break;
                            case 88:
                                next();
                                state = 79;
                                break;
                            case 89:
                                next();
                                state = 79;
                                break;
                            case 66:
                                next();
                                state = 79;
                                break;
                            case 113:
                                next();
                                state = 79;
                                break;
                            case 87:
                                next();
                                state = 79;
                                break;
                            case 116:
                                next();
                                state = 79;
                                break;
                            case 69:
                                next();
                                state = 79;
                                break;
                            case 115:
                                next();
                                state = 79;
                                break;
                            case 68:
                                next();
                                state = 79;
                                break;
                            case 114:
                                next();
                                state = 79;
                                break;
                            case 67:
                                next();
                                state = 79;
                                break;
                            case 90:
                                next();
                                state = 79;
                                break;
                            case 99:
                                next();
                                state = 79;
                                break;
                            case 52:
                                next();
                                state = 79;
                                break;
                            case 100:
                                next();
                                state = 79;
                                break;
                            case 53:
                                next();
                                state = 79;
                                break;
                            case 101:
                                next();
                                state = 79;
                                break;
                            case 54:
                                next();
                                state = 79;
                                break;
                            case 103:
                                next();
                                state = 103;
                                break;
                            case 56:
                                next();
                                state = 79;
                                break;
                            case 111:
                                next();
                                state = 79;
                                break;
                            case 110:
                                next();
                                state = 79;
                                break;
                            case 86:
                                next();
                                state = 79;
                                break;
                            case 109:
                                next();
                                state = 79;
                                break;
                            case 85:
                                next();
                                state = 79;
                                break;
                            case 108:
                                next();
                                state = 79;
                                break;
                            case 84:
                                next();
                                state = 79;
                                break;
                            case 107:
                                next();
                                state = 79;
                                break;
                            case 83:
                                next();
                                state = 79;
                                break;
                            case 106:
                                next();
                                state = 79;
                                break;
                            case 82:
                                next();
                                state = 79;
                                break;
                            case 105:
                                next();
                                state = 79;
                                break;
                            case 104:
                                next();
                                state = 79;
                                break;
                            case 57:
                                next();
                                state = 79;
                                break;
                            case 102:
                                next();
                                state = 79;
                                break;
                            default:
                                m_semantic.id(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 86:
                        m_semantic.assign(m_lexeme.str());
                        return true;
                    case 87:
                        m_semantic.deref(m_lexeme.str());
                        return true;
                    case 88:
                        switch (c) {
                            case 81:
                                next();
                                state = 79;
                                break;
                            case 49:
                                next();
                                state = 79;
                                break;
                            case 71:
                                next();
                                state = 79;
                                break;
                            case 118:
                                next();
                                state = 79;
                                break;
                            case 72:
                                next();
                                state = 79;
                                break;
                            case 119:
                                next();
                                state = 79;
                                break;
                            case 74:
                                next();
                                state = 79;
                                break;
                            case 121:
                                next();
                                state = 79;
                                break;
                            case 75:
                                next();
                                state = 79;
                                break;
                            case 122:
                                next();
                                state = 79;
                                break;
                            case 73:
                                next();
                                state = 79;
                                break;
                            case 120:
                                next();
                                state = 79;
                                break;
                            case 95:
                                next();
                                state = 79;
                                break;
                            case 48:
                                next();
                                state = 79;
                                break;
                            case 70:
                                next();
                                state = 79;
                                break;
                            case 117:
                                next();
                                state = 79;
                                break;
                            case 56:
                                next();
                                state = 79;
                                break;
                            case 98:
                                next();
                                state = 79;
                                break;
                            case 51:
                                next();
                                state = 79;
                                break;
                            case 50:
                                next();
                                state = 79;
                                break;
                            case 97:
                                next();
                                state = 79;
                                break;
                            case 80:
                                next();
                                state = 79;
                                break;
                            case 79:
                                next();
                                state = 79;
                                break;
                            case 78:
                                next();
                                state = 79;
                                break;
                            case 77:
                                next();
                                state = 79;
                                break;
                            case 76:
                                next();
                                state = 79;
                                break;
                            case 65:
                                next();
                                state = 79;
                                break;
                            case 112:
                                next();
                                state = 79;
                                break;
                            case 88:
                                next();
                                state = 79;
                                break;
                            case 89:
                                next();
                                state = 79;
                                break;
                            case 66:
                                next();
                                state = 79;
                                break;
                            case 113:
                                next();
                                state = 79;
                                break;
                            case 87:
                                next();
                                state = 79;
                                break;
                            case 116:
                                next();
                                state = 79;
                                break;
                            case 69:
                                next();
                                state = 79;
                                break;
                            case 115:
                                next();
                                state = 79;
                                break;
                            case 68:
                                next();
                                state = 79;
                                break;
                            case 114:
                                next();
                                state = 79;
                                break;
                            case 67:
                                next();
                                state = 79;
                                break;
                            case 90:
                                next();
                                state = 79;
                                break;
                            case 99:
                                next();
                                state = 79;
                                break;
                            case 52:
                                next();
                                state = 79;
                                break;
                            case 100:
                                next();
                                state = 79;
                                break;
                            case 53:
                                next();
                                state = 79;
                                break;
                            case 102:
                                next();
                                state = 79;
                                break;
                            case 55:
                                next();
                                state = 79;
                                break;
                            case 101:
                                next();
                                state = 111;
                                break;
                            case 54:
                                next();
                                state = 79;
                                break;
                            case 111:
                                next();
                                state = 79;
                                break;
                            case 110:
                                next();
                                state = 79;
                                break;
                            case 86:
                                next();
                                state = 79;
                                break;
                            case 109:
                                next();
                                state = 79;
                                break;
                            case 85:
                                next();
                                state = 79;
                                break;
                            case 108:
                                next();
                                state = 79;
                                break;
                            case 84:
                                next();
                                state = 79;
                                break;
                            case 107:
                                next();
                                state = 79;
                                break;
                            case 83:
                                next();
                                state = 79;
                                break;
                            case 106:
                                next();
                                state = 79;
                                break;
                            case 82:
                                next();
                                state = 79;
                                break;
                            case 105:
                                next();
                                state = 79;
                                break;
                            case 104:
                                next();
                                state = 79;
                                break;
                            case 57:
                                next();
                                state = 79;
                                break;
                            case 103:
                                next();
                                state = 79;
                                break;
                            default:
                                m_semantic.id(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 89:
                        switch (c) {
                            case 81:
                                next();
                                state = 79;
                                break;
                            case 49:
                                next();
                                state = 79;
                                break;
                            case 72:
                                next();
                                state = 79;
                                break;
                            case 119:
                                next();
                                state = 79;
                                break;
                            case 74:
                                next();
                                state = 79;
                                break;
                            case 121:
                                next();
                                state = 79;
                                break;
                            case 75:
                                next();
                                state = 79;
                                break;
                            case 122:
                                next();
                                state = 79;
                                break;
                            case 73:
                                next();
                                state = 79;
                                break;
                            case 120:
                                next();
                                state = 79;
                                break;
                            case 95:
                                next();
                                state = 79;
                                break;
                            case 48:
                                next();
                                state = 79;
                                break;
                            case 70:
                                next();
                                state = 79;
                                break;
                            case 117:
                                next();
                                state = 79;
                                break;
                            case 86:
                                next();
                                state = 79;
                                break;
                            case 56:
                                next();
                                state = 79;
                                break;
                            case 103:
                                next();
                                state = 79;
                                break;
                            case 98:
                                next();
                                state = 79;
                                break;
                            case 51:
                                next();
                                state = 79;
                                break;
                            case 50:
                                next();
                                state = 79;
                                break;
                            case 97:
                                next();
                                state = 79;
                                break;
                            case 80:
                                next();
                                state = 79;
                                break;
                            case 79:
                                next();
                                state = 79;
                                break;
                            case 78:
                                next();
                                state = 79;
                                break;
                            case 77:
                                next();
                                state = 79;
                                break;
                            case 76:
                                next();
                                state = 79;
                                break;
                            case 65:
                                next();
                                state = 79;
                                break;
                            case 112:
                                next();
                                state = 79;
                                break;
                            case 88:
                                next();
                                state = 79;
                                break;
                            case 89:
                                next();
                                state = 79;
                                break;
                            case 66:
                                next();
                                state = 79;
                                break;
                            case 113:
                                next();
                                state = 79;
                                break;
                            case 87:
                                next();
                                state = 79;
                                break;
                            case 116:
                                next();
                                state = 79;
                                break;
                            case 69:
                                next();
                                state = 79;
                                break;
                            case 115:
                                next();
                                state = 79;
                                break;
                            case 68:
                                next();
                                state = 79;
                                break;
                            case 114:
                                next();
                                state = 79;
                                break;
                            case 67:
                                next();
                                state = 79;
                                break;
                            case 90:
                                next();
                                state = 79;
                                break;
                            case 99:
                                next();
                                state = 79;
                                break;
                            case 52:
                                next();
                                state = 79;
                                break;
                            case 100:
                                next();
                                state = 79;
                                break;
                            case 53:
                                next();
                                state = 79;
                                break;
                            case 101:
                                next();
                                state = 79;
                                break;
                            case 54:
                                next();
                                state = 79;
                                break;
                            case 102:
                                next();
                                state = 79;
                                break;
                            case 55:
                                next();
                                state = 79;
                                break;
                            case 118:
                                next();
                                state = 107;
                                break;
                            case 71:
                                next();
                                state = 79;
                                break;
                            case 84:
                                next();
                                state = 79;
                                break;
                            case 107:
                                next();
                                state = 79;
                                break;
                            case 111:
                                next();
                                state = 79;
                                break;
                            case 110:
                                next();
                                state = 79;
                                break;
                            case 109:
                                next();
                                state = 79;
                                break;
                            case 85:
                                next();
                                state = 79;
                                break;
                            case 108:
                                next();
                                state = 79;
                                break;
                            case 83:
                                next();
                                state = 79;
                                break;
                            case 106:
                                next();
                                state = 79;
                                break;
                            case 82:
                                next();
                                state = 79;
                                break;
                            case 105:
                                next();
                                state = 79;
                                break;
                            case 104:
                                next();
                                state = 79;
                                break;
                            case 57:
                                next();
                                state = 79;
                                break;
                            default:
                                m_semantic.id(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 90:
                        switch (c) {
                            case 62:
                                next();
                                state = 94;
                                break;
                            case 61:
                                next();
                                state = 82;
                                break;
                            default:
                                m_semantic.lt(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 91:
                        switch (c) {
                            case 81:
                                next();
                                state = 79;
                                break;
                            case 49:
                                next();
                                state = 79;
                                break;
                            case 71:
                                next();
                                state = 79;
                                break;
                            case 118:
                                next();
                                state = 79;
                                break;
                            case 72:
                                next();
                                state = 79;
                                break;
                            case 119:
                                next();
                                state = 79;
                                break;
                            case 74:
                                next();
                                state = 79;
                                break;
                            case 121:
                                next();
                                state = 79;
                                break;
                            case 75:
                                next();
                                state = 79;
                                break;
                            case 122:
                                next();
                                state = 79;
                                break;
                            case 73:
                                next();
                                state = 79;
                                break;
                            case 120:
                                next();
                                state = 79;
                                break;
                            case 95:
                                next();
                                state = 79;
                                break;
                            case 48:
                                next();
                                state = 79;
                                break;
                            case 70:
                                next();
                                state = 79;
                                break;
                            case 117:
                                next();
                                state = 79;
                                break;
                            case 55:
                                next();
                                state = 79;
                                break;
                            case 98:
                                next();
                                state = 79;
                                break;
                            case 51:
                                next();
                                state = 79;
                                break;
                            case 50:
                                next();
                                state = 79;
                                break;
                            case 97:
                                next();
                                state = 79;
                                break;
                            case 80:
                                next();
                                state = 79;
                                break;
                            case 79:
                                next();
                                state = 79;
                                break;
                            case 78:
                                next();
                                state = 79;
                                break;
                            case 77:
                                next();
                                state = 79;
                                break;
                            case 76:
                                next();
                                state = 79;
                                break;
                            case 65:
                                next();
                                state = 79;
                                break;
                            case 112:
                                next();
                                state = 79;
                                break;
                            case 88:
                                next();
                                state = 79;
                                break;
                            case 89:
                                next();
                                state = 79;
                                break;
                            case 66:
                                next();
                                state = 79;
                                break;
                            case 113:
                                next();
                                state = 79;
                                break;
                            case 87:
                                next();
                                state = 79;
                                break;
                            case 116:
                                next();
                                state = 79;
                                break;
                            case 69:
                                next();
                                state = 79;
                                break;
                            case 115:
                                next();
                                state = 79;
                                break;
                            case 68:
                                next();
                                state = 79;
                                break;
                            case 114:
                                next();
                                state = 79;
                                break;
                            case 67:
                                next();
                                state = 79;
                                break;
                            case 90:
                                next();
                                state = 79;
                                break;
                            case 99:
                                next();
                                state = 79;
                                break;
                            case 52:
                                next();
                                state = 79;
                                break;
                            case 100:
                                next();
                                state = 49;
                                break;
                            case 53:
                                next();
                                state = 79;
                                break;
                            case 101:
                                next();
                                state = 79;
                                break;
                            case 54:
                                next();
                                state = 79;
                                break;
                            case 111:
                                next();
                                state = 79;
                                break;
                            case 110:
                                next();
                                state = 79;
                                break;
                            case 86:
                                next();
                                state = 79;
                                break;
                            case 109:
                                next();
                                state = 79;
                                break;
                            case 85:
                                next();
                                state = 79;
                                break;
                            case 108:
                                next();
                                state = 79;
                                break;
                            case 84:
                                next();
                                state = 79;
                                break;
                            case 107:
                                next();
                                state = 79;
                                break;
                            case 83:
                                next();
                                state = 79;
                                break;
                            case 106:
                                next();
                                state = 79;
                                break;
                            case 82:
                                next();
                                state = 79;
                                break;
                            case 105:
                                next();
                                state = 79;
                                break;
                            case 104:
                                next();
                                state = 79;
                                break;
                            case 57:
                                next();
                                state = 79;
                                break;
                            case 103:
                                next();
                                state = 79;
                                break;
                            case 56:
                                next();
                                state = 79;
                                break;
                            case 102:
                                next();
                                state = 79;
                                break;
                            default:
                                m_semantic.id(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 92:
                        switch (c) {
                            case 81:
                                next();
                                state = 79;
                                break;
                            case 49:
                                next();
                                state = 79;
                                break;
                            case 71:
                                next();
                                state = 79;
                                break;
                            case 118:
                                next();
                                state = 79;
                                break;
                            case 72:
                                next();
                                state = 79;
                                break;
                            case 119:
                                next();
                                state = 79;
                                break;
                            case 74:
                                next();
                                state = 79;
                                break;
                            case 121:
                                next();
                                state = 79;
                                break;
                            case 75:
                                next();
                                state = 79;
                                break;
                            case 122:
                                next();
                                state = 79;
                                break;
                            case 73:
                                next();
                                state = 79;
                                break;
                            case 120:
                                next();
                                state = 79;
                                break;
                            case 95:
                                next();
                                state = 79;
                                break;
                            case 48:
                                next();
                                state = 79;
                                break;
                            case 70:
                                next();
                                state = 79;
                                break;
                            case 117:
                                next();
                                state = 79;
                                break;
                            case 55:
                                next();
                                state = 79;
                                break;
                            case 98:
                                next();
                                state = 79;
                                break;
                            case 51:
                                next();
                                state = 79;
                                break;
                            case 50:
                                next();
                                state = 79;
                                break;
                            case 97:
                                next();
                                state = 79;
                                break;
                            case 80:
                                next();
                                state = 79;
                                break;
                            case 79:
                                next();
                                state = 79;
                                break;
                            case 78:
                                next();
                                state = 79;
                                break;
                            case 77:
                                next();
                                state = 79;
                                break;
                            case 76:
                                next();
                                state = 79;
                                break;
                            case 65:
                                next();
                                state = 79;
                                break;
                            case 112:
                                next();
                                state = 79;
                                break;
                            case 88:
                                next();
                                state = 79;
                                break;
                            case 89:
                                next();
                                state = 79;
                                break;
                            case 66:
                                next();
                                state = 79;
                                break;
                            case 113:
                                next();
                                state = 79;
                                break;
                            case 87:
                                next();
                                state = 79;
                                break;
                            case 116:
                                next();
                                state = 79;
                                break;
                            case 69:
                                next();
                                state = 79;
                                break;
                            case 115:
                                next();
                                state = 79;
                                break;
                            case 68:
                                next();
                                state = 79;
                                break;
                            case 114:
                                next();
                                state = 79;
                                break;
                            case 67:
                                next();
                                state = 79;
                                break;
                            case 90:
                                next();
                                state = 79;
                                break;
                            case 99:
                                next();
                                state = 79;
                                break;
                            case 52:
                                next();
                                state = 79;
                                break;
                            case 100:
                                next();
                                state = 79;
                                break;
                            case 53:
                                next();
                                state = 79;
                                break;
                            case 101:
                                next();
                                state = 79;
                                break;
                            case 54:
                                next();
                                state = 79;
                                break;
                            case 111:
                                next();
                                state = 79;
                                break;
                            case 110:
                                next();
                                state = 79;
                                break;
                            case 86:
                                next();
                                state = 79;
                                break;
                            case 109:
                                next();
                                state = 79;
                                break;
                            case 85:
                                next();
                                state = 79;
                                break;
                            case 108:
                                next();
                                state = 79;
                                break;
                            case 84:
                                next();
                                state = 79;
                                break;
                            case 107:
                                next();
                                state = 79;
                                break;
                            case 83:
                                next();
                                state = 79;
                                break;
                            case 106:
                                next();
                                state = 79;
                                break;
                            case 82:
                                next();
                                state = 79;
                                break;
                            case 105:
                                next();
                                state = 79;
                                break;
                            case 104:
                                next();
                                state = 79;
                                break;
                            case 57:
                                next();
                                state = 79;
                                break;
                            case 103:
                                next();
                                state = 79;
                                break;
                            case 56:
                                next();
                                state = 79;
                                break;
                            case 102:
                                next();
                                state = 79;
                                break;
                            default:
                                m_semantic.pointer(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 93:
                        switch (c) {
                            case 10:
                                next();
                                state = 63;
                                break;
                            case 32:
                                next();
                                state = 63;
                                break;
                            case 9:
                                next();
                                state = 63;
                                break;
                            default:
                                return false;
                        }
                        break;
                    case 94:
                        m_semantic.ne(m_lexeme.str());
                        return true;
                    case 95:
                        switch (c) {
                            case 49:
                                next();
                                state = 96;
                                break;
                            case 50:
                                next();
                                state = 96;
                                break;
                            case 51:
                                next();
                                state = 96;
                                break;
                            case 52:
                                next();
                                state = 96;
                                break;
                            case 53:
                                next();
                                state = 96;
                                break;
                            case 54:
                                next();
                                state = 96;
                                break;
                            case 56:
                                next();
                                state = 96;
                                break;
                            case 57:
                                next();
                                state = 96;
                                break;
                            case 55:
                                next();
                                state = 96;
                                break;
                            case 48:
                                next();
                                state = 96;
                                break;
                            default:
                                m_semantic.intlit(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 96:
                        switch (c) {
                            case 48:
                                next();
                                state = 96;
                                break;
                            case 49:
                                next();
                                state = 96;
                                break;
                            case 50:
                                next();
                                state = 96;
                                break;
                            case 51:
                                next();
                                state = 96;
                                break;
                            case 52:
                                next();
                                state = 96;
                                break;
                            case 53:
                                next();
                                state = 96;
                                break;
                            case 54:
                                next();
                                state = 96;
                                break;
                            case 55:
                                next();
                                state = 96;
                                break;
                            case 56:
                                next();
                                state = 96;
                                break;
                            case 57:
                                next();
                                state = 96;
                                break;
                            default:
                                m_semantic.intlit(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 97:
                        switch (c) {
                            case 81:
                                next();
                                state = 79;
                                break;
                            case 49:
                                next();
                                state = 79;
                                break;
                            case 71:
                                next();
                                state = 79;
                                break;
                            case 118:
                                next();
                                state = 79;
                                break;
                            case 72:
                                next();
                                state = 79;
                                break;
                            case 119:
                                next();
                                state = 79;
                                break;
                            case 74:
                                next();
                                state = 79;
                                break;
                            case 121:
                                next();
                                state = 79;
                                break;
                            case 75:
                                next();
                                state = 79;
                                break;
                            case 122:
                                next();
                                state = 79;
                                break;
                            case 73:
                                next();
                                state = 79;
                                break;
                            case 120:
                                next();
                                state = 79;
                                break;
                            case 95:
                                next();
                                state = 79;
                                break;
                            case 48:
                                next();
                                state = 79;
                                break;
                            case 70:
                                next();
                                state = 79;
                                break;
                            case 117:
                                next();
                                state = 79;
                                break;
                            case 55:
                                next();
                                state = 79;
                                break;
                            case 98:
                                next();
                                state = 79;
                                break;
                            case 51:
                                next();
                                state = 79;
                                break;
                            case 50:
                                next();
                                state = 79;
                                break;
                            case 97:
                                next();
                                state = 79;
                                break;
                            case 80:
                                next();
                                state = 79;
                                break;
                            case 79:
                                next();
                                state = 79;
                                break;
                            case 78:
                                next();
                                state = 79;
                                break;
                            case 77:
                                next();
                                state = 79;
                                break;
                            case 76:
                                next();
                                state = 79;
                                break;
                            case 65:
                                next();
                                state = 79;
                                break;
                            case 112:
                                next();
                                state = 79;
                                break;
                            case 88:
                                next();
                                state = 79;
                                break;
                            case 89:
                                next();
                                state = 79;
                                break;
                            case 66:
                                next();
                                state = 79;
                                break;
                            case 113:
                                next();
                                state = 79;
                                break;
                            case 87:
                                next();
                                state = 79;
                                break;
                            case 116:
                                next();
                                state = 79;
                                break;
                            case 69:
                                next();
                                state = 79;
                                break;
                            case 115:
                                next();
                                state = 79;
                                break;
                            case 68:
                                next();
                                state = 79;
                                break;
                            case 114:
                                next();
                                state = 79;
                                break;
                            case 67:
                                next();
                                state = 79;
                                break;
                            case 90:
                                next();
                                state = 79;
                                break;
                            case 99:
                                next();
                                state = 79;
                                break;
                            case 52:
                                next();
                                state = 79;
                                break;
                            case 100:
                                next();
                                state = 79;
                                break;
                            case 53:
                                next();
                                state = 79;
                                break;
                            case 101:
                                next();
                                state = 79;
                                break;
                            case 54:
                                next();
                                state = 79;
                                break;
                            case 111:
                                next();
                                state = 32;
                                break;
                            case 110:
                                next();
                                state = 79;
                                break;
                            case 86:
                                next();
                                state = 79;
                                break;
                            case 109:
                                next();
                                state = 79;
                                break;
                            case 85:
                                next();
                                state = 79;
                                break;
                            case 108:
                                next();
                                state = 79;
                                break;
                            case 84:
                                next();
                                state = 79;
                                break;
                            case 107:
                                next();
                                state = 79;
                                break;
                            case 83:
                                next();
                                state = 79;
                                break;
                            case 106:
                                next();
                                state = 79;
                                break;
                            case 82:
                                next();
                                state = 79;
                                break;
                            case 105:
                                next();
                                state = 79;
                                break;
                            case 104:
                                next();
                                state = 79;
                                break;
                            case 57:
                                next();
                                state = 79;
                                break;
                            case 103:
                                next();
                                state = 79;
                                break;
                            case 56:
                                next();
                                state = 79;
                                break;
                            case 102:
                                next();
                                state = 79;
                                break;
                            default:
                                m_semantic.id(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 98:
                        switch (c) {
                            case 81:
                                next();
                                state = 79;
                                break;
                            case 49:
                                next();
                                state = 79;
                                break;
                            case 71:
                                next();
                                state = 79;
                                break;
                            case 118:
                                next();
                                state = 79;
                                break;
                            case 72:
                                next();
                                state = 79;
                                break;
                            case 119:
                                next();
                                state = 79;
                                break;
                            case 74:
                                next();
                                state = 79;
                                break;
                            case 121:
                                next();
                                state = 79;
                                break;
                            case 75:
                                next();
                                state = 79;
                                break;
                            case 122:
                                next();
                                state = 79;
                                break;
                            case 73:
                                next();
                                state = 79;
                                break;
                            case 120:
                                next();
                                state = 79;
                                break;
                            case 95:
                                next();
                                state = 79;
                                break;
                            case 48:
                                next();
                                state = 79;
                                break;
                            case 70:
                                next();
                                state = 79;
                                break;
                            case 117:
                                next();
                                state = 79;
                                break;
                            case 55:
                                next();
                                state = 79;
                                break;
                            case 98:
                                next();
                                state = 79;
                                break;
                            case 51:
                                next();
                                state = 79;
                                break;
                            case 50:
                                next();
                                state = 79;
                                break;
                            case 97:
                                next();
                                state = 79;
                                break;
                            case 80:
                                next();
                                state = 79;
                                break;
                            case 79:
                                next();
                                state = 79;
                                break;
                            case 78:
                                next();
                                state = 79;
                                break;
                            case 77:
                                next();
                                state = 79;
                                break;
                            case 76:
                                next();
                                state = 79;
                                break;
                            case 65:
                                next();
                                state = 79;
                                break;
                            case 112:
                                next();
                                state = 79;
                                break;
                            case 88:
                                next();
                                state = 79;
                                break;
                            case 89:
                                next();
                                state = 79;
                                break;
                            case 66:
                                next();
                                state = 79;
                                break;
                            case 113:
                                next();
                                state = 79;
                                break;
                            case 87:
                                next();
                                state = 79;
                                break;
                            case 116:
                                next();
                                state = 79;
                                break;
                            case 69:
                                next();
                                state = 79;
                                break;
                            case 115:
                                next();
                                state = 79;
                                break;
                            case 68:
                                next();
                                state = 79;
                                break;
                            case 114:
                                next();
                                state = 79;
                                break;
                            case 67:
                                next();
                                state = 79;
                                break;
                            case 90:
                                next();
                                state = 79;
                                break;
                            case 99:
                                next();
                                state = 79;
                                break;
                            case 52:
                                next();
                                state = 79;
                                break;
                            case 100:
                                next();
                                state = 79;
                                break;
                            case 53:
                                next();
                                state = 79;
                                break;
                            case 101:
                                next();
                                state = 79;
                                break;
                            case 54:
                                next();
                                state = 79;
                                break;
                            case 111:
                                next();
                                state = 79;
                                break;
                            case 110:
                                next();
                                state = 79;
                                break;
                            case 86:
                                next();
                                state = 79;
                                break;
                            case 109:
                                next();
                                state = 79;
                                break;
                            case 85:
                                next();
                                state = 79;
                                break;
                            case 108:
                                next();
                                state = 79;
                                break;
                            case 84:
                                next();
                                state = 79;
                                break;
                            case 107:
                                next();
                                state = 79;
                                break;
                            case 83:
                                next();
                                state = 79;
                                break;
                            case 106:
                                next();
                                state = 79;
                                break;
                            case 82:
                                next();
                                state = 79;
                                break;
                            case 105:
                                next();
                                state = 79;
                                break;
                            case 104:
                                next();
                                state = 79;
                                break;
                            case 57:
                                next();
                                state = 79;
                                break;
                            case 103:
                                next();
                                state = 79;
                                break;
                            case 56:
                                next();
                                state = 79;
                                break;
                            case 102:
                                next();
                                state = 79;
                                break;
                            default:
                                m_semantic.module(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 99:
                        switch (c) {
                            case 81:
                                next();
                                state = 79;
                                break;
                            case 49:
                                next();
                                state = 79;
                                break;
                            case 71:
                                next();
                                state = 79;
                                break;
                            case 118:
                                next();
                                state = 79;
                                break;
                            case 72:
                                next();
                                state = 79;
                                break;
                            case 119:
                                next();
                                state = 79;
                                break;
                            case 74:
                                next();
                                state = 79;
                                break;
                            case 121:
                                next();
                                state = 79;
                                break;
                            case 75:
                                next();
                                state = 79;
                                break;
                            case 122:
                                next();
                                state = 79;
                                break;
                            case 73:
                                next();
                                state = 79;
                                break;
                            case 120:
                                next();
                                state = 79;
                                break;
                            case 95:
                                next();
                                state = 79;
                                break;
                            case 48:
                                next();
                                state = 79;
                                break;
                            case 70:
                                next();
                                state = 79;
                                break;
                            case 117:
                                next();
                                state = 79;
                                break;
                            case 55:
                                next();
                                state = 79;
                                break;
                            case 98:
                                next();
                                state = 79;
                                break;
                            case 51:
                                next();
                                state = 79;
                                break;
                            case 50:
                                next();
                                state = 79;
                                break;
                            case 97:
                                next();
                                state = 79;
                                break;
                            case 80:
                                next();
                                state = 79;
                                break;
                            case 79:
                                next();
                                state = 79;
                                break;
                            case 78:
                                next();
                                state = 79;
                                break;
                            case 77:
                                next();
                                state = 79;
                                break;
                            case 76:
                                next();
                                state = 79;
                                break;
                            case 65:
                                next();
                                state = 79;
                                break;
                            case 112:
                                next();
                                state = 79;
                                break;
                            case 88:
                                next();
                                state = 79;
                                break;
                            case 89:
                                next();
                                state = 79;
                                break;
                            case 66:
                                next();
                                state = 79;
                                break;
                            case 113:
                                next();
                                state = 79;
                                break;
                            case 87:
                                next();
                                state = 79;
                                break;
                            case 116:
                                next();
                                state = 79;
                                break;
                            case 69:
                                next();
                                state = 79;
                                break;
                            case 115:
                                next();
                                state = 79;
                                break;
                            case 68:
                                next();
                                state = 79;
                                break;
                            case 114:
                                next();
                                state = 79;
                                break;
                            case 67:
                                next();
                                state = 79;
                                break;
                            case 90:
                                next();
                                state = 79;
                                break;
                            case 99:
                                next();
                                state = 79;
                                break;
                            case 52:
                                next();
                                state = 79;
                                break;
                            case 100:
                                next();
                                state = 100;
                                break;
                            case 53:
                                next();
                                state = 79;
                                break;
                            case 101:
                                next();
                                state = 79;
                                break;
                            case 54:
                                next();
                                state = 79;
                                break;
                            case 111:
                                next();
                                state = 79;
                                break;
                            case 110:
                                next();
                                state = 79;
                                break;
                            case 86:
                                next();
                                state = 79;
                                break;
                            case 109:
                                next();
                                state = 79;
                                break;
                            case 85:
                                next();
                                state = 79;
                                break;
                            case 108:
                                next();
                                state = 79;
                                break;
                            case 84:
                                next();
                                state = 79;
                                break;
                            case 107:
                                next();
                                state = 79;
                                break;
                            case 83:
                                next();
                                state = 79;
                                break;
                            case 106:
                                next();
                                state = 79;
                                break;
                            case 82:
                                next();
                                state = 79;
                                break;
                            case 105:
                                next();
                                state = 79;
                                break;
                            case 104:
                                next();
                                state = 79;
                                break;
                            case 57:
                                next();
                                state = 79;
                                break;
                            case 103:
                                next();
                                state = 79;
                                break;
                            case 56:
                                next();
                                state = 79;
                                break;
                            case 102:
                                next();
                                state = 79;
                                break;
                            default:
                                m_semantic.id(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 100:
                        switch (c) {
                            case 81:
                                next();
                                state = 79;
                                break;
                            case 49:
                                next();
                                state = 79;
                                break;
                            case 71:
                                next();
                                state = 79;
                                break;
                            case 118:
                                next();
                                state = 79;
                                break;
                            case 72:
                                next();
                                state = 79;
                                break;
                            case 119:
                                next();
                                state = 79;
                                break;
                            case 74:
                                next();
                                state = 79;
                                break;
                            case 121:
                                next();
                                state = 79;
                                break;
                            case 75:
                                next();
                                state = 79;
                                break;
                            case 122:
                                next();
                                state = 79;
                                break;
                            case 73:
                                next();
                                state = 79;
                                break;
                            case 120:
                                next();
                                state = 79;
                                break;
                            case 95:
                                next();
                                state = 79;
                                break;
                            case 48:
                                next();
                                state = 79;
                                break;
                            case 70:
                                next();
                                state = 79;
                                break;
                            case 117:
                                next();
                                state = 79;
                                break;
                            case 55:
                                next();
                                state = 79;
                                break;
                            case 98:
                                next();
                                state = 79;
                                break;
                            case 51:
                                next();
                                state = 79;
                                break;
                            case 50:
                                next();
                                state = 79;
                                break;
                            case 97:
                                next();
                                state = 79;
                                break;
                            case 80:
                                next();
                                state = 79;
                                break;
                            case 79:
                                next();
                                state = 79;
                                break;
                            case 78:
                                next();
                                state = 79;
                                break;
                            case 77:
                                next();
                                state = 79;
                                break;
                            case 76:
                                next();
                                state = 79;
                                break;
                            case 65:
                                next();
                                state = 79;
                                break;
                            case 112:
                                next();
                                state = 79;
                                break;
                            case 88:
                                next();
                                state = 79;
                                break;
                            case 89:
                                next();
                                state = 79;
                                break;
                            case 66:
                                next();
                                state = 79;
                                break;
                            case 113:
                                next();
                                state = 79;
                                break;
                            case 87:
                                next();
                                state = 79;
                                break;
                            case 116:
                                next();
                                state = 79;
                                break;
                            case 69:
                                next();
                                state = 79;
                                break;
                            case 115:
                                next();
                                state = 79;
                                break;
                            case 68:
                                next();
                                state = 79;
                                break;
                            case 114:
                                next();
                                state = 79;
                                break;
                            case 67:
                                next();
                                state = 79;
                                break;
                            case 90:
                                next();
                                state = 79;
                                break;
                            case 99:
                                next();
                                state = 79;
                                break;
                            case 52:
                                next();
                                state = 79;
                                break;
                            case 100:
                                next();
                                state = 79;
                                break;
                            case 53:
                                next();
                                state = 79;
                                break;
                            case 101:
                                next();
                                state = 79;
                                break;
                            case 54:
                                next();
                                state = 79;
                                break;
                            case 111:
                                next();
                                state = 79;
                                break;
                            case 110:
                                next();
                                state = 79;
                                break;
                            case 86:
                                next();
                                state = 79;
                                break;
                            case 109:
                                next();
                                state = 79;
                                break;
                            case 85:
                                next();
                                state = 79;
                                break;
                            case 108:
                                next();
                                state = 79;
                                break;
                            case 84:
                                next();
                                state = 79;
                                break;
                            case 107:
                                next();
                                state = 79;
                                break;
                            case 83:
                                next();
                                state = 79;
                                break;
                            case 106:
                                next();
                                state = 79;
                                break;
                            case 82:
                                next();
                                state = 79;
                                break;
                            case 105:
                                next();
                                state = 79;
                                break;
                            case 104:
                                next();
                                state = 79;
                                break;
                            case 57:
                                next();
                                state = 79;
                                break;
                            case 103:
                                next();
                                state = 79;
                                break;
                            case 56:
                                next();
                                state = 79;
                                break;
                            case 102:
                                next();
                                state = 79;
                                break;
                            default:
                                m_semantic.record(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 101:
                        switch (c) {
                            case 103:
                                next();
                                state = 79;
                                break;
                            case 57:
                                next();
                                state = 79;
                                break;
                            case 104:
                                next();
                                state = 79;
                                break;
                            case 105:
                                next();
                                state = 79;
                                break;
                            case 82:
                                next();
                                state = 79;
                                break;
                            case 106:
                                next();
                                state = 79;
                                break;
                            case 83:
                                next();
                                state = 79;
                                break;
                            case 107:
                                next();
                                state = 79;
                                break;
                            case 84:
                                next();
                                state = 79;
                                break;
                            case 108:
                                next();
                                state = 79;
                                break;
                            case 85:
                                next();
                                state = 79;
                                break;
                            case 109:
                                next();
                                state = 79;
                                break;
                            case 111:
                                next();
                                state = 79;
                                break;
                            case 110:
                                next();
                                state = 79;
                                break;
                            case 55:
                                next();
                                state = 79;
                                break;
                            case 102:
                                next();
                                state = 79;
                                break;
                            case 54:
                                next();
                                state = 79;
                                break;
                            case 81:
                                next();
                                state = 79;
                                break;
                            case 56:
                                next();
                                state = 79;
                                break;
                            case 86:
                                next();
                                state = 79;
                                break;
                            case 70:
                                next();
                                state = 79;
                                break;
                            case 117:
                                next();
                                state = 79;
                                break;
                            case 48:
                                next();
                                state = 79;
                                break;
                            case 95:
                                next();
                                state = 79;
                                break;
                            case 71:
                                next();
                                state = 79;
                                break;
                            case 118:
                                next();
                                state = 79;
                                break;
                            case 97:
                                next();
                                state = 79;
                                break;
                            case 50:
                                next();
                                state = 79;
                                break;
                            case 51:
                                next();
                                state = 79;
                                break;
                            case 98:
                                next();
                                state = 79;
                                break;
                            case 120:
                                next();
                                state = 79;
                                break;
                            case 73:
                                next();
                                state = 79;
                                break;
                            case 74:
                                next();
                                state = 79;
                                break;
                            case 121:
                                next();
                                state = 79;
                                break;
                            case 49:
                                next();
                                state = 79;
                                break;
                            case 72:
                                next();
                                state = 79;
                                break;
                            case 119:
                                next();
                                state = 79;
                                break;
                            case 75:
                                next();
                                state = 79;
                                break;
                            case 122:
                                next();
                                state = 79;
                                break;
                            case 80:
                                next();
                                state = 79;
                                break;
                            case 79:
                                next();
                                state = 79;
                                break;
                            case 78:
                                next();
                                state = 79;
                                break;
                            case 77:
                                next();
                                state = 79;
                                break;
                            case 76:
                                next();
                                state = 79;
                                break;
                            case 65:
                                next();
                                state = 79;
                                break;
                            case 112:
                                next();
                                state = 79;
                                break;
                            case 88:
                                next();
                                state = 79;
                                break;
                            case 89:
                                next();
                                state = 79;
                                break;
                            case 66:
                                next();
                                state = 79;
                                break;
                            case 113:
                                next();
                                state = 79;
                                break;
                            case 87:
                                next();
                                state = 79;
                                break;
                            case 116:
                                next();
                                state = 79;
                                break;
                            case 69:
                                next();
                                state = 79;
                                break;
                            case 115:
                                next();
                                state = 79;
                                break;
                            case 68:
                                next();
                                state = 79;
                                break;
                            case 114:
                                next();
                                state = 79;
                                break;
                            case 67:
                                next();
                                state = 79;
                                break;
                            case 90:
                                next();
                                state = 79;
                                break;
                            case 99:
                                next();
                                state = 79;
                                break;
                            case 52:
                                next();
                                state = 79;
                                break;
                            case 100:
                                next();
                                state = 79;
                                break;
                            case 53:
                                next();
                                state = 79;
                                break;
                            case 101:
                                next();
                                state = 85;
                                break;
                            default:
                                m_semantic.id(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 102:
                        switch (c) {
                            case 81:
                                next();
                                state = 79;
                                break;
                            case 49:
                                next();
                                state = 79;
                                break;
                            case 71:
                                next();
                                state = 79;
                                break;
                            case 118:
                                next();
                                state = 79;
                                break;
                            case 72:
                                next();
                                state = 79;
                                break;
                            case 119:
                                next();
                                state = 79;
                                break;
                            case 74:
                                next();
                                state = 79;
                                break;
                            case 121:
                                next();
                                state = 79;
                                break;
                            case 75:
                                next();
                                state = 79;
                                break;
                            case 122:
                                next();
                                state = 79;
                                break;
                            case 73:
                                next();
                                state = 79;
                                break;
                            case 120:
                                next();
                                state = 79;
                                break;
                            case 95:
                                next();
                                state = 79;
                                break;
                            case 48:
                                next();
                                state = 79;
                                break;
                            case 70:
                                next();
                                state = 79;
                                break;
                            case 117:
                                next();
                                state = 79;
                                break;
                            case 55:
                                next();
                                state = 79;
                                break;
                            case 98:
                                next();
                                state = 79;
                                break;
                            case 51:
                                next();
                                state = 79;
                                break;
                            case 50:
                                next();
                                state = 79;
                                break;
                            case 97:
                                next();
                                state = 79;
                                break;
                            case 80:
                                next();
                                state = 79;
                                break;
                            case 79:
                                next();
                                state = 79;
                                break;
                            case 78:
                                next();
                                state = 79;
                                break;
                            case 77:
                                next();
                                state = 79;
                                break;
                            case 76:
                                next();
                                state = 79;
                                break;
                            case 65:
                                next();
                                state = 79;
                                break;
                            case 112:
                                next();
                                state = 79;
                                break;
                            case 88:
                                next();
                                state = 79;
                                break;
                            case 89:
                                next();
                                state = 79;
                                break;
                            case 66:
                                next();
                                state = 79;
                                break;
                            case 113:
                                next();
                                state = 79;
                                break;
                            case 87:
                                next();
                                state = 79;
                                break;
                            case 116:
                                next();
                                state = 79;
                                break;
                            case 69:
                                next();
                                state = 79;
                                break;
                            case 115:
                                next();
                                state = 79;
                                break;
                            case 68:
                                next();
                                state = 79;
                                break;
                            case 114:
                                next();
                                state = 79;
                                break;
                            case 67:
                                next();
                                state = 79;
                                break;
                            case 90:
                                next();
                                state = 79;
                                break;
                            case 99:
                                next();
                                state = 79;
                                break;
                            case 52:
                                next();
                                state = 79;
                                break;
                            case 100:
                                next();
                                state = 79;
                                break;
                            case 53:
                                next();
                                state = 79;
                                break;
                            case 101:
                                next();
                                state = 79;
                                break;
                            case 54:
                                next();
                                state = 79;
                                break;
                            case 111:
                                next();
                                state = 79;
                                break;
                            case 110:
                                next();
                                state = 79;
                                break;
                            case 86:
                                next();
                                state = 79;
                                break;
                            case 109:
                                next();
                                state = 79;
                                break;
                            case 85:
                                next();
                                state = 79;
                                break;
                            case 108:
                                next();
                                state = 79;
                                break;
                            case 84:
                                next();
                                state = 79;
                                break;
                            case 107:
                                next();
                                state = 79;
                                break;
                            case 83:
                                next();
                                state = 79;
                                break;
                            case 106:
                                next();
                                state = 79;
                                break;
                            case 82:
                                next();
                                state = 79;
                                break;
                            case 105:
                                next();
                                state = 79;
                                break;
                            case 104:
                                next();
                                state = 79;
                                break;
                            case 57:
                                next();
                                state = 79;
                                break;
                            case 103:
                                next();
                                state = 79;
                                break;
                            case 56:
                                next();
                                state = 79;
                                break;
                            case 102:
                                next();
                                state = 79;
                                break;
                            default:
                                m_semantic.begin(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 103:
                        switch (c) {
                            case 81:
                                next();
                                state = 79;
                                break;
                            case 49:
                                next();
                                state = 79;
                                break;
                            case 71:
                                next();
                                state = 79;
                                break;
                            case 118:
                                next();
                                state = 79;
                                break;
                            case 72:
                                next();
                                state = 79;
                                break;
                            case 119:
                                next();
                                state = 79;
                                break;
                            case 74:
                                next();
                                state = 79;
                                break;
                            case 121:
                                next();
                                state = 79;
                                break;
                            case 75:
                                next();
                                state = 79;
                                break;
                            case 122:
                                next();
                                state = 79;
                                break;
                            case 73:
                                next();
                                state = 79;
                                break;
                            case 120:
                                next();
                                state = 79;
                                break;
                            case 95:
                                next();
                                state = 79;
                                break;
                            case 48:
                                next();
                                state = 79;
                                break;
                            case 70:
                                next();
                                state = 79;
                                break;
                            case 117:
                                next();
                                state = 79;
                                break;
                            case 55:
                                next();
                                state = 79;
                                break;
                            case 98:
                                next();
                                state = 79;
                                break;
                            case 51:
                                next();
                                state = 79;
                                break;
                            case 50:
                                next();
                                state = 79;
                                break;
                            case 97:
                                next();
                                state = 79;
                                break;
                            case 80:
                                next();
                                state = 79;
                                break;
                            case 79:
                                next();
                                state = 79;
                                break;
                            case 78:
                                next();
                                state = 79;
                                break;
                            case 77:
                                next();
                                state = 79;
                                break;
                            case 76:
                                next();
                                state = 79;
                                break;
                            case 65:
                                next();
                                state = 79;
                                break;
                            case 112:
                                next();
                                state = 79;
                                break;
                            case 88:
                                next();
                                state = 79;
                                break;
                            case 89:
                                next();
                                state = 79;
                                break;
                            case 66:
                                next();
                                state = 79;
                                break;
                            case 113:
                                next();
                                state = 79;
                                break;
                            case 87:
                                next();
                                state = 79;
                                break;
                            case 116:
                                next();
                                state = 79;
                                break;
                            case 69:
                                next();
                                state = 79;
                                break;
                            case 115:
                                next();
                                state = 79;
                                break;
                            case 68:
                                next();
                                state = 79;
                                break;
                            case 114:
                                next();
                                state = 79;
                                break;
                            case 67:
                                next();
                                state = 79;
                                break;
                            case 90:
                                next();
                                state = 79;
                                break;
                            case 99:
                                next();
                                state = 79;
                                break;
                            case 52:
                                next();
                                state = 79;
                                break;
                            case 100:
                                next();
                                state = 79;
                                break;
                            case 53:
                                next();
                                state = 79;
                                break;
                            case 101:
                                next();
                                state = 79;
                                break;
                            case 54:
                                next();
                                state = 79;
                                break;
                            case 111:
                                next();
                                state = 79;
                                break;
                            case 110:
                                next();
                                state = 79;
                                break;
                            case 86:
                                next();
                                state = 79;
                                break;
                            case 109:
                                next();
                                state = 79;
                                break;
                            case 85:
                                next();
                                state = 79;
                                break;
                            case 108:
                                next();
                                state = 79;
                                break;
                            case 84:
                                next();
                                state = 79;
                                break;
                            case 107:
                                next();
                                state = 79;
                                break;
                            case 83:
                                next();
                                state = 79;
                                break;
                            case 106:
                                next();
                                state = 79;
                                break;
                            case 82:
                                next();
                                state = 79;
                                break;
                            case 105:
                                next();
                                state = 104;
                                break;
                            case 104:
                                next();
                                state = 79;
                                break;
                            case 57:
                                next();
                                state = 79;
                                break;
                            case 103:
                                next();
                                state = 79;
                                break;
                            case 56:
                                next();
                                state = 79;
                                break;
                            case 102:
                                next();
                                state = 79;
                                break;
                            default:
                                m_semantic.id(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 104:
                        switch (c) {
                            case 81:
                                next();
                                state = 79;
                                break;
                            case 49:
                                next();
                                state = 79;
                                break;
                            case 71:
                                next();
                                state = 79;
                                break;
                            case 118:
                                next();
                                state = 79;
                                break;
                            case 72:
                                next();
                                state = 79;
                                break;
                            case 119:
                                next();
                                state = 79;
                                break;
                            case 74:
                                next();
                                state = 79;
                                break;
                            case 121:
                                next();
                                state = 79;
                                break;
                            case 75:
                                next();
                                state = 79;
                                break;
                            case 122:
                                next();
                                state = 79;
                                break;
                            case 73:
                                next();
                                state = 79;
                                break;
                            case 120:
                                next();
                                state = 79;
                                break;
                            case 95:
                                next();
                                state = 79;
                                break;
                            case 48:
                                next();
                                state = 79;
                                break;
                            case 70:
                                next();
                                state = 79;
                                break;
                            case 117:
                                next();
                                state = 79;
                                break;
                            case 55:
                                next();
                                state = 79;
                                break;
                            case 98:
                                next();
                                state = 79;
                                break;
                            case 51:
                                next();
                                state = 79;
                                break;
                            case 50:
                                next();
                                state = 79;
                                break;
                            case 97:
                                next();
                                state = 79;
                                break;
                            case 80:
                                next();
                                state = 79;
                                break;
                            case 79:
                                next();
                                state = 79;
                                break;
                            case 78:
                                next();
                                state = 79;
                                break;
                            case 77:
                                next();
                                state = 79;
                                break;
                            case 76:
                                next();
                                state = 79;
                                break;
                            case 65:
                                next();
                                state = 79;
                                break;
                            case 112:
                                next();
                                state = 79;
                                break;
                            case 88:
                                next();
                                state = 79;
                                break;
                            case 89:
                                next();
                                state = 79;
                                break;
                            case 66:
                                next();
                                state = 79;
                                break;
                            case 113:
                                next();
                                state = 79;
                                break;
                            case 87:
                                next();
                                state = 79;
                                break;
                            case 116:
                                next();
                                state = 79;
                                break;
                            case 69:
                                next();
                                state = 79;
                                break;
                            case 115:
                                next();
                                state = 79;
                                break;
                            case 68:
                                next();
                                state = 79;
                                break;
                            case 114:
                                next();
                                state = 79;
                                break;
                            case 67:
                                next();
                                state = 79;
                                break;
                            case 90:
                                next();
                                state = 79;
                                break;
                            case 99:
                                next();
                                state = 79;
                                break;
                            case 52:
                                next();
                                state = 79;
                                break;
                            case 100:
                                next();
                                state = 79;
                                break;
                            case 53:
                                next();
                                state = 79;
                                break;
                            case 101:
                                next();
                                state = 79;
                                break;
                            case 54:
                                next();
                                state = 79;
                                break;
                            case 110:
                                next();
                                state = 102;
                                break;
                            case 111:
                                next();
                                state = 79;
                                break;
                            case 86:
                                next();
                                state = 79;
                                break;
                            case 109:
                                next();
                                state = 79;
                                break;
                            case 85:
                                next();
                                state = 79;
                                break;
                            case 108:
                                next();
                                state = 79;
                                break;
                            case 84:
                                next();
                                state = 79;
                                break;
                            case 107:
                                next();
                                state = 79;
                                break;
                            case 83:
                                next();
                                state = 79;
                                break;
                            case 106:
                                next();
                                state = 79;
                                break;
                            case 82:
                                next();
                                state = 79;
                                break;
                            case 105:
                                next();
                                state = 79;
                                break;
                            case 104:
                                next();
                                state = 79;
                                break;
                            case 57:
                                next();
                                state = 79;
                                break;
                            case 103:
                                next();
                                state = 79;
                                break;
                            case 56:
                                next();
                                state = 79;
                                break;
                            case 102:
                                next();
                                state = 79;
                                break;
                            default:
                                m_semantic.id(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 105:
                        switch (c) {
                            case 49:
                                next();
                                state = 79;
                                break;
                            case 71:
                                next();
                                state = 79;
                                break;
                            case 118:
                                next();
                                state = 79;
                                break;
                            case 72:
                                next();
                                state = 79;
                                break;
                            case 119:
                                next();
                                state = 79;
                                break;
                            case 74:
                                next();
                                state = 79;
                                break;
                            case 121:
                                next();
                                state = 79;
                                break;
                            case 75:
                                next();
                                state = 79;
                                break;
                            case 122:
                                next();
                                state = 79;
                                break;
                            case 73:
                                next();
                                state = 79;
                                break;
                            case 120:
                                next();
                                state = 79;
                                break;
                            case 95:
                                next();
                                state = 79;
                                break;
                            case 48:
                                next();
                                state = 79;
                                break;
                            case 70:
                                next();
                                state = 79;
                                break;
                            case 117:
                                next();
                                state = 79;
                                break;
                            case 86:
                                next();
                                state = 79;
                                break;
                            case 56:
                                next();
                                state = 79;
                                break;
                            case 98:
                                next();
                                state = 79;
                                break;
                            case 51:
                                next();
                                state = 79;
                                break;
                            case 50:
                                next();
                                state = 79;
                                break;
                            case 97:
                                next();
                                state = 79;
                                break;
                            case 81:
                                next();
                                state = 79;
                                break;
                            case 80:
                                next();
                                state = 79;
                                break;
                            case 79:
                                next();
                                state = 79;
                                break;
                            case 78:
                                next();
                                state = 79;
                                break;
                            case 77:
                                next();
                                state = 79;
                                break;
                            case 76:
                                next();
                                state = 79;
                                break;
                            case 65:
                                next();
                                state = 79;
                                break;
                            case 112:
                                next();
                                state = 79;
                                break;
                            case 88:
                                next();
                                state = 79;
                                break;
                            case 89:
                                next();
                                state = 79;
                                break;
                            case 66:
                                next();
                                state = 79;
                                break;
                            case 113:
                                next();
                                state = 79;
                                break;
                            case 87:
                                next();
                                state = 79;
                                break;
                            case 116:
                                next();
                                state = 79;
                                break;
                            case 69:
                                next();
                                state = 79;
                                break;
                            case 115:
                                next();
                                state = 79;
                                break;
                            case 68:
                                next();
                                state = 79;
                                break;
                            case 114:
                                next();
                                state = 79;
                                break;
                            case 67:
                                next();
                                state = 79;
                                break;
                            case 90:
                                next();
                                state = 79;
                                break;
                            case 99:
                                next();
                                state = 79;
                                break;
                            case 52:
                                next();
                                state = 79;
                                break;
                            case 100:
                                next();
                                state = 79;
                                break;
                            case 53:
                                next();
                                state = 79;
                                break;
                            case 101:
                                next();
                                state = 79;
                                break;
                            case 54:
                                next();
                                state = 79;
                                break;
                            case 102:
                                next();
                                state = 79;
                                break;
                            case 55:
                                next();
                                state = 79;
                                break;
                            case 110:
                                next();
                                state = 79;
                                break;
                            case 111:
                                next();
                                state = 79;
                                break;
                            case 109:
                                next();
                                state = 79;
                                break;
                            case 85:
                                next();
                                state = 79;
                                break;
                            case 108:
                                next();
                                state = 79;
                                break;
                            case 84:
                                next();
                                state = 79;
                                break;
                            case 107:
                                next();
                                state = 79;
                                break;
                            case 83:
                                next();
                                state = 79;
                                break;
                            case 106:
                                next();
                                state = 79;
                                break;
                            case 82:
                                next();
                                state = 79;
                                break;
                            case 105:
                                next();
                                state = 79;
                                break;
                            case 104:
                                next();
                                state = 79;
                                break;
                            case 57:
                                next();
                                state = 79;
                                break;
                            case 103:
                                next();
                                state = 79;
                                break;
                            default:
                                m_semantic.id(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 106:
                        switch (c) {
                            case 81:
                                next();
                                state = 79;
                                break;
                            case 49:
                                next();
                                state = 79;
                                break;
                            case 71:
                                next();
                                state = 79;
                                break;
                            case 118:
                                next();
                                state = 79;
                                break;
                            case 72:
                                next();
                                state = 79;
                                break;
                            case 119:
                                next();
                                state = 79;
                                break;
                            case 74:
                                next();
                                state = 79;
                                break;
                            case 121:
                                next();
                                state = 79;
                                break;
                            case 75:
                                next();
                                state = 79;
                                break;
                            case 122:
                                next();
                                state = 79;
                                break;
                            case 73:
                                next();
                                state = 79;
                                break;
                            case 120:
                                next();
                                state = 79;
                                break;
                            case 95:
                                next();
                                state = 79;
                                break;
                            case 48:
                                next();
                                state = 79;
                                break;
                            case 70:
                                next();
                                state = 79;
                                break;
                            case 117:
                                next();
                                state = 79;
                                break;
                            case 55:
                                next();
                                state = 79;
                                break;
                            case 98:
                                next();
                                state = 79;
                                break;
                            case 51:
                                next();
                                state = 79;
                                break;
                            case 50:
                                next();
                                state = 79;
                                break;
                            case 97:
                                next();
                                state = 79;
                                break;
                            case 80:
                                next();
                                state = 79;
                                break;
                            case 79:
                                next();
                                state = 79;
                                break;
                            case 78:
                                next();
                                state = 79;
                                break;
                            case 77:
                                next();
                                state = 79;
                                break;
                            case 76:
                                next();
                                state = 79;
                                break;
                            case 65:
                                next();
                                state = 79;
                                break;
                            case 112:
                                next();
                                state = 79;
                                break;
                            case 88:
                                next();
                                state = 79;
                                break;
                            case 89:
                                next();
                                state = 79;
                                break;
                            case 66:
                                next();
                                state = 79;
                                break;
                            case 113:
                                next();
                                state = 79;
                                break;
                            case 87:
                                next();
                                state = 79;
                                break;
                            case 116:
                                next();
                                state = 79;
                                break;
                            case 69:
                                next();
                                state = 79;
                                break;
                            case 115:
                                next();
                                state = 79;
                                break;
                            case 68:
                                next();
                                state = 79;
                                break;
                            case 114:
                                next();
                                state = 79;
                                break;
                            case 67:
                                next();
                                state = 79;
                                break;
                            case 90:
                                next();
                                state = 79;
                                break;
                            case 99:
                                next();
                                state = 79;
                                break;
                            case 52:
                                next();
                                state = 79;
                                break;
                            case 100:
                                next();
                                state = 79;
                                break;
                            case 53:
                                next();
                                state = 79;
                                break;
                            case 101:
                                next();
                                state = 79;
                                break;
                            case 54:
                                next();
                                state = 79;
                                break;
                            case 111:
                                next();
                                state = 79;
                                break;
                            case 110:
                                next();
                                state = 79;
                                break;
                            case 86:
                                next();
                                state = 79;
                                break;
                            case 109:
                                next();
                                state = 79;
                                break;
                            case 85:
                                next();
                                state = 79;
                                break;
                            case 108:
                                next();
                                state = 79;
                                break;
                            case 84:
                                next();
                                state = 79;
                                break;
                            case 107:
                                next();
                                state = 79;
                                break;
                            case 83:
                                next();
                                state = 79;
                                break;
                            case 106:
                                next();
                                state = 79;
                                break;
                            case 82:
                                next();
                                state = 79;
                                break;
                            case 105:
                                next();
                                state = 79;
                                break;
                            case 104:
                                next();
                                state = 79;
                                break;
                            case 57:
                                next();
                                state = 79;
                                break;
                            case 103:
                                next();
                                state = 79;
                                break;
                            case 56:
                                next();
                                state = 79;
                                break;
                            case 102:
                                next();
                                state = 79;
                                break;
                            default:
                                m_semantic.andd(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 107:
                        switch (c) {
                            case 81:
                                next();
                                state = 79;
                                break;
                            case 49:
                                next();
                                state = 79;
                                break;
                            case 71:
                                next();
                                state = 79;
                                break;
                            case 118:
                                next();
                                state = 79;
                                break;
                            case 72:
                                next();
                                state = 79;
                                break;
                            case 119:
                                next();
                                state = 79;
                                break;
                            case 74:
                                next();
                                state = 79;
                                break;
                            case 121:
                                next();
                                state = 79;
                                break;
                            case 75:
                                next();
                                state = 79;
                                break;
                            case 122:
                                next();
                                state = 79;
                                break;
                            case 73:
                                next();
                                state = 79;
                                break;
                            case 120:
                                next();
                                state = 79;
                                break;
                            case 95:
                                next();
                                state = 79;
                                break;
                            case 48:
                                next();
                                state = 79;
                                break;
                            case 70:
                                next();
                                state = 79;
                                break;
                            case 117:
                                next();
                                state = 79;
                                break;
                            case 55:
                                next();
                                state = 79;
                                break;
                            case 98:
                                next();
                                state = 79;
                                break;
                            case 51:
                                next();
                                state = 79;
                                break;
                            case 50:
                                next();
                                state = 79;
                                break;
                            case 97:
                                next();
                                state = 79;
                                break;
                            case 80:
                                next();
                                state = 79;
                                break;
                            case 79:
                                next();
                                state = 79;
                                break;
                            case 78:
                                next();
                                state = 79;
                                break;
                            case 77:
                                next();
                                state = 79;
                                break;
                            case 76:
                                next();
                                state = 79;
                                break;
                            case 65:
                                next();
                                state = 79;
                                break;
                            case 112:
                                next();
                                state = 79;
                                break;
                            case 88:
                                next();
                                state = 79;
                                break;
                            case 89:
                                next();
                                state = 79;
                                break;
                            case 66:
                                next();
                                state = 79;
                                break;
                            case 113:
                                next();
                                state = 79;
                                break;
                            case 87:
                                next();
                                state = 79;
                                break;
                            case 116:
                                next();
                                state = 79;
                                break;
                            case 69:
                                next();
                                state = 79;
                                break;
                            case 115:
                                next();
                                state = 79;
                                break;
                            case 68:
                                next();
                                state = 79;
                                break;
                            case 114:
                                next();
                                state = 79;
                                break;
                            case 67:
                                next();
                                state = 79;
                                break;
                            case 90:
                                next();
                                state = 79;
                                break;
                            case 99:
                                next();
                                state = 79;
                                break;
                            case 52:
                                next();
                                state = 79;
                                break;
                            case 100:
                                next();
                                state = 79;
                                break;
                            case 53:
                                next();
                                state = 79;
                                break;
                            case 101:
                                next();
                                state = 79;
                                break;
                            case 54:
                                next();
                                state = 79;
                                break;
                            case 111:
                                next();
                                state = 79;
                                break;
                            case 110:
                                next();
                                state = 79;
                                break;
                            case 86:
                                next();
                                state = 79;
                                break;
                            case 109:
                                next();
                                state = 79;
                                break;
                            case 85:
                                next();
                                state = 79;
                                break;
                            case 108:
                                next();
                                state = 79;
                                break;
                            case 84:
                                next();
                                state = 79;
                                break;
                            case 107:
                                next();
                                state = 79;
                                break;
                            case 83:
                                next();
                                state = 79;
                                break;
                            case 106:
                                next();
                                state = 79;
                                break;
                            case 82:
                                next();
                                state = 79;
                                break;
                            case 105:
                                next();
                                state = 79;
                                break;
                            case 104:
                                next();
                                state = 79;
                                break;
                            case 57:
                                next();
                                state = 79;
                                break;
                            case 103:
                                next();
                                state = 79;
                                break;
                            case 56:
                                next();
                                state = 79;
                                break;
                            case 102:
                                next();
                                state = 79;
                                break;
                            default:
                                m_semantic.div(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 108:
                        m_semantic.realdiv(m_lexeme.str());
                        return true;
                    case 109:
                        m_semantic.eq(m_lexeme.str());
                        return true;
                    case 110:
                        switch (c) {
                            case 103:
                                next();
                                state = 79;
                                break;
                            case 57:
                                next();
                                state = 79;
                                break;
                            case 104:
                                next();
                                state = 88;
                                break;
                            case 105:
                                next();
                                state = 79;
                                break;
                            case 82:
                                next();
                                state = 79;
                                break;
                            case 106:
                                next();
                                state = 79;
                                break;
                            case 83:
                                next();
                                state = 79;
                                break;
                            case 107:
                                next();
                                state = 79;
                                break;
                            case 84:
                                next();
                                state = 79;
                                break;
                            case 108:
                                next();
                                state = 79;
                                break;
                            case 85:
                                next();
                                state = 79;
                                break;
                            case 109:
                                next();
                                state = 79;
                                break;
                            case 111:
                                next();
                                state = 114;
                                break;
                            case 110:
                                next();
                                state = 79;
                                break;
                            case 55:
                                next();
                                state = 79;
                                break;
                            case 102:
                                next();
                                state = 79;
                                break;
                            case 54:
                                next();
                                state = 79;
                                break;
                            case 81:
                                next();
                                state = 79;
                                break;
                            case 56:
                                next();
                                state = 79;
                                break;
                            case 86:
                                next();
                                state = 79;
                                break;
                            case 70:
                                next();
                                state = 79;
                                break;
                            case 117:
                                next();
                                state = 79;
                                break;
                            case 48:
                                next();
                                state = 79;
                                break;
                            case 95:
                                next();
                                state = 79;
                                break;
                            case 71:
                                next();
                                state = 79;
                                break;
                            case 118:
                                next();
                                state = 79;
                                break;
                            case 97:
                                next();
                                state = 79;
                                break;
                            case 50:
                                next();
                                state = 79;
                                break;
                            case 51:
                                next();
                                state = 79;
                                break;
                            case 98:
                                next();
                                state = 79;
                                break;
                            case 120:
                                next();
                                state = 79;
                                break;
                            case 73:
                                next();
                                state = 79;
                                break;
                            case 74:
                                next();
                                state = 79;
                                break;
                            case 121:
                                next();
                                state = 10;
                                break;
                            case 49:
                                next();
                                state = 79;
                                break;
                            case 72:
                                next();
                                state = 79;
                                break;
                            case 119:
                                next();
                                state = 79;
                                break;
                            case 75:
                                next();
                                state = 79;
                                break;
                            case 122:
                                next();
                                state = 79;
                                break;
                            case 80:
                                next();
                                state = 79;
                                break;
                            case 79:
                                next();
                                state = 79;
                                break;
                            case 78:
                                next();
                                state = 79;
                                break;
                            case 77:
                                next();
                                state = 79;
                                break;
                            case 76:
                                next();
                                state = 79;
                                break;
                            case 65:
                                next();
                                state = 79;
                                break;
                            case 112:
                                next();
                                state = 79;
                                break;
                            case 88:
                                next();
                                state = 79;
                                break;
                            case 89:
                                next();
                                state = 79;
                                break;
                            case 66:
                                next();
                                state = 79;
                                break;
                            case 113:
                                next();
                                state = 79;
                                break;
                            case 87:
                                next();
                                state = 79;
                                break;
                            case 116:
                                next();
                                state = 79;
                                break;
                            case 69:
                                next();
                                state = 79;
                                break;
                            case 115:
                                next();
                                state = 79;
                                break;
                            case 68:
                                next();
                                state = 79;
                                break;
                            case 114:
                                next();
                                state = 79;
                                break;
                            case 67:
                                next();
                                state = 79;
                                break;
                            case 90:
                                next();
                                state = 79;
                                break;
                            case 99:
                                next();
                                state = 79;
                                break;
                            case 52:
                                next();
                                state = 79;
                                break;
                            case 100:
                                next();
                                state = 79;
                                break;
                            case 53:
                                next();
                                state = 79;
                                break;
                            case 101:
                                next();
                                state = 79;
                                break;
                            default:
                                m_semantic.id(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 111:
                        switch (c) {
                            case 81:
                                next();
                                state = 79;
                                break;
                            case 49:
                                next();
                                state = 79;
                                break;
                            case 71:
                                next();
                                state = 79;
                                break;
                            case 118:
                                next();
                                state = 79;
                                break;
                            case 72:
                                next();
                                state = 79;
                                break;
                            case 119:
                                next();
                                state = 79;
                                break;
                            case 74:
                                next();
                                state = 79;
                                break;
                            case 121:
                                next();
                                state = 79;
                                break;
                            case 75:
                                next();
                                state = 79;
                                break;
                            case 122:
                                next();
                                state = 79;
                                break;
                            case 73:
                                next();
                                state = 79;
                                break;
                            case 120:
                                next();
                                state = 79;
                                break;
                            case 95:
                                next();
                                state = 79;
                                break;
                            case 48:
                                next();
                                state = 79;
                                break;
                            case 70:
                                next();
                                state = 79;
                                break;
                            case 117:
                                next();
                                state = 79;
                                break;
                            case 55:
                                next();
                                state = 79;
                                break;
                            case 98:
                                next();
                                state = 79;
                                break;
                            case 51:
                                next();
                                state = 79;
                                break;
                            case 50:
                                next();
                                state = 79;
                                break;
                            case 97:
                                next();
                                state = 79;
                                break;
                            case 80:
                                next();
                                state = 79;
                                break;
                            case 79:
                                next();
                                state = 79;
                                break;
                            case 78:
                                next();
                                state = 79;
                                break;
                            case 77:
                                next();
                                state = 79;
                                break;
                            case 76:
                                next();
                                state = 79;
                                break;
                            case 65:
                                next();
                                state = 79;
                                break;
                            case 112:
                                next();
                                state = 79;
                                break;
                            case 88:
                                next();
                                state = 79;
                                break;
                            case 89:
                                next();
                                state = 79;
                                break;
                            case 66:
                                next();
                                state = 79;
                                break;
                            case 113:
                                next();
                                state = 79;
                                break;
                            case 87:
                                next();
                                state = 79;
                                break;
                            case 116:
                                next();
                                state = 79;
                                break;
                            case 69:
                                next();
                                state = 79;
                                break;
                            case 115:
                                next();
                                state = 79;
                                break;
                            case 68:
                                next();
                                state = 79;
                                break;
                            case 114:
                                next();
                                state = 79;
                                break;
                            case 67:
                                next();
                                state = 79;
                                break;
                            case 90:
                                next();
                                state = 79;
                                break;
                            case 99:
                                next();
                                state = 79;
                                break;
                            case 52:
                                next();
                                state = 79;
                                break;
                            case 100:
                                next();
                                state = 79;
                                break;
                            case 53:
                                next();
                                state = 79;
                                break;
                            case 101:
                                next();
                                state = 79;
                                break;
                            case 54:
                                next();
                                state = 79;
                                break;
                            case 111:
                                next();
                                state = 79;
                                break;
                            case 110:
                                next();
                                state = 112;
                                break;
                            case 86:
                                next();
                                state = 79;
                                break;
                            case 109:
                                next();
                                state = 79;
                                break;
                            case 85:
                                next();
                                state = 79;
                                break;
                            case 108:
                                next();
                                state = 79;
                                break;
                            case 84:
                                next();
                                state = 79;
                                break;
                            case 107:
                                next();
                                state = 79;
                                break;
                            case 83:
                                next();
                                state = 79;
                                break;
                            case 106:
                                next();
                                state = 79;
                                break;
                            case 82:
                                next();
                                state = 79;
                                break;
                            case 105:
                                next();
                                state = 79;
                                break;
                            case 104:
                                next();
                                state = 79;
                                break;
                            case 57:
                                next();
                                state = 79;
                                break;
                            case 103:
                                next();
                                state = 79;
                                break;
                            case 56:
                                next();
                                state = 79;
                                break;
                            case 102:
                                next();
                                state = 79;
                                break;
                            default:
                                m_semantic.id(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 112:
                        switch (c) {
                            case 81:
                                next();
                                state = 79;
                                break;
                            case 49:
                                next();
                                state = 79;
                                break;
                            case 71:
                                next();
                                state = 79;
                                break;
                            case 118:
                                next();
                                state = 79;
                                break;
                            case 72:
                                next();
                                state = 79;
                                break;
                            case 119:
                                next();
                                state = 79;
                                break;
                            case 74:
                                next();
                                state = 79;
                                break;
                            case 121:
                                next();
                                state = 79;
                                break;
                            case 75:
                                next();
                                state = 79;
                                break;
                            case 122:
                                next();
                                state = 79;
                                break;
                            case 73:
                                next();
                                state = 79;
                                break;
                            case 120:
                                next();
                                state = 79;
                                break;
                            case 95:
                                next();
                                state = 79;
                                break;
                            case 48:
                                next();
                                state = 79;
                                break;
                            case 70:
                                next();
                                state = 79;
                                break;
                            case 117:
                                next();
                                state = 79;
                                break;
                            case 55:
                                next();
                                state = 79;
                                break;
                            case 98:
                                next();
                                state = 79;
                                break;
                            case 51:
                                next();
                                state = 79;
                                break;
                            case 50:
                                next();
                                state = 79;
                                break;
                            case 97:
                                next();
                                state = 79;
                                break;
                            case 80:
                                next();
                                state = 79;
                                break;
                            case 79:
                                next();
                                state = 79;
                                break;
                            case 78:
                                next();
                                state = 79;
                                break;
                            case 77:
                                next();
                                state = 79;
                                break;
                            case 76:
                                next();
                                state = 79;
                                break;
                            case 65:
                                next();
                                state = 79;
                                break;
                            case 112:
                                next();
                                state = 79;
                                break;
                            case 88:
                                next();
                                state = 79;
                                break;
                            case 89:
                                next();
                                state = 79;
                                break;
                            case 66:
                                next();
                                state = 79;
                                break;
                            case 113:
                                next();
                                state = 79;
                                break;
                            case 87:
                                next();
                                state = 79;
                                break;
                            case 116:
                                next();
                                state = 79;
                                break;
                            case 69:
                                next();
                                state = 79;
                                break;
                            case 115:
                                next();
                                state = 79;
                                break;
                            case 68:
                                next();
                                state = 79;
                                break;
                            case 114:
                                next();
                                state = 79;
                                break;
                            case 67:
                                next();
                                state = 79;
                                break;
                            case 90:
                                next();
                                state = 79;
                                break;
                            case 99:
                                next();
                                state = 79;
                                break;
                            case 52:
                                next();
                                state = 79;
                                break;
                            case 100:
                                next();
                                state = 79;
                                break;
                            case 53:
                                next();
                                state = 79;
                                break;
                            case 101:
                                next();
                                state = 79;
                                break;
                            case 54:
                                next();
                                state = 79;
                                break;
                            case 111:
                                next();
                                state = 79;
                                break;
                            case 110:
                                next();
                                state = 79;
                                break;
                            case 86:
                                next();
                                state = 79;
                                break;
                            case 109:
                                next();
                                state = 79;
                                break;
                            case 85:
                                next();
                                state = 79;
                                break;
                            case 108:
                                next();
                                state = 79;
                                break;
                            case 84:
                                next();
                                state = 79;
                                break;
                            case 107:
                                next();
                                state = 79;
                                break;
                            case 83:
                                next();
                                state = 79;
                                break;
                            case 106:
                                next();
                                state = 79;
                                break;
                            case 82:
                                next();
                                state = 79;
                                break;
                            case 105:
                                next();
                                state = 79;
                                break;
                            case 104:
                                next();
                                state = 79;
                                break;
                            case 57:
                                next();
                                state = 79;
                                break;
                            case 103:
                                next();
                                state = 79;
                                break;
                            case 56:
                                next();
                                state = 79;
                                break;
                            case 102:
                                next();
                                state = 79;
                                break;
                            default:
                                m_semantic.then(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 113:
                        switch (c) {
                            case 49:
                                next();
                                state = 79;
                                break;
                            case 71:
                                next();
                                state = 79;
                                break;
                            case 118:
                                next();
                                state = 79;
                                break;
                            case 72:
                                next();
                                state = 79;
                                break;
                            case 119:
                                next();
                                state = 79;
                                break;
                            case 74:
                                next();
                                state = 79;
                                break;
                            case 121:
                                next();
                                state = 79;
                                break;
                            case 75:
                                next();
                                state = 79;
                                break;
                            case 122:
                                next();
                                state = 79;
                                break;
                            case 73:
                                next();
                                state = 79;
                                break;
                            case 120:
                                next();
                                state = 79;
                                break;
                            case 95:
                                next();
                                state = 79;
                                break;
                            case 48:
                                next();
                                state = 79;
                                break;
                            case 70:
                                next();
                                state = 79;
                                break;
                            case 117:
                                next();
                                state = 79;
                                break;
                            case 86:
                                next();
                                state = 79;
                                break;
                            case 57:
                                next();
                                state = 79;
                                break;
                            case 98:
                                next();
                                state = 79;
                                break;
                            case 51:
                                next();
                                state = 79;
                                break;
                            case 50:
                                next();
                                state = 79;
                                break;
                            case 97:
                                next();
                                state = 79;
                                break;
                            case 81:
                                next();
                                state = 79;
                                break;
                            case 80:
                                next();
                                state = 79;
                                break;
                            case 79:
                                next();
                                state = 79;
                                break;
                            case 78:
                                next();
                                state = 79;
                                break;
                            case 77:
                                next();
                                state = 79;
                                break;
                            case 76:
                                next();
                                state = 79;
                                break;
                            case 65:
                                next();
                                state = 79;
                                break;
                            case 112:
                                next();
                                state = 79;
                                break;
                            case 88:
                                next();
                                state = 79;
                                break;
                            case 87:
                                next();
                                state = 79;
                                break;
                            case 116:
                                next();
                                state = 79;
                                break;
                            case 69:
                                next();
                                state = 79;
                                break;
                            case 115:
                                next();
                                state = 79;
                                break;
                            case 68:
                                next();
                                state = 79;
                                break;
                            case 89:
                                next();
                                state = 79;
                                break;
                            case 66:
                                next();
                                state = 79;
                                break;
                            case 113:
                                next();
                                state = 79;
                                break;
                            case 90:
                                next();
                                state = 79;
                                break;
                            case 67:
                                next();
                                state = 79;
                                break;
                            case 114:
                                next();
                                state = 55;
                                break;
                            case 99:
                                next();
                                state = 79;
                                break;
                            case 52:
                                next();
                                state = 79;
                                break;
                            case 100:
                                next();
                                state = 79;
                                break;
                            case 53:
                                next();
                                state = 79;
                                break;
                            case 101:
                                next();
                                state = 79;
                                break;
                            case 54:
                                next();
                                state = 79;
                                break;
                            case 102:
                                next();
                                state = 79;
                                break;
                            case 55:
                                next();
                                state = 79;
                                break;
                            case 103:
                                next();
                                state = 79;
                                break;
                            case 56:
                                next();
                                state = 79;
                                break;
                            case 111:
                                next();
                                state = 79;
                                break;
                            case 110:
                                next();
                                state = 79;
                                break;
                            case 109:
                                next();
                                state = 79;
                                break;
                            case 85:
                                next();
                                state = 79;
                                break;
                            case 108:
                                next();
                                state = 79;
                                break;
                            case 84:
                                next();
                                state = 79;
                                break;
                            case 107:
                                next();
                                state = 79;
                                break;
                            case 83:
                                next();
                                state = 79;
                                break;
                            case 106:
                                next();
                                state = 79;
                                break;
                            case 82:
                                next();
                                state = 79;
                                break;
                            case 105:
                                next();
                                state = 79;
                                break;
                            case 104:
                                next();
                                state = 79;
                                break;
                            default:
                                m_semantic.id(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 114:
                        switch (c) {
                            case 81:
                                next();
                                state = 79;
                                break;
                            case 49:
                                next();
                                state = 79;
                                break;
                            case 71:
                                next();
                                state = 79;
                                break;
                            case 118:
                                next();
                                state = 79;
                                break;
                            case 72:
                                next();
                                state = 79;
                                break;
                            case 119:
                                next();
                                state = 79;
                                break;
                            case 74:
                                next();
                                state = 79;
                                break;
                            case 121:
                                next();
                                state = 79;
                                break;
                            case 75:
                                next();
                                state = 79;
                                break;
                            case 122:
                                next();
                                state = 79;
                                break;
                            case 73:
                                next();
                                state = 79;
                                break;
                            case 120:
                                next();
                                state = 79;
                                break;
                            case 95:
                                next();
                                state = 79;
                                break;
                            case 48:
                                next();
                                state = 79;
                                break;
                            case 70:
                                next();
                                state = 79;
                                break;
                            case 117:
                                next();
                                state = 79;
                                break;
                            case 55:
                                next();
                                state = 79;
                                break;
                            case 98:
                                next();
                                state = 79;
                                break;
                            case 51:
                                next();
                                state = 79;
                                break;
                            case 50:
                                next();
                                state = 79;
                                break;
                            case 97:
                                next();
                                state = 79;
                                break;
                            case 80:
                                next();
                                state = 79;
                                break;
                            case 79:
                                next();
                                state = 79;
                                break;
                            case 78:
                                next();
                                state = 79;
                                break;
                            case 77:
                                next();
                                state = 79;
                                break;
                            case 76:
                                next();
                                state = 79;
                                break;
                            case 65:
                                next();
                                state = 79;
                                break;
                            case 112:
                                next();
                                state = 79;
                                break;
                            case 88:
                                next();
                                state = 79;
                                break;
                            case 89:
                                next();
                                state = 79;
                                break;
                            case 66:
                                next();
                                state = 79;
                                break;
                            case 113:
                                next();
                                state = 79;
                                break;
                            case 87:
                                next();
                                state = 79;
                                break;
                            case 116:
                                next();
                                state = 79;
                                break;
                            case 69:
                                next();
                                state = 79;
                                break;
                            case 115:
                                next();
                                state = 79;
                                break;
                            case 68:
                                next();
                                state = 79;
                                break;
                            case 114:
                                next();
                                state = 79;
                                break;
                            case 67:
                                next();
                                state = 79;
                                break;
                            case 90:
                                next();
                                state = 79;
                                break;
                            case 99:
                                next();
                                state = 79;
                                break;
                            case 52:
                                next();
                                state = 79;
                                break;
                            case 100:
                                next();
                                state = 79;
                                break;
                            case 53:
                                next();
                                state = 79;
                                break;
                            case 101:
                                next();
                                state = 79;
                                break;
                            case 54:
                                next();
                                state = 79;
                                break;
                            case 111:
                                next();
                                state = 79;
                                break;
                            case 110:
                                next();
                                state = 79;
                                break;
                            case 86:
                                next();
                                state = 79;
                                break;
                            case 109:
                                next();
                                state = 79;
                                break;
                            case 85:
                                next();
                                state = 79;
                                break;
                            case 108:
                                next();
                                state = 79;
                                break;
                            case 84:
                                next();
                                state = 79;
                                break;
                            case 107:
                                next();
                                state = 79;
                                break;
                            case 83:
                                next();
                                state = 79;
                                break;
                            case 106:
                                next();
                                state = 79;
                                break;
                            case 82:
                                next();
                                state = 79;
                                break;
                            case 105:
                                next();
                                state = 79;
                                break;
                            case 104:
                                next();
                                state = 79;
                                break;
                            case 57:
                                next();
                                state = 79;
                                break;
                            case 103:
                                next();
                                state = 79;
                                break;
                            case 56:
                                next();
                                state = 79;
                                break;
                            case 102:
                                next();
                                state = 79;
                                break;
                            default:
                                m_semantic.to(m_lexeme.str());
                                return true;
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
