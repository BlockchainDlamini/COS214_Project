/**
 * @file MakePeppers.h
 * @brief Contains the class declarations for the MakePeppers class, a subclass of MakeTopping, responsible for creating pepper toppings for a food item in the kitchen.
 */

#ifndef __MAKE_PEPPERS_H__
#define __MAKE_PEPPERS_H__

#include "MakeTopping.h"

/**
 * @class MakePeppers
 * @brief Represents the MakePeppers class, responsible for creating pepper toppings for a food item in the kitchen.
 */
class MakePeppers : public MakeTopping {
public:
    /**
     * @brief Constructor for the MakePeppers class.
     * @param kitchen A shared pointer to the Kitchen where the pepper toppings are created.
     */
    MakePeppers(std::shared_ptr<Kitchen> kitchen);

    /**
     * @brief Execute the MakePeppers command, creating and returning a shared pointer to the FoodItem representing the pepper toppings.
     * @return A shared pointer to the created FoodItem object.
     */
    std::shared_ptr<FoodItem> execute();
};

#endif
