#include "BaseChef.h"

BaseChef::BaseChef()
{
    nextChef = make_shared<CheeseChef>();
}
void BaseChef::handleOrder(int id, vector<shared_ptr<MenuItemCommand>> orders, vector<shared_ptr<FoodItem>> foods)
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

shared_ptr<FoodItem> BaseChef::execute(shared_ptr<MenuItemCommand> val)
{
    if (typeid(val) == typeid(MakeStuffedCrust))
        return make_shared<StuffedCrust>();
    else if (typeid(val) == typeid(MakeThinCrust))
        return make_shared<ThinCrust>();
    else if (typeid(val) == typeid(MakeDoubleDecker))
        return make_shared<DoubleDecker>();
    else if (typeid(val) == typeid(MakeBoiled))
        return make_shared<Boiled>();
    else if (typeid(val) == typeid(MakeDeepDish))
        return make_shared<DeepDish>();
}