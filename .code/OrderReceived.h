#ifndef OrderReceived_H
#define OrderReceived_H
#include "OrderProcessState.h"
class OrderReceived : public OrderProcessState
{
     void execute();
    void handleChange();
    std::shared_ptr<Customer> getState();
};
#endif