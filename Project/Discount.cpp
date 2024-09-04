#include "Discount.h"

using namespace std;

PercentageDiscount::PercentageDiscount(double percentage)
    : percentage(percentage) {}

double PercentageDiscount::applyDiscount(double total) const {
    return total - (total * percentage / 100);
}

FixedDiscount::FixedDiscount(double amount)
    : amount(amount) {}

double FixedDiscount::applyDiscount(double total) const {
    return total - amount;
}
