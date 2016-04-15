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
    
    /**
     * Triggered when CodeFrame is started. If CodeFrame is already active
     * this method will not be called again.
     */
    virtual void on_start() = 0;
    
    /**
     * Triggered when CodeFrame is stopped If CodeFrame is not active
     * this method will not be called again.
     */
    virtual void on_stop() = 0;
    
    /**
     * Triggered when CodeFrame is paused
     */
    virtual void on_pause() = 0;
    
    /**
     * Triggered when CodeFrame is resumed
     */
    virtual void on_resume() = 0;
    
    /**
     * Method will return map containing measured results
     * Key of the map is measured metric name
     */
    virtual unordered_map<string, profiler::Number> get_result () = 0;
};


} // namespace profiler
#endif  // PERFORMANCE_COUNTER_BASE_HH