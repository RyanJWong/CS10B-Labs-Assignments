#ifndef __ITEM_TO_PURCHASE_H__
#define __ITEM_TO_PURCHASE_H__

#include <iostream>
#include "string.h"
using namespace std;

class ItemToPurchase {
    public:
        ItemToPurchase();
        ItemToPurchase(string name, string description, int price , int quantity );

        void setName(const string& name);
        void setPrice(const int& price);
        void setQuantity(const int& quantity); 
        void setDescription(const string& description);
        void printItemCost();
        void printItemDescription();

        string name() const;
        string description() const;
        int price() const;
        int quantity() const;
        
  private:
        string _name; 
        string _description;
        int _price;
        int _quantity; 

};

#endif

