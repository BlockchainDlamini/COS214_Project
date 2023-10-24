#ifndef Frustrated_H
#define Frustrated_H
#include "EmotionState.h"
class Frustrated : public EmotionState
{
    //bool payBill();
    void handleChange(std::shared_ptr<Customer>);
    std::shared_ptr<Customer> getState();
    float getTip();
};
#endif
