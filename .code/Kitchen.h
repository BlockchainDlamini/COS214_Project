#ifndef KITCHEN_H
#define KITCHEN_H
#include "Toppings.h"
class Kitchen
{
protected: 
	shared_ptr<Kitchen> nextChef;
public:
	Kitchen(shared_ptr<Kitchen> ptr);
	virtual void handleOrder(int, vector<shared_ptr<MenuItemCommand>>, vector<shared_ptr<FoodItem>>);
	virtual void handleOrder(pair<int, vector<shared_ptr<Order>>>);
	virtual shared_ptr<FoodItem> createFoodItem();
	virtual shared_ptr<FoodItem> execute();
};
#endif