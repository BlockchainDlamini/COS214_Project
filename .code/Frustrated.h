#ifndef Frustrated_H
#define Frustrated_H
#include "EmotionState.h"
#include <memory>
class Frustrated : public EmotionState
{
public:
    // bool payBill();
    Frustrated();
    void handleChange(std::shared_ptr<Customer>);
    //  std::shared_ptr<Customer> getState();
    string getEmotion()
    {
        return emotion;
    };
    float getTip();
};
#endif
