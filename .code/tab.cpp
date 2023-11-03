#include "Tab.h"
#include <string>
Tab::Tab()
{
}
std::string Tab::listOutstandingOrders()
{
    string output = "";
    output += "Customer ID: " + ID + "\n";
    for (shared_ptr<OrderMemento> order : tab)
    {
        output += "Order ID: " + to_string(order->getID()) + "\n";
        output += "Description: " + description;
    }
    output += "Total: " + to_string(getTotal());
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

void Tab::setID(string id)
{
    ID = id;
}

void Tab::addOrder(std::shared_ptr<OrderMemento> order, string ID)
{
    setID(ID);
    // checkID(ID);
    tab.push_back(order);
}

std::vector<std::shared_ptr<OrderMemento>> Tab::getTab()
{
    return tab;
}

float Tab::getTotal()
{
    float total = 0;
    for (shared_ptr<OrderMemento> order : tab)
    {
        total += order->getPrice();
    }
    return total;
}

bool Tab::checkID(string ID)
{
    if (this->ID == ID)
    {
        return true;
    }
    return false;
}

string Tab::getID()
{
    return ID;
}

void Tab::clearTab()
{
    tab.clear();
}

void Tab::setDescription(string d)
{
    description = d;
}
