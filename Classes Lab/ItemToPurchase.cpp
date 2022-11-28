#include "ItemToPurchase.h"
using namespace std;

ItemToPurchase::ItemToPurchase() {
    this->_name = "none";
    this->_price = 0;
    this->_quantity = 0;
    this->_description = "none";
}

ItemToPurchase::ItemToPurchase(string name, string description, int price, int quantity) {
    this->_name = name;
    this->_price = price;
    this->_quantity = quantity;
    this->_description = description;
}


void ItemToPurchase::setName(const string& name) {
    this->_name= name;
}




void ItemToPurchase::setPrice(const int& price) {
    this->_price = price;
}

void ItemToPurchase::setQuantity(const int& quantity) {
    this->_quantity = quantity;
} 

void ItemToPurchase::setDescription(const string& description) {
    this->_description = description;
}
void ItemToPurchase::printItemCost() {
    cout << this->_name << " " << this->_quantity << " @ $" << this->_price << " = $" << this->_price * this->_quantity << endl;
}
void ItemToPurchase::printItemDescription() {
    cout << this->_name << ": " << this->_description << endl;
}

string ItemToPurchase::name() const {
    return this->_name;
}

string ItemToPurchase::description() const{
    return this->_description;
}

int ItemToPurchase::price() const {
    return this->_price;
}
int ItemToPurchase::quantity() const {
    return this->_quantity;
}
