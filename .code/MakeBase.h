/**
 * @file MakeBase.h
 * @brief Contains the MakeBase class, a subclass of MenuItemCommand, responsible for creating a base for a food item in the kitchen.
 * @bug No known bugs.
 */

#ifndef __MAKE_BASE_H__
#define __MAKE_BASE_H__

#include "MenuItemCommand.h"//BOBS ADDITION

/**
 * @class MakeBase
 * @brief Represents the MakeBase class, responsible for creating a base for a food item in the kitchen.
 */
class MakeBase : public MenuItemCommand, public enable_shared_from_this<MakeBase> {
public:
    /**
     * @brief Constructor for the MakeBase class.
     * @param kitchen A shared pointer to the Kitchen where the base is created.
     */
    MakeBase(std::shared_ptr<Kitchen>, std::string);

    /**
     * @brief Execute the MakeBase command, creating and returning a shared pointer to the FoodItem representing the base.
     * @return A shared pointer to the created FoodItem object.
     */
    std::shared_ptr<FoodItem> execute();
private:
    std::string size;
};

#endif
