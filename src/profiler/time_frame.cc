
#include "time_frame.hh"
#include "profiler_base.hh"


namespace profiler {


TimeFrame::TimeFrame(const profiler::CodePoint &cp) : 
    code_point_(cp),
    index_(profiler::Profiler::instance()->insert_time_frame(*this)) {
    this->start();
}

TimeFrame::~TimeFrame() {
    this->stop();
};

void TimeFrame::start() {
    is_running_ = true;
}

bool TimeFrame::stop(bool forced) {
    is_running_ = false;
    return false;
}

void TimeFrame::pause() {
    
}

void TimeFrame::resume() {
    
}

ostream & operator <<(ostream& os, const TimeFrame& tf) {
    os << "time-frame: " << (!tf.is_running_ ? "not-" : "") << "running, [";
    os << tf.index_ << "] code-point {" << endl;
    os << tf.code_point_;
    os << "}" << endl;
    return os;
}

} // namespace profiler