#include "Waiting.h"
void Waiting::execute(std::shared_ptr<Customer> context)
{
    context->changeMood();
    handleChange(context);
}

void Waiting::handleChange(std::shared_ptr<Customer> context)
{
    if (context->hasFood() == true && context->hasBill == false)
    {
        context->setOrderProcessState(make_shared<OrderReceived>());
    }
}

std::string Waiting::getName()
{
    return stateName;
}