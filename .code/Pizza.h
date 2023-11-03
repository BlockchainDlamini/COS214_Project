/**
 * @file Pizza.h
 * @brief Contains the class declaration for the Pizza class, a subclass of gameElement, responsible for creating a pizza for the player to eat.
 */

#ifndef __PIZZA_H_
#define __PIZZA_H_
#include "MakeTomatoPaste.h"//BOBS ADDITION

class HeadChef;

/**
 * @class Pizza
 * @brief Represents the Pizza class, responsible for creating and describing a pizza for the player to eat.
 */
class Pizza : gameElement {
public:
    /**
     * @brief Constructor for the Pizza class.
     */
    Pizza();

    /**
     * @brief Generates and returns a description of the pizza.
     * @return A string description of the pizza.
     */
    string getDescription();

    /**
     * @brief Returns the price of the pizza.
     * @return The price of the pizza as a float.
     */
    float getPrice();

    friend class HeadChef;

private:
    shared_ptr<FoodItem> base;
    list<shared_ptr<FoodItem>> cheeseList;
    list<shared_ptr<FoodItem>> sauceList; 
    list<shared_ptr<FoodItem>> toppingsList;
    float price;
};

#endif
