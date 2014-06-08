#include "ast.h"

namespace frontend {

const char* NameError::what() const noexcept {
	return m_message.c_str();
}

NameError::~NameError() {
}

void SymbolTable::declare(const std::string &name, Decl *decl) {
	auto it = m_entries.find(name);
	if (it != m_entries.end()) {
		throw NameError("symbol redeclaration");
	}
	m_entries[name] = decl;
}

Decl* SymbolTable::lookup(const std::string &name) const {
	auto it = m_entries.find(name);
	if (it != m_entries.end()) {
		return it->second;
	}
	if (m_parent != nullptr) {
		return m_parent->lookup(name);
	}
	throw NameError("symbol not found");
}

const Type* SymbolTable::lookupType(const std::string &name) const {
	auto decl = lookup(name);
	auto type = dynamic_cast<const TypeDecl*>(decl);
	if (type == nullptr) {
		throw NameError("not a type");
	}
	return type->effectiveType();
}

Decl* SymbolTable::lookupValue(const std::string &name) const {
	auto decl = lookup(name);
	auto type = dynamic_cast<const TypeDecl*>(decl);
	if (type != nullptr) {
		throw NameError("not a value");
	}
	return decl;
}

} // namespace frontend
