#include "CartItem.h"
#include "Discount.h"
#include "DiscountFactory.h"
#include "DiscountManager.h"
#include "Inventory.h"
#include "Product.h"
#include "ShoppingCart.h"
#include <memory>
#include <list>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    int choice;
    ShoppingCart cart;
    int qty;
    do {
        cout << "\n\t\tShopping Cart & Products Management " << endl;
        cout << "\t\t------------------------------------ " << endl;
        cout << " 1. Cart Management\n 2. Inventory Management\n 3. Check Discount and Bill\n 4. Demonstration of STL\n 5. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                    // Shopping Cart and Product Management
                    cart.menu();
                break;
            }
            case 2: {
                // Template Class Demonstration
                Inventory<Product> productInventory;
                productInventory.menu();
            }
            case 3: {
                double total = cart.getTotalPrice();

                // Display total number of items in all carts using static function
                cout << "Total items in all carts: " << ShoppingCart::getTotalItemsInAllCarts() << endl;

                // Discount Management using Singleton Design Pattern
                DiscountManager& discountManager = DiscountManager::getInstance();
                discountManager.setDiscount(DiscountFactory::createDiscount("Percentage", 10.0));
                double discountedPrice = discountManager.applyDiscount(total);
                cout << "\nTotal after 10% discount: $" << discountedPrice << endl;

                discountManager.setDiscount(DiscountFactory::createDiscount("Fixed", 5.0));
                discountedPrice = discountManager.applyDiscount(total);
                cout << "Total after $5 Fixed discount: $" << discountedPrice << endl;
                break;
            }
            case 4: {
                // STL Containers and Algorithm
                list<int> quantities = { 5, 10, 15, 20 };
                set<double> prices = { 0.99, 0.59, 1.99, 0.89 };

                // Use std::transform to increase all quantities by 1 using a lambda function
                transform(quantities.begin(), quantities.end(), quantities.begin(), [](int qty) { return qty + 1; });

                // Display the modified quantities
                cout << "Modified quantities: ";
                for (const auto& qty : quantities) {
                    cout << qty << " ";
                }
                cout << endl;

                // Display the prices in ascending order (std::set already sorts them)
                cout << "Prices: ";
                for (const auto& price : prices) {
                    cout << price << " ";
                }
                cout << std::endl;
                break;
            }
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice, try again.\n";
        }
    } while (choice != 5);


    return 0;
}
