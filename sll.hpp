
#include <iostream>
#include <string>
using namespace std;
struct Node{
int value;
Node* next;
Node* prev;
};

class  Sll{
    // proprties = value
    private:        
        Node *head, *cur, *tail;
        int n;

    public:
    //contructors = method but special

    Sll(){
        head = nullptr;
        n=0;
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
//insert at the front
    void push_front(int val){
        Node* newNode = new Node{val, nullptr};
        newNode->next = head;
        head = newNode;
        n++;
    }
    void pop_front(int val){
        Node* newNode = new Node{val, nullptr};
        if(n==0){
            cout<<"no node to remove"<<endl;
        }
        Node* tmp = head;
        head = head->next;
        delete tmp;
    }
    void push_back(int val){
        Node* newNode = new Node{val, nullptr};
        if(n == 0){
            push_front(val);
            return;
        }
        _traverse();
        Node* newNode = new Node{val, nullptr};
        cur->next = newNode;
        n++;
    }
    void pop_back(int val){
        if(n==0){
            cout<<"No node to delelte";
        }
        cur = head;
        while(cur->next->next){
            cur = cur->next;
        }
        delete cur->next;
        cur->next = nullptr;
        n--;
    }


    
    
    //insert at the middle or a specific position
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

void sll_obs(){

}