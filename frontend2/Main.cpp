#include <iostream>
#include <sstream>

#include "Parser.h"

const char *INPUT = R"(
module x;
  var
    a, b, c : integer;
    d, e, f : real;

  procedure p;
    var x : integer;
    var y : real;

    procedure q;
    begin
    end q;
  begin
  end p;

  procedure add(a, b : integer) : integer;
  begin
    return x(a, b);
  end add;

  procedure x(a, b : integer) : integer;
    var res : real;
  begin
    res := a + b;
    return res;
  end x;

end x.
)";

int main() {
	std::istringstream input(INPUT);
	frontend::Parser parser(input);
	parser.parse();

	return EXIT_SUCCESS;
}
