#ifndef FOODITEM_H
#define FOODITEM_H

#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include "gameElement.h"

using namespace std;

/**
 * @class FoodItem
 * @brief A class representing a food item, derived from gameElement.
 *
 * This class is used to represent a food item, which may include various properties such as name and price.
 */
class FoodItem : public gameElement
{
protected:
    float price; /**< The price of the food item. */
    string name; /**< The name of the food item. */

public:
    /**
     * @brief Constructor for the FoodItem class.
     * @param name The name of the food item.
     * @param price The price of the food item.
     */
    FoodItem(string name, float price);

    /**
     * @brief Get the name of the food item.
     * @return The name of the food item.
     */
    string getName();

    /**
     * @brief Get the price of the food item.
     * @return The price of the food item.
     */
    float getPrice();

    /**
     * @brief Convert the food item to a string representation.
     * @return A string representation of the food item.
     */
    string toString();
};

#endif
