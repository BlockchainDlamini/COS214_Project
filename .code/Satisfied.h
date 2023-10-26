#ifndef Satisfied_H
#define Satisfied_H
#include "EmotionState.h"
class Satisfied : public EmotionState
{
    Satisfied();
    // bool payBill();
    void handleChange(std::shared_ptr<Customer>);
    std::shared_ptr<Customer> getState();
    string getEmotion(){
        return emotion;
    };
    float getTip();
};
#endif
