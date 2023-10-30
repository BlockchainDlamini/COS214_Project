/**
 * @file MakeMozzarella.h
 * @brief Contains the class declarations for the MakeMozzarella class, a subclass of MakeCheese, responsible for creating a Mozzarella cheese topping for a food item in the kitchen.
 */

#ifndef __MAKE_MOZZARELLA_H__
#define __MAKE_MOZZARELLA_H__

#include "MakeCheese.h"

/**
 * @class MakeMozzarella
 * @brief Represents the MakeMozzarella class, responsible for creating a Mozzarella cheese topping for a food item in the kitchen.
 */
class MakeMozzarella : public MakeCheese {
public:
    /**
     * @brief Constructor for the MakeMozzarella class.
     * @param kitchen A shared pointer to the Kitchen where the Mozzarella cheese topping is created.
     */
    MakeMozzarella(std::shared_ptr<Kitchen> kitchen);

    /**
     * @brief Execute the MakeMozzarella command, creating and returning a shared pointer to the FoodItem representing the Mozzarella cheese topping.
     * @return A shared pointer to the created FoodItem object.
     */
    std::shared_ptr<FoodItem> execute();
};

#endif