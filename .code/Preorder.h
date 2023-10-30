#ifndef Preorder_H
#define Preorder_H

#include "OrderProcessState.h"
#include "Waiting.h"

/**
 * @class Preorder
 * @brief Represents the "Preorder" state in the order processing system.
 */
class Preorder : public OrderProcessState {
public:
    /**
     * @brief Constructor for creating a Preorder state.
     */
    Preorder() {
        stateName = "Preorder";
    }

    /**
     * @brief Execute the Preorder state.
     */
    void execute(std::shared_ptr<Customer> context);

    std::string getName();

    /**
     * @brief Handle a change in the state by moving to the next state.
     * @param context A shared pointer to the customer context.
     */
    void handleChange(std::shared_ptr<Customer> context);

    // You may want to add the missing documentation for the getState() function.
    // std::shared_ptr<Customer> getState();
};

#endif
