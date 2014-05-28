#ifndef CODE_GENERATOR_H_
#define CODE_GENERATOR_H_

#include "parser-table.h"

namespace parsing {

class CodeGenerator {
	const ParserTable& m_table;
	const Spec&        m_spec;
public:
	inline
	CodeGenerator(const ParserTable &table, const Spec& spec)
		: m_table(table),
		  m_spec(spec)
	{
	}
	void generate(std::ostream &out) const;
};

inline std::ostream& operator<<(std::ostream &out, const CodeGenerator &codeGen) {
    codeGen.generate(out);
    return out;
}

} // namespace parsing

#endif /* CODE_GENERATOR_H_ */
