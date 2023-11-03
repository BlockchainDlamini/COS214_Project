#include "PredefinedOrders.h"
using namespace std;

PredefinedOrders::PredefinedOrders() {
    headChef = make_shared<HeadChef>();
} 

void PredefinedOrders::makeMozzarellaPizza(int waiterID, string val) {
    vector<shared_ptr<FoodItem>> ingredients = {
        make_shared<Mozzarella>(),
        make_shared<ThinCrust>(val),
    };
    headChef->handleOrder(waiterID, ingredients);
}

void PredefinedOrders::makePepperoniPizza(int waiterID, string val) {
    vector<shared_ptr<FoodItem>> ingredients = {
        make_shared<Pepperoni>(),
        make_shared<ThinCrust>(val),
    };
    headChef->handleOrder(waiterID, ingredients);
}

void PredefinedOrders::makeCheesyPizza(int waiterID, string val) {
    vector<shared_ptr<FoodItem>> ingredients = {
        make_shared<Mozzarella>(),
        make_shared<Cheddar>(),
        make_shared<ThinCrust>(val),
    };
    headChef->handleOrder(waiterID, ingredients);
}

void PredefinedOrders::makeChickenDoubleDeckerPizza(int waiterID, string val) {
    vector<shared_ptr<FoodItem>> ingredients = {
        make_shared<DoubleDecker>(val),
        make_shared<Chicken>(),
    };
    headChef->handleOrder(waiterID, ingredients);
}