#ifndef TYPE_H_
#define TYPE_H_

#include <vector>
#include <memory>
#include <unordered_map>
#include <exception>

namespace frontend {

class TypeChecker;

class Type {
	Type(const Type&) = delete;
	Type(Type&&) = delete;
	Type& operator=(const Type&) = delete;
	Type& operator=(Type&&) = delete;
public:
	virtual ~Type() {
	}
protected:
	enum class Id {
		Void,
		Scalar,
		Record,
		Callable,
		Pointer,
		Array
	};
	inline Type(Id id) : m_id(id) {
	}
private:
	friend class TypeChecker;
	Id m_id;
};

class VoidType : public Type {
	friend class TypeChecker;
protected:
	inline VoidType() : Type(Id::Void) {
	}
};

class BooleanType : public Type {
	friend class TypeChecker;
protected:
	inline BooleanType() : Type(Id::Scalar) {
	}
};

class IntegerType : public Type {
	friend class TypeChecker;
protected:
	inline IntegerType() : Type(Id::Scalar) {
	}
};

typedef std::unordered_map<std::string, Type*> FieldTypeMap;

class RecordType : public Type {
	friend class TypeChecker;
protected:
	inline RecordType(FieldTypeMap&& fieldMap)
		: Type(Id::Record), m_fieldMap(fieldMap)
	{
	}
private:
	FieldTypeMap m_fieldMap;
};

typedef std::vector<Type*> ParamTypeVect;

class ProcedureType : public Type {
	friend class TypeChecker;
protected:
	inline ProcedureType(ParamTypeVect&& params)
		: Type(Id::Callable), m_params(params)
	{
	}
private:
	ParamTypeVect m_params;
};

class FunctionType : public ProcedureType {
	friend class TypeChecker;
protected:
	inline FunctionType(ParamTypeVect&& params, Type *returnType)
		: ProcedureType(std::move(params)), m_returnType(returnType)
	{
	}
private:
	Type* m_returnType;
};

class PointerType : public Type {
	friend class TypeChecker;
protected:
	inline PointerType(RecordType* targetType)
		: Type(Id::Pointer), m_targetType(targetType)
	{
	}
private:
	RecordType* m_targetType;
};

class ArrayType : public Type {
	friend class TypeChecker;
protected:
	inline ArrayType(size_t dimension, Type* type)
		: Type(Id::Array), m_dimension(dimension), m_type(type)
	{
	}
private:
	size_t  m_dimension;
	Type*   m_type;
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

class TypeChecker {
	typedef std::unique_ptr<Type> TypePtr;

	static VoidType s_void;
	static IntegerType s_integer;
	static BooleanType s_boolean;

	std::vector<TypePtr> m_types;
public:
	inline TypeChecker() : m_types() {
	}

	VoidType* voidType() const;
	IntegerType* integerType() const;
	BooleanType* booleanType() const;
	RecordType* makeRecordType(FieldTypeMap &&fields);
	ProcedureType* makeProcedureType(ParamTypeVect &&params);
	FunctionType* makeFunctionType(ParamTypeVect &&params, Type* returnType);
	ArrayType* makeArrayType(size_t dimension, Type* type);
	PointerType* makePointerType(Type* targetType);
	Type* checkAdd(const Type *left, const Type *right) const;
	Type* checkSub(const Type *left, const Type *right) const;
	Type* checkMul(const Type *left, const Type *right) const;
	Type* checkRealDiv(const Type *left, const Type *right) const;
	Type* checkDiv(const Type *left, const Type *right) const;
	Type* checkMod(const Type *left, const Type *right) const;
	Type* checkAnd(const Type *left, const Type *right) const;
	Type* checkOr(const Type *left, const Type *right) const;
	Type* checkNot(const Type *left, const Type *right) const;
	Type* checkEQ(const Type *left, const Type *right) const;
	Type* checkNE(const Type *left, const Type *right) const;
	Type* checkLT(const Type *left, const Type *right) const;
	Type* checkLE(const Type *left, const Type *right) const;
	Type* checkGE(const Type *left, const Type *right) const;
	Type* checkGT(const Type *left, const Type *right) const;
	void checkCall(const Type *left, const std::vector<Type*> &params) const;
	Type* checkCallExpr(const Type *left, const std::vector<Type*> &params) const;
	Type* checkDeref(const Type *type) const;
	Type* checkField(const Type *type, const std::string &field) const;
	Type* checkIndex(const Type *type, const Type &indexType) const;
};

} // namespace frontend

#endif /* TYPE_CHECKER_H_ */
