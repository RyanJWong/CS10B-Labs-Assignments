#include "IntList.h"

#include <ostream>

using namespace std;

IntList::IntList() : head(nullptr) {}


void IntList::push_front(int val) {
   if (!head) {
      head = new IntNode(val);
   } else {
      IntNode *temp = new IntNode(val);
      temp->next = head;
      head = temp;
   }
}
ostream & operator<<(ostream & out, const IntList & list) {
   if(list.head != nullptr) {
      out << list.head->value;
      if (list.head->next != nullptr) {
         out << " ";
         IntList temp;
         temp.head = list.head->next;
          out << temp;
      }
   }
   return out;
}

   /* Returns true if the integer passed in is contained within the IntList.
      Otherwise returns false.
   */
bool IntList::exists(int num) const {
   if (head == nullptr) {
      return false;
   }
   if (head->value == num) return true;
   IntList temp;
   temp.head = head->next;
   return temp.exists(num);
}
