
#include <iostream>
#include <string>
#include "node.hpp"
#ifndef NODE
#define NODE

using namespace std;
class Csll_observe{

    private:
    SNode *head;
    SNode *tail;
    int n;
    public:
    Csll_observe(){
        head = nullptr;
        tail = nullptr;
        n = 0;
        
    }
    void method();

};
// void Csll_observe::method() {//csll
//     if(tail){
//   tail->next = head;
//     }
// }
void Csll_observe::method() { 
    SNode* cur = head;        
    int steps = n;            
    for (int i = 0; i < steps; i++) {
        cur = cur->next;
        if (!cur) cur = head;//i give up bro
    }
    cout << "SLL: " << endl;
}

#endif