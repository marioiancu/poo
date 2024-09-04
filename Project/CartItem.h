#ifndef CARTITEM_H
#define CARTITEM_H

#include "Product.h"

using namespace std;

class CartItem {
private:
    Product product;
    int quantity;

public:
    // Constructor
    CartItem(const Product& product, int quantity);

    // Getters
    Product& getProduct();
    int getQuantity() const;

    // Setters
    void setQuantity(int qty);

    // Calculate the total price for the item
    double getTotalPrice() const;

    // Overloaded output operator for CartItem
    friend ostream& operator<<(ostream& os, const CartItem& item);
};

#endif // CARTITEM_H
