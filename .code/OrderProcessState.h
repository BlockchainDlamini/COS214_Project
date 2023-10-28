#ifndef OrderProcessState_H
#define OrderProcessState_H
#include "Customer.h"
#include <iostream>
#include <memory>
#include <string>
using namespace std;
class Customer;
class OrderProcessState
{
protected:
    std::shared_ptr<Customer> context;

public:
    std::string stateName;
    OrderProcessState();
    virtual void execute() = 0;
    virtual void handleChange(std::shared_ptr<Customer> customer) = 0;
    // virtual std::shared_ptr<Customer> getState();
    void printStateChange();
};
#endif
