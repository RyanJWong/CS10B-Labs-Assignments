#include "ShoppingCart.h"

ShoppingCart::ShoppingCart() {
    this->_customerName = "none";
    this->_currentDate = "January 1, 2016";
}

ShoppingCart::ShoppingCart(string name, string date) {
    this->_customerName = name;
    this->_currentDate = date;
}

string ShoppingCart::customerName() const{
    return this->_customerName;
}
string ShoppingCart::date() const{
    return this->_currentDate;
}
void ShoppingCart::addItem(ItemToPurchase item) {
    this->_cartItems.push_back(item);
}
void ShoppingCart::removeItem(ItemToPurchase item) {
    for (unsigned i = 0; i < this->_cartItems.size(); ++i) {
        if (this->_cartItems.at(i).name() == item.name()) {
            this->_cartItems.erase(_cartItems.begin() + i); 
            return;
        }
    }
    cout << "Item not found in cart. Nothing removed." << endl;
}
void ShoppingCart::modifyItem(ItemToPurchase item) {
    for (unsigned i = 0; i < this->_cartItems.size(); ++i) {
        if (this->_cartItems.at(i).name() == item.name()) {
            if (item.price() != 0) {
                _cartItems.at(i).setPrice(item.price());
            }
            if (item.quantity() != 0) {
                _cartItems.at(i).setQuantity(item.quantity());
            }
            if (item.description() != "none") {
                _cartItems.at(i).setDescription(item.description());
            }
            return;
        }
    }
    cout << "Item not found in cart. Nothing modified." << endl ;
}

int ShoppingCart::numItemsInCart() const {
    return this->_cartItems.size();
}

int ShoppingCart::costOfCart() const {
    int total = 0;
    for (ItemToPurchase i : _cartItems) {
        total = total + i.price() * i.quantity();
    }
    return total;
}

void ShoppingCart::printTotal() const {
    cout << customerName() << "'s Shopping Cart - " << date() << endl;
    int size = 0;
    for (ItemToPurchase i : _cartItems) {
        size = size + i.quantity();
    }
    cout << "Number of Items: " <<  size << endl << endl;
    if (_cartItems.size() > 0) {
        for (ItemToPurchase i : _cartItems) {
            i.printItemCost();
        }
    }
    else {
        cout << "SHOPPING CART IS EMPTY" << endl;
    }
    cout << endl << "Total: $" << costOfCart() << endl << endl;
}

void ShoppingCart::printDescriptions() const {
    cout << customerName() << "'s Shopping Cart - " << date() << endl << endl;
    cout << "Item Descriptions" << endl;
    for (ItemToPurchase i : _cartItems) {
        i.printItemDescription();
    }
}


