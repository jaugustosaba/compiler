#ifndef SPEC_PARSER_H_
#define SPEC_PARSER_H_

#include <istream>
#include <string>

#include "spec.h"

namespace lexing {

struct BadSpec : public std::exception {
	typedef size_t PosType;

    BadSpec(const std::string &message, PosType line, PosType column)
        : m_message(message), m_line(line), m_column(column)
    {
    }
    const char* what() const noexcept override {
        return m_message.data();
    }
    PosType line() const {
        return m_line;
    }
    PosType column() const {
        return m_column;
    }
    ~BadSpec() noexcept override {
    }
private:
    std::string  m_message;
    PosType      m_line;
    PosType      m_column;
};

Spec parseSpec(std::istream &input);

} // namespace lexing

#endif /* SPEC_PARSER_H_ */
