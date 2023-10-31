/**
 * @file MakeCheese.h
 * @brief Contains the class declarations for the MakeCheese class, a subclass of MenuItemCommand, responsible for creating a cheese topping for a food item in the kitchen.
 * @bug No known bugs.
 */

#ifndef __MAKE_CHEESE_H__
#define __MAKE_CHEESE_H__

#include "MenuItemCommand.h"

/**
 * @class MakeCheese
 * @brief Represents the MakeCheese class, responsible for creating a cheese topping for a food item in the kitchen.
 */
class MakeCheese : public MenuItemCommand {
public:
    /**
     * @brief Constructor for the MakeCheese class.
     * @param kitchen A shared pointer to the Kitchen where the cheese topping is created.
     */
    MakeCheese(std::shared_ptr<Kitchen> kitchen);
};

#endif
