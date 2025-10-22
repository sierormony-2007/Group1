<<<<<<< HEAD

=======
>>>>>>> a659d28932f7081816c75044400926f565baf3bf
#include <iostream>
#include <string>
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
    void pop_frontH(int val){
        Node* newNode = new Node{val, nullptr};
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
        Node* newNode = new Node{val, nullptr};
        cur->next = newNode;
        n++;
    }
    void pop_backH(int val){
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


    
    
    //push/pop front back Head + tail
    void push_frontHT(int val){

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
<<<<<<< HEAD

=======
>>>>>>> a659d28932f7081816c75044400926f565baf3bf
