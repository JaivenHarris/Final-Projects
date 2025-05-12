

#include <iostream>
#include <string>
#include "ProduceItem.h"

#ifndef FRUIT_H
#define FRUIT_H
using namespace std;

/* Fruit class inherits from ProduceItem
A. Define a class representing the Fruit
B. Declare a private member variable for organic status
C. Default constructor to set default values
D. Parameterized constructor to set specific values
E. Accessor method to retrieve the organic status
F. Mutator method to set the organic status
G. toString method to return a string representation of the fruit  
*/
// A. Define a class representing the Fruit
class Fruit : public ProduceItem {

    // B. Declare a private member variable for organic status
    private:
        bool isOrganic;
    
    // C. Default constructor to set default values
    public:
        Fruit() : ProduceItem(), isOrganic(false) {}
        
        // D. Parameterized constructor to set specific values
        Fruit(string name, double price, string unit, bool isOrganic): ProduceItem(name, price, unit), isOrganic(isOrganic) {}
        
        // E. Accessor method to retrieve the organic status
        bool getIsOrganic() const { 
            return isOrganic; 
        }
        
        // F. Mutator method to set the organic status
        void setIsOrganic(bool organic) {
        isOrganic = organic; 
        }
        
        // G. toString method to return a string representation of the fruit
        string toString() const override {
            string organicLabel = isOrganic ? " (Organic)" : "";
            return ProduceItem::toString() + organicLabel;
        }
};
#endif