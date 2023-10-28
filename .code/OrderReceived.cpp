#include "OrderReceived.h"
void OrderReceived::execute(){

}

void OrderReceived::handleChange(std::shared_ptr<Customer> context){
    context->setOrderProcessState(make_shared<DinnerDone>());
}