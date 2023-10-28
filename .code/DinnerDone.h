#ifndef DinnerDone_H
#define DinnerDone_H
#include "OrderProcessState.h"
class DinnerDone : public OrderProcessState
{
public:
    DinnerDone()
    {
        stateName = "DinnerDone";
    }
    void execute();                                       // triggers the requestBill function in the customer
    void handleChange(std::shared_ptr<Customer> context); // moving to the next state
    std::shared_ptr<Customer> getState();
};
#endif