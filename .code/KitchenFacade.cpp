#include "KitchenInterface.h"
using namespace std;

KitchenInterface::KitchenInterface() {
    managerChef = make_shared<ManagerChef>();
    shared_ptr<Kitchen> kitchen = managerChef;
    while (!dynamic_pointer_cast<HeadChef>(kitchen))
        kitchen = kitchen->getNextChef();
    headChef = dynamic_pointer_cast<HeadChef>(kitchen);
}

shared_ptr<Kitchen> KitchenInterface::getKitchenReference() {
    return managerChef;
}

void KitchenInterface::delegateOrderProcess(pair<int, vector<pair<int, shared_ptr<Order>>>> orders) {
    managerChef->handleOrder(orders);
}

pair<int, std::vector<std::shared_ptr<pair<int, std::shared_ptr<Pizza>>>>> collectOrder() {
    return headChef->collectOrder();
}