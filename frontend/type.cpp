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



} // namespace frontend
