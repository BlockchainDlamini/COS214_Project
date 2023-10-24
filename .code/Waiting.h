#ifndef Waiting_H
#define Waiting_H
#include "OrderProcessState.h"
class Waiting : public OrderProcessState
{
     void execute();
    void handleChange();
    std::shared_ptr<Customer> getState();
};
#endif