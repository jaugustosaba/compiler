#include "parser.h"
#include "lexer.h"

namespace frontend {

namespace {

typedef ParserHelper::Symbol<TokenPtr, NodePtr> Symbol;

struct Semantic {
	typedef NodePtr Result;

	inline
	Result handleModule(
			const Symbol &MODULE, const Symbol &ID0, const Symbol &SEMI0,
			const Symbol &decls0,
			const Symbol &optStmts,
			const Symbol &END, const Symbol &ID1, const Symbol &SEMI1)
	{
		auto decls1 = std::dynamic_pointer_cast<Declarations>(decls0.result());
		return NodePtr(new Module(ID0.token(), decls1, ID1.token()));
	}

	inline
	Result handleDecls(
			const Symbol &consts,
			const Symbol &types,
			const Symbol &vars,
			const Symbol &procdecls)
	{
		auto firstconst = std::dynamic_pointer_cast<ConstDecl>(consts.result());
		auto firsttype = std::dynamic_pointer_cast<UserTypeDecl>(types.result());
		auto firstvar = std::dynamic_pointer_cast<VarDecl>(vars.result());
		auto firstproc = std::dynamic_pointer_cast<Procedure>(procdecls.result());
		return NodePtr(new Declarations(firstconst, firsttype, firstvar, firstproc));
	}

	inline
	Result handleEmptyProcDecls() {
		return NodePtr();
	}

	inline
	Result handleAppendProcDecl(
		const Symbol &procdecl, const Symbol &procdecls)
	{
		auto first = std::dynamic_pointer_cast<Procedure>(procdecl.result());
		auto second = std::dynamic_pointer_cast<Procedure>(procdecls.result());
		first->next = second;
		return first;
	}

	inline
	Result handleProcedure(
		const Symbol &PROCEDURE, const Symbol &ID0, const Symbol &fparams,
		const Symbol &SEMI0, const Symbol &decls0, const Symbol &BEGIN,
		const Symbol &stmts, const Symbol &END, const Symbol &ID1,
		const Symbol &SEMI1)
	{
		auto decls1 = std::dynamic_pointer_cast<Declarations>(decls0.result());
		auto fps = std::dynamic_pointer_cast<FParam>(fparams.result());
		auto stmts1 = std::dynamic_pointer_cast<Stmt>(stmts.result());
		ProcedurePtr ptr(new Procedure(
				ID0.token(), fps, decls1, stmts1, ID1.token()));
		return ptr;
	}

	inline
	Result handleFunction(
		const Symbol &FUNCTION, const Symbol &ID0, const Symbol &fparams,
		const Symbol &COLON, const Symbol &RETTYPE, const Symbol &SEMI0,
		const Symbol &decls0, const Symbol &BEGIN, const Symbol &stmts,
		const Symbol &END, const Symbol &ID1, const Symbol &SEMI1)
	{
		auto decls1 = std::dynamic_pointer_cast<Declarations>(decls0.result());
		auto fps = std::dynamic_pointer_cast<FParam>(fparams.result());
		auto stmts1 = std::dynamic_pointer_cast<Stmt>(stmts.result());
		ProcedurePtr ptr(new Function(
				ID0.token(), fps, RETTYPE.token(), decls1, stmts1, ID1.token()));
		return ptr;
	}

	inline
	Result handleTypes(const Symbol &TYPE, const Symbol &typedecls) {
		return typedecls.result();
	}

	inline
	Result handleAppendTypeDecl(const Symbol &typedecl, const Symbol &typedecls) {
		auto first = std::dynamic_pointer_cast<UserTypeDecl>(typedecl.result());
		auto second = std::dynamic_pointer_cast<UserTypeDecl>(typedecls.result());
		first->next = second;
		return first;
	}

	inline
	Result handleTypeDecl(const Symbol &ID, const Symbol &EQ,
		const Symbol &typedesc, const Symbol &SEMI)
	{
		auto desc = std::dynamic_pointer_cast<TypeDescriptor>(typedesc.result());
		return NodePtr(new UserTypeDecl(ID.token(), desc));
	}

	inline
	Result handleRecord(
		const Symbol &RECORD, const Symbol &fields, const Symbol &END)
	{
		auto firstfield = std::dynamic_pointer_cast<Field>(fields.result());
		return NodePtr(new RecordDescriptor(firstfield));
	}

	inline
	Result handleAppendField(const Symbol &field, const Symbol &fields) {
		auto first = std::dynamic_pointer_cast<Field>(field.result());
		auto second = std::dynamic_pointer_cast<Field>(fields.result());
		first->next = second;
		return first;
	}

