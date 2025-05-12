#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iomanip>

#ifndef PRODUCE_ITEM_H
#define PRODUCE_ITEM_H

using namespace std;

/*Class for produce items with price and unit (lb or count)
A. Define a class representing the Produce Item
B. Declare private member variables for name, price, and unit
C. Constructor to initialize the member variables
D. Default constructor to set default values
E. Parameterized constructor to set specific values
F. Accessor methods to retrieve the name, price, and unit
G. Mutator methods to set the name, price, and unit
H. toString method to return a string representation of the produce item
I. Virtual destructor to allow for proper cleanup of derived classes
*/
// A. Define a class representing the Produce Item
class ProduceItem {

    //B. Declare private member variables for name, price, and unit
    private:
        string name;
        double price;
        string unit; 
    
    //C. Constructor to initialize the member variables
    public:

        //D. Default constructor to set default values
        ProduceItem() : name(""), price(0.0), unit("lb") {}
    
        //E. Parameterized constructor to set specific values
        ProduceItem(string name, double price, string unit): name(name), price(price), unit(unit) {}
    
        //F. Accessor methods to retrieve the name, price, and unit
        string getName() const { 
        return name; 
    }

        double getPrice() const { 
        return price; 
    }

        string getUnit() const { 
        return unit; 
    }
    
        //G. Mutator methods to set the name, price, and unit
        void setName(string name) {
        this->name = name;
    }

        void setPrice(double price) {
        this->price = price; 
        }

        void setUnit(string unit) { 
        this->unit = unit; 
    }
    
        //H. toString method to return a string representation of the produce item
        virtual string toString() const {
            ostringstream priceFormat;
            priceFormat << fixed << setprecision(2) << price;
            return name + " - $" + priceFormat.str() + "/" + unit;
        }
    
};

#endif