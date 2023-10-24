#ifndef Disgruntaled_H
#define Disgruntaled_H
#include "EmotionState.h"
class Disgruntaled : public EmotionState
{
private:

public:
    //bool payBill();
    void handleChange(std::shared_ptr<Customer>);
    std::shared_ptr<Customer> getState();
    float getTip();
};
#endif
