#include<iostream>
#include<string>
#include "node.hpp"
using namespace std;
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
    
    //push/pop front&back Head + tail
    void push_front(int val){

    }
    void push_back(int val){

    }
    void pop_front(){
        if(n==0){
            cout<<"empty!!";
            return;
        }
        DNode* head = tail;
        if(head == tail){
            head = tail = nullptr;
        }else {
            head = head->next;
            head->prev = nullptr;
        }
    }
    void pop_back(){
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