#ifndef PARSER_H_
#define PARSER_H_

#include <iostream>

#include "ast.h"

namespace frontend {

ExprPtr parse(std::istream &input);

}

#endif /* PARSER_H_ */