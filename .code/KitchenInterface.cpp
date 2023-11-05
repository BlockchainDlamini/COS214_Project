#include "KitchenInterface.h"
using namespace std;

KitchenInterface::KitchenInterface() {
    managerChef = make_shared<ManagerChef>();
    headChef = managerChef->cycle();
    //cout << headChef << endl;
    headChef->setNextChef(managerChef);
}

shared_ptr<Kitchen> KitchenInterface::getKitchenReference() {
    return managerChef;
}

void KitchenInterface::delegateOrderProcess(pair<int, vector<pair<int, shared_ptr<Order>>>> orders) {
    //printKitchenloop();
    managerChef->handleOrder(orders);
}



pair<int, std::vector<std::shared_ptr<pair<int, std::shared_ptr<Pizza>>>>> KitchenInterface::collectOrder() {
    return headChef->collectOrder();
}

int KitchenInterface::getWaiterID() {
    return headChef->getWaiterID();
}


void KitchenInterface::setGameEngine(shared_ptr<Mediator> val)
{
    gameEngine = val;
    headChef->setGameEngine(val);
}


//void KitchenInterface::printKitchenloop()
//{
//    shared_ptr<Kitchen> tempy = managerChef;
//    while (tempy->getNextChef() != managerChef)
//    {
//        cout << tempy << " -> " << tempy->getNextChef()<<"\n";
//        tempy = tempy->getNextChef();
//    }
//    cout << tempy << "----->" << tempy->getNextChef() << endl;
//
//    cout << "\n\n" << endl;
//}