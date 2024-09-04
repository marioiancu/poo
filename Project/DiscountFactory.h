#ifndef DISCOUNTFACTORY_H
#define DISCOUNTFACTORY_H

#include "Discount.h"
#include <memory>
#include <string>

using namespace std;

// Factory Method Design Pattern
class DiscountFactory {
public:
    static unique_ptr<Discount> createDiscount(const string& type, double value) {
        if (type == "Percentage") {
            return make_unique<PercentageDiscount>(value);
        }
        else if (type == "Fixed") {
            return make_unique<FixedDiscount>(value);
        }
        else {
            return nullptr;
        }
    }
};

#endif // DISCOUNTFACTORY_H
