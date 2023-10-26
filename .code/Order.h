#ifndef Order_H
#define Order_H
#include "Customer.h"
#include "MenuItemOrderCommand.h"
#include "OrderMemento.h"
class Order : public enable_shared_from_this<Order>

{
private:
    std::vector<std::shared_ptr<MenuItemOrderCommand>> formula;
    int price;
    int orderID;

public:
    Order(int);
    Order(int orderID, std::vector<std::shared_ptr<MenuItemOrderCommand>> order);
    Order(int price, int orderID, std::vector<std::shared_ptr<MenuItemOrderCommand>> order);
    void placeOrder();
    int getPrice();
    int getOrderID();
    std::shared_ptr<OrderMemento> createOrderMemento();
    void setOrderMemento(std::shared_ptr<OrderMemento>);
    void addMenuItemOrderCommand(shared_ptr<MenuItemOrderCommand>);
    string showFormula(); // returns a tostring of the formula
};
#endif
