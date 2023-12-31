/**
 * @file MakeStuffedCrust.h
 * @brief Contains the class declarations for the MakeStuffedCrust class, a subclass of MakeBase, responsible for creating a stuffed crust for a food item in the kitchen.
 */

#ifndef __MAKE_STUFFED_CRUST_H__
#define __MAKE_STUFFED_CRUST_H__

#include "MakeRanch.h"//BOBS ADDITION

/**
 * @class MakeStuffedCrust
 * @brief Represents the MakeStuffedCrust class, responsible for creating a stuffed crust for a food item in the kitchen.
 */
class MakeStuffedCrust : public MakeBase {
public:
    /**
     * @brief Constructor for the MakeStuffedCrust class.
     * @param kitchen A shared pointer to the Kitchen where the stuffed crust is created.
     */
    MakeStuffedCrust(std::shared_ptr<Kitchen> kitchen, string);
};

#endif
