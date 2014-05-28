#include "ndfa-builder.h"

namespace lexing {

Ndfa buildNdfa(const Spec &spec) {
	Ndfa ndfa;
	ndfa.root = ndfa.createState();
	for (const auto &rule : spec.rules) {
		auto fs = ndfa.createState();
		fs->isFinal = true;
		fs->action = rule.action;
		rule.regex->buildNdfa(ndfa, ndfa.root, fs);
	}
	return ndfa;
}

} // namespace lexing



