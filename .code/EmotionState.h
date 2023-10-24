#ifndef EmotionState_H
#define EmotionState_H
#include "Customer.h"
class Customer;
class EmotionState
{
private:
    std::shared_ptr<Customer> context;

public:
    virtual bool payBill() = 0;
    virtual void handleChange() = 0;
    virtual std::shared_ptr<Customer> getState() = 0;
};
#endif