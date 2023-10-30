/**
 * @file MakeSauce.h
 * @brief Contains the class declarations for the MakeSauce class, a subclass of MenuItemCommand, responsible for creating a sauce for a food item in the kitchen.
 * @bug No known bugs.
 */

#ifndef __MAKE_SAUCE_H__
#define __MAKE_SAUCE_H__

#include "MenuItemCommand.h"

/**
 * @class MakeSauce
 * @brief Represents the MakeSauce class, responsible for creating sauce toppings for food items in the kitchen.
 */
class MakeSauce : public MenuItemCommand {
public:
    /**
     * @brief Constructor for the MakeSauce class.
     * @param state A shared pointer to the Kitchen where the sauce is created.
     */
    MakeSauce(std::shared_ptr<Kitchen> state);

    /**
     * @brief Execute the MakeSauce command, creating and returning a shared pointer to the FoodItem representing the sauce topping.
     * @return A shared pointer to the created FoodItem object, which represents the sauce topping.
     */
    std::shared_ptr<FoodItem> execute();
};

#endif
