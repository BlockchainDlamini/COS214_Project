#ifndef SAUCECHEF_H
#define SAUCECHEF_H
#include "Kitchen.h"
#include "Sauce.h"
class SauceChef :
    public Kitchen
{
    SauceChef(shared_ptr<Kitchen> ptr);
    void handleOrder(int, vector<shared_ptr<MenuItemCommand>>, vector<shared_ptr<FoodItem>>);
    shared_ptr<FoodItem> createFoodItem();
    shared_ptr<FoodItem> execute();
};
#endif

SauceChef::SauceChef(shared_ptr<Kitchen> ptr) :Kitchen(ptr) {}
void SauceChef::handleOrder(int, vector<shared_ptr<MenuItemCommand>>, vector<shared_ptr<FoodItem>>) {}
shared_ptr<FoodItem> SauceChef::createFoodItem() 
{
    return make_shared<>();
}
shared_ptr<FoodItem> SauceChef::execute()
{
    createFoodItem();
}