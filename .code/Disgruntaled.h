#ifndef Disgruntaled_H
#define Disgruntaled_H
#include "EmotionState.h"
class Disgruntaled : public EmotionState
{

public:
    Disgruntaled();
    // bool payBill();
    void handleChange(std::shared_ptr<Customer>);
    std::shared_ptr<Customer> getState();
    string getEmotion()
    {
        return emotion;
    };
    float getTip();
};
#endif
