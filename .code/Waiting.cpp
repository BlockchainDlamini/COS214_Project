#include "Waiting.h"
void Waiting::execute()
{
}

void Waiting::handleChange()
{
    context->setOrderProcessState(make_shared<OrderReceived>());
}