#ifndef BASECHEF_H
#define BASECHEF_H

/**
 * @file BaseChef.h
 * @brief Declaration of the BaseChef class.
 */

 // Include necessary headers
#include "CheeseChef.h" // BOBS ADDITION
#include <vector>
#include <memory>

/**
 * @class BaseChef
 * @brief Represents a chef in the kitchen.
 *
 * The BaseChef class is a part of a larger kitchen management system.
 * It is the base class from which other chef classes inherit. It provides
 * common functionality and serves as a foundation for more specialized chefs.
 */
class BaseChef :
    public Kitchen
{
public:
    /**
     * @brief Constructor for the BaseChef class.
     */
    BaseChef();

    /**
     * @brief Handle an order.
     *
     * This function is responsible for handling an order by processing
     * a list of MenuItemCommand objects and a list of FoodItem objects.
     *
     * @param tableNumber The number of the table placing the order.
     * @param orderNumber The order number.
     * @param commands A vector of shared pointers to MenuItemCommand objects.
     * @param foodItems A vector of shared pointers to FoodItem objects.
     */
    void handleOrder(int tableNumber, int orderNumber, std::vector<std::shared_ptr<MenuItemCommand>> commands, std::vector<std::shared_ptr<FoodItem>> foodItems);

    /**
     * @brief Execute a menu item command.
     *
     * This function executes a menu item command and returns a shared pointer
     * to a FoodItem.
     *
     * @param command The MenuItemCommand to execute.
     * @param specialInstructions Special instructions for preparing the food.
     * @return A shared pointer to the prepared FoodItem.
     */
    std::shared_ptr<FoodItem> execute(MenuItemCommand* command, std::string specialInstructions);

    /**
     * @brief Display the base chef's art or information.
     */
    void displayBaseArt();
};

#endif
