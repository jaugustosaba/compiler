#ifndef AST_H_
#define AST_H_

#include <string>
#include <memory>
#include <vector>

#include "lexer.h"
#include "symbol-table.h"

namespace frontend {

struct Type;
struct RecordType;
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
struct Designator;
struct VarDecl;
struct ConstDecl;
struct Declarations;
struct IntExpr;
struct BinExpr;
struct UnExpr;
struct IdDesig;
struct FieldDesig;
struct ExprList;
struct IdExpr;
struct DerefDesig;
struct IndexDesig;
struct Stmt;
struct Elseif;
struct IfStmt;
struct WhileStmt;
struct CallStmt;
struct AssignStmt;
struct Module;
struct FParam;
struct BaseProcedure;
struct Procedure;
struct Function;

typedef std::unique_ptr<Type> TypePtr;
typedef std::shared_ptr<Node> NodePtr;
typedef std::shared_ptr<Ident> IdentPtr;
typedef std::shared_ptr<TypeDescriptor> TypeDescriptorPtr;
typedef std::shared_ptr<Field> FieldPtr;
typedef std::shared_ptr<RecordDescriptor> RecordDescriptorPtr;
typedef std::shared_ptr<UserTypeDecl> UserTypeDeclPtr;
typedef std::shared_ptr<Expr> ExprPtr;
typedef std::shared_ptr<Designator> DesignatorPtr;
typedef std::shared_ptr<VarDecl> VarDeclPtr;
typedef std::shared_ptr<ConstDecl> ConstDeclPtr;
typedef std::shared_ptr<Declarations> DeclarationsPtr;
typedef std::shared_ptr<ExprList> ExprListPtr;
typedef std::shared_ptr<Stmt> StmtPtr;
typedef std::shared_ptr<Elseif> ElseifPtr;
typedef std::shared_ptr<Module> ModulePtr;
typedef std::shared_ptr<FParam> FParamPtr;
typedef std::shared_ptr<BaseProcedure> BaseProcedurePtr;

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

class TypeError : public std::exception {
	std::string m_message;
public:
	inline TypeError(const std::string &message)
		: m_message(message)
	{
	}
	const char* what() const noexcept override;
	~TypeError() noexcept override;
};

struct Type {
	const static Type BOOLEAN;
	const static Type INTEGER;
	virtual ~Type() {
	}
protected:
	inline Type() {
	}
};

struct ArrayType : public Type {
	size_t       dimension;
	const Type*  elementType;
};

struct RecordType : public Type {
	std::unordered_map<std::string, const Type*> fieldTypes;
};

struct PointerType : public Type {
	const RecordType*  targetType;
};

struct FParamType {
	const Type*  type;
	bool         isVar;
	bool         isOpenArray;
};

struct ProcedureType : public Type {
	std::vector<FParamType> params;
};

struct FunctionType : public ProcedureType {
	const Type* returnType;
};

struct Node {
	virtual ~Node() {
	}
protected:
	inline Node() {
	}
};

struct Decl : public Node {
	virtual const Type* effectiveType() const = 0;
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
	virtual void loadType(SymbolTable &st) = 0;
	virtual const Type* effectiveType() const = 0;
};

struct Field : public Node {
	IdentPtr  firstIdent;
	TokenPtr  typeName;
	FieldPtr  next;

	inline Field(const IdentPtr &firstIdent, const TokenPtr &typeName)
		: firstIdent(firstIdent), typeName(typeName), next()
	{
	}
};

struct RecordDescriptor : public TypeDescriptor {
	RecordType type;
	FieldPtr   firstField;

	inline RecordDescriptor(const FieldPtr &firstField)
		: TypeDescriptor(),
		  type(),
		  firstField(firstField)
	{
	}
	void loadType(SymbolTable &st) override;
	const Type* effectiveType() const override;
};

struct ArrayDescriptor : public TypeDescriptor {
	ArrayType    type;
	ExprListPtr  firstExpr;
	TokenPtr     elementTypeName;

	inline ArrayDescriptor(
			const ExprListPtr &firstExpr,
			const TokenPtr &elementTypeName)
		: TypeDescriptor(),
		  type(),
		  firstExpr(firstExpr),
		  elementTypeName(elementTypeName)
	{
	}
	void loadType(SymbolTable &st) override;
	const Type* effectiveType() const override;
};

struct PointerDescriptor : public TypeDescriptor {
	PointerType  type;
	TokenPtr     typeName;

	inline PointerDescriptor(const TokenPtr &typeName)
		: TypeDescriptor(),
		  typeName(typeName)
	{
	}
	void loadType(SymbolTable &st) override;
	const Type* effectiveType() const override;
};

struct TypeDecl : public Decl {
protected:
	inline TypeDecl() : Decl() {
	}
};

struct BuiltinTypeDecl : public TypeDecl {
	const Type *type;

