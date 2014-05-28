#ifndef PARSING_H_
#define PARSING_H_

#include <istream>
#include <ostream>

namespace parsing {

struct Parsing {
	bool showSRConflicts;
	bool showSRConflictItems;

	bool generate(std::istream &input, std::ostream &output, std::ostream &error) const;
};

} // namespace parsing

#endif /* PARSING_H_ */
