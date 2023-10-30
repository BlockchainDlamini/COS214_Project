#include "SauceChef.h"

SauceChef::SauceChef(shared_ptr<Kitchen> ptr) :Kitchen(ptr) 
{
    nextChef = make_shared<HeadChef>();
}
void SauceChef::handleOrder(int id, vector<shared_ptr<MenuItemCommand>> orders, vector<shared_ptr<FoodItem>> foods)
{
    for (vector<shared_ptr<MenuItemCommand>> it = orders.begin(); it != orders.end(); it++)
    {
        if (typeid(*(*it)) == typeid(MakeSauce))
        {
            foods.push_back((*it)->execute(*it));
        }
    }
    nextChef->handleOrder(id, orders, foods);
}

shared_ptr<FoodItem> SauceChef::execute(shared_ptr<MenuItemCommand> val)
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