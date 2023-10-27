#include "Pizza.h"
using namespace std;

Pizza::Pizza(vector<shared_ptr<FoodItem>> component) {
    base = component[0];
    sauce = component[1];
    cheese = component[2];
    toppings = component[3];
}