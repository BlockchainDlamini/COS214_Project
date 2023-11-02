#include "Customer.h"
using namespace std;

Customer::Customer(int bankAmount, int id) : gameElement()
{
    bankAccountAmount = bankAmount; // each customer brings R1000 when they come to restaurant
    ID = id;
    tabID = "No Tab";
    // kitchen
}
Customer::Customer(std::shared_ptr<EmotionState> mood, int bankAccountAmount) : gameElement()
{
    this->mood = mood;
    this->bankAccountAmount = bankAccountAmount;
}

Customer::Customer(int bankAccount) : gameElement()
{
    bankAccountAmount = bankAccount;
}

void Customer::setManager(shared_ptr<Kitchen> ptr)
{
    kitchen = ptr;
}
void Customer ::changeMood()
{
    mood->handleChange(this);
}
void Customer::changedOrderProcessState()
{
    orderProcess->execute(this);
    orderProcess->printStateChange();
}

void Customer::requestBill() // sets the hasBill to true.
{
    // needs to tell the waiter that they want the bill
    setOperation("requestbill");
    changed();
    hasBill = true;
}
void Customer::payBill(char c, float t) // returns true if the customer has either paid or added the bill to a tab
{
    changedOrderProcessState(); // take the state to dinnerdone from orderreceived
    setTotal(t);
    if (hasBill == true)
    {
        if (c == 'P' || c == 'p')
        {
            if (bankAccountAmount < total)
            {
                cout << "Customer cannot pay the bill, insufficient funds" << endl;
            }
            else
            {
                float tip = total + (total * mood->getTip());
                bankAccountAmount = bankAccountAmount - (total + tip);
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
        }
        else
        {
            cout << "Incorrect input" << endl;
        }
    }
    else
    {
        cout << "Customer has not received the bill from the waiter" << endl;
    }
    leave();
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
        cout << "CustomerID: [" + to_string(myID) + " has cleared his tab" << endl;
    }
}
string Customer::printBill()
{
    string output = "";
    if (hasBill == true)
    {

        output += "CustomerID: [" + to_string(myID) + "] Bank Account Amount: [R" + to_string(bankAccountAmount) + "] Tip Percentage: [" + to_string(mood->getTip()) + "] \nOrders: [" + to_string(ID) + "]\n";
        for (shared_ptr<Order> order : orders)
        {
            output += order->showOrder() + "\n";
        }
        output += "Total Amount: [" + to_string(getTotal()) + "]";
        return output;
    }
    output = "CustomerID [" + to_string(myID) + "]  has not received the bill yet\n";
    return output;
}

