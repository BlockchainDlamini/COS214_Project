#include "KitchenInterface.h"
using namespace std;

KitchenInterface::KitchenInterface() {
    managerChef = make_shared<ManagerChef>();
    headChef = dynamic_pointer_cast<HeadChef>(managerChef->cycle());
    headChef->setNextChef(managerChef);
}

shared_ptr<Kitchen> KitchenInterface::getKitchenReference() {
    return managerChef;
}

void KitchenInterface::delegateOrderProcess(pair<int, vector<pair<int, shared_ptr<Order>>>> orders) {
    managerChef->handleOrder(orders);
}

pair<int, std::vector<std::shared_ptr<pair<int, std::shared_ptr<Pizza>>>>> KitchenInterface::collectOrder() {
    return headChef->collectOrder();
}

int KitchenInterface::getWaiterID() {
    return headChef->getWaiterID();
}