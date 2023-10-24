#ifndef Preorder_H
#define Preorder_H
#include "OrderProcessState.h"
class Preorder : public OrderProcessState
{
    void execute();
    void handleChange();
    std::shared_ptr<Customer> getState();
};
#endif