vector<shared_ptr<MenuItemCommand>> Customer::buildPizza() // for building own pizza
{
    vector<shared_ptr<MenuItemCommand>> result;
    int base;
    int topping;
    int sauce;
    int cheese;
    bool start = true;
    bool startSauce = true;
    int sauceCount = 0;
    bool startTopping = true;
    int sauceTopping = 0;
    bool startCheese = true;
    string size;
    int sauceCheese = 0;
    int total = 0;
    string choice = "";
    std::cout << "Choose a pizza size?" << endl;
    cin >> size;
    while (start)
    {
        std::cout << "Choose 1 base only" << endl;
        std::cout << "1.Stuffed-crust: R34" << endl;
        std::cout << "2.Thin crust: R45" << endl;
        std::cout << "3.Double-Decker: R68" << endl;
        std::cout << "4.Boiled: R52" << endl;
        std::cout << "5.Deep-dish: R89" << endl;
        std::cin >> base;

        switch (base)
        {
        case 1:
            total += 34;
            result.push_back(make_shared<MakeStuffedCrust>(kitchen, size));
            break;
        case 2:
            total += 45;
            result.push_back(make_shared<MakeThinCrust>(kitchen, size));
            break;
        case 3:
            total += 68;
            result.push_back(make_shared<MakeDoubleDecker>(kitchen, size));
            break;
        case 4:
            total += 52;
            result.push_back(make_shared<MakeBoiledCrust>(kitchen, size));
            break;
        case 5:
            total += 89;
            result.push_back(make_shared<MakeDeepDish>(kitchen, size));
            break;
        }

        while (startSauce && sauceCount <= 4)
        {
            std::cout << "Add some sauces" << endl;
            std::cout << "1.Sweet-chilli: R76" << std::endl;
            std::cout << "2.Ranch: R63" << std::endl;
            std::cout << "3.Tomato Paste: R47" << std::endl;
            std::cout << "4.Chutney sauce: R85" << std::endl;

            std::cin >> sauce;
            switch (sauce)
            {
            case 1:
                total += 76;
                result.push_back(make_shared<MakeSweetChilli>(kitchen));
                break;
            case 2:
                total += 63;
                result.push_back(make_shared<MakeRanch>(kitchen));
                break;
            case 3:
                total += 47;
                result.push_back(make_shared<MakeTomatoPaste>(kitchen));
                break;
            case 4:
                total += 85;
                result.push_back(make_shared<MakeChutneySauce>(kitchen));
                break;
            }
            if (sauceCount < 5)
            {
                cout << "Would you like to add another sauce" << endl;
                cin >> choice;
                if (choice == "yes" || choice == "Yes" || choice == "y")
                {
                    startSauce = true;
                }
                else
                {
                    startSauce = false;
                }
            }
        }
        while (startTopping && sauceTopping <= 6)
        {
            std::cout << "Add some toppings" << endl;
            std::cout << "1.Pepperoni: R91" << std::endl;
            std::cout << "2.Olives: R73" << std::endl;
            std::cout << "3.Mushrooms: R58" << std::endl;
            std::cout << "4.Chicken: R82" << std::endl;
            std::cout << "5.Beef: R69" << std::endl;
            std::cout << "6.Peppers: R94" << std::endl;

            std::cin >> topping;
            switch (topping)
            {
            case 1:
                total += 91;
                result.push_back(make_shared<MakePepperoni>(kitchen));
                break;
            case 2:
                total += 73;
                result.push_back(make_shared<MakeOlives>(kitchen));
                break;
            case 3:
                total += 58;
                result.push_back(make_shared<MakeMushrooms>(kitchen));
                break;
            case 4:
                total += 82;
                result.push_back(make_shared<MakeChicken>(kitchen));
                break;
            case 5:
                total += 69;
                result.push_back(make_shared<MakeBeef>(kitchen));
                break;
            case 6:
                total += 94;
                result.push_back(make_shared<MakePeppers>(kitchen));
                break;
            }
            if (sauceTopping < 7)
            {
                cout << "Would you like to add another topping" << endl;
                cin >> choice;
                if (choice == "yes" || choice == "Yes" || choice == "y")
                {
                    startTopping = true;
                }
                else
                {

                    startTopping = false;
                }
            }
        }
        while (startCheese && sauceCheese <= 5)
        {
            std::cout << "Add some cheese" << endl;
            std::cout << "1.Mozzarella: R87" << std::endl;
            std::cout << "2.Cheddar: R72" << std::endl;
            std::cout << "3.Gouda: R56" << std::endl;
            std::cout << "4.Parmesan: R81" << std::endl;
            std::cout << "5.Blue: R96" << std::endl;

            std::cin >> cheese;
            switch (cheese)
            {
            case 1:
                total += 87;
                result.push_back(make_shared<MakeMozzarella>(kitchen));
                break;
            case 2:
                total += 72;
                result.push_back(make_shared<MakeMozzarella>(kitchen));
                break;
            case 3:
                total += 56;
                result.push_back(make_shared<MakeGouda>(kitchen));
                break;
            case 4:
                total += 81;
                result.push_back(make_shared<MakeParmesan>(kitchen));
                break;
            case 5:
                total += 96;
                result.push_back(make_shared<MakeBlueCheese>(kitchen));
                break;
            }
            if (sauceCheese < 6)
            {
                cout << "Would you like to add another cheese" << endl;
                cin >> choice;
                if (choice == "yes" || choice == "Yes" || choice == "y")
                {
                    startCheese = true;
                }
                else
                {

                    startCheese = false;
                }
            }
        }
        start = false;
    }
    setTotal(total);
    return result;
}
vector<shared_ptr<MenuItemCommand>> Customer::predefinedOrder()
{
    vector<shared_ptr<MenuItemCommand>> result;
    int pizza;
    bool start = true;
    string size;
    string done;
    cout << "Please choose a pizza from the predefined menu" << endl;
    while (start)
    {
        cout << "Pick a size for your pizza \n1.Large\n2.Medium\n3.Small" << endl;
        cin >> size;
        cout << "1.Mozzarella Pizza R120" << endl;
        cout << "2.Pepperoni Pizza R122" << endl;
        cout << "3.Cheesy Pizza R69" << endl;
        cout << "4.Chicken Double Decker Pizza R42069" << endl;
        cin >> pizza;
        switch (pizza)
        {
        case 1:
            result.push_back(make_shared<MakeThinCrust>(kitchen, size));
            result.push_back(make_shared<MakeMozzarella>(kitchen));
            total += 120;
            break;
        case 2:
            result.push_back(make_shared<MakeThinCrust>(kitchen, size));
            result.push_back(make_shared<MakePepperoni>(kitchen));
            total += 122;
            break;
        case 3:
            result.push_back(make_shared<MakeThinCrust>(kitchen, size));
            result.push_back(make_shared<MakeMozzarella>(kitchen));
            result.push_back(make_shared<MakeParmesan>(kitchen));
            result.push_back(make_shared<MakeCheddar>(kitchen));
            total += 69;
            break;
        case 4:
            result.push_back(make_shared<MakeDoubleDecker>(kitchen, size));
            result.push_back(make_shared<MakeChicken>(kitchen));
            total += 42069;
            break;
        }
        start = false;
    }
    return result;
}
void Customer::createOrder()
{
    bool start = true;
    int orderCount;
    string choice;
    string build;
    int pizza;
    while (start)
    {
        cout << "Would you like to build your pizza?" << endl;
        cin >> build;
        if (build == "Yes" || build == "yes")
        {
            std::shared_ptr<Order> order = make_shared<Order>(ID, total);
            order->addMenuItems(buildPizza());
            orders.push_back(order);
            orderCount++;
            std::cout << "Order No." + to_string(orderCount) + " has been added to you cart of orders for Customer " + to_string(myID) << endl;
            cout << "Would you like to make another order?" << endl;
            cin >> choice;
            if (choice == "yes" || choice == "Yes")
            {
                start = true;
            }
            else
            {
                start = false;
            }
        }
        else
        {
            std::shared_ptr<Order> order = make_shared<Order>(ID, total);
            order->addMenuItems(predefinedOrder());
            std::cout << "Order No." + to_string(orderCount) + " has been added to you cart of orders for Customer " + to_string(myID) << endl;
            cout << "Would you like to make another order?" << endl;
            cin >> choice;
            if (choice == "yes" || choice == "Yes")
            {
                start = true;
            }
            else
            {
                start = false;
            }
        }
    }
    hasOrdered = true;
    changedOrderProcessState();
}

