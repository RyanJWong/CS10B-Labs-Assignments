#include "IntList.h"

/* Initializes an empty list.
*/
IntList::IntList() : head(nullptr) {}

/* Inserts a data value to the front of the list.
*/
void IntList::push_front(int val) {
   if (!head) {
      head = new IntNode(val);
   } 
   else {
      IntNode *temp = new IntNode(val);
      temp->next = head;
      head = temp;
   }
}

void IntList::swapHeadAndTail() {
   // list size 0
   if (head == nullptr) {
      return;
   }
   IntNode *tail = head, *temp,*prev = nullptr;
   // grab tail and second to last

   while (tail->next != nullptr) {
      prev = tail;
      tail = tail->next;
   }
   // list size 1 do nothing
   if (head == tail) {
      return;    
   }
   // list size 2 swap
   else if (head->next == tail) {
      temp = head;
      head = tail;
      head->next = temp;      
      temp->next = nullptr;
   }
   else {
      // otherwise execute
      temp = head;
      head = tail;
      head->next = temp->next;
      prev->next = temp;
      temp->next = nullptr;  
   }
}
