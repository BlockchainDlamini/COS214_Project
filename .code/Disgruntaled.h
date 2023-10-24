#ifndef Disgruntaled_H
#define Disgruntaled_H
#include "EmotionState.h"
class Disgruntaled : public EmotionState
{
     bool payBill();
    void handleChange();
    std::shared_ptr<Customer> getState();
};
#endif