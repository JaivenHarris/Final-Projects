#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include "ProduceItem.h"

#ifndef TOTAL_AMOUNT_H
#define TOTAL_AMOUNT_H

using namespace std;

/* Total Amount class to calculate and display the total amount
A. Define a class representing the Total Amount
B. Declare a vector to store the items and a double for subtotal
C. Constructor to initialize the subtotal
D. Function to add an item to the total amount and update the subtotal
E. Function to remove an item from the total amount and update the subtotal
F. Getter function to retrieve the subtotal
G. Getter function to retrieve the total amount
H. Getter function to retrieve the items
I. Function to display the total amount
J. Function to write the total amount to a file
*/

// A. Define a class representing the Total Amount
class TotalAmount {

    // B. Declare a vector to store the items and a double for subtotal
    private:
        vector<ProduceItem*> items;
        double subtotal;
    
    // C. Constructor to initialize the subtotal
    public:
        TotalAmount() : subtotal(0.0) {}
        
        // D. Function to add an item to the total amount and update the subtotal
        void addItem(ProduceItem* item) {
            items.push_back(item);
            subtotal += item->getPrice();
        }
        
        // E. Function to remove an item from the total amount and update the subtotal
        void removeItem(const string& itemName) {
            for (auto it = items.begin(); it != items.end(); ++it) {
                if ((*it)->getName() == itemName) {
                    subtotal -= (*it)->getPrice();
                    items.erase(it);
                    return;
                }
            }
        }
        
        // F. Getter function to retrieve the subtotal
        double getSubtotal() const {
            return subtotal;
        }
        
        // G. Getter function to retrieve the total amount
        double getTotal() const {
            return subtotal;
        }
        
        // H. Getter function to retrieve the items
        const vector<ProduceItem*>& getItems() const {
            return items;
        }
        
        // I. Function to display the total amount
        void displayTotal() const {
            cout << fixed << setprecision(2);
            cout << "---------- Receipt ----------" << endl;
            cout << "Items:" << endl;
            for (const auto& item : items) {
                cout << "- " << item->toString() << endl;
            }
            cout << "----------------------------" << endl;
            cout << "Subtotal: $" << subtotal << endl;
            cout << "Total: $" << getTotal() << endl;
            cout << "----------------------------" << endl;
        }
        
        // J. Function to write the total amount to a file
        void writeTotalToFile() const {
            ofstream outFile("receipt.txt");
            if (outFile.is_open()) {
                outFile << fixed << setprecision(2);
                outFile << "---------- Bears Produce Receipt ----------" << endl;
                outFile << "Date: " << __DATE__ << " " << __TIME__ << endl;
                outFile << "Items:" << endl;
                for (const auto& item : items) {
                    outFile << "- " << item->toString() << endl;
                }
                outFile << "----------------------------" << endl;
                outFile << "Subtotal: $" << subtotal << endl;
                outFile << "Total: $" << getTotal() << endl;
                outFile << "----------------------------" << endl;
                outFile << "Thank you for shopping at Bears Produce!" << endl;
                outFile.close();
                cout << "Receipt saved to receipt.txt" << endl;
            } else {
                cout << "Error: Unable to save receipt to file." << endl;
            }
        }
};

#endif