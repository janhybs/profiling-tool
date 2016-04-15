#ifndef PERFORMANCE_COUNTER_BASE_HH
#define PERFORMANCE_COUNTER_BASE_HH

#include <iostream>
#include <unordered_map>
#include <string>
#include "../time/time_point.hh"

using namespace std;
namespace profiler {


union Number {
    int i;
    long l;
    float f;
    double d;
};

class PerformanceCounterBase {
public:
    inline PerformanceCounterBase() {};
    
    virtual void on_start() = 0;
    
    virtual void on_stop() = 0;
    
    virtual void on_pause() = 0;
    
    virtual void on_resume() = 0;
    
    virtual unordered_map<string, profiler::Number> get_result () = 0;
};


} // namespace profiler
#endif  // PERFORMANCE_COUNTER_BASE_HH