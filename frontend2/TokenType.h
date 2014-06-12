#ifndef TOKENTYPE_H_
#define TOKENTYPE_H_

namespace frontend {

enum class TokenType {
	Eof,
	Semi,
	Dot,
	Comma,
	Colon,
	Assign,
	Eq,
	Ne,
	Lt,
	Le,
	Gt,
	Ge,
	LParen,
	RParen,
	Add,
	Sub,
	Mul,
	RealDiv,
	Module,
	End,
	Var,
	Procedure,
	Begin,
	If,
	Then,
	Else,
	Elseif,
	While,
	Do,
	Not,
	Or,
	Div,
	Mod,
	And,
	True,
	False,
	Return,
	Int,
	Id,
};

} // namespace frontend

#endif /* TOKENTYPE_H_ */
