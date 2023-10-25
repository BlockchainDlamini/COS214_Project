#ifndef Order_H
#define Order_H
#include "Customer.h"
#include "MenuItemOrderCommand.h"
#include "OrderMemento.h"
class Order
{
private:
    std::vector<std::shared_ptr<MenuItemOrderCommand>> order;
    int price;
    int orderID;

public:
    Order();
    Order(int price, int orderID, std::vector<std::shared_ptr<MenuItemOrderCommand>> order);
    void addToTab();
    void placeOrder();
    int getPrice();
    std::shared_ptr<OrderMemento> createOrderMemento();
    void setOrderMemento(std::shared_ptr<OrderMemento>);
    void addMenuItemOrderCommand();
};
#endif
