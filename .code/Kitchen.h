#ifndef KITCHEN_H
#define KITCHEN_H

#include "Pizza.h"//BOBS ADDITION

/**
 * @class Kitchen
 * @brief A class representing a kitchen in a restaurant, derived from gameElement.
 *
 * This class serves as the base class for various kitchen-related classes and is responsible for handling orders and managing chefs in the kitchen.
 */
class MenuItemCommand;
class Order;

class Kitchen : public gameElement
{
protected:
    shared_ptr<Kitchen> nextChef; /**< A shared pointer to the next chef in the kitchen. */

public:
    /**
     * @brief Constructor for the Kitchen class.
     */
    Kitchen();

    /**
     * @brief Handle an order with a vector of food items.
     * @param tableNumber The table number for the order.
     * @param foodItems A vector of shared pointers to FoodItem objects representing the order.
     */
    virtual void handleOrder(int, int, vector<shared_ptr<FoodItem>>);

    /**
     * @brief Handle an order with a vector of MenuItemCommand objects and a vector of food items.
     * @param tableNumber The table number for the order.
     * @param commands A vector of shared pointers to MenuItemCommand objects representing the order.
     * @param foodItems A vector of shared pointers to FoodItem objects to work with.
     */
    virtual void handleOrder(int, int, vector<shared_ptr<MenuItemCommand>>, vector<shared_ptr<FoodItem>>);

    /**
     * @brief Handle an order with a pair containing an order number and a vector of orders.
     * @param orderInfo A pair containing the order number and a vector of shared pointers to Order objects.
     */
    virtual void handleOrder(pair<int, vector<pair<int, shared_ptr<Order>>>>);

    /**
     * @brief Check if all orders are complete.
     * @return true if all orders are complete, false otherwise.
     */
    virtual bool ordersComplete();

    /**
     * @brief Handle an order by order number.
     * @param orderNumber The order number to handle.
     */
    virtual void handleOrder(int orderNumber);

    /**
     * @brief Execute a MenuItemCommand.
     * @param command A shared pointer to the MenuItemCommand to execute.
     * @return A shared pointer to the resulting FoodItem after executing the command.
     */
    virtual shared_ptr<FoodItem> execute(shared_ptr<MenuItemCommand> command);

    /**
     * @brief Execute a MenuItemCommand with a specified string parameter.
     * @param command A shared pointer to the MenuItemCommand to execute.
     * @param parameter A string parameter for the command.
     * @return A shared pointer to the resulting FoodItem after executing the command.
     */
    virtual shared_ptr<FoodItem> execute(shared_ptr<MenuItemCommand> command, string parameter);

    /**
     * @brief Get the next chef in the kitchen.
     * @return A shared pointer to the next chef.
     */
    shared_ptr<Kitchen> getNextChef();

    /**
     * @brief Set the next chef in the kitchen.
     * @param chef A shared pointer to the next chef to set.
     */
    void setNextChef(shared_ptr<Kitchen> chef);

    virtual shared_ptr<Kitchen> cycle();
};

#endif