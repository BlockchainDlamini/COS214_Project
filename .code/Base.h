#ifndef BASE_H
#define BASE_H

#include "Peppers.h"//BOBS ADDITION

/**
 * @class Base
 * @brief A class representing a base food item, derived from FoodItem.
 *
 * This class is used to represent a base food item, such as a pizza crust or a burger bun.
 */
class Base : public FoodItem
{
public:
    /**
     * @brief Constructor for the Base class.
     * @param name The name of the base.
     * @param price The price of the base.
     * @param size The size of the base.
     */
    Base(string name, float price, string size);

private:
    string size; /**< The size of the base. */
};

#endif