	inline BuiltinTypeDecl(const Type* type)
		: TypeDecl(), type(type)
	{
	}
	const Type* effectiveType() const override;
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
	void loadTypes(SymbolTable &st);
	const Type* effectiveType() const override;
};

struct Expr : public Node {
	const Type* type;

	inline Expr()
		: type(nullptr)
	{
	}
	virtual void typeCheck(SymbolTable &st) = 0;
};

struct LValue : public Decl {
protected:
	inline LValue() : Decl() {
	}
};

struct VarDecl : public LValue {
	IdentPtr     firstIdent;
	TokenPtr     typeName;
	const Type*  type;
	VarDeclPtr   next;

	inline VarDecl(const IdentPtr &firstIdent, const TokenPtr &typeName)
		: LValue(), firstIdent(firstIdent), typeName(typeName),
		  type(nullptr), next()
	{
	}
	const Type* effectiveType() const override;
	void loadSymbols(SymbolTable &st);
	void loadTypes(SymbolTable &st);
};

struct ConstDecl : public Decl {
	TokenPtr      id;
	ExprPtr       expr;
	const Type*   type;
	ConstDeclPtr  next;

	inline ConstDecl(
			const TokenPtr &id,
			const ExprPtr &expr)
		: id(id), expr(expr), type(nullptr), next()
	{
	}
	void loadSymbols(SymbolTable &st);
	void typeCheck(SymbolTable &st);
	const Type* effectiveType() const override;
};

struct Declarations : public Node {
	ConstDeclPtr      firstConstant;
	UserTypeDeclPtr   firstType;
	VarDeclPtr        firstVariable;
	BaseProcedurePtr  firstProcedure;

	inline Declarations(
			const ConstDeclPtr &firstConstant,
			const UserTypeDeclPtr &firstType,
			const VarDeclPtr &firstVariable,
			const BaseProcedurePtr &firstProcedure)
		: firstConstant(firstConstant),
		  firstType(firstType),
		  firstVariable(firstVariable),
		  firstProcedure(firstProcedure)
	{
	}
	void loadSymbols(SymbolTable &parent);
	void loadTypes(SymbolTable &st);
	void typeCheck(SymbolTable &st);
};

struct IntExpr : public Expr {
	TokenPtr value;

	inline
	IntExpr(const TokenPtr &value) : Expr(), value(value) {
	}
	void typeCheck(SymbolTable &st) override;
};

struct BoolExpr : public Expr {
	bool value;

	inline
	BoolExpr(bool value) : Expr(), value(value) {
	}
	void typeCheck(SymbolTable &st) override;
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
	void typeCheck(SymbolTable &st) override;
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
	void typeCheck(SymbolTable &st) override;
};

struct Designator : public Node {
	const Type* type;
	virtual void typeCheck(SymbolTable &st) = 0;
	virtual bool isUpdatable() const;
};

struct IdDesig : public Designator {
	TokenPtr id;
	Decl*    decl;

	inline IdDesig(const TokenPtr &id)
		: Designator(), id(id), decl(nullptr)
	{
	}
	void typeCheck(SymbolTable &st) override;
	bool isUpdatable() const override;
};

struct FieldDesig : public Designator {
	DesignatorPtr  designator;
	TokenPtr       field;

	inline FieldDesig(
			const DesignatorPtr &designator,
			const TokenPtr &field)
		: Designator(), designator(designator), field(field)
	{
	}
	void typeCheck(SymbolTable &st) override;
};

struct ExprList : public Node {
	ExprPtr      expr;
	ExprListPtr  tail;

	inline ExprList(const ExprPtr &expr)
		: expr(expr)
	{
	}
	void typeCheck(SymbolTable &st);
};

struct DerefDesig : public Designator {
	DesignatorPtr designator;

	inline DerefDesig(const DesignatorPtr &designator)
		: Designator(), designator(designator)
	{
	}
	void typeCheck(SymbolTable &st) override;
};

struct IndexDesig : public Designator {
	DesignatorPtr  designator;
	ExprListPtr    firstExpr;

	inline IndexDesig(const DesignatorPtr &designator, const ExprListPtr &firstExpr)
		: Designator(), designator(designator), firstExpr(firstExpr)
	{
	}
	void typeCheck(SymbolTable &st) override;
};

struct Stmt : public Node {
	StmtPtr next;

	inline Stmt() : next() {
	}
	virtual void typeCheck(SymbolTable &st) = 0;
};

struct Elseif : public Node {
	ExprPtr    expr;
	StmtPtr    firstStmt;
	ElseifPtr  next;

