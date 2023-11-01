#include "OrderMemento.h"
OrderMemento::OrderMemento(std::shared_ptr<OrderMemento> order)
{
    this->formula = order->getToBePaid();
    this->price = order->price;
    this->orderID = order->orderID;
}

OrderMemento::OrderMemento(int price, int orderID, std::vector<std::shared_ptr<MenuItemCommand>> order)
{
    this->price = price;
    this->orderID = orderID;
    this->formula = order;
}

OrderMemento::OrderMemento(int price, std::vector<std::shared_ptr<MenuItemCommand>> formula)
{
    this->price = price;
    this->formula = formula;
}

float OrderMemento::getPrice()
{
    return price;
}

void OrderMemento::setPrice(float price)
{
    this->price = price;
}

int OrderMemento::getID()
{
    return orderID;
}
void OrderMemento::setID(int id)
{
    orderID = id;
}

std::vector<std::shared_ptr<MenuItemCommand>> OrderMemento::getToBePaid()
{
    return formula;
}

void OrderMemento::setToBePaid(std::vector<std::shared_ptr<MenuItemCommand>> commands)
{
    for (shared_ptr<MenuItemCommand> item : formula)
    {
        if (!commands.empty())
        {
            item = commands.front(); // need to make shallow copies
            commands.erase(commands.begin());
        }
    }
}
