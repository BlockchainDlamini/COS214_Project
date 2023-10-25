#ifndef Tab_H
#define Tab_H
#include "OrderMemento.h"
#include <string>
class Tab
{
private:
    std::vector<std::shared_ptr<OrderMemento>> tab;

public:
    Tab();
    std::string listOutstandingOrders();
    bool payOrder(); // check to see if the customer has paid his/hers/their tab
    void addOrder(shared_ptr<OrderMemento>);
    std::vector<std::shared_ptr<OrderMemento>> getTab();
    int getTotal();
    void clearTab();
};
#endif