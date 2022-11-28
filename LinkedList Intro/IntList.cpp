#include "IntList.h"
#include <iostream>
using namespace std;

IntList::IntList() {
    head = nullptr;
    tail = nullptr;
}
IntList::~IntList() {
    if (head!= nullptr) {
        if (head->next != nullptr) {
            IntNode* curr = head->next;
            IntNode* temp = head;
            //edge case if list is size one
            while (curr->next != nullptr) {
                curr = curr->next;
                delete temp;
                temp = curr;
            }
        }
        // list size of one 
        else {
            delete head;
        }
        head = nullptr;
        tail = nullptr;
    }
}
void IntList::push_front(int val) {
    // if list is not empty attach node to head
    IntNode *n = new IntNode(val);
    if (head != nullptr) {
        n->next = head;
        head = n;
    }
    // else set head and tail to new node
    else {
        head = n;
        tail = n;
    }
}
void IntList::pop_front() {
    // if list is not empty delete head
    if (head != nullptr) {
        IntNode* temp = head;
        // delete head if there is a next and assign head to next
        if (head->next != nullptr) {
            head = head->next;
            delete temp;
        }
        // list is size one so set head and tail to nullptr
        else {
            delete head;
            head = nullptr;
            tail = nullptr;
        }
    }
    // otherwise do nothing
}
bool IntList::empty() const {
    bool isEmpty = false;
    if (head == nullptr) isEmpty = true;
    return isEmpty;
}
const int & IntList::front() const {
    return head->value;
}
const int & IntList::back() const {
    return tail->value;
}

ostream & operator<<(ostream & o, const IntList & rhs) {
    for (IntNode * curr = rhs.head; curr != nullptr; curr = curr->next) {
        o << curr->value;
        if (curr->next != nullptr) o << " ";
    }
    return o;
}