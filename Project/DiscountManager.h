#ifndef DISCOUNTMANAGER_H
#define DISCOUNTMANAGER_H

#include <memory>
#include "Discount.h"

using namespace std;

// Singleton Design Pattern
class DiscountManager {
private:
    static unique_ptr<DiscountManager> instance;
    unique_ptr<Discount> discount;

    DiscountManager() = default;  // Private constructor

public:
    static DiscountManager& getInstance() {
        if (!instance) {
            instance.reset(new DiscountManager());
        }
        return *instance;
    }

    void setDiscount(unique_ptr<Discount> discount) {
        this->discount = move(discount);
    }

    double applyDiscount(double total) {
        if (discount) {
            return discount->applyDiscount(total);
        }
        return total;
    }
};

// Initialize the static member
unique_ptr<DiscountManager> DiscountManager::instance = nullptr;

#endif // DISCOUNTMANAGER_H
