#ifndef Order_H
#define Order_H

#include "OrderMemento.h" //BOBS ADDITION

/**
 * @class Order
 * @brief Represents an order placed by a customer.
 */
class Order : public enable_shared_from_this<Order>
{
private:
    std::vector<std::shared_ptr<MenuItemCommand>> formula; /**< The list of menu items in the order. */
    float price;                                           /**< The total price of the order. */
    int orderID;                                           /**< The unique identifier for the order.*/
public:
    /**
     * @brief Constructor for an order with a given order ID.
     * @param orderID The unique identifier for the order.
     */
    Order(int orderID);

    /**
     * @brief Constructor for an order with a given order ID and a list of menu item commands.
     * @param orderID The unique identifier for the order.
     * @param order A vector of shared pointers to menu item order commands.
     */
    Order(int orderID, std::vector<std::shared_ptr<MenuItemCommand>> order);

    /**
     * @brief Constructor for an order with a given price, order ID, and a list of menu item commands.
     * @param price The total price of the order.
     * @param orderID The unique identifier for the order.
     * @param order A vector of shared pointers to menu item order commands.
     */
    Order(float price, int orderID, std::vector<std::shared_ptr<MenuItemCommand>> order);

    /**
     * @brief Place the order.
     */
    // void placeOrder();

    /**
     * @brief Get the total price of the order.
     * @return The total price of the order.
     */
    float getPrice();

    /**
     * @brief Get the unique identifier for the order.
     * @return The order ID.
     */
    int getOrderID();

    /**
     * @brief Create a memento of the order's state.
     * @return A shared pointer to the order memento.
     */
    std::shared_ptr<OrderMemento> createOrderMemento();

    /**
     * @brief Set the state of the order from a memento.
     * @param memento A shared pointer to the order memento.
     */
    void setOrderMemento(std::shared_ptr<OrderMemento> memento);

    /**
     * @brief Add a menu item order command to the order.
     * @param command A shared pointer to the menu item order command.
     */
    void addMenuItemCommand(std::shared_ptr<MenuItemCommand> command);
    void addMenuItems(vector<shared_ptr<MenuItemCommand>> commands);
    /**
     * @brief Show the formula of the order as a string.
     * @return A string representation of the order's formula.
     */
    // string showFormula();
    /**
     * @brief Retrieve and display the order details as a string.
     *
     * Use this function to obtain the details of an order and return them as a formatted string. The string may include information about items, quantities, and additional order-specific details.
     *
     * @return A string containing the order details.
     */
    std::string showOrder();

    /**
     * @brief Set the price of the order.
     *
     * This function allows you to specify the total price of the order. The price should be a floating-point value representing the cost of the entire order.
     *
     * @param price The total price of the order.
     */
    void setPrice(float price);

    /**
     * @brief Get a collection of shared pointers to menu item commands.
     *
     * This function provides access to a collection of shared pointers to MenuItemCommand objects. These pointers represent a set of menu item commands associated with the order, allowing you to inspect and manipulate the order's contents.
     *
     * @return A vector of shared pointers to MenuItemCommand objects.
     */
    std::vector<std::shared_ptr<MenuItemCommand>> getFormula();
};

#endif
