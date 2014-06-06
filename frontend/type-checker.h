#ifndef TYPE_CHECKER_H_
#define TYPE_CHECKER_H_

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

typedef std::unordered_map<std::string, const Type*> FieldTypeMap;

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
	inline FunctionType(ParamTypeVect&& params, const Type *returnType)
		: ProcedureType(std::move(params)), m_returnType(returnType)
	{
	}
private:
	const Type* m_returnType;
};

class PointerType : public Type {
	friend class TypeChecker;
protected:
	inline PointerType(const RecordType* targetType)
		: Type(Id::Pointer), m_targetType(targetType)
	{
	}
private:
	const RecordType* m_targetType;
};

class ArrayType : public Type {
	friend class TypeChecker;
protected:
	inline ArrayType(size_t dimension, const Type* type)
		: Type(Id::Array), m_dimension(dimension), m_type(type)
	{
	}
private:
	size_t        m_dimension;
	const Type*   m_type;
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
	typedef std::unique_ptr<RecordType> RecordTypePtr;
	typedef std::unique_ptr<ProcedureType> ProcedureTypePtr;
	typedef std::unique_ptr<FunctionType> FunctionTypePtr;
	typedef std::unique_ptr<ArrayType> ArrayTypePtr;
	typedef std::unique_ptr<PointerType> PointerTypePtr;

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
	FunctionType* makeFunctionType(ParamTypeVect &&params, const Type* returnType);
	ArrayType* makeArrayType(size_t dimension, const Type* type);
	PointerType* makePointerType(const Type* targetType);
	const Type* checkAdd(const Type *left, const Type *right) const;
	const Type* checkSub(const Type *left, const Type *right) const;
	const Type* checkMul(const Type *left, const Type *right) const;
	const Type* checkRealDiv(const Type *left, const Type *right) const;
	const Type* checkDiv(const Type *left, const Type *right) const;
	const Type* checkMod(const Type *left, const Type *right) const;
	const Type* checkAnd(const Type *left, const Type *right) const;
	const Type* checkOr(const Type *left, const Type *right) const;
	const Type* checkNot(const Type *type) const;
	const Type* checkEQ(const Type *left, const Type *right) const;
	const Type* checkNE(const Type *left, const Type *right) const;
	const Type* checkLT(const Type *left, const Type *right) const;
	const Type* checkLE(const Type *left, const Type *right) const;
	const Type* checkGE(const Type *left, const Type *right) const;
	const Type* checkGT(const Type *left, const Type *right) const;
	void checkCall(const Type *left, const std::vector<Type*> &params) const;
	const Type* checkCallExpr(const Type *left, const std::vector<Type*> &params) const;
	const Type* checkDeref(const Type *type) const;
	const Type* checkField(const Type *type, const std::string &field) const;
	const Type* checkIndex(const Type *type, const Type *indexType) const;
	void checkAssign(const Type *dest, const Type *value) const;

private:
	void mismatch() const;
	inline void assertSameScalar(const Type *left, const Type *right) const {
		if ((left->m_id != Type::Id::Scalar) && (left != right)) {
			mismatch();
		}
	}
	inline bool isBoolean(const Type *type) const {
		return type == &s_boolean;
	}
	inline bool isInteger(const Type *type) const {
		return type == &s_integer;
	}
	inline bool isNumeric(const Type *type) const {
		return isInteger(type);
	}
	inline void assertSameNumeric(const Type *left, const Type *right) const {
		assertSameScalar(left, right);
		if (!isNumeric(left)) {
			mismatch();
		}
	}
	inline void assertBothIntegers(const Type *left, const Type *right) const {
		assertSameScalar(left, right);
		if (!isInteger(left)) {
			mismatch();
		}
	}
	inline void assertBoolean(const Type *type) const {
		if (!isBoolean(type)) {
			mismatch();
		}
	}
	inline void assertInteger(const Type *type) const {
		if (!isInteger(type)) {
			mismatch();
		}
	}
	inline void assertBothBooleans(const Type *left, const Type *right) const {
		assertSameScalar(left, right);
		if (!isBoolean(left)) {
			mismatch();
		}
	}
	void checkCallAux(const ProcedureType *proctype, const std::vector<Type*> &params) const;
};

} // namespace frontend

#endif /* TYPE_CHECKER_H_ */
