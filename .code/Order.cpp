#include "Order.h"
Order::Order()
{
    price = 20;
}
Order::Order(int price, int orderID, std::vector<std::shared_ptr<MenuItemOrderCommand>> order)
{
    this->price = price;
    this->orderID = orderID;
    this->formula = order;
}
Order::Order(int orderID,std::vector<std::shared_ptr<MenuItemOrderCommand>> order )
{
    this->orderID = orderID;
    this->formula = order;
}
// void addToTab(){

// }

// void Order::placeOrder()
// {
// }

int Order::getPrice()
{
    return price;
}

std::shared_ptr<OrderMemento> Order::createOrderMemento()
{
    return make_shared<OrderMemento>(price, orderID, formula);
}

void Order::setOrderMemento(std::shared_ptr<OrderMemento> order)
{
    price = order->getPrice();
    orderID = order->getID();
    formula = order->getToBePaid();
}

void Order::addMenuItemOrderCommand(shared_ptr<MenuItemOrderCommand> command)
{
    formula.push_back(command);
}