#ifndef AST_H_
#define AST_H_

#include <string>
#include <memory>
#include <vector>

#include "lexer.h"
#include "type-checker.h"
#include "symbol-table.h"

namespace frontend {

struct Type;
struct Node;
struct Decl;
struct Ident;
struct TypeDescriptor;
struct Field;
struct RecordDescriptor;
struct ArrayDescriptor;
struct PointerDescriptor;
struct UserTypeDecl;
struct Expr;
struct VarDecl;
struct ConstDecl;
struct Declarations;
struct IntExpr;
struct BinExpr;
struct UnExpr;
struct IdExpr;
struct FieldExpr;
struct ExprList;
struct CallExpr;
struct DerefExpr;
struct IndexExpr;
struct Stmt;
struct Elseif;
struct IfStmt;
struct WhileStmt;
struct CallStmt;
struct AssignStmt;
struct Module;
struct FParam;
struct Procedure;
struct Function;

typedef std::shared_ptr<Node> NodePtr;
typedef std::shared_ptr<Ident> IdentPtr;
typedef std::shared_ptr<TypeDescriptor> TypeDescriptorPtr;
typedef std::shared_ptr<Field> FieldPtr;
typedef std::shared_ptr<RecordDescriptor> RecordDescriptorPtr;
typedef std::shared_ptr<UserTypeDecl> UserTypeDeclPtr;
typedef std::shared_ptr<Expr> ExprPtr;
typedef std::shared_ptr<VarDecl> VarDeclPtr;
typedef std::shared_ptr<ConstDecl> ConstDeclPtr;
typedef std::shared_ptr<Declarations> DeclarationsPtr;
typedef std::shared_ptr<ExprList> ExprListPtr;
typedef std::shared_ptr<Stmt> StmtPtr;
typedef std::shared_ptr<Elseif> ElseifPtr;
typedef std::shared_ptr<Module> ModulePtr;
typedef std::shared_ptr<FParam> FParamPtr;
typedef std::shared_ptr<Procedure> ProcedurePtr;

enum class UnOp {
	Not,
};

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

struct Node {
	virtual ~Node() {
	}
protected:
	inline Node() {
	}
};

struct Decl : public Node {
	const Type* type;
protected:
	inline Decl() : type(nullptr) {
	}
};

struct Ident : public Node {
	TokenPtr  id;
	IdentPtr  next;

	inline Ident(const TokenPtr &id)
		: id(id), next()
	{
	}
};

struct TypeDescriptor : public Node {
};

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

struct ArrayDescriptor : public TypeDescriptor {
	ExprListPtr firstExpr;
	TokenPtr    type;

	inline ArrayDescriptor(
			const ExprListPtr &firstExpr,
			const TokenPtr &type)
		: firstExpr(firstExpr), type(type)
	{
	}

};

struct PointerDescriptor : public TypeDescriptor {
	TokenPtr type;

	inline PointerDescriptor(const TokenPtr &type)
		: type(type)
	{
	}
};

struct TypeDecl : public Decl {
protected:
	inline TypeDecl() : Decl() {
	}
};

struct BuiltinTypeDecl : public TypeDecl {
	inline BuiltinTypeDecl(const Type* type) : TypeDecl() {
		this->type = type;
	}
};

struct UserTypeDecl : public TypeDecl {
	TokenPtr            id;
	TypeDescriptorPtr   descriptor;
	UserTypeDeclPtr     next;

	inline UserTypeDecl(const TokenPtr &id, const TypeDescriptorPtr &descriptor)
		: TypeDecl(), id(id), descriptor(descriptor), next()
	{
	}
	void loadSymbols(SymbolTable &st);
};

struct Expr : public Node {
	Type* type;

	inline Expr() : type(nullptr) {
	}
};

struct LValue : public Decl {
protected:
	inline LValue() : Decl() {
	}
};

struct VarDecl : public LValue {
	IdentPtr     firstIdent;
	TokenPtr     type;
	VarDeclPtr   next;

	inline VarDecl(const IdentPtr &firstIdent, const TokenPtr &type)
		: LValue(), firstIdent(firstIdent), type(type), next()
	{
	}
	void loadSymbols(SymbolTable &st);
};

struct ConstDecl : public Decl {
	TokenPtr      id;
	ExprPtr       expr;
	ConstDeclPtr  next;

