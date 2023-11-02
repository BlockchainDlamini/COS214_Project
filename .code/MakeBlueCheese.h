/**
 * @file MakeBlueCheese.h
 * @brief Contains the class declarations for the MakeBlueCheese class, a subclass of MakeCheese, responsible for creating a blue cheese topping for a food item in the kitchen.
 */

#ifndef __MAKE_BLUECHEESE_H__
#define __MAKE_BLUECHEESE_H__

#include "MakeCheese.h"

/**
 * @class MakeBlueCheese
 * @brief Represents the MakeBlueCheese class, responsible for creating a blue cheese topping for a food item in the kitchen.
 */
class MakeBlueCheese : public MakeCheese {
public:
    /**
     * @brief Constructor for the MakeBlueCheese class.
     * @param kitchen A shared pointer to the Kitchen where the blue cheese topping is created.
     */
    MakeBlueCheese(std::shared_ptr<Kitchen> kitchen);
};

#endif
