#ifndef Satisfied_H
#define Satisfied_H
#include "EmotionState.h"
class Satisfied : public EmotionState
{
    // bool payBill();
    void handleChange(std::shared_ptr<Customer>);
    std::shared_ptr<Customer> getState();
    float getTip();
};
#endif
