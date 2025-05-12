#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "ProduceItem.h"
#include "TotalAmount.h"

#ifndef SHOPPER_H
#define SHOPPER_H

using namespace std;

/* Shopper Class for the user:
   A. Define a class representing the Shopper
   B. Declare vectors to store the cart and items, and a double for balance
   C. Constructor to initialize the balance and populate the items vector with fruits and vegetables from ProduceDepartment
   D. Function to add an item to the cart and update the balance
   E. Function to remove an item from the cart and update the balance
   F. Getter function to retrieve the cart contents
   G. Getter function to retrieve the balance
   H. Getter function to retrieve the total amount
   I. Function to display the user items in cart and amount
*/
// A. Define a class representing the Shopper
class Shopper {

    // B. Declare vectors to store the cart and items, and a double for balance
    private:
        double balance;
        vector<ProduceItem*> cart;
        TotalAmount totalAmount;
        
    public:
        // C. Constructor to initialize the balance and populate the items vector with fruits and vegetables from ProduceDepartment
        Shopper(double initialBalance = 50.00) : balance(initialBalance) {}
    
        // D. Function to add an item to the cart and update the balance
        bool addItem(ProduceItem* item) {
            if (!item) return false;
            
            if (balance >= item->getPrice()) {
                cart.push_back(item);
                balance -= item->getPrice();
                totalAmount.addItem(item);
                return true;
            }
            return false; 
        }
    
        // E. Function to remove an item from the cart and update the balance
        bool removeItem(const string& itemName) {
            for (auto it = cart.begin(); it != cart.end(); ++it) {
                if ((*it)->getName() == itemName) {
                    balance += (*it)->getPrice();
                    totalAmount.removeItem(itemName);
                    cart.erase(it);
                    return true;
                }
            }
            return false; 
        }
        
        // F. Added to fix missing methods
        const vector<ProduceItem*>& getCart() const {
            return cart;
        }
        
        // G. Added to fix missing methods
        double getBalance() const {
            return balance;
        }
        
        // H. Added to fix missing methods
        const TotalAmount& getTotalAmount() const {
            return totalAmount;
        }
        
        // I. Added to fix missing methods
        void displayDetails() const {
            cout << "\n----- Shopper Details -----" << endl;
            cout << "Balance: $" << fixed << setprecision(2) << balance << endl;
            
            if (cart.empty()) {
                cout << "Your cart is empty." << endl;
            } else {
                cout << "Items in cart:" << endl;
                for (const auto& item : cart) {
                    cout << "- " << item->toString() << endl;
                }
                cout << "Total items: " << cart.size() << endl;
            }
            cout << "---------------------------" << endl;
        }
};

#endif