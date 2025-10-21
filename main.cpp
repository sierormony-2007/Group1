#include <iostream>
#include <string>
#include "sll.hpp"
#include "dll.hpp"
#include "node.hpp"
#include "csll.hpp"
using namespace std;
int main(){

void sll_observe(Sll* obj, void (Sll::*method)(), string msg){
    auto t0 = clk::now();

    (obj->*method)(); // perform operation

    auto t1 = clk::now();

    auto duration = chrono::duration_cast<chrono::nanoseconds>(t1 - t0);
    cout<<msg <<": "<<duration.count() <<" nanosecond(s)" <<endl;
    return 0;
}

}