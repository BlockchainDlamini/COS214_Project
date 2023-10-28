#include "Order.h"
Order::Order(int id) // default price is 20
{
    orderID = id;
    price = 20;
}
Order::Order(int price, int orderID, std::vector<std::shared_ptr<MenuItemOrderCommand>> order)
{
    this->price = price;
    this->orderID = orderID;
    this->formula = order;
}
Order::Order(int orderID, std::vector<std::shared_ptr<MenuItemOrderCommand>> order)
{
    this->orderID = orderID;
    this->formula = order;
}

int Order::getPrice()
{
    return price;
}
int Order::getOrderID()
{
    return orderID;
}

void Order::placeOrder()
{
}

std::shared_ptr<OrderMemento> Order::createOrderMemento()
{
    return make_shared<OrderMemento>(price, orderID, formula);
}

void Order::setOrderMemento(std::shared_ptr<OrderMemento> order)
{
    price = order->getPrice();
    orderID = order->getID();
    formula = order->getToBePaid(); // this is a shallow copy will be adjusted into a deep copy
}

void Order::addMenuItemOrderCommand(shared_ptr<MenuItemOrderCommand> command)
{
    formula.push_back(command);
}