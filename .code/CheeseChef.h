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
     * This si the Constructor for the class
     */
    CheeseChef();

    /**
     * @brief Handle an order for cheese-based dishes.
     * @param tableNumber The table number for the order.
     * @param commands A vector of shared pointers to MenuItemCommand objects representing the order.
     * @param foodItems A vector of shared pointers to FoodItem objects to work with.4
     * This function function will take in orders and the respected cheff will pick the commands that belong to him 
     * or that only he knows how to prepare and passes on the remaining orders to the other chefs in the link
     */
    void handleOrder(int, int, vector<shared_ptr<MenuItemCommand>>, vector<shared_ptr<FoodItem>>);

    /**
     * @brief Execute a MenuItemCommand related to cheese-based dishes.
     * @param command A shared pointer to the MenuItemCommand to execute.
     * @return A shared pointer to the resulting FoodItem after executing the command.
     */
    shared_ptr<FoodItem> execute(MenuItemCommand*);

    /**
    * @brief This function displays the visual representation of Cheese which is a blocks of cheese in this case
    */
    void displayCheeseArt();
};

#endif
