#ifndef __SHOPPING_CART_H__
#define __SHOPPING_CART_H__

#include <iostream>
#include "string.h"
#include "vector"
#include "ItemToPurchase.h"
using namespace std;

class ShoppingCart {
   
    public:
        ShoppingCart();
        ShoppingCart(string name, string date);
        string customerName() const;
        string date() const;
        void addItem(ItemToPurchase item);
        void removeItem(ItemToPurchase item);
        void modifyItem(ItemToPurchase item);

        int numItemsInCart() const;
        int costOfCart() const;
        void printTotal() const;
        void printDescriptions() const;


    private:
        string _customerName;
        string _currentDate;
        vector <ItemToPurchase> _cartItems;
};


#endif