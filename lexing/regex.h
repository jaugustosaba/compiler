#ifndef REGEX_H_
#define REGEX_H_

#include "ndfa.h"

namespace lexing {

struct Regex {
	virtual void buildNdfa(Ndfa &ndfa, NdfaState *from, NdfaState *to) const = 0;
	virtual ~Regex() {
	}
};

typedef std::shared_ptr<Regex> RegexPtr;

struct BinaryRegex : public Regex {
	RegexPtr left;
	RegexPtr right;

	inline BinaryRegex(const RegexPtr &left, const RegexPtr &right)
		: left(left), right(right)
	{
	}
};

struct UnaryRegex : public Regex {
	RegexPtr regex;

	inline UnaryRegex(const RegexPtr &regex)
		: regex(regex)
	{
	}
};

struct CatRegex : public BinaryRegex {
	inline CatRegex(const RegexPtr &left, const RegexPtr &right)
		: BinaryRegex(left, right)
	{
	}
	void buildNdfa(Ndfa &ndfa, NdfaState *from, NdfaState *to) const override;
};

struct OrRegex : public BinaryRegex {
	inline OrRegex(const RegexPtr &left, const RegexPtr &right)
		: BinaryRegex(left, right)
	{
	}
	void buildNdfa(Ndfa &ndfa, NdfaState *from, NdfaState *to) const override;
};

struct CharRegex : public Regex {
	int value;

	inline CharRegex(int value)
		: value(value)
	{
	}
	void buildNdfa(Ndfa &ndfa, NdfaState *from, NdfaState *to) const override;
};

struct StarRegex : public UnaryRegex {
	inline StarRegex(const RegexPtr &regex)
		: UnaryRegex(regex)
	{
	}
	void buildNdfa(Ndfa &ndfa, NdfaState *from, NdfaState *to) const override;
};

struct OptRegex : public UnaryRegex {
	inline OptRegex(const RegexPtr &regex)
		: UnaryRegex(regex)
	{
	}
	void buildNdfa(Ndfa &ndfa, NdfaState *from, NdfaState *to) const override;
};

} // namespace lexing

#endif /* REGEX_H_ */
