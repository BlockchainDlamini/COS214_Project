#include "ManagerChef.h"

ManagerChef::ManagerChef()
{
	nextChef = make_shared<BaseChef>();
}

shared_ptr<Kitchen> ManagerChef::cycle()
{
	shared_ptr<Kitchen> tempy = nextChef;
	while (tempy->getNextChef() != 0)
	{
		tempy = tempy->getNextChef();
	}

	return tempy;
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
	/*cout << "Manager" << endl;
	cout << "CHEF_ADDRESS::::::: " << this << endl;*/
	orders = pr.second;
	if (!orders.empty())
	{
		vector<shared_ptr<FoodItem>> foods;
		pair<int, shared_ptr<Order>> t = pr.second.back();
		orders.pop_back();
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