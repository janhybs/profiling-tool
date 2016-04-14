#include <iostream>

#include "profiler/profiler_base.hh"

using namespace std;


int main() {
	
	START_TIMER("foo");
	START_TIMER("foo");
	START_TIMER("foo");
	
	cout << timer_12 << endl;
}