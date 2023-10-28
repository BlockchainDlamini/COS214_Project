#include "Preorder.h"
void Preorder::execute()
{
}
void Preorder::handleChange()
{
    context->setOrderProcessState(make_shared<Waiting>());
    
}