	inline ConstDecl(
			const TokenPtr &id,
			const ExprPtr &expr)
		: id(id), expr(expr)
	{
	}
	void loadSymbols(SymbolTable &st);
};

struct Declarations : public Node {
	ConstDeclPtr     firstConstant;
	UserTypeDeclPtr  firstType;
	VarDeclPtr       firstVariable;
	ProcedurePtr     firstProcedure;

	inline Declarations(
			const ConstDeclPtr &firstConstant,
			const UserTypeDeclPtr &firstType,
			const VarDeclPtr &firstVariable,
			const ProcedurePtr &firstProcedure)
		: firstConstant(firstConstant),
		  firstType(firstType),
		  firstVariable(firstVariable),
		  firstProcedure(firstProcedure)
	{
	}
	void loadSymbols(SymbolTable &parent);
};

struct IntExpr : public Expr {
	TokenPtr value;

	inline
	IntExpr(const TokenPtr &value) : Expr(), value(value) {
	}
};

struct BinExpr : public Expr {
	BinOp    op;
	ExprPtr  left;
	ExprPtr  right;

	inline BinExpr(
			BinOp op,
			const ExprPtr &left,
			const ExprPtr &right)
		: Expr(), op(op), left(left), right(right)
	{
	}
};

struct UnExpr : public Expr {
	UnOp     op;
	ExprPtr  expr;

	inline UnExpr(
			UnOp op,
			const ExprPtr &expr)
		: Expr(), op(op), expr(expr)
	{
	}
};

struct IdExpr : public Expr {
	TokenPtr id;

	inline IdExpr(const TokenPtr &id)
		: Expr(), id(id)
	{
	}
};

struct FieldExpr : public Expr {
	ExprPtr expr;
	TokenPtr field;

	inline FieldExpr(
			const ExprPtr &expr,
			const TokenPtr &field)
		: Expr(), expr(expr), field(field)
	{
	}
};

struct ExprList : public Node {
	ExprPtr      expr;
	ExprListPtr  tail;

	inline ExprList(const ExprPtr &expr)
		: expr(expr)
	{
	}
};

struct CallExpr : public Expr {
	ExprPtr      lvalue;
	ExprListPtr  firstExpr;

	inline CallExpr(const ExprPtr &lvalue, const ExprListPtr &firstExpr)
		: Expr(), lvalue(lvalue), firstExpr(firstExpr)
	{
	}
};

struct DerefExpr : public Expr {
	ExprPtr lvalue;

	inline DerefExpr(const ExprPtr &lvalue)
		: Expr(), lvalue(lvalue)
	{
	}
};

struct IndexExpr : public Expr {
	ExprPtr      lvalue;
	ExprListPtr  firstExpr;

	inline IndexExpr(const ExprPtr &lvalue, const ExprListPtr &firstExpr)
		: Expr(), lvalue(lvalue), firstExpr(firstExpr)
	{
	}
};

struct Stmt : public Node {
	StmtPtr next;

	inline Stmt() : next() {
	}
};

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
			const StmtPtr &firstElseStmt)
		: Stmt(),
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

struct CallStmt : public Stmt {
	ExprPtr  expr;

	inline CallStmt(const ExprPtr &expr)
		: expr(expr)
	{
	}
};

struct AssignStmt : public Stmt {
	ExprPtr  lvalue;
	ExprPtr  rvalue;

	inline AssignStmt(
			const ExprPtr &lvalue,
			const ExprPtr &rvalue)
		: lvalue(lvalue), rvalue(rvalue)
	{
	}
};

struct Module : public Node {
	SymbolTable      symbolTable;
	TokenPtr         id0;
	DeclarationsPtr  decls;
	TokenPtr         id1;

	inline Module(
			const TokenPtr &id0,
			const DeclarationsPtr &decls,
			const TokenPtr &id1)
		: symbolTable(), id0(id0), decls(decls), id1(id1)
	{
	}
	void loadSymbols(const SymbolTable* builtins);
};

struct FParam : public Decl {
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
	void loadSymbols(SymbolTable &st);
};

struct Procedure : public LValue {
	SymbolTable      symbolTable;
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
		: LValue(), symbolTable(), id0(id0), decls(decls),
		  firstStmt(firstStmt), id1(id1), next()
	{
	}
	void loadSymbols(SymbolTable &parent);
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
