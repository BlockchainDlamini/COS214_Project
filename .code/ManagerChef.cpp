#include "ManagerChef.h"

ManagerChef::ManagerChef()
{
	nextChef = make_shared<BaseChef>();
	shared_ptr<Kitchen> tempy = enable_shared_from_this<ManagerChef>::shared_from_this();
	while (tempy->getNextChef() != 0)
	{
		tempy = tempy->getNextChef();
	}
	
	tempy->setNextChef(shared_from_this());
}

void ManagerChef::handleOrder(pair<int, vector<shared_ptr<Order>>> pr)
{
	while (!pr.second.empty())
	{
		vector<shared_ptr<FoodItem>> foods;
		nextChef->handleOrder(pr.first, pr.second.back()->getFormula(), foods);
		pr.second.pop_back();
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