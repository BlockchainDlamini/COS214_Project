#ifndef KITCHEN_H
#define KITCHEN_H
#include "Pizza.h"
//THIS IS THE CLASS AT TEH TOP OF THE LINKING BETWEEN THE KITCHEN CLASSES
class MenuItemCommand;
class Order;
class Kitchen : public gameElement
{
protected:
	shared_ptr<Kitchen> nextChef;
public:
	Kitchen();
	void handleOrder(int, vector<shared_ptr<FoodItem>>);
	virtual void handleOrder(int, vector<shared_ptr<MenuItemCommand>>, vector<shared_ptr<FoodItem>>);
	virtual void handleOrder(pair<int, vector<shared_ptr<Order>>>);
	virtual bool ordersComplete();
	virtual void handleOrder(int);
	virtual shared_ptr<FoodItem> execute(shared_ptr<MenuItemCommand>);
	shared_ptr<Kitchen> getNextChef();
	void setNextChef(shared_ptr<Kitchen>);
};
#endif
