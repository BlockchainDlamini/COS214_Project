#ifndef SAUCECHEF_H
#define SAUCECHEF_H
#include "ToppingsChef.h"
class SauceChef :
    public Kitchen
{
public:
    SauceChef();
    void handleOrder(int, vector<shared_ptr<MenuItemCommand>>, vector<shared_ptr<FoodItem>>);
    shared_ptr<FoodItem> execute(shared_ptr<MenuItemCommand>);
};
#endif
