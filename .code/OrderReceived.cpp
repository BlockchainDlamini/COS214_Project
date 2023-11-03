#include "OrderReceived.h"
#include "Customer.h"
void OrderReceived::execute(Customer *context)
{
    context->changeMood();
    handleChange(context);
}

void OrderReceived::handleChange(Customer *context)
{
    context->requestBill();
    if (context->hasOrdered == true && context->hasBill == true && context->hasFood == true)
    {
        context->setOrderProcessState(make_shared<DinnerDone>());
    }
}
std::string OrderReceived::getName()
{
    return stateName;
}