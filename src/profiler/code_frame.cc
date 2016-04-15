
#include "code_frame.hh"
#include "profiler_base.hh"
#include "counters/time_counter.hh"


namespace profiler {


CodeFrame::CodeFrame(const profiler::CodePoint &cp) : code_point_(cp), index_(profiler::Profiler::instance()->push_code_frame(*this)) {
    counters.push_back(make_shared<profiler::TimeCounter>());
    counters.push_back(make_shared<profiler::TimeCounter>());
    this->start();
}

CodeFrame::~CodeFrame() {
    this->stop();
};

void CodeFrame::start() {
    if (is_running_) return;
    
    is_running_ = true;
    for(auto &counter : counters) {
        counter->on_start();
    }
}

bool CodeFrame::stop(bool forced) {
    if (!is_running_) return false;
    
    is_running_ = false;
    for(auto &counter : counters) {
        counter->on_stop();
        cout << counter->get_result()["duration"].d << endl;
    }
    return false;
}

void CodeFrame::pause() {
    
}

void CodeFrame::resume() {
    
}

ostream & operator <<(ostream& os, const CodeFrame& cf) {
    os << "code-frame: " << (!cf.is_running_ ? "not-" : "") << "running, [";
    os << cf.index_ << "] code-point {" << endl;
    os << cf.code_point_;
    os << "}" << endl;
    return os;
}

} // namespace profiler