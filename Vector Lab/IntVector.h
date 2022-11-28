#ifndef __INT_VECTOR_H__
#define __INT_VECTOR_H__
#include <stdexcept>
using namespace std;
class IntVector {
    public:
        IntVector(unsigned capacity = 0, int value = 0);
        ~IntVector();
        unsigned size() const;
        unsigned capacity() const;
        bool empty() const;
        const int & at(unsigned index) const;
        const int & front() const;
        const int & back() const;
        int & back();
        int & front();
        int & at(unsigned index);
        void insert(unsigned index, int value);
        void erase(unsigned index);
        void push_back(int value);
        void pop_back();
        void clear();
        void resize(unsigned size, int value = 0);
        void reserve(unsigned n);
        void assign(unsigned n, int value);


    private: 
        unsigned _size;
        unsigned _capacity;
        int *_data;
        void expand();
        void expand(unsigned amount);

    
};

#endif