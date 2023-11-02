#ifndef CHICKEN_H
#define CHICKEN_H

#include "Mushrooms.h"

/**
 * @class Chicken
 * @brief A class representing chicken topping, derived from Toppings.
 *
 * This class is used to represent a chicken topping that can be added to a food item.
 */
class Chicken : public Toppings
{
public:
    /**
     * @brief Constructor for the Chicken class.
     */
    Chicken();
};

#endif
