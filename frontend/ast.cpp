#include "ast.h"

namespace frontend {

void Module::loadSymbols(const SymbolTable* builtins) {
	symbolTable.setParent(builtins);
	decls->loadSymbols(symbolTable);
}

void Declarations::loadSymbols(SymbolTable &st) {
	if (firstConstant) {
		firstConstant->loadSymbols(st);
	}
	if (firstType) {
		firstType->loadSymbols(st);
	}
	if (firstVariable) {
		firstVariable->loadSymbols(st);
	}
}

void ConstDecl::loadSymbols(SymbolTable &st) {
	ConstDecl *constt = this;
	while (constt != nullptr) {
		st.declare(constt->id->lexeme(), constt);
		constt = constt->next.get();
	}
}

void UserTypeDecl::loadSymbols(SymbolTable &st) {
	UserTypeDecl *type = this;
	while (type != nullptr) {
		st.declare(type->id->lexeme(), type);
		type = type->next.get();
	}
}

void VarDecl::loadSymbols(SymbolTable &st) {
	VarDecl *var = this;
	while (var != nullptr) {
		Ident *ident = var->firstIdent.get();
		while (ident != nullptr) {
			st.declare(ident->id->lexeme(), var);
			ident = ident->next.get();
		}
		var = var->next.get();
	}
}

void Procedure::loadSymbols(SymbolTable &st) {
	symbolTable.setParent(&st);
	firstFParam->loadSymbols(symbolTable);
	decls->loadSymbols(symbolTable);
}

void FParam::loadSymbols(SymbolTable &st) {
	FParam *fparam = this;
	while (fparam != nullptr) {
		Ident *ident = fparam->firstIdent.get();
		while (ident != nullptr) {
			st.declare(ident->id->lexeme(), fparam);
			ident = ident->next.get();
		}
		fparam = fparam->next.get();
	}
}

} // namespace frontend



