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
    pizza = make_shared<Pizza>();
    for (shared_ptr<Base> item : order) {
        addBase(item);
        pizza->price += item->getPrice();
    } 
    for (shared_ptr<Toppings> item : order) {
        addTopping(item);
        pizza->price += item->getPrice();
    } 
    for (shared_ptr<Sauce> item : order) {
        addSauce(item);
        pizza->price += item->getPrice();

    }
    for (shared_ptr<Cheese> item : order) {
        addCheese(item);
        pizza->price += item->getPrice();
    }
}

void HeadChef::addTopping(shared_ptr<FoodItem> item) {
    pizza->toppingsList->insert(item);
}

void HeadChef::addSauce(shared_ptr<FoodItem> item) {
    pizza->sauce->insert(item);
}

void HeadChef::addBase(shared_ptr<FoodItem> item) {
    pizza->base = item;
}

void HeadChef::addCheese(shared_ptr<FoodItem> item) {
    pizza->cheese->insert(item);
}

shared_ptr<Pizza> HeadChef::getPizza() {
    return pizza;
}

