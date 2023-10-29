#include "Customer.h"

Customer::Customer(int bankAmount, int id) : gameElement()
{
    bankAccountAmount = bankAmount; // each customer brings R1000 when they come to restaurant
    ID = id;
}
Customer::Customer(std::shared_ptr<EmotionState> mood, int bankAccountAmount):gameElement()
{
    this->mood = mood;
    this->bankAccountAmount = bankAccountAmount;
}
string Customer::get()
{
    // return this;
}

// void Customer::setOperation(string operation)
// {
//     this->operation = operation;
// }
// void Customer::changed()
// {
// }
// void Customer ::changeMood()
// {
//     mood->handleChange(shared_from_this());
// }
// void Customer::changedOrderProcessState()
// {
//     orderProcess->handleChange(shared_from_this());
// }
void Customer::setID(int id)
{
    ID = id;
}
void Customer::requestBill()
{
    // needs to tell the waiter that they want the bill
}
bool Customer::payBill(char c, float t) // returns true if the customer has either paid or added the bill to a tab
{
    float total = t;
    if (hasBill == true)
    {
        if (c == 'P' || c == 'p')
        {
            if (bankAccountAmount < total)
            {
                cout << "Customer cannot pay the bill, insufficient funds" << endl;
                return false;
            }
            else
            {
                float tip = total + (total * mood->getTip());
                bankAccountAmount = bankAccountAmount - (total + tip);
                return true;
            }
        }
        else if (c == 'T' && isLoyal() == true) // has a tab and wants to add to tab
        {
            for (std::shared_ptr<Order> order : orders)
            {
                if (order != nullptr)
                {
                    tab->addOrder(order->createOrderMemento());
                }
            }
            return true;
        }
        else if (c == 'T' && isLoyal() == false) // doesn't have a tab but wants to add
        {
            startTab(); // create a new tab for customer
            for (std::shared_ptr<Order> order : orders)
            {
                if (order != nullptr)
                {
                    tab->addOrder(order->createOrderMemento());
                }
            }
            return true;
        }
        else
        {
            cout << "Incorrect input" << endl;
            return false;
        }
    }
    else
    {
        cout << "Customer has not received the bill from the waiter" << endl;
        return false;
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
    cout << "CustomerID: [" + to_string(ID) + "] has created a new tab" << endl;
}
void Customer::payTab()
{
    if (tab->payOrder() == true)
    {
        bankAccountAmount - tab->getTotal();
        tab->clearTab();
        cout << "CustomerID: [" + to_string(ID) + " has cleared his tab" << endl;
    }
}
string Customer::printBill()
{
    string output = "";
    if (hasBill == true)
    {

        output += "CustomerID: [" + to_string(ID) + "] Bank Account Amount: [R" + to_string(bankAccountAmount) + "] Tip Percentage: [" + to_string(mood->getTip()) + "] \nOrders: " + "\n";
        for (shared_ptr<Order> order : orders)
        {
            output += "OrderID: [" + to_string(order->getOrderID()) + "] Price: [" + to_string(order->getPrice()) + "] \n";
        }
    }
    output = "CustomerID [" + to_string(ID) + "]  has not received the bill yet\n";
    return output;
}
void Customer::createOrder(int orderID, vector<shared_ptr<MenuItemOrderCommand>> commands)
{
    std::shared_ptr<Order> order = make_shared<Order>(orderID, commands);
    orders.push_back(order);
    std::cout << "Order: " + to_string(orderID) + " has been added" << endl;
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
std::vector<std::shared_ptr<Order>> Customer::getOrders()
{
    return this->orders;
}

bool Customer::receiveOrder(shared_ptr<Pizza> pizza)
{
    if (pizza != nullptr)
    {
        this->pizza = pizza;
        return true;
    }
    return false;
}

std::string Customer::printCustomer()
{
    std::string output = "CustomerID: [" + to_string(ID) + "] Mood: [" + mood->getEmotion() + "] Table Number: [" + to_string(tableNum) + "] Bank Account Amount: [" + to_string(bankAccountAmount) + "]" + " Order Status: " + orderProcess->stateName;
    return output;
}
int Customer::getID()
{
    return ID;
}
bool Customer::hasFood()
{
    if (pizza != nullptr)
    {
        return true;
    }
    return false;
}
