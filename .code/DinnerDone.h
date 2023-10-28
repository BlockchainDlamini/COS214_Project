#ifndef DinnerDone_H
#define DinnerDone_H
#include "OrderProcessState.h"
class DinnerDone : public OrderProcessState
{
    public:
    DinnerDone(){
        stateName = "DinnerDone";
    }
    void execute(); // triggers the requestBill function in the customer
    void handleChange();// moving to the next state
    std::shared_ptr<Customer> getState();  
};
#endif