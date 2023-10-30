#ifndef OrderProcessState_H
#define OrderProcessState_H

#include "Customer.h"
#include <iostream>
#include <memory>
#include <string>
using namespace std;

class Customer;

/**
 * @class OrderProcessState
 * @brief Abstract base class for representing various states in the order processing system.
 */
class OrderProcessState {
protected:
    std::shared_ptr<Customer> context;

public:
    std::string stateName;
   virtual std::string getName() = 0;

    /**
     * @brief Default constructor for OrderProcessState.
     */
    OrderProcessState();

    /**
     * @brief Execute the state-specific behavior.
     */
    virtual void execute(Customer* context) = 0;

    /**
     * @brief Handle a change in the state by moving to the next state.
     * @param customer A shared pointer to the customer context.
     */
    virtual void handleChange(Customer* customer) = 0;

    /**
     * @brief Print information about the state change.
     */
    void printStateChange();
};

#endif
