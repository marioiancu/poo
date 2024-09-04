#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <string>

using namespace std;

class Product {
private:
    string name;
    double price;
    int stock_available;

public:
    // Default constructor
    Product();

    // Initialization constructor
    Product(const string& name, double price, int stock);

    // Overloaded constructor
    Product(const string& name, double price);

    // Copy constructor
    Product(const Product& copy);

    // Copy assignment operator
    Product& operator=(const Product& copy);

    // Destructor
    ~Product();

    // Getters
    const string& getName() const { return name; }
    double getPrice() const { return price; }
    int getStock() const { return stock_available; }
    void setStock(int qty) { stock_available = qty; }

    // Overloaded operators
    Product operator+(int qty) const;
    Product operator-(int qty) const;
    bool operator==(const Product& prod) const;

    // Declaration of overloaded output operator
    friend ostream& operator<<(ostream& os, const Product& product);

    // Declaration of overloaded input operator
    friend istream& operator>>(istream& is, Product& product);
};

#endif // PRODUCT_H
