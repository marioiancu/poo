#ifndef DISCOUNT_H
#define DISCOUNT_H

using namespace std;

// Base Class
class Discount {
public:
    virtual double applyDiscount(double total) const = 0;
    virtual ~Discount() = default;
};

// Derived Class# 1
class PercentageDiscount : public Discount {
private:
    double percentage;

public:
    PercentageDiscount(double percentage);
    double applyDiscount(double total) const override;
};

// Derived Class# 2
class FixedDiscount : public Discount {
private:
    double amount;

public:
    FixedDiscount(double amount);
    double applyDiscount(double total) const override;
};

#endif // DISCOUNT_H
