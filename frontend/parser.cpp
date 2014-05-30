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
		const Symbol &PROCEDURE, const Symbol &ID0, const Symbol &SEMI0,
		const Symbol &decls0,
		const Symbol &BEGIN,
		const Symbol &END, const Symbol &ID1, const Symbol &SEMI1)
	{
		auto decls1 = std::dynamic_pointer_cast<Declarations>(decls0.result());
		ProcedurePtr ptr(new Procedure(ID0.token(), decls1, ID1.token()));
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
	Result handleRecord(const Symbol &RECORD, const Symbol &END)
	{
		return NodePtr(new RecordDescriptor());
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
		return NodePtr(new Variable(ID0.token(), ID1.token()));
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



