#ifndef CHEESECHEFF_H
#define CHEESECHEFF_H
#include "SauceChef.h"
class CheeseChef :
    public Kitchen
{
public:
    CheeseChef(shared_ptr<Kitchen> ptr);
    void handleOrder(int, vector<shared_ptr<MenuItemCommand>>, vector<shared_ptr<FoodItem>>);
    shared_ptr<FoodItem> createFoodItem();
    shared_ptr<FoodItem> execute();
};
#endif

CheeseChef::CheeseChef(shared_ptr<Kitchen> ptr) :Kitchen(ptr){}
void CheeseChef::handleOrder(int id, vector<shared_ptr<MenuItemCommand>> orders, vector<shared_ptr<FoodItem>> foods)
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

shared_ptr<FoodItem> CheeseChef::createFoodItem()
{
    return make_shared<>();
}
shared_ptr<FoodItem> CheeseChef::execute()
{
    return createFoodItem();
}