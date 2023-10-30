#include "DinnerDone.h"
void DinnerDone::execute(Customer* context)
{
    context->changeMood();
    handleChange(context);
}
void DinnerDone::handleChange(Customer* context)
{
    
}

std::string DinnerDone::getName()
{
    return stateName;
}