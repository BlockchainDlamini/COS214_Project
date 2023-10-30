#ifndef SAUCECHEF_H
#define SAUCECHEF_H
#include "ToppingsChef.h"
class SauceChef :
    public Kitchen
{
public:
    SauceChef(shared_ptr<Kitchen> ptr);
    void handleOrder(int, vector<shared_ptr<MenuItemCommand>>, vector<shared_ptr<FoodItem>>);
    shared_ptr<FoodItem> createFoodItem();
    shared_ptr<FoodItem> execute(shared_ptr<MenuItemCommand>);
};
#endif
