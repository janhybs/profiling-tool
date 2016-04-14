#ifndef TIME_FRAME_HH
#define TIME_FRAME_HH


#include <vector>
#include <string>
#include <iterator>
#include <iostream>
#include <algorithm>
#include <array>

#include "code_point.hh"

using namespace std;

namespace profiler {


// These helper macros are necessary due to use of _LINE_ variable in START_TIMER macro.
#define _PASTE(a,b) a ## b
#define PASTE(a,b) _PASTE(a, b)

// #define START_TIMER(tag) static constexpr profiler::CodePoint PASTE(cp_,__LINE__) = CODE_POINT(tag); profiler::TimeFrame PASTE(timer_,__LINE__) = profiler::TimeFrame(PASTE(cp_,__LINE__));

#define START_TIMER_(tag) profiler::TimeFrame(CODE_POINT(tag));
#define START_TIMER(tag) static profiler::TimeFrame PASTE(timer_,__LINE__) = START_TIMER_(tag);


class TimeFrame {
public:
    TimeFrame(const profiler::CodePoint &cp) : code_point_(cp) {};
    ~TimeFrame() {};
    
protected:
    const profiler::CodePoint & code_point_;
    int foo;
    
    /**
     * define stream << operator
     */
    friend std::ostream & operator <<(std::ostream&, const TimeFrame&);
};

} // namespace profiler

#endif  // TIME_FRAME_HH