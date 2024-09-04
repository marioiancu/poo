#ifndef INVENTORY_H
#define INVENTORY_H

#include <map>
#include <string>
#include <typeinfo>
#include <iostream>

using namespace std;

// Template Class
template <typename T>
class Inventory {
private:
    map<std::string, T> inventoryItems;

public:
    void addItem(const string& name, T item) {
        inventoryItems[name] = item;
    }

    void addItem() {
        string name; double price; int stock;
        cout << "Enter Item Name: ";
        cin >> name;
        cout << "Enter Price: ";
        cin >> price;
        cout << "Enter Stock: ";
        cin >> stock;
        T item(name,price,stock);
        inventoryItems[name] = item;
    }

    void removeItem(const string& name) {
        inventoryItems.erase(name);
    }

    void displayItems() const {
        for (const auto& pair : inventoryItems) {
            const string& name = pair.first;
            const T& item = pair.second;
            cout << "Item: " << name << ", Type: " << typeid(item).name() << endl;
        }
    }

    void menu() {
        int choice;
        int qty;
        do {
            cout << "\n\t\tInventory & Products Management " << endl;
            cout << "\t\t------------------------------------ " << endl;
            cout << " 1. Add Item in Inventory\n 2. Remove Item from Inventory\n 3. Display Inventory\n 4. Exit to Previous Menu\nEnter choice: ";
            cin >> choice;

            switch (choice) {
            case 1: {

                //Product apple("Apple", 0.99, 100);
                //Product banana("Banana", 0.59, 150);

                //productInventory.addItem("Apple", apple);
                //productInventory.addItem("Banana", banana);
                this->addItem();
                break;
            }
            case 2: {
                string name;
                cout << "\nEnter Name of Item to remove: ";
                cin >> name;
                this->removeItem(name);
                break;
            }
            case 3:
                this->displayItems();
                break;
            case 4:
                break;
            default:
                cout << "Invalid choice, try again.\n";
            }
        } while (choice != 4);
    }

    T* getItem(const std::string& name) {
        auto it = inventoryItems.find(name);
        if (it != inventoryItems.end()) {
            return &it->second;
        }
        return nullptr;
    }
};

#endif // INVENTORY_H
