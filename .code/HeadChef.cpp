/*@file HeadChef.cpp
    *@brief contains the HeadChef class
    *       which is a subclass of Kitchen
    *       and creates a pizza
    *@bug No known bugs.
*/

#include "HeadChef.h"
using namespace std;

HeadChef::HeadChef() {
    next = NULL;
}

void HeadChef::handleOrder(vector<shared_ptr<FoodItem>> order) {
    bakePizza(order);
}

void HeadChef::bakePizza(vector<shared_ptr<FoodItem>> order) {
    pizza = make_shared<Pizza>(order);
}

shared_ptr<Pizza> HeadChef::getPizza(){
    return pizza;
}

