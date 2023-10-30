#ifndef OrderReceived_H
#define OrderReceived_H

#include "OrderProcessState.h"
#include "DinnerDone.h"

/**
 * @class OrderReceived
 * @brief Represents the "Order Received" state in the order processing system.
 */
class OrderReceived : public OrderProcessState {
public:
    /**
     * @brief Constructor for creating an OrderReceived state.
     */
    OrderReceived() {
        stateName = "OrderReceived";
    }

    /**
     * @brief Execute the OrderReceived state.
     */
    void execute(std::shared_ptr<Customer> context);
    std::string getName();

    /**
     * @brief Handle a change in the state by moving to the next state.
     * @param context A shared pointer to the customer context.
     */
    void handleChange(std::shared_ptr<Customer> context);

    /**
     * @brief Get the current state as a shared pointer to a Customer.
     * @return A shared pointer to the current state.
     */
    std::shared_ptr<Customer> getState();
};

#endif