	inline
	Result handleField(
			const Symbol &identlist, const Symbol &COLON,
			const Symbol &ID, const Symbol &SEMI)
	{
		auto firstIdent = std::dynamic_pointer_cast<Ident>(identlist.result());
		return NodePtr(new Field(firstIdent, ID.token()));
	}

	inline
	Result handleVars(const Symbol &VAR, const Symbol &vardecls) {
		return vardecls.result();
	}

	inline
	Result handleAppendVarDecl(const Symbol &vardecl, const Symbol &vardecls) {
		auto first = std::dynamic_pointer_cast<VarDecl>(vardecl.result());
		auto second = std::dynamic_pointer_cast<VarDecl>(vardecls.result());
		first->next = second;
		return first;
	}

	inline
	Result handleVarDecl(const Symbol &ID0, const Symbol &COLON,
			const Symbol &ID1, const Symbol &SEMI)
	{
		auto firstIdent = std::dynamic_pointer_cast<Ident>(ID0.result());
		return NodePtr(new VarDecl(firstIdent, ID1.token()));
	}

	inline
	Result handleIdentList(const Symbol &ID, const Symbol &identlisttail) {
		IdentPtr ident(new Ident(ID.token()));
		ident->next = std::dynamic_pointer_cast<Ident>(identlisttail.result());
		return ident;
	}

	inline
	Result handleAppendIdent(
			const Symbol &COMMA, const Symbol &ID, const Symbol &identlisttail)
	{
		IdentPtr ident(new Ident(ID.token()));
		ident->next = std::dynamic_pointer_cast<Ident>(identlisttail.result());
		return ident;
	}

	inline
	Result handleFParams(
			const Symbol &LPAREN, const Symbol &fparam,
			const Symbol &fparamlist, const Symbol &RPAREN)
	{
		return appendFParam(fparam, fparamlist);
	}

	inline
	Result handleAppendFParam(
			const Symbol &SEMI, const Symbol &fparam, const Symbol &fparamlist)
	{
		return appendFParam(fparam, fparamlist);
	}

	inline
	Result appendFParam(const Symbol &fparam, const Symbol &fparamlist) {
		auto first = std::dynamic_pointer_cast<FParam>(fparam.result());
		auto second = std::dynamic_pointer_cast<FParam>(fparamlist.result());
		first->next = second;
		return first;
	}

	inline
	Result handleVarFParam(
			const Symbol &VAR, const Symbol &identlist,
			const Symbol &COLON, const Symbol &ID)
	{
		return newFParam(true, identlist, ID);
	}

	inline
	Result handleFParam(
			const Symbol &identlist, const Symbol &COLON, const Symbol &ID)
	{
		return newFParam(false, identlist, ID);
	}

	inline Result newFParam(bool isVar, const Symbol &identlist, const Symbol &ID) {
		auto firstIdent = std::dynamic_pointer_cast<Ident>(identlist.result());
		return NodePtr(new FParam(isVar, firstIdent, ID.token()));
	}

	inline
	Result handleOptStmt(const Symbol &BEGIN, const Symbol &stmts) {
		return stmts.result();
	}

	inline
	Result handleAppendStmt(
			const Symbol &stmt, const Symbol &SEMI, const Symbol &stmts)
	{
		auto first = std::dynamic_pointer_cast<Stmt>(stmt.result());
		auto second = std::dynamic_pointer_cast<Stmt>(stmts.result());
		first->next = second;
		return first;
	}

	inline
	Result handleIfStmt(
			const Symbol &IF, const Symbol &expr, const Symbol &THEN,
			const Symbol &stmts, const Symbol &elseifs, const Symbol &optElse,
			const Symbol &END)
	{
		auto exp = std::dynamic_pointer_cast<Expr>(expr.result());
		auto firstStmt = std::dynamic_pointer_cast<Stmt>(stmts.result());
		auto firstElseif = std::dynamic_pointer_cast<Elseif>(elseifs.result());
		auto firstElseStmt = std::dynamic_pointer_cast<Stmt>(optElse.result());
		return NodePtr(new IfStmt(exp, firstStmt, firstElseif, firstElseStmt));
	}

	inline
	Result handleAppendElseif(const Symbol &elseif, const Symbol &elseifs) {
		auto first = std::dynamic_pointer_cast<Elseif>(elseif.result());
		auto second = std::dynamic_pointer_cast<Elseif>(elseifs.result());
		first->next = second;
		return first;
	}

