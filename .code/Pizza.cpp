/*@file Pizza.cpp
@brief contains the Pizza class
    *which is a subclass of FoodItem
    *and creates a pizza
*/
#include "Pizza.h"
using namespace std;

Pizza::Pizza(vector<shared_ptr<FoodItem>> component) {
    base = component[0];
    sauce = component[1];
    cheese = component[2];
    toppings = component[3];
}