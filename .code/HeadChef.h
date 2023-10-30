/**
 * @file HeadChef.h
 * @brief Contains the HeadChef class, a subclass of Kitchen, responsible for creating pizza in the kitchen.
 * @bug No known bugs.
 */

#ifndef __HEAD_CHEF_H__
#define __HEAD_CHEF_H__

#include "Kitchen.h"
#include "Pizza.h"
#include "FoodItem.h"
#include "Toppings.h"
#include "Base.h"
#include "Cheese.h"
#include "Sauce.h"
#include <utility>
#include <vector>
#include <memory>
using namespace std;

/**
 * @class HeadChef
 * @brief Represents the HeadChef class, responsible for creating pizzas.
 */
class HeadChef : public Kitchen {
public:
    /**
     * @brief Constructor for the HeadChef class.
     */
    HeadChef();

    /**
     * @brief Bake a pizza using the provided food items.
     *        Implements the Builder Pattern to define pizza construction.
     * @param foodItems A vector of shared pointers to FoodItem objects.
     * @return A shared pointer to the created Pizza object.
     */
    shared_ptr<Pizza> bakePizza(vector<shared_ptr<FoodItem>> foodItems);

    /**
     * @brief Add a topping to a pizza.
     * @param pizza A shared pointer to the Pizza object.
     * @param topping A shared pointer to the FoodItem representing the topping.
     */
    void addTopping(shared_ptr<Pizza> pizza, shared_ptr<FoodItem> topping);

    /**
     * @brief Add a sauce to a pizza.
     * @param pizza A shared pointer to the Pizza object.
     * @param sauce A shared pointer to the FoodItem representing the sauce.
     */
    void addSauce(shared_ptr<Pizza> pizza, shared_ptr<FoodItem> sauce);

    /**
     * @brief Add a base to a pizza.
     * @param pizza A shared pointer to the Pizza object.
     * @param base A shared pointer to the FoodItem representing the pizza base.
     */
    void addBase(shared_ptr<Pizza> pizza, shared_ptr<FoodItem> base);

    /**
     * @brief Add cheese to a pizza.
     * @param pizza A shared pointer to the Pizza object.
     * @param cheese A shared pointer to the FoodItem representing the cheese.
     */
    void addCheese(shared_ptr<Pizza> pizza, shared_ptr<FoodItem> cheese);

    /**
     * @brief Send the prepared pizza to the next stage or chef.
     */
    void sendPizza();

private:
    pair<int, vector<shared_ptr<Pizza>>> pizzas; // A data member to store pizzas.
    shared_ptr<Kitchen> nextChef; // A pointer to the next chef in the process.
};

#endif
