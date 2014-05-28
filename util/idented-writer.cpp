#include "idented-writer.h"

namespace util {

void IdentedWriter::identIfNeeded() {
    if (m_eol) {
        for (size_t i=0; i<m_tabs; ++i) {
            for (size_t j=0; j<m_tabsize; ++j) {
                m_out << " ";
            }
        }
        m_eol = false;
    }
}

} // namespace util
