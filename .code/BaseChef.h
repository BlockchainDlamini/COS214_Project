#ifndef BASECHEF_H
#define BASECHEF_H
//THIS IS THE CLASS AT THE BOTTOM OF ALL THE CLASSES THAT HAVE BEEN LINKED TOGETHER
#include "CheeseChef.h"//BOBS ADDITION
class BaseChef :
    public Kitchen
{
public:
    BaseChef();
    void handleOrder(int, vector<shared_ptr<MenuItemCommand>>, vector<shared_ptr<FoodItem>>);
    shared_ptr<FoodItem> execute(shared_ptr<MenuItemCommand>, string);
};
#endif