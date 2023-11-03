/**
 * @file RegularWaiter.h
 * @brief Defines the RegularWaiter class, responsible for serving tables and managing orders.
 */
#ifndef REGULARWAITER_H
#define REGULARWAITER_H


#include "Waiter.h"
//#include "Order.h"
//#include "Floor.h"

class Pizza;
class Floor;
class Order;
/**
 * @class RegularWaiter
 * @brief Represents a Regular Waiter responsible for serving tables and managing orders.
 */
class RegularWaiter :  public enable_shared_from_this<RegularWaiter>, public Waiter {
public:
    /**
    * @brief Constructor for the RegularWaiter class.
    * @param Id The unique identifier for the waiter.
    * @param assignedTables A vector of table identifiers assigned to the waiter.
    * @param floorObj A shared pointer to the floor object.
    */
    RegularWaiter(int Id, std::vector<int> assignedTables, shared_ptr<Floor> floorObj);
    
    /**
    * @brief Take an order from a table.
    * @param tableId The identifier of the table for which the order is being taken.
    */
    void takeOrder(int tableId);
    
    /**
    * @brief returns the orders to send to the mediator.
    * @return A pair with the waiters id and the vector of orders.
    */
    std::pair<int, std::vector<std::shared_ptr<Order>>> getForKitchen();
    
    /**
    * @brief Take an order to the table of customers.
    * @param pizzasForTable the vector of pizzas returned from the kitchen.
    */
    void takeOrderToTable(std::vector<std::shared_ptr<Pizza>> pizzasForTable);
    
    /**
    * @brief Deals with the customers and paying the bill.
    */
    void payBill(int tableId);

    /**
    * @brief Function for the mediator.
    */
    virtual string get();
    
    /**
    * @brief Function for the mediator.
    */
    void changed();
    
    /**
    * @brief Function for the mediator.
    * @param op To replace the "operation" string from the mediator.
    */
    void setOperation(string op);

    /**
    * @brief To return a vector of the tables a waiter is responsible for.
    * @return A vector of ints.
    */
    vector<int> getAssignedTables();

    /**
    * @brief Returns the latest list of pizzas.
    */
    void getPizzas();

    /**
    * @brief Create a shared pointer to a RegularWaiter.
    * @param Id The unique identifier for the waiter.
    * @param assignedTables A vector of table identifiers assigned to the waiter.
    * @param floorObj A shared pointer to the floor object.
    * @return A shared pointer to the created RegularWaiter.
    */
    static shared_ptr<RegularWaiter> createRegularWaiter(int Id, std::vector<int> assignedTables, shared_ptr<Floor> floorObj);
    
    /**
    * @brief Gets the waiter responsible for the table.
    * @param tableId The identifier of the table for which the waiter is responsible.
    * @return A shared pointer to the created RegularWaiter.
    */
    std::shared_ptr<RegularWaiter> waiterResponsible(int tableId);

    /**
    * @brief Get the unique identifier of the waiter.
    * @return The unique identifier of the waiter.
    */
    int getWaiterID();


private:
    shared_ptr<Floor> floorObject;
    std::vector<shared_ptr<Pizza>> pizzasForTable;
    int Id;
    std::vector<int> assignedTables;
    int tableID;
    std::vector<shared_ptr<Order>> ordersForATable;
    std::pair<int, std::vector<std::shared_ptr<Order>>> forKitchen;


    static std::vector<shared_ptr<RegularWaiter>> waiters;
};

#endif  // REGULARWAITER_H
