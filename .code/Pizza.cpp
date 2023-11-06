/*@file Pizza.cpp
@brief contains the Pizza class
    *which is a subclass of FoodItem
    *and creates a pizza
*/
#include "Pizza.h"
using namespace std;


Pizza::Pizza() {
    price = 0;
}

float Pizza::getPrice() {
    return price;
}

string Pizza::getDescription() {
    string description ="";
    description += "ITEMS:\n";
    description += base->toString();
    for (shared_ptr<FoodItem> item : cheeseList) {
        description += item->toString();
    }
    for (shared_ptr<FoodItem> item : sauceList) {
        description += item->toString();
    }
    for (shared_ptr<FoodItem> item : toppingsList) {
        description += item->toString();
    }
    return description;
}
