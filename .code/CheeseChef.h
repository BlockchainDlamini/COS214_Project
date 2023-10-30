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
    shared_ptr<FoodItem> execute(shared_ptr<MenuItemCommand>);
};
#endif

CheeseChef::CheeseChef() :Kitchen(ptr) 
{ 
    nextChef = make_shared<ToppingsChef>(); 
}


void CheeseChef::handleOrder(int id, vector<shared_ptr<MenuItemCommand>> orders, vector<shared_ptr<FoodItem>> foods)
{
    for (vector<shared_ptr<MenuItemCommand>> it = orders.begin(); it != orders.end(); it++)
    {
        if (typeid(*(*it)) == typeid(MakeSauce))
        {
            foods.push_back((*it)->execute());
        }
    }
    nextChef->handleOrder(id, orders, foods);
}

shared_ptr<FoodItem> CheeseChef::execute(shared_ptr<MenuItemCommand> val)
{
    if (typeid(val) == typeid(MakeSweetChilli))
        return make_shared<SweetChilli>();
    else if (typeid(val) == typeid(MakeRanch))
        return make_shared<Ranch>();
    else if (typeid(val) == typeid(MakeTomatoPaste))
        return make_shared<TomatoPaste>();
    else if (typeid(val) == typeid(MakeChutney))
        return make_shared<Chutney>();
}