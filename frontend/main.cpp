#include <iostream>
#include <sstream>

#include "parser.h"

const char* INPUT = R"(
module m;
  type
    zica = 
      record
        a, b : boolean;
        c : integer;
      end ;

  var
    a, k, l : integer;
    b : real;

  procedure x();
  begin
    if then
    elseif then
      if then
      end;
    elseif then
      while do
      end;
    else
    end;
  end x;

  function y(a, b : integer; var c:integer) : integer;
  begin
  end y;

begin
  if then
    while do
    end;
  end;
end m;
)";

int main(int argc, char **argv) {
	std::istringstream input(INPUT);
	auto expr = frontend::parse(input);
	return EXIT_SUCCESS;
}
