#include <iostream>
using namespace std;


struct Node {
   // 2KB size for each block
   int value;
   struct Node *prev;
   struct Node *next;
};
struct Node* head = nullptr;
struct Node* temp = nullptr;



void AddToMemory(int newSize) {
   struct Node* newnode = (struct Node*) malloc(sizeof(struct Node));
   newnode->value = newSize;
   newnode->prev = nullptr;
   newnode->next = head;
   if(head != nullptr)
   head->prev = newnode ;
   head = newnode;
}


void traverse() {
   struct Node* ptr;
   ptr = head;
   while(ptr != nullptr) {
      cout<< ptr->value <<" ";
      ptr = ptr->next;
   }


}

void createMemory() { //memory indexed from 0-127 for how many blocks that would be 256KB/2KB = 128
    for(int i = 0; i < 128; i++) {
        AddToMemory(0);
    }
    
   cout<<"The doubly linked list is: ";
   traverse();
   cout<< "\n" << head->value << head->next->value << endl;
   //return 0;
}