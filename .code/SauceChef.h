#ifndef SAUCECHEF_H
#define SAUCECHEF_H

#include "ToppingsChef.h"//BOBS ADDITION

/**
 * @class SauceChef
 * @brief A class representing a chef specialized in sauce-related dishes, derived from Kitchen.
 *
 * This class is responsible for preparing dishes that involve sauces as a primary ingredient or condiment.
 */
class SauceChef : public Kitchen
{
public:
    /**
     * @brief Constructor for the SauceChef class.
     */
    SauceChef();

    /**
     * @brief Handle an order for sauce-related dishes.
     * @param tableNumber The table number for the order.
     * @param commands A vector of shared pointers to MenuItemCommand objects representing the order.
     * @param foodItems A vector of shared pointers to FoodItem objects to work with.
     */
    void handleOrder(int, int, vector<shared_ptr<MenuItemCommand>>, vector<shared_ptr<FoodItem>>);

    /**
     * @brief Execute a MenuItemCommand related to sauce-related dishes.
     * @param command A shared pointer to the MenuItemCommand to execute.
     * @return A shared pointer to the resulting FoodItem after executing the command.
     */
    shared_ptr<FoodItem> execute(shared_ptr<MenuItemCommand> command);

    void displaySauceArt();
};

#endif
