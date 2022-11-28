#include "SortedSet.h"
#include <ostream>

using namespace std;
SortedSet::SortedSet() : IntList(){
    
}
SortedSet::SortedSet(const SortedSet & set) : IntList(set) {
}
SortedSet::SortedSet(const IntList & list) : IntList(list){
    remove_duplicates();
    selection_sort();
}



SortedSet::~SortedSet() {
}

bool SortedSet::in(int value) const{
    bool inSet = false;
    for (IntNode * curr = head; curr != nullptr; curr = curr->next) {
        if (curr->value == value) inSet = true;
    }
    return inSet;
}

SortedSet SortedSet::operator|(const SortedSet & rhs) {
    SortedSet temp;
    for (IntNode * curr = rhs.head; curr != nullptr; curr = curr->next) {
        temp.add(curr->value);
    }
    for (IntNode * curr = head; curr != nullptr; curr = curr->next) {
        temp.add(curr->value);
    }
    return temp;
}
SortedSet SortedSet::operator&(const SortedSet & rhs) {
    SortedSet temp;
    for (IntNode * curr = head; curr != nullptr; curr = curr->next) {
        if (rhs.in(curr->value)) temp.add(curr->value);
    }
    return temp;
}

SortedSet & SortedSet::operator|=(const SortedSet & rhs) {
    if (this != &rhs) {
        SortedSet temp = *this;  
        clear();
        for (IntNode * curr = rhs.head; curr != nullptr; curr = curr->next) {
            add(curr->value);
        }
        for (IntNode * curr = temp.head; curr != nullptr; curr = curr->next) {
            add(curr->value);
        }
    }
    return *this;
}

SortedSet  & SortedSet::operator&=(const SortedSet & rhs) {
    if (this != &rhs) {
        SortedSet temp = *this;  
        clear();
        for (IntNode * curr = temp.head; curr != nullptr; curr = curr->next) {
            if (rhs.in(curr->value)) add(curr->value);
        }
    }
    return *this;
}


void SortedSet::add(int value) {
    bool inSet = false;
    IntNode * temp = new IntNode(value);
    IntNode * curr = head;
    // Make sure val is unique
    for (IntNode * c = head; c != nullptr; c = c->next) {
        if(c->value == value) inSet = true;
    }
    if (!inSet) {
        // list size 0
        if (head == nullptr) {
            head = temp;
            tail = temp;
        }
        // list size 1
        else if (curr->next == nullptr) {
            if (value > head->value) {
                head->next = temp;
                tail = temp;
            }
            else {
                temp->next = head;
                tail = head;
                head = temp;
            }
        }
        else if (head->value >= value) {
                temp->next = head;
                tail = head;
                head = temp;
        }
        else {
            // loop until the next value is greater than passed val
            while (curr->next != nullptr && curr->next->value < value) {
                curr = curr->next;
            }
            // insert node after curr if the value is less than the next node
            temp->next = curr->next;
            curr->next = temp;
            // if added node is at the end, set tail to it
            if (temp->next == nullptr) {
                tail = temp;
            }
        }
    }
    
}

void SortedSet::push_front(int value) {
    add(value);
}

void SortedSet::push_back(int value) {
    add(value);
}

void SortedSet::insert_ordered(int value) {
    add(value);
}

