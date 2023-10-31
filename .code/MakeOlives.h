/**
 * @file MakeOlives.h
 * @brief Contains the class declarations for the MakeOlives class, a subclass of MakeTopping, responsible for creating olive toppings for a food item in the kitchen.
 */

#ifndef __MAKEOLIVES_H__
#define __MAKEOLIVES_H__

#include "MakeTopping.h"

/**
 * @class MakeOlives
 * @brief Represents the MakeOlives class, responsible for creating olive toppings for a food item in the kitchen.
 */
class MakeOlives : public MakeTopping {
public:
    /**
     * @brief Constructor for the MakeOlives class.
     * @param kitchen A shared pointer to the Kitchen where the olive toppings are created.
     */
    MakeOlives(std::shared_ptr<Kitchen> kitchen);
};

#endif
