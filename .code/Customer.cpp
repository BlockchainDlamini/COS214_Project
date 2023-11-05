#include "Customer.h"
using namespace std;
Customer::Customer(int id, float bankAmount) : gameElement()
{
    bankAccountAmount = bankAmount;
    ID = id;
    tableNum = 0;
    tabID = "No Tab";
    for (int i = 0; i < 10; i++)
    {
        complaints[i] = make_shared<string>();
        happyMessages[i] = make_shared<string>();
    }
    // Assign string values using the assign method
    complaints[0]->assign("I ordered a pizza last night, and it arrived cold. I was really disappointed with the quality of the food.");
    complaints[1]->assign("The delivery took over an hour, and when my pizza finally arrived, it was completely burnt. This is unacceptable.");
    complaints[2]->assign("I found a hair in my pizza, and it completely ruined my dining experience. Hygiene should be a top priority.");
    complaints[3]->assign("The pizza was very greasy, and it gave me an upset stomach. I expected better quality from your restaurant.");
    complaints[4]->assign("I requested no onions on my pizza, but it came with onions anyway. Please pay more attention to custom orders.");
    complaints[5]->assign("The pizza crust was undercooked and doughy. It was practically inedible.");
    complaints[6]->assign("The online menu showed a variety of toppings, but when I ordered, I was told that some were not available. This inconsistency is frustrating.");
    complaints[7]->assign("The portion size of the pizza was much smaller than I expected, and I felt like I didn't get my money's worth.");
    complaints[8]->assign("The customer service was rude and unhelpful when I called to address an issue with my order.");
    complaints[9]->assign("I dined in, and the restaurant was so noisy and crowded that it was impossible to have a conversation. It really affected my experience.");

    // Assign string values to the happyMessages array
    happyMessages[0]->assign("I just wanted to say how much I love your pizza! It's always so delicious and consistently amazing.");
    happyMessages[1]->assign("Your delivery service is top-notch. The pizza always arrives hot and on time. Thank you for the great service.");
    happyMessages[2]->assign("The Margherita pizza I had at your restaurant last night was heavenly. I can't stop thinking about it.");
    happyMessages[3]->assign("Your staff is always friendly and welcoming. Dining at your restaurant feels like being part of a big, pizza-loving family.");
    happyMessages[4]->assign("I appreciate the variety of pizza options on your menu. It's great to have so many choices to suit different tastes.");
    happyMessages[5]->assign("The garlic knots that come with the pizza are the best I've ever had. They're a delightful addition to the meal.");
    happyMessages[6]->assign("I love how fresh the ingredients on your pizza are. It's clear that you use high-quality, locally sourced products.");
    happyMessages[7]->assign("The atmosphere at your restaurant is cozy and inviting. It's the perfect place to enjoy a slice or two with friends.");
    happyMessages[8]->assign("The specialty pizzas on your menu are creative and unique. It's always a pleasure to try something new.");
    happyMessages[9]->assign("I hosted a party and ordered a large pizza catering package from your restaurant. Everyone raved about the delicious pizzas. You made my event a hit!");
}
Customer::Customer(std::shared_ptr<EmotionState> mood, float bankAccountAmount) : gameElement()
{
    this->mood = mood;
    this->bankAccountAmount = bankAccountAmount;
}
Customer::Customer(float bankAccount)
{
    bankAccountAmount = bankAccount;
}
void Customer ::changeMood()
{
    mood->handleChange(this);
}

void Customer::logComplaint()
{
    if (mood->getEmotion() == "Disgruntaled" || mood->getEmotion() == "Frustrated")
    {
        cout << complaints[randomNumberForMessages()] << endl;
    }
    else if (mood->getEmotion() == "Happy" || mood->getEmotion() == "Satisfied")
    {
        cout << happyMessages[randomNumberForMessages()] << endl;
    }
}
void Customer::changedOrderProcessState()
{
    orderProcess->execute(this);
}
void Customer::requestBill()
{
    setOperation("REQUESTBILL");
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
                cout << "Customer has paid the bill, as the payment was accepted" << endl;
            }
        }
        else if (c == 'T' || c == 't' && isLoyal() == true) // has a tab and wants to add to tab
        {
            for (std::shared_ptr<Order> order : orders)
            {
                order->setPrice(total);
                if (order != nullptr)
                {
                    tab->addOrder(order->createOrderMemento(), tabID);
                }
            }
            cout << "Order has been added to the tab" << endl;
        }
        else if (c == 'T' || c == 't' && isLoyal() == false) // doesn't have a tab but wants to add
        {
            cout << "The Customer [" + to_string(myID) + "] is not a loyal customer" << endl;
        }
        else
        {
            cout << "Incorrect input, Payment Declined" << endl;
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
    int random = getRandomNumber();
    if (random <= 50)
    {
        return false;
    }
    return true;
}

