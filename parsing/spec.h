#ifndef SPEC_H_
#define SPEC_H_

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <unordered_set>

namespace parsing {

enum class Associativity {
	Left,
	Right,
	NoAssoc,
};

struct Production;
struct Token;

typedef std::unordered_set<Token*> TokenSet;

struct Symbol {
	TokenSet firstSet;
	virtual ~Symbol() {}
};

typedef std::unique_ptr<Production> ProductionPtr;

struct Rule : public Symbol {
	size_t                      id;
	std::string                 name;
	std::vector<ProductionPtr>  productions;
};

typedef std::unique_ptr<Rule> RulePtr;

struct Token : public Symbol {
	size_t         id;
	std::string    name;
	int            priority;
	Associativity  assoc;
};

typedef std::unique_ptr<Token> TokenPtr;

struct Production {
	Rule*                 rule;
	std::vector<Symbol*>  symbols;
	std::string           action;
	Token*                lastToken;
	TokenSet              firstSet;
};

struct Options {
	std::string guard;
	std::string className;
	std::string nameSpace;

	inline Options()
		: guard(),
		  className("Parser"),
		  nameSpace()
	{
	}
};

struct Spec {
	Rule*                  root;
	Token*                 eof;
	Token*                 error;
	std::vector<RulePtr>   rules;
	std::vector<TokenPtr>  tokens;
	Options                options;

	void computeFirstSet();
	void computeLastTokens();
};

} // namespace parsing

#endif /* SPEC_H_ */
