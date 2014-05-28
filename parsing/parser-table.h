#ifndef PARSER_TABLE_H_
#define PARSER_TABLE_H_

#include "lalr.h"

namespace parsing {

enum class ActionType {
	Shift,
	Reduce,
	Error,
	Accept,
};

struct Action {
	ActionType  actionType;
	size_t      value;
};

struct Reduction {
	size_t       rule;
	size_t       symbolCount;
	std::string  action;
};

// shift-reduce veredict
enum class SRVeredict {
	Shift,
	Reduce,
	Neither,
};

// shift-reduce conflict
struct SRConflict {
	const State*      state;
	const Kernel*     kernel;
	const Token*      token;
	SRVeredict        veredict;
};

typedef std::unique_ptr<SRConflict> SRConflictPtr;

// reduce-reduce veredict
enum class RRVeredict {
	First,
	Second,
};

// reduce-reduce conflict
struct RRConflict {
	const State*      state;
	const Kernel*     first;
	const Kernel*     second;
	const Token*      token;
	RRVeredict        veredict;
};

typedef std::unique_ptr<RRConflict> RRConflictPtr;

struct ParserTable {
    typedef std::vector<Action> ActionVect;
    typedef std::vector<ActionVect> ActionTable;
    typedef std::vector<size_t> GotoVect;
    typedef std::vector<GotoVect> GotoTable;
    typedef std::vector<Reduction> ReductionVect;
    typedef std::vector<std::string> StringVect;
    typedef std::vector<SRConflictPtr> SRConflictVect;
    typedef std::vector<RRConflictPtr> RRConflictVect;

	size_t          root;
	ActionTable     actions;
	GotoTable       gotos;
	ReductionVect   reductions;
	StringVect      tokens;
	StringVect      rules;
	SRConflictVect  srConflicts;
	RRConflictVect  rrConflicts;
};

ParserTable makeTable(const Spec &spec, const LALR &lalr);

} // namespace parsing

#endif /* PARSER_TABLE_H_ */
