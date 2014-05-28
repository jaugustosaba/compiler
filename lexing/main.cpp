#include <iostream>

#include "lexing.h"

int main(int argc, char **argv) {
	auto &input = std::cin;
	auto &output = std::cout;
	auto &error = std::cerr;

	input.exceptions(std::istream::badbit);
	output.exceptions(std::ostream::badbit);
	lexing::Lexing lexing;
	try {
		lexing.generate(input, output, error);
	} catch (std::ios_base::failure &e) {
		error << "I/O error: " << e.what() << std::endl;
	}
	return EXIT_SUCCESS;
}
