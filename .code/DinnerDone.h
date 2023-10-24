#ifndef DinnerDone_H
#define DinnerDone_H
#include "OrderProcessState.h"
class DinnerDone : public OrderProcessState
{
     void execute();
    void handleChange();
    std::shared_ptr<Customer> getState();
};
#endif