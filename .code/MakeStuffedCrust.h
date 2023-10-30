/**
 * @file MakeStuffedCrust.h
 * @brief Contains the class declarations for the MakeStuffedCrust class, a subclass of MakeBase, responsible for creating a stuffed crust for a food item in the kitchen.
 */

#ifndef __MAKE_STUFFED_CRUST_H__
#define __MAKE_STUFFED_CRUST_H__

#include "MakeBase.h"

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
    MakeStuffedCrust(std::shared_ptr<Kitchen> kitchen);

    /**
     * @brief Execute the MakeStuffedCrust command, creating and returning a shared pointer to the FoodItem representing the stuffed crust.
     * @return A shared pointer to the created FoodItem object.
     */
    std::shared_ptr<FoodItem> execute();
};

#endif
