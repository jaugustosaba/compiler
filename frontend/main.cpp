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
    pzica = pointer to zica;
    azica = array 10, 20 of pzica;

  var
    a, k, l : integer;
    b : real;

  procedure x();
  begin
    if (a+b+c > b) or not k then
    elseif b <> c then
      if l = m then
      end;
    elseif k = y then
      while d do
      end;
    else
    end;
  end x;

  function y(a, b : integer; var c:integer) : integer;
    var k : integer;
  begin
    k := a + b + c;
    y := 20;
    y;
    l := m() + n.k.l();
    while k().x do
      k[i, j] = a[l][m]^.value;
    end;
  end y;

begin
end m;
)";

int main(int argc, char **argv) {
	std::istringstream input(INPUT);
	auto expr = frontend::parse(input);
	return EXIT_SUCCESS;
}
