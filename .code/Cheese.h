#ifndef CHEESE_H
#define CHEESE_H

#include "Chutney.h"//BOBS ADDITION

/**
 * @class Cheese
 * @brief A class representing cheese, derived from FoodItem.
 *
 * This class is used to represent a type of cheese that can be used as a topping or ingredient in food items.
 */
class Cheese : public FoodItem
{
public:
    /**
     * @brief Constructor for the Cheese class.
     * @param name The name of the cheese.
     * @param price The price of the cheese.
     */
    Cheese(string name, float price);
};

#endif
