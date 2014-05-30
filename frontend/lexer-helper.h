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
            size_t state = 31;
            while (true) {
                c = peek();
                switch (state) {
                    case 0:
                        switch (c) {
                            case 81:
                                next();
                                state = 28;
                                break;
                            case 49:
                                next();
                                state = 28;
                                break;
                            case 71:
                                next();
                                state = 28;
                                break;
                            case 118:
                                next();
                                state = 28;
                                break;
                            case 72:
                                next();
                                state = 28;
                                break;
                            case 119:
                                next();
                                state = 28;
                                break;
                            case 74:
                                next();
                                state = 28;
                                break;
                            case 121:
                                next();
                                state = 28;
                                break;
                            case 75:
                                next();
                                state = 28;
                                break;
                            case 122:
                                next();
                                state = 28;
                                break;
                            case 73:
                                next();
                                state = 28;
                                break;
                            case 120:
                                next();
                                state = 28;
                                break;
                            case 95:
                                next();
                                state = 28;
                                break;
                            case 48:
                                next();
                                state = 28;
                                break;
                            case 70:
                                next();
                                state = 28;
                                break;
                            case 117:
                                next();
                                state = 28;
                                break;
                            case 55:
                                next();
                                state = 28;
                                break;
                            case 98:
                                next();
                                state = 28;
                                break;
                            case 51:
                                next();
                                state = 28;
                                break;
                            case 50:
                                next();
                                state = 28;
                                break;
                            case 97:
                                next();
                                state = 28;
                                break;
                            case 80:
                                next();
                                state = 28;
                                break;
                            case 79:
                                next();
                                state = 28;
                                break;
                            case 78:
                                next();
                                state = 28;
                                break;
                            case 77:
                                next();
                                state = 28;
                                break;
                            case 76:
                                next();
                                state = 28;
                                break;
                            case 65:
                                next();
                                state = 28;
                                break;
                            case 112:
                                next();
                                state = 28;
                                break;
                            case 88:
                                next();
                                state = 28;
                                break;
                            case 89:
                                next();
                                state = 28;
                                break;
                            case 66:
                                next();
                                state = 28;
                                break;
                            case 113:
                                next();
                                state = 28;
                                break;
                            case 87:
                                next();
                                state = 28;
                                break;
                            case 116:
                                next();
                                state = 28;
                                break;
                            case 69:
                                next();
                                state = 28;
                                break;
                            case 115:
                                next();
                                state = 28;
                                break;
                            case 68:
                                next();
                                state = 28;
                                break;
                            case 114:
                                next();
                                state = 28;
                                break;
                            case 67:
                                next();
                                state = 28;
                                break;
                            case 90:
                                next();
                                state = 28;
                                break;
                            case 99:
                                next();
                                state = 28;
                                break;
                            case 52:
                                next();
                                state = 28;
                                break;
                            case 100:
                                next();
                                state = 28;
                                break;
                            case 53:
                                next();
                                state = 28;
                                break;
                            case 101:
                                next();
                                state = 28;
                                break;
                            case 54:
                                next();
                                state = 28;
                                break;
                            case 111:
                                next();
                                state = 28;
                                break;
                            case 110:
                                next();
                                state = 28;
                                break;
                            case 86:
                                next();
                                state = 28;
                                break;
                            case 109:
                                next();
                                state = 28;
                                break;
                            case 85:
                                next();
                                state = 28;
                                break;
                            case 108:
                                next();
                                state = 28;
                                break;
                            case 84:
                                next();
                                state = 28;
                                break;
                            case 107:
                                next();
                                state = 28;
                                break;
                            case 83:
                                next();
                                state = 28;
                                break;
                            case 106:
                                next();
                                state = 28;
                                break;
                            case 82:
                                next();
                                state = 28;
                                break;
                            case 105:
                                next();
                                state = 28;
                                break;
                            case 104:
                                next();
                                state = 28;
                                break;
                            case 57:
                                next();
                                state = 28;
                                break;
                            case 103:
                                next();
                                state = 28;
                                break;
                            case 56:
                                next();
                                state = 28;
                                break;
                            case 102:
                                next();
                                state = 28;
                                break;
                            default:
                                m_semantic.begin(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 1:
                        switch (c) {
                            case 81:
                                next();
                                state = 28;
                                break;
                            case 49:
                                next();
                                state = 28;
                                break;
                            case 71:
                                next();
                                state = 28;
                                break;
                            case 118:
                                next();
                                state = 28;
                                break;
                            case 72:
                                next();
                                state = 28;
                                break;
                            case 119:
                                next();
                                state = 28;
                                break;
                            case 74:
                                next();
                                state = 28;
                                break;
                            case 121:
                                next();
                                state = 28;
                                break;
                            case 75:
                                next();
                                state = 28;
                                break;
                            case 122:
                                next();
                                state = 28;
                                break;
                            case 73:
                                next();
                                state = 28;
                                break;
                            case 120:
                                next();
                                state = 28;
                                break;
                            case 95:
                                next();
                                state = 28;
                                break;
                            case 48:
                                next();
                                state = 28;
                                break;
                            case 70:
                                next();
                                state = 28;
                                break;
                            case 117:
                                next();
                                state = 28;
                                break;
                            case 55:
                                next();
                                state = 28;
                                break;
                            case 98:
                                next();
                                state = 28;
                                break;
                            case 51:
                                next();
                                state = 28;
                                break;
                            case 50:
                                next();
                                state = 28;
                                break;
                            case 97:
                                next();
                                state = 28;
                                break;
                            case 80:
                                next();
                                state = 28;
                                break;
                            case 79:
                                next();
                                state = 28;
                                break;
                            case 78:
                                next();
                                state = 28;
                                break;
                            case 77:
                                next();
                                state = 28;
                                break;
                            case 76:
                                next();
                                state = 28;
                                break;
                            case 65:
                                next();
                                state = 28;
                                break;
                            case 112:
                                next();
                                state = 28;
                                break;
                            case 88:
                                next();
                                state = 28;
                                break;
                            case 89:
                                next();
                                state = 28;
                                break;
                            case 66:
                                next();
                                state = 28;
                                break;
                            case 113:
                                next();
                                state = 28;
                                break;
                            case 87:
                                next();
                                state = 28;
                                break;
                            case 116:
                                next();
                                state = 28;
                                break;
                            case 69:
                                next();
                                state = 28;
                                break;
                            case 115:
                                next();
                                state = 28;
                                break;
                            case 68:
                                next();
                                state = 28;
                                break;
                            case 114:
                                next();
                                state = 28;
                                break;
                            case 67:
                                next();
                                state = 28;
                                break;
                            case 90:
                                next();
                                state = 28;
                                break;
                            case 99:
                                next();
                                state = 28;
                                break;
                            case 52:
                                next();
                                state = 28;
                                break;
                            case 100:
                                next();
                                state = 28;
                                break;
                            case 53:
                                next();
                                state = 28;
                                break;
                            case 101:
                                next();
                                state = 28;
                                break;
                            case 54:
                                next();
                                state = 28;
                                break;
                            case 110:
                                next();
                                state = 0;
                                break;
                            case 111:
                                next();
                                state = 28;
                                break;
                            case 86:
                                next();
                                state = 28;
                                break;
                            case 109:
                                next();
                                state = 28;
                                break;
                            case 85:
                                next();
                                state = 28;
                                break;
                            case 108:
                                next();
                                state = 28;
                                break;
                            case 84:
                                next();
                                state = 28;
                                break;
                            case 107:
                                next();
                                state = 28;
                                break;
                            case 83:
                                next();
                                state = 28;
                                break;
                            case 106:
                                next();
                                state = 28;
                                break;
                            case 82:
                                next();
                                state = 28;
                                break;
                            case 105:
                                next();
                                state = 28;
                                break;
                            case 104:
                                next();
                                state = 28;
                                break;
                            case 57:
                                next();
                                state = 28;
                                break;
                            case 103:
                                next();
                                state = 28;
                                break;
                            case 56:
                                next();
                                state = 28;
                                break;
                            case 102:
                                next();
                                state = 28;
                                break;
                            default:
                                m_semantic.id(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 2:
                        m_semantic.comma(m_lexeme.str());
                        return true;
                    case 3:
                        switch (c) {
                            case 81:
                                next();
                                state = 28;
                                break;
                            case 49:
                                next();
                                state = 28;
                                break;
                            case 71:
                                next();
                                state = 28;
                                break;
                            case 118:
                                next();
                                state = 28;
                                break;
                            case 72:
                                next();
                                state = 28;
                                break;
                            case 119:
                                next();
                                state = 28;
                                break;
                            case 74:
                                next();
                                state = 28;
                                break;
                            case 121:
                                next();
                                state = 28;
                                break;
                            case 75:
                                next();
                                state = 28;
                                break;
                            case 122:
                                next();
                                state = 28;
                                break;
                            case 73:
                                next();
                                state = 28;
                                break;
                            case 120:
                                next();
                                state = 28;
                                break;
                            case 95:
                                next();
                                state = 28;
                                break;
                            case 48:
                                next();
                                state = 28;
                                break;
                            case 70:
                                next();
                                state = 28;
                                break;
                            case 117:
                                next();
                                state = 28;
                                break;
                            case 56:
                                next();
                                state = 28;
                                break;
                            case 98:
                                next();
                                state = 28;
                                break;
                            case 51:
                                next();
                                state = 28;
                                break;
                            case 50:
                                next();
                                state = 28;
                                break;
                            case 97:
                                next();
                                state = 28;
                                break;
                            case 80:
                                next();
                                state = 28;
                                break;
                            case 79:
                                next();
                                state = 28;
                                break;
                            case 78:
                                next();
                                state = 28;
                                break;
                            case 77:
                                next();
                                state = 28;
                                break;
                            case 76:
                                next();
                                state = 28;
                                break;
                            case 65:
                                next();
                                state = 28;
                                break;
                            case 112:
                                next();
                                state = 28;
                                break;
                            case 88:
                                next();
                                state = 28;
                                break;
                            case 89:
                                next();
                                state = 28;
                                break;
                            case 66:
                                next();
                                state = 28;
                                break;
                            case 113:
                                next();
                                state = 28;
                                break;
                            case 87:
                                next();
                                state = 28;
                                break;
                            case 116:
                                next();
                                state = 28;
                                break;
                            case 69:
                                next();
                                state = 28;
                                break;
                            case 115:
                                next();
                                state = 28;
                                break;
                            case 68:
                                next();
                                state = 28;
                                break;
                            case 114:
                                next();
                                state = 28;
                                break;
                            case 67:
                                next();
                                state = 28;
                                break;
                            case 90:
                                next();
                                state = 28;
                                break;
                            case 99:
                                next();
                                state = 28;
                                break;
                            case 52:
                                next();
                                state = 28;
                                break;
                            case 100:
                                next();
                                state = 28;
                                break;
                            case 53:
                                next();
                                state = 28;
                                break;
                            case 102:
                                next();
                                state = 28;
                                break;
                            case 55:
                                next();
                                state = 28;
                                break;
                            case 101:
                                next();
                                state = 19;
                                break;
                            case 54:
                                next();
                                state = 28;
                                break;
                            case 111:
                                next();
                                state = 28;
                                break;
                            case 110:
                                next();
                                state = 28;
                                break;
                            case 86:
                                next();
                                state = 28;
                                break;
                            case 109:
                                next();
                                state = 28;
                                break;
                            case 85:
                                next();
                                state = 28;
                                break;
                            case 108:
                                next();
                                state = 28;
                                break;
                            case 84:
                                next();
                                state = 28;
                                break;
                            case 107:
                                next();
                                state = 28;
                                break;
                            case 83:
                                next();
                                state = 28;
                                break;
                            case 106:
                                next();
                                state = 28;
                                break;
                            case 82:
                                next();
                                state = 28;
                                break;
                            case 105:
                                next();
                                state = 28;
                                break;
                            case 104:
                                next();
                                state = 28;
                                break;
                            case 57:
                                next();
                                state = 28;
                                break;
                            case 103:
                                next();
                                state = 28;
                                break;
                            default:
                                m_semantic.id(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 4:
                        switch (c) {
                            case 81:
                                next();
                                state = 28;
                                break;
                            case 49:
                                next();
                                state = 28;
                                break;
                            case 71:
                                next();
                                state = 28;
                                break;
                            case 118:
                                next();
                                state = 28;
                                break;
                            case 72:
                                next();
                                state = 28;
                                break;
                            case 119:
                                next();
                                state = 28;
                                break;
                            case 74:
                                next();
                                state = 28;
                                break;
                            case 121:
                                next();
                                state = 28;
                                break;
                            case 75:
                                next();
                                state = 28;
                                break;
                            case 122:
                                next();
                                state = 28;
                                break;
                            case 73:
                                next();
                                state = 28;
                                break;
                            case 120:
                                next();
                                state = 28;
                                break;
                            case 95:
                                next();
                                state = 28;
                                break;
                            case 48:
                                next();
                                state = 28;
                                break;
                            case 70:
                                next();
                                state = 28;
                                break;
                            case 117:
                                next();
                                state = 28;
                                break;
                            case 55:
                                next();
                                state = 28;
                                break;
                            case 98:
                                next();
                                state = 28;
                                break;
                            case 51:
                                next();
                                state = 28;
                                break;
                            case 50:
                                next();
                                state = 28;
                                break;
                            case 97:
                                next();
                                state = 28;
                                break;
                            case 80:
                                next();
                                state = 28;
                                break;
                            case 79:
                                next();
                                state = 28;
                                break;
                            case 78:
                                next();
                                state = 28;
                                break;
                            case 77:
                                next();
                                state = 28;
                                break;
                            case 76:
                                next();
                                state = 28;
                                break;
                            case 65:
                                next();
                                state = 28;
                                break;
                            case 112:
                                next();
                                state = 28;
                                break;
                            case 88:
                                next();
                                state = 28;
                                break;
                            case 89:
                                next();
                                state = 28;
                                break;
                            case 66:
                                next();
                                state = 28;
                                break;
                            case 113:
                                next();
                                state = 28;
                                break;
                            case 87:
                                next();
                                state = 28;
                                break;
                            case 116:
                                next();
                                state = 28;
                                break;
                            case 69:
                                next();
                                state = 28;
                                break;
                            case 115:
                                next();
                                state = 28;
                                break;
                            case 68:
                                next();
                                state = 28;
                                break;
                            case 114:
                                next();
                                state = 3;
                                break;
                            case 67:
                                next();
                                state = 28;
                                break;
                            case 90:
                                next();
                                state = 28;
                                break;
                            case 99:
                                next();
                                state = 28;
                                break;
                            case 52:
                                next();
                                state = 28;
                                break;
                            case 100:
                                next();
                                state = 28;
                                break;
                            case 53:
                                next();
                                state = 28;
                                break;
                            case 101:
                                next();
                                state = 28;
                                break;
                            case 54:
                                next();
                                state = 28;
                                break;
                            case 111:
                                next();
                                state = 28;
                                break;
                            case 110:
                                next();
                                state = 28;
                                break;
                            case 86:
                                next();
                                state = 28;
                                break;
                            case 109:
                                next();
                                state = 28;
                                break;
                            case 85:
                                next();
                                state = 28;
                                break;
                            case 108:
                                next();
                                state = 28;
                                break;
                            case 84:
                                next();
                                state = 28;
                                break;
                            case 107:
                                next();
                                state = 28;
                                break;
                            case 83:
                                next();
                                state = 28;
                                break;
                            case 106:
                                next();
                                state = 28;
                                break;
                            case 82:
                                next();
                                state = 28;
                                break;
                            case 105:
                                next();
                                state = 28;
                                break;
                            case 104:
                                next();
                                state = 28;
                                break;
                            case 57:
                                next();
                                state = 28;
                                break;
                            case 103:
                                next();
                                state = 28;
                                break;
                            case 56:
                                next();
                                state = 28;
                                break;
                            case 102:
                                next();
                                state = 28;
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
                                state = 28;
                                break;
                            case 49:
                                next();
                                state = 28;
                                break;
                            case 71:
                                next();
                                state = 28;
                                break;
                            case 118:
                                next();
                                state = 28;
                                break;
                            case 72:
                                next();
                                state = 28;
                                break;
                            case 119:
                                next();
                                state = 28;
                                break;
                            case 74:
                                next();
                                state = 28;
                                break;
                            case 121:
                                next();
                                state = 28;
                                break;
                            case 75:
                                next();
                                state = 28;
                                break;
                            case 122:
                                next();
                                state = 28;
                                break;
                            case 73:
                                next();
                                state = 28;
                                break;
                            case 120:
                                next();
                                state = 28;
                                break;
                            case 95:
                                next();
                                state = 28;
                                break;
                            case 48:
                                next();
                                state = 28;
                                break;
                            case 86:
                                next();
                                state = 28;
                                break;
                            case 56:
                                next();
                                state = 28;
                                break;
                            case 103:
                                next();
                                state = 28;
                                break;
                            case 98:
                                next();
                                state = 28;
                                break;
                            case 51:
                                next();
                                state = 28;
                                break;
                            case 50:
                                next();
                                state = 28;
                                break;
                            case 97:
                                next();
                                state = 28;
                                break;
                            case 80:
                                next();
                                state = 28;
                                break;
                            case 79:
                                next();
                                state = 28;
                                break;
                            case 78:
                                next();
                                state = 28;
                                break;
                            case 77:
                                next();
                                state = 28;
                                break;
                            case 76:
                                next();
                                state = 28;
                                break;
                            case 65:
                                next();
                                state = 28;
                                break;
                            case 112:
                                next();
                                state = 28;
                                break;
                            case 88:
                                next();
                                state = 28;
                                break;
                            case 89:
                                next();
                                state = 28;
                                break;
                            case 66:
                                next();
                                state = 28;
                                break;
                            case 113:
                                next();
                                state = 28;
                                break;
                            case 87:
                                next();
                                state = 28;
                                break;
                            case 116:
                                next();
                                state = 28;
                                break;
                            case 69:
                                next();
                                state = 28;
                                break;
                            case 115:
                                next();
                                state = 28;
                                break;
                            case 68:
                                next();
                                state = 28;
                                break;
                            case 114:
                                next();
                                state = 28;
                                break;
                            case 67:
                                next();
                                state = 28;
                                break;
                            case 90:
                                next();
                                state = 28;
                                break;
                            case 99:
                                next();
                                state = 28;
                                break;
                            case 52:
                                next();
                                state = 28;
                                break;
                            case 100:
                                next();
                                state = 28;
                                break;
                            case 53:
                                next();
                                state = 28;
                                break;
                            case 101:
                                next();
                                state = 28;
                                break;
                            case 54:
                                next();
                                state = 28;
                                break;
                            case 102:
                                next();
                                state = 28;
                                break;
                            case 55:
                                next();
                                state = 28;
                                break;
                            case 117:
                                next();
                                state = 4;
                                break;
                            case 70:
                                next();
                                state = 28;
                                break;
                            case 83:
                                next();
                                state = 28;
                                break;
                            case 106:
                                next();
                                state = 28;
                                break;
                            case 111:
                                next();
                                state = 28;
                                break;
                            case 110:
                                next();
                                state = 28;
                                break;
                            case 109:
                                next();
                                state = 28;
                                break;
                            case 85:
                                next();
                                state = 28;
                                break;
                            case 108:
                                next();
                                state = 28;
                                break;
                            case 84:
                                next();
                                state = 28;
                                break;
                            case 107:
                                next();
                                state = 28;
                                break;
                            case 82:
                                next();
                                state = 28;
                                break;
                            case 105:
                                next();
                                state = 28;
                                break;
                            case 104:
                                next();
                                state = 28;
                                break;
                            case 57:
                                next();
                                state = 28;
                                break;
                            default:
                                m_semantic.id(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 6:
                        switch (c) {
                            case 81:
                                next();
                                state = 28;
                                break;
                            case 49:
                                next();
                                state = 28;
                                break;
                            case 71:
                                next();
                                state = 28;
                                break;
                            case 118:
                                next();
                                state = 28;
                                break;
                            case 72:
                                next();
                                state = 28;
                                break;
                            case 119:
                                next();
                                state = 28;
                                break;
                            case 74:
                                next();
                                state = 28;
                                break;
                            case 121:
                                next();
                                state = 28;
                                break;
                            case 75:
                                next();
                                state = 28;
                                break;
                            case 122:
                                next();
                                state = 28;
                                break;
                            case 73:
                                next();
                                state = 28;
                                break;
                            case 120:
                                next();
                                state = 28;
                                break;
                            case 95:
                                next();
                                state = 28;
                                break;
                            case 48:
                                next();
                                state = 28;
                                break;
                            case 70:
                                next();
                                state = 28;
                                break;
                            case 117:
                                next();
                                state = 28;
                                break;
                            case 55:
                                next();
                                state = 28;
                                break;
                            case 98:
                                next();
                                state = 28;
                                break;
                            case 51:
                                next();
                                state = 28;
                                break;
                            case 50:
                                next();
                                state = 28;
                                break;
                            case 97:
                                next();
                                state = 28;
                                break;
                            case 80:
                                next();
                                state = 28;
                                break;
                            case 79:
                                next();
                                state = 28;
                                break;
                            case 78:
                                next();
                                state = 28;
                                break;
                            case 77:
                                next();
                                state = 28;
                                break;
                            case 76:
                                next();
                                state = 28;
                                break;
                            case 65:
                                next();
                                state = 28;
                                break;
                            case 112:
                                next();
                                state = 28;
                                break;
                            case 88:
                                next();
                                state = 28;
                                break;
                            case 89:
                                next();
                                state = 28;
                                break;
                            case 66:
                                next();
                                state = 28;
                                break;
                            case 113:
                                next();
                                state = 28;
                                break;
                            case 87:
                                next();
                                state = 28;
                                break;
                            case 116:
                                next();
                                state = 28;
                                break;
                            case 69:
                                next();
                                state = 28;
                                break;
                            case 115:
                                next();
                                state = 28;
                                break;
                            case 68:
                                next();
                                state = 28;
                                break;
                            case 114:
                                next();
                                state = 28;
                                break;
                            case 67:
                                next();
                                state = 28;
                                break;
                            case 90:
                                next();
                                state = 28;
                                break;
                            case 99:
                                next();
                                state = 28;
                                break;
                            case 52:
                                next();
                                state = 28;
                                break;
                            case 100:
                                next();
                                state = 28;
                                break;
                            case 53:
                                next();
                                state = 28;
                                break;
                            case 101:
                                next();
                                state = 28;
                                break;
                            case 54:
                                next();
                                state = 28;
                                break;
                            case 111:
                                next();
                                state = 28;
                                break;
                            case 110:
                                next();
                                state = 28;
                                break;
                            case 86:
                                next();
                                state = 28;
                                break;
                            case 109:
                                next();
                                state = 28;
                                break;
                            case 85:
                                next();
                                state = 28;
                                break;
                            case 108:
                                next();
                                state = 28;
                                break;
                            case 84:
                                next();
                                state = 28;
                                break;
                            case 107:
                                next();
                                state = 28;
                                break;
                            case 83:
                                next();
                                state = 28;
                                break;
                            case 106:
                                next();
                                state = 28;
                                break;
                            case 82:
                                next();
                                state = 28;
                                break;
                            case 105:
                                next();
                                state = 28;
                                break;
                            case 104:
                                next();
                                state = 28;
                                break;
                            case 57:
                                next();
                                state = 28;
                                break;
                            case 103:
                                next();
                                state = 28;
                                break;
                            case 56:
                                next();
                                state = 28;
                                break;
                            case 102:
                                next();
                                state = 28;
                                break;
                            default:
                                m_semantic.module(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 7:
                        switch (c) {
                            case 81:
                                next();
                                state = 28;
                                break;
                            case 49:
                                next();
                                state = 28;
                                break;
                            case 71:
                                next();
                                state = 28;
                                break;
                            case 118:
                                next();
                                state = 28;
                                break;
                            case 72:
                                next();
                                state = 28;
                                break;
                            case 119:
                                next();
                                state = 28;
                                break;
                            case 74:
                                next();
                                state = 28;
                                break;
                            case 121:
                                next();
                                state = 28;
                                break;
                            case 75:
                                next();
                                state = 28;
                                break;
                            case 122:
                                next();
                                state = 28;
                                break;
                            case 73:
                                next();
                                state = 28;
                                break;
                            case 120:
                                next();
                                state = 28;
                                break;
                            case 95:
                                next();
                                state = 28;
                                break;
                            case 48:
                                next();
                                state = 28;
                                break;
                            case 70:
                                next();
                                state = 28;
                                break;
                            case 117:
                                next();
                                state = 28;
                                break;
                            case 55:
                                next();
                                state = 28;
                                break;
                            case 98:
                                next();
                                state = 28;
                                break;
                            case 51:
                                next();
                                state = 28;
                                break;
                            case 50:
                                next();
                                state = 28;
                                break;
                            case 97:
                                next();
                                state = 28;
                                break;
                            case 80:
                                next();
                                state = 28;
                                break;
                            case 79:
                                next();
                                state = 28;
                                break;
                            case 78:
                                next();
                                state = 28;
                                break;
                            case 77:
                                next();
                                state = 28;
                                break;
                            case 76:
                                next();
                                state = 28;
                                break;
                            case 65:
                                next();
                                state = 28;
                                break;
                            case 112:
                                next();
                                state = 28;
                                break;
                            case 88:
                                next();
                                state = 28;
                                break;
                            case 89:
                                next();
                                state = 28;
                                break;
                            case 66:
                                next();
                                state = 28;
                                break;
                            case 113:
                                next();
                                state = 28;
                                break;
                            case 87:
                                next();
                                state = 28;
                                break;
                            case 116:
                                next();
                                state = 28;
                                break;
                            case 69:
                                next();
                                state = 28;
                                break;
                            case 115:
                                next();
                                state = 28;
                                break;
                            case 68:
                                next();
                                state = 28;
                                break;
                            case 114:
                                next();
                                state = 28;
                                break;
                            case 67:
                                next();
                                state = 28;
                                break;
                            case 90:
                                next();
                                state = 28;
                                break;
                            case 99:
                                next();
                                state = 28;
                                break;
                            case 52:
                                next();
                                state = 28;
                                break;
                            case 100:
                                next();
                                state = 28;
                                break;
                            case 53:
                                next();
                                state = 28;
                                break;
                            case 101:
                                next();
                                state = 28;
                                break;
                            case 54:
                                next();
                                state = 28;
                                break;
                            case 85:
                                next();
                                state = 28;
                                break;
                            case 108:
                                next();
                                state = 32;
                                break;
                            case 111:
                                next();
                                state = 28;
                                break;
                            case 110:
                                next();
                                state = 28;
                                break;
                            case 86:
                                next();
                                state = 28;
                                break;
                            case 109:
                                next();
                                state = 28;
                                break;
                            case 84:
                                next();
                                state = 28;
                                break;
                            case 107:
                                next();
                                state = 28;
                                break;
                            case 83:
                                next();
                                state = 28;
                                break;
                            case 106:
                                next();
                                state = 28;
                                break;
                            case 82:
                                next();
                                state = 28;
                                break;
                            case 105:
                                next();
                                state = 28;
                                break;
                            case 104:
                                next();
                                state = 28;
                                break;
                            case 57:
                                next();
                                state = 28;
                                break;
                            case 103:
                                next();
                                state = 28;
                                break;
                            case 56:
                                next();
                                state = 28;
                                break;
                            case 102:
                                next();
                                state = 28;
                                break;
                            default:
                                m_semantic.id(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 8:
                        switch (c) {
                            case 81:
                                next();
                                state = 28;
                                break;
                            case 49:
                                next();
                                state = 28;
                                break;
                            case 71:
                                next();
                                state = 28;
                                break;
                            case 118:
                                next();
                                state = 28;
                                break;
                            case 72:
                                next();
                                state = 28;
                                break;
                            case 119:
                                next();
                                state = 28;
                                break;
                            case 74:
                                next();
                                state = 28;
                                break;
                            case 121:
                                next();
                                state = 28;
                                break;
                            case 75:
                                next();
                                state = 28;
                                break;
                            case 122:
                                next();
                                state = 28;
                                break;
                            case 73:
                                next();
                                state = 28;
                                break;
                            case 120:
                                next();
                                state = 28;
                                break;
                            case 95:
                                next();
                                state = 28;
                                break;
                            case 48:
                                next();
                                state = 28;
                                break;
                            case 70:
                                next();
                                state = 28;
                                break;
                            case 117:
                                next();
                                state = 7;
                                break;
                            case 55:
                                next();
                                state = 28;
                                break;
                            case 98:
                                next();
                                state = 28;
                                break;
                            case 51:
                                next();
                                state = 28;
                                break;
                            case 50:
                                next();
                                state = 28;
                                break;
                            case 97:
                                next();
                                state = 28;
                                break;
                            case 80:
                                next();
                                state = 28;
                                break;
                            case 79:
                                next();
                                state = 28;
                                break;
                            case 78:
                                next();
                                state = 28;
                                break;
                            case 77:
                                next();
                                state = 28;
                                break;
                            case 76:
                                next();
                                state = 28;
                                break;
                            case 65:
                                next();
                                state = 28;
                                break;
                            case 112:
                                next();
                                state = 28;
                                break;
                            case 88:
                                next();
                                state = 28;
                                break;
                            case 89:
                                next();
                                state = 28;
                                break;
                            case 66:
                                next();
                                state = 28;
                                break;
                            case 113:
                                next();
                                state = 28;
                                break;
                            case 87:
                                next();
                                state = 28;
                                break;
                            case 116:
                                next();
                                state = 28;
                                break;
                            case 69:
                                next();
                                state = 28;
                                break;
                            case 115:
                                next();
                                state = 28;
                                break;
                            case 68:
                                next();
                                state = 28;
                                break;
                            case 114:
                                next();
                                state = 28;
                                break;
                            case 67:
                                next();
                                state = 28;
                                break;
                            case 90:
                                next();
                                state = 28;
                                break;
                            case 99:
                                next();
                                state = 28;
                                break;
                            case 52:
                                next();
                                state = 28;
                                break;
                            case 100:
                                next();
                                state = 28;
                                break;
                            case 53:
                                next();
                                state = 28;
                                break;
                            case 101:
                                next();
                                state = 28;
                                break;
                            case 54:
                                next();
                                state = 28;
                                break;
                            case 111:
                                next();
                                state = 28;
                                break;
                            case 110:
                                next();
                                state = 28;
                                break;
                            case 86:
                                next();
                                state = 28;
                                break;
                            case 109:
                                next();
                                state = 28;
                                break;
                            case 85:
                                next();
                                state = 28;
                                break;
                            case 108:
                                next();
                                state = 28;
                                break;
                            case 84:
                                next();
                                state = 28;
                                break;
                            case 107:
                                next();
                                state = 28;
                                break;
                            case 83:
                                next();
                                state = 28;
                                break;
                            case 106:
                                next();
                                state = 28;
                                break;
                            case 82:
                                next();
                                state = 28;
                                break;
                            case 105:
                                next();
                                state = 28;
                                break;
                            case 104:
                                next();
                                state = 28;
                                break;
                            case 57:
                                next();
                                state = 28;
                                break;
                            case 103:
                                next();
                                state = 28;
                                break;
                            case 56:
                                next();
                                state = 28;
                                break;
                            case 102:
                                next();
                                state = 28;
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
                                state = 28;
                                break;
                            case 49:
                                next();
                                state = 28;
                                break;
                            case 71:
                                next();
                                state = 28;
                                break;
                            case 118:
                                next();
                                state = 28;
                                break;
                            case 72:
                                next();
                                state = 28;
                                break;
                            case 119:
                                next();
                                state = 28;
                                break;
                            case 74:
                                next();
                                state = 28;
                                break;
                            case 121:
                                next();
                                state = 28;
                                break;
                            case 75:
                                next();
                                state = 28;
                                break;
                            case 122:
                                next();
                                state = 28;
                                break;
                            case 73:
                                next();
                                state = 28;
                                break;
                            case 120:
                                next();
                                state = 28;
                                break;
                            case 95:
                                next();
                                state = 28;
                                break;
                            case 48:
                                next();
                                state = 28;
                                break;
                            case 70:
                                next();
                                state = 28;
                                break;
                            case 117:
                                next();
                                state = 28;
                                break;
                            case 56:
                                next();
                                state = 28;
                                break;
                            case 98:
                                next();
                                state = 28;
                                break;
                            case 51:
                                next();
                                state = 28;
                                break;
                            case 50:
                                next();
                                state = 28;
                                break;
                            case 97:
                                next();
                                state = 28;
                                break;
                            case 80:
                                next();
                                state = 28;
                                break;
                            case 79:
                                next();
                                state = 28;
                                break;
                            case 78:
                                next();
                                state = 28;
                                break;
                            case 77:
                                next();
                                state = 28;
                                break;
                            case 76:
                                next();
                                state = 28;
                                break;
                            case 65:
                                next();
                                state = 28;
                                break;
                            case 112:
                                next();
                                state = 28;
                                break;
                            case 88:
                                next();
                                state = 28;
                                break;
                            case 89:
                                next();
                                state = 28;
                                break;
                            case 66:
                                next();
                                state = 28;
                                break;
                            case 113:
                                next();
                                state = 28;
                                break;
                            case 87:
                                next();
                                state = 28;
                                break;
                            case 116:
                                next();
                                state = 28;
                                break;
                            case 69:
                                next();
                                state = 28;
                                break;
                            case 115:
                                next();
                                state = 28;
                                break;
                            case 68:
                                next();
                                state = 28;
                                break;
                            case 114:
                                next();
                                state = 28;
                                break;
                            case 67:
                                next();
                                state = 28;
                                break;
                            case 90:
                                next();
                                state = 28;
                                break;
                            case 99:
                                next();
                                state = 28;
                                break;
                            case 52:
                                next();
                                state = 28;
                                break;
                            case 101:
                                next();
                                state = 28;
                                break;
                            case 54:
                                next();
                                state = 28;
                                break;
                            case 102:
                                next();
                                state = 28;
                                break;
                            case 55:
                                next();
                                state = 28;
                                break;
                            case 100:
                                next();
                                state = 8;
                                break;
                            case 53:
                                next();
                                state = 28;
                                break;
                            case 111:
                                next();
                                state = 28;
                                break;
                            case 110:
                                next();
                                state = 28;
                                break;
                            case 86:
                                next();
                                state = 28;
                                break;
                            case 109:
                                next();
                                state = 28;
                                break;
                            case 85:
                                next();
                                state = 28;
                                break;
                            case 108:
                                next();
                                state = 28;
                                break;
                            case 84:
                                next();
                                state = 28;
                                break;
                            case 107:
                                next();
                                state = 28;
                                break;
                            case 83:
                                next();
                                state = 28;
                                break;
                            case 106:
                                next();
                                state = 28;
                                break;
                            case 82:
                                next();
                                state = 28;
                                break;
                            case 105:
                                next();
                                state = 28;
                                break;
                            case 104:
                                next();
                                state = 28;
                                break;
                            case 57:
                                next();
                                state = 28;
                                break;
                            case 103:
                                next();
                                state = 28;
                                break;
                            default:
                                m_semantic.id(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 10:
                        m_semantic.colon(m_lexeme.str());
                        return true;
                    case 11:
                        switch (c) {
                            case 81:
                                next();
                                state = 28;
                                break;
                            case 49:
                                next();
                                state = 28;
                                break;
                            case 71:
                                next();
                                state = 28;
                                break;
                            case 118:
                                next();
                                state = 28;
                                break;
                            case 72:
                                next();
                                state = 28;
                                break;
                            case 119:
                                next();
                                state = 28;
                                break;
                            case 74:
                                next();
                                state = 28;
                                break;
                            case 121:
                                next();
                                state = 28;
                                break;
                            case 75:
                                next();
                                state = 28;
                                break;
                            case 122:
                                next();
                                state = 28;
                                break;
                            case 73:
                                next();
                                state = 28;
                                break;
                            case 120:
                                next();
                                state = 28;
                                break;
                            case 95:
                                next();
                                state = 28;
                                break;
                            case 48:
                                next();
                                state = 28;
                                break;
                            case 70:
                                next();
                                state = 28;
                                break;
                            case 117:
                                next();
                                state = 28;
                                break;
                            case 55:
                                next();
                                state = 28;
                                break;
                            case 98:
                                next();
                                state = 28;
                                break;
                            case 51:
                                next();
                                state = 28;
                                break;
                            case 50:
                                next();
                                state = 28;
                                break;
                            case 97:
                                next();
                                state = 28;
                                break;
                            case 80:
                                next();
                                state = 28;
                                break;
                            case 79:
                                next();
                                state = 28;
                                break;
                            case 78:
                                next();
                                state = 28;
                                break;
                            case 77:
                                next();
                                state = 28;
                                break;
                            case 76:
                                next();
                                state = 28;
                                break;
                            case 65:
                                next();
                                state = 28;
                                break;
                            case 112:
                                next();
                                state = 28;
                                break;
                            case 88:
                                next();
                                state = 28;
                                break;
                            case 89:
                                next();
                                state = 28;
                                break;
                            case 66:
                                next();
                                state = 28;
                                break;
                            case 113:
                                next();
                                state = 28;
                                break;
                            case 87:
                                next();
                                state = 28;
                                break;
                            case 116:
                                next();
                                state = 28;
                                break;
                            case 69:
                                next();
                                state = 28;
                                break;
                            case 115:
                                next();
                                state = 28;
                                break;
                            case 68:
                                next();
                                state = 28;
                                break;
                            case 114:
                                next();
                                state = 28;
                                break;
                            case 67:
                                next();
                                state = 28;
                                break;
                            case 90:
                                next();
                                state = 28;
                                break;
                            case 99:
                                next();
                                state = 28;
                                break;
                            case 52:
                                next();
                                state = 28;
                                break;
                            case 100:
                                next();
                                state = 28;
                                break;
                            case 53:
                                next();
                                state = 28;
                                break;
                            case 101:
                                next();
                                state = 28;
                                break;
                            case 54:
                                next();
                                state = 28;
                                break;
                            case 111:
                                next();
                                state = 28;
                                break;
                            case 110:
                                next();
                                state = 28;
                                break;
                            case 86:
                                next();
                                state = 28;
                                break;
                            case 109:
                                next();
                                state = 28;
                                break;
                            case 85:
                                next();
                                state = 28;
                                break;
                            case 108:
                                next();
                                state = 28;
                                break;
                            case 84:
                                next();
                                state = 28;
                                break;
                            case 107:
                                next();
                                state = 28;
                                break;
                            case 83:
                                next();
                                state = 28;
                                break;
                            case 106:
                                next();
                                state = 28;
                                break;
                            case 82:
                                next();
                                state = 28;
                                break;
                            case 105:
                                next();
                                state = 28;
                                break;
                            case 104:
                                next();
                                state = 28;
                                break;
                            case 57:
                                next();
                                state = 28;
                                break;
                            case 103:
                                next();
                                state = 28;
                                break;
                            case 56:
                                next();
                                state = 28;
                                break;
                            case 102:
                                next();
                                state = 28;
                                break;
                            default:
                                m_semantic.type(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 12:
                        switch (c) {
                            case 81:
                                next();
                                state = 28;
                                break;
                            case 49:
                                next();
                                state = 28;
                                break;
                            case 71:
                                next();
                                state = 28;
                                break;
                            case 118:
                                next();
                                state = 28;
                                break;
                            case 72:
                                next();
                                state = 28;
                                break;
                            case 119:
                                next();
                                state = 28;
                                break;
                            case 74:
                                next();
                                state = 28;
                                break;
                            case 121:
                                next();
                                state = 28;
                                break;
                            case 75:
                                next();
                                state = 28;
                                break;
                            case 122:
                                next();
                                state = 28;
                                break;
                            case 73:
                                next();
                                state = 28;
                                break;
                            case 120:
                                next();
                                state = 28;
                                break;
                            case 95:
                                next();
                                state = 28;
                                break;
                            case 48:
                                next();
                                state = 28;
                                break;
                            case 70:
                                next();
                                state = 28;
                                break;
                            case 117:
                                next();
                                state = 28;
                                break;
                            case 55:
                                next();
                                state = 28;
                                break;
                            case 98:
                                next();
                                state = 28;
                                break;
                            case 51:
                                next();
                                state = 28;
                                break;
                            case 50:
                                next();
                                state = 28;
                                break;
                            case 97:
                                next();
                                state = 28;
                                break;
                            case 80:
                                next();
                                state = 28;
                                break;
                            case 79:
                                next();
                                state = 28;
                                break;
                            case 78:
                                next();
                                state = 28;
                                break;
                            case 77:
                                next();
                                state = 28;
                                break;
                            case 76:
                                next();
                                state = 28;
                                break;
                            case 65:
                                next();
                                state = 28;
                                break;
                            case 112:
                                next();
                                state = 28;
                                break;
                            case 88:
                                next();
                                state = 28;
                                break;
                            case 89:
                                next();
                                state = 28;
                                break;
                            case 66:
                                next();
                                state = 28;
                                break;
                            case 113:
                                next();
                                state = 28;
                                break;
                            case 87:
                                next();
                                state = 28;
                                break;
                            case 116:
                                next();
                                state = 28;
                                break;
                            case 69:
                                next();
                                state = 28;
                                break;
                            case 115:
                                next();
                                state = 28;
                                break;
                            case 68:
                                next();
                                state = 28;
                                break;
                            case 114:
                                next();
                                state = 28;
                                break;
                            case 67:
                                next();
                                state = 28;
                                break;
                            case 90:
                                next();
                                state = 28;
                                break;
                            case 99:
                                next();
                                state = 28;
                                break;
                            case 52:
                                next();
                                state = 28;
                                break;
                            case 100:
                                next();
                                state = 28;
                                break;
                            case 53:
                                next();
                                state = 28;
                                break;
                            case 101:
                                next();
                                state = 28;
                                break;
                            case 54:
                                next();
                                state = 28;
                                break;
                            case 111:
                                next();
                                state = 28;
                                break;
                            case 110:
                                next();
                                state = 28;
                                break;
                            case 86:
                                next();
                                state = 28;
                                break;
                            case 109:
                                next();
                                state = 28;
                                break;
                            case 85:
                                next();
                                state = 28;
                                break;
                            case 108:
                                next();
                                state = 28;
                                break;
                            case 84:
                                next();
                                state = 28;
                                break;
                            case 107:
                                next();
                                state = 28;
                                break;
                            case 83:
                                next();
                                state = 28;
                                break;
                            case 106:
                                next();
                                state = 28;
                                break;
                            case 82:
                                next();
                                state = 28;
                                break;
                            case 105:
                                next();
                                state = 1;
                                break;
                            case 104:
                                next();
                                state = 28;
                                break;
                            case 57:
                                next();
                                state = 28;
                                break;
                            case 103:
                                next();
                                state = 28;
                                break;
                            case 56:
                                next();
                                state = 28;
                                break;
                            case 102:
                                next();
                                state = 28;
                                break;
                            default:
                                m_semantic.id(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 13:
                        switch (c) {
                            case 49:
                                next();
                                state = 28;
                                break;
                            case 71:
                                next();
                                state = 28;
                                break;
                            case 118:
                                next();
                                state = 28;
                                break;
                            case 72:
                                next();
                                state = 28;
                                break;
                            case 119:
                                next();
                                state = 28;
                                break;
                            case 74:
                                next();
                                state = 28;
                                break;
                            case 121:
                                next();
                                state = 28;
                                break;
                            case 75:
                                next();
                                state = 28;
                                break;
                            case 122:
                                next();
                                state = 28;
                                break;
                            case 73:
                                next();
                                state = 28;
                                break;
                            case 120:
                                next();
                                state = 28;
                                break;
                            case 95:
                                next();
                                state = 28;
                                break;
                            case 48:
                                next();
                                state = 28;
                                break;
                            case 70:
                                next();
                                state = 28;
                                break;
                            case 117:
                                next();
                                state = 28;
                                break;
                            case 86:
                                next();
                                state = 28;
                                break;
                            case 56:
                                next();
                                state = 28;
                                break;
                            case 98:
                                next();
                                state = 28;
                                break;
                            case 51:
                                next();
                                state = 28;
                                break;
                            case 50:
                                next();
                                state = 28;
                                break;
                            case 97:
                                next();
                                state = 28;
                                break;
                            case 81:
                                next();
                                state = 28;
                                break;
                            case 80:
                                next();
                                state = 28;
                                break;
                            case 79:
                                next();
                                state = 28;
                                break;
                            case 78:
                                next();
                                state = 28;
                                break;
                            case 77:
                                next();
                                state = 28;
                                break;
                            case 76:
                                next();
                                state = 28;
                                break;
                            case 65:
                                next();
                                state = 28;
                                break;
                            case 112:
                                next();
                                state = 26;
                                break;
                            case 88:
                                next();
                                state = 28;
                                break;
                            case 66:
                                next();
                                state = 28;
                                break;
                            case 113:
                                next();
                                state = 28;
                                break;
                            case 87:
                                next();
                                state = 28;
                                break;
                            case 116:
                                next();
                                state = 28;
                                break;
                            case 69:
                                next();
                                state = 28;
                                break;
                            case 115:
                                next();
                                state = 28;
                                break;
                            case 68:
                                next();
                                state = 28;
                                break;
                            case 114:
                                next();
                                state = 28;
                                break;
                            case 67:
                                next();
                                state = 28;
                                break;
                            case 90:
                                next();
                                state = 28;
                                break;
                            case 99:
                                next();
                                state = 28;
                                break;
                            case 52:
                                next();
                                state = 28;
                                break;
                            case 100:
                                next();
                                state = 28;
                                break;
                            case 53:
                                next();
                                state = 28;
                                break;
                            case 101:
                                next();
                                state = 28;
                                break;
                            case 54:
                                next();
                                state = 28;
                                break;
                            case 102:
                                next();
                                state = 28;
                                break;
                            case 55:
                                next();
                                state = 28;
                                break;
                            case 89:
                                next();
                                state = 28;
                                break;
                            case 111:
                                next();
                                state = 28;
                                break;
                            case 110:
                                next();
                                state = 28;
                                break;
                            case 109:
                                next();
                                state = 28;
                                break;
                            case 85:
                                next();
                                state = 28;
                                break;
                            case 108:
                                next();
                                state = 28;
                                break;
                            case 84:
                                next();
                                state = 28;
                                break;
                            case 107:
                                next();
                                state = 28;
                                break;
                            case 83:
                                next();
                                state = 28;
                                break;
                            case 106:
                                next();
                                state = 28;
                                break;
                            case 82:
                                next();
                                state = 28;
                                break;
                            case 105:
                                next();
                                state = 28;
                                break;
                            case 104:
                                next();
                                state = 28;
                                break;
                            case 57:
                                next();
                                state = 28;
                                break;
                            case 103:
                                next();
                                state = 28;
                                break;
                            default:
                                m_semantic.id(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 14:
                        switch (c) {
                            case 103:
                                next();
                                state = 28;
                                break;
                            case 57:
                                next();
                                state = 28;
                                break;
                            case 104:
                                next();
                                state = 28;
                                break;
                            case 105:
                                next();
                                state = 28;
                                break;
                            case 82:
                                next();
                                state = 28;
                                break;
                            case 106:
                                next();
                                state = 28;
                                break;
                            case 83:
                                next();
                                state = 28;
                                break;
                            case 107:
                                next();
                                state = 28;
                                break;
                            case 84:
                                next();
                                state = 28;
                                break;
                            case 108:
                                next();
                                state = 28;
                                break;
                            case 85:
                                next();
                                state = 28;
                                break;
                            case 109:
                                next();
                                state = 28;
                                break;
                            case 111:
                                next();
                                state = 28;
                                break;
                            case 110:
                                next();
                                state = 28;
                                break;
                            case 55:
                                next();
                                state = 28;
                                break;
                            case 102:
                                next();
                                state = 28;
                                break;
                            case 54:
                                next();
                                state = 28;
                                break;
                            case 81:
                                next();
                                state = 28;
                                break;
                            case 56:
                                next();
                                state = 28;
                                break;
                            case 86:
                                next();
                                state = 28;
                                break;
                            case 70:
                                next();
                                state = 28;
                                break;
                            case 117:
                                next();
                                state = 28;
                                break;
                            case 48:
                                next();
                                state = 28;
                                break;
                            case 95:
                                next();
                                state = 28;
                                break;
                            case 71:
                                next();
                                state = 28;
                                break;
                            case 118:
                                next();
                                state = 28;
                                break;
                            case 97:
                                next();
                                state = 28;
                                break;
                            case 50:
                                next();
                                state = 28;
                                break;
                            case 51:
                                next();
                                state = 28;
                                break;
                            case 98:
                                next();
                                state = 28;
                                break;
                            case 120:
                                next();
                                state = 28;
                                break;
                            case 73:
                                next();
                                state = 28;
                                break;
                            case 74:
                                next();
                                state = 28;
                                break;
                            case 121:
                                next();
                                state = 13;
                                break;
                            case 49:
                                next();
                                state = 28;
                                break;
                            case 72:
                                next();
                                state = 28;
                                break;
                            case 119:
                                next();
                                state = 28;
                                break;
                            case 75:
                                next();
                                state = 28;
                                break;
                            case 122:
                                next();
                                state = 28;
                                break;
                            case 80:
                                next();
                                state = 28;
                                break;
                            case 79:
                                next();
                                state = 28;
                                break;
                            case 78:
                                next();
                                state = 28;
                                break;
                            case 77:
                                next();
                                state = 28;
                                break;
                            case 76:
                                next();
                                state = 28;
                                break;
                            case 65:
                                next();
                                state = 28;
                                break;
                            case 112:
                                next();
                                state = 28;
                                break;
                            case 88:
                                next();
                                state = 28;
                                break;
                            case 89:
                                next();
                                state = 28;
                                break;
                            case 66:
                                next();
                                state = 28;
                                break;
                            case 113:
                                next();
                                state = 28;
                                break;
                            case 87:
                                next();
                                state = 28;
                                break;
                            case 116:
                                next();
                                state = 28;
                                break;
                            case 69:
                                next();
                                state = 28;
                                break;
                            case 115:
                                next();
                                state = 28;
                                break;
                            case 68:
                                next();
                                state = 28;
                                break;
                            case 114:
                                next();
                                state = 28;
                                break;
                            case 67:
                                next();
                                state = 28;
                                break;
                            case 90:
                                next();
                                state = 28;
                                break;
                            case 99:
                                next();
                                state = 28;
                                break;
                            case 52:
                                next();
                                state = 28;
                                break;
                            case 100:
                                next();
                                state = 28;
                                break;
                            case 53:
                                next();
                                state = 28;
                                break;
                            case 101:
                                next();
                                state = 28;
                                break;
                            default:
                                m_semantic.id(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 15:
                        switch (c) {
                            case 49:
                                next();
                                state = 28;
                                break;
                            case 71:
                                next();
                                state = 28;
                                break;
                            case 118:
                                next();
                                state = 28;
                                break;
                            case 72:
                                next();
                                state = 28;
                                break;
                            case 119:
                                next();
                                state = 28;
                                break;
                            case 74:
                                next();
                                state = 28;
                                break;
                            case 121:
                                next();
                                state = 28;
                                break;
                            case 75:
                                next();
                                state = 28;
                                break;
                            case 122:
                                next();
                                state = 28;
                                break;
                            case 73:
                                next();
                                state = 28;
                                break;
                            case 120:
                                next();
                                state = 28;
                                break;
                            case 95:
                                next();
                                state = 28;
                                break;
                            case 48:
                                next();
                                state = 28;
                                break;
                            case 70:
                                next();
                                state = 28;
                                break;
                            case 117:
                                next();
                                state = 28;
                                break;
                            case 86:
                                next();
                                state = 28;
                                break;
                            case 56:
                                next();
                                state = 28;
                                break;
                            case 98:
                                next();
                                state = 28;
                                break;
                            case 51:
                                next();
                                state = 28;
                                break;
                            case 50:
                                next();
                                state = 28;
                                break;
                            case 97:
                                next();
                                state = 28;
                                break;
                            case 81:
                                next();
                                state = 28;
                                break;
                            case 80:
                                next();
                                state = 28;
                                break;
                            case 79:
                                next();
                                state = 28;
                                break;
                            case 78:
                                next();
                                state = 28;
                                break;
                            case 77:
                                next();
                                state = 28;
                                break;
                            case 76:
                                next();
                                state = 28;
                                break;
                            case 65:
                                next();
                                state = 28;
                                break;
                            case 112:
                                next();
                                state = 28;
                                break;
                            case 88:
                                next();
                                state = 28;
                                break;
                            case 89:
                                next();
                                state = 28;
                                break;
                            case 66:
                                next();
                                state = 28;
                                break;
                            case 113:
                                next();
                                state = 28;
                                break;
                            case 87:
                                next();
                                state = 28;
                                break;
                            case 116:
                                next();
                                state = 28;
                                break;
                            case 69:
                                next();
                                state = 28;
                                break;
                            case 115:
                                next();
                                state = 28;
                                break;
                            case 68:
                                next();
                                state = 28;
                                break;
                            case 114:
                                next();
                                state = 28;
                                break;
                            case 67:
                                next();
                                state = 28;
                                break;
                            case 90:
                                next();
                                state = 28;
                                break;
                            case 99:
                                next();
                                state = 28;
                                break;
                            case 52:
                                next();
                                state = 28;
                                break;
                            case 100:
                                next();
                                state = 28;
                                break;
                            case 53:
                                next();
                                state = 28;
                                break;
                            case 101:
                                next();
                                state = 28;
                                break;
                            case 54:
                                next();
                                state = 28;
                                break;
                            case 102:
                                next();
                                state = 28;
                                break;
                            case 55:
                                next();
                                state = 28;
                                break;
                            case 110:
                                next();
                                state = 28;
                                break;
                            case 111:
                                next();
                                state = 28;
                                break;
                            case 109:
                                next();
                                state = 28;
                                break;
                            case 85:
                                next();
                                state = 28;
                                break;
                            case 108:
                                next();
                                state = 28;
                                break;
                            case 84:
                                next();
                                state = 28;
                                break;
                            case 107:
                                next();
                                state = 28;
                                break;
                            case 83:
                                next();
                                state = 28;
                                break;
                            case 106:
                                next();
                                state = 28;
                                break;
                            case 82:
                                next();
                                state = 28;
                                break;
                            case 105:
                                next();
                                state = 28;
                                break;
                            case 104:
                                next();
                                state = 28;
                                break;
                            case 57:
                                next();
                                state = 28;
                                break;
                            case 103:
                                next();
                                state = 28;
                                break;
                            default:
                                m_semantic.id(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 16:
                        switch (c) {
                            case 81:
                                next();
                                state = 28;
                                break;
                            case 49:
                                next();
                                state = 28;
                                break;
                            case 71:
                                next();
                                state = 28;
                                break;
                            case 118:
                                next();
                                state = 28;
                                break;
                            case 72:
                                next();
                                state = 28;
                                break;
                            case 119:
                                next();
                                state = 28;
                                break;
                            case 74:
                                next();
                                state = 28;
                                break;
                            case 121:
                                next();
                                state = 28;
                                break;
                            case 75:
                                next();
                                state = 28;
                                break;
                            case 122:
                                next();
                                state = 28;
                                break;
                            case 73:
                                next();
                                state = 28;
                                break;
                            case 120:
                                next();
                                state = 28;
                                break;
                            case 95:
                                next();
                                state = 28;
                                break;
                            case 48:
                                next();
                                state = 28;
                                break;
                            case 70:
                                next();
                                state = 28;
                                break;
                            case 117:
                                next();
                                state = 28;
                                break;
                            case 55:
                                next();
                                state = 28;
                                break;
                            case 98:
                                next();
                                state = 28;
                                break;
                            case 51:
                                next();
                                state = 28;
                                break;
                            case 50:
                                next();
                                state = 28;
                                break;
                            case 97:
                                next();
                                state = 28;
                                break;
                            case 80:
                                next();
                                state = 28;
                                break;
                            case 79:
                                next();
                                state = 28;
                                break;
                            case 78:
                                next();
                                state = 28;
                                break;
                            case 77:
                                next();
                                state = 28;
                                break;
                            case 76:
                                next();
                                state = 28;
                                break;
                            case 65:
                                next();
                                state = 28;
                                break;
                            case 112:
                                next();
                                state = 28;
                                break;
                            case 88:
                                next();
                                state = 28;
                                break;
                            case 89:
                                next();
                                state = 28;
                                break;
                            case 66:
                                next();
                                state = 28;
                                break;
                            case 113:
                                next();
                                state = 28;
                                break;
                            case 87:
                                next();
                                state = 28;
                                break;
                            case 116:
                                next();
                                state = 28;
                                break;
                            case 69:
                                next();
                                state = 28;
                                break;
                            case 115:
                                next();
                                state = 28;
                                break;
                            case 68:
                                next();
                                state = 28;
                                break;
                            case 114:
                                next();
                                state = 28;
                                break;
                            case 67:
                                next();
                                state = 28;
                                break;
                            case 90:
                                next();
                                state = 28;
                                break;
                            case 99:
                                next();
                                state = 28;
                                break;
                            case 52:
                                next();
                                state = 28;
                                break;
                            case 100:
                                next();
                                state = 28;
                                break;
                            case 53:
                                next();
                                state = 28;
                                break;
                            case 101:
                                next();
                                state = 28;
                                break;
                            case 54:
                                next();
                                state = 28;
                                break;
                            case 103:
                                next();
                                state = 12;
                                break;
                            case 56:
                                next();
                                state = 28;
                                break;
                            case 111:
                                next();
                                state = 28;
                                break;
                            case 110:
                                next();
                                state = 28;
                                break;
                            case 86:
                                next();
                                state = 28;
                                break;
                            case 109:
                                next();
                                state = 28;
                                break;
                            case 85:
                                next();
                                state = 28;
                                break;
                            case 108:
                                next();
                                state = 28;
                                break;
                            case 84:
                                next();
                                state = 28;
                                break;
                            case 107:
                                next();
                                state = 28;
                                break;
                            case 83:
                                next();
                                state = 28;
                                break;
                            case 106:
                                next();
                                state = 28;
                                break;
                            case 82:
                                next();
                                state = 28;
                                break;
                            case 105:
                                next();
                                state = 28;
                                break;
                            case 104:
                                next();
                                state = 28;
                                break;
                            case 57:
                                next();
                                state = 28;
                                break;
                            case 102:
                                next();
                                state = 28;
                                break;
                            default:
                                m_semantic.id(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 17:
                        switch (c) {
                            case 9:
                                next();
                                state = 17;
                                break;
                            case 32:
                                next();
                                state = 17;
                                break;
                            case 10:
                                next();
                                state = 17;
                                break;
                            default:
                                return false;
                        }
                        break;
                    case 18:
                        switch (c) {
                            case 81:
                                next();
                                state = 28;
                                break;
                            case 49:
                                next();
                                state = 28;
                                break;
                            case 71:
                                next();
                                state = 28;
                                break;
                            case 118:
                                next();
                                state = 28;
                                break;
                            case 72:
                                next();
                                state = 28;
                                break;
                            case 119:
                                next();
                                state = 28;
                                break;
                            case 74:
                                next();
                                state = 28;
                                break;
                            case 121:
                                next();
                                state = 28;
                                break;
                            case 75:
                                next();
                                state = 28;
                                break;
                            case 122:
                                next();
                                state = 28;
                                break;
                            case 73:
                                next();
                                state = 28;
                                break;
                            case 120:
                                next();
                                state = 28;
                                break;
                            case 95:
                                next();
                                state = 28;
                                break;
                            case 48:
                                next();
                                state = 28;
                                break;
                            case 70:
                                next();
                                state = 28;
                                break;
                            case 117:
                                next();
                                state = 28;
                                break;
                            case 55:
                                next();
                                state = 28;
                                break;
                            case 98:
                                next();
                                state = 28;
                                break;
                            case 51:
                                next();
                                state = 28;
                                break;
                            case 50:
                                next();
                                state = 28;
                                break;
                            case 97:
                                next();
                                state = 28;
                                break;
                            case 80:
                                next();
                                state = 28;
                                break;
                            case 79:
                                next();
                                state = 28;
                                break;
                            case 78:
                                next();
                                state = 28;
                                break;
                            case 77:
                                next();
                                state = 28;
                                break;
                            case 76:
                                next();
                                state = 28;
                                break;
                            case 65:
                                next();
                                state = 28;
                                break;
                            case 112:
                                next();
                                state = 28;
                                break;
                            case 88:
                                next();
                                state = 28;
                                break;
                            case 89:
                                next();
                                state = 28;
                                break;
                            case 66:
                                next();
                                state = 28;
                                break;
                            case 113:
                                next();
                                state = 28;
                                break;
                            case 87:
                                next();
                                state = 28;
                                break;
                            case 116:
                                next();
                                state = 28;
                                break;
                            case 69:
                                next();
                                state = 28;
                                break;
                            case 115:
                                next();
                                state = 28;
                                break;
                            case 68:
                                next();
                                state = 28;
                                break;
                            case 114:
                                next();
                                state = 28;
                                break;
                            case 67:
                                next();
                                state = 28;
                                break;
                            case 90:
                                next();
                                state = 28;
                                break;
                            case 99:
                                next();
                                state = 28;
                                break;
                            case 52:
                                next();
                                state = 28;
                                break;
                            case 100:
                                next();
                                state = 28;
                                break;
                            case 53:
                                next();
                                state = 28;
                                break;
                            case 101:
                                next();
                                state = 28;
                                break;
                            case 54:
                                next();
                                state = 28;
                                break;
                            case 111:
                                next();
                                state = 41;
                                break;
                            case 110:
                                next();
                                state = 28;
                                break;
                            case 86:
                                next();
                                state = 28;
                                break;
                            case 109:
                                next();
                                state = 28;
                                break;
                            case 85:
                                next();
                                state = 28;
                                break;
                            case 108:
                                next();
                                state = 28;
                                break;
                            case 84:
                                next();
                                state = 28;
                                break;
                            case 107:
                                next();
                                state = 28;
                                break;
                            case 83:
                                next();
                                state = 28;
                                break;
                            case 106:
                                next();
                                state = 28;
                                break;
                            case 82:
                                next();
                                state = 28;
                                break;
                            case 105:
                                next();
                                state = 28;
                                break;
                            case 104:
                                next();
                                state = 28;
                                break;
                            case 57:
                                next();
                                state = 28;
                                break;
                            case 103:
                                next();
                                state = 28;
                                break;
                            case 56:
                                next();
                                state = 28;
                                break;
                            case 102:
                                next();
                                state = 28;
                                break;
                            default:
                                m_semantic.id(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 19:
                        switch (c) {
                            case 81:
                                next();
                                state = 28;
                                break;
                            case 49:
                                next();
                                state = 28;
                                break;
                            case 71:
                                next();
                                state = 28;
                                break;
                            case 118:
                                next();
                                state = 28;
                                break;
                            case 72:
                                next();
                                state = 28;
                                break;
                            case 119:
                                next();
                                state = 28;
                                break;
                            case 74:
                                next();
                                state = 28;
                                break;
                            case 121:
                                next();
                                state = 28;
                                break;
                            case 75:
                                next();
                                state = 28;
                                break;
                            case 122:
                                next();
                                state = 28;
                                break;
                            case 73:
                                next();
                                state = 28;
                                break;
                            case 120:
                                next();
                                state = 28;
                                break;
                            case 95:
                                next();
                                state = 28;
                                break;
                            case 48:
                                next();
                                state = 28;
                                break;
                            case 70:
                                next();
                                state = 28;
                                break;
                            case 117:
                                next();
                                state = 28;
                                break;
                            case 55:
                                next();
                                state = 28;
                                break;
                            case 98:
                                next();
                                state = 28;
                                break;
                            case 51:
                                next();
                                state = 28;
                                break;
                            case 50:
                                next();
                                state = 28;
                                break;
                            case 97:
                                next();
                                state = 28;
                                break;
                            case 80:
                                next();
                                state = 28;
                                break;
                            case 79:
                                next();
                                state = 28;
                                break;
                            case 78:
                                next();
                                state = 28;
                                break;
                            case 77:
                                next();
                                state = 28;
                                break;
                            case 76:
                                next();
                                state = 28;
                                break;
                            case 65:
                                next();
                                state = 28;
                                break;
                            case 112:
                                next();
                                state = 28;
                                break;
                            case 88:
                                next();
                                state = 28;
                                break;
                            case 89:
                                next();
                                state = 28;
                                break;
                            case 66:
                                next();
                                state = 28;
                                break;
                            case 113:
                                next();
                                state = 28;
                                break;
                            case 87:
                                next();
                                state = 28;
                                break;
                            case 116:
                                next();
                                state = 28;
                                break;
                            case 69:
                                next();
                                state = 28;
                                break;
                            case 115:
                                next();
                                state = 28;
                                break;
                            case 68:
                                next();
                                state = 28;
                                break;
                            case 114:
                                next();
                                state = 28;
                                break;
                            case 67:
                                next();
                                state = 28;
                                break;
                            case 90:
                                next();
                                state = 28;
                                break;
                            case 99:
                                next();
                                state = 28;
                                break;
                            case 52:
                                next();
                                state = 28;
                                break;
                            case 100:
                                next();
                                state = 28;
                                break;
                            case 53:
                                next();
                                state = 28;
                                break;
                            case 101:
                                next();
                                state = 28;
                                break;
                            case 54:
                                next();
                                state = 28;
                                break;
                            case 111:
                                next();
                                state = 28;
                                break;
                            case 110:
                                next();
                                state = 28;
                                break;
                            case 86:
                                next();
                                state = 28;
                                break;
                            case 109:
                                next();
                                state = 28;
                                break;
                            case 85:
                                next();
                                state = 28;
                                break;
                            case 108:
                                next();
                                state = 28;
                                break;
                            case 84:
                                next();
                                state = 28;
                                break;
                            case 107:
                                next();
                                state = 28;
                                break;
                            case 83:
                                next();
                                state = 28;
                                break;
                            case 106:
                                next();
                                state = 28;
                                break;
                            case 82:
                                next();
                                state = 28;
                                break;
                            case 105:
                                next();
                                state = 28;
                                break;
                            case 104:
                                next();
                                state = 28;
                                break;
                            case 57:
                                next();
                                state = 28;
                                break;
                            case 103:
                                next();
                                state = 28;
                                break;
                            case 56:
                                next();
                                state = 28;
                                break;
                            case 102:
                                next();
                                state = 28;
                                break;
                            default:
                                m_semantic.procedure(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 20:
                        switch (c) {
                            case 49:
                                next();
                                state = 28;
                                break;
                            case 71:
                                next();
                                state = 28;
                                break;
                            case 118:
                                next();
                                state = 28;
                                break;
                            case 72:
                                next();
                                state = 28;
                                break;
                            case 119:
                                next();
                                state = 28;
                                break;
                            case 74:
                                next();
                                state = 28;
                                break;
                            case 121:
                                next();
                                state = 28;
                                break;
                            case 75:
                                next();
                                state = 28;
                                break;
                            case 122:
                                next();
                                state = 28;
                                break;
                            case 73:
                                next();
                                state = 28;
                                break;
                            case 120:
                                next();
                                state = 28;
                                break;
                            case 95:
                                next();
                                state = 28;
                                break;
                            case 48:
                                next();
                                state = 28;
                                break;
                            case 70:
                                next();
                                state = 28;
                                break;
                            case 117:
                                next();
                                state = 28;
                                break;
                            case 86:
                                next();
                                state = 28;
                                break;
                            case 57:
                                next();
                                state = 28;
                                break;
                            case 98:
                                next();
                                state = 28;
                                break;
                            case 51:
                                next();
                                state = 28;
                                break;
                            case 50:
                                next();
                                state = 28;
                                break;
                            case 97:
                                next();
                                state = 28;
                                break;
                            case 81:
                                next();
                                state = 28;
                                break;
                            case 80:
                                next();
                                state = 28;
                                break;
                            case 79:
                                next();
                                state = 28;
                                break;
                            case 78:
                                next();
                                state = 28;
                                break;
                            case 77:
                                next();
                                state = 28;
                                break;
                            case 76:
                                next();
                                state = 28;
                                break;
                            case 65:
                                next();
                                state = 28;
                                break;
                            case 112:
                                next();
                                state = 28;
                                break;
                            case 88:
                                next();
                                state = 28;
                                break;
                            case 87:
                                next();
                                state = 28;
                                break;
                            case 116:
                                next();
                                state = 28;
                                break;
                            case 69:
                                next();
                                state = 28;
                                break;
                            case 115:
                                next();
                                state = 28;
                                break;
                            case 68:
                                next();
                                state = 28;
                                break;
                            case 89:
                                next();
                                state = 28;
                                break;
                            case 66:
                                next();
                                state = 28;
                                break;
                            case 113:
                                next();
                                state = 28;
                                break;
                            case 90:
                                next();
                                state = 28;
                                break;
                            case 67:
                                next();
                                state = 28;
                                break;
                            case 114:
                                next();
                                state = 40;
                                break;
                            case 99:
                                next();
                                state = 28;
                                break;
                            case 52:
                                next();
                                state = 28;
                                break;
                            case 100:
                                next();
                                state = 28;
                                break;
                            case 53:
                                next();
                                state = 28;
                                break;
                            case 101:
                                next();
                                state = 28;
                                break;
                            case 54:
                                next();
                                state = 28;
                                break;
                            case 102:
                                next();
                                state = 28;
                                break;
                            case 55:
                                next();
                                state = 28;
                                break;
                            case 103:
                                next();
                                state = 28;
                                break;
                            case 56:
                                next();
                                state = 28;
                                break;
                            case 111:
                                next();
                                state = 28;
                                break;
                            case 110:
                                next();
                                state = 28;
                                break;
                            case 109:
                                next();
                                state = 28;
                                break;
                            case 85:
                                next();
                                state = 28;
                                break;
                            case 108:
                                next();
                                state = 28;
                                break;
                            case 84:
                                next();
                                state = 28;
                                break;
                            case 107:
                                next();
                                state = 28;
                                break;
                            case 83:
                                next();
                                state = 28;
                                break;
                            case 106:
                                next();
                                state = 28;
                                break;
                            case 82:
                                next();
                                state = 28;
                                break;
                            case 105:
                                next();
                                state = 28;
                                break;
                            case 104:
                                next();
                                state = 28;
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
                                state = 28;
                                break;
                            case 49:
                                next();
                                state = 28;
                                break;
                            case 71:
                                next();
                                state = 28;
                                break;
                            case 118:
                                next();
                                state = 28;
                                break;
                            case 72:
                                next();
                                state = 28;
                                break;
                            case 119:
                                next();
                                state = 28;
                                break;
                            case 74:
                                next();
                                state = 28;
                                break;
                            case 121:
                                next();
                                state = 28;
                                break;
                            case 75:
                                next();
                                state = 28;
                                break;
                            case 122:
                                next();
                                state = 28;
                                break;
                            case 73:
                                next();
                                state = 28;
                                break;
                            case 120:
                                next();
                                state = 28;
                                break;
                            case 95:
                                next();
                                state = 28;
                                break;
                            case 48:
                                next();
                                state = 28;
                                break;
                            case 70:
                                next();
                                state = 28;
                                break;
                            case 117:
                                next();
                                state = 28;
                                break;
                            case 56:
                                next();
                                state = 28;
                                break;
                            case 98:
                                next();
                                state = 28;
                                break;
                            case 51:
                                next();
                                state = 28;
                                break;
                            case 50:
                                next();
                                state = 28;
                                break;
                            case 97:
                                next();
                                state = 28;
                                break;
                            case 80:
                                next();
                                state = 28;
                                break;
                            case 79:
                                next();
                                state = 28;
                                break;
                            case 78:
                                next();
                                state = 28;
                                break;
                            case 77:
                                next();
                                state = 28;
                                break;
                            case 76:
                                next();
                                state = 28;
                                break;
                            case 65:
                                next();
                                state = 28;
                                break;
                            case 112:
                                next();
                                state = 28;
                                break;
                            case 88:
                                next();
                                state = 28;
                                break;
                            case 89:
                                next();
                                state = 28;
                                break;
                            case 66:
                                next();
                                state = 28;
                                break;
                            case 113:
                                next();
                                state = 28;
                                break;
                            case 87:
                                next();
                                state = 28;
                                break;
                            case 116:
                                next();
                                state = 28;
                                break;
                            case 69:
                                next();
                                state = 28;
                                break;
                            case 115:
                                next();
                                state = 28;
                                break;
                            case 68:
                                next();
                                state = 28;
                                break;
                            case 114:
                                next();
                                state = 28;
                                break;
                            case 67:
                                next();
                                state = 28;
                                break;
                            case 90:
                                next();
                                state = 28;
                                break;
                            case 99:
                                next();
                                state = 28;
                                break;
                            case 52:
                                next();
                                state = 28;
                                break;
                            case 101:
                                next();
                                state = 28;
                                break;
                            case 54:
                                next();
                                state = 28;
                                break;
                            case 102:
                                next();
                                state = 28;
                                break;
                            case 55:
                                next();
                                state = 28;
                                break;
                            case 100:
                                next();
                                state = 22;
                                break;
                            case 53:
                                next();
                                state = 28;
                                break;
                            case 111:
                                next();
                                state = 28;
                                break;
                            case 110:
                                next();
                                state = 28;
                                break;
                            case 86:
                                next();
                                state = 28;
                                break;
                            case 109:
                                next();
                                state = 28;
                                break;
                            case 85:
                                next();
                                state = 28;
                                break;
                            case 108:
                                next();
                                state = 28;
                                break;
                            case 84:
                                next();
                                state = 28;
                                break;
                            case 107:
                                next();
                                state = 28;
                                break;
                            case 83:
                                next();
                                state = 28;
                                break;
                            case 106:
                                next();
                                state = 28;
                                break;
                            case 82:
                                next();
                                state = 28;
                                break;
                            case 105:
                                next();
                                state = 28;
                                break;
                            case 104:
                                next();
                                state = 28;
                                break;
                            case 57:
                                next();
                                state = 28;
                                break;
                            case 103:
                                next();
                                state = 28;
                                break;
                            default:
                                m_semantic.id(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 22:
                        switch (c) {
                            case 81:
                                next();
                                state = 28;
                                break;
                            case 49:
                                next();
                                state = 28;
                                break;
                            case 71:
                                next();
                                state = 28;
                                break;
                            case 118:
                                next();
                                state = 28;
                                break;
                            case 72:
                                next();
                                state = 28;
                                break;
                            case 119:
                                next();
                                state = 28;
                                break;
                            case 74:
                                next();
                                state = 28;
                                break;
                            case 121:
                                next();
                                state = 28;
                                break;
                            case 75:
                                next();
                                state = 28;
                                break;
                            case 122:
                                next();
                                state = 28;
                                break;
                            case 73:
                                next();
                                state = 28;
                                break;
                            case 120:
                                next();
                                state = 28;
                                break;
                            case 95:
                                next();
                                state = 28;
                                break;
                            case 48:
                                next();
                                state = 28;
                                break;
                            case 70:
                                next();
                                state = 28;
                                break;
                            case 117:
                                next();
                                state = 28;
                                break;
                            case 55:
                                next();
                                state = 28;
                                break;
                            case 98:
                                next();
                                state = 28;
                                break;
                            case 51:
                                next();
                                state = 28;
                                break;
                            case 50:
                                next();
                                state = 28;
                                break;
                            case 97:
                                next();
                                state = 28;
                                break;
                            case 80:
                                next();
                                state = 28;
                                break;
                            case 79:
                                next();
                                state = 28;
                                break;
                            case 78:
                                next();
                                state = 28;
                                break;
                            case 77:
                                next();
                                state = 28;
                                break;
                            case 76:
                                next();
                                state = 28;
                                break;
                            case 65:
                                next();
                                state = 28;
                                break;
                            case 112:
                                next();
                                state = 28;
                                break;
                            case 88:
                                next();
                                state = 28;
                                break;
                            case 89:
                                next();
                                state = 28;
                                break;
                            case 66:
                                next();
                                state = 28;
                                break;
                            case 113:
                                next();
                                state = 28;
                                break;
                            case 87:
                                next();
                                state = 28;
                                break;
                            case 116:
                                next();
                                state = 28;
                                break;
                            case 69:
                                next();
                                state = 28;
                                break;
                            case 115:
                                next();
                                state = 28;
                                break;
                            case 68:
                                next();
                                state = 28;
                                break;
                            case 114:
                                next();
                                state = 28;
                                break;
                            case 67:
                                next();
                                state = 28;
                                break;
                            case 90:
                                next();
                                state = 28;
                                break;
                            case 99:
                                next();
                                state = 28;
                                break;
                            case 52:
                                next();
                                state = 28;
                                break;
                            case 100:
                                next();
                                state = 28;
                                break;
                            case 53:
                                next();
                                state = 28;
                                break;
                            case 101:
                                next();
                                state = 28;
                                break;
                            case 54:
                                next();
                                state = 28;
                                break;
                            case 111:
                                next();
                                state = 28;
                                break;
                            case 110:
                                next();
                                state = 28;
                                break;
                            case 86:
                                next();
                                state = 28;
                                break;
                            case 109:
                                next();
                                state = 28;
                                break;
                            case 85:
                                next();
                                state = 28;
                                break;
                            case 108:
                                next();
                                state = 28;
                                break;
                            case 84:
                                next();
                                state = 28;
                                break;
                            case 107:
                                next();
                                state = 28;
                                break;
                            case 83:
                                next();
                                state = 28;
                                break;
                            case 106:
                                next();
                                state = 28;
                                break;
                            case 82:
                                next();
                                state = 28;
                                break;
                            case 105:
                                next();
                                state = 28;
                                break;
                            case 104:
                                next();
                                state = 28;
                                break;
                            case 57:
                                next();
                                state = 28;
                                break;
                            case 103:
                                next();
                                state = 28;
                                break;
                            case 56:
                                next();
                                state = 28;
                                break;
                            case 102:
                                next();
                                state = 28;
                                break;
                            default:
                                m_semantic.end(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 23:
                        switch (c) {
                            case 103:
                                next();
                                state = 28;
                                break;
                            case 57:
                                next();
                                state = 28;
                                break;
                            case 104:
                                next();
                                state = 28;
                                break;
                            case 105:
                                next();
                                state = 28;
                                break;
                            case 82:
                                next();
                                state = 28;
                                break;
                            case 106:
                                next();
                                state = 28;
                                break;
                            case 83:
                                next();
                                state = 28;
                                break;
                            case 107:
                                next();
                                state = 28;
                                break;
                            case 84:
                                next();
                                state = 28;
                                break;
                            case 108:
                                next();
                                state = 28;
                                break;
                            case 85:
                                next();
                                state = 28;
                                break;
                            case 109:
                                next();
                                state = 28;
                                break;
                            case 111:
                                next();
                                state = 28;
                                break;
                            case 110:
                                next();
                                state = 28;
                                break;
                            case 55:
                                next();
                                state = 28;
                                break;
                            case 102:
                                next();
                                state = 28;
                                break;
                            case 54:
                                next();
                                state = 28;
                                break;
                            case 81:
                                next();
                                state = 28;
                                break;
                            case 56:
                                next();
                                state = 28;
                                break;
                            case 86:
                                next();
                                state = 28;
                                break;
                            case 70:
                                next();
                                state = 28;
                                break;
                            case 117:
                                next();
                                state = 28;
                                break;
                            case 48:
                                next();
                                state = 28;
                                break;
                            case 95:
                                next();
                                state = 28;
                                break;
                            case 71:
                                next();
                                state = 28;
                                break;
                            case 118:
                                next();
                                state = 28;
                                break;
                            case 97:
                                next();
                                state = 28;
                                break;
                            case 50:
                                next();
                                state = 28;
                                break;
                            case 51:
                                next();
                                state = 28;
                                break;
                            case 98:
                                next();
                                state = 28;
                                break;
                            case 120:
                                next();
                                state = 28;
                                break;
                            case 73:
                                next();
                                state = 28;
                                break;
                            case 74:
                                next();
                                state = 28;
                                break;
                            case 121:
                                next();
                                state = 28;
                                break;
                            case 49:
                                next();
                                state = 28;
                                break;
                            case 72:
                                next();
                                state = 28;
                                break;
                            case 119:
                                next();
                                state = 28;
                                break;
                            case 75:
                                next();
                                state = 28;
                                break;
                            case 122:
                                next();
                                state = 28;
                                break;
                            case 80:
                                next();
                                state = 28;
                                break;
                            case 79:
                                next();
                                state = 28;
                                break;
                            case 78:
                                next();
                                state = 28;
                                break;
                            case 77:
                                next();
                                state = 28;
                                break;
                            case 76:
                                next();
                                state = 28;
                                break;
                            case 65:
                                next();
                                state = 28;
                                break;
                            case 112:
                                next();
                                state = 28;
                                break;
                            case 88:
                                next();
                                state = 28;
                                break;
                            case 89:
                                next();
                                state = 28;
                                break;
                            case 66:
                                next();
                                state = 28;
                                break;
                            case 113:
                                next();
                                state = 28;
                                break;
                            case 87:
                                next();
                                state = 28;
                                break;
                            case 116:
                                next();
                                state = 28;
                                break;
                            case 69:
                                next();
                                state = 28;
                                break;
                            case 115:
                                next();
                                state = 28;
                                break;
                            case 68:
                                next();
                                state = 28;
                                break;
                            case 114:
                                next();
                                state = 18;
                                break;
                            case 67:
                                next();
                                state = 28;
                                break;
                            case 90:
                                next();
                                state = 28;
                                break;
                            case 99:
                                next();
                                state = 28;
                                break;
                            case 52:
                                next();
                                state = 28;
                                break;
                            case 100:
                                next();
                                state = 28;
                                break;
                            case 53:
                                next();
                                state = 28;
                                break;
                            case 101:
                                next();
                                state = 28;
                                break;
                            default:
                                m_semantic.id(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 24:
                        switch (c) {
                            case 49:
                                next();
                                state = 28;
                                break;
                            case 71:
                                next();
                                state = 28;
                                break;
                            case 118:
                                next();
                                state = 28;
                                break;
                            case 72:
                                next();
                                state = 28;
                                break;
                            case 119:
                                next();
                                state = 28;
                                break;
                            case 74:
                                next();
                                state = 28;
                                break;
                            case 121:
                                next();
                                state = 28;
                                break;
                            case 75:
                                next();
                                state = 28;
                                break;
                            case 122:
                                next();
                                state = 28;
                                break;
                            case 73:
                                next();
                                state = 28;
                                break;
                            case 120:
                                next();
                                state = 28;
                                break;
                            case 95:
                                next();
                                state = 28;
                                break;
                            case 48:
                                next();
                                state = 28;
                                break;
                            case 70:
                                next();
                                state = 28;
                                break;
                            case 117:
                                next();
                                state = 28;
                                break;
                            case 86:
                                next();
                                state = 28;
                                break;
                            case 57:
                                next();
                                state = 28;
                                break;
                            case 98:
                                next();
                                state = 28;
                                break;
                            case 51:
                                next();
                                state = 28;
                                break;
                            case 50:
                                next();
                                state = 28;
                                break;
                            case 97:
                                next();
                                state = 28;
                                break;
                            case 81:
                                next();
                                state = 28;
                                break;
                            case 80:
                                next();
                                state = 28;
                                break;
                            case 79:
                                next();
                                state = 28;
                                break;
                            case 78:
                                next();
                                state = 28;
                                break;
                            case 77:
                                next();
                                state = 28;
                                break;
                            case 76:
                                next();
                                state = 28;
                                break;
                            case 65:
                                next();
                                state = 28;
                                break;
                            case 112:
                                next();
                                state = 28;
                                break;
                            case 88:
                                next();
                                state = 28;
                                break;
                            case 87:
                                next();
                                state = 28;
                                break;
                            case 116:
                                next();
                                state = 28;
                                break;
                            case 69:
                                next();
                                state = 28;
                                break;
                            case 115:
                                next();
                                state = 28;
                                break;
                            case 68:
                                next();
                                state = 28;
                                break;
                            case 89:
                                next();
                                state = 28;
                                break;
                            case 66:
                                next();
                                state = 28;
                                break;
                            case 113:
                                next();
                                state = 28;
                                break;
                            case 90:
                                next();
                                state = 28;
                                break;
                            case 67:
                                next();
                                state = 28;
                                break;
                            case 114:
                                next();
                                state = 25;
                                break;
                            case 99:
                                next();
                                state = 28;
                                break;
                            case 52:
                                next();
                                state = 28;
                                break;
                            case 100:
                                next();
                                state = 28;
                                break;
                            case 53:
                                next();
                                state = 28;
                                break;
                            case 101:
                                next();
                                state = 28;
                                break;
                            case 54:
                                next();
                                state = 28;
                                break;
                            case 102:
                                next();
                                state = 28;
                                break;
                            case 55:
                                next();
                                state = 28;
                                break;
                            case 103:
                                next();
                                state = 28;
                                break;
                            case 56:
                                next();
                                state = 28;
                                break;
                            case 111:
                                next();
                                state = 28;
                                break;
                            case 110:
                                next();
                                state = 28;
                                break;
                            case 109:
                                next();
                                state = 28;
                                break;
                            case 85:
                                next();
                                state = 28;
                                break;
                            case 108:
                                next();
                                state = 28;
                                break;
                            case 84:
                                next();
                                state = 28;
                                break;
                            case 107:
                                next();
                                state = 28;
                                break;
                            case 83:
                                next();
                                state = 28;
                                break;
                            case 106:
                                next();
                                state = 28;
                                break;
                            case 82:
                                next();
                                state = 28;
                                break;
                            case 105:
                                next();
                                state = 28;
                                break;
                            case 104:
                                next();
                                state = 28;
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
                                state = 28;
                                break;
                            case 49:
                                next();
                                state = 28;
                                break;
                            case 71:
                                next();
                                state = 28;
                                break;
                            case 118:
                                next();
                                state = 28;
                                break;
                            case 72:
                                next();
                                state = 28;
                                break;
                            case 119:
                                next();
                                state = 28;
                                break;
                            case 74:
                                next();
                                state = 28;
                                break;
                            case 121:
                                next();
                                state = 28;
                                break;
                            case 75:
                                next();
                                state = 28;
                                break;
                            case 122:
                                next();
                                state = 28;
                                break;
                            case 73:
                                next();
                                state = 28;
                                break;
                            case 120:
                                next();
                                state = 28;
                                break;
                            case 95:
                                next();
                                state = 28;
                                break;
                            case 48:
                                next();
                                state = 28;
                                break;
                            case 70:
                                next();
                                state = 28;
                                break;
                            case 117:
                                next();
                                state = 28;
                                break;
                            case 55:
                                next();
                                state = 28;
                                break;
                            case 98:
                                next();
                                state = 28;
                                break;
                            case 51:
                                next();
                                state = 28;
                                break;
                            case 50:
                                next();
                                state = 28;
                                break;
                            case 97:
                                next();
                                state = 28;
                                break;
                            case 80:
                                next();
                                state = 28;
                                break;
                            case 79:
                                next();
                                state = 28;
                                break;
                            case 78:
                                next();
                                state = 28;
                                break;
                            case 77:
                                next();
                                state = 28;
                                break;
                            case 76:
                                next();
                                state = 28;
                                break;
                            case 65:
                                next();
                                state = 28;
                                break;
                            case 112:
                                next();
                                state = 28;
                                break;
                            case 88:
                                next();
                                state = 28;
                                break;
                            case 89:
                                next();
                                state = 28;
                                break;
                            case 66:
                                next();
                                state = 28;
                                break;
                            case 113:
                                next();
                                state = 28;
                                break;
                            case 87:
                                next();
                                state = 28;
                                break;
                            case 116:
                                next();
                                state = 28;
                                break;
                            case 69:
                                next();
                                state = 28;
                                break;
                            case 115:
                                next();
                                state = 28;
                                break;
                            case 68:
                                next();
                                state = 28;
                                break;
                            case 114:
                                next();
                                state = 28;
                                break;
                            case 67:
                                next();
                                state = 28;
                                break;
                            case 90:
                                next();
                                state = 28;
                                break;
                            case 99:
                                next();
                                state = 28;
                                break;
                            case 52:
                                next();
                                state = 28;
                                break;
                            case 100:
                                next();
                                state = 28;
                                break;
                            case 53:
                                next();
                                state = 28;
                                break;
                            case 101:
                                next();
                                state = 28;
                                break;
                            case 54:
                                next();
                                state = 28;
                                break;
                            case 111:
                                next();
                                state = 28;
                                break;
                            case 110:
                                next();
                                state = 28;
                                break;
                            case 86:
                                next();
                                state = 28;
                                break;
                            case 109:
                                next();
                                state = 28;
                                break;
                            case 85:
                                next();
                                state = 28;
                                break;
                            case 108:
                                next();
                                state = 28;
                                break;
                            case 84:
                                next();
                                state = 28;
                                break;
                            case 107:
                                next();
                                state = 28;
                                break;
                            case 83:
                                next();
                                state = 28;
                                break;
                            case 106:
                                next();
                                state = 28;
                                break;
                            case 82:
                                next();
                                state = 28;
                                break;
                            case 105:
                                next();
                                state = 28;
                                break;
                            case 104:
                                next();
                                state = 28;
                                break;
                            case 57:
                                next();
                                state = 28;
                                break;
                            case 103:
                                next();
                                state = 28;
                                break;
                            case 56:
                                next();
                                state = 28;
                                break;
                            case 102:
                                next();
                                state = 28;
                                break;
                            default:
                                m_semantic.var(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 26:
                        switch (c) {
                            case 81:
                                next();
                                state = 28;
                                break;
                            case 49:
                                next();
                                state = 28;
                                break;
                            case 71:
                                next();
                                state = 28;
                                break;
                            case 118:
                                next();
                                state = 28;
                                break;
                            case 72:
                                next();
                                state = 28;
                                break;
                            case 119:
                                next();
                                state = 28;
                                break;
                            case 74:
                                next();
                                state = 28;
                                break;
                            case 121:
                                next();
                                state = 28;
                                break;
                            case 75:
                                next();
                                state = 28;
                                break;
                            case 122:
                                next();
                                state = 28;
                                break;
                            case 73:
                                next();
                                state = 28;
                                break;
                            case 120:
                                next();
                                state = 28;
                                break;
                            case 95:
                                next();
                                state = 28;
                                break;
                            case 48:
                                next();
                                state = 28;
                                break;
                            case 70:
                                next();
                                state = 28;
                                break;
                            case 117:
                                next();
                                state = 28;
                                break;
                            case 55:
                                next();
                                state = 28;
                                break;
                            case 98:
                                next();
                                state = 28;
                                break;
                            case 51:
                                next();
                                state = 28;
                                break;
                            case 50:
                                next();
                                state = 28;
                                break;
                            case 97:
                                next();
                                state = 28;
                                break;
                            case 80:
                                next();
                                state = 28;
                                break;
                            case 79:
                                next();
                                state = 28;
                                break;
                            case 78:
                                next();
                                state = 28;
                                break;
                            case 77:
                                next();
                                state = 28;
                                break;
                            case 76:
                                next();
                                state = 28;
                                break;
                            case 65:
                                next();
                                state = 28;
                                break;
                            case 112:
                                next();
                                state = 28;
                                break;
                            case 88:
                                next();
                                state = 28;
                                break;
                            case 89:
                                next();
                                state = 28;
                                break;
                            case 66:
                                next();
                                state = 28;
                                break;
                            case 113:
                                next();
                                state = 28;
                                break;
                            case 87:
                                next();
                                state = 28;
                                break;
                            case 116:
                                next();
                                state = 28;
                                break;
                            case 69:
                                next();
                                state = 28;
                                break;
                            case 115:
                                next();
                                state = 28;
                                break;
                            case 68:
                                next();
                                state = 28;
                                break;
                            case 114:
                                next();
                                state = 28;
                                break;
                            case 67:
                                next();
                                state = 28;
                                break;
                            case 90:
                                next();
                                state = 28;
                                break;
                            case 99:
                                next();
                                state = 28;
                                break;
                            case 52:
                                next();
                                state = 28;
                                break;
                            case 100:
                                next();
                                state = 28;
                                break;
                            case 53:
                                next();
                                state = 28;
                                break;
                            case 101:
                                next();
                                state = 11;
                                break;
                            case 54:
                                next();
                                state = 28;
                                break;
                            case 111:
                                next();
                                state = 28;
                                break;
                            case 110:
                                next();
                                state = 28;
                                break;
                            case 86:
                                next();
                                state = 28;
                                break;
                            case 109:
                                next();
                                state = 28;
                                break;
                            case 85:
                                next();
                                state = 28;
                                break;
                            case 108:
                                next();
                                state = 28;
                                break;
                            case 84:
                                next();
                                state = 28;
                                break;
                            case 107:
                                next();
                                state = 28;
                                break;
                            case 83:
                                next();
                                state = 28;
                                break;
                            case 106:
                                next();
                                state = 28;
                                break;
                            case 82:
                                next();
                                state = 28;
                                break;
                            case 105:
                                next();
                                state = 28;
                                break;
                            case 104:
                                next();
                                state = 28;
                                break;
                            case 57:
                                next();
                                state = 28;
                                break;
                            case 103:
                                next();
                                state = 28;
                                break;
                            case 56:
                                next();
                                state = 28;
                                break;
                            case 102:
                                next();
                                state = 28;
                                break;
                            default:
                                m_semantic.id(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 27:
                        switch (c) {
                            case 103:
                                next();
                                state = 28;
                                break;
                            case 57:
                                next();
                                state = 28;
                                break;
                            case 104:
                                next();
                                state = 28;
                                break;
                            case 105:
                                next();
                                state = 28;
                                break;
                            case 82:
                                next();
                                state = 28;
                                break;
                            case 106:
                                next();
                                state = 28;
                                break;
                            case 83:
                                next();
                                state = 28;
                                break;
                            case 107:
                                next();
                                state = 28;
                                break;
                            case 84:
                                next();
                                state = 28;
                                break;
                            case 108:
                                next();
                                state = 28;
                                break;
                            case 85:
                                next();
                                state = 28;
                                break;
                            case 109:
                                next();
                                state = 28;
                                break;
                            case 111:
                                next();
                                state = 28;
                                break;
                            case 110:
                                next();
                                state = 28;
                                break;
                            case 55:
                                next();
                                state = 28;
                                break;
                            case 102:
                                next();
                                state = 28;
                                break;
                            case 54:
                                next();
                                state = 28;
                                break;
                            case 81:
                                next();
                                state = 28;
                                break;
                            case 56:
                                next();
                                state = 28;
                                break;
                            case 86:
                                next();
                                state = 28;
                                break;
                            case 70:
                                next();
                                state = 28;
                                break;
                            case 117:
                                next();
                                state = 28;
                                break;
                            case 48:
                                next();
                                state = 28;
                                break;
                            case 95:
                                next();
                                state = 28;
                                break;
                            case 71:
                                next();
                                state = 28;
                                break;
                            case 118:
                                next();
                                state = 28;
                                break;
                            case 97:
                                next();
                                state = 24;
                                break;
                            case 50:
                                next();
                                state = 28;
                                break;
                            case 51:
                                next();
                                state = 28;
                                break;
                            case 98:
                                next();
                                state = 28;
                                break;
                            case 120:
                                next();
                                state = 28;
                                break;
                            case 73:
                                next();
                                state = 28;
                                break;
                            case 74:
                                next();
                                state = 28;
                                break;
                            case 121:
                                next();
                                state = 28;
                                break;
                            case 49:
                                next();
                                state = 28;
                                break;
                            case 72:
                                next();
                                state = 28;
                                break;
                            case 119:
                                next();
                                state = 28;
                                break;
                            case 75:
                                next();
                                state = 28;
                                break;
                            case 122:
                                next();
                                state = 28;
                                break;
                            case 80:
                                next();
                                state = 28;
                                break;
                            case 79:
                                next();
                                state = 28;
                                break;
                            case 78:
                                next();
                                state = 28;
                                break;
                            case 77:
                                next();
                                state = 28;
                                break;
                            case 76:
                                next();
                                state = 28;
                                break;
                            case 65:
                                next();
                                state = 28;
                                break;
                            case 112:
                                next();
                                state = 28;
                                break;
                            case 88:
                                next();
                                state = 28;
                                break;
                            case 89:
                                next();
                                state = 28;
                                break;
                            case 66:
                                next();
                                state = 28;
                                break;
                            case 113:
                                next();
                                state = 28;
                                break;
                            case 87:
                                next();
                                state = 28;
                                break;
                            case 116:
                                next();
                                state = 28;
                                break;
                            case 69:
                                next();
                                state = 28;
                                break;
                            case 115:
                                next();
                                state = 28;
                                break;
                            case 68:
                                next();
                                state = 28;
                                break;
                            case 114:
                                next();
                                state = 28;
                                break;
                            case 67:
                                next();
                                state = 28;
                                break;
                            case 90:
                                next();
                                state = 28;
                                break;
                            case 99:
                                next();
                                state = 28;
                                break;
                            case 52:
                                next();
                                state = 28;
                                break;
                            case 100:
                                next();
                                state = 28;
                                break;
                            case 53:
                                next();
                                state = 28;
                                break;
                            case 101:
                                next();
                                state = 28;
                                break;
                            default:
                                m_semantic.id(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 28:
                        switch (c) {
                            case 88:
                                next();
                                state = 28;
                                break;
                            case 87:
                                next();
                                state = 28;
                                break;
                            case 116:
                                next();
                                state = 28;
                                break;
                            case 69:
                                next();
                                state = 28;
                                break;
                            case 115:
                                next();
                                state = 28;
                                break;
                            case 68:
                                next();
                                state = 28;
                                break;
                            case 114:
                                next();
                                state = 28;
                                break;
                            case 67:
                                next();
                                state = 28;
                                break;
                            case 113:
                                next();
                                state = 28;
                                break;
                            case 66:
                                next();
                                state = 28;
                                break;
                            case 112:
                                next();
                                state = 28;
                                break;
                            case 65:
                                next();
                                state = 28;
                                break;
                            case 76:
                                next();
                                state = 28;
                                break;
                            case 77:
                                next();
                                state = 28;
                                break;
                            case 78:
                                next();
                                state = 28;
                                break;
                            case 79:
                                next();
                                state = 28;
                                break;
                            case 80:
                                next();
                                state = 28;
                                break;
                            case 89:
                                next();
                                state = 28;
                                break;
                            case 90:
                                next();
                                state = 28;
                                break;
                            case 97:
                                next();
                                state = 28;
                                break;
                            case 50:
                                next();
                                state = 28;
                                break;
                            case 98:
                                next();
                                state = 28;
                                break;
                            case 51:
                                next();
                                state = 28;
                                break;
                            case 99:
                                next();
                                state = 28;
                                break;
                            case 52:
                                next();
                                state = 28;
                                break;
                            case 100:
                                next();
                                state = 28;
                                break;
                            case 53:
                                next();
                                state = 28;
                                break;
                            case 101:
                                next();
                                state = 28;
                                break;
                            case 54:
                                next();
                                state = 28;
                                break;
                            case 111:
                                next();
                                state = 28;
                                break;
                            case 110:
                                next();
                                state = 28;
                                break;
                            case 86:
                                next();
                                state = 28;
                                break;
                            case 109:
                                next();
                                state = 28;
                                break;
                            case 85:
                                next();
                                state = 28;
                                break;
                            case 108:
                                next();
                                state = 28;
                                break;
                            case 84:
                                next();
                                state = 28;
                                break;
                            case 107:
                                next();
                                state = 28;
                                break;
                            case 83:
                                next();
                                state = 28;
                                break;
                            case 106:
                                next();
                                state = 28;
                                break;
                            case 82:
                                next();
                                state = 28;
                                break;
                            case 105:
                                next();
                                state = 28;
                                break;
                            case 104:
                                next();
                                state = 28;
                                break;
                            case 57:
                                next();
                                state = 28;
                                break;
                            case 103:
                                next();
                                state = 28;
                                break;
                            case 56:
                                next();
                                state = 28;
                                break;
                            case 102:
                                next();
                                state = 28;
                                break;
                            case 55:
                                next();
                                state = 28;
                                break;
                            case 117:
                                next();
                                state = 28;
                                break;
                            case 70:
                                next();
                                state = 28;
                                break;
                            case 48:
                                next();
                                state = 28;
                                break;
                            case 95:
                                next();
                                state = 28;
                                break;
                            case 120:
                                next();
                                state = 28;
                                break;
                            case 73:
                                next();
                                state = 28;
                                break;
                            case 122:
                                next();
                                state = 28;
                                break;
                            case 75:
                                next();
                                state = 28;
                                break;
                            case 121:
                                next();
                                state = 28;
                                break;
                            case 74:
                                next();
                                state = 28;
                                break;
                            case 119:
                                next();
                                state = 28;
                                break;
                            case 72:
                                next();
                                state = 28;
                                break;
                            case 118:
                                next();
                                state = 28;
                                break;
                            case 71:
                                next();
                                state = 28;
                                break;
                            case 49:
                                next();
                                state = 28;
                                break;
                            case 81:
                                next();
                                state = 28;
                                break;
                            default:
                                m_semantic.id(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 29:
                        switch (c) {
                            case 103:
                                next();
                                state = 28;
                                break;
                            case 57:
                                next();
                                state = 28;
                                break;
                            case 104:
                                next();
                                state = 28;
                                break;
                            case 105:
                                next();
                                state = 28;
                                break;
                            case 82:
                                next();
                                state = 28;
                                break;
                            case 106:
                                next();
                                state = 28;
                                break;
                            case 83:
                                next();
                                state = 28;
                                break;
                            case 107:
                                next();
                                state = 28;
                                break;
                            case 84:
                                next();
                                state = 28;
                                break;
                            case 108:
                                next();
                                state = 28;
                                break;
                            case 85:
                                next();
                                state = 28;
                                break;
                            case 109:
                                next();
                                state = 28;
                                break;
                            case 111:
                                next();
                                state = 28;
                                break;
                            case 110:
                                next();
                                state = 21;
                                break;
                            case 55:
                                next();
                                state = 28;
                                break;
                            case 102:
                                next();
                                state = 28;
                                break;
                            case 54:
                                next();
                                state = 28;
                                break;
                            case 81:
                                next();
                                state = 28;
                                break;
                            case 56:
                                next();
                                state = 28;
                                break;
                            case 86:
                                next();
                                state = 28;
                                break;
                            case 70:
                                next();
                                state = 28;
                                break;
                            case 117:
                                next();
                                state = 28;
                                break;
                            case 48:
                                next();
                                state = 28;
                                break;
                            case 95:
                                next();
                                state = 28;
                                break;
                            case 71:
                                next();
                                state = 28;
                                break;
                            case 118:
                                next();
                                state = 28;
                                break;
                            case 97:
                                next();
                                state = 28;
                                break;
                            case 50:
                                next();
                                state = 28;
                                break;
                            case 51:
                                next();
                                state = 28;
                                break;
                            case 98:
                                next();
                                state = 28;
                                break;
                            case 120:
                                next();
                                state = 28;
                                break;
                            case 73:
                                next();
                                state = 28;
                                break;
                            case 74:
                                next();
                                state = 28;
                                break;
                            case 121:
                                next();
                                state = 28;
                                break;
                            case 49:
                                next();
                                state = 28;
                                break;
                            case 72:
                                next();
                                state = 28;
                                break;
                            case 119:
                                next();
                                state = 28;
                                break;
                            case 75:
                                next();
                                state = 28;
                                break;
                            case 122:
                                next();
                                state = 28;
                                break;
                            case 80:
                                next();
                                state = 28;
                                break;
                            case 79:
                                next();
                                state = 28;
                                break;
                            case 78:
                                next();
                                state = 28;
                                break;
                            case 77:
                                next();
                                state = 28;
                                break;
                            case 76:
                                next();
                                state = 28;
                                break;
                            case 65:
                                next();
                                state = 28;
                                break;
                            case 112:
                                next();
                                state = 28;
                                break;
                            case 88:
                                next();
                                state = 28;
                                break;
                            case 89:
                                next();
                                state = 28;
                                break;
                            case 66:
                                next();
                                state = 28;
                                break;
                            case 113:
                                next();
                                state = 28;
                                break;
                            case 87:
                                next();
                                state = 28;
                                break;
                            case 116:
                                next();
                                state = 28;
                                break;
                            case 69:
                                next();
                                state = 28;
                                break;
                            case 115:
                                next();
                                state = 28;
                                break;
                            case 68:
                                next();
                                state = 28;
                                break;
                            case 114:
                                next();
                                state = 28;
                                break;
                            case 67:
                                next();
                                state = 28;
                                break;
                            case 90:
                                next();
                                state = 28;
                                break;
                            case 99:
                                next();
                                state = 28;
                                break;
                            case 52:
                                next();
                                state = 28;
                                break;
                            case 100:
                                next();
                                state = 28;
                                break;
                            case 53:
                                next();
                                state = 28;
                                break;
                            case 101:
                                next();
                                state = 28;
                                break;
                            default:
                                m_semantic.id(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 30:
                        switch (c) {
                            case 81:
                                next();
                                state = 28;
                                break;
                            case 49:
                                next();
                                state = 28;
                                break;
                            case 71:
                                next();
                                state = 28;
                                break;
                            case 118:
                                next();
                                state = 28;
                                break;
                            case 72:
                                next();
                                state = 28;
                                break;
                            case 119:
                                next();
                                state = 28;
                                break;
                            case 74:
                                next();
                                state = 28;
                                break;
                            case 121:
                                next();
                                state = 28;
                                break;
                            case 75:
                                next();
                                state = 28;
                                break;
                            case 122:
                                next();
                                state = 28;
                                break;
                            case 73:
                                next();
                                state = 28;
                                break;
                            case 120:
                                next();
                                state = 28;
                                break;
                            case 95:
                                next();
                                state = 28;
                                break;
                            case 48:
                                next();
                                state = 28;
                                break;
                            case 70:
                                next();
                                state = 28;
                                break;
                            case 117:
                                next();
                                state = 28;
                                break;
                            case 55:
                                next();
                                state = 28;
                                break;
                            case 98:
                                next();
                                state = 28;
                                break;
                            case 51:
                                next();
                                state = 28;
                                break;
                            case 50:
                                next();
                                state = 28;
                                break;
                            case 97:
                                next();
                                state = 28;
                                break;
                            case 80:
                                next();
                                state = 28;
                                break;
                            case 79:
                                next();
                                state = 28;
                                break;
                            case 78:
                                next();
                                state = 28;
                                break;
                            case 77:
                                next();
                                state = 28;
                                break;
                            case 76:
                                next();
                                state = 28;
                                break;
                            case 65:
                                next();
                                state = 28;
                                break;
                            case 112:
                                next();
                                state = 28;
                                break;
                            case 88:
                                next();
                                state = 28;
                                break;
                            case 89:
                                next();
                                state = 28;
                                break;
                            case 66:
                                next();
                                state = 28;
                                break;
                            case 113:
                                next();
                                state = 28;
                                break;
                            case 87:
                                next();
                                state = 28;
                                break;
                            case 116:
                                next();
                                state = 28;
                                break;
                            case 69:
                                next();
                                state = 28;
                                break;
                            case 115:
                                next();
                                state = 28;
                                break;
                            case 68:
                                next();
                                state = 28;
                                break;
                            case 114:
                                next();
                                state = 28;
                                break;
                            case 67:
                                next();
                                state = 28;
                                break;
                            case 90:
                                next();
                                state = 28;
                                break;
                            case 99:
                                next();
                                state = 28;
                                break;
                            case 52:
                                next();
                                state = 28;
                                break;
                            case 100:
                                next();
                                state = 28;
                                break;
                            case 53:
                                next();
                                state = 28;
                                break;
                            case 101:
                                next();
                                state = 28;
                                break;
                            case 54:
                                next();
                                state = 28;
                                break;
                            case 111:
                                next();
                                state = 20;
                                break;
                            case 110:
                                next();
                                state = 28;
                                break;
                            case 86:
                                next();
                                state = 28;
                                break;
                            case 109:
                                next();
                                state = 28;
                                break;
                            case 85:
                                next();
                                state = 28;
                                break;
                            case 108:
                                next();
                                state = 28;
                                break;
                            case 84:
                                next();
                                state = 28;
                                break;
                            case 107:
                                next();
                                state = 28;
                                break;
                            case 83:
                                next();
                                state = 28;
                                break;
                            case 106:
                                next();
                                state = 28;
                                break;
                            case 82:
                                next();
                                state = 28;
                                break;
                            case 105:
                                next();
                                state = 28;
                                break;
                            case 104:
                                next();
                                state = 28;
                                break;
                            case 57:
                                next();
                                state = 28;
                                break;
                            case 103:
                                next();
                                state = 28;
                                break;
                            case 56:
                                next();
                                state = 28;
                                break;
                            case 102:
                                next();
                                state = 28;
                                break;
                            default:
                                m_semantic.id(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 31:
                        switch (c) {
                            case 97:
                                next();
                                state = 15;
                                break;
                            case 90:
                                next();
                                state = 15;
                                break;
                            case 89:
                                next();
                                state = 15;
                                break;
                            case 88:
                                next();
                                state = 15;
                                break;
                            case 87:
                                next();
                                state = 15;
                                break;
                            case 115:
                                next();
                                state = 15;
                                break;
                            case 68:
                                next();
                                state = 15;
                                break;
                            case 113:
                                next();
                                state = 15;
                                break;
                            case 66:
                                next();
                                state = 15;
                                break;
                            case 76:
                                next();
                                state = 15;
                                break;
                            case 77:
                                next();
                                state = 15;
                                break;
                            case 78:
                                next();
                                state = 15;
                                break;
                            case 79:
                                next();
                                state = 15;
                                break;
                            case 80:
                                next();
                                state = 15;
                                break;
                            case 120:
                                next();
                                state = 15;
                                break;
                            case 73:
                                next();
                                state = 15;
                                break;
                            case 72:
                                next();
                                state = 15;
                                break;
                            case 119:
                                next();
                                state = 15;
                                break;
                            case 70:
                                next();
                                state = 15;
                                break;
                            case 117:
                                next();
                                state = 15;
                                break;
                            case 99:
                                next();
                                state = 15;
                                break;
                            case 100:
                                next();
                                state = 15;
                                break;
                            case 103:
                                next();
                                state = 15;
                                break;
                            case 102:
                                next();
                                state = 15;
                                break;
                            case 104:
                                next();
                                state = 15;
                                break;
                            case 111:
                                next();
                                state = 15;
                                break;
                            case 110:
                                next();
                                state = 15;
                                break;
                            case 85:
                                next();
                                state = 15;
                                break;
                            case 108:
                                next();
                                state = 15;
                                break;
                            case 61:
                                next();
                                state = 35;
                                break;
                            case 32:
                                next();
                                state = 44;
                                break;
                            case 10:
                                next();
                                state = 44;
                                break;
                            case 107:
                                next();
                                state = 15;
                                break;
                            case 83:
                                next();
                                state = 15;
                                break;
                            case 9:
                                next();
                                state = 44;
                                break;
                            case 106:
                                next();
                                state = 15;
                                break;
                            case 59:
                                next();
                                state = 38;
                                break;
                            case 105:
                                next();
                                state = 15;
                                break;
                            case 58:
                                next();
                                state = 10;
                                break;
                            case 122:
                                next();
                                state = 15;
                                break;
                            case 75:
                                next();
                                state = 15;
                                break;
                            case 114:
                                next();
                                state = 37;
                                break;
                            case 67:
                                next();
                                state = 15;
                                break;
                            case 84:
                                next();
                                state = 15;
                                break;
                            case 116:
                                next();
                                state = 14;
                                break;
                            case 69:
                                next();
                                state = 15;
                                break;
                            case 82:
                                next();
                                state = 15;
                                break;
                            case 44:
                                next();
                                state = 2;
                                break;
                            case 86:
                                next();
                                state = 15;
                                break;
                            case 109:
                                next();
                                state = 36;
                                break;
                            case 121:
                                next();
                                state = 15;
                                break;
                            case 74:
                                next();
                                state = 15;
                                break;
                            case 98:
                                next();
                                state = 43;
                                break;
                            case 112:
                                next();
                                state = 23;
                                break;
                            case 65:
                                next();
                                state = 15;
                                break;
                            case 101:
                                next();
                                state = 29;
                                break;
                            case 95:
                                next();
                                state = 15;
                                break;
                            case 118:
                                next();
                                state = 27;
                                break;
                            case 71:
                                next();
                                state = 15;
                                break;
                            case 81:
                                next();
                                state = 15;
                                break;
                            default:
                                throw LexError();
                        }
                        break;
                    case 32:
                        switch (c) {
                            case 81:
                                next();
                                state = 28;
                                break;
                            case 49:
                                next();
                                state = 28;
                                break;
                            case 71:
                                next();
                                state = 28;
                                break;
                            case 118:
                                next();
                                state = 28;
                                break;
                            case 72:
                                next();
                                state = 28;
                                break;
                            case 119:
                                next();
                                state = 28;
                                break;
                            case 74:
                                next();
                                state = 28;
                                break;
                            case 121:
                                next();
                                state = 28;
                                break;
                            case 75:
                                next();
                                state = 28;
                                break;
                            case 122:
                                next();
                                state = 28;
                                break;
                            case 73:
                                next();
                                state = 28;
                                break;
                            case 120:
                                next();
                                state = 28;
                                break;
                            case 95:
                                next();
                                state = 28;
                                break;
                            case 48:
                                next();
                                state = 28;
                                break;
                            case 70:
                                next();
                                state = 28;
                                break;
                            case 117:
                                next();
                                state = 28;
                                break;
                            case 55:
                                next();
                                state = 28;
                                break;
                            case 98:
                                next();
                                state = 28;
                                break;
                            case 51:
                                next();
                                state = 28;
                                break;
                            case 50:
                                next();
                                state = 28;
                                break;
                            case 97:
                                next();
                                state = 28;
                                break;
                            case 80:
                                next();
                                state = 28;
                                break;
                            case 79:
                                next();
                                state = 28;
                                break;
                            case 78:
                                next();
                                state = 28;
                                break;
                            case 77:
                                next();
                                state = 28;
                                break;
                            case 76:
                                next();
                                state = 28;
                                break;
                            case 65:
                                next();
                                state = 28;
                                break;
                            case 112:
                                next();
                                state = 28;
                                break;
                            case 88:
                                next();
                                state = 28;
                                break;
                            case 89:
                                next();
                                state = 28;
                                break;
                            case 66:
                                next();
                                state = 28;
                                break;
                            case 113:
                                next();
                                state = 28;
                                break;
                            case 87:
                                next();
                                state = 28;
                                break;
                            case 116:
                                next();
                                state = 28;
                                break;
                            case 69:
                                next();
                                state = 28;
                                break;
                            case 115:
                                next();
                                state = 28;
                                break;
                            case 68:
                                next();
                                state = 28;
                                break;
                            case 114:
                                next();
                                state = 28;
                                break;
                            case 67:
                                next();
                                state = 28;
                                break;
                            case 90:
                                next();
                                state = 28;
                                break;
                            case 99:
                                next();
                                state = 28;
                                break;
                            case 52:
                                next();
                                state = 28;
                                break;
                            case 100:
                                next();
                                state = 28;
                                break;
                            case 53:
                                next();
                                state = 28;
                                break;
                            case 101:
                                next();
                                state = 6;
                                break;
                            case 54:
                                next();
                                state = 28;
                                break;
                            case 111:
                                next();
                                state = 28;
                                break;
                            case 110:
                                next();
                                state = 28;
                                break;
                            case 86:
                                next();
                                state = 28;
                                break;
                            case 109:
                                next();
                                state = 28;
                                break;
                            case 85:
                                next();
                                state = 28;
                                break;
                            case 108:
                                next();
                                state = 28;
                                break;
                            case 84:
                                next();
                                state = 28;
                                break;
                            case 107:
                                next();
                                state = 28;
                                break;
                            case 83:
                                next();
                                state = 28;
                                break;
                            case 106:
                                next();
                                state = 28;
                                break;
                            case 82:
                                next();
                                state = 28;
                                break;
                            case 105:
                                next();
                                state = 28;
                                break;
                            case 104:
                                next();
                                state = 28;
                                break;
                            case 57:
                                next();
                                state = 28;
                                break;
                            case 103:
                                next();
                                state = 28;
                                break;
                            case 56:
                                next();
                                state = 28;
                                break;
                            case 102:
                                next();
                                state = 28;
                                break;
                            default:
                                m_semantic.id(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 33:
                        switch (c) {
                            case 81:
                                next();
                                state = 28;
                                break;
                            case 49:
                                next();
                                state = 28;
                                break;
                            case 71:
                                next();
                                state = 28;
                                break;
                            case 118:
                                next();
                                state = 28;
                                break;
                            case 72:
                                next();
                                state = 28;
                                break;
                            case 119:
                                next();
                                state = 28;
                                break;
                            case 74:
                                next();
                                state = 28;
                                break;
                            case 121:
                                next();
                                state = 28;
                                break;
                            case 75:
                                next();
                                state = 28;
                                break;
                            case 122:
                                next();
                                state = 28;
                                break;
                            case 73:
                                next();
                                state = 28;
                                break;
                            case 120:
                                next();
                                state = 28;
                                break;
                            case 95:
                                next();
                                state = 28;
                                break;
                            case 48:
                                next();
                                state = 28;
                                break;
                            case 70:
                                next();
                                state = 28;
                                break;
                            case 117:
                                next();
                                state = 28;
                                break;
                            case 56:
                                next();
                                state = 28;
                                break;
                            case 98:
                                next();
                                state = 28;
                                break;
                            case 51:
                                next();
                                state = 28;
                                break;
                            case 50:
                                next();
                                state = 28;
                                break;
                            case 97:
                                next();
                                state = 28;
                                break;
                            case 80:
                                next();
                                state = 28;
                                break;
                            case 79:
                                next();
                                state = 28;
                                break;
                            case 78:
                                next();
                                state = 28;
                                break;
                            case 77:
                                next();
                                state = 28;
                                break;
                            case 76:
                                next();
                                state = 28;
                                break;
                            case 65:
                                next();
                                state = 28;
                                break;
                            case 112:
                                next();
                                state = 28;
                                break;
                            case 88:
                                next();
                                state = 28;
                                break;
                            case 89:
                                next();
                                state = 28;
                                break;
                            case 66:
                                next();
                                state = 28;
                                break;
                            case 113:
                                next();
                                state = 28;
                                break;
                            case 87:
                                next();
                                state = 28;
                                break;
                            case 116:
                                next();
                                state = 28;
                                break;
                            case 69:
                                next();
                                state = 28;
                                break;
                            case 115:
                                next();
                                state = 28;
                                break;
                            case 68:
                                next();
                                state = 28;
                                break;
                            case 114:
                                next();
                                state = 28;
                                break;
                            case 67:
                                next();
                                state = 28;
                                break;
                            case 90:
                                next();
                                state = 28;
                                break;
                            case 99:
                                next();
                                state = 28;
                                break;
                            case 52:
                                next();
                                state = 28;
                                break;
                            case 100:
                                next();
                                state = 28;
                                break;
                            case 53:
                                next();
                                state = 28;
                                break;
                            case 102:
                                next();
                                state = 28;
                                break;
                            case 55:
                                next();
                                state = 28;
                                break;
                            case 101:
                                next();
                                state = 34;
                                break;
                            case 54:
                                next();
                                state = 28;
                                break;
                            case 111:
                                next();
                                state = 28;
                                break;
                            case 110:
                                next();
                                state = 28;
                                break;
                            case 86:
                                next();
                                state = 28;
                                break;
                            case 109:
                                next();
                                state = 28;
                                break;
                            case 85:
                                next();
                                state = 28;
                                break;
                            case 108:
                                next();
                                state = 28;
                                break;
                            case 84:
                                next();
                                state = 28;
                                break;
                            case 107:
                                next();
                                state = 28;
                                break;
                            case 83:
                                next();
                                state = 28;
                                break;
                            case 106:
                                next();
                                state = 28;
                                break;
                            case 82:
                                next();
                                state = 28;
                                break;
                            case 105:
                                next();
                                state = 28;
                                break;
                            case 104:
                                next();
                                state = 28;
                                break;
                            case 57:
                                next();
                                state = 28;
                                break;
                            case 103:
                                next();
                                state = 28;
                                break;
                            default:
                                m_semantic.id(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 34:
                        switch (c) {
                            case 81:
                                next();
                                state = 28;
                                break;
                            case 49:
                                next();
                                state = 28;
                                break;
                            case 71:
                                next();
                                state = 28;
                                break;
                            case 118:
                                next();
                                state = 28;
                                break;
                            case 72:
                                next();
                                state = 28;
                                break;
                            case 119:
                                next();
                                state = 28;
                                break;
                            case 74:
                                next();
                                state = 28;
                                break;
                            case 121:
                                next();
                                state = 28;
                                break;
                            case 75:
                                next();
                                state = 28;
                                break;
                            case 122:
                                next();
                                state = 28;
                                break;
                            case 73:
                                next();
                                state = 28;
                                break;
                            case 120:
                                next();
                                state = 28;
                                break;
                            case 95:
                                next();
                                state = 28;
                                break;
                            case 48:
                                next();
                                state = 28;
                                break;
                            case 70:
                                next();
                                state = 28;
                                break;
                            case 117:
                                next();
                                state = 28;
                                break;
                            case 55:
                                next();
                                state = 28;
                                break;
                            case 98:
                                next();
                                state = 28;
                                break;
                            case 51:
                                next();
                                state = 28;
                                break;
                            case 50:
                                next();
                                state = 28;
                                break;
                            case 97:
                                next();
                                state = 28;
                                break;
                            case 80:
                                next();
                                state = 28;
                                break;
                            case 79:
                                next();
                                state = 28;
                                break;
                            case 78:
                                next();
                                state = 28;
                                break;
                            case 77:
                                next();
                                state = 28;
                                break;
                            case 76:
                                next();
                                state = 28;
                                break;
                            case 65:
                                next();
                                state = 28;
                                break;
                            case 112:
                                next();
                                state = 28;
                                break;
                            case 88:
                                next();
                                state = 28;
                                break;
                            case 89:
                                next();
                                state = 28;
                                break;
                            case 66:
                                next();
                                state = 28;
                                break;
                            case 113:
                                next();
                                state = 28;
                                break;
                            case 87:
                                next();
                                state = 28;
                                break;
                            case 116:
                                next();
                                state = 28;
                                break;
                            case 69:
                                next();
                                state = 28;
                                break;
                            case 115:
                                next();
                                state = 28;
                                break;
                            case 68:
                                next();
                                state = 28;
                                break;
                            case 114:
                                next();
                                state = 28;
                                break;
                            case 67:
                                next();
                                state = 28;
                                break;
                            case 90:
                                next();
                                state = 28;
                                break;
                            case 99:
                                next();
                                state = 28;
                                break;
                            case 52:
                                next();
                                state = 28;
                                break;
                            case 100:
                                next();
                                state = 5;
                                break;
                            case 53:
                                next();
                                state = 28;
                                break;
                            case 101:
                                next();
                                state = 28;
                                break;
                            case 54:
                                next();
                                state = 28;
                                break;
                            case 111:
                                next();
                                state = 28;
                                break;
                            case 110:
                                next();
                                state = 28;
                                break;
                            case 86:
                                next();
                                state = 28;
                                break;
                            case 109:
                                next();
                                state = 28;
                                break;
                            case 85:
                                next();
                                state = 28;
                                break;
                            case 108:
                                next();
                                state = 28;
                                break;
                            case 84:
                                next();
                                state = 28;
                                break;
                            case 107:
                                next();
                                state = 28;
                                break;
                            case 83:
                                next();
                                state = 28;
                                break;
                            case 106:
                                next();
                                state = 28;
                                break;
                            case 82:
                                next();
                                state = 28;
                                break;
                            case 105:
                                next();
                                state = 28;
                                break;
                            case 104:
                                next();
                                state = 28;
                                break;
                            case 57:
                                next();
                                state = 28;
                                break;
                            case 103:
                                next();
                                state = 28;
                                break;
                            case 56:
                                next();
                                state = 28;
                                break;
                            case 102:
                                next();
                                state = 28;
                                break;
                            default:
                                m_semantic.id(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 35:
                        m_semantic.eq(m_lexeme.str());
                        return true;
                    case 36:
                        switch (c) {
                            case 103:
                                next();
                                state = 28;
                                break;
                            case 57:
                                next();
                                state = 28;
                                break;
                            case 104:
                                next();
                                state = 28;
                                break;
                            case 105:
                                next();
                                state = 28;
                                break;
                            case 82:
                                next();
                                state = 28;
                                break;
                            case 106:
                                next();
                                state = 28;
                                break;
                            case 83:
                                next();
                                state = 28;
                                break;
                            case 107:
                                next();
                                state = 28;
                                break;
                            case 84:
                                next();
                                state = 28;
                                break;
                            case 108:
                                next();
                                state = 28;
                                break;
                            case 85:
                                next();
                                state = 28;
                                break;
                            case 109:
                                next();
                                state = 28;
                                break;
                            case 111:
                                next();
                                state = 9;
                                break;
                            case 110:
                                next();
                                state = 28;
                                break;
                            case 55:
                                next();
                                state = 28;
                                break;
                            case 102:
                                next();
                                state = 28;
                                break;
                            case 54:
                                next();
                                state = 28;
                                break;
                            case 81:
                                next();
                                state = 28;
                                break;
                            case 56:
                                next();
                                state = 28;
                                break;
                            case 86:
                                next();
                                state = 28;
                                break;
                            case 70:
                                next();
                                state = 28;
                                break;
                            case 117:
                                next();
                                state = 28;
                                break;
                            case 48:
                                next();
                                state = 28;
                                break;
                            case 95:
                                next();
                                state = 28;
                                break;
                            case 71:
                                next();
                                state = 28;
                                break;
                            case 118:
                                next();
                                state = 28;
                                break;
                            case 97:
                                next();
                                state = 28;
                                break;
                            case 50:
                                next();
                                state = 28;
                                break;
                            case 51:
                                next();
                                state = 28;
                                break;
                            case 98:
                                next();
                                state = 28;
                                break;
                            case 120:
                                next();
                                state = 28;
                                break;
                            case 73:
                                next();
                                state = 28;
                                break;
                            case 74:
                                next();
                                state = 28;
                                break;
                            case 121:
                                next();
                                state = 28;
                                break;
                            case 49:
                                next();
                                state = 28;
                                break;
                            case 72:
                                next();
                                state = 28;
                                break;
                            case 119:
                                next();
                                state = 28;
                                break;
                            case 75:
                                next();
                                state = 28;
                                break;
                            case 122:
                                next();
                                state = 28;
                                break;
                            case 80:
                                next();
                                state = 28;
                                break;
                            case 79:
                                next();
                                state = 28;
                                break;
                            case 78:
                                next();
                                state = 28;
                                break;
                            case 77:
                                next();
                                state = 28;
                                break;
                            case 76:
                                next();
                                state = 28;
                                break;
                            case 65:
                                next();
                                state = 28;
                                break;
                            case 112:
                                next();
                                state = 28;
                                break;
                            case 88:
                                next();
                                state = 28;
                                break;
                            case 89:
                                next();
                                state = 28;
                                break;
                            case 66:
                                next();
                                state = 28;
                                break;
                            case 113:
                                next();
                                state = 28;
                                break;
                            case 87:
                                next();
                                state = 28;
                                break;
                            case 116:
                                next();
                                state = 28;
                                break;
                            case 69:
                                next();
                                state = 28;
                                break;
                            case 115:
                                next();
                                state = 28;
                                break;
                            case 68:
                                next();
                                state = 28;
                                break;
                            case 114:
                                next();
                                state = 28;
                                break;
                            case 67:
                                next();
                                state = 28;
                                break;
                            case 90:
                                next();
                                state = 28;
                                break;
                            case 99:
                                next();
                                state = 28;
                                break;
                            case 52:
                                next();
                                state = 28;
                                break;
                            case 100:
                                next();
                                state = 28;
                                break;
                            case 53:
                                next();
                                state = 28;
                                break;
                            case 101:
                                next();
                                state = 28;
                                break;
                            default:
                                m_semantic.id(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 37:
                        switch (c) {
                            case 103:
                                next();
                                state = 28;
                                break;
                            case 57:
                                next();
                                state = 28;
                                break;
                            case 104:
                                next();
                                state = 28;
                                break;
                            case 105:
                                next();
                                state = 28;
                                break;
                            case 82:
                                next();
                                state = 28;
                                break;
                            case 106:
                                next();
                                state = 28;
                                break;
                            case 83:
                                next();
                                state = 28;
                                break;
                            case 107:
                                next();
                                state = 28;
                                break;
                            case 84:
                                next();
                                state = 28;
                                break;
                            case 108:
                                next();
                                state = 28;
                                break;
                            case 85:
                                next();
                                state = 28;
                                break;
                            case 109:
                                next();
                                state = 28;
                                break;
                            case 111:
                                next();
                                state = 28;
                                break;
                            case 110:
                                next();
                                state = 28;
                                break;
                            case 55:
                                next();
                                state = 28;
                                break;
                            case 102:
                                next();
                                state = 28;
                                break;
                            case 54:
                                next();
                                state = 28;
                                break;
                            case 81:
                                next();
                                state = 28;
                                break;
                            case 56:
                                next();
                                state = 28;
                                break;
                            case 86:
                                next();
                                state = 28;
                                break;
                            case 70:
                                next();
                                state = 28;
                                break;
                            case 117:
                                next();
                                state = 28;
                                break;
                            case 48:
                                next();
                                state = 28;
                                break;
                            case 95:
                                next();
                                state = 28;
                                break;
                            case 71:
                                next();
                                state = 28;
                                break;
                            case 118:
                                next();
                                state = 28;
                                break;
                            case 97:
                                next();
                                state = 28;
                                break;
                            case 50:
                                next();
                                state = 28;
                                break;
                            case 51:
                                next();
                                state = 28;
                                break;
                            case 98:
                                next();
                                state = 28;
                                break;
                            case 120:
                                next();
                                state = 28;
                                break;
                            case 73:
                                next();
                                state = 28;
                                break;
                            case 74:
                                next();
                                state = 28;
                                break;
                            case 121:
                                next();
                                state = 28;
                                break;
                            case 49:
                                next();
                                state = 28;
                                break;
                            case 72:
                                next();
                                state = 28;
                                break;
                            case 119:
                                next();
                                state = 28;
                                break;
                            case 75:
                                next();
                                state = 28;
                                break;
                            case 122:
                                next();
                                state = 28;
                                break;
                            case 80:
                                next();
                                state = 28;
                                break;
                            case 79:
                                next();
                                state = 28;
                                break;
                            case 78:
                                next();
                                state = 28;
                                break;
                            case 77:
                                next();
                                state = 28;
                                break;
                            case 76:
                                next();
                                state = 28;
                                break;
                            case 65:
                                next();
                                state = 28;
                                break;
                            case 112:
                                next();
                                state = 28;
                                break;
                            case 88:
                                next();
                                state = 28;
                                break;
                            case 89:
                                next();
                                state = 28;
                                break;
                            case 66:
                                next();
                                state = 28;
                                break;
                            case 113:
                                next();
                                state = 28;
                                break;
                            case 87:
                                next();
                                state = 28;
                                break;
                            case 116:
                                next();
                                state = 28;
                                break;
                            case 69:
                                next();
                                state = 28;
                                break;
                            case 115:
                                next();
                                state = 28;
                                break;
                            case 68:
                                next();
                                state = 28;
                                break;
                            case 114:
                                next();
                                state = 28;
                                break;
                            case 67:
                                next();
                                state = 28;
                                break;
                            case 90:
                                next();
                                state = 28;
                                break;
                            case 99:
                                next();
                                state = 28;
                                break;
                            case 52:
                                next();
                                state = 28;
                                break;
                            case 100:
                                next();
                                state = 28;
                                break;
                            case 53:
                                next();
                                state = 28;
                                break;
                            case 101:
                                next();
                                state = 39;
                                break;
                            default:
                                m_semantic.id(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 38:
                        m_semantic.semi(m_lexeme.str());
                        return true;
                    case 39:
                        switch (c) {
                            case 81:
                                next();
                                state = 28;
                                break;
                            case 49:
                                next();
                                state = 28;
                                break;
                            case 71:
                                next();
                                state = 28;
                                break;
                            case 118:
                                next();
                                state = 28;
                                break;
                            case 72:
                                next();
                                state = 28;
                                break;
                            case 119:
                                next();
                                state = 28;
                                break;
                            case 74:
                                next();
                                state = 28;
                                break;
                            case 121:
                                next();
                                state = 28;
                                break;
                            case 75:
                                next();
                                state = 28;
                                break;
                            case 122:
                                next();
                                state = 28;
                                break;
                            case 73:
                                next();
                                state = 28;
                                break;
                            case 120:
                                next();
                                state = 28;
                                break;
                            case 95:
                                next();
                                state = 28;
                                break;
                            case 48:
                                next();
                                state = 28;
                                break;
                            case 70:
                                next();
                                state = 28;
                                break;
                            case 117:
                                next();
                                state = 28;
                                break;
                            case 56:
                                next();
                                state = 28;
                                break;
                            case 98:
                                next();
                                state = 28;
                                break;
                            case 51:
                                next();
                                state = 28;
                                break;
                            case 50:
                                next();
                                state = 28;
                                break;
                            case 97:
                                next();
                                state = 28;
                                break;
                            case 80:
                                next();
                                state = 28;
                                break;
                            case 79:
                                next();
                                state = 28;
                                break;
                            case 78:
                                next();
                                state = 28;
                                break;
                            case 77:
                                next();
                                state = 28;
                                break;
                            case 76:
                                next();
                                state = 28;
                                break;
                            case 65:
                                next();
                                state = 28;
                                break;
                            case 112:
                                next();
                                state = 28;
                                break;
                            case 88:
                                next();
                                state = 28;
                                break;
                            case 89:
                                next();
                                state = 28;
                                break;
                            case 66:
                                next();
                                state = 28;
                                break;
                            case 113:
                                next();
                                state = 28;
                                break;
                            case 87:
                                next();
                                state = 28;
                                break;
                            case 116:
                                next();
                                state = 28;
                                break;
                            case 69:
                                next();
                                state = 28;
                                break;
                            case 115:
                                next();
                                state = 28;
                                break;
                            case 68:
                                next();
                                state = 28;
                                break;
                            case 114:
                                next();
                                state = 28;
                                break;
                            case 67:
                                next();
                                state = 28;
                                break;
                            case 90:
                                next();
                                state = 28;
                                break;
                            case 100:
                                next();
                                state = 28;
                                break;
                            case 53:
                                next();
                                state = 28;
                                break;
                            case 101:
                                next();
                                state = 28;
                                break;
                            case 54:
                                next();
                                state = 28;
                                break;
                            case 102:
                                next();
                                state = 28;
                                break;
                            case 55:
                                next();
                                state = 28;
                                break;
                            case 99:
                                next();
                                state = 30;
                                break;
                            case 52:
                                next();
                                state = 28;
                                break;
                            case 110:
                                next();
                                state = 28;
                                break;
                            case 111:
                                next();
                                state = 28;
                                break;
                            case 86:
                                next();
                                state = 28;
                                break;
                            case 109:
                                next();
                                state = 28;
                                break;
                            case 85:
                                next();
                                state = 28;
                                break;
                            case 108:
                                next();
                                state = 28;
                                break;
                            case 84:
                                next();
                                state = 28;
                                break;
                            case 107:
                                next();
                                state = 28;
                                break;
                            case 83:
                                next();
                                state = 28;
                                break;
                            case 106:
                                next();
                                state = 28;
                                break;
                            case 82:
                                next();
                                state = 28;
                                break;
                            case 105:
                                next();
                                state = 28;
                                break;
                            case 104:
                                next();
                                state = 28;
                                break;
                            case 57:
                                next();
                                state = 28;
                                break;
                            case 103:
                                next();
                                state = 28;
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
                                state = 28;
                                break;
                            case 49:
                                next();
                                state = 28;
                                break;
                            case 71:
                                next();
                                state = 28;
                                break;
                            case 118:
                                next();
                                state = 28;
                                break;
                            case 72:
                                next();
                                state = 28;
                                break;
                            case 119:
                                next();
                                state = 28;
                                break;
                            case 74:
                                next();
                                state = 28;
                                break;
                            case 121:
                                next();
                                state = 28;
                                break;
                            case 75:
                                next();
                                state = 28;
                                break;
                            case 122:
                                next();
                                state = 28;
                                break;
                            case 73:
                                next();
                                state = 28;
                                break;
                            case 120:
                                next();
                                state = 28;
                                break;
                            case 95:
                                next();
                                state = 28;
                                break;
                            case 48:
                                next();
                                state = 28;
                                break;
                            case 70:
                                next();
                                state = 28;
                                break;
                            case 117:
                                next();
                                state = 28;
                                break;
                            case 55:
                                next();
                                state = 28;
                                break;
                            case 98:
                                next();
                                state = 28;
                                break;
                            case 51:
                                next();
                                state = 28;
                                break;
                            case 50:
                                next();
                                state = 28;
                                break;
                            case 97:
                                next();
                                state = 28;
                                break;
                            case 80:
                                next();
                                state = 28;
                                break;
                            case 79:
                                next();
                                state = 28;
                                break;
                            case 78:
                                next();
                                state = 28;
                                break;
                            case 77:
                                next();
                                state = 28;
                                break;
                            case 76:
                                next();
                                state = 28;
                                break;
                            case 65:
                                next();
                                state = 28;
                                break;
                            case 112:
                                next();
                                state = 28;
                                break;
                            case 88:
                                next();
                                state = 28;
                                break;
                            case 89:
                                next();
                                state = 28;
                                break;
                            case 66:
                                next();
                                state = 28;
                                break;
                            case 113:
                                next();
                                state = 28;
                                break;
                            case 87:
                                next();
                                state = 28;
                                break;
                            case 116:
                                next();
                                state = 28;
                                break;
                            case 69:
                                next();
                                state = 28;
                                break;
                            case 115:
                                next();
                                state = 28;
                                break;
                            case 68:
                                next();
                                state = 28;
                                break;
                            case 114:
                                next();
                                state = 28;
                                break;
                            case 67:
                                next();
                                state = 28;
                                break;
                            case 90:
                                next();
                                state = 28;
                                break;
                            case 99:
                                next();
                                state = 28;
                                break;
                            case 52:
                                next();
                                state = 28;
                                break;
                            case 100:
                                next();
                                state = 42;
                                break;
                            case 53:
                                next();
                                state = 28;
                                break;
                            case 101:
                                next();
                                state = 28;
                                break;
                            case 54:
                                next();
                                state = 28;
                                break;
                            case 111:
                                next();
                                state = 28;
                                break;
                            case 110:
                                next();
                                state = 28;
                                break;
                            case 86:
                                next();
                                state = 28;
                                break;
                            case 109:
                                next();
                                state = 28;
                                break;
                            case 85:
                                next();
                                state = 28;
                                break;
                            case 108:
                                next();
                                state = 28;
                                break;
                            case 84:
                                next();
                                state = 28;
                                break;
                            case 107:
                                next();
                                state = 28;
                                break;
                            case 83:
                                next();
                                state = 28;
                                break;
                            case 106:
                                next();
                                state = 28;
                                break;
                            case 82:
                                next();
                                state = 28;
                                break;
                            case 105:
                                next();
                                state = 28;
                                break;
                            case 104:
                                next();
                                state = 28;
                                break;
                            case 57:
                                next();
                                state = 28;
                                break;
                            case 103:
                                next();
                                state = 28;
                                break;
                            case 56:
                                next();
                                state = 28;
                                break;
                            case 102:
                                next();
                                state = 28;
                                break;
                            default:
                                m_semantic.id(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 41:
                        switch (c) {
                            case 81:
                                next();
                                state = 28;
                                break;
                            case 49:
                                next();
                                state = 28;
                                break;
                            case 71:
                                next();
                                state = 28;
                                break;
                            case 118:
                                next();
                                state = 28;
                                break;
                            case 72:
                                next();
                                state = 28;
                                break;
                            case 119:
                                next();
                                state = 28;
                                break;
                            case 74:
                                next();
                                state = 28;
                                break;
                            case 121:
                                next();
                                state = 28;
                                break;
                            case 75:
                                next();
                                state = 28;
                                break;
                            case 122:
                                next();
                                state = 28;
                                break;
                            case 73:
                                next();
                                state = 28;
                                break;
                            case 120:
                                next();
                                state = 28;
                                break;
                            case 95:
                                next();
                                state = 28;
                                break;
                            case 48:
                                next();
                                state = 28;
                                break;
                            case 70:
                                next();
                                state = 28;
                                break;
                            case 117:
                                next();
                                state = 28;
                                break;
                            case 55:
                                next();
                                state = 28;
                                break;
                            case 98:
                                next();
                                state = 28;
                                break;
                            case 51:
                                next();
                                state = 28;
                                break;
                            case 50:
                                next();
                                state = 28;
                                break;
                            case 97:
                                next();
                                state = 28;
                                break;
                            case 80:
                                next();
                                state = 28;
                                break;
                            case 79:
                                next();
                                state = 28;
                                break;
                            case 78:
                                next();
                                state = 28;
                                break;
                            case 77:
                                next();
                                state = 28;
                                break;
                            case 76:
                                next();
                                state = 28;
                                break;
                            case 65:
                                next();
                                state = 28;
                                break;
                            case 112:
                                next();
                                state = 28;
                                break;
                            case 88:
                                next();
                                state = 28;
                                break;
                            case 89:
                                next();
                                state = 28;
                                break;
                            case 66:
                                next();
                                state = 28;
                                break;
                            case 113:
                                next();
                                state = 28;
                                break;
                            case 87:
                                next();
                                state = 28;
                                break;
                            case 116:
                                next();
                                state = 28;
                                break;
                            case 69:
                                next();
                                state = 28;
                                break;
                            case 115:
                                next();
                                state = 28;
                                break;
                            case 68:
                                next();
                                state = 28;
                                break;
                            case 114:
                                next();
                                state = 28;
                                break;
                            case 67:
                                next();
                                state = 28;
                                break;
                            case 90:
                                next();
                                state = 28;
                                break;
                            case 99:
                                next();
                                state = 33;
                                break;
                            case 52:
                                next();
                                state = 28;
                                break;
                            case 100:
                                next();
                                state = 28;
                                break;
                            case 53:
                                next();
                                state = 28;
                                break;
                            case 101:
                                next();
                                state = 28;
                                break;
                            case 54:
                                next();
                                state = 28;
                                break;
                            case 111:
                                next();
                                state = 28;
                                break;
                            case 110:
                                next();
                                state = 28;
                                break;
                            case 86:
                                next();
                                state = 28;
                                break;
                            case 109:
                                next();
                                state = 28;
                                break;
                            case 85:
                                next();
                                state = 28;
                                break;
                            case 108:
                                next();
                                state = 28;
                                break;
                            case 84:
                                next();
                                state = 28;
                                break;
                            case 107:
                                next();
                                state = 28;
                                break;
                            case 83:
                                next();
                                state = 28;
                                break;
                            case 106:
                                next();
                                state = 28;
                                break;
                            case 82:
                                next();
                                state = 28;
                                break;
                            case 105:
                                next();
                                state = 28;
                                break;
                            case 104:
                                next();
                                state = 28;
                                break;
                            case 57:
                                next();
                                state = 28;
                                break;
                            case 103:
                                next();
                                state = 28;
                                break;
                            case 56:
                                next();
                                state = 28;
                                break;
                            case 102:
                                next();
                                state = 28;
                                break;
                            default:
                                m_semantic.id(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 42:
                        switch (c) {
                            case 81:
                                next();
                                state = 28;
                                break;
                            case 49:
                                next();
                                state = 28;
                                break;
                            case 71:
                                next();
                                state = 28;
                                break;
                            case 118:
                                next();
                                state = 28;
                                break;
                            case 72:
                                next();
                                state = 28;
                                break;
                            case 119:
                                next();
                                state = 28;
                                break;
                            case 74:
                                next();
                                state = 28;
                                break;
                            case 121:
                                next();
                                state = 28;
                                break;
                            case 75:
                                next();
                                state = 28;
                                break;
                            case 122:
                                next();
                                state = 28;
                                break;
                            case 73:
                                next();
                                state = 28;
                                break;
                            case 120:
                                next();
                                state = 28;
                                break;
                            case 95:
                                next();
                                state = 28;
                                break;
                            case 48:
                                next();
                                state = 28;
                                break;
                            case 70:
                                next();
                                state = 28;
                                break;
                            case 117:
                                next();
                                state = 28;
                                break;
                            case 55:
                                next();
                                state = 28;
                                break;
                            case 98:
                                next();
                                state = 28;
                                break;
                            case 51:
                                next();
                                state = 28;
                                break;
                            case 50:
                                next();
                                state = 28;
                                break;
                            case 97:
                                next();
                                state = 28;
                                break;
                            case 80:
                                next();
                                state = 28;
                                break;
                            case 79:
                                next();
                                state = 28;
                                break;
                            case 78:
                                next();
                                state = 28;
                                break;
                            case 77:
                                next();
                                state = 28;
                                break;
                            case 76:
                                next();
                                state = 28;
                                break;
                            case 65:
                                next();
                                state = 28;
                                break;
                            case 112:
                                next();
                                state = 28;
                                break;
                            case 88:
                                next();
                                state = 28;
                                break;
                            case 89:
                                next();
                                state = 28;
                                break;
                            case 66:
                                next();
                                state = 28;
                                break;
                            case 113:
                                next();
                                state = 28;
                                break;
                            case 87:
                                next();
                                state = 28;
                                break;
                            case 116:
                                next();
                                state = 28;
                                break;
                            case 69:
                                next();
                                state = 28;
                                break;
                            case 115:
                                next();
                                state = 28;
                                break;
                            case 68:
                                next();
                                state = 28;
                                break;
                            case 114:
                                next();
                                state = 28;
                                break;
                            case 67:
                                next();
                                state = 28;
                                break;
                            case 90:
                                next();
                                state = 28;
                                break;
                            case 99:
                                next();
                                state = 28;
                                break;
                            case 52:
                                next();
                                state = 28;
                                break;
                            case 100:
                                next();
                                state = 28;
                                break;
                            case 53:
                                next();
                                state = 28;
                                break;
                            case 101:
                                next();
                                state = 28;
                                break;
                            case 54:
                                next();
                                state = 28;
                                break;
                            case 111:
                                next();
                                state = 28;
                                break;
                            case 110:
                                next();
                                state = 28;
                                break;
                            case 86:
                                next();
                                state = 28;
                                break;
                            case 109:
                                next();
                                state = 28;
                                break;
                            case 85:
                                next();
                                state = 28;
                                break;
                            case 108:
                                next();
                                state = 28;
                                break;
                            case 84:
                                next();
                                state = 28;
                                break;
                            case 107:
                                next();
                                state = 28;
                                break;
                            case 83:
                                next();
                                state = 28;
                                break;
                            case 106:
                                next();
                                state = 28;
                                break;
                            case 82:
                                next();
                                state = 28;
                                break;
                            case 105:
                                next();
                                state = 28;
                                break;
                            case 104:
                                next();
                                state = 28;
                                break;
                            case 57:
                                next();
                                state = 28;
                                break;
                            case 103:
                                next();
                                state = 28;
                                break;
                            case 56:
                                next();
                                state = 28;
                                break;
                            case 102:
                                next();
                                state = 28;
                                break;
                            default:
                                m_semantic.record(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 43:
                        switch (c) {
                            case 103:
                                next();
                                state = 28;
                                break;
                            case 57:
                                next();
                                state = 28;
                                break;
                            case 104:
                                next();
                                state = 28;
                                break;
                            case 105:
                                next();
                                state = 28;
                                break;
                            case 82:
                                next();
                                state = 28;
                                break;
                            case 106:
                                next();
                                state = 28;
                                break;
                            case 83:
                                next();
                                state = 28;
                                break;
                            case 107:
                                next();
                                state = 28;
                                break;
                            case 84:
                                next();
                                state = 28;
                                break;
                            case 108:
                                next();
                                state = 28;
                                break;
                            case 85:
                                next();
                                state = 28;
                                break;
                            case 109:
                                next();
                                state = 28;
                                break;
                            case 111:
                                next();
                                state = 28;
                                break;
                            case 110:
                                next();
                                state = 28;
                                break;
                            case 55:
                                next();
                                state = 28;
                                break;
                            case 102:
                                next();
                                state = 28;
                                break;
                            case 54:
                                next();
                                state = 28;
                                break;
                            case 81:
                                next();
                                state = 28;
                                break;
                            case 56:
                                next();
                                state = 28;
                                break;
                            case 86:
                                next();
                                state = 28;
                                break;
                            case 70:
                                next();
                                state = 28;
                                break;
                            case 117:
                                next();
                                state = 28;
                                break;
                            case 48:
                                next();
                                state = 28;
                                break;
                            case 95:
                                next();
                                state = 28;
                                break;
                            case 71:
                                next();
                                state = 28;
                                break;
                            case 118:
                                next();
                                state = 28;
                                break;
                            case 97:
                                next();
                                state = 28;
                                break;
                            case 50:
                                next();
                                state = 28;
                                break;
                            case 51:
                                next();
                                state = 28;
                                break;
                            case 98:
                                next();
                                state = 28;
                                break;
                            case 120:
                                next();
                                state = 28;
                                break;
                            case 73:
                                next();
                                state = 28;
                                break;
                            case 74:
                                next();
                                state = 28;
                                break;
                            case 121:
                                next();
                                state = 28;
                                break;
                            case 49:
                                next();
                                state = 28;
                                break;
                            case 72:
                                next();
                                state = 28;
                                break;
                            case 119:
                                next();
                                state = 28;
                                break;
                            case 75:
                                next();
                                state = 28;
                                break;
                            case 122:
                                next();
                                state = 28;
                                break;
                            case 80:
                                next();
                                state = 28;
                                break;
                            case 79:
                                next();
                                state = 28;
                                break;
                            case 78:
                                next();
                                state = 28;
                                break;
                            case 77:
                                next();
                                state = 28;
                                break;
                            case 76:
                                next();
                                state = 28;
                                break;
                            case 65:
                                next();
                                state = 28;
                                break;
                            case 112:
                                next();
                                state = 28;
                                break;
                            case 88:
                                next();
                                state = 28;
                                break;
                            case 89:
                                next();
                                state = 28;
                                break;
                            case 66:
                                next();
                                state = 28;
                                break;
                            case 113:
                                next();
                                state = 28;
                                break;
                            case 87:
                                next();
                                state = 28;
                                break;
                            case 116:
                                next();
                                state = 28;
                                break;
                            case 69:
                                next();
                                state = 28;
                                break;
                            case 115:
                                next();
                                state = 28;
                                break;
                            case 68:
                                next();
                                state = 28;
                                break;
                            case 114:
                                next();
                                state = 28;
                                break;
                            case 67:
                                next();
                                state = 28;
                                break;
                            case 90:
                                next();
                                state = 28;
                                break;
                            case 99:
                                next();
                                state = 28;
                                break;
                            case 52:
                                next();
                                state = 28;
                                break;
                            case 100:
                                next();
                                state = 28;
                                break;
                            case 53:
                                next();
                                state = 28;
                                break;
                            case 101:
                                next();
                                state = 16;
                                break;
                            default:
                                m_semantic.id(m_lexeme.str());
                                return true;
                        }
                        break;
                    case 44:
                        switch (c) {
                            case 10:
                                next();
                                state = 17;
                                break;
                            case 32:
                                next();
                                state = 17;
                                break;
                            case 9:
                                next();
                                state = 17;
                                break;
                            default:
                                return false;
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
