#include "symbol-table.h"

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

} // namespace frontend