#include <iostream>

using namespace std;

#include "ItemToPurchase.h"
#include "string.h"
#include "ShoppingCart.h"

void printMenu(ShoppingCart& cart);

int main() {
    string name;
    string date;
    cout << "Enter customer's name: ";
    getline(cin, name);
    cout << endl << "Enter today's date: ";
    getline(cin, date);
    cout << endl << endl << "Customer name: " << name << endl << "Today's date: " << date << endl <<endl;
    ShoppingCart cart = ShoppingCart(name, date);
    printMenu(cart);
    return 0;
}

void printMenu(ShoppingCart& cart) {
    char option;
    bool running = true;
    
    while (running) {
        cout << "MENU" << endl;
        cout << "a - Add item to cart" << endl;
        cout << "d - Remove item from cart" << endl;
        cout << "c - Change item quantity" << endl;
        cout << "i - Output items' descriptions" << endl;
        cout << "o - Output shopping cart" << endl;
        cout << "q - Quit" << endl << endl;
       
        bool valid = false;
        while (!valid) {
            cout << "Choose an option: ";

            string o = "";
            getline(cin, o);
            option = o.at(0);
            cout << endl;
            string name = "none";
            string description = "none";
            string price = "0";
            string quantity = "0";
            switch (option) {
                case 'a' :
                    cout << endl << "ADD ITEM TO CART" << endl;
                    cout << "Enter the item name: ";
                    getline(cin, name);
                    cout << endl << "Enter the item description: ";
                    getline(cin, description);
                    cout << endl << "Enter the item price: ";
                    getline(cin, price);
                    cout << endl << "Enter the item quantity: ";
                    getline(cin, quantity);
                    cout << endl << endl;
                    cart.addItem(ItemToPurchase(name, description, stoi(price), stoi(quantity)));
                    valid = true;
                    break;
                case 'd':
                    cout << endl << "REMOVE ITEM FROM CART" << endl;
                    cout << "Enter name of item to remove: ";
                    getline(cin, name);
                    cout << endl;
                    cart.removeItem(ItemToPurchase(name, "none", 0, 0));
                    cout << endl;
                    valid = true;
                    break;
                case 'c':
                    cout << endl << "CHANGE ITEM QUANTITY" << endl;
                    cout << "Enter the item name: ";
                    getline(cin, name);
                    cout << endl << "Enter the new quantity: ";
                    getline(cin, quantity);
                    cout << endl;
                    cart.modifyItem(ItemToPurchase(name,"none", 0, stoi(quantity)));
                    cout << endl;
                    valid = true;
                    break;
                case 'i':
                    cout << endl << "OUTPUT ITEMS' DESCRIPTIONS" << endl;
                    cart.printDescriptions();
                    valid = true;
                    cout << endl;
                    break;
                case 'o':
                    cout << endl << "OUTPUT SHOPPING CART" << endl;
                    cart.printTotal();
                    valid = true;
                    break;
                case 'q':
                    running = false;
                    valid = true;
                    break;
                default:
                    break;
                
            }
        }
   }
}