#include "profiler_base.hh"

namespace profiler {

Profiler * Profiler::_instance = NULL;
Profiler * Profiler::instance() { 
    if (_instance == NULL) {
        _instance = new Profiler();
    }
    return _instance;
}


size_t Profiler::insert_time_frame(TimeFrame & tf) {
    timers_.push_back(tf);
    return timers_.size() - 1;
}

} // namespace profiler