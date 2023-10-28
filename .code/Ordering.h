#ifndef Ordering_H
#define Ordering_H

#include "OrderProcessState.h"

/**
 * @class Ordering
 * @brief A concrete class representing the ordering state of a customer's order process.
 */
class Ordering : public OrderProcessState {
public:
    /**
     * @brief Execute the actions associated with the ordering state.
     */
    void execute();

    /**
     * @brief Handle a change in the customer's order process state.
     * @param customer A shared pointer to the customer whose state is changing.
     */
    void handleChange(std::shared_ptr<Customer> customer);

    /**
     * @brief Get the current state of the customer.
     * @return A shared pointer to the customer.
     */
    std::shared_ptr<Customer> getState();
};

#endif
