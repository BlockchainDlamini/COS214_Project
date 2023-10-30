#include "SauceChef.h"

SauceChef::SauceChef(shared_ptr<Kitchen> ptr) :Kitchen(ptr)
{
    nextChef = make_shared<HeadChef>();
}
void SauceChef::handleOrder(int id, vector<shared_ptr<MenuItemCommand>> orders, vector<shared_ptr<FoodItem>> foods)
{
    for (vector<shared_ptr<MenuItemCommand>> it = orders.begin(); it != orders.end(); it++)
    {
        if ((*it)->getReciever() == this)
        {
            foods.push_back((*it)->execute(*it));
        }
    }
    nextChef->handleOrder(id, orders, foods);
}

shared_ptr<FoodItem> SauceChef::execute(shared_ptr<MenuItemCommand> val)
{
    if (typeid(val) == typeid(Pepperoni))
        return make_shared<Mozzarella>();
    else if (typeid(val) == typeid(Olives))
        return make_shared<Olives>();
    else if (typeid(val) == typeid(Mushrooms))
        return make_shared<Mushrooms>();
    else if (typeid(val) == typeid(Chicken))
        return make_shared<Chicken>();
    else if (typeid(val) == typeid(Beef))
        return make_shared<Beef>();
    else if (typeid(val) == typeid(Peppers))
        return make_shared<Peppers>();
}