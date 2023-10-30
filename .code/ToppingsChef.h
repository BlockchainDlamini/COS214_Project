#ifndef TOPPINGSCHEF_H
#define TOPPINGSCHEF_H
#include "Kitchen.h"
class ToppingsChef :
    public Kitchen
{
    ToppingsChef();
    void handleOrder(int, vector<shared_ptr<MenuItemCommand>>, vector<shared_ptr<FoodItem>>);
    shared_ptr<FoodItem> execute(shared_ptr<MenuItemCommand> val)
};
#endif