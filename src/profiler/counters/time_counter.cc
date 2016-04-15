#include <iostream>

#include "time_counter.hh"
#include <unordered_map>
#include <string>

using namespace std;
namespace profiler {

TimeCounter::TimeCounter () {
    
}

void TimeCounter::on_start() {
    time_start = profiler::TimePoint();
};

void TimeCounter::on_stop() {
    time_stop = profiler::TimePoint();
    duration = { d:(time_stop - time_start) }; // fill up the mebmber 'd' as double
    cout << "stopping " << (time_stop - time_start) << endl;
};

unordered_map<string, profiler::Number> TimeCounter::get_result () {
    unordered_map<string, profiler::Number> result;
    result["duration"] = duration;
    return result;
};

} // namespace profiler