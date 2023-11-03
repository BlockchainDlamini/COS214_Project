#include "SauceChef.h"

SauceChef::SauceChef()
{
    nextChef = make_shared<ToppingsChef>();
}
void SauceChef::handleOrder(int id, vector<shared_ptr<MenuItemCommand>> orders, vector<shared_ptr<FoodItem>> foods)
{
    for (vector<shared_ptr<MenuItemCommand>>::iterator it = orders.begin(); it != orders.end(); it++)
    {
        if (dynamic_pointer_cast<MakeSauce>((*it)))
        {
            cout << "****IN THE ---SAUCECHEFF--- CHEFF COOKING!!!!!!!!" << endl;

            foods.push_back((*it)->execute());
        }
    }
    nextChef->handleOrder(id, orders, foods);
}

shared_ptr<FoodItem> SauceChef::execute(shared_ptr<MenuItemCommand> val)
{
    if (dynamic_pointer_cast<MakeSweetChilli>(val))
    {
        cout << "COOKED UP A SWEETCHILLI SAUCE" << endl;
        return make_shared<SweetChilli>();
    }
    else if (dynamic_pointer_cast<MakeSweetChilli>(val))
    {
        cout << "COOKED UP A RANCH SAUCE" << endl;
        return make_shared<Ranch>();
    }
    else if (dynamic_pointer_cast<MakeSweetChilli>(val))
    {
        cout << "COOKED UP A TOMATOPASTE SAUCE" << endl;
        return make_shared<TomatoPaste>();
    }
    else if (dynamic_pointer_cast<MakeChutneySauce>(val))
    {
        cout << "COOKED UP A CHUTNEY SAUCE" << endl;
        return make_shared<Chutney>();
    }
  
    return 0;
}