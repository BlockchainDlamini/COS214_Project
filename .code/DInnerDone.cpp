#include "DinnerDone.h"
void DinnerDone::execute(std::shared_ptr<Customer> context)
{
    context->changeMood();
    handleChange(context);
}
void DinnerDone::handleChange(std::shared_ptr<Customer> context)
{
    context->requestBill();
}

std::string DinnerDone::getName()
{
    return stateName;
}