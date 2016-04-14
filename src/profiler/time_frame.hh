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
    TimeFrame(const profiler::CodePoint &cp);
    
    ~TimeFrame();
    
    inline bool is_running() {
        return is_running_;
    };
    
    /**
     * Start the timer. If it is already started, just increase number of starts (recursions) and calls.
     */
    void start();

    /**
     * If number of starts (recursions) drop back to zero, we stop the timer and add the period to the cumulative time.
     * This method do not take care of its childs (it has no access to the other timers).
     * When the parameter 2p forced is 'true', we stop the timer immediately regardless the number of recursions.
     * Returns true if the timer is not closed (recursions didn't drop to zero yet).
     */
    bool stop(bool forced = false);
    /**
     * Pauses current timer, save measured petsc memory information util resume.
     * We get Petsc maximum memory usage via PetscMemoryGetMaximumUsage call
     * and save this value into temp value. (we override local maximum if temp
     * value is greater)
     */
    void pause();
    /**
     * Resume current timer. e tell Petsc to monitor the maximum memory 
     * usage once again. We call PetscMemorySetGetMaximumUsage so later in 
     * resume() method will PetscMemoryGetMaximumUsage method work.
     */
    void resume();
    
protected:
    const profiler::CodePoint & code_point_;
    const size_t index_;
    
    bool is_running_;
    
    
    /**
     * define stream << operator
     */
    friend std::ostream & operator <<(std::ostream&, const TimeFrame&);
};

} // namespace profiler
#endif  // TIME_FRAME_HH