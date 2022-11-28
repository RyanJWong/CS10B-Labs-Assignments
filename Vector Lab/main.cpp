#include "IntVector.h"
#include <iostream>
using namespace std;
int main() {
    
    // Test accessors
    IntVector b = IntVector(2,2);
    cout << "Vector (2,2)" << endl;
    std::cout << "Vector w/ size 2 at index 1: " << b.at(1) << std::endl;
    std::cout << "Vector w/ size 2 at index 0: " <<b.front() << std::endl;
    IntVector a = IntVector();
    cout << "Vector (0,0)" << endl;
    std::cout << "Vector w/ size 0 size: " << a.size() << std::endl;
    std::cout << "Vector w/ size 0 capacity: " << a.capacity() << std::endl;
    std::cout << "Vector w/ is empty: ";
    if (a.empty()) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
    // Test Insert
    IntVector insert = IntVector(10,10);
    cout << "Vector (10,10)" << endl;
    cout << "Vector at index 9: " << insert.at(9) << endl;
    insert.insert(0, 1);
    cout << "Vector at index 0: " << insert.at(0) << endl;
    cout << "Vector at index 10: " << insert.at(10) << endl;

    // Test Erase
    IntVector erase = IntVector(5,5);
    cout << "Vector (5,5)" << endl;
    erase.insert(1, 2);
    cout << "Inserting 2 at index 1" << endl;
    cout << "Vector at index 1: " << erase.at(1) << endl;
    erase.erase(0);
    cout << "Erasing index 0" << endl;
    cout << "Vector at index 0: " << erase.at(0) << endl;

    // Test Pushback
    IntVector push = IntVector(2,2);
    cout << "Vector (2,2)" << endl;
    cout << "Pushing back 3" << endl;
    push.push_back(3);
    cout << "Vector at index 2: " << push.at(2) << endl;

    // Test Popback
    IntVector pop = IntVector(2,2);
    cout << "Vector (2,2)" << endl;
    cout << "Popping back" << endl;
    pop.pop_back();
    cout << "Vector new size: " << pop.size() << endl;

    // Test Clear
    IntVector clear = IntVector(100,100);
    cout << "Vector (100, 100)" << endl;
    cout << "Clearing" << endl;
    clear.clear();
    cout << "Vector new size: " << clear.size() << endl;

    // Test Resize
    IntVector size = IntVector(100,100);
    cout << "Vector (100, 100)" << endl;
    cout << "Resizing to 1000" << endl;
    size.resize(1000,1);
    cout << "Vector new capacity: " << size.capacity() << endl;

    cout << "Vector new size: " << size.size() << endl;
    cout << "Vector at index 999: " << size.at(999) << endl;
    cout << "Resizing to 10" << endl;
    size.resize(10);
    cout << "Vector new size: " << size.size() << endl;

    // Test Assign
    IntVector assign = IntVector(100,100);
    cout << "Vector (100, 100)" << endl;
    cout << "Assigning to 10,1" << endl;
    assign.assign(10,1);
    cout << "Vector new size: " << assign.size() << endl;
    cout << "Vector new capacity: " << assign.capacity() << endl;
    cout << "Vector at index 0: " << assign.at(0) << endl;
    return 0;
}