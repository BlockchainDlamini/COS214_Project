#ifndef OrderProcessState_H
#define OrderProcessState_H
#include "Customer.h"

class OrderProcessState
{
protected:
    std::shared_ptr<Customer> context;
    string stateName;

public:
    OrderProcessState(){};
    virtual void execute();
    virtual void handleChange(std::shared_ptr<Customer>);
    virtual std::shared_ptr<Customer> getState();
    void printStateChange()
    {
        cout << "Customer state has changed to " + stateName;
    };
};
#endif
