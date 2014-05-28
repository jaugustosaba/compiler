#include <iostream>

#include "parsing.h"

int main(int argc, char **argv) {
	auto &input = std::cin;
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
