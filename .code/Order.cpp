#include "Order.h"
Order::Order(int id,float price)
{
    orderID = id;
    this->price = price;
}
Order::Order(float price, int orderID, std::vector<std::shared_ptr<MenuItemCommand>> order)
{
    this->price = price;
    this->orderID = orderID;
    this->formula = order;
}
Order::Order(int orderID, std::vector<std::shared_ptr<MenuItemCommand>> order)
{
    this->orderID = orderID;
    this->formula = order;
}

float Order::getPrice()
{
    return price;
}
int Order::getOrderID()
{
    return orderID;
}

// void Order::placeOrder()
// {
// }

std::shared_ptr<OrderMemento> Order::createOrderMemento()
{
    return make_shared<OrderMemento>(price, orderID, formula);
}

void Order::setOrderMemento(std::shared_ptr<OrderMemento> order)
{
    price = order->getPrice();
    //  orderID = order->getID();
    formula = order->getToBePaid(); // this is a shallow copy will be adjusted into a deep copy
}

void Order::addMenuItemCommand(shared_ptr<MenuItemCommand> command)
{
    formula.push_back(command);
}

void Order::addMenuItems(vector<shared_ptr<MenuItemCommand>> commands)
{
    formula = commands;
}

void Order::setPrice(float price)
{
    this->price = price;
}

std::vector<std::shared_ptr<MenuItemCommand>> Order::getFormula()
{
    return formula;
}
// string Order::showFormula()
// {
//     string output = "";
//     for (shared_ptr<MenuItemCommand> menu : formula)
//     {output+="MenuItem+ ["+to_string
//     }
// }
string Order::showOrder()
{
    string output = "";
    output += "OrderID: [" + to_string(orderID) + "] Total: [" + to_string(price) + "]";
    return output;
}