#include <sstream>

#include "code-generator.h"
#include "../util/idented-writer.h"

namespace lexing {

namespace {

using util::IdentedWriter;
using util::endl;

struct GeneratorHelper {
    const Dfa&     dfa;
    const Spec&    spec;
    IdentedWriter  out;

    void generate() {
    	auto &className = spec.options.className;
    	auto &nameSpace = spec.options.nameSpace;
    	auto guard = spec.options.guard;
    	if (guard.empty()) {
    		std::ostringstream out;
    		for (size_t i=0; i<className.size(); ++i) {
    			out << char(std::toupper(className[i]));
    		}
    		out << "_H_";
    		guard = out.str();
    	}
    	out << "#ifndef " << guard << endl;
    	out << "#define " << guard << endl << endl;
    	out << "#include <sstream>" << endl;
    	out << "#include <stdexcept>" << endl << endl;
    	if (!nameSpace.empty()) {
    		out << "namespace " << nameSpace << " {" << endl << endl;
    	}
        out << "struct " << className << " {" << endl;
        out.increaseIdent();
        generateLexError();
        generateLexFunc();
        out.decreaseIdent();
        out << "private:" << endl;
        out.increaseIdent();
        generateHelper();
        out.decreaseIdent();
        out << "};" << endl << endl;
        if (!nameSpace.empty()) {
        	out << "} // namespace " << nameSpace << endl << endl;
        }
        out << "#endif" << endl;
    }
private:
    void generateLexError() {
        out << "struct LexError : public std::exception {" << endl;
        out.increaseIdent();
        out << "LexError() {" << endl;
        out << "}" << endl;
        out << "const char* what() const noexcept override {" << endl;
        out.increaseIdent();
        out << "return \"lex error\";" << endl;
        out.decreaseIdent();
        out << "}" << endl;
        out << "~LexError() noexcept override {" << endl;
        out << "}" << endl;
        out.decreaseIdent();
        out << "};" << endl << endl;
    }
    void generateLexFunc() {
        out << "template <class Input, class Semantic>" << endl;
        out << "static bool lex(Input& input, Semantic& semantic) {" << endl;
        out.increaseIdent();
        out << "Helper<Input, Semantic> helper(input, semantic);" << endl;
        out << "return helper.lex();" << endl;
        out.decreaseIdent();
        out << "}" << endl;
    }
    void generateHelper() {
        out << "template <class Input, class Semantic>" << endl;
        out << "class Helper {" << endl;
        out.increaseIdent();
        out << "Input&              m_input;" << endl;
        out << "Semantic&           m_semantic;" << endl;
        out << "std::ostringstream  m_lexeme;" << endl;
        out.decreaseIdent();
        out << "public:" << endl;
        out.increaseIdent();
        out << "Helper(Input& input, Semantic& semantic)" << endl;
        out.increaseIdent();
        out << ": m_input(input), m_semantic(semantic), m_lexeme()" << endl;
        out.decreaseIdent();
        out << "{" << endl;
        out << "}" << endl;
        generateHelperLex();
        generatePeekFun();
        generateNextFunc();
        out.decreaseIdent();
        out << "};" << endl;
    }
    void generateActionHelper(const DfaState *state) {
        if (state->isFinal) {
            if ((state->action != nullptr) && (!state->action->name.empty())) {
                out << "m_semantic." << state->action->name << "(m_lexeme.str());" << endl;
                out << "return true;" << endl;
                return;
            } else {
            	out << "return false;" << endl;
            	return;
            }
        }
        out << "throw LexError();" << endl;
    }
    void generateHelperLex() {
        out << "bool lex() {" << endl;
        out.increaseIdent();
        out << "m_lexeme.str(\"\");" << endl;
        out << "int c = peek();" << endl;
        out << "if (c == -1) {" << endl;
        out.increaseIdent();
        out << "return false;" << endl;
        out.decreaseIdent();
        out << "}" << endl;
        out << "size_t state = " << dfa.root->id << ";" << endl;
        out << "while (true) {" << endl;
        out.increaseIdent();
        out << "c = peek();" << endl;
        out << "switch (state) {" << endl;
        out.increaseIdent();
        for (const auto &state : dfa.states) {
            out << "case " << state->id << ":" << endl;
            out.increaseIdent();
            if (state->transitions.empty()) {
                generateActionHelper(state.get());
            } else {
                out << "switch (c) {" << endl;
                out.increaseIdent();
                for (const auto &pair : state->transitions) {
                    out << "case " << pair.first << ":" << endl;
                    out.increaseIdent();
                    out << "next();" << endl;
                    out << "state = " << pair.second->id << ";" << endl;
                    out << "break;" << endl;
                    out.decreaseIdent();
                }
                out << "default:" << endl;
                out.increaseIdent();
                generateActionHelper(state.get());
                out.decreaseIdent();
                out.decreaseIdent();
                out << "}" << endl;
                out << "break;" << endl;
            }
            out.decreaseIdent();
        }
        out.decreaseIdent();
        out << "}" << endl;
        out.decreaseIdent();
        out << "}" << endl;
        out << "throw std::logic_error(\"unexpect code\");" << endl;
        out.decreaseIdent();
        out << "}" << endl;
    }
    void generatePeekFun() {
        out << "inline int peek() {" << endl;
        out.increaseIdent();
        out << "return m_input.peek();" << endl;
        out.decreaseIdent();
        out << "}" << endl;
    }
    void generateNextFunc() {
        out << "inline void next() {" << endl;
        out.increaseIdent();
        out << "int c = m_input.peek();" << endl;
        out << "if (c != -1) {" << endl;
        out.increaseIdent();
        out << "m_lexeme << char(c);" << endl;
        out.decreaseIdent();
        out << "}" << endl;
        out << "m_input.next();" << endl;
        out.decreaseIdent();
        out << "}" << endl;
    }
};

} // anonymous namespace

void CodeGenerator::generate(std::ostream &out) const {
    GeneratorHelper helper{m_dfa, m_spec, IdentedWriter(out)};
    helper.generate();
}

} // namespace lexing
