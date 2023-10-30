#include "CheeseChef.h"

CheeseChef::CheeseChef()
{
    nextChef = make_shared<ToppingsChef>();
}

void CheeseChef::handleOrder(int id, vector<shared_ptr<MenuItemCommand>> orders, vector<shared_ptr<FoodItem>> foods)
{
    for (vector<shared_ptr<MenuItemCommand>> it = orders.begin(); it != orders.end(); it++)
    {
        if (typeid(*(*it)) == typeid(MakeCheese))
        {
            foods.push_back((*it)->execute());
        }
    }
    nextChef->handleOrder(id, orders, foods);
}

shared_ptr<FoodItem> CheeseChef::execute(shared_ptr<MenuItemCommand> val)
{
    if (typeid(val) == typeid(MakeMozzarella))
        return make_shared<Mozzarella>();
    else if (typeid(val) == typeid(MakeCheddar))
        return make_shared<Cheddar>();
    else if (typeid(val) == typeid(MakeGouda))
        return make_shared<Gouda>();
    else if (typeid(val) == typeid(MakeParmesan))
        return make_shared<Parmesan>();
    else if (typeid(val) == typeid(MakeBlueCheese))
        return make_shared<BlueCheese>();
}