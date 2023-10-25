#ifndef OrderMemento_H
#define OrderMemento_H
#include "Order.h"
class OrderMemento : public enable_shared_from_this<OrderMemento>
{
private:
    std::vector<std::shared_ptr<MenuItemOrderCommand>> formula;
    int price;
    int orderID;

public:
    OrderMemento(int, int, std::vector<std::shared_ptr<MenuItemOrderCommand>>);
    OrderMemento(std::shared_ptr<OrderMemento>);
    int getPrice();
    void setPrice(int);
    int getID();
    void setID(int );
    std::vector<std::shared_ptr<MenuItemOrderCommand>> getToBePaid();
    void setToBePaid(std::vector<std::shared_ptr<MenuItemOrderCommand>>);
};
#endif