#include "IntVector.h"
#include <stdexcept>
using namespace std;

IntVector::IntVector(unsigned capacity, int value) {
    int* temp = new int[capacity];
    for (unsigned i = 0; i < capacity; i++) {
        temp[i] = value;
    }
    _capacity = capacity;
    _size = capacity;
    _data = temp;
}
IntVector::~IntVector() {
    delete[] _data;
}
unsigned IntVector::size() const {
    return _size;
}
unsigned IntVector::capacity() const {
    return _capacity;
}
bool IntVector::empty() const {
    if (_size == 0) return true;
    return false;
}
const int & IntVector::at(unsigned index) const {
    if (index >= _size || index < 0) {
        throw std::out_of_range("IntVector::at_range_check");
    }
    return _data[index];
}
int & IntVector::at(unsigned index)  {
    if (index >= _size || index < 0) {
        throw out_of_range("IntVector::at_range_check");
    }
    return _data[index];
}
const int & IntVector::front() const {
    return at(0);
}
int & IntVector::front() {
    return at(0);
}
const int & IntVector::back() const {
    return at(_size -1);
}
int & IntVector::back() {
    return at(_size -1);
}

void IntVector::expand() {
    if (_capacity == 0) _capacity = 1;
    else {
        _capacity = _capacity * 2;
    }
    int* temp = new int[_capacity];
    for (unsigned i = 0; i < _size; i++) {
        temp[i] = _data[i];
    }
    delete [] _data;
    _data = temp;
}
void IntVector::expand(unsigned amount) {
    _capacity += amount;
    int* temp = new int[_capacity];
    for (unsigned i = 0; i < _size; i++) {
        temp[i] = _data[i];
    }
    delete [] _data;
    _data = temp;
}
void IntVector::insert(unsigned index, int value) {
    if (index <= _size) {
        if (_size + 1 > _capacity) expand();
        for (unsigned i = index; i < _size; ++i){
            _data[i+1] = _data[i]; 
        }
        _size++;
        _data[index] = value;
    }
    else {
        throw out_of_range("IntVector::insert_range_check");
    }
}

void IntVector::erase(unsigned index) {
    if (index < 0 || index >= _size)         throw out_of_range("IntVector::erase_range_check");

    for (unsigned i = index; i < _size; ++i){
        _data[i] = _data[i+1];
    }
    _size--;
     
}

void IntVector::push_back(int value) {
    if (_size + 1 > _capacity) expand();
    _data[_size] = value;
    _size ++;
}

void IntVector::pop_back() {
    _size--;
}

void IntVector::clear() {
    _size = 0;
}

void IntVector::resize(unsigned size, int value) {
    if (size < _size) {
        _size = size;
    }
    else {
        if (size > _capacity) {
            if (_capacity * 2 > size && _capacity != 0) expand();
            else expand(size-_capacity);
        }
        for (unsigned i = _size; i < size; i++) {
            _data[i] = value;
        }
        _size = size;
    }
}
void IntVector::reserve(unsigned n) {
    if (n > _capacity) _capacity = n;
}

void IntVector::assign(unsigned n, int value) {

    if (n > _capacity) {
        if (_capacity * 2 > n && _capacity != 0)  expand();
        else expand(n-_capacity);
    }
    _size = n;
    int* temp = new int[_capacity];
    for (unsigned i = 0; i < n; i++) {
        temp[i] = value;
    }
    delete[] _data;
    _data = temp;
}

