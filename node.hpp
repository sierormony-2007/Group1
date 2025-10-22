#include<iostream>
#ifndef Node
#define Node
using namespace std;

struct SNode{
    int data;
    SNode* next;
};

struct DNode{
   int value;
   DNode* next;
   DNode* prev;
};


#endif
