/**
 * @file MakeTopping.h
 * @brief Contains the class declarations for the MakeTopping class, a subclass of MenuItemCommand, responsible for creating toppings for food items in the kitchen.
 * @bug No known bugs.
 */

#ifndef __MAKE_TOPPING_H__
#define __MAKE_TOPPING_H__

#include "MenuItemCommand.h"

/**
 * @class MakeTopping
 * @brief Represents the MakeTopping class, responsible for creating various toppings for food items in the kitchen.
 */
class MakeTopping : public MenuItemCommand, public enable_shared_from_this<MakeTopping> {
public:
    /**
     * @brief Constructor for the MakeTopping class.
     * @param state A shared pointer to the Kitchen where the toppings are created.
     */
    MakeTopping(std::shared_ptr<Kitchen> state);

    /**
     * @brief Execute the MakeTopping command, creating and returning a shared pointer to the FoodItem representing the topping.
     * @return A shared pointer to the created FoodItem object, which represents the topping.
     */
    std::shared_ptr<FoodItem> execute();
};

#endif
