#ifndef MANAGERCHEF_H
#define MANAGERCHEF_H
#include "Kitchen.h"
#include <queue>
class ManagerChef :
    public Kitchen
{
public:
	ManagerChef(shared_ptr<Kitchen> ptr);
	void handleOrder(pair<int, vector<shared_ptr<Order>>>);
};
#endif