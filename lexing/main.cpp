#include <iostream>
#include <sstream>

#include "lexing.h"

const static char *INPUT = R"(
%%

%%
"a" ~> action0 ;
"ab*" ~> action1 ;
)";


int main(int argc, char **argv) {
	std::istringstream input(INPUT);

	auto &output = std::cout;
	auto &error = std::cerr;

	output.exceptions(std::ostream::failbit);
	error.exceptions(std::ostream::failbit);
	lexing::Lexing lexing;
	try {
		lexing.generate(input, output, error);
	} catch (std::ios_base::failure &e) {
		error << "I/O error: " << e.what() << std::endl;
	}
	return EXIT_SUCCESS;
}
