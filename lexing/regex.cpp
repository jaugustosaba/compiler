#include "regex.h"

namespace lexing {

void CatRegex::buildNdfa(Ndfa &ndfa, NdfaState *from, NdfaState *to) const {
	auto s = ndfa.createState();
	this->left->buildNdfa(ndfa, from, s);
    this->right->buildNdfa(ndfa, s, to);
}

void OrRegex::buildNdfa(Ndfa &ndfa, NdfaState *from, NdfaState *to) const {
    this->left->buildNdfa(ndfa, from, to);
    this->right->buildNdfa(ndfa, from, to);
}

void CharRegex::buildNdfa(Ndfa &ndfa, NdfaState *from, NdfaState *to) const {
	from->transitions[value].insert(to);
}

void StarRegex::buildNdfa(Ndfa &ndfa, NdfaState *from, NdfaState *to) const {
    auto s = ndfa.createState();
    from->transitions[EmptySymbol].insert(s);
    this->regex->buildNdfa(ndfa, s, s);
    s->transitions[EmptySymbol].insert(to);
}

void OptRegex::buildNdfa(Ndfa &ndfa, NdfaState *from, NdfaState *to) const {
	from->transitions[EmptySymbol].insert(to);
    this->regex->buildNdfa(ndfa, from, to);
}

} // namespace lexing

