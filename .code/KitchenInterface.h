#ifndef __KITCHEN_INTERFACE_H__
#define __KITCHEN_INTERFACE_H__

#include "gameElement.h"
#include "Kitchen.h"
#include "ManagerChef.h"
#include "Pizza.h"
#include <utility>
#include <vector>
#include "Order.h"


class KitchenInterface : gameElement {
public: 
    KitchenInterface();
    std::shared_ptr<Kitchen> getKitchenReference();
    pair<int, pair<int, std::vector<FoodItem>>> collectOrder();
    void delegateOrderProcess(pair<int, std::vector<pair<int, std::shared_ptr<Order>>>>);
private: 
    std::shared_ptr<ManagerChef> managerChef;
    std::shared_ptr<HeadChef> headChef;
};

#endif