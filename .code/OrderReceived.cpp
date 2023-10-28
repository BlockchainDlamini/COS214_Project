#include "OrderReceived.h"
void OrderReceived::execute(){

}

void OrderReceived::handleChange(){
    context->setOrderProcessState(make_shared<DinnerDone>());
}