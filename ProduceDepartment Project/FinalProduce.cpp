/*
Author: Jaiven Harris
Date: 3/3/2025
Purpose: Create a program of bears produce store for the shopper to choose what they want and perform calculations on total amount.
*/

#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <limits>
#include <sstream>

//All the header files 
#include "ProduceItem.h"
#include "Fruit.h"
#include "Vegetable.h"
#include "TotalAmount.h"
#include "ProduceDepartment.h"
#include "Shopper.h"

using namespace std;

/* IDEAS OF WHAT I NEED FIRST BEFORE CODING (3/3/2025 -- 4/20/25)
(1) 3 classes(1. Produce department (Class will contains items of fruits and vegetables), 2.Shopper (contains shopper cart, balance, and list of what they have), 3. Total Amount(Class for the calculating total amount in the shopper cart.) )
(2) sort function for sorting the fruits and vegetables by pounds and counts in the shopper view cart (quicksort)
(3) search function for searching the produce items (binary search Example: if the shopper wants a tomato the binary search would find the tomato and put it in the vegetable section of the shopper carts)
(4) Vectors for holding the produce items with prices (Example: vectors of fruit would be (Apple $1.99lb, Pears $1.50lb, Oranges $2.50lb) and vegetables would be (Onions $1.79lb, Tomatoes $1.99lb, and Lettuce $1.89lb). 
(5) Create functions for the shopper (Example: 1.shopperList(), 2.shopperCart() inside the shopper class)
(6) Create a file for outputing the total amount of what the shopper has.
(7) Main function for calling all the classes and functions (ONLY)
(8) Make a pointer to point in the direction of the "lb" and not by count (Example: item is 2.99, and item 1 is 2.19lb)
(9) Have data validation for user incorrect input (try catch for catching exceptions of the user incorrect input such as "Sorry the item is not on the list")
*/

//Display Menu for user Options
void displayMenu() {
    cout << "\n----- Bears Produce Menu -----" << endl;
    cout << "1. View Inventory" << endl;
    cout << "2. Search for Item" << endl;
    cout << "3. Add Item to Cart" << endl;
    cout << "4. View Cart" << endl;
    cout << "5. Remove Item from Cart" << endl;
    cout << "6. Checkout" << endl;
    cout << "7. View Shopper Details" << endl;
    cout << "Enter your choice: ";
}

/* Main function 
A. Main function to run the program
B. Create an instance of ProduceDepartment and create a shopper with a balance of $50
C. Display welcome message
D. Variable to store user choice and a boolean to control the loop
E. Loop to display menu and handle user input
F. Switch case to handle user choices
*/
//A. Main function to run the program
int main() {
    
    //B. Create an instance of ProduceDepartment and create a shopper with a balance of $50
    ProduceDepartment produce;
    Shopper shopper(50.00);
    
    //C. Display welcome message
    cout << "Welcome shopper to Bears Produce!!" << endl;
    cout << "Please choose from the following from 1-7 below with your available gift card balance of $50" << endl;
    
    //D. Variable to store user choice and a boolean to control the loop
    int choice;
    bool running = true;
    
    //E. Loop to display menu and handle user input
    while(running) {
        displayMenu();
        try {
            cin >> choice;
            cin.ignore();

            //F. Switch case to handle user choices
            switch(choice) {
                case 1: {
                    
                    cout << "Available items: " << endl;
                    cout << "Fruits:" << endl;
                    for (const string& fruit : produce.getFruitNames()) {
                        cout << "- " << fruit << endl;
                    }
                    cout << "\nVegetables:" << endl;
                    for (const string& vegetable : produce.getVegetableNames()) {
                        cout << "- " << vegetable << endl;
                    }
                    break;
                }
                case 2: {
                    
                    string item;
                    cout << "Enter the name of the item you want to search for: ";
                    getline(cin, item);
                    
                    Fruit* fruit = produce.findFruitByName(item);
                    if (fruit) {
                        cout << "Item found in fruits: " << fruit->toString() << endl;
                    } else {
                        Vegetable* veg = produce.findVegetableByName(item);
                        if (veg) {
                            cout << "Item found in vegetables: " << veg->toString() << endl;
                        } else {
                            cout << "Item not found." << endl;
                        }
                    }
                    break;
                }
                case 3: {
                    
                    string item;
                    cout << "Enter the name of the item you want to add to cart: ";
                    getline(cin, item);
                    
                    Fruit* fruit = produce.findFruitByName(item);
                    if (fruit) {
                        if (shopper.addItem(fruit)) {
                            cout << fruit->getName() << " added to cart." << endl;
                            cout << "Remaining balance: $" << fixed << setprecision(2) << shopper.getBalance() << endl;
                        } else {
                            cout << "Not enough balance to add this item." << endl;
                        }
                    } else {
                        Vegetable* veg = produce.findVegetableByName(item);
                        if (veg) {
                            if (shopper.addItem(veg)) {
                                cout << veg->getName() << " added to cart." << endl;
                                cout << "Remaining balance: $" << fixed << setprecision(2) << shopper.getBalance() << endl;
                            } else {
                                cout << "Not enough balance to add this item." << endl;
                            }
                        } else {
                            cout << "Item not found." << endl;
                        }
                    }
                    break;
                }
                case 4: {
                    
                    const vector<ProduceItem*>& cart = shopper.getCart();
                    if (cart.empty()) {
                        cout << "Your cart is empty." << endl;
                    } else {
                        cout << "Items in your cart:" << endl;
                        for (const auto& item : cart) {
                            cout << "- " << item->toString() << endl;
                        }
                        cout << "Total items: " << cart.size() << endl;
                        cout << "Remaining balance: $" << fixed << setprecision(2) << shopper.getBalance() << endl;
                    }
                    break;
                }
                case 5: {
                    
                    string item;
                    cout << "Enter the name of the item you want to remove from cart: ";
                    getline(cin, item);
                    
                    if (shopper.removeItem(item)) {
                        cout << item << " removed from cart." << endl;
                        cout << "Updated balance: $" << fixed << setprecision(2) << shopper.getBalance() << endl;
                    } else {
                        cout << "Item not found in cart." << endl;
                    }
                    break;
                }
                case 6: {
                   
                    if (shopper.getCart().empty()) {
                        cout << "Your cart is empty. Nothing to checkout." << endl;
                    } else {
                        shopper.getTotalAmount().displayTotal();
                        shopper.getTotalAmount().writeTotalToFile();
                        cout << "Thank you for shopping at Bears Produce!" << endl;
                        running = false;
                    }
                    break;
                }
                case 7: {
                    
                    shopper.displayDetails();
                    break;
                }
                default: {
                    throw invalid_argument("Invalid choice. Please enter a number between 1 and 7.");
                }
            }
        } catch (const exception& e) {
            cout << "Error: " << e.what() << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        
        if (running) {
            cout << "\nPress Enter to continue...";
            cin.get();
        }
    }
    
    return 0;
}