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
    double duration_ = (time_stop - time_start);
    duration = { d:duration_ };
    cout << "stopping " << duration_ << endl;
};

unordered_map<string, profiler::Number> TimeCounter::get_result () {
    unordered_map<string, profiler::Number> result;
    result["duration"] = duration;
    return result;
};

} // namespace profiler