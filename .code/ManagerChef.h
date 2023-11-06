#ifndef MANAGERCHEF_H
#define MANAGERCHEF_H

#include "BaseChef.h"//BOBS ADDITION

/**
 * @class ManagerChef
 * @brief A class representing a manager chef in the kitchen, derived from Kitchen and enable_shared_from_this.
 *
 * This class is responsible for managing orders and coordinating chefs in the kitchen.
 */
class ManagerChef : public Kitchen, public enable_shared_from_this<ManagerChef>
{
private:
    vector<pair<int, shared_ptr<Order>>> orders; /**< A vector of shared pointers to Order objects representing pending orders. */

public:
    /**
     * @brief Constructor for the ManagerChef class.
     */
    ManagerChef();

    /**
     * @brief Handle an order by order number.
     * @param orderNumber The order number to handle.
     * This is function is the fucntion thats used when another order is in the list.
     * And is only called by the headChef after the headChef checks if there are anymore orders to be taken care of
     * if there are then this handler is called.
     */
    void handleOrder(int orderNumber);

    /**
     * @brief Handle a batch of orders with an order number and a vector of orders.
     * @param orderInfo A pair containing the order number and a vector of shared pointers to Order objects.
     * This is the handler function and its purpose is to handle all of the orders that come in from a wiater 
     * and is meant to pass the orders for each pizza and once the pizza is created depending if there are still orders remaining 
     * it will pass those remaining orders through to the other chefs.
     */
    void handleOrder(pair<int, vector<pair<int, shared_ptr<Order>>>>);
    /**
     * @brief Check if all orders are complete.
     * @return true if all orders are complete, false otherwise.
     */
    bool ordersComplete();

    /**
     * @brief Get a list of chefs under the management of this manager chef.
     * @return A vector of shared pointers to Kitchen objects representing chefs.
     * This function is used to get the chefs currently in the chain
     */
    vector<shared_ptr<Kitchen>> getChefs();

    /**
     * @brief Perform a cycle of processing orders and coordinating chefs.
     * This function is used to set circular linking in between the chain of resposibility
     */
    shared_ptr<Kitchen> cycle();
};

#endif
