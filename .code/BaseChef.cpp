#include "BaseChef.h"

BaseChef::BaseChef()
{
    nextChef = make_shared<CheeseChef>();
}
void BaseChef::handleOrder(int waiter_id, int customer_id, vector<shared_ptr<MenuItemCommand>> orders, vector<shared_ptr<FoodItem>>foods)
{
    for (vector<shared_ptr<MenuItemCommand>>::iterator it = orders.begin(); it != orders.end(); it++)
    {
        if (dynamic_pointer_cast<MakeBase>((*it)))
        {
            cout << "****IN THE ---BASE--- CHEFF COOKING!!!!!!!!" << endl;
            foods.push_back((*it)->execute());
        }
    }
    nextChef->handleOrder(waiter_id,customer_id,orders, foods);
}

shared_ptr<FoodItem> BaseChef::execute(shared_ptr<MenuItemCommand> val, string t)
{
    if (dynamic_pointer_cast<MakeStuffedCrust>(val))
    {
        cout << "COOKED UP A STUFFED CRUST" << endl;
        return make_shared<StuffedCrust>(t);
    }
    else if (dynamic_pointer_cast<MakeThinCrust>(val))
    {
        cout << "COOKED UP A THIN CRUST" << endl;
        return make_shared<ThinCrust>(t);
    }
    else if (dynamic_pointer_cast<MakeDoubleDecker>(val))
    {
        cout << "COOKED UP A DOUBLE-DECKER CRUST" << endl;
        return make_shared<DoubleDecker>(t);
    }
    else if (dynamic_pointer_cast<MakeBoiledCrust>(val))
    {
        cout << "COOKED UP A BOILED CRUST" << endl;
        return make_shared<Boiled>(t);
    }
    else if (dynamic_pointer_cast<MakeDeepDish>(val))
    {
        cout << "COOKED UP A DEEPDISH CRUST" << endl;
        return make_shared<DeepDish>(t);
    }

    return 0;
}