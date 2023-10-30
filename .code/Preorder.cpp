#include "Preorder.h"
void Preorder::execute(std::shared_ptr<Customer> context)
{
    context->changeMood();
    handleChange(context);
}
void Preorder::handleChange(std::shared_ptr<Customer> context)
{
    if (context->hasFood() == false && context->hasBill == false)
    {
        context->setOrderProcessState(make_shared<Waiting>());
    }
}

std::string Preorder::getName()
{
    return stateName;
}