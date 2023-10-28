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
     * @brief Get, Set and changer for Mediator
     */
    virtual void get() = 0;
    virtual void changed() = 0;
    virtual void set(string op) = 0;

    virtual ~Waiter() {};
};

#endif // WAITER_H
