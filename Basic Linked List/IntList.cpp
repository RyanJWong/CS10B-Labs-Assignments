#include "IntList.h"
#include <iostream>
using namespace std;

IntList::IntList() {
    head = nullptr;
    tail = nullptr;
}
IntList::~IntList() {
   if (head != nullptr) {
        if (head->next != nullptr) {
            IntNode* curr = head;
            IntNode* temp = curr;
            //edge case if list is size one
            while (curr != nullptr) {
                curr = curr->next;
                delete temp;
                temp = nullptr;
                temp = curr;
            }
        }
        // list size of one 
        else {
            delete head;
            head = nullptr;
        }
        head = nullptr;
        tail = nullptr;
    }
}

IntList::IntList(const IntList &cpy) {
    head = nullptr;
    tail = nullptr;
    for (IntNode * curr = cpy.head; curr != nullptr; curr = curr->next) {
            push_back(curr->value);
    }   
}
IntList & IntList::operator=(const IntList &rhs) {
   if (this != &rhs) {           // 1. Don't self-assign
        clear();
        for (IntNode * curr = rhs.head; curr != nullptr; curr = curr->next) {
            push_back(curr->value);
        }
    }
    return *this;
}
void IntList::clear() {
    if (head != nullptr) {
        if (head->next != nullptr) {
            IntNode* curr = head;
            IntNode* temp = curr;
            while (curr != nullptr) {
                curr = curr->next;
                delete temp;
                temp = nullptr;
                temp = curr;
            }
        }
        // list size of one 
        else {
            delete head;
            head = nullptr;
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
void IntList::push_back(int value) {
    // if list is not empty attach node to tail
    IntNode *n = new IntNode(value);
    if (tail != nullptr) {
        tail->next = n;
        tail = n;
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
            temp = nullptr;
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

void IntList::selection_sort() {
    // two loops
   
    IntNode * temp = head;
    while (temp != nullptr) {
        IntNode * min = temp;
        IntNode * curr = temp->next;
        while (curr != nullptr) {
            if (curr->value < min->value) {
                min = curr;
            }
            curr = curr->next;
        }
        swap(temp->value, min->value);
        temp = temp->next;
    }
    
}

void IntList::insert_ordered(int value) {
    if (head != nullptr) { // only run if the list isn't empty
        IntNode * prev = head;
        if (head->next != nullptr) {
            for (IntNode* curr = head->next; curr != nullptr; curr = curr->next) {
                if (value >= prev->value && value <= curr->value) { // insert value between two nodes if its greater or equal than the prev node and less than or equal to curr node
                    IntNode* temp = new IntNode(value);
                    prev->next = temp;
                    temp->next = curr;
                    return;
                }
                prev = curr;
            }
            // if the function is still running at this point that means the value is at the beginning or end of the list
            if (value > head->value) push_back(value);
            else push_front(value);
        }
        else {
            if (value > head->value) push_back(value);
            else push_front(value);
        }
    }
    else { // else just add it to the front
        push_front(value);
    }
}
void IntList::remove_duplicates() {
    if (head != nullptr) { // only run if the list isn't empty
        if (head->next != nullptr) {
            
            IntNode * i = head;
            while (i != nullptr && i->next != nullptr) {
                IntNode * prev = i;
                while (prev->next != nullptr) {
                    IntNode * curr = prev->next;
                    if (curr->value == i->value) {
                        IntNode * temp = curr;
                        prev->next = curr->next;
                        delete(temp);
                        if (prev->next == nullptr) tail = prev;
                    }
                    else {
                        prev = prev->next;
                    }
                }
                i = i->next;
            }          
        }
    }
}