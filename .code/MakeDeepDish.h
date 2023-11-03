/**
 * @file MakeDeepDish.h
 * @brief Contains the class declarations for the MakeDeepDish class, a subclass of MakeBase, responsible for creating a deep-dish crust for a food item in the kitchen.
 */

#ifndef __MAKE_DEEP_DISH_H__
#define __MAKE_DEEP_DISH_H__

#include "MakeChutneySauce.h"//BOBS ADDITION

/**
 * @class MakeDeepDish
 * @brief Represents the MakeDeepDish class, responsible for creating a deep-dish crust for a food item in the kitchen.
 */
class MakeDeepDish : public MakeBase {
public:
    /**
     * @brief Constructor for the MakeDeepDish class.
     * @param kitchen A shared pointer to the Kitchen where the deep-dish crust is created.
     */
    MakeDeepDish(std::shared_ptr<Kitchen> kitchen, string);
};

#endif
