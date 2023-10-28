/**
 * @file Waiter.h
 * @brief Defines the Waiter class, responsible for handling orders and interactions with customers and kitchen.
 */
#ifndef WAITER_H
#define WAITER_H

#include <string>
#include <vector>
#include <iostream>
#include "Customer.h"
#include "Kitchen.h"
#include "iterator.h"
#include "gameElement.h"
#include "table.h"
#include "Order.h"

using namespace std;

/**
 * @class Waiter
 * @brief Represents a waiter responsible for taking orders, delivering food, and processing payments.
 */
class Waiter : public gameElement {
public:
    /**
     * @param customer The customer to be dealt with.
     * @param order The order for the customer.
     */


    /**
     * @brief Take order from customer.
     */
    virtual void takeOrder(std::shared_ptr<Customer> customer, std::shared_ptr<Order> order) = 0;
    /**
     * @brief Take order to customer.
     */
    virtual void bringOrder(std::shared_ptr<Customer> customer, std::shared_ptr<Order> order) = 0;
    /**
     * @brief Communicates an order with the kitchen.
     */
    virtual void communicateWithKitchen(std::shared_ptr<Order> order) = 0;
    /**
     * @brief Get the order from the kitchen.
     */
    virtual void pickUpOrderFromKitchen(std::shared_ptr<Order> order) = 0;
    /**
     * @brief Processes the customers payment.
     */
    virtual void processPayment(std::shared_ptr<Customer> customer) = 0;


    /**
     * @brief Get, Set and changer for Mediator pattern.
     */
    virtual void get() = 0;
    virtual void changed() = 0;
    virtual void set() = 0;

    virtual ~Waiter() {};
};

#endif // WAITER_H