void Customer::startTab()
{
    if (isLoyal() == true)
    {
        tabID = generateRandomString(6);
        tab = std::make_shared<Tab>();
        cout << "CustomerID: [" + to_string(myID) + "] has created a new tab, your tab ID: [" + tabID + "]" << endl;
    }
    else
    {
        cout << "The Customer [" + to_string(myID) + "] is not a loyal customer" << endl;
    }
}
void Customer::payTab()
{
    cout << tab->listOutstandingOrders() << endl;
    if (tab->payOrder() == true)
    {
        bankAccountAmount = tab->getTotal();
        tab->clearTab();
        cout << "CustomerID: [" + to_string(1) + " has cleared his tab" << endl;
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
vector<shared_ptr<MenuItemCommand>> Customer::addMenuItems() // for building own pizza
{
    vector<shared_ptr<MenuItemCommand>> result;
    bool done = 0;
    int base = 0;
    int topping = 0;
    int sauce = 0;
    int cheese = 0;
    bool start = true;
    bool startSauce = true;
    int sauceCount = 0;
    bool startTopping = true;
    int sauceTopping = 0;
    bool startCheese = true;
    string size = "";
    int sauceCheese = 0;
    float total = 0.0;
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
        if (base > 5)
        {
            cout << "Please enter a valid number. 1-5" << endl;
            cin >> base;
        }
        switch (base)
        {
        case 1:
            cout << "You have choosen Stuffed-crust" << endl;
            total += 34;
            result.push_back(make_shared<MakeStuffedCrust>(kitchen, size));
            break;
        case 2:
            cout << "You have choosen Thin crust" << endl;
            total += 45;
            result.push_back(make_shared<MakeThinCrust>(kitchen, size));
            break;
        case 3:
            cout << "You have choosen Double-Decker" << endl;
            total += 68;
            result.push_back(make_shared<MakeDoubleDecker>(kitchen, size));
            break;
        case 4:
            cout << "You have choosen Boiled Crust" << endl;
            total += 52;
            result.push_back(make_shared<MakeBoiledCrust>(kitchen, size));
            break;
        case 5:
            cout << "You have choosen Deep-dish" << endl;
            total += 89;
            result.push_back(make_shared<MakeDeepDish>(kitchen, size));
            break;
        default:
            start = false;
        }

        while (startSauce && sauceCount <= 4)
        {
            std::cout << "Add some sauces" << endl;
            std::cout << "1.Sweet-chilli: R76" << std::endl;
            std::cout << "2.Ranch: R63" << std::endl;
            std::cout << "3.Tomato Paste: R47" << std::endl;
            std::cout << "4.Chutney sauce: R85" << std::endl;
            std::cin >> sauce;
            if (sauce > 4)
            {
                cout << "Please enter a valid number. 1-5" << endl;
                cin >> sauce;
            }
            switch (sauce)
            {
            case 1:
                cout << "You have choosen Sweet-chilli" << endl;
                total += 76;
                result.push_back(make_shared<MakeSweetChilli>(kitchen));
                break;
            case 2:
                cout << "You have choosen Ranch" << endl;
                total += 63;
                result.push_back(make_shared<MakeRanch>(kitchen));
                break;
            case 3:
                cout << "You have choosen Tomato Paste" << endl;
                total += 47;
                result.push_back(make_shared<MakeTomatoPaste>(kitchen));
                break;
            case 4:
                cout << "You have choosen Chutney sauce" << endl;
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
            if (topping > 4)
            {
                cout << "Please enter a valid number. 1-5" << endl;
                cin >> topping;
            }
            switch (topping)
            {
            case 1:
                cout << "You have choosen Pepperoni" << endl;
                total += 91;
                result.push_back(make_shared<MakePepperoni>(kitchen));
                break;
            case 2:
                cout << "You have choosen Olives" << endl;
                total += 73;
                result.push_back(make_shared<MakeOlives>(kitchen));
                break;
            case 3:
                cout << "You have choosen Mushrooms" << endl;
                total += 58;
                result.push_back(make_shared<MakeMushrooms>(kitchen));
                break;
            case 4:
                cout << "You have choosen Chicken" << endl;
                total += 82;
                result.push_back(make_shared<MakeChicken>(kitchen));
                break;
            case 5:
                cout << "You have choosen Beef" << endl;
                total += 69;
                result.push_back(make_shared<MakeBeef>(kitchen));
                break;
            case 6:
                cout << "You have choosen Peppers" << endl;
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
            std::cout << "5.Blue Cheese: R96" << std::endl;
            std::cin >> cheese;
            if (cheese > 4)
            {
                cout << "Please enter a valid number. 1-5" << endl;
                cin >> cheese;
            }
            switch (cheese)
            {
            case 1:
                cout << "You have choosen Mozzarella" << endl;
                total += 87;
                result.push_back(make_shared<MakeMozzarella>(kitchen));
                break;
            case 2:
                cout << "You have choosen Cheddar" << endl;
                total += 72;
                result.push_back(make_shared<MakeMozzarella>(kitchen));
                break;
            case 3:
                cout << "You have choosen Gouda" << endl;
                total += 56;
                result.push_back(make_shared<MakeGouda>(kitchen));
                break;
            case 4:
                cout << "You have choosen Parmesan" << endl;
                total += 81;
                result.push_back(make_shared<MakeParmesan>(kitchen));
                break;
            case 5:
                cout << "You have choosen Blue Cheese" << endl;
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
        if (done == "yes" || done == "Yes")
        {
            start = true;
        }
        else
        {
            start = false;
        }
    }
    return result;
}
void Customer::createOrder()
{
    bool start = true;
    int orderCount = 0;
    string choice = "";
    string build = "";
    while (start)
    {
        cout << "Would you like to build your pizza?" << endl;
        cin >> build;
        if (build == "Yes" || build == "yes")
        {
            std::shared_ptr<Order> order = make_shared<Order>(ID);
            order->addMenuItems(addMenuItems());
            orders.push_back(order);
            orderCount++;
            std::cout << "Order: " + to_string(orderCount) + " has been added" << endl;
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
            std::shared_ptr<Order> order = make_shared<Order>(ID);
            order->addMenuItems(predefinedOrder());
            orders.push_back(order);
            orderCount++;
            std::cout << "Order: " + to_string(orderCount) + " has been added" << endl;
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
}
void Customer::beSeated(int table)
{
    if (table > 0)
    {
        tableNum = table;
    }
}
int Customer::getTableNum()
{
    return tableNum;
}
void Customer::setEmotionState(std::shared_ptr<EmotionState> mood)
{
    this->mood = mood;
}
// shared_ptr<Customer> Customer::getMe()
// {

//     return enable_shared_from_this<Customer>::shared_from_this();
// }
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
vector<pair<int, shared_ptr<Order>>> Customer::getOrders()
{
    vector<pair<int, shared_ptr<Order>>> vec;
    for (auto val = orders.begin(); val != orders.end(); val++)
    {
        vec.push_back(make_pair(ID, *val));
    }
    return vec;
}
bool Customer::receiveOrder(vector<shared_ptr<Pizza>> pizza)
{
    if (!pizza.empty())
    {
        this->pizza = pizza;
        for (auto it = pizza.begin(); it != pizza.end(); it++)
        {
            tab->setDescription((*it)->getDescription());
        }
        hasFood = true;
        changedOrderProcessState(); // change state to orderReceived from waiting
        return true;
    }
    return false;
}
std::string Customer::printCustomer()
{
    if (tableNum == 0)
    {
        std::string output = "CustomerID: [" + to_string(1) + "] Mood: [" + mood->getEmotion() + "] Table Number: [ Customer does not have a table yet] Bank Account Amount: [" + to_string(bankAccountAmount) + "]" + " Order Status: [" + orderProcess->stateName + "]";
        return output;
    }
    else
    {
        std::string output = "CustomerID: [" + to_string(1) + "] Mood: [" + mood->getEmotion() + "] Table Number: [" + to_string(tableNum) + "] Bank Account Amount: [" + to_string(bankAccountAmount) + "]" + " Order Status: [" + orderProcess->stateName + "]";
        return output;
    }
}
int Customer::getID()
{
    return ID;
}
void Customer::hasPizza()
{
    if (!pizza.empty())
    {
        hasFood = true;
    }
}

void Customer::leave()
{
    setOperation("LEAVE");
    changed();
    cout << "Customer has left" << endl;
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

void Customer::setKitchenReference(shared_ptr<Kitchen> ptr)
{
    kitchen = ptr;
}

void Customer::talkToWaiter()
{
    setOperation("GIVEORDER");
    hasOrdered = true;
    changedOrderProcessState(); // change state to waiting from preorder
    changed();                  // changed();
}

void Customer::getKitchenReference()
{
    setOperation("GETKITCHENREFERENCE");
    changed();
}