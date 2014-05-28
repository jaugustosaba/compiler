#ifndef SPEC_PARSER_H_
#define SPEC_PARSER_H_

#include <istream>
#include <string>
#include <exception>

#include "spec.h"

namespace parsing {

struct SpecError : public std::exception {
	typedef size_t PosType;

	inline
	SpecError(const std::string &message, PosType line, PosType column)
		: m_message(message), m_line(line), m_column(column)
	{
	}
	const char* what() const noexcept override {
		return m_message.data();
	}
	inline PosType line() const {
		return m_line;
	}
	inline PosType column() const {
		return m_column;
	}
	~SpecError() noexcept override {
	}
private:
	std::string  m_message;
	PosType      m_line;
	PosType      m_column;
};

Spec parse(std::istream &input);

} // namespace parsing

#endif /* SPEC_PARSER_H_ */
