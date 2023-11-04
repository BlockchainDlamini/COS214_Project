#include "ToppingsChef.h"
ToppingsChef::ToppingsChef()
{
    nextChef = make_shared<HeadChef>();
}
void ToppingsChef::handleOrder(int waiter_id, int customer_id, vector<shared_ptr<MenuItemCommand>> orders, vector<shared_ptr<FoodItem>>foods)
{
    for (vector<shared_ptr<MenuItemCommand>>::iterator it = orders.begin(); it != orders.end(); it++)
    {
        if (dynamic_pointer_cast<MakeTopping>((*it)))
        {
            cout << "****IN THE ---TOPPINGS CHEFF--- CHEFF COOKING!!!!!!!!" << endl;
            foods.push_back((*it)->execute());
        }
    }
    nextChef->handleOrder(waiter_id,customer_id, foods);
}

shared_ptr<FoodItem> ToppingsChef::execute(shared_ptr<MenuItemCommand> val)
{

  
    if (dynamic_pointer_cast<MakeOlives>(val))
    {
        cout << "COOKED UP A OLIVE TOPPING" << endl;
        return make_shared<Olives>();
    }
    else if (dynamic_pointer_cast<MakeMushrooms>(val))
    {
        cout << "COOKED UP A MUSHROOMS TOPPING" << endl;
        return make_shared<Mushrooms>();
    }
    else if (dynamic_pointer_cast<MakeChicken>(val))
    {
        cout << "COOKED UP A CHICKEN TOPPING" << endl;
        return make_shared<Chicken>();
    }
    else if (dynamic_pointer_cast<MakeBeef>(val))
    {
        cout << "COOKED UP A BEEF TOPPING" << endl;
        return make_shared<Beef>();
    }
    else if (dynamic_pointer_cast<MakePeppers>(val))
    {
        cout << "COOKED UP A PEPPERS TOPPING" << endl;
        return make_shared<Peppers>();
    }
    else if (dynamic_pointer_cast<MakePepperoni>(val))
    {
        cout << "COOKED UP A PPEPPERONI TOPPINGS" << endl;
        return make_shared<Pepperoni>();
    }

    return 0;
}