#ifndef __PIZZA_H_
#define __PIZZA_H_

#include "gameElement.h"
#include "FoodItem.h"
#include <vector>
using namespace std;

class Pizza : gameElement {
    public:
        Pizza();
        Pizza(vector<shared_ptr<FoodItem>>);
    private:
        shared_ptr<FoodItem> base;
        shared_ptr<FoodItem> cheese;
        shared_ptr<FoodItem> sauce; 
        shared_ptr<FoodItem> toppings;

};

#endif 