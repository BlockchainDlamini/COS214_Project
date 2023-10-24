#ifndef Happy_H
#define Happy_H
#include "EmotionState.h"
class Happy : public EmotionState
{
    //bool payBill();
    void handleChange(std::shared_ptr<Customer>);
    std::shared_ptr<Customer> getState();
    float getTip();
};
#endif
