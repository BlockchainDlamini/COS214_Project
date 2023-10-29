#include "PredefinedOrders.h"
using namespace std;

PredefinedOrders::PredefinedOrders() {
    headChef = make_shared<HeadChef>();
} 
shared_ptr<Pizza> PredefinedOrders::makeMozzarellaPizza() {
    vector<shared_ptr<FoodItem>> ingredients = {
        make_shared<Mozzarella>(),
        make_shared<ThinCrust>(),
    };
    headChef->handleOrder(ingredients);
    return headChef->getPizza();
}

shared_ptr<Pizza> PredefinedOrders::makePepperoniPizza() {
    vector<shared_ptr<FoodItem>> ingredients = {
        make_shared<Pepperoni>(),
        make_shared<ThinCrust>(),
    };
    headChef->handleOrder(ingredients);
    return headChef->getPizza();
}

shared_ptr<Pizza> PredefinedOrders::makeCheesyPizza() {
    vector<shared_ptr<FoodItem>> ingredients = {
        make_shared<Mozzarella>(),
        make_shared<Cheddar>(),
        make_shared<ThinCrust>(),
    };
    headChef->handleOrder(ingredients);
    return headChef->getPizza();
}

shared_ptr<Pizza> PredefinedOrders::makeChickenDoubleDeckerPizza() {
    vector<shared_ptr<FoodItem>> ingredients = {
        make_shared<DoubleDecker>(),
        make_shared<Chicken>(),
    };
    headChef->handleOrder(ingredients);
    return headChef->getPizza();
}