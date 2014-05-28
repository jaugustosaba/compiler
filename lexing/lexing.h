#ifndef LEXING_H_
#define LEXING_H_

#include <istream>
#include <ostream>

namespace lexing {

struct Lexing {
	bool generate(std::istream &input, std::ostream &output, std::ostream &error);
};

} // namespace lexing

#endif /* LEXING_H_ */
