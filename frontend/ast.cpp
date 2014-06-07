#include "ast.h"

namespace frontend {

const Type Type::BOOLEAN;
const Type Type::INTEGER;

void RecordDescriptor::loadType(SymbolTable &st) {
	auto field = firstField.get();
	auto &fieldTypes = type.fieldTypes;
	while (field != nullptr) {
		auto type = st.lookupType(field->typeName->lexeme());
		auto ident = field->firstIdent.get();
		while (ident != nullptr) {
			auto &id = ident->id->lexeme();
			auto it = fieldTypes.find(id);
			if (it != fieldTypes.end()) {
				throw NameError("field redeclaration");
			}
			fieldTypes[id] = type;
			ident = ident->next.get();
		}
		field = field->next.get();
	}
}

const Type* RecordDescriptor::effectiveType() const {
	return &type;
}

void ArrayDescriptor::loadType(SymbolTable &st) {

}

const Type* ArrayDescriptor::effectiveType() const {
	return &type;
}

void PointerDescriptor::loadType(SymbolTable &st) {
	auto targetType = st.lookupType(typeName->lexeme());
	auto recordType = dynamic_cast<const RecordType*>(targetType);
	if (recordType == nullptr) {
		throw NameError("not a record");
	}
	type.targetType = recordType;
}

const Type* PointerDescriptor::effectiveType() const {
	return &type;
}

const Type* BuiltinTypeDecl::effectiveType() const {
	return type;
}

const Type* VarDecl::effectiveType() const {
	return type;
}

const Type* ConstDecl::effectiveType() const {
	return type;
}

const Type* Procedure::effectiveType() const {
	return &type;
}

const Type* Function::effectiveType() const {
	return &type;
}

void Module::loadSymbols(const SymbolTable* builtins) {
	symbolTable.setParent(builtins);
	decls->loadSymbols(symbolTable);
}

void Module::loadTypes() {
	decls->loadTypes(symbolTable);
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

void Declarations::loadTypes(SymbolTable &st) {
	firstType->loadTypes(st);
	firstProcedure->loadTypes();
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

void UserTypeDecl::loadTypes(SymbolTable &st) {
	UserTypeDecl *userType = this;
	while (userType) {
		userType->descriptor->loadType(st);
		userType = userType->next.get();
	}
}

const Type* UserTypeDecl::effectiveType() const {
	return descriptor->effectiveType();
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

void BaseProcedure::loadSymbols(SymbolTable &st) {
	symbolTable.setParent(&st);
	firstFParam->loadSymbols(symbolTable);
	decls->loadSymbols(symbolTable);
}

void BaseProcedure::loadTypes() {
	decls->loadTypes(symbolTable);
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

const Type* FParam::effectiveType() const {
	return type;
}

} // namespace frontend



