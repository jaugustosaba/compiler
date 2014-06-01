#ifndef AST_H_
#define AST_H_

#include <string>
#include <memory>
#include <vector>

#include "lexer.h"

namespace frontend {

struct Node {
	virtual ~Node() {
	}
};

typedef std::shared_ptr<Node> NodePtr;

struct Ident;
typedef std::shared_ptr<Ident> IdentPtr;

struct Ident : public Node {
	TokenPtr  id;
	IdentPtr  next;

	inline Ident(const TokenPtr &id)
		: id(id), next()
	{
	}
};

struct Procedure;
typedef std::shared_ptr<Procedure> ProcedurePtr;

struct TypeDescriptor : public Node {
};

typedef std::shared_ptr<TypeDescriptor> TypeDescriptorPtr;

struct Field;

typedef std::shared_ptr<Field> FieldPtr;

struct Field : public Node {
	IdentPtr  firstIdent;
	TokenPtr  type;
	FieldPtr  next;

	inline Field(
			const IdentPtr &firstIdent,
			const TokenPtr &type
		)
		: firstIdent(firstIdent), type(type), next()
	{
	}
};

struct RecordDescriptor : public TypeDescriptor {
	FieldPtr firstField;

	inline RecordDescriptor(const FieldPtr &firstField)
		: firstField(firstField)
	{
	}
};

typedef std::shared_ptr<RecordDescriptor> RecordDescriptorPtr;

struct Type;
typedef std::shared_ptr<Type> TypePtr;

struct Type : public Node {
	TokenPtr            id;
	TypeDescriptorPtr   descriptor;
	TypePtr             next;

	inline Type(const TokenPtr &id, const TypeDescriptorPtr &descriptor)
		: id(id), descriptor(descriptor), next()
	{
	}
};

struct Variable;
typedef std::shared_ptr<Variable> VariablePtr;

struct Variable : public Node {
	IdentPtr     firstIdent;
	TokenPtr     type;
	VariablePtr  next;

	inline Variable(const IdentPtr &firstIdent, const TokenPtr &type)
		: firstIdent(firstIdent), type(type), next()
	{
	}
};

struct Declarations : public Node {
	TypePtr  firstType;
	VariablePtr         firstVariable;
	ProcedurePtr        firstProcedure;

	inline Declarations(
			const TypePtr &firstType,
			const VariablePtr &firstVariable,
			const ProcedurePtr &firstProcedure
		)
		: firstType(firstType),
		  firstVariable(firstVariable),
		  firstProcedure(firstProcedure)
	{
	}
};

typedef std::shared_ptr<Declarations> DeclarationsPtr;

struct Expr : public Node {
};

typedef std::shared_ptr<Expr> ExprPtr;

enum class BinOp {
	EQ,
	NE,
	LT,
	LE,
	GT,
	GE,
	Add,
	Sub,
	Mul,
	RealDiv,
	Div,
	Mod,
	And,
	Or
};

struct BinExpr : public Expr {
	BinOp    op;
	ExprPtr  left;
	ExprPtr  right;

	inline BinExpr(
			BinOp op,
			const ExprPtr &left,
			const ExprPtr &right)
		: op(op), left(left), right(right)
	{
	}
};

enum class UnOp {
	Not,
};

struct UnExpr : public Expr {
	UnOp     op;
	ExprPtr  expr;

	inline UnExpr(
			UnOp op,
			const ExprPtr &expr)
		: op(op), expr(expr)
	{
	}
};

struct IdExpr : public Expr {
	TokenPtr id;

	inline IdExpr(const TokenPtr &id)
		: id(id)
	{
	}
};

struct FieldExpr : public Expr {
	ExprPtr expr;
	TokenPtr field;

	inline FieldExpr(
			const ExprPtr &expr,
			const TokenPtr &field)
		: expr(expr), field(field)
	{
	}
};

struct Stmt;
typedef std::shared_ptr<Stmt> StmtPtr;

struct Stmt : public Node {
	StmtPtr next;

	inline Stmt() : next() {
	}
};

struct Elseif;
typedef std::shared_ptr<Elseif> ElseifPtr;

struct Elseif : public Node {
	ExprPtr    expr;
	StmtPtr    firstStmt;
	ElseifPtr  next;

	inline Elseif(
			const ExprPtr &expr,
			const StmtPtr &firstStmt
		) : expr(expr), firstStmt(firstStmt), next()
	{
	}
};

struct IfStmt : public Stmt {
	ExprPtr    expr;
	StmtPtr    firstStmt;
	ElseifPtr  firstElseif;
	StmtPtr    firstElseStmt;

	inline IfStmt(
			const ExprPtr &expr,
			const StmtPtr &firstStmt,
			const ElseifPtr &firstElseif,
			const StmtPtr &firstElseStmt
		) : Stmt(),
			expr(expr),
			firstStmt(firstStmt),
			firstElseif(firstElseif),
			firstElseStmt(firstElseStmt)
	{
	}
};

struct WhileStmt : public Stmt {
	ExprPtr  expr;
	StmtPtr  firstStmt;

	inline WhileStmt(const ExprPtr &expr, const StmtPtr &firstStmt)
		: Stmt(), expr(expr), firstStmt(firstStmt)
	{
	}
};

struct Module : public Node {
	TokenPtr         id0;
	DeclarationsPtr  decls;
	TokenPtr         id1;

	inline Module(
			const TokenPtr &id0,
			const DeclarationsPtr &decls,
			const TokenPtr &id1)
		: id0(id0), decls(decls), id1(id1)
	{
	}
};

struct FParam;

typedef std::shared_ptr<FParam> FParamPtr;

struct FParam : public Node {
	bool          isVar;
	IdentPtr      firstIdent;
	TokenPtr      type;
	FParamPtr     next;

	inline FParam(
			bool isVar,
			const IdentPtr &firstIdent,
			const TokenPtr &type)
		: isVar(isVar), firstIdent(firstIdent), type(type)
	{
	}
};

struct Procedure : public Node {
	TokenPtr         id0;
	FParamPtr        firstFParam;
	DeclarationsPtr  decls;
	StmtPtr          firstStmt;
	TokenPtr         id1;
	ProcedurePtr     next;

	inline Procedure(
			const TokenPtr &id0,
			const FParamPtr &firstFParam,
			const DeclarationsPtr &decls,
			const StmtPtr &firstStmt,
			const TokenPtr &id1
		)
		: id0(id0), decls(decls), firstStmt(firstStmt),
		  id1(id1), next()
	{
	}
};

struct Function : public Procedure {
	TokenPtr resultType;

	inline Function(
			const TokenPtr &id0,
			const FParamPtr &firstFParam,
			const TokenPtr &resultType,
			const DeclarationsPtr &decls,
			const StmtPtr &firstStmt,
			const TokenPtr &id1
		)
		: Procedure(id0, firstFParam, decls, firstStmt, id1),
		  resultType(resultType)
	{
	}
};

} // namespace frontend

#endif /* AST_H_ */
