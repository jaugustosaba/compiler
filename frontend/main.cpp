#include <iostream>
#include <sstream>

#include "parser.h"

const char* INPUT = R"(
module m;
  type
    zica = 
      record
      end ;

  var
    a : integer;
    b : real;

  procedure x;
  begin
  end x;

  procedure y;
  begin
  end y;
end m;
)";

int main(int argc, char **argv) {
	std::istringstream input(INPUT);
	auto expr = frontend::parse(input);
	return EXIT_SUCCESS;
}
