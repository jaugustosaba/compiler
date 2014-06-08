#ifndef SYMBOL_TABLE_H_
#define SYMBOL_TABLE_H_

#include <string>
#include <unordered_map>
#include <exception>

namespace frontend {

struct Decl;
struct Type;

struct NameError : public std::exception {
	std::string m_message;
public:
	inline NameError(const std::string &message)
		: m_message(message)
	{
	}
	const char* what() const noexcept override;
	~NameError() override;
};

class SymbolTable {
	typedef std::unordered_map<std::string, Decl*> EntryMap;

	EntryMap            m_entries;
	const SymbolTable*  m_parent;
public:
	inline SymbolTable()
		: m_entries(), m_parent(nullptr)
	{
	}
	inline void setParent(const SymbolTable *parent) {
		m_parent = parent;
	}
	void declare(const std::string &name, Decl *decl);
	Decl* lookup(const std::string &name) const;
	const Type* lookupType(const std::string &name) const;
	Decl* lookupValue(const std::string &name) const;
};

} // namespace frontend

#endif /* SYMBOL_TABLE_H_ */
