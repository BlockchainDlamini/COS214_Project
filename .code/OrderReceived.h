#ifndef OrderReceived_H
#define OrderReceived_H
#include "OrderProcessState.h"
#include "DinnerDone.h"
class OrderReceived : public OrderProcessState
{
public:
    OrderReceived()
    {
        stateName = "OrderReceived";
    };
    void execute();
    void handleChange();
    std::shared_ptr<Customer> getState();
};
#endif