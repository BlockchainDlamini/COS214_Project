#ifndef Tab_H
#define Tab_H
#include "OrderMemento.h"
#include <string>
class Tab
{
private:
    std::vector<std::shared_ptr<OrderMemento>> tab;

public:
    std::string listOutstandingOrders();
    bool payOrder();
    void addOrder(shared_ptr<OrderMemento>);
    std::vector<std::shared_ptr<OrderMemento>> getTab();
    int getTotal();
};
#endif