#ifndef CODE_GENERATOR_H_
#define CODE_GENERATOR_H_

#include "spec.h"
#include "dfa.h"

namespace lexing {

class CodeGenerator {
    const Dfa&   m_dfa;
    const Spec&  m_spec;
public:
    inline
    CodeGenerator(const Dfa &dfa, const Spec &spec)
        : m_dfa(dfa), m_spec(spec)
    {
    }
    void generate(std::ostream &out) const;
};

inline std::ostream& operator<<(std::ostream& out, const CodeGenerator &codegen) {
    codegen.generate(out);
    return out;
}

} // namespace lexing

#endif /* CODE_GENERATOR_H_ */
