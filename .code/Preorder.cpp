#include "Preorder.h"
void Preorder::execute()
{
}
void Preorder::handleChange(std::shared_ptr<Customer> context)
{
    context->setOrderProcessState(make_shared<Waiting>());
    
}