

add_library(profilerlib SHARED
    profiler/profiler_base.cc
    profiler/code_frame.cc
    profiler/code_point.cc
    
    profiler/time/time_point.cc
    profiler/counters/performance_counter_base.cc
    profiler/counters/time_counter.cc
)