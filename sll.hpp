
#include <iostream>
#include <string>
#include<chrono>
using namespace std;
struct Node{
int value;
Node* next;
};

class  Sll{
    // proprties = value
    private:        
        Node *head, *cur, *tail, *prev;
        int n;

    public:
    //contructors = method but special

    Sll(){
        head = nullptr;
        tail = nullptr;
        n=0;
        prev = nullptr;
    }
    int size(){
        return n;
    }
    void _traverse(){
        cur = head;
        while(cur->next != nullptr){
            cur = cur->next;
        }
    }
//push/pop front back Head only
    void push_frontH(int val){
        Node* newNode = new Node{val, nullptr};
        newNode->next = head;
        head = newNode;
        n++;
    }
    void pop_frontH(){
        if(n==0){
            cout<<"no node to remove"<<endl;
        }
        Node* tmp = head;
        head = head->next;
        delete tmp;
    }
    void push_backH(int val){
        Node* newNode = new Node{val, nullptr};
        if(n == 0){
            push_frontH(val);
            return;
        }
        _traverse();
        cur->next = newNode;
        n++;
    }
    void pop_backH(){
        if(n==0){
            cout<<"No node to delelte";
        }
        if(n == 1){
            delete head;
            head = nullptr;
            n--;
            return;
        }
        cur = head;
        while(cur->next->next){
            cur = cur->next;
        }
        delete cur->next;
        cur->next = nullptr;
        n--;
    }


    
    
    //push/pop front back Head + tail
    void push_frontHT(int val){
        Node* newNode = new Node{val, nullptr};
        newNode->next = head;
        head = newNode;
        if(tail = nullptr){
            tail = head;
        }
        n++;
    }
    void pop_frontHT(){
        if(n==0){
            cout<<"no node to remove"<<endl;
        }
        Node* tmp = head;
        head = head->next;
        delete tmp;
        n--;
        if(head == nullptr){
            tail = nullptr;
        }

    }
    void push_backHT(int val){
        Node* newNode = new Node{val, nullptr};
        if(tail == nullptr){
            head = tail = newNode;
        }else{
            tail->next = newNode;
            tail = newNode;
        }
        n++;
    }
    void pop_backHT(){
        if(n == 0){
            cout<<"no node to delete"<<endl;
        }
        if(n == 1){
            head = tail = nullptr;
            n--;
            return;
        }
        cur = head;
        while(cur->next != tail){
            cur =cur->next;
        }
        delete tail;
        tail = cur;
        tail->next = nullptr;
        n--;
    }
    


    void insertMiddle(int val, int pos){
        if(pos > n){
            cout<<"Out of node range!\n";
        }
        if(pos == 0){
            insertFront(val);
            return;
        }
        if(pos == n){
            insertEnd(val);
            return;
        }
        cur = head;
        for(int i=0; i<pos - 1; i++)
            cur = cur->next;
        Node *newNode = new Node{val, nullptr};
        cur->next = newNode;
        n++;
    }

    //delete from the middle
    void deleteMiddle(int val, int pos){
        if(pos > n){
            cout<<"Out of node range!\n";
        }
        if(pos == 0){
            deleteFront();
            return;
        }
        if(pos == n){
            deleteEnd();
            return;
        }
        cur = head;
        for(int i=2; i<pos; i++)
            cur = cur->next;
        Node* nodeToDelete = cur->next;
        cur->next = nodeToDelete->next;
        delete nodeToDelete;
    }
    

    void print(){
        cur = head;
        while(cur != nullptr){
        cout << cur->value;
        if(cur->next != nullptr)
            cout << " -> ";
        cur = cur->next;
    }
    cout << endl;
    }
    

};

void sll_observe(Sll* obj, void (Sll::*method)(), string msg){
    using clk = chrono::high_resolution_clock;
    auto t0 = clk::now();

    (obj->*method)(); // perform operation

    auto t1 = clk::now();

    auto duration = chrono::duration_cast<chrono::nanoseconds>(t1 - t0);
    cout<<msg <<": "<<duration.count() <<" nanosecond(s)" <<endl;
    return ;
}
