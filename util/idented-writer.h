#ifndef IDENTED_WRITER_H_
#define IDENTED_WRITER_H_

#include <ostream>
#include <stdexcept>

namespace util {

    class IdentedWriter;

    inline void endl(IdentedWriter &);

    class IdentedWriter {
        std::ostream&  m_out;
        size_t         m_tabsize;
        size_t         m_tabs;
        bool           m_eol;
    public:
        inline
        IdentedWriter(std::ostream &out, size_t tabsize=4)
            : m_out(out),
              m_tabsize(tabsize),
              m_tabs(0),
              m_eol(true)
        {
        }
        inline void increaseIdent() {
            m_tabs++;
        }
        inline void decreaseIdent() {
            m_tabs--;
            if (m_tabs < 0) {
                throw std::logic_error("identation mismatch");
            }
        }
        inline IdentedWriter& operator<<(const char *c) {
            identIfNeeded();
            m_out << c;
            return *this;
        }
        inline IdentedWriter& operator<<(const std::string &s) {
            identIfNeeded();
            m_out << s;
            return *this;
        }
        inline IdentedWriter& operator<<(char c) {
            identIfNeeded();
            m_out << c;
            return *this;
        }
        inline IdentedWriter& operator<<(size_t n) {
            identIfNeeded();
            m_out << n;
            return *this;
        }
        inline IdentedWriter& operator<<(int i) {
            identIfNeeded();
            m_out << i;
            return *this;
        }
        inline IdentedWriter& operator<<(void f(IdentedWriter&)) {
            f(*this);
            return *this;
        }
    private:
        void identIfNeeded();
        inline void newLine() {
            m_out << std::endl;
            m_eol = true;
        }
        friend void endl(IdentedWriter &);
    };

    inline void endl(IdentedWriter &iw) {
        iw.newLine();
    }

} // namespace util

#endif /* IDENTED_WRITER_H_ */
