#include "SymbolTable.h"

namespace frontend {

NameError::NameError(const std::string &message)
	: m_message(message)
{
}

const char* NameError::what() const noexcept {
	return m_message.c_str();
}

NameError::~NameError() noexcept {
}

void SymbolTable::declare(const std::string& name, Decl *decl) {
	auto it = m_entries.find(name);
	if (it != m_entries.end()) {
		throw NameError("name redeclaration");
	}
	m_entries[name] = decl;
}

Decl* SymbolTable::lookup(const std::string& name) const {
	auto it = m_entries.find(name);
	if (it == m_entries.end()) {
		if (m_parent == nullptr) {
			throw NameError("symbol not found");
		}
		return m_parent->lookup(name);
	}
	return it->second;
}

} // namespace frontend



