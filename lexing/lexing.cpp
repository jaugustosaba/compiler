#include "lexing.h"
#include "spec-parser.h"
#include "ndfa-builder.h"
#include "converter.h"
#include "code-generator.h"

namespace lexing {

bool Lexing::generate(std::istream &input, std::ostream &output, std::ostream &error) {
	try {
		auto spec = parseSpec(input);
		auto ndfa = buildNdfa(spec);
		auto dfa = convert(ndfa);
		output << lexing::CodeGenerator(dfa, spec);
		return true;
	} catch (BadSpec &e) {
		error
			<< "syntax error: " << e.what() << " at ("
			<< e.line() << ", " << e.column() << ")";
	}
	return false;
}


} // namespace lexing
