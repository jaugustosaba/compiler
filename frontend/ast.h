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

struct Procedure;
typedef std::shared_ptr<Procedure> ProcedurePtr;

struct TypeDescriptor : public Node {
};

typedef std::shared_ptr<TypeDescriptor> TypeDescriptorPtr;

struct RecordDescriptor : public TypeDescriptor {
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

struct IdentList : public Node {
	std::vector<TokenPtr> idents;

	inline IdentList() : idents() {
	}
};

typedef std::shared_ptr<IdentList> IdentListPtr;

struct Variable;
typedef std::shared_ptr<Variable> VariablePtr;

struct Variable : public Node {
	IdentListPtr  idents;
	TokenPtr      type;
	VariablePtr   next;

	inline Variable(const IdentListPtr &idents, const TokenPtr &type)
		: idents(idents), type(type), next()
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

struct Module : public Node {
	TokenPtr         id0;
	DeclarationsPtr  decls;
	TokenPtr         id1;

	inline Module(
			const TokenPtr &id0,
			const DeclarationsPtr &decls,
			const TokenPtr &id1
		)
		: id0(id0), decls(decls), id1(id1)
	{
	}
};

struct Procedure : public Node {
	TokenPtr         id0;
	DeclarationsPtr  decls;
	TokenPtr         id1;
	ProcedurePtr     next;

	inline Procedure(
			const TokenPtr &id0,
			const DeclarationsPtr &decls,
			const TokenPtr &id1
		)
		: id0(id0), decls(decls), id1(id1), next()
	{
	}
};

} // namespace frontend

#endif /* AST_H_ */