	inline Elseif(
			const ExprPtr &expr,
			const StmtPtr &firstStmt)
		: expr(expr), firstStmt(firstStmt), next()
	{
	}
	void typeCheck(SymbolTable &st);
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
	void typeCheck(SymbolTable &st) override;
};

struct IdExpr : public Expr {
	DesignatorPtr  designator;
	ExprListPtr    firstExpr;

	inline IdExpr(const DesignatorPtr &designator, const ExprListPtr &firstExpr)
		: Expr(), designator(designator), firstExpr(firstExpr)
	{
	}
	void typeCheck(SymbolTable &st) override;
};

struct WhileStmt : public Stmt {
	ExprPtr  expr;
	StmtPtr  firstStmt;

	inline WhileStmt(const ExprPtr &expr, const StmtPtr &firstStmt)
		: Stmt(), expr(expr), firstStmt(firstStmt)
	{
	}
	void typeCheck(SymbolTable &st) override;
};

struct CallStmt : public Stmt {
	DesignatorPtr  designator;
	ExprListPtr    aparams;

	inline CallStmt(const DesignatorPtr &designator, const ExprListPtr &aparams)
		: designator(designator), aparams(aparams)
	{
	}
	void typeCheck(SymbolTable &st) override;
};

struct AssignStmt : public Stmt {
	DesignatorPtr  designator;
	ExprPtr        expr;

	inline AssignStmt(const DesignatorPtr &designator, const ExprPtr &expr)
		: designator(designator), expr(expr)
	{
	}
	void typeCheck(SymbolTable &st) override;
};

struct TypeContainer {
	std::vector<TypePtr> declaredTypes;
};

struct Module : public Node, public TypeContainer {
	SymbolTable      symbolTable;
	TokenPtr         id0;
	DeclarationsPtr  decls;
	StmtPtr          firstStmt;
	TokenPtr         id1;

	inline Module(
			const TokenPtr &id0,
			const DeclarationsPtr &decls,
			const StmtPtr &firstStmt,
			const TokenPtr &id1)
		: Node(), TypeContainer(), symbolTable(),
		  id0(id0), decls(decls), firstStmt(firstStmt), id1(id1)
	{
	}
	void loadSymbols(const SymbolTable* builtins);
	void loadTypes();
	void typeCheck();
};

struct FParam : public Decl {
	bool          isVar;
	IdentPtr      firstIdent;
	TokenPtr      typeName;
	const Type*   type;
	FParamPtr     next;

	inline FParam(
			bool isVar,
			const IdentPtr &firstIdent,
			const TokenPtr &typeName)
		: isVar(isVar), firstIdent(firstIdent),
		  typeName(typeName), type(nullptr), next()
	{
	}
	void loadSymbols(SymbolTable &st);
	void loadTypes(SymbolTable &st);
	const Type* effectiveType() const override;
};

struct BaseProcedure : public LValue {
	SymbolTable       symbolTable;
	TokenPtr          id0;
	FParamPtr         firstFParam;
	DeclarationsPtr   decls;
	StmtPtr           firstStmt;
	TokenPtr          id1;
	BaseProcedurePtr  next;

	inline BaseProcedure(
			const TokenPtr &id0,
			const FParamPtr &firstFParam,
			const DeclarationsPtr &decls,
			const StmtPtr &firstStmt,
			const TokenPtr &id1)
		: LValue(), symbolTable(), id0(id0),
		  firstFParam(firstFParam), decls(decls),
		  firstStmt(firstStmt), id1(id1), next()
	{
	}
	void loadSymbols(SymbolTable &parent);
	virtual void loadTypes(SymbolTable &st);
	virtual void typeCheck();
};

struct Procedure : public BaseProcedure {
	ProcedureType type;

	inline Procedure(
			const TokenPtr &id0,
			const FParamPtr &firstFParam,
			const DeclarationsPtr &decls,
			const StmtPtr &firstStmt,
			const TokenPtr &id1)
		: BaseProcedure(id0, firstFParam, decls, firstStmt, id1),
		  type()
	{
	}
	void loadTypes(SymbolTable &st) override;
	const Type* effectiveType() const override;
};

struct Function : public BaseProcedure {
	TokenPtr      resultType;
	FunctionType  type;

	inline Function(
			const TokenPtr &id0,
			const FParamPtr &firstFParam,
			const TokenPtr &resultType,
			const DeclarationsPtr &decls,
			const StmtPtr &firstStmt,
			const TokenPtr &id1
		)
		: BaseProcedure(id0, firstFParam, decls, firstStmt, id1),
		  resultType(resultType), type()
	{
	}
	void loadTypes(SymbolTable &st) override;
	const Type* effectiveType() const override;
};

} // namespace frontend

#endif /* AST_H_ */
