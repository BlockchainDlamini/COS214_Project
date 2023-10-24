#ifndef OrderProcessState_H
#define OrderProcessState_H
#include "Customer.h"
class Customer;
class OrderProcessState
{
private:
    std::shared_ptr<Customer> context;

public:
    virtual void execute();
    virtual void handleChange();
    virtual std::shared_ptr<Customer> getState();
};
#endif