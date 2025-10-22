#include<iostream>
#include<string>
using namespace std;
#include "node.hpp"
class Doublylinkedlist{
    private:
       DNode *head, *tail, *prev;
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
    void deleteAtPosition(){
      
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
    
void deleteFront(){
        if(n==0){
            cout<<"empty!!";
            return;
        }
        Node* head = tail;
        if(head == tail){
            head = tail = nullptr;
        }else {
            head = head->next;
            head->prev = nullptr;
        }
    }
    void deleteEnd(){
        if(n==0){
            cout<<"empty!!";
            return;
        }
        if(head == tail){
            head = tail = nullptr;
        }
        else {
            tail = tail-> prev;
            tail->next = nullptr;
        }
    }


};