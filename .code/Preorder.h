#ifndef Preorder_H
#define Preorder_H
#include "OrderProcessState.h"
#include "Waiting.h"
class Preorder : public OrderProcessState
{
public:
    Preorder()
    {
        stateName = "Preorder";
    }
    void execute();
    void handleChange();
    std::shared_ptr<Customer> getState();
};
#endif