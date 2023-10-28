#include "DinnerDone.h"
void DinnerDone::execute(){
    context->requestBill();
}
void DinnerDone::handleChange(std::shared_ptr<Customer> context){

}

