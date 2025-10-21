#include <iostream>
#include <string>
using namespace std;
struct Node{
int value;
Node* next;
};

class  LinkedList{
    // proprties = value
    private:        
        Node *head, *cur;
        int n;

    public:
    //contructors = method but special

    LinkedList(){
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
    void insertFront(int val){
        Node* newNode = new Node{val, nullptr};
        newNode->next = head;
        head = newNode;
        n++;
    }

    //insert at the end
    void insertEnd(int val){
        if(n == 0){
            insertFront(val);
            return;
        }
        _traverse();
        Node* newNode = new Node{val, nullptr};
        cur->next = newNode;
        n++;
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
    // delete at the front
    void deleteFront(){
        if(n==0){
            cout<<"No node to delelte";
        }
        Node* tmp = head;
        head = head->next;
        delete tmp;
        n--;
    }
    //delete at the end
    void deleteEnd(){
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
// swaping two nodes 
void swap(){
    Node *newNode = new Node();
    newNode->next = head;


    while(newNode->next != nullptr && newNode->next->next != nullptr){
        Node *swap1 = newNode->next;
        Node *swap2 = newNode->next->next;

        swap1->next = swap2->next;
        swap2->next = swap1;

        newNode->next = swap2;
        newNode = swap1;
    }
    
}

//search in linkedList
    bool search(int value) {
        Node* cur = head;
        while(cur != nullptr) {
            if(cur->value == value) {
                return true;
            }
            cur = cur->next;
        }
        return false;
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