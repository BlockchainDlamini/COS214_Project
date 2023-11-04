#ifndef CHEESECHEFF_H
#define CHEESECHEFF_H

#include "SauceChef.h"//BOBS ADDITION
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
/**
 * @class CheeseChef
 * @brief A class representing a chef specialized in cheese-based dishes, derived from Kitchen.
 *
 * This class is used to represent a chef responsible for preparing dishes that involve cheese as a primary ingredient.
 */
class CheeseChef : public Kitchen
{
public:
    /**
     * @brief Constructor for the CheeseChef class.
     */
    CheeseChef();

    /**
     * @brief Handle an order for cheese-based dishes.
     * @param tableNumber The table number for the order.
     * @param commands A vector of shared pointers to MenuItemCommand objects representing the order.
     * @param foodItems A vector of shared pointers to FoodItem objects to work with.
     */
    void handleOrder(int, int, vector<shared_ptr<MenuItemCommand>>, vector<shared_ptr<FoodItem>>);

    /**
     * @brief Execute a MenuItemCommand related to cheese-based dishes.
     * @param command A shared pointer to the MenuItemCommand to execute.
     * @return A shared pointer to the resulting FoodItem after executing the command.
     */
    shared_ptr<FoodItem> execute(shared_ptr<MenuItemCommand> command);

    void displayCheeseArt();
};

#endif
