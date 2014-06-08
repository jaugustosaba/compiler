#include "ast.h"

namespace frontend {

const Type Type::BOOLEAN;
const Type Type::INTEGER;

const char* TypeError::what() const noexcept {
	return m_message.data();
}

TypeError::~TypeError() noexcept {
}

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

void Module::typeCheck() {
	decls->typeCheck(symbolTable);
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
	if (firstProcedure) {
		firstProcedure->loadSymbols(st);
	}
}

void Declarations::loadTypes(SymbolTable &st) {
	if (firstType) {
		firstType->loadTypes(st);
	}
	if (firstProcedure) {
		firstProcedure->loadTypes();
	}
}

void Declarations::typeCheck(SymbolTable &st) {
	if (firstConstant) {
		firstConstant->typeCheck(st);
	}
	if (firstProcedure) {
		firstProcedure->typeCheck();
	}
}

void IntExpr::typeCheck(SymbolTable &st) {
	type = &Type::INTEGER;
}

void BinExpr::typeCheck(SymbolTable &st) {
	left->typeCheck(st);
	right->typeCheck(st);
	if (left->type != right->type) {
		throw TypeError("binary exprs require same type");
	}
	switch (op) {
	case BinOp::EQ:
	case BinOp::NE:
		type = &Type::BOOLEAN;
		break;
	case BinOp::LT:
	case BinOp::LE:
	case BinOp::GT:
	case BinOp::GE:
		if (left->type != &Type::INTEGER) {
			throw TypeError("expecting integer on boolean comparation");
		}
		type = &Type::BOOLEAN;
		break;
	case BinOp::Add:
	case BinOp::Sub:
	case BinOp::Mul:
	case BinOp::RealDiv:
	case BinOp::Div:
	case BinOp::Mod:
		if (left->type != &Type::INTEGER) {
			throw TypeError("expecting integer on arithmetic expression");
		}
		type = &Type::INTEGER;
		break;
		break;
	case BinOp::And:
	case BinOp::Or:
		if (left->type != &Type::BOOLEAN) {
			throw TypeError("expecting boolean on logical expression");
		}
		type = &Type::BOOLEAN;
		break;
	}
}

void UnExpr::typeCheck(SymbolTable &st) {
	expr->typeCheck(st);
	switch (op) {
	case UnOp::Not:
		if (expr->type != &Type::BOOLEAN) {
			throw TypeError("expecting boolean on logical expression");
		}
		type = &Type::BOOLEAN;
		break;
	}
}

void IdExpr::typeCheck(SymbolTable &st) {
	decl = st.lookupValue(id->lexeme());
	type = decl->effectiveType();
}

void FieldExpr::typeCheck(SymbolTable &st) {
	expr->typeCheck(st);
	auto rectype = dynamic_cast<const RecordType*>(expr->type);
	if (rectype == nullptr) {
		throw TypeError("not a field type");
	}
	auto it = rectype->fieldTypes.find(field->lexeme());
	if (it == rectype->fieldTypes.end()) {
		throw TypeError("field not found");
	}
	type = it->second;
}

void ExprList::typeCheck(SymbolTable &st) {
	expr->typeCheck(st);
	if (tail) {
		tail->typeCheck(st);
	}
}

void CallExpr::typeCheck(SymbolTable &st) {
	lvalue->typeCheck(st);
	auto functype = dynamic_cast<const FunctionType*>(lvalue->type);
	if (functype == nullptr) {
		throw TypeError("not a function type");
	}
	firstExpr->typeCheck(st);
	std::vector<Expr*> aparams;
	for (ExprList *el=firstExpr.get(); el != nullptr; el=el->tail.get()) {
		aparams.push_back(el->expr.get());
	}
	if (aparams.size() != functype->params.size()) {
		throw TypeError("wrong argument number");
	}
	for (size_t i=0; i<aparams.size(); ++i) {
		auto expr = aparams[i];
		auto &fptype = functype->params[i];
		if (expr->type != fptype.type) {
			throw TypeError("wrong argument type");
		}
		if (fptype.isVar) {
			auto idExpr = dynamic_cast<IdExpr*>(expr);
			if (idExpr) {
				throw TypeError("not a lvalue");
			}
		}
	}
}

void DerefExpr::typeCheck(SymbolTable &st) {
	lvalue->typeCheck(st);
	auto ptype = dynamic_cast<const PointerType*>(lvalue->type);
	if (ptype == nullptr) {
		throw TypeError("not a pointer type");
	}
	type = ptype->targetType;
}

void IndexExpr::typeCheck(SymbolTable &st) {

}

void Elseif::typeCheck(SymbolTable &st) {
	expr->typeCheck(st);
	if (expr->type != &Type::BOOLEAN) {
		throw TypeError("expecting boolean condition on elseif");
	}
	if (firstStmt) {
		firstStmt->typeCheck(st);
	}
}

void IfStmt::typeCheck(SymbolTable &st) {
	expr->typeCheck(st);
	if (expr->type != &Type::BOOLEAN) {
		throw TypeError("expecting boolean condition on if");
	}
	if (firstStmt) {
		firstStmt->typeCheck(st);
	}
	if (firstElseif) {
		firstElseif->typeCheck(st);
	}
	if (firstElseStmt) {
		firstElseStmt->typeCheck(st);
	}
	if (next) {
		next->typeCheck(st);
	}
}

void WhileStmt::typeCheck(SymbolTable &st) {
	expr->typeCheck(st);
	if (expr->type != &Type::BOOLEAN) {
		throw TypeError("expecting boolean condition on while");
	}
	if (firstStmt) {
		firstStmt->typeCheck(st);
	}
	if (next) {
		next->typeCheck(st);
	}
}

void CallStmt::typeCheck(SymbolTable &st) {
	expr->typeCheck(st);
	if (next) {
		next->typeCheck(st);
	}
}

void AssignStmt::typeCheck(SymbolTable &st) {
	lvalue->typeCheck(st);
	rvalue->typeCheck(st);
	if (next) {
		next->typeCheck(st);
	}
}

void ConstDecl::loadSymbols(SymbolTable &st) {
	ConstDecl *constt = this;
	while (constt != nullptr) {
		st.declare(constt->id->lexeme(), constt);
		constt = constt->next.get();
	}
}

void ConstDecl::typeCheck(SymbolTable &st) {
	expr->typeCheck(st);
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
	if (firstFParam) {
		firstFParam->loadSymbols(symbolTable);
	}
	decls->loadSymbols(symbolTable);
	if (next) {
		next->loadSymbols(st);
	}
}

void BaseProcedure::loadTypes() {
	if (firstFParam) {
		firstFParam->loadTypes(symbolTable);
	}
	decls->loadTypes(symbolTable);
	if (next) {
		next->loadTypes();
	}
}

void BaseProcedure::typeCheck() {
	decls->typeCheck(symbolTable);
	if (firstStmt) {
		firstStmt->typeCheck(symbolTable);
	}
	if (next) {
		next->typeCheck();
	}
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

void FParam::loadTypes(SymbolTable &st) {
	FParam *fparam = this;
	while (fparam != nullptr) {
		fparam->type = st.lookupType(fparam->typeName->lexeme());
		fparam = fparam->next.get();
	}
}

const Type* FParam::effectiveType() const {
	return type;
}

} // namespace frontend