	inline
	Result handleElseif(
			const Symbol &ELSEIF, const Symbol &expr,
			const Symbol &THEN, const Symbol &stmts)
	{
		auto exp = std::dynamic_pointer_cast<Expr>(expr.result());
		auto firstStmt = std::dynamic_pointer_cast<Stmt>(stmts.result());
		return NodePtr(new Elseif(exp, firstStmt));
	}

	inline
	Result handleOptElse(const Symbol &ELSE, const Symbol &stmts) {
		return stmts.result();
	}

	inline
	Result handleWhile(
			const Symbol &WHILE, const Symbol &expr, const Symbol &DO,
			const Symbol &stmts, const Symbol &END)
	{
		auto expr1 = std::dynamic_pointer_cast<Expr>(expr.result());
		auto firstStmt = std::dynamic_pointer_cast<Stmt>(stmts.result());
		return NodePtr(new WhileStmt(expr1, firstStmt));
	}

	inline
	Result handleEq(const Symbol &expr0, const Symbol &EQ, const Symbol &expr1) {
		return makeBinaryExpr(BinOp::EQ, expr0, expr1);
	}

	inline
	Result handleNe(const Symbol &expr0, const Symbol &NE, const Symbol &expr1) {
		return makeBinaryExpr(BinOp::NE, expr0, expr1);
	}

	inline
	Result handleLt(const Symbol &expr0, const Symbol &LT, const Symbol &expr1) {
		return makeBinaryExpr(BinOp::LT, expr0, expr1);
	}

	inline
	Result handleLe(const Symbol &expr0, const Symbol &LE, const Symbol &expr1) {
		return makeBinaryExpr(BinOp::LE, expr0, expr1);
	}

	inline
	Result handleGt(const Symbol &expr0, const Symbol &GT, const Symbol &expr1) {
		return makeBinaryExpr(BinOp::GT, expr0, expr1);
	}

	inline
	Result handleGe(const Symbol &expr0, const Symbol &GE, const Symbol &expr1) {
		return makeBinaryExpr(BinOp::GE, expr0, expr1);
	}

	inline
	Result handleAdd(const Symbol &expr0, const Symbol &ADD, const Symbol &expr1) {
		return makeBinaryExpr(BinOp::Add, expr0, expr1);
	}

	inline
	Result handleSub(const Symbol &expr0, const Symbol &SUB, const Symbol &expr1) {
		return makeBinaryExpr(BinOp::Sub, expr0, expr1);
	}

	inline
	Result handleMul(const Symbol &expr0, const Symbol &MUL, const Symbol &expr1) {
		return makeBinaryExpr(BinOp::Mul, expr0, expr1);
	}

	inline
	Result handleRealDiv(const Symbol &expr0, const Symbol &REALDIV, const Symbol &expr1) {
		return makeBinaryExpr(BinOp::RealDiv, expr0, expr1);
	}

	inline
	Result handleDiv(const Symbol &expr0, const Symbol &DIV, const Symbol &expr1) {
		return makeBinaryExpr(BinOp::Div, expr0, expr1);
	}

	inline
	Result handleMod(const Symbol &expr0, const Symbol &MOD, const Symbol &expr1) {
		return makeBinaryExpr(BinOp::Mod, expr0, expr1);
	}

	inline
	Result handleAnd(const Symbol &expr0, const Symbol &AND, const Symbol &expr1) {
		return makeBinaryExpr(BinOp::And, expr0, expr1);
	}

	inline
	Result handleOr(const Symbol &expr0, const Symbol &OR, const Symbol &expr1) {
		return makeBinaryExpr(BinOp::Or, expr0, expr1);
	}

	inline
	Result makeBinaryExpr(BinOp op, const Symbol &expr0, const Symbol &expr1) {
		auto left = std::dynamic_pointer_cast<Expr>(expr0.result());
		auto right = std::dynamic_pointer_cast<Expr>(expr1.result());
		return NodePtr(new BinExpr(op, left, right));
	}

	inline
	Result handleNot(const Symbol &NOT, const Symbol &expr) {
		return makeUnaryExpr(UnOp::Not, expr);
	}

	inline
	Result makeUnaryExpr(UnOp op, const Symbol &expr) {
		auto expr1 = std::dynamic_pointer_cast<Expr>(expr.result());
		return NodePtr(new UnExpr(op, expr1));
	}

	inline
	Result handleSubExpr(const Symbol &LPAREN, const Symbol &expr, const Symbol &RPAREN) {
		return expr.result();
	}

