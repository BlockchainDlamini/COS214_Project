#include "Customer.h"
using namespace std;
string Customer::getName()
{
    return name;
}
void Customer::setName(string name)
{
    this->name = name;
}
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
    hasBill = true;
    setOperation("REQUESTBILL");
    changed();
    
}
void Customer::payBill(char c, float t, bool check) // returns true if the customer has either paid or added the bill to a tab
{
    if (check == true) {
        leave();
    }
    
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
    //leave();
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
        cout << "Customer Name: [" + name + "] has created a new tab, your tab ID: [" + tabID + "]" << endl;
    }
    else
    {
        cout << "The Customer [" + name + "] is not a loyal customer" << endl;
    }
}
void Customer::payTab()
{
    cout << tab->listOutstandingOrders() << endl;
    if (tab->payOrder() == true)
    {
        bankAccountAmount = tab->getTotal();
        tab->clearTab();
        cout << "Customer Name: [" + name + "] has cleared his tab" << endl;
    }
}
string Customer::printBill()
{
    string output = "";
    if (hasBill == true)
    {

        output += "Customer Name: [" + name + "] Bank Account Amount: [R" + to_string(bankAccountAmount) + "] Tip Percentage: [" + to_string(mood->getTip()) + "] \nOrders: [" + to_string(ID) + "]\n";
        for (shared_ptr<Order> order : orders)
        {
            output += order->showOrder() + "\n";
        }
        output += "Total Amount: [" + to_string(getTotal()) + "]";
        return output;
    }
    output = "Customer Name [" + name + "]  has not received the bill yet\n";
    return output;
}
vector<shared_ptr<MenuItemCommand>> Customer::addMenuItems() // for building own pizza
{
    getKitchenReference();
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
    std::cout << "\033[47;30mChoose a pizza size! (S/M/L)\033[0m" << std::endl;


    cin >> size;
    while (start)
    {
        std::cout << "\033[47;30mChoose one base only from the list below: \033[0m" << std::endl;
        std::cout << "\033[36m1.Stuffed-crust: R34\033[0m" << endl;
        std::cout << "\033[36m2.Thin crust: R45\033[0m" << endl;
        std::cout << "\033[36m3.Double-Decker: R68\033[0m" << endl;
        std::cout << "\033[36m4.Boiled: R52\033[0m" << endl;
        std::cout << "\033[36m5.Deep-dish: R89\033[0m" << endl;
        std::cin >> base;
        if (base > 5)
        {
            std::cout << "\033[47;30mPlease enter a valid number. 1-5\033[0m" << std::endl;
            cin >> base;
        }
        switch (base)
        {
            case 1:
                std::cout << "\033[34m* You have chosen Stuffed-crust *\033[0m" << endl;
                total += 34;
                result.push_back(make_shared<MakeStuffedCrust>(kitchen, size));
                break;
            case 2:
                std::cout << "\033[34m* You have chosen Thin crust *\033[0m" << endl;
                total += 45;
                result.push_back(make_shared<MakeThinCrust>(kitchen, size));
                break;
            case 3:
                std::cout << "\033[34m* You have chosen Double-Decker *\033[0m" << endl;
                total += 68;
                result.push_back(make_shared<MakeDoubleDecker>(kitchen, size));
                break;
            case 4:
                std::cout << "\033[34m* You have chosen Boiled Crust *\033[0m" << endl;
                total += 52;
                result.push_back(make_shared<MakeBoiledCrust>(kitchen, size));
                break;
            case 5:
                std::cout << "\033[34m* You have chosen Deep-dish *\033[0m" << endl;
                total += 89;
                result.push_back(make_shared<MakeDeepDish>(kitchen, size));
                break;
            default:
                start = false;
        }

        while (startSauce && sauceCount <= 4)
        {
            std::cout << "\033[47;30mAdd some sauces from the list below: \033[0m" << std::endl;
            std::cout << "\033[36m1.Sweet-chilli: R76\033[0m" << endl;
            std::cout << "\033[36m2.Ranch: R63\033[0m" << endl;
            std::cout << "\033[36m3.Tomato Paste: R47\033[0m" << endl;
            std::cout << "\033[36m4.Chutney sauce: R85\033[0m" << endl;
            std::cin >> sauce;
            if (sauce > 4)
            {
                cout << "Please enter a valid number. 1-5" << endl;
                cin >> sauce;
            }
            switch (sauce)
            {
                case 1:
                    std::cout << "\033[34m* You have chosen Sweet-chilli *\033[0m" << endl;
                    total += 76;
                    result.push_back(make_shared<MakeSweetChilli>(kitchen));
                    break;
                case 2:
                    std::cout << "\033[34m* You have chosen Ranch *\033[0m" << endl;
                    total += 63;
                    result.push_back(make_shared<MakeRanch>(kitchen));
                    break;
                case 3:
                    std::cout << "\033[34m* You have chosen Tomato Paste *\033[0m" << endl;
                    total += 47;
                    result.push_back(make_shared<MakeTomatoPaste>(kitchen));
                    break;
                case 4:
                    std::cout << "\033[34m* You have chosen Chutney sauce *\033[0m" << endl;
                    total += 85;
                    result.push_back(make_shared<MakeChutneySauce>(kitchen));
                    break;
            }
            if (sauceCount < 5)
            {
                std::cout << "\033[47;30mWould you like to add another sauce? (yes/no) \033[0m" << std::endl;
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
            std::cout << "\033[47;30mAdd some toppings from the list below: \033[0m" << std::endl;
            std::cout << "\033[36m1.Pepperoni: R91\033[0m" << endl;
            std::cout << "\033[36m2.Olives: R73\033[0m" << endl;
            std::cout << "\033[36m3.Mushrooms: R58\033[0m" << endl;
            std::cout << "\033[36m4.Chicken: R82\033[0m" << endl;
            std::cout << "\033[36m5.Beef: R69\033[0m" << endl;
            std::cout << "\033[36m6.Peppers: R94\033[0m" << endl;
            std::cin >> topping;
            if (topping > 4)
            {
                cout << "Please enter a valid number. 1-5" << endl;
                cin >> topping;
            }
            switch (topping)
            {
                case 1:
                    std::cout << "\033[34m* You have chosen Pepperoni *\033[0m" << endl;
                    total += 91;
                    result.push_back(make_shared<MakePepperoni>(kitchen));
                    break;
                case 2:
                    std::cout << "\033[34m* You have chosen Olives *\033[0m" << endl;
                    total += 73;
                    result.push_back(make_shared<MakeOlives>(kitchen));
                    break;
                case 3:
                    std::cout << "\033[34m* You have chosen Mushrooms *\033[0m" << endl;
                    total += 58;
                    result.push_back(make_shared<MakeMushrooms>(kitchen));
                    break;
                case 4:
                    std::cout << "\033[34m* You have chosen Chicken *\033[0m" << endl;
                    total += 82;
                    result.push_back(make_shared<MakeChicken>(kitchen));
                    break;
                case 5:
                    std::cout << "\033[34m* You have chosen Beef *\033[0m" << endl;
                    total += 69;
                    result.push_back(make_shared<MakeBeef>(kitchen));
                    break;
                case 6:
                    std::cout << "\033[34m* You have chosen Peppers *\033[0m" << endl;
                    total += 94;
                    result.push_back(make_shared<MakePeppers>(kitchen));
                    break;
            }
            if (sauceTopping < 7)
            {
                std::cout << "\033[47;30mWould you like to add another topping? (yes/no)\033[0m" << std::endl;

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
            std::cout << "\033[47;30mAdd cheese from the list of options below: \033[0m" << std::endl;
            std::cout << "\033[36m1.Mozzarella: R87\033[0m" << endl;
            std::cout << "\033[36m2.Cheddar: R72\033[0m" << endl;
            std::cout << "\033[36m3.Gouda: R56\033[0m" << endl;
            std::cout << "\033[36m4.Parmesan: R81\033[0m" << endl;
            std::cout << "\033[36m5.Blue Cheese: R96\033[0m" << endl;
            std::cin >> cheese;
            if (cheese > 4)
            {
                cout << "Please enter a valid number. 1-5" << endl;
                cin >> cheese;
            }
            switch (cheese)
            {
                case 1:
                    std::cout << "\033[34m* You have chosen Mozzarella *\033[0m" << endl;

                    total += 87;
                    result.push_back(make_shared<MakeMozzarella>(kitchen));
                    break;
                case 2:
                    std::cout << "\033[34m* You have chosen Cheddar *\033[0m" << endl;

                    total += 72;
                    result.push_back(make_shared<MakeMozzarella>(kitchen));
                    break;
                case 3:
                    std::cout << "\033[34m* You have chosen Gouda *\033[0m" << endl;

                    total += 56;
                    result.push_back(make_shared<MakeGouda>(kitchen));
                    break;
                case 4:
                    std::cout << "\033[34m*You have chosen Parmesan *\033[0m" << endl;

                    total += 81;
                    result.push_back(make_shared<MakeParmesan>(kitchen));
                    break;
                case 5:
                    std::cout << "\033[34m* You have chosen Blue Cheese *\033[0m" << endl;

                    total += 96;
                    result.push_back(make_shared<MakeBlueCheese>(kitchen));
                    break;
            }
            if (sauceCheese < 6)
            {
                std::cout << "\033[47;30mWould you like to add another cheese? (yes/no)\033[0m" << std::endl;

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
    getKitchenReference();
    vector<shared_ptr<MenuItemCommand>> result;
    int pizza = 0;
    bool start = true;
    string size;
    string done;
    std::cout << "\033[47;30mPlease choose a pizza from the predefined menu \033[0m" << std::endl;

    while (start)
    {
        std::cout << "\033[47;30mPick a size for your pizza : 1.Large 2.Medium 3.Small \033[0m" << std::endl;

        cin >> size;
        std::cout << "\033[36m1.Mozzarella Pizza R120\033[0m" << endl;
        std::cout << "\033[36m2.Pepperoni Pizza R122\033[0m" << endl;
        std::cout << "\033[36m3.Cheesy Pizza R69\033[0m" << endl;
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
        std::cout << "\033[47;30mWould you like to build your own pizza from scratch? (yes/no)\033[0m" << std::endl;

        cin >> build;
        if (build == "Yes" || build == "yes")
        {
            std::shared_ptr<Order> order = make_shared<Order>(ID);
            order->addMenuItems(addMenuItems());
            orders.push_back(order);
            orderCount++;
            std::cout << "Order: " + to_string(orderCount) + " has been added" << endl;
            std::cout << "\033[47;30mWould you like to make another order? (yes/no)\033[0m" << std::endl;

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
        std::string output = "Customer Name: [" + name + "] Mood: [" + mood->getEmotion() + "] Table Number: [ Customer does not have a table yet] Bank Account Amount: [" + to_string(bankAccountAmount) + "]" + " Order Status: [" + orderProcess->stateName + "]";
        return output;
    }
    else
    {
        std::string output = "Customer Name: [" + name + "] Mood: [" + mood->getEmotion() + "] Table Number: [" + to_string(tableNum) + "] Bank Account Amount: [" + to_string(bankAccountAmount) + "]" + " Order Status: [" + orderProcess->stateName + "]";
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
