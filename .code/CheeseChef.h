#ifndef CHEESECHEFF_H
#define CHEESECHEFF_H
#include "SauceChef.h"
class CheeseChef :
    public Kitchen
{
public:
    CheeseChef();
    void handleOrder(int, vector<shared_ptr<MenuItemCommand>>, vector<shared_ptr<FoodItem>>);
    shared_ptr<FoodItem> execute(shared_ptr<MenuItemCommand>);
};
#endif
