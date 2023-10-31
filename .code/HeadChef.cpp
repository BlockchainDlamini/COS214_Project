/*@file HeadChef.cpp
    *@brief contains the HeadChef class
    *       which is a subclass of Kitchen
    *       and creates a pizza
    *@bug No known bugs.
*/
#include "HeadChef.h"
using namespace std;

HeadChef::HeadChef() : Kitchen() {
    nextChef = nullptr;
}

void HeadChef::handleOrder(int waiterID, vector<shared_ptr<FoodItem>> order) {
    bakePizza(order);
    pizzas.first = waiterID;
    pizzas.second.push_back(bakePizza(order));
    while (!nextChef->ordersComplete()) 
        nextChef->handleOrder(waiterID);
    setOperation("COLLECTORDER");
    changed();
    //send the pizza out be sent to waiter ask Hamza again
}

shared_ptr<Pizza> HeadChef::bakePizza(vector<shared_ptr<FoodItem>> order) {
    shared_ptr<Pizza> pizza = make_shared<Pizza>();
    for (shared_ptr<FoodItem> item : order) {
        if (typeid(item) == typeid(Base)) {
            addBase(pizza, item);
            pizza->price += item->getPrice();
        }
    } 
    for (shared_ptr<FoodItem> item : order) {
        if (typeid(item) == typeid(Toppings)) {
            addTopping(pizza, item);
            pizza->price += item->getPrice();
        }
    } 
    for (shared_ptr<FoodItem> item : order) {
        if (typeid(item) == typeid(Sauce)) {
            addSauce(pizza, item);
            pizza->price += item->getPrice();
        }
    }
    for (shared_ptr<FoodItem> item : order) {
        if (typeid(item) == typeid(Cheese)) {
            addCheese(pizza, item);
            pizza->price += item->getPrice();
        }
    }
    return pizza;
}

void HeadChef::addTopping(shared_ptr<Pizza> pizza, shared_ptr<FoodItem> item) {
    pizza->toppingsList.push_back(item);
}

void HeadChef::addSauce(shared_ptr<Pizza> pizza, shared_ptr<FoodItem> item) {
    pizza->sauceList.push_back(item);
}

void HeadChef::addBase(shared_ptr<Pizza> pizza, shared_ptr<FoodItem> item) {
    pizza->base = item;
}

void HeadChef::addCheese(shared_ptr<Pizza> pizza, shared_ptr<FoodItem> item) {
    pizza->cheeseList.push_back(item);
}

int HeadChef::getWaiterID() {
    return pizzas.first;
}

vector<shared_ptr<Pizza>> HeadChef::getPizzas() {
    return pizzas.second;
}
