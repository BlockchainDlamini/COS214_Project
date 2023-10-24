#ifndef OrderProcessState_H
#define OrderProcessState_H
#include "Customer.h"

class OrderProcessState
{
private:
    std::shared_ptr<Customer> context;

public:
    OrderProcessState(){};
    virtual void execute();
    virtual void handleChange(std::shared_ptr<Customer>);
    virtual std::shared_ptr<Customer> getState();
};
#endif
