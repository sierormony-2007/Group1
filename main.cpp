#include <iostream>

#include "sll.hpp"
#include "dll.hpp"

#include "csll.hpp"
#include <chrono>



int main(){
    Dll d;
    dll_observe(&d, &Dll::push_front, "Insert Front Time", 10);
    
}


