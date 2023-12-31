#ifndef Waiting_H
#define Waiting_H

#include "OrderReceived.h"//BOBS ADDITION

/**
 * @class Waiting
 * @brief Represents the "Waiting" state in the order processing system.
 */
class Waiting : public OrderProcessState
{
public:
    /**
     * @brief Constructor for creating a Waiting state.
     */
    Waiting()
    {
        stateName = "Waiting";
    }

    /**
     * @brief Execute the Waiting state.
     */
    void execute(Customer* context);

    std::string getName();
    /**
     * @brief Handle a change in the state by moving to the next state.
     * @param context A shared pointer to the customer context.
     */
    void handleChange(Customer* context);

    /**
     * @brief Get the current state as a shared pointer to a Customer.
     * @return A shared pointer to the current state.
     */
    //std::shared_ptr<Customer> getState();
};

#endif
