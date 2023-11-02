#ifndef SAUCE_H
#define SAUCE_H

#include "FoodItem.h"

/**
 * @class Sauce
 * @brief A class representing a sauce, derived from FoodItem.
 *
 * This class is used to represent a type of sauce that can be used as a condiment or flavoring in food items.
 */
class Sauce : public FoodItem
{
public:
    /**
     * @brief Constructor for the Sauce class.
     * @param name The name of the sauce.
     * @param price The price of the sauce.
     */
    Sauce(string name, float price);
};

#endif
