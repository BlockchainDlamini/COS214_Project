/**
 * @file MakePeppers.h
 * @brief Contains the class declarations for the MakePeppers class, a subclass of MakeTopping, responsible for creating pepper toppings for a food item in the kitchen.
 */

#ifndef __MAKE_PEPPERS_H__
#define __MAKE_PEPPERS_H__

#include "MakePepperoni.h"//BOBS ADDITION

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
};

#endif
