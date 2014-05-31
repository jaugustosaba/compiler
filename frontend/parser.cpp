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
			const Symbol &types,
			const Symbol &vars,
			const Symbol &procdecls)
	{
		auto firsttype = std::dynamic_pointer_cast<Type>(types.result());
		auto firstvar = std::dynamic_pointer_cast<Variable>(vars.result());
		auto firstproc = std::dynamic_pointer_cast<Procedure>(procdecls.result());
		return NodePtr(new Declarations(firsttype, firstvar, firstproc));
	}

	inline
	Result handleEmptyProcDecls() {
		return NodePtr();
	}

	inline
	Result handleAppendProcDecl(
		const Symbol &procdecl, const Symbol &procdecls)
	{
		auto first = std::dynamic_pointer_cast<Procedure>(procdecls.result());
		auto second = std::dynamic_pointer_cast<Procedure>(procdecl.result());
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
		auto first = std::dynamic_pointer_cast<Type>(typedecl.result());
		auto second = std::dynamic_pointer_cast<Type>(typedecl.result());
		first->next = second;
		return first;
	}

	inline
	Result handleTypeDecl(const Symbol &ID, const Symbol &EQ,
		const Symbol &typedesc, const Symbol &SEMI)
	{
		auto desc = std::dynamic_pointer_cast<TypeDescriptor>(typedesc.result());
		return NodePtr(new Type(ID.token(), desc));
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
		auto first = std::dynamic_pointer_cast<Variable>(vardecl.result());
		auto second = std::dynamic_pointer_cast<Variable>(vardecls.result());
		first->next = second;
		return first;
	}

	inline
	Result handleVarDecl(const Symbol &ID0, const Symbol &COLON,
			const Symbol &ID1, const Symbol &SEMI)
	{
		auto firstIdent = std::dynamic_pointer_cast<Ident>(ID0.result());
		return NodePtr(new Variable(firstIdent, ID1.token()));
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
};

} // anonymous namespace

NodePtr parse(std::istream &input) {
	Lexer lexer(input);
	lexer.next();
	Semantic semantic;
	return ParserHelper::parse(lexer, semantic);
}

} // namespace frontend



