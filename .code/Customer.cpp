#include "Customer.h"

Customer::Customer()
{
    mood = std::make_shared<EmotionState>();
    hasOrdered = false;
    tab = nullptr;
    orderProcess = std::make_shared<OrderProcessState>();
    bankAccountAmount = 1000; // each customer brings R1000 when they come to restaurant
}
Customer::Customer(std::shared_ptr<EmotionState> mood, int bankAccountAmount)
{
    this->mood = mood;
    this->bankAccountAmount = bankAccountAmount;
}
void Customer::get()
{
}

void Customer::set()
{
}
void Customer::changed()
{
}
void Customer ::changeMood()
{
    mood->handleChange(shared_from_this());
}
void Customer::changedOrderProcessState()
{
    orderProcess->handleChange(shared_from_this());
}
void Customer::setID(int id)
{
    ID = id;
}
void Customer::requestBill()
{
    // needs to tell the waiter that they want the bill
}
bool Customer::payBill(char c)
{
    if (hasBill == true)
    {
        if (c == 'P')
        {
            for (std::shared_ptr<Order> order : orders)
            {
                if (order != nullptr)
                {
                    bankAccountAmount - order->getPrice();
                }
            }
        }
        else if (c == 'T')
        {
            for (std::shared_ptr<Order> order : orders)
            {
                if (order != nullptr)
                {
                    order->addToTab();
                }
            }
        }
    }
    else
    {
        cout << "Customer has not received the bill from the waiter" << endl;
    }
}
bool Customer::isLoyal()
{
    if (tab == nullptr)
    {
        return false;
    }
    else
    {
        return true;
    }
}
void Customer::startTab()
{
    tab = std::make_shared<Tab>();
}
void Customer::createOrder(std::shared_ptr<Order> order)
{
    orders.push_back(order);
}
void Customer::beSeated(int tableNum)
{
    this->tableNum = tableNum;
}

int Customer::getTableNum()
{
    return tableNum;
}

void Customer::setEmotionState(std::shared_ptr<EmotionState> mood)
{
    this->mood = mood;
}

void Customer::setOrderProcessState(std::shared_ptr<OrderProcessState> orderProcess)
{
    this->orderProcess = orderProcess;
}
std::shared_ptr<EmotionState> Customer::getMood()
{
    return mood;
}
std::shared_ptr<OrderProcessState> Customer::getOrderProcessState()
{
    return orderProcess;
}
std::vector<std::shared_ptr<Order>> Customer::sendOrder()
{
    return this->orders;
}

bool Customer::receiveOrder(std::vector<std::shared_ptr<Order>> orders)
{
    this->orders = orders;
}

std::string Customer::printCustomer()
{
    std::string output = "";
    return output;
}