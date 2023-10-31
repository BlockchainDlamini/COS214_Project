/**
 * @file MakeBeef.h
 * @brief Contains the MakeBeef class, a subclass of MakeTopping, responsible for creating a beef topping for a food item in the kitchen.
 * @bug No known bugs.
 */

#ifndef __MAKE_BEEF_H__
#define __MAKE_BEEF_H__

#include "MakeTopping.h"

/**
 * @class MakeBeef
 * @brief Represents the MakeBeef class, responsible for creating a beef topping for a food item in the kitchen.
 */
class MakeBeef : public MakeTopping {
public:
    /**
     * @brief Constructor for the MakeBeef class.
     * @param kitchen A shared pointer to the Kitchen where the beef topping is created.
     */
    MakeBeef(std::shared_ptr<Kitchen> kitchen);
};

#endif
