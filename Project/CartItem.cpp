#include "CartItem.h"

using namespace std;

// Constructor
CartItem::CartItem(const Product& product, int quantity)
    : product(product), quantity(quantity) {}

// Getters
Product& CartItem::getProduct() { return product; }
int CartItem::getQuantity() const { return quantity; }

// Setters
void CartItem::setQuantity(int qty) { quantity = qty; }

// Calculate the total price for the item
double CartItem::getTotalPrice() const { return product.getPrice() * quantity; }

// Overloaded output operator for CartItem
ostream& operator<<(ostream& os, const CartItem& item) {
    os << item.product << "\t-Item Quantity: " << item.getQuantity() << "\t-Price: $" << item.getTotalPrice();
    return os;
}
