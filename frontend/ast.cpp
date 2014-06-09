#include "ast.h"

namespace frontend {

namespace {

void typeCheckFParams(const ProcedureType *proctype, const ExprList *firstExpr) {
	std::vector<const Expr*> aparams;
	for (auto e=firstExpr; e != nullptr; e=e->tail.get()) {
		aparams.push_back(e->expr.get());
	}
	if (aparams.size() != proctype->params.size()) {
		throw TypeError("wrong argument number");
	}
	for (size_t i=0; i<aparams.size(); ++i) {
		auto expr = aparams[i];
		auto &fptype = proctype->params[i];
		if (expr->type != fptype.type) {
			throw TypeError("wrong argument type");
		}
		if (fptype.isVar) {
			auto idexpr = dynamic_cast<const IdExpr*>(expr);
			if (idexpr == nullptr) {
				throw TypeError("not a lvalue");
			}
			if (!idexpr->designator->isUpdatable()) {
				throw TypeError("cannot update a constant value");
			}
		}
	}
}

void loadFParamTypes(ProcedureType *proctype, FParam *firstFParam) {
	for (auto fparam=firstFParam; fparam != nullptr; fparam=fparam->next.get()) {
		for (auto ident=fparam->firstIdent.get(); ident != nullptr; ident=ident->next.get()) {
			FParamType fparamtype{fparam->type, fparam->isVar};
			proctype->params.push_back(fparamtype);
		}
	}
}

} // anonymous namespace

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

void Procedure::loadTypes(SymbolTable &st) {
	BaseProcedure::loadTypes(st);
	loadFParamTypes(&type, firstFParam.get());
}

const Type* Procedure::effectiveType() const {
	return &type;
}

void Function::loadTypes(SymbolTable &st) {
	BaseProcedure::loadTypes(st);
	loadFParamTypes(&type, firstFParam.get());
	type.returnType = st.lookupType(resultType->lexeme());
}

const Type* Function::effectiveType() const {
	return &type;
}

void Module::loadSymbols(const SymbolTable* builtins) {
	symbolTable.setParent(builtins);
	decls->loadSymbols(symbolTable);
	if (id0->lexeme() != id1->lexeme()) {
		throw TypeError("module names do not match");
	}
}

void Module::loadTypes() {
	decls->loadTypes(symbolTable);
}

void Module::typeCheck() {
	decls->typeCheck(symbolTable);
	if (firstStmt) {
		firstStmt->typeCheck(symbolTable);
	}
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
	if (firstVariable) {
		firstVariable->loadTypes(st);
	}
	if (firstProcedure) {
		firstProcedure->loadTypes(st);
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

void BoolExpr::typeCheck(SymbolTable &st) {
	type = &Type::BOOLEAN;
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

bool Designator::isUpdatable() const {
	return true;
}

void IdDesig::typeCheck(SymbolTable &st) {
	decl = st.lookupValue(id->lexeme());
	type = decl->effectiveType();
}

bool IdDesig::isUpdatable() const {
	if (dynamic_cast<VarDecl*>(decl) != nullptr) {
		return true;
	}
	if (dynamic_cast<FParam*>(decl) != nullptr) {
		return true;
	}
	return false;
}

void FieldDesig::typeCheck(SymbolTable &st) {
	designator->typeCheck(st);
	auto rectype = dynamic_cast<const RecordType*>(designator->type);
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

void IdExpr::typeCheck(SymbolTable &st) {
	designator->typeCheck(st);
	auto proctype = dynamic_cast<const ProcedureType*>(designator->type);
	if (proctype == nullptr) {
		type = designator->type;
	} else {
		auto functype = dynamic_cast<const FunctionType*>(proctype);
		if (functype == nullptr) {
			throw TypeError("not a function type");
		}
		typeCheckFParams(functype, firstExpr.get());
		type = functype->returnType;
	}
}

void DerefDesig::typeCheck(SymbolTable &st) {
	designator->typeCheck(st);
	auto ptype = dynamic_cast<const PointerType*>(designator->type);
	if (ptype == nullptr) {
		throw TypeError("not a pointer type");
	}
	type = ptype->targetType;
}

void IndexDesig::typeCheck(SymbolTable &st) {

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
	designator->typeCheck(st);
	auto proctype = dynamic_cast<const ProcedureType*>(designator->type);
	if (proctype == nullptr) {
		throw TypeError("not a procedure type");
	}
	aparams->typeCheck(st);
	typeCheckFParams(proctype, aparams.get());
	if (next) {
		next->typeCheck(st);
	}
}

void AssignStmt::typeCheck(SymbolTable &st) {
	designator->typeCheck(st);
	if (!designator->isUpdatable()) {
		throw TypeError("cannot assign to non-updatable");
	}
	expr->typeCheck(st);
	if (designator->type != expr->type) {
		throw TypeError("cannot assign to diferent types");
	}
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

void VarDecl::loadTypes(SymbolTable &st) {
	type = st.lookupType(typeName->lexeme());
	if (next) {
		next->loadTypes(st);
	}
}

void BaseProcedure::loadSymbols(SymbolTable &st) {
	symbolTable.setParent(&st);
	if (firstFParam) {
		firstFParam->loadSymbols(symbolTable);
	}
	decls->loadSymbols(symbolTable);
	if (id0->lexeme() != id1->lexeme()) {
		throw TypeError("procedure idents do not match");
	}
	st.declare(id0->lexeme(), this);
	if (next) {
		next->loadSymbols(st);
	}
}

void BaseProcedure::loadTypes(SymbolTable &st) {
	if (firstFParam) {
		firstFParam->loadTypes(symbolTable);
	}
	decls->loadTypes(symbolTable);
	if (next) {
		next->loadTypes(st);
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



