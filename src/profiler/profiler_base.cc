#include "profiler_base.hh"

namespace profiler {

Profiler * Profiler::_instance = NULL;
Profiler * Profiler::instance() { 
    if (_instance == NULL) {
        _instance = new Profiler();
    }
    return _instance;
}


size_t Profiler::push_code_frame(CodeFrame & tf) {
    code_frames_.push_back(tf);
    return code_frames_.size() - 1;
}

} // namespace profiler