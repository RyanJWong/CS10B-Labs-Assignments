#ifndef SORTEDSET_H
#define SORTEDSET_H
#include "IntList.h"
#include <ostream>

using namespace std;
class SortedSet : public IntList {
    public:
        SortedSet();
        SortedSet(const SortedSet & set);
        SortedSet(const IntList & list);
        ~SortedSet();
        bool in(int value) const;
        SortedSet operator|(const SortedSet & rhs);
        SortedSet operator&(const SortedSet & rhs);
        SortedSet & operator|=(const SortedSet & rhs);
        SortedSet & operator&=(const SortedSet & rhs);
        void add(int value);
        void push_front(int value);
        void push_back(int value);
        void insert_ordered(int value);
}; 

#endif