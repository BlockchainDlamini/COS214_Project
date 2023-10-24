#ifndef OrderMemento_H
#define OrderMemento_H
#include "Order.h"
class OrderMemento
{
private:
    std::vector<std::shared_ptr<MenuItemOrderCommand>> toBePaid;

public:
    std::vector<std::shared_ptr<MenuItemOrderCommand>> getToBePaid();
    void setToBePaid(std::vector<std::shared_ptr<MenuItemOrderCommand>>);
};
#endif