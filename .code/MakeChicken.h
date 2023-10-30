/**
 * @file MakeChicken.h
 * @brief Contains the class declarations for the MakeChicken class, a subclass of MakeTopping, responsible for creating a chicken topping for a food item in the kitchen.
 */

#ifndef __MAKE_CHICKEN_H__
#define __MAKE_CHICKEN_H__

#include "MakeTopping.h"

/**
 * @class MakeChicken
 * @brief Represents the MakeChicken class, responsible for creating a chicken topping for a food item in the kitchen.
 */
class MakeChicken : public MakeTopping {
public:
    /**
     * @brief Constructor for the MakeChicken class.
     * @param kitchen A shared pointer to the Kitchen where the chicken topping is created.
     */
    MakeChicken(std::shared_ptr<Kitchen> kitchen);

    /**
     * @brief Execute the MakeChicken command, creating and returning a shared pointer to the FoodItem representing the chicken topping.
     * @return A shared pointer to the created FoodItem object.
     */
    std::shared_ptr<FoodItem> execute();
};

#endif
