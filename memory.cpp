#include <iostream>
using namespace std;


struct Node {
   int data;
   struct Node *prev;
   struct Node *next;
};
struct Node* head = NULL;


void AddToMemory(int newdata) {
   struct Node* newnode = (struct Node*) malloc(sizeof(struct Node));
   newnode->data = newdata;
   newnode->prev = NULL;
   newnode->next = head;
   if(head != NULL)
   head->prev = newnode ;
   head = newnode;
}


void traverse() {
   struct Node* ptr;
   ptr = head;
   while(ptr != NULL) {
      cout<< ptr->data <<" ";
      ptr = ptr->next;
   }


}

int main() {
    for(int i = 0; i < 256; i++) {
        AddToMemory(2);
    }
    
   cout<<"The doubly linked list is: ";
   traverse();
   return 0;
}