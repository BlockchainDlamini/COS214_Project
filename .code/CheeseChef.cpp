#include "CheeseChef.h"

CheeseChef::CheeseChef()
{
    nextChef = make_shared<SauceChef>();
}

void CheeseChef::handleOrder(int waiter_id, int customer_id, vector<shared_ptr<MenuItemCommand>> orders, vector<shared_ptr<FoodItem>>foods)
{
    for (vector<shared_ptr<MenuItemCommand>>::iterator it = orders.begin(); it != orders.end(); it++)
    {
        if (dynamic_pointer_cast<MakeCheese>((*it)))
        {
            cout << "****IN THE ---CHEESE--- CHEFF COOKING!!!!!!!!" << endl;
            foods.push_back((*it)->execute());
        }
    }
    nextChef->handleOrder(waiter_id, customer_id, orders, foods);
}

shared_ptr<FoodItem> CheeseChef::execute(shared_ptr<MenuItemCommand> val)
{
    if (dynamic_pointer_cast<MakeMozzarella>(val))
    {
        cout << "COOKED UP A MOZZARELLA CHEESE" << endl;
        return make_shared<Mozzarella>();
    }
    else if (dynamic_pointer_cast<MakeCheddar>(val))
    {
        cout << "COOKED UP A CHEDDAR CHEESE" << endl;
        return make_shared<Cheddar>();
    }
    else if (dynamic_pointer_cast<MakeGouda>(val))
    {
        cout << "COOKED UP A GOUDA CHEESE" << endl;
        return make_shared<Gouda>();
    }
    else if (dynamic_pointer_cast<MakeParmesan>(val))
    {
        cout << "COOKED UP A PARMESAN CHEESE" << endl;
        return make_shared<Parmesan>();
    }
    else if (dynamic_pointer_cast<MakeBlueCheese>(val))
    {
        cout << "COOKED UP A BLUCHEESE" << endl;
        return make_shared<BlueCheese>();
    }

    return 0;
}