#include "ManagerChef.h"

ManagerChef::ManagerChef()
{
	nextChef = make_shared<BaseChef>();
}

void ManagerChef::cycle()
{
	shared_ptr<Kitchen> tempy = nextChef;
	while (tempy->getNextChef() != 0)
	{
		tempy = tempy->getNextChef();
	}

	tempy->setNextChef(enable_shared_from_this<ManagerChef>::shared_from_this());
}

vector<shared_ptr<Kitchen>> ManagerChef::getChefs()
{
	vector<shared_ptr<Kitchen>> chefs;
	//chefs.push_back(nextChef);
	shared_ptr<Kitchen> ptr = nextChef;
	while (ptr != enable_shared_from_this<ManagerChef>::shared_from_this())
	{
		chefs.push_back(ptr);
		ptr = ptr->getNextChef();
	}
	return chefs;
}
void ManagerChef::handleOrder(pair<int, vector<pair<int, shared_ptr<Order>>>> pr)
{
	orders = pr.second;
	while (!pr.second.empty())
	{
		vector<shared_ptr<FoodItem>> foods;
		pair<int, shared_ptr<Order>> t = pr.second.back();
		pr.second.pop_back();
		nextChef->handleOrder(pr.first,t.first, t.second->getFormula(), foods);
	}
}

void ManagerChef::handleOrder(int id)
{
	handleOrder(make_pair(id, orders));
}

bool ManagerChef::ordersComplete()
{
	return orders.empty();
}