#ifndef SPEC_H_
#define SPEC_H_

#include "action.h"
#include "regex.h"

namespace lexing {

struct Rule {
	RegexPtr   regex;
	ActionPtr  action;
};

struct Options {
	std::string  guard;
	std::string  className;
	std::string  nameSpace;

	inline Options()
		: guard(),
		  className("Lexer"),
		  nameSpace()
	{
	}
};

struct Spec {
	std::vector<Rule>  rules;
	Options            options;
};

} // namespace lexing

#endif /* SPEC_H_ */
