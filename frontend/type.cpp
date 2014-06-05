#include "type.h"

namespace frontend {

VoidType TypeChecker::s_void{};

IntegerType TypeChecker::s_integer{};

BooleanType TypeChecker::s_boolean{};

const char* TypeError::what() const noexcept {
	return m_message.data();
}

TypeError::~TypeError() noexcept {
}

VoidType* TypeChecker::voidType() const {
	return &s_void;
}

IntegerType* TypeChecker::integerType() const {
	return &s_integer;
}

BooleanType* TypeChecker::booleanType() const {
	return &s_boolean;
}

RecordType* TypeChecker::makeRecordType(FieldTypeMap &&fields) {
	RecordTypePtr ptr(new RecordType(std::move(fields)));
	auto p = ptr.get();
	m_types.push_back(std::move(ptr));
	return p;
}

ProcedureType* TypeChecker::makeProcedureType(ParamTypeVect &&params) {
	ProcedureTypePtr ptr(new ProcedureType(std::move(params)));
	auto p = ptr.get();
	m_types.push_back(std::move(ptr));
	return p;
}

FunctionType* TypeChecker::makeFunctionType(ParamTypeVect &&params, const Type* returnType) {
	FunctionTypePtr ptr(new FunctionType(std::move(params), returnType));
	auto p = ptr.get();
	m_types.push_back(std::move(ptr));
	return p;
}

ArrayType* TypeChecker::makeArrayType(size_t dimension, const Type* type) {
	ArrayTypePtr ptr(new ArrayType(dimension, type));
	auto p = ptr.get();
	m_types.push_back(std::move(ptr));
	return p;
}

PointerType* TypeChecker::makePointerType(const Type* targetType) {
	auto recordType = dynamic_cast<const RecordType*>(targetType);
	if (recordType == nullptr) {
		mismatch();
	}
	PointerTypePtr ptr(new PointerType(recordType));
	auto p = ptr.get();
	m_types.push_back(std::move(ptr));
	return p;
}

const Type* TypeChecker::checkAdd(const Type *left, const Type *right) const {
	assertSameNumeric(left, right);
	return left;
}

const Type* TypeChecker::checkSub(const Type *left, const Type *right) const {
	assertSameNumeric(left, right);
	return left;
}

const Type* TypeChecker::checkMul(const Type *left, const Type *right) const {
	assertSameNumeric(left, right);
	return left;
}

const Type* TypeChecker::checkRealDiv(const Type *left, const Type *right) const {
	throw std::runtime_error("not implemented");
}

const Type* TypeChecker::checkDiv(const Type *left, const Type *right) const {
	assertBothIntegers(left, right);
	return left;
}

const Type* TypeChecker::checkMod(const Type *left, const Type *right) const {
	assertBothIntegers(left, right);
	return left;
}

const Type* TypeChecker::checkAnd(const Type *left, const Type *right) const {
	assertBothBooleans(left, right);
	return left;
}

const Type* TypeChecker::checkOr(const Type *left, const Type *right) const {
	assertBothBooleans(left, right);
	return left;
}

const Type* TypeChecker::checkNot(const Type *type) const {
	assertBoolean(type);
	return type;
}

const Type* TypeChecker::checkEQ(const Type *left, const Type *right) const {
	assertSameScalar(left, right);
	return &s_boolean;
}

const Type* TypeChecker::checkNE(const Type *left, const Type *right) const {
	assertSameScalar(left, right);
	return &s_boolean;
}

const Type* TypeChecker::checkLT(const Type *left, const Type *right) const {
	assertSameNumeric(left, right);
	return left;
}

const Type* TypeChecker::checkLE(const Type *left, const Type *right) const {
	assertSameNumeric(left, right);
	return left;
}

const Type* TypeChecker::checkGE(const Type *left, const Type *right) const {
	assertSameNumeric(left, right);
	return left;
}

const Type* TypeChecker::checkGT(const Type *left, const Type *right) const {
	assertSameNumeric(left, right);
	return left;
}

void TypeChecker::checkCall(const Type *left, const std::vector<Type*> &params) const {

}

const Type* TypeChecker::checkCallExpr(const Type *left, const std::vector<Type*> &params) const {

}

const Type* TypeChecker::checkDeref(const Type *type) const {
	auto pointer = dynamic_cast<const PointerType*>(type);
	if (pointer == nullptr) {
		mismatch();
	}
	return pointer->m_targetType;
}

const Type* TypeChecker::checkField(const Type *type, const std::string &field) const {
	auto record = dynamic_cast<const RecordType*>(type);
	if (record == nullptr) {
		mismatch();
	}
	auto it = record->m_fieldMap.find(field);
	if (it == record->m_fieldMap.end()) {
		mismatch();
	}
	return it->second;
}

const Type* TypeChecker::checkIndex(const Type *type, const Type *indexType) const {
	assertInteger(indexType);
	auto array = dynamic_cast<const ArrayType*>(type);
	if (array == nullptr) {
		mismatch();
	}
	return array->m_type;
}

void TypeChecker::mismatch() const {
	throw TypeError("type mismatch");
}

} // namespace frontend
