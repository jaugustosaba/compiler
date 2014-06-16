#ifndef SYMBOLTABLE_H_
#define SYMBOLTABLE_H_

#include <string>
#include <unordered_map>
#include <exception>

#include "Decl.h"

namespace frontend {

class NameError : public std::exception {
	std::string m_message;
public:
	NameError(const std::string &message);
	const char* what() const noexcept override;
	~NameError() noexcept override;
};

class SymbolTable {
	typedef std::unordered_map<std::string, Decl*> EntryMap;

	const SymbolTable* m_parent;
	EntryMap           m_entries;
public:
	inline SymbolTable()
		: m_parent(nullptr), m_entries()
	{
	}
	inline void setParent(const SymbolTable *parent) {
		m_parent = parent;
	}
	void declare(const std::string& name, Decl *decl);
	Decl* lookup(const std::string& name) const;
};

} // namespace frontend

#endif /* SYMBOLTABLE_H_ */
