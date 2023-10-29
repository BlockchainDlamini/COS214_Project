#ifndef BASE_H
#define BASE_H
#include "Toppings.h"
class Base :
    public FoodItem
{
    Base(shared_ptr<Kitchen> ptr);
    void handleOrder(int, vector<shared_ptr<MenuItemCommand>>, vector<shared_ptr<FoodItem>>);
    shared_ptr<FoodItem> createFoodItem();
    shared_ptr<FoodItem> execute();
};
#endif

Base::Base(shared_ptr<Kitchen> ptr):Kitchen(ptr)
{}
void Base::handleOrder(int id, vector<shared_ptr<MenuItemCommand>> orders, vector<shared_ptr<FoodItem>> foods)
{

}