	inline
	Result handleFieldExpr(const Symbol &expr, const Symbol &DOT, const Symbol &ID) {
		auto expr1 = std::dynamic_pointer_cast<Expr>(expr.result());
		return NodePtr(new FieldExpr(expr1, ID.token()));
	}

	inline
	Result handleIntExpr(const Symbol &INTLIT) {
		return NodePtr(new IntExpr(INTLIT.token()));
	}

	inline
	Result handleIdExpr(const Symbol &ID) {
		return NodePtr(new IdExpr(ID.token()));
	}

	inline
	Result handleAssignStmt(const Symbol &ASSIGN, const Symbol &expr) {
		return expr.result();
	}

	inline
	Result handleCallOrAssignStmt(const Symbol &expr, const Symbol &optassign) {
		auto lvalue = std::dynamic_pointer_cast<Expr>(expr.result());
		auto rvalue = std::dynamic_pointer_cast<Expr>(optassign.result());
		if (rvalue.get() == nullptr) {
			return NodePtr(new CallStmt(lvalue));
		}
		return NodePtr(new AssignStmt(lvalue, rvalue));
	}

	inline
	Result handleCallExpr(const Symbol &expr, const Symbol &aparams) {
		auto lvalue = std::dynamic_pointer_cast<Expr>(expr.result());
		auto fistAParam = std::dynamic_pointer_cast<ExprList>(aparams.result());
		return NodePtr(new CallExpr(lvalue, fistAParam));
	}

	inline
	Result handleAParams(
			const Symbol &LPAREN, const Symbol &exprlist, const Symbol &RPAREN)
	{
		return exprlist.result();
	}

	inline
	Result handleFirstExpr(const Symbol &expr, const Symbol &aparamlisttail) {
		return appendExpr(expr, aparamlisttail);
	}

	inline
	Result handleAppendExpr(
			const Symbol &COMMA, const Symbol &expr, const Symbol &exprlisttail)
	{
		return appendExpr(expr, exprlisttail);
	}

	inline
	Result appendExpr(const Symbol &expr, const Symbol &exprlist) {
		auto expr1 = std::dynamic_pointer_cast<Expr>(expr.result());
		ExprListPtr first(new ExprList(expr1));
		auto second = std::dynamic_pointer_cast<ExprList>(exprlist.result());
		first->tail = second;
		return first;
	}

	inline
	Result handlePointer(const Symbol &POINTER, const Symbol &TO, const Symbol &ID) {
		return NodePtr(new PointerDescriptor(ID.token()));
	}

	inline
	Result handleArray(
			const Symbol &ARRAY, const Symbol &exprlist,
			const Symbol &OF, const Symbol &ID)
	{
		auto exprs = std::dynamic_pointer_cast<ExprList>(exprlist.result());
		return NodePtr(new ArrayDescriptor(exprs, ID.token()));
	}

	inline
	Result handleDerefExpr(const Symbol &expr, const Symbol &DEREF) {
		auto lvalue = std::dynamic_pointer_cast<Expr>(expr.result());
		return NodePtr(new DerefExpr(lvalue));
	}

	inline
	Result handleIndexExpr(
			const Symbol &expr, const Symbol &LSQUARE,
			const Symbol &exprlist, const Symbol &RSQUARE)
	{
		auto lvalue = std::dynamic_pointer_cast<Expr>(expr.result());
		auto firstExpr = std::dynamic_pointer_cast<ExprList>(exprlist.result());
		return NodePtr(new IndexExpr(lvalue, firstExpr));
	}

	inline
	Result handleConsts(const Symbol &CONST, const Symbol &constlist) {
		return constlist.result();
	}

	inline
	Result handleAppendConst(const Symbol &constt, const Symbol &constlist) {
		auto first = std::dynamic_pointer_cast<ConstDecl>(constt.result());
		auto second = std::dynamic_pointer_cast<ConstDecl>(constlist.result());
		first->next = second;
		return first;
	}

	inline
	Result handleConst(
			const Symbol &ID, const Symbol &EQ,
			const Symbol &expr, const Symbol &SEMI)
	{
		auto expr0 = std::dynamic_pointer_cast<Expr>(expr.result());
		return NodePtr(new ConstDecl(ID.token(), expr0));
	}
};

} // anonymous namespace

ModulePtr parse(std::istream &input) {
	Lexer lexer(input);
	lexer.next();
	Semantic semantic;
	auto expr = ParserHelper::parse(lexer, semantic);
	return std::dynamic_pointer_cast<Module>(expr);
}

} // namespace frontend



