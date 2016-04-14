#include "code_point.hh"


namespace profiler {
    
ostream & operator <<(ostream& os, const CodePoint& cp) {
    os << "tag:    " << cp.tag_ << endl;
    os << "subtag: " << cp.subtag_ << endl;
    os << "hash:   " << cp.hash_ << endl;
    os << "file:   " << cp.file_ << " (" << cp.func_ << ":" << cp.line_ << ")" << endl;
    return os;
}

} // namespace profiler