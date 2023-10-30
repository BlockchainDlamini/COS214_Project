#include "Customer.h"

Customer::Customer(int bankAmount, int id) 
{
    bankAccountAmount = bankAmount; // each customer brings R1000 when they come to restaurant
    ID = id;
    tabID = "No Tab";
    // this->tableNum = tableNum;
}
Customer::Customer(std::shared_ptr<EmotionState> mood, int bankAccountAmount)
{
    this->mood = mood;
    this->bankAccountAmount = bankAccountAmount;
}
void Customer ::changeMood()
{
    mood->handleChange(shared_from_this());
}
void Customer::changedOrderProcessState()
{
    orderProcess->execute(shared_from_this());
}

void Customer::requestBill()
{
    // needs to tell the waiter that they want the bill
    hasBill = true;
}
bool Customer::payBill(char c, float t) // returns true if the customer has either paid or added the bill to a tab
{
    setTotal(t);
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
                order->setPrice(total);
                if (order != nullptr)
                {
                    tab->addOrder(order->createOrderMemento(), tabID);
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
                    tab->addOrder(order->createOrderMemento(), tabID);
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
    leave(tableNum);
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
    tabID = generateRandomString(6);
    tab = std::make_shared<Tab>();
    cout << "CustomerID: [" + tabID + "] has created a new tab" << endl;
}
void Customer::payTab()
{
    if (tab->payOrder() == true)
    {
        bankAccountAmount - tab->getTotal();
        tab->clearTab();
        cout << "CustomerID: [" + to_string(1) + " has cleared his tab" << endl;
    }
}
string Customer::printBill()
{
    string output = "";
    if (hasBill == true)
    {

       // output += "CustomerID: [" + to_string(myID) + "] Bank Account Amount: [R" + to_string(bankAccountAmount) + "] Tip Percentage: [" + to_string(mood->getTip()) + "] \nOrders: [" + to_string(ID) + "]\n";
        for (shared_ptr<Order> order : orders)
        {
            output += order->showOrder() + "\n";
        }
        output += "Total Amount: [" + to_string(getTotal()) + "]";
        return output;
    }
   // output = "CustomerID [" + to_string(myID) + "]  has not received the bill yet\n";
    return output;
}
void Customer::createOrder(int orderID, vector<shared_ptr<MenuItemOrderCommand>> commands)
{
    ID = orderID;
    std::shared_ptr<Order> order = make_shared<Order>(orderID, commands);
    orders.push_back(order);
    std::cout << "Order: " + to_string(orderID) + " has been added" << endl;
}

void Customer::beSeated(int tableNum)
{
    this->tableNum = tableNum; // set the table number for the customer when he is seated
}

int Customer::getTableNum()
{
    return tableNum;
}

void Customer::setEmotionState(std::shared_ptr<EmotionState> mood)
{
    this->mood = mood;
}

shared_ptr<Customer> Customer::getMe()
{

    return enable_shared_from_this<Customer>::shared_from_this();
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
    std::string output = "CustomerID: [" + to_string(1) + "] Mood: [" + mood->getEmotion() + "] Table Number: [" + to_string(tableNum) + "] Bank Account Amount: [" + to_string(bankAccountAmount) + "]" + " Order Status: [" + orderProcess->stateName + "]";
    return output;
}
// int Customer::getID()
// {
//     return ID;
// }
bool Customer::hasFood()
{
    if (pizza != nullptr)
    {
        return true;
    }
    return false;
}

bool Customer::leave(int tableNum)
{
    if (orderProcess->getName() == "DinnerDone" && this->tableNum == tableNum)
    {
        return true;
    }
    return false;
}

float Customer::getTotal()
{
    return total;
}

void Customer::setTotal(float t)
{
    total = t;
}

std::shared_ptr<Tab> Customer::getTab()
{
    return tab;
}