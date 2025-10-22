
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
void Csll_observe::method() {
    if(tail){
  tail->next = head;
    }
    cout << "Method called!" << endl;
}
#endif