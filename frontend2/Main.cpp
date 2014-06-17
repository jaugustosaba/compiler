#include <iostream>
#include <sstream>

#include "Parser.h"
#include "TypeDecl.h"
#include "ScalarType.h"

const char *INPUT = R"(
MODULE x;
  VAR
    a, b, c : INTEGER;
    d, e, f : REAL;

  PROCEDURE p;
    VAR x : INTEGER;
        y : REAL;
        z : BOOLEAN;
    PROCEDURE q;
    BEGIN
    END q;
  BEGIN
    q;
  END p;

  PROCEDURE add(a, b : INTEGER) : INTEGER;
  BEGIN
    RETURN x(a, b);
  END add;

  PROCEDURE x(a, b : INTEGER) : INTEGER;
    VAR res : REAL;
  BEGIN
    res := a + b;
    RETURN res;
  END x;

END x.
)";

namespace frontend {

void run(std::istream &input) {
	Parser parser(input);
	auto module = parser.parse();
	ScalarType integer;
	TypeDecl intdecl;
	intdecl.type = &integer;
	ScalarType boolean;
	TypeDecl booldecl;
	booldecl.type = &boolean;
	SymbolTable st;
	st.declare("integer", &intdecl);
	st.declare("boolean", &booldecl);
}

} // namespace frontend

int main() {
	std::istringstream input(INPUT);
	frontend::run(input);
	return EXIT_SUCCESS;
}
