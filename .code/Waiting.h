#ifndef Waiting_H
#define Waiting_H
#include "OrderProcessState.h"
#include "OrderReceived.h"
class Waiting : public OrderProcessState
{
public:
    Waiting()
    {
        stateName = "Waiting";
    }
    void execute();
    void handleChange();
    std::shared_ptr<Customer> getState();
};
#endif