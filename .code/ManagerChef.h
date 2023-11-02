#ifndef MANAGERCHEF_H
#define MANAGERCHEF_H

#include "BaseChef.h"
#include <utility>

/**
 * @class ManagerChef
 * @brief A class representing a manager chef in the kitchen, derived from Kitchen and enable_shared_from_this.
 *
 * This class is responsible for managing orders and coordinating chefs in the kitchen.
 */
class ManagerChef : public Kitchen, public enable_shared_from_this<ManagerChef>
{
private:
    vector<shared_ptr<Order>> orders; /**< A vector of shared pointers to Order objects representing pending orders. */

public:
    /**
     * @brief Constructor for the ManagerChef class.
     */
    ManagerChef();

    /**
     * @brief Handle an order by order number.
     * @param orderNumber The order number to handle.
     */
    void handleOrder(int orderNumber);

    /**
     * @brief Handle a batch of orders with an order number and a vector of orders.
     * @param orderInfo A pair containing the order number and a vector of shared pointers to Order objects.
     */
    void handleOrder(pair<int, vector<shared_ptr<Order>>> orderInfo);

    /**
     * @brief Check if all orders are complete.
     * @return true if all orders are complete, false otherwise.
     */
    bool ordersComplete();

    /**
     * @brief Get a list of chefs under the management of this manager chef.
     * @return A vector of shared pointers to Kitchen objects representing chefs.
     */
    vector<shared_ptr<Kitchen>> getChefs();

    /**
     * @brief Perform a cycle of processing orders and coordinating chefs.
     */
    void cycle();
};

#endif
