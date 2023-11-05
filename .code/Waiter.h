/**
 * @file Waiter.h
 * @brief Defines the Waiter class, responsible for handling orders and interactions with customers and kitchen.
 */
#ifndef WAITER_H
#define WAITER_H

#include "findSpaceVisitor.h"//BOBS ADDITION

using namespace std;

/**
 * @class Waiter class
 * @brief Represents a waiter responsible for taking orders, delivering food, and processing payments.
 */
class Waiter : public enable_shared_from_this<Waiter>, public gameElement {
public:
    /**
     * @brief Get function for Mediator.
     * @details This function is used to get information from the Mediator.
     */
    virtual string get() = 0;

    /**
     * @brief Changed function for Mediator.
     * @details This function is called when the Mediator needs to notify the Waiter of a change.
     */
    //virtual void changed() = 0;

    /**
     * @brief Set function for Mediator.
     * @param op The operation to be performed by the Mediator.
     * @details This function is used to send a request to the Mediator with a specified operation.
     */
    virtual void setOperation(string op) = 0;

    /**
     * @brief Destructor for the Waiter class.
     * @details This virtual destructor is provided for proper cleanup when derived classes are destroyed.
     */
    virtual ~Waiter() {}
};

#endif // WAITER_H
