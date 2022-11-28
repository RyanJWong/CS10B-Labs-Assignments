#include "SortedSet.h"

#include <iostream>
using namespace std;

int main() {
   cout << "Enter a test number(1-5): ";
	int test;
	cin >> test;
	cout << endl;
   //tests constructor, destructor, push_front, pop_front, display
   if (test == 1) {
      cout << endl;
      cout << "list1 constructor called" << endl;
      SortedSet list1;
      cout << "pushfront 10" << endl;
      list1.push_front(10);
      cout << "pushfront 20" << endl;
      list1.push_front(20);
      cout << "pushfront 30" << endl;
      list1.push_front(30);
      cout << "list1: " << list1 << endl;
      cout << "pop" << endl;
      list1.pop_front();
      cout << "list1: " << list1 << endl;
      cout << "pop" << endl;
      list1.pop_front();
      cout << "list1: " << list1 << endl;
      cout << "pop" << endl;
      list1.pop_front();
      cout << "list1: " << list1 << endl;
   }
   if (test == 1) {
      cout << "list1 destructor called" << endl;
   }

   //tests push_back
   if (test == 2) {
      cout << endl;
      cout << "list2 constructor called" << endl;
      SortedSet list2;
      cout << "pushback 10" << endl;
      list2.push_back(10);
      cout << "pushback 20" << endl;
      list2.push_back(20);
      cout << "pushback 30" << endl;
      list2.push_back(30);
      cout << "list2: " << list2 << endl;
      cout << "pop" << endl;
      list2.pop_front();
      cout << "list2: " << list2 << endl;
      cout << "pop" << endl;
      list2.pop_front();
      cout << "list2: " << list2 << endl;
      cout << "pop" << endl;
      list2.pop_front();
      cout << "list2: " << list2 << endl;
   }
   if (test == 2) {
      cout << "list2 destructor called" << endl;
   }

   //tests selection_sort
   if (test == 3) {
      cout << endl;
// -61 -38 -16 45 79 87 120 124 128 129 134 140
      cout << "list3 constructor called" << endl;
      SortedSet list3;
      list3.push_front(120);
      list3.push_front(124);
      list3.push_front(128);
      list3.push_front(-16);
      list3.push_front(134);
      list3.push_front(-61);
            list3.push_front(87);
      list3.push_front(-38);
      list3.push_front(-45);
            list3.push_front(129);
      list3.push_front(79);
      list3.push_front(140);
      
     
      cout << "list3: " << list3 << endl;
    
   }
   if (test == 3) {
      cout << "list3 destructor called" << endl;
   }

   //tests insert_sorted
   if (test == 4) {
      cout << endl;
      cout << "list4 constructor called" << endl;
      SortedSet list4;
      cout << "insert 20" << endl;
      list4.insert_ordered(20);
      cout << "insert 10" << endl;
      list4.insert_ordered(10);
      cout << "insert 30" << endl;
      list4.insert_ordered(30);
      cout << "list4: " << list4 << endl;
      cout << "insert 50" << endl;
      list4.insert_ordered(50);
      cout << "list4: " << list4 << endl;
      cout << "insert 40" << endl;
      list4.insert_ordered(40);
      cout << "list4: " << list4 << endl;
      cout << "insert 11" << endl;
      list4.insert_ordered(11);
      cout << "list4: " << list4 << endl;
      cout << "insert 10" << endl;
      list4.insert_ordered(10);
      cout << "list4: " << list4 << endl;
      cout << "insert 11" << endl;
      list4.insert_ordered(11);
      cout << "list4: " << list4 << endl;
      cout << "insert 9" << endl;
      list4.insert_ordered(9);
      cout << "list4: " << list4 << endl;
      cout << "insert 50" << endl;
      list4.insert_ordered(50);
      cout << "list4: " << list4 << endl;
      cout << "insert 51" << endl;
      list4.insert_ordered(51);
      cout << "list4: " << list4 << endl;
   }
   if (test == 4) {
      cout << "list4 destructor called" << endl;
   }
   
   //tests remove_duplicates
   if (test == 5) {
      cout << endl;
      cout << "list5 constructor called" << endl;
      SortedSet list5;
      cout << "pushfront 146" << endl;
      list5.push_front(146);
      cout << "pushfront 146" << endl;
      list5.push_front(146);
      cout << "pushfront 120" << endl;
      list5.push_front(120);
      cout << "list5: " << list5 << endl;
      cout << "remove_duplicates()" << endl;
      list5.remove_duplicates();
      cout << "list5: " << list5  << " back: " << list5.back()<< endl;
   }
   if (test == 5) {
      cout << "list5 destructor called" << endl;
   }
   if (test == 6) {
      //-52 -5 22 70 88 140 177
      SortedSet list5;
      list5.push_front(-52);
      list5.push_front(-5);
      list5.push_front(22);
      list5.push_front(70);
      list5.push_front(88);
      list5.push_front(140);
      list5.push_front(177);
      SortedSet list6 = list5;
      cout << list6 << endl;
   }
    if (test == 6) {
      cout << "list6 copy constructor called" << endl;
   }
   if (test == 7) {

      SortedSet list7;
      cout << "pushfront 10" << endl;
      list7.push_front(10);
      cout << "pushfront 20" << endl;
      list7.push_front(20);
      cout << "pushfront 10" << endl;
      list7.push_front(10);
      cout << "pushfront 30" << endl;
      list7.push_front(30);
      SortedSet list8;
      SortedSet list9;
      list9 = list7 | list8;
      cout << list9 << endl;
      SortedSet list10;
      list10 = list9 & list7;
      cout << list10 << endl;
   }
    if (test == 7) {
      cout << "list9 = list7 | list8 operator called" << endl;
   }
   /*
   * Destructor will be tested by looking at code. There is no run-time 
   * test for it. Make sure your destructor actually deletes ALL nodes, not
   * just the head and/or tail.
   */
   
   return 0;
}
