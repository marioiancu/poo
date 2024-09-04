#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include "CartItem.h"
#include <vector>

using namespace std;

class ShoppingCart {
private:
    vector<CartItem> items;

    // Static attribute to keep track of the total number of items
    static int totalItemsInAllCarts;

public:
    // Add product to cart
    void addProduct(Product& product, int quantity);

    // Remove product from cart
    void removeProduct(const Product& product);

    // Calculate the total price of all items in the cart
    double getTotalPrice() const;

    // Search Product
    bool searchProduct(Product& prod);

    // Display all items in the cart
    void displayCart() const;

    // Static function to get the total number of items in all carts
    static int getTotalItemsInAllCarts();

    // Interactive menu
    void menu();
};

#endif // SHOPPINGCART_H
