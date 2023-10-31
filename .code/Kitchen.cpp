#include "Kitchen.h"

Kitchen::Kitchen()
{}

void Kitchen::setNextChef(shared_ptr<Kitchen> val)
{
	nextChef = val;
}

shared_ptr<Kitchen> Kitchen::getNextChef()
{
	return nextChef;
}

void Kitchen::handleOrder(int, vector<shared_ptr<MenuItemCommand>>, vector<shared_ptr<FoodItem>>)
{
	cout << "Nothing was handled";
}

void Kitchen::handleOrder(pair<int, vector<shared_ptr<Order>>> pr)
{
	cout << "Nothing was handled";
}

shared_ptr<FoodItem> Kitchen::execute()
{
	cout << "Nothing was executed";
	return 0;
}

bool Kitchen::ordersComplete()
{
	return 0;
}

void Kitchen::handleOrder(int)
{}

void Kitchen::handleOrder(int, vector<shared_ptr<FoodItem>>) {}