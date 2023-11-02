#ifndef BASECHEF_H
#define BASECHEF_H

#include "CheeseChef.h"

/**
 * @class BaseChef
 * @brief A class representing a chef specialized in base-related dishes, derived from Kitchen.
 *
 * This class is responsible for preparing dishes that involve different types of bases as primary components.
 */
class BaseChef : public Kitchen
{
public:
    /**
     * @brief Constructor for the BaseChef class.
     */
    BaseChef();

    /**
     * @brief Handle an order for dishes that involve bases.
     * @param tableNumber The table number for the order.
     * @param commands A vector of shared pointers to MenuItemCommand objects representing the order.
     * @param foodItems A vector of shared pointers to FoodItem objects to work with.
     */
    void handleOrder(int tableNumber, vector<shared_ptr<MenuItemCommand>> commands, vector<shared_ptr<FoodItem>> foodItems);

    /**
     * @brief Execute a MenuItemCommand related to dishes that involve bases.
     * @param val A shared pointer to the MenuItemCommand to execute.
     * @param parameter A string parameter for the command.
     * @return A shared pointer to the resulting FoodItem after executing the command.
     */
    shared_ptr<FoodItem> execute(shared_ptr<MenuItemCommand> val, string parameter);
};

#endif
