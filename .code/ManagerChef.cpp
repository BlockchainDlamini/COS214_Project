#include "ManagerChef.h"

ManagerChef::ManagerChef(shared_ptr<Kitchen> ptr) :Kitchen(ptr) {}

void ManagerChef::handleOrder(pair<int, vector<shared_ptr<Order>>> pr)
{
	while (!pr.second.empty())
	{
		vector<shared_ptr<FoodItem>> foods;
		nextChef->handleOrder(pr.first, pr.second.back()->getFormula(), foods);
		pr.second.pop_back();
	}
}
