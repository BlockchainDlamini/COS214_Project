#ifndef Tab_H
#define Tab_H

#include "OrderMemento.h"
#include <string>
#include <memory>

/**
 * @class Tab
 * @brief Represents a tab that stores a list of outstanding orders as OrderMementos.
 */
class Tab {
private:
    std::vector<std::shared_ptr<OrderMemento>> tab;

public:
    /**
     * @brief Constructor to create an empty tab.
     */
    Tab();

    /**
     * @brief Get a string representing the list of outstanding orders in the tab.
     * @return A string representing the outstanding orders.
     */
    std::string listOutstandingOrders();

    /**
     * @brief Check if the customer has paid their tab.
     * @return True if the customer has paid the tab, false otherwise.
     */
    bool payOrder();

    /**
     * @brief Add an OrderMemento to the tab.
     * @param orderMemento A shared pointer to the OrderMemento to add.
     */
    void addOrder(std::shared_ptr<OrderMemento> orderMemento);

    /**
     * @brief Get the list of outstanding orders in the tab.
     * @return A vector of shared pointers to OrderMemento representing outstanding orders.
     */
    std::vector<std::shared_ptr<OrderMemento>> getTab();

    /**
     * @brief Get the total price of outstanding orders in the tab.
     * @return The total price of outstanding orders.
     */
    int getTotal();

    /**
     * @brief Clear the tab by removing all outstanding orders.
     */
    void clearTab();
};

#endif
