#ifndef CHEESE_H
#define CHEESE_H
#include "Sauce.h"
class Cheese :
    public FoodItem
{
    Cheese(shared_ptr<Kitchen> ptr);
    void handleOrder(int, vector<shared_ptr<MenuItemCommand>>, vector<shared_ptr<FoodItem>>);
    shared_ptr<FoodItem> createFoodItem();
    shared_ptr<FoodItem> execute();
};
#endif
Cheese::Cheese(shared_ptr<Kitchen> ptr):Kitchen(PTR){}
void Cheese::handleOrder(int, vector<shared_ptr<MenuItemCommand>>, vector<shared_ptr<FoodItem>>)
{

}
shared_ptr<FoodItem> Cheese::createFoodItem();
shared_ptr<FoodItem> Cheese::execute();