void Customer::beSeated(int table)
{
    tableNum = table; // set the table number for the customer when he is seated
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
        tab->setDescription(pizza->getDescription());
        hasFood = true;
        changedOrderProcessState(); // change state to orderReceived from waiting
        return true;
    }
    return false;
}

std::string Customer::printCustomer()
{
    std::string output = "CustomerID: [" + to_string(1) + "] Mood: [" + mood->getEmotion() + "] Table Number: [" + to_string(tableNum) + "] Bank Account Amount: [" + to_string(bankAccountAmount) + "]" + " Order Status: [" + orderProcess->stateName + "]";
    return output;
}
int Customer::getID()
{
    return ID;
}
void Customer::hasPizza()
{
    if (pizza != nullptr)
    {
        hasFood = true;
    }
}

void Customer::leave()
{
    setOperation("leave");
    changed();
    cout << "Customer has left " << endl;
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

void Customer::talkToWaiter()
{
    setOperation("giveorder");
    hasOrdered = true;
    changedOrderProcessState(); // change state to waiting from preorder
    changed();                  // changed();
}

void Customer::setKitchenReference(shared_ptr<Kitchen> ptr)
{
    kitchen = ptr;
}

void Customer::getKitchenReference()
{
    setOperation("GETKITCHENREFENCE");
    changed();
}
