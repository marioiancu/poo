#include "Product.h"

using namespace std;

// Default constructor
Product::Product() : name(""), price(0.0), stock_available(0) {}

// Initialization constructor
Product::Product(const string& name, double price, int stock)
    : name(name), price(price), stock_available(stock) {}

// Overloaded constructor
Product::Product(const string& name, double price)
    : name(name), price(price), stock_available(0) {}

// Copy constructor
Product::Product(const Product& copy)
    : name(copy.name), price(copy.price), stock_available(copy.stock_available) {}

// Copy assignment operator
Product& Product::operator=(const Product& copy) {
    if (this != &copy) {
        name = copy.name;
        price = copy.price;
        stock_available = copy.stock_available;
    }
    return *this;
}

// Destructor
Product::~Product() {}

// Overloaded output operator
ostream& operator<<(ostream& os, const Product& product) {
    os << "Product Name: " << product.getName()
        << ", Price: " << product.getPrice()
        << ", Stock: " << product.getStock();
    return os;
}

// Overloaded input operator
istream& operator>>(istream& is, Product& product) {
    cout << "Enter product name: ";
    is >> product.name;
    cout << "Enter price: ";
    is >> product.price;
    return is;
}

// Overloaded operators
Product Product::operator+(int qty) const {
    return Product(name, price, stock_available + qty);
}

Product Product::operator-(int qty) const {
    return Product(name, price, stock_available - qty);
}

bool Product::operator==(const Product& prod) const {
    return name == prod.name && price == prod.price;
}
