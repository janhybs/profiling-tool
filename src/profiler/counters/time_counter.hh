#ifndef TIME_COUNTER_HH
#define TIME_COUNTER_HH

#include <iostream>
#include <unordered_map>
#include <string>

#include "performance_counter_base.hh"
#include "../time/time_point.hh"

using namespace std;
namespace profiler {

class TimeCounter : public PerformanceCounterBase {
public:
    TimeCounter();
    
    void on_start();
    void on_stop();
    unordered_map<string, profiler::Number> get_result ();
    
    // no need to override since time is continuous
    inline void on_pause() {};
    inline void on_resume() {};
    
protected:
    
    profiler::TimePoint time_start, time_stop;
    profiler::Number duration;
};

} // namespace profiler
#endif  // TIME_COUNTER_HH