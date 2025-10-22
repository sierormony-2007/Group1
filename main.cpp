#include <iostream>
#include <string>
#include "sll.hpp"
#include "dll.hpp"
#include "node.hpp"
#include "csll.hpp"
#include <chrono>
using clk = std::chrono::high_resolution_clock;

using namespace std;

void Csll_observe(Csll_observe* obj, void (Csll_observe::*method)(), string msg){
   auto t0 = clk::now();

    (obj->*method)(); // perform operation

    auto t1 = clk::now();

    auto duration = chrono::duration_cast<chrono::nanoseconds>(t1 - t0);
    cout<<msg <<": "<<duration.count() <<" nanosecond(s)" <<endl;
 }
int main(){
Csll_observe myObj;
 Csll_observe(&myObj, &Csll_observe::method, "Timing method");




    return 0;

}