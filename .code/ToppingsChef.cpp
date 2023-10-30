#include "ToppingsChef.h"

ToppingsChef::ToppingsChef()
{
    nextChef = make_shared<HeadChef>();
}
void ToppingsChef::handleOrder(int id, vector<shared_ptr<MenuItemCommand>> orders, vector<shared_ptr<FoodItem>> foods)
{
    for (vector<shared_ptr<MenuItemCommand>> it = orders.begin(); it != orders.end(); it++)
    {
        if (typeid(*(*it)) == typeid(MakeToppings))
        {
            foods.push_back((*it)->execute(*it));
        }
    }
    nextChef->handleOrder(id, foods);
}

shared_ptr<FoodItem> ToppingsChef::execute(shared_ptr<MenuItemCommand> val)
{

    if (typeid(val) == typeid(MakeMozzarella))
        return make_shared<Mozzarella>();
    else if (typeid(val) == typeid(MakeOlives))
        return make_shared<Olives>();
    else if (typeid(val) == typeid(MakeMushrooms))
        return make_shared<Mushrooms>();
    else if (typeid(val) == typeid(MakeChicken))
        return make_shared<Chicken>();
    else if (typeid(val) == typeid(MakeBeef))
        return make_shared<Beef>();
    else if (typeid(val) == typeid(MakePeppers))
        return make_shared<Peppers>();
}