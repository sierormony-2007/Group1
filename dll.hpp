#include<iostream>
#include<string>
#include<chrono>
#include "node.hpp"
using namespace std;
class Dll{
    private:
       DNode *head, *tail, *prev, *cur;
       int n;
    public:
    Dll(){
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
        DNode* newNode = new DNode{val,nullptr};
        if(head == nullptr){
            head= newNode;
            tail= newNode;
        }else{
        newNode->next = head;
        head->prev = newNode;
        head = newNode;}


        
    }
    void push_back(int val){
        if(n==0){
            push_front(val);
        }
        DNode* newNode = new DNode{val,nullptr};
        if(head == nullptr){
            head= newNode;
            tail= newNode;
        }else{
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
        }
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
// void dll_observe(Dll* obj, void (Dll::*method)(), string msg){
//     using clk = chrono::high_resolution_clock;
//     auto t0 = clk::now();

//     (obj->*method)(); // perform operation

//     auto t1 = clk::now();

//     auto duration = chrono::duration_cast<chrono::nanoseconds>(t1 - t0);
//     cout<<msg <<": "<<duration.count() <<" nanosecond(s)" <<endl;
//     return ;
// }
template <typename T, typename Method, typename... Args>
void dll_observe(T* obj, Method method, string msg, Args&&... args) {
    auto t0 = chrono::high_resolution_clock::now();

    (obj->*method)(std::forward<Args>(args)...); // call the method with parameters

    auto t1 = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::nanoseconds>(t1 - t0);
    cout << msg << ": " << duration.count() << " nanosecond(s)" << endl;
}