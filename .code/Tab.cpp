#include "Tab.h"
Tab::Tab()
{
}
std::string Tab::listOutstandingOrders()
{
    string output = "";
    for (shared_ptr<OrderMemento> order : tab)
    {
        output += "Order ID: " + to_string(order->getID()) + "Price: " + to_string(order->getPrice()) + "\n";
    }
    output += "Total: " + getTotal();
    return output;
}

bool Tab::payOrder()
{
    if (tab.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Tab::addOrder(std::shared_ptr<OrderMemento> order)
{
    tab.push_back(order);
}

std::vector<std::shared_ptr<OrderMemento>> Tab::getTab()
{
    return tab;
}

int Tab::getTotal()
{
    int total = 0;
    for (shared_ptr<OrderMemento> order : tab)
    {
        total += order->getPrice();
    }
    return total;
}

void Tab::clearTab()
{
    tab.clear();
}