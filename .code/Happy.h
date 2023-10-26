#ifndef Happy_H
#define Happy_H
#include "EmotionState.h"
class Happy : public EmotionState
{
    Happy();
    //bool payBill();
    void handleChange(std::shared_ptr<Customer>);
    std::shared_ptr<Customer> getState();
    string getEmotion(){
        return emotion;
    };
    float getTip();
};
#endif
