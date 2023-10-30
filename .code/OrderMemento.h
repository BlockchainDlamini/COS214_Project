#ifndef OrderMemento_H
#define OrderMemento_H

#include "Order.h"
#include <memory>
#include <vector>

/**
 * @class OrderMemento
 * @brief Represents a memento for storing the state of an order.
 */
class OrderMemento : public enable_shared_from_this<OrderMemento>
{
private:
    std::vector<std::shared_ptr<MenuItemOrderCommand>> formula; /**< The list of menu item order commands in the order memento. */
    float price;                                                /**< The total price of the order memento. */
    int orderID;                                                /**< The unique order ID associated with the order memento. */

public:
    /**
     * @brief Constructor for creating an OrderMemento with a specified price, order ID, and list of menu item order commands.
     * @param price The total price of the order memento.
     * @param orderID The unique order ID associated with the order memento.
     * @param formula The list of menu item order commands in the order memento.
     */
    OrderMemento(int price, int orderID, std::vector<std::shared_ptr<MenuItemOrderCommand>> formula);
    OrderMemento(int price, std::vector<std::shared_ptr<MenuItemOrderCommand>> formula);

    /**
     * @brief Constructor for creating an OrderMemento from an existing OrderMemento object.
     * @param orderMemento A shared pointer to an existing OrderMemento object to create a new one from.
     */
    OrderMemento(std::shared_ptr<OrderMemento> orderMemento);

    /**
     * @brief Get the total price of the order memento.
     * @return The total price of the order memento.
     */
    float getPrice();

    /**
     * @brief Set the total price of the order memento.
     * @param price The total price to set.
     */
    void setPrice(float price);

    /**
     * @brief Get the unique order ID associated with the order memento.
     * @return The order ID.
     */
    int getID();

    /**
     * @brief Set the unique order ID associated with the order memento.
     * @param orderID The order ID to set.
     */
    void setID(int orderID);

    /**
     * @brief Get the list of menu item order commands in the order memento.
     * @return The list of menu item order commands.
     */
    std::vector<std::shared_ptr<MenuItemOrderCommand>> getToBePaid();

    /**
     * @brief Set the list of menu item order commands in the order memento.
     * @param formula The list of menu item order commands to set.
     */
    void setToBePaid(std::vector<std::shared_ptr<MenuItemOrderCommand>> formula);
};

#endif
