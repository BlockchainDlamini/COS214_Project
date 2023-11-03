#ifndef TOPPINGS_H
#define TOPPINGS_H

#include "BlueCheese.h"//BOBS ADDITION

/**
 * @class Toppings
 * @brief A class representing toppings for food items, derived from FoodItem.
 *
 * This class is used to represent toppings that can be added to a food item, such as cheese, meats, or vegetables.
 */
class Toppings : public FoodItem
{
public:
    /**
     * @brief Constructor for the Toppings class.
     * @param name The name of the topping.
     * @param price The price of the topping.
     */
    Toppings(string name, float price);
};

#endif
