/**
 * @file MakeMushrooms.h
 * @brief Contains the class declarations for the MakeMushrooms class, a subclass of MakeTopping, responsible for creating mushroom toppings for a food item in the kitchen.
 */

#ifndef __MAKE_MUSHROOMS_H__
#define __MAKE_MUSHROOMS_H__

#include "MakeTopping.h"

/**
 * @class MakeMushrooms
 * @brief Represents the MakeMushrooms class, responsible for creating mushroom toppings for a food item in the kitchen.
 */
class MakeMushrooms : public MakeTopping {
public:
    /**
     * @brief Constructor for the MakeMushrooms class.
     * @param kitchen A shared pointer to the Kitchen where the mushroom toppings are created.
     */
    MakeMushrooms(std::shared_ptr<Kitchen> kitchen);
};

#endif
