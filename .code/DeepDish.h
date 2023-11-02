#ifndef DEEPDISH_H
#define DEEPDISH_H

#include "Boiled.h"

/**
 * @class DeepDish
 * @brief A class representing a deep dish base, derived from Base.
 *
 * This class is used to represent a deep dish-style base for food items, which is typically associated with certain types of dishes.
 */
class DeepDish : public Base
{
public:
    /**
     * @brief Constructor for the DeepDish class.
     * @param name The name of the deep dish base.
     */
    DeepDish(string name);
};

#endif
