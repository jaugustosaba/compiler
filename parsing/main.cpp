#include <iostream>
#include <sstream>

#include "parsing.h"

const static char *INPUT = R"(
%%

%nonassoc LT;
%left PLUS;
%left TIMES;
%right POW;

%token ID;

%root expr;

%%

expr : expr PLUS expr  ~> {add}
     | expr TIMES expr ~> {times}
     | expr POW expr   ~> {power}
     | expr LT expr    ~> {compare}
     | ID              ~> {id}
;

)";

int main(int argc, char **argv) {
	std::istringstream input(INPUT);
	auto &output = std::cout;
	auto &error = std::cerr;

	input.exceptions(std::istream::badbit);
	output.exceptions(std::ostream::badbit);
	parsing::Parsing p{};
	try {
		if (p.generate(input, output, error)) {
			return EXIT_SUCCESS;
		}
	} catch (std::ios_base::failure &e) {
		error << "I/O error: '" << e.what() << "'" << std::endl;
	}
	return EXIT_FAILURE;
}
