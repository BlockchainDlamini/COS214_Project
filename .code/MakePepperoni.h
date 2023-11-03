/**
 * @file MakePepperoni.h
 * @brief Contains the class declarations for the MakePepperoni class, a subclass of MakeTopping, responsible for creating a pepperoni topping for a food item in the kitchen.
 */

#ifndef __MAKE_PEPPERONI_H__
#define __MAKE_PEPPERONI_H__

#include "MakeParmesan.h"//BOBS ADDITION

/**
 * @class MakePepperoni
 * @brief Represents the MakePepperoni class, responsible for creating a pepperoni topping for a food item in the kitchen.
 */
class MakePepperoni : public MakeTopping {
public:
    /**
     * @brief Constructor for the MakePepperoni class.
     * @param kitchen A shared pointer to the Kitchen where the pepperoni topping is created.
     */
    MakePepperoni(std::shared_ptr<Kitchen> kitchen);
};

#endif
