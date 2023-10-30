#include "OrderReceived.h"
void OrderReceived::execute(std::shared_ptr<Customer> context)
{
    context->changeMood();
    handleChange(context);
}

void OrderReceived::handleChange(std::shared_ptr<Customer> context)
{
    if (context->hasBill == true && context->hasFood() == true)
    {
        context->setOrderProcessState(make_shared<DinnerDone>());
    }
}
std::string OrderReceived::getName()
{
    return stateName;
}