#include "Waiting.h"
void Waiting::execute(Customer *context)
{
    context->changeMood();
    handleChange(context);
}

void Waiting::handleChange(Customer *context)
{
    if (context->hasOrdered == true && context->hasFood == true && context->hasBill == false)
    {
        context->setOrderProcessState(make_shared<OrderReceived>());
    }
}

std::string Waiting::getName()
{
    return stateName;
}