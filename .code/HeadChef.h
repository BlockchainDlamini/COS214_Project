#ifndef __HEAD_CHEF_H__
#define __HEAD_CHEF_H__

#include "Kitchen.h"
#include "Pizza.h"
#include "FoodItem.h"
#include <queue>
#include <vector>
#include <memory>
using namespace std;

class HeadChef : public Kitchen {
    public: 
        HeadChef();
        void handleOrder(vector<shared_ptr<FoodItem>>);
        void bakePizza(vector<shared_ptr<FoodItem>>);
        shared_ptr<Pizza> getPizza();
    private:
        shared_ptr<Pizza> pizza;
        shared_ptr<Kitchen> next;
};

#endif