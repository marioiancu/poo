#include "ShoppingCart.h"
#include <iostream>
#include <algorithm>

using namespace std;

// Initialize the static member
int ShoppingCart::totalItemsInAllCarts = 0;

// Add product to cart
void ShoppingCart::addProduct(Product& product, int quantity) {
    product = product - quantity;
    for (auto& item : items) {
        if (item.getProduct() == product) {
            item.setQuantity(item.getQuantity() + quantity);
            item.getProduct().setStock(product.getStock());
            totalItemsInAllCarts += quantity;  // Update static count
            return;
        }
    }
    items.push_back(CartItem(product, quantity));
    totalItemsInAllCarts += quantity;  // Update static count
}

// Remove product from cart
void ShoppingCart::removeProduct(const Product& product) {
    auto it = remove_if(items.begin(), items.end(),
        [&product](CartItem& item) {
            if (item.getProduct() == product) {
                totalItemsInAllCarts -= item.getQuantity();  // Update static count
                return true;
            }
            return false;
        });
    items.erase(it, items.end());
}

// Calculate the total price of all items in the cart
double ShoppingCart::getTotalPrice() const {
    double total = 0;
    for (const auto& item : items) {
        total += item.getTotalPrice();
    }
    return total;
}

// Search Product
bool ShoppingCart::searchProduct(Product& prod) {
    for (auto& item : items) {
        if (prod == item.getProduct()) {
            prod.setStock(item.getProduct().getStock());
            return true;
        }
    }
    return false;
}

// Display all items in the cart
void ShoppingCart::displayCart() const {
    for (const auto& item : items) {
        cout << item << endl;
    }
    cout << "\n\tTotal Cart Price: $" << getTotalPrice() << endl;
}

// Static function to get the total number of items in all carts
int ShoppingCart::getTotalItemsInAllCarts() {
    return totalItemsInAllCarts;
}

// Interactive menu
void ShoppingCart::menu() {
    int choice;
    int qty;
    do {
        cout << "\n\tShopping Cart Management " << endl;
        cout << "\t-------------------------- " << endl;
        cout << " 1. Add Product\n 2. Remove Product\n 3. Display Cart\n 4. Check Bill\nEnter choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int quantity;
            Product product("", 0.0, 0);
            cin >> product;
            if (!searchProduct(product)) {
                cout << "Enter Available Stock: ";
                cin >> qty;
                product.setStock(qty);
            }

            cout << "Enter quantity to add, Available Stock (" << product.getStock() << ") : ";
            cin >> quantity;
            if (quantity <= product.getStock()) {
                addProduct(product, quantity);
            }
            else {
                cout << "\nSelect Appropriate quantity, Check Available Stock." << endl;
            }
            break;
        }
        case 2: {
            Product product("", 0.0, 0);
            cin >> product;
            removeProduct(product);
            break;
        }
        case 3:
            displayCart();
            break;
        case 4:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice, try again.\n";
        }
    } while (choice != 4);
}
