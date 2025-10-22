#include <iostream>
#include <string>
<<<<<<< HEAD
#include <chrono>
#include "sll.hpp"
#include "dll.hpp"
=======
>>>>>>> 1e5a1caabeb6de4a60480ea85044e74d683d8ed1
#include "node.hpp"
#include "csll.hpp"
#include <chrono>

using namespace std;
<<<<<<< HEAD

int main(){
void sll_observe(Sll* obj, void (Sll::*method)(), string msg){
=======
using clk = chrono::high_resolution_clock;

void observe_time(Csll_observe* obj, void (Csll_observe::*method)(), string msg) {
>>>>>>> 1e5a1caabeb6de4a60480ea85044e74d683d8ed1
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
