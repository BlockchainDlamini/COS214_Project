/**
 * @class KitchenInterface
 * @brief A class that represents the interface for the kitchen in the game.
 * @details This class is responsible for managing the kitchen operations in the game. It delegates orders to the chefs and collects the prepared orders.
 */
#ifndef __KITCHEN_INTERFACE_H__
#define __KITCHEN_INTERFACE_H__
#include "Mediator.h"
class KitchenInterface : public gameElement {
public: 
    /**
     * @brief Default constructor for KitchenInterface.
     */
    KitchenInterface();

    /**
     * @brief Get the reference to the Kitchen object.
     * @return Shared pointer to the Kitchen object.
     */
    std::shared_ptr<Kitchen> getKitchenReference();

    /**
     * @brief Collect the prepared order from the kitchen.
     * @return A pair containing the order ID and a vector of shared pointers to the prepared pizzas.
     */
    pair<int, std::vector<std::shared_ptr<pair<int, std::shared_ptr<Pizza>>>>> collectOrder();

    /**
     * @brief Delegate the order processing to the chefs.
     * @param order A pair containing the order ID and a vector of pairs with pizza ID and shared pointer to the Order object.
     */
    void delegateOrderProcess(pair<int, std::vector<pair<int, std::shared_ptr<Order>>>>);
    
    /**
     * @brief Get the ID of the waiter.
     * @return The ID of the waiter.
     */
    int getWaiterID();
private: 
    std::shared_ptr<ManagerChef> managerChef; 
    std::shared_ptr<HeadChef> headChef;
};

#endif
