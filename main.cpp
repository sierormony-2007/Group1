#include <iostream>
#include <string>
#include "node.hpp"
#include "csll.hpp"
#include <chrono>

using namespace std;
using clk = chrono::high_resolution_clock;

void observe_time(Csll_observe* obj, void (Csll_observe::*method)(), string msg) {
    auto t0 = clk::now();
    (obj->*method)(); 
    auto t1 = clk::now();

    auto duration = chrono::duration_cast<chrono::nanoseconds>(t1 - t0);
    cout << msg << ": " << duration.count() << " nanosecond(s)" << endl;
}



int main() {
    Csll_observe myObj;
    observe_time(&myObj, &Csll_observe::method, "Timing method");
    return 0;
}
