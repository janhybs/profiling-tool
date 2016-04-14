
#include "time_frame.hh"


namespace profiler {
    
ostream & operator <<(ostream& os, const TimeFrame& tf) {
    os << "time-frame: code-point{" << endl;
    os << tf.code_point_;
    os << "}" << endl;
    return os;
}

} // namespace profiler