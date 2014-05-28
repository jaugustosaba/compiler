#ifndef REGEX_PARSER_H_
#define REGEX_PARSER_H_

#include <istream>
#include <string>

#include "regex.h"

namespace lexing {

class BadRegex : public std::exception {
public:
    typedef size_t PosType;

    BadRegex(const std::string &message, PosType position)
        : std::exception(), m_message(message), m_position(position)
    {
    }
    const char* what() const noexcept override {
        return m_message.data();
    }
    PosType position() const {
        return m_position;
    }
    ~BadRegex() noexcept override {
    }
private:
    std::string  m_message;
    PosType    m_position;
};

RegexPtr parseRegex(std::istream &input);
RegexPtr parseRegex(const std::string &regex);

} // namespace lexing

#endif /* REGEX_PARSER_H_ */
