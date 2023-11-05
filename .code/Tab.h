#ifndef Tab_H
#define Tab_H

#include "ManagerChef.h" //BOBS ADDITION

/**
 * @class Tab
 * @brief Represents a tab that stores a list of outstanding orders as OrderMementos.
 */
class Tab
{
private:
    std::vector<std::shared_ptr<OrderMemento>> tab;
    string ID; // unique id for customer
    string description;

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
     * @brief Set the identifier for an object.
     *
     * Use this function to set a unique identifier for an object, such as an entity or a record. The identifier should be a string that uniquely identifies the object.
     *
     * @param id The unique identifier to be associated with the object.
     */
    void setID(std::string id);

    /**
     * @brief Get the identifier of the object.
     *
     * This function retrieves the unique identifier associated with the object and returns it as a string. The identifier helps in distinguishing the object from others.
     *
     * @return The unique identifier of the object as a string.
     */
    std::string getID();

    /**
     * @brief Add an OrderMemento to the tab.
     * @param orderMemento A shared pointer to the OrderMemento to add.
     */
    void addOrder(std::shared_ptr<OrderMemento> orderMemento, string ID);

    /**
     * @brief Get the list of outstanding orders in the tab.
     * @return A vector of shared pointers to OrderMemento representing outstanding orders.
     */
    std::vector<std::shared_ptr<OrderMemento>> getTab();

    /**
     * @brief Get the total price of outstanding orders in the tab.
     * @return The total price of outstanding orders.
     */
    float getTotal();

    void setDescription(string d);

    bool checkID(string ID);
    /**
     * @brief Clear the tab by removing all outstanding orders.
     */
    void clearTab();
};

#endif
