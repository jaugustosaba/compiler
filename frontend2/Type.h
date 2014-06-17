#ifndef TYPE_H_
#define TYPE_H_

namespace frontend {

struct Type {
	virtual ~Type() {
	}
protected:
	Type() = default;
};

} // namespace frontend

#endif /* TYPE_H_ */
