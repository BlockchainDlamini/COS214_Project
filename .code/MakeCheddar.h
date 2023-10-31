/**
 * @file MakeCheddar.h
 * @brief Contains the class declarations for the MakeCheddar class, a subclass of MakeCheese, responsible for creating a cheddar cheese topping for a food item in the kitchen.
 */

#ifndef __MAKE_CHEDDAR_H__
#define __MAKE_CHEDDAR_H__

#include "MakeCheese.h"

/**
 * @class MakeCheddar
 * @brief Represents the MakeCheddar class, responsible for creating a cheddar cheese topping for a food item in the kitchen.
 */
class MakeCheddar : public MakeCheese {
public:
    /**
     * @brief Constructor for the MakeCheddar class.
     * @param kitchen A shared pointer to the Kitchen where the cheddar cheese topping is created.
     */
    MakeCheddar(std::shared_ptr<Kitchen> kitchen);
};

#endif
