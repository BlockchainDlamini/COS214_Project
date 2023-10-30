#ifndef MANAGERCHEF_H
#define MANAGERCHEF_H
#include "BaseChef.h"
#include <utility>
class ManagerChef :
    public Kitchen, public enable_shared_from_this<ManagerChef>
{
private:
	vector<shared_ptr<Order>> orders;

public:
	ManagerChef();
	void handleOrder(int);
	void handleOrder(pair<int, vector<shared_ptr<Order>>>);
	bool ordersComplete();
};
#endif