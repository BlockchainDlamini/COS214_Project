/**
 * @file MakeDoubleDecker.h
 * @brief Contains the class declarations for the MakeDoubleDecker class, a subclass of MakeBase, responsible for creating a double-decker crust for a food item in the kitchen.
 */

#ifndef __MAKE_DOUBLE_DECKER_H__
#define __MAKE_DOUBLE_DECKER_H__

#include "MakeBase.h"

/**
 * @class MakeDoubleDecker
 * @brief Represents the MakeDoubleDecker class, responsible for creating a double-decker crust for a food item in the kitchen.
 */
class MakeDoubleDecker : public MakeBase {
public:
    /**
     * @brief Constructor for the MakeDoubleDecker class.
     * @param kitchen A shared pointer to the Kitchen where the double-decker crust is created.
     */
    MakeDoubleDecker(std::shared_ptr<Kitchen> kitchen);

    /**
     * @brief Execute the MakeDoubleDecker command, creating and returning a shared pointer to the FoodItem representing the double-decker crust.
     * @return A shared pointer to the created FoodItem object.
     */
    std::shared_ptr<FoodItem> execute();
};

#endif
