#include <iostream>
#include <string>
#include "ProduceItem.h"

#ifndef VEGETABLE_H
#define VEGETABLE_H

using namespace std;
/* Vegetable class inherits from ProduceItem
A. Define a class representing the Vegetable
B. Declare a private member variable for organic status
C. Default constructor to set default values
D. Parameterized constructor to set specific values
E. Accessor method to retrieve the organic status
F. Mutator method to set the organic status
G. toString method to return a string representation of the vegetable  
*/
// A. Define a class representing the Vegetable
class Vegetable : public ProduceItem {

    //B. Declare a private member variable for organic status
    private:
        bool isOrganic;
    
    //C. Default constructor to set default values
    public:
        Vegetable() : ProduceItem(), isOrganic(false) {}
        
        //D. Parameterized constructor to set specific values
        Vegetable(string name, double price, string unit, bool isOrganic): ProduceItem(name, price, unit), isOrganic(isOrganic) {}
    
        //E. Accessor method to retrieve the organic status
        bool getIsOrganic() const { 
        return isOrganic; 
    }
    
        //F. Mutator method to set the organic status
        void setIsOrganic(bool organic) { 
        this->isOrganic = organic; 
        }
    
        //G. toString method to return a string representation of the vegetable
        string toString() const override {
            string organicLabel = isOrganic ? " (Organic)" : "";
            return ProduceItem::toString() + organicLabel;
        }
};

#endif