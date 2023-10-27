#include "HeadChef.h"
using namespace std;

HeadChef::HeadChef() {
    next = NULL;
}

void HeadChef::handleOrder(vector<shared_ptr<FoodItem>> order) {
    bakePizza(order);
}

void HeadChef::bakePizza(vector<shared_ptr<FoodItem>> order) {
    Pizza(order);
}

shared_ptr<Pizza> HeadChef::getPizza(){
    return pizza;
}

