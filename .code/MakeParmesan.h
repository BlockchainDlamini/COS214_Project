/**
 * @file MakeParmsan.h
 * @brief Contains the class declarations for the MakeParmsan class, a subclass of MakeCheese, responsible for creating a Mozzarella cheese topping for a food item in the kitchen.
 */

#ifndef __MAKE_PARMESAN_H__
#define __MAKE_PARMESAN_H__

#include "MakeOlives.h"//BOBS ADDITION

/**
 * @class MakeParmesan
 * @brief Represents the MakeParmesan class, responsible for creating a Mozzarella cheese topping for a food item in the kitchen.
 */
class MakeParmesan : public MakeCheese {
public:
    /**
     * @brief Constructor for the MakeParmesan class.
     * @param kitchen A shared pointer to the Kitchen where the Mozzarella cheese topping is created.
     */
    MakeParmesan(std::shared_ptr<Kitchen> kitchen);
};

#endif
