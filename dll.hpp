#include<iostream>
#include<string>
#include "node.hpp"
using namespace std;
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
   //erase-given node
    void deleteFront(){
        
      
    }
    void deleteAtPosition(int pos){
        DNode* cur=head;
        if(pos<0||pos>=n){
            cout<<"Out of node range!\n";
            return;
        }
        for(int i=0; i<pos-1; i++){
            cur=cur->next;
        }
        DNode* nodeTodelete=cur->next;
        cur->next=nodeTodelete->next;
        nodeTodelete->next->prev=nodeTodelete->prev;
        delete nodeTodelete;
        n--;
    }
    void deleteTail(){
      
    }
    //push/pop front&back Head + tail
    void push_front(int val){

    }
    void push_back(int val){

    }
    void pop_front(){

    }
    void pop_back(){

    }


};