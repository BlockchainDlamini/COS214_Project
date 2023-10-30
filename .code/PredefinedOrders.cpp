#include "PredefinedOrders.h"
using namespace std;

PredefinedOrders::PredefinedOrders() {
    headChef = make_shared<HeadChef>();
} 

void PredefinedOrders::makeMozzarellaPizza(int waiterID) {
    vector<shared_ptr<FoodItem>> ingredients = {
        make_shared<Mozzarella>(),
        make_shared<ThinCrust>(),
    };
    headChef->handleOrder(waiterID, ingredients);
}

void PredefinedOrders::makePepperoniPizza(int waiterID) {
    vector<shared_ptr<FoodItem>> ingredients = {
        make_shared<Pepperoni>(),
        make_shared<ThinCrust>(),
    };
    headChef->handleOrder(waiterID, ingredients);
}

void PredefinedOrders::makeCheesyPizza(int waiterID) {
    vector<shared_ptr<FoodItem>> ingredients = {
        make_shared<Mozzarella>(),
        make_shared<Cheddar>(),
        make_shared<ThinCrust>(),
    };
    headChef->handleOrder(waiterID, ingredients);
}

void PredefinedOrders::makeChickenDoubleDeckerPizza(int waiterID) {
    vector<shared_ptr<FoodItem>> ingredients = {
        make_shared<DoubleDecker>(),
        make_shared<Chicken>(),
    };
    headChef->handleOrder(waiterID, ingredients);
}