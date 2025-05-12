#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include "Fruit.h"
#include "Vegetable.h"

#ifndef PRODUCE_DEPARTMENT_H
#define PRODUCE_DEPARTMENT_H

using namespace std;

/* Produce Department Class for fruits and vegetables
A. Define a class representing the Produce Department
B. Declare vectors to store fruits and vegetables
C. Constructor to initialize the fruits and vegetables vectors with items
D. Function to add a fruit to the fruits vector
E. Function to add a vegetable to the vegetables vector
F. Function to retrieve the fruits vector
G. Function to retrieve the vegetables vector
H. Function to retrieve the names of all fruits
I. Function to retrieve the names of all vegetables
J. Function to find a fruit by name
K. Function to find a vegetable by name
*/
// A. Define a class representing the Produce Department
class ProduceDepartment {

    // B. Declare vectors to store fruits and vegetables
    private:
        vector<Fruit> fruits;
        vector<Vegetable> vegetables;
    
    public:
        // C. Constructor to initialize the fruits and vegetables vectors with items
        ProduceDepartment() {
            
            
            fruits.push_back(Fruit("Apple", 1.99, "lb", true));
            fruits.push_back(Fruit("Banana", 0.99, "count", false));
            fruits.push_back(Fruit("Orange", 2.50, "lb", true));
            fruits.push_back(Fruit("Strawberries", 2.50, "count", true));
            fruits.push_back(Fruit("Grapes", 2.00, "lb", true));
            fruits.push_back(Fruit("Pineapple", 3.00, "count", true));
            fruits.push_back(Fruit("Blueberries", 3.50, "count", true));
            fruits.push_back(Fruit("Blackberries", 3.50, "count", true));
            fruits.push_back(Fruit("Raspberries", 3.50, "count", true));
            fruits.push_back(Fruit("Watermelon", 5.00, "count", true));
            fruits.push_back(Fruit("Mango", 2.00, "count", true));
            fruits.push_back(Fruit("Kiwi", 1.75, "count", true));
            fruits.push_back(Fruit("Peaches", 1.80, "count", true));
            fruits.push_back(Fruit("Pears", 1.50, "count", true));
            fruits.push_back(Fruit("Plums", 1.50, "count", true));
            fruits.push_back(Fruit("Cherries", 3.00, "count", true));
            fruits.push_back(Fruit("Cantaloupe", 3.00, "count", true));
            fruits.push_back(Fruit("Honeydew", 3.00, "count", true));
            fruits.push_back(Fruit("Lemons", 0.75, "count", true));
            fruits.push_back(Fruit("Limes", 0.50, "count", true));
            fruits.push_back(Fruit("Grapefruit", 1.00, "count", true));
            fruits.push_back(Fruit("Tangerines", 1.50, "count", true));
            fruits.push_back(Fruit("Clementines", 1.50, "count", true));
            fruits.push_back(Fruit("Avocado", 1.50, "count", true));
            fruits.push_back(Fruit("Dragon Fruit", 5.00, "count", true));
    
        
            vegetables.push_back(Vegetable("Carrots", 1.00, "count", true));
            vegetables.push_back(Vegetable("Broccoli", 2.50, "count", true));
            vegetables.push_back(Vegetable("Spinach", 2.00, "count", true));
            vegetables.push_back(Vegetable("Tomatoes", 1.20, "lb", true));
            vegetables.push_back(Vegetable("Cucumbers", 1.50, "lb", true));
            vegetables.push_back(Vegetable("Potatoes", 1.50, "lb", true));
            vegetables.push_back(Vegetable("Onions", 1.50, "lb", true));
            vegetables.push_back(Vegetable("Bell Peppers", 2.00, "lb", true));
            vegetables.push_back(Vegetable("Lettuce", 1.75, "count", true));
            vegetables.push_back(Vegetable("Zucchini", 1.60, "lb", true));
            vegetables.push_back(Vegetable("Squash", 1.50, "lb", true));
            vegetables.push_back(Vegetable("Eggplant", 2.00, "lb", true));
            vegetables.push_back(Vegetable("Cauliflower", 2.50, "lb", true));
            vegetables.push_back(Vegetable("Green Beans", 1.80, "lb", true));
            vegetables.push_back(Vegetable("Cabbage", 1.50, "count", true));
            vegetables.push_back(Vegetable("Radishes", 1.00, "count", true));
            vegetables.push_back(Vegetable("Celery", 1.50, "count", true));
            vegetables.push_back(Vegetable("Asparagus", 3.00, "lb", true));
            vegetables.push_back(Vegetable("Brussels Sprouts", 2.50, "lb", true));
            vegetables.push_back(Vegetable("Mushrooms", 2.00, "count", true));
            vegetables.push_back(Vegetable("Sweet Potatoes", 1.50, "lb", true));
            vegetables.push_back(Vegetable("Corn", 1.00, "count", true));
            vegetables.push_back(Vegetable("Peas", 1.50, "lb", true));
            vegetables.push_back(Vegetable("Collard Greens", 2.00, "count", true));
        }
    
        // D. Function to add a fruit to the fruits vector
        void addFruit(const Fruit& fruit) {
            fruits.push_back(fruit);
        }
    
        // E. Function to add a vegetable to the vegetables vector
        void addVegetable(const Vegetable& vegetable) {
            vegetables.push_back(vegetable);
        }

        // F. Function to retrieve the fruits vector
        const vector<Fruit>& getFruits() const {
            return fruits;
        }
    
        // G. Function to retrieve the vegetables vector
        const vector<Vegetable>& getVegetables() const {
            return vegetables;
        }
    
        // H. Function to retrieve the names of all fruits
        vector<string> getFruitNames() const {
            vector<string> names;
            for (const Fruit& fruit : fruits) {
                names.push_back(fruit.toString());
            }
            return names;
        }
    
        // I. Function to retrieve the names of all vegetables
        vector<string> getVegetableNames() const {
            vector<string> names;
            for (const Vegetable& veg : vegetables) {
                names.push_back(veg.toString());
            }
            return names;
        }
    
        // J. Function to find a fruit by name
        Fruit* findFruitByName(const string& name) {
            for (Fruit& fruit : fruits) {
                if (fruit.getName() == name) {
                    return &fruit;
                }
            }
            return nullptr;
        }
    
        // K. Function to find a vegetable by name
        Vegetable* findVegetableByName(const string& name) {
            for (Vegetable& veg : vegetables) {
                if (veg.getName() == name) {
                    return &veg;
                }
            }
            return nullptr;
        }
};

#endif