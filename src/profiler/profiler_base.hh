#ifndef PROFILER_BASE_HH
#define PROFILER_BASE_HH


#include <vector>
#include <string>
#include <iterator>
#include <iostream>
#include <algorithm>
#include <array>

#include "code_point.hh"
#include "time_frame.hh"

using namespace std;

namespace profiler {

class Profiler {
public:
    
    /**
     * Returns unique Profiler object.
     */
    static Profiler * instance();
    
    size_t insert_time_frame(TimeFrame & tf);
    
protected:
    
    /// Vector of all timers. Whole tree is stored in this array.
    vector<profiler::TimeFrame> timers_;
    
    /// Pointer to the unique instance of singleton Profiler class.
    static Profiler * _instance;
};
    
    
} // namespace profiler
#endif  // PROFILER_BASE_HH