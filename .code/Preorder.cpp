#include "Preorder.h"
void Preorder::execute(Customer* context)
{
    context->changeMood();
    handleChange(context);
}
void Preorder::handleChange(Customer* context)
{
    if (context->hasOrdered == true && context->hasBill == false && context->hasFood == false)
    {
        context->setOrderProcessState(make_shared<Waiting>());
    }
}

std::string Preorder::getName()
{
    return stateName;
}