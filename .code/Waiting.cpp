#include "Waiting.h"
void Waiting::execute()
{
}

void Waiting::handleChange(std::shared_ptr<Customer> context)
{
    context->setOrderProcessState(make_shared<OrderReceived>());
}