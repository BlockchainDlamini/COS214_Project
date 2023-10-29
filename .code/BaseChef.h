#ifndef BASECHEF_H
#define BASECHEF_H
#include "Kitchen.h"
class BaseChef :
    public Kitchen
{
    BaseChef(shared_ptr<Kitchen> ptr);
    void handleOrder(int, vector<shared_ptr<MenuItemCommand>>, vector<shared_ptr<FoodItem>>);
    shared_ptr<FoodItem> createFoodItem();
    shared_ptr<FoodItem> execute();
};
#endif

BaseChef::BaseChef(shared_ptr<Kitchen> ptr) :Kitchen(ptr)
{
}
void BaseChef::handleOrder(int id, vector<shared_ptr<MenuItemCommand>> orders, vector<shared_ptr<FoodItem>> foods)
{
    for (vector<shared_ptr<MenuItemCommand>> it = orders.begin(); it != orders.end(); it++)
    {
        if ((*it)->getReciever() == this)
        {
            foods.push_back((*it)->execute());
        }
    }
    nextChef->handleOrder(id, orders, foods);
}
shared_ptr<FoodItem> BaseChef::createFoodItem(string p)
{
    if (p == "Stuffed-crust")
        return make_shared<StuffedCrust>();
    else if (p == "Thin crust")
        return make_shared<ThinCrust>();
    else if (p == " Double-Decker")
        return make_shared<DoubleDecker>();
    else if (p == "Boiled")
        return make_shared<Boiled>();
    else if (p == "Deep-dish")
        return make_shared<DeepDish>();
}
shared_ptr<FoodItem> BaseChef::execute(string p)
{
    createFoodItem(p);
}