#include <iostream>

#include "profiler/code_point.hh"
#include "profiler/time_frame.hh"
#include "stdio.h"

using namespace std;


int main() {
	
	START_TIMER("foo");
	
	cout << timer_12 << endl;
}