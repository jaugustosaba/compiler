#ifndef POSITION_H_
#define POSITION_H_

#include <istream>

namespace frontend {

class Position {
public:
	typedef std::istream::off_type Offset;
	typedef size_t UInt;

	inline
	Position()
		: m_line(1), m_column(1), m_offset(0)
	{
	}
	inline
	Position(UInt line, UInt column, Offset offset)
		: m_line(line), m_column(column), m_offset(offset)
	{
	}
	inline UInt line() const {
		return m_line;
	}
	inline UInt column() const {
		return m_column;
	}
	inline Offset offset() const {
		return m_offset;
	}
private:
	UInt    m_line;
	UInt    m_column;
	Offset  m_offset;
};

} // namespace frontend

#endif /* POSITION_H_ */
