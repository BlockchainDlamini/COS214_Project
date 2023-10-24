#ifndef Ordering_H
#define Ordering_H
#include "OrderProcessState.h"
class Ordering : public OrderProcessState
{
    void execute();
    void handleChange();
    std::shared_ptr<Customer> getState();
};
#endif