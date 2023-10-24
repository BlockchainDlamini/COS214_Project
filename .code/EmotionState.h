#ifndef EmotionState_H
#define EmotionState_H
#include "Customer.h"

class EmotionState
{
private:
    std::shared_ptr<Customer> context;

public:
    EmotionState(){};
    virtual bool payBill() = 0;
    virtual void handleChange(std::shared_ptr<Customer>) = 0;
    virtual std::shared_ptr<Customer> getState() = 0;
};
#endif
