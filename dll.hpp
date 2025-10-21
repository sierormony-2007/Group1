#include<iostream>
#include<string>
using namespace std;
struct DNode{
    int value;
    DNode* next;
    DNode* prev;
};
class Doublylinkedlist{
    private:
       DNode *head, *tail;
       int n;
    public:
    Doublylinkedlist(){
        head = nullptr;
        tail = nullptr;
        n=0;
    }
    void deleteAt(int val){
       DNode* temp = head;
         
    }
};