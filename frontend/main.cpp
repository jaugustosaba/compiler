#include <iostream>
#include <sstream>

#include "parser.h"

const char* INPUT = R"(
module m;
  type
    X = record
          x, y : integer;
        end;
    Y = pointer to X;
  var
    x : X;
    p : Y;
    res : integer;

  procedure add(x, y : integer; var res : integer);
  begin
    res := x + y;
  end add;

  function f(var x : X) : boolean;
    var result : boolean;
  begin
    result := (x.x = x.y);
  end f;

  function dup(var x : integer) : integer;
  begin
    
  end dup;

  function zica : Y;
  begin
  end zica;

begin
  x.x := 10;
  x.y := 20;
  add(x.x, x.y, res);
  f(x);
  dup(res);
  p := zica;
  p^.x := 11;
  p^.y := 21;
  f(p^);
end m;
)";

namespace frontend {

void run(std::istream &input) {
	BuiltinTypeDecl integer(&Type::INTEGER);
	BuiltinTypeDecl boolean(&Type::BOOLEAN);
	SymbolTable builtins;
	builtins.declare("integer", &integer);
	builtins.declare("boolean", &boolean);
	auto module = parse(input);
	module->loadSymbols(&builtins);
	module->loadTypes();
	module->typeCheck();
}

} // namespace frontend

int main(int argc, char **argv) {
	std::istringstream input(INPUT);
	frontend::run(input);
	return EXIT_SUCCESS;
}
