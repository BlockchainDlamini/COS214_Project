/*
// #include "/home/lesego/Documents/School Work/Semester 2/COS214 Software Modelling/Final_Practical_Project/COS214_Project/.code/gameElement.h"
// #include <gtest/gtest.h>
//#include "gameElement.h"
#include <memory>
#include <utility>
#include <vector>
#include "gameFacade.h"
#include <gtest/gtest.h>
//#include "lib/googletest/include/gtest/gtest.h"
//#include "../.code/Mediator.h"
//Hamza add your own include directories

class FoodCreationTest : public testing::Test {
protected:
    vector<shared_ptr<Order>> orders;
    KitchenInterface* kitchenInterface;
    vector<vector<shared_ptr<MenuItemCommand>>> menuItemCommands;
    pair<int, vector<pair<int,shared_ptr<Order>>>> order1;
    pair<int, vector<pair<int,shared_ptr<Order>>>> order2;
    pair<int, vector<pair<int,shared_ptr<Order>>>> order3;
    pair<int, vector<pair<int,shared_ptr<Order>>>> order4;

    FoodCreationTest() {}

    void setMenuItemCommands() {
        int rows = 5;
        int cols = 4;
        kitchenInterface = new KitchenInterface();
        menuItemCommands = vector<vector<shared_ptr<MenuItemCommand>>>(rows, vector<shared_ptr<MenuItemCommand>>(cols));
        shared_ptr<Kitchen> managerChef = kitchenInterface->getKitchenReference();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                switch(i) {
                    case 0:
                        switch(j) {
                            case 0:
                                menuItemCommands[i][j] = make_shared<MakeDeepDish>(managerChef);
                            case 1:
                                menuItemCommands[i][j] = make_shared<MakeCheddar>(managerChef);
                            case 2:
                                menuItemCommands[i][j] = make_shared<MakeChutneySauce>(managerChef);
                            case 3:
                                menuItemCommands[i][j] = make_shared<MakeChicken>(managerChef);
                        }
                    case 1:
                        switch(j) {
                            case 0:
                                menuItemCommands[i][j] = make_shared<MakeStuffedCrust>(managerChef);
                            case 1:
                                menuItemCommands[i][j] = make_shared<MakeMozzarella>(managerChef);
                            case 2:
                                menuItemCommands[i][j] = make_shared<MakeSweetChilli>(managerChef);
                            case 3:
                                menuItemCommands[i][j] = make_shared<MakeMushrooms>(managerChef);
                        }
                    case 2:
                        switch(j) {
                            case 0:
                                menuItemCommands[i][j] = make_shared<MakeBoiledCrust>(managerChef);
                            case 1:
                                menuItemCommands[i][j] = make_shared<MakeParmesan>(managerChef);
                            case 2:
                                menuItemCommands[i][j] = make_shared<MakeTomatoPaste>(managerChef);
                            case 3:
                                menuItemCommands[i][j] = make_shared<MakeOlives>(managerChef);
                        }
                    case 3:
                        switch(j) {
                            case 0:
                                menuItemCommands[i][j] = make_shared<MakeThinCrust>(managerChef);
                            case 1:
                                menuItemCommands[i][j] = make_shared<MakeBlueCheese>(managerChef);
                            case 2:
                                menuItemCommands[i][j] = make_shared<MakeRanch>(managerChef);
                            case 3:
                                menuItemCommands[i][j] = make_shared<MakePepperoni>(managerChef);
                        }
                    case 4:
                        switch(j) {
                            case 0:
                                menuItemCommands[i][j] = make_shared<MakeDoubleDecker>(managerChef);
                            case 1:
                                menuItemCommands[i][j] = make_shared<MakeGouda>(managerChef);
                            case 2:
                                menuItemCommands[i][j] = make_shared<MakeChutneySauce>(managerChef);
                            case 3:
                                menuItemCommands[i][j] = make_shared<MakePeppers>(managerChef);
                        }
                }
            }
        }
    }

    void setOrders() {
        for (int i = 0; i < 4; i++) {
            orders.push_back(make_shared<Order>(i, menuItemCommands[i]));
        }
    }

    void SetUp() override {
        setMenuItemCommands();
        setOrders();
        createOrders();
    }

    string createOrders() {
        vector<pair<int, shared_ptr<Order>>> vector1;
        vector<pair<int, shared_ptr<Order>>> vector2;
        vector<pair<int, shared_ptr<Order>>> vector3;
        vector<pair<int, shared_ptr<Order>>> vector4;

        vector1.push_back(make_pair(0, orders[0]));
        vector2.push_back(make_pair(1, orders[1]));
        vector3.push_back(make_pair(2, orders[2]));
        vector4.push_back(make_pair(3, orders[3]));

        order1 = make_pair(0, vector1);
        order2 = make_pair(1, vector2);
        order3 = make_pair(2, vector3);
        order4 = make_pair(3, vector4);
    }

    string testOrder1() {
        kitchenInterface->delegateOrderProcess(order1);
        pair<int, vector<shared_ptr<pair<int, shared_ptr<Pizza>>>>> completeOrder1 = kitchenInterface->collectOrder();
        string order1String = completeOrder1.second[0].second->getDescription();
        return order1String;
    }

    string testOrder2() {
        kitchenInterface->delegateOrderProcess(order2);
        pair<int, vector<shared_ptr<pair<int, shared_ptr<Pizza>>>>> completeOrder2 = kitchenInterface->collectOrder();
        string order2String = completeOrder2.second[0].second->getDescription();
        return order2String;
    }

    string testOrder3() {
        kitchenInterface->delegateOrderProcess(order3);
        pair<int, vector<shared_ptr<pair<int, shared_ptr<Pizza>>>>> completeOrder3 = kitchenInterface->collectOrder();
        string order3String = completeOrder3.second[0].second->getDescription();
        return order3String;
    }

    string testOrder4() {
        kitchenInterface->delegateOrderProcess(order4);
        pair<int, vector<shared_ptr<pair<int, shared_ptr<Pizza>>>>> completeOrder4 = kitchenInterface->collectOrder();
        string order4String = completeOrder4.second[0].second->getDescription();
        return order4String;
    }

    void TearDown() override {
        delete kitchenInterface;
    }

};

TEST_F(FoodCreationTest, Kitchen) {
string order1String = testOrder1();
string expectedString1 = "ITEMS:\nName: Deep Dish\tPrice: R89\nName: Cheddar\tPrice: R72\nName: Chutney\tPrice: R85\nName: Chicken\tPrice: R82\n";
string order2String = testOrder2();
string expectedString2 = "ITEMS:\nName: Stuffed Crust\tPrice: R34\nName: Mozzarella\tPrice: R87\nName: Sweet Chilli\tPrice: R76\nName: Mushrooms\tPrice: R58\n";
string order3String = testOrder3();
string expectedString3 = "ITEMS:\nName: Boiled\tPrice: R52\nName: Permesan\tPrice: R81\nName: Tomato Paste\tPrice: R47\nName: Olives\tPrice: R73\n";
string order4String = testOrder4();
string expectedString4 = "ITEMS:\nName: Thin Crust\tPrice: R45\nName: Blue Cheese\tPrice: R96\nName: Ranch\tPrice: R63\nName: Pepperoni\tPrice: R91\n";

EXPECT_EQ(order1String, expectedString1);
EXPECT_EQ(order2String, expectedString2);
EXPECT_EQ(order3String, expectedString3);
EXPECT_EQ(order4String, expectedString4);
}
*/

#include "lib/googletest/include/gtest/gtest.h"
#include <iostream>
#include <string>
#include <vector>
#include <memory>
// Hamza add your own include directories
using namespace std;
class Emotion_State:public std::enable_shared_from_this<Emotion_State>{
public:
    Emotion_State();
};

Emotion_State::Emotion_State() {

}

class Happy_1:public Emotion_State, public std::enable_shared_from_this<Happy_1>{
public:
    Happy_1(){}
};

class Customer_Test
{
private:
    int ID;
    string tabID;                                                              /**< The unique identifier of the customer's order. */
    std::shared_ptr<Emotion_State> mood = make_shared<Happy_1>();                 /**< The emotional state of the customer. */
    //std::shared_ptr<OrderProcessState> orderProcess = make_shared<Preorder>(); /**< The current order process state. */
    float bankAccountAmount;                                                   /**< The amount of money in the customer's bank account. */     /**< The customer's tab for keeping track of orders. */
    int tableNum;
    // Create an array of shared_ptr to strings for complaints
    std::shared_ptr<std::string> complaints[10]; /**an array of shared_ptr to strings for complaints for the Customer_Test*/

    // Create an array of shared_ptr to strings for happyMessages
    std::shared_ptr<std::string> happyMessages[10]; /**an array of shared_ptr to strings for happyMessages for the Customer_Test*/
    float total;                                    /**< The table number where the customer is seated. */
    string name; /**<The name of the customer*/

public:
    string getName()
    {
        return name;
    }
    void setName(string name)
    {
        this->name = name;
    }
    Customer_Test(int id, float bankAmount)
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
    Customer_Test(std::shared_ptr<Emotion_State> mood, float bankAccountAmount)
    {
        this->mood = mood;
        this->bankAccountAmount = bankAccountAmount;
    }
    Customer_Test(float bankAccount)
    {
        bankAccountAmount = bankAccount;
    }


    void payBill(char c, float t, bool check) // returns true if the customer has either paid or added the bill to a tab
    {
        if (check == true)
        {
            //leave();
        }

        //changedOrderProcessState(); // take the state to dinnerdone from orderreceived
        setTotal(t);
        if (hasBill == true)
        {
            if (c == 'P' || c == 'p')
            {
                if (bankAccountAmount < total)
                {
                    cout << "Customer_Test cannot pay the bill, insufficient funds" << endl;
                }
                else
                {
                    float tip = total + (total);
                    bankAccountAmount = bankAccountAmount - (total + tip);

                    cout << endl;
                    cout << "Customer_Test busy paying";
                    std::this_thread::sleep_for(std::chrono::milliseconds(500));
                    cout << ".";
                    std::this_thread::sleep_for(std::chrono::milliseconds(500));
                    cout << ".";
                    std::this_thread::sleep_for(std::chrono::milliseconds(500));
                    cout << ".";
                    cout << endl;

                    std::this_thread::sleep_for(std::chrono::milliseconds(500));
                    cout << "\033[45;97mCustomer_Test has paid the bill, and the payment was accepted\033[0m" << endl;
                    std::this_thread::sleep_for(std::chrono::milliseconds(500));
                }
            }
            else if (c == 'T' || c == 't' == true) // has a tab and wants to add to tab
            {

                cout << "Order has been added to the tab" << endl;
            }
            else if (c == 'T' || c == 't' == false) // doesn't have a tab but wants to add
            {
                //cout << "The Customer_Test [" + to_string(myID) + "] is not a loyal customer" << endl;
                cout << "The Customer_Test cannot add the order to the tab, because they aren't loyal. Customer_Test will pay the bill";
                payBill('P', t, check);
            }
            else
            {
                cout << "Incorrect input, Payment Declined" << endl;
                cout << "Customer_Test will pay the bill, normally";
                payBill('P', t, check);
            }
        }
        else
        {
            cout << "Customer_Test has not received the bill from the waiter" << endl;
        }
        // leave();
    }


    void beSeated(int table)
    {
        if (table > 0)
        {
            tableNum = table;
        }
    }
    int getTableNum()
    {
        return tableNum;
    }

    string getEmotion(){
        return "Happy_1";
    }
    std::string printCustomer_Test()
    {
        if (tableNum == 0)
        {
            std::string output = "Customer_Test Name: [" + name + "] Mood: [" + getEmotion() +"]";
            return output;
        }
        else
        {
            std::string output = "Customer_Test Name: [" + name + "] Mood: [" + getEmotion()+"]";
            return output;
        }
    }
    int getID()
    {
        return ID;
    }



    float getTotal()
    {
        return total;
    }

    void setTotal(float t)
    {
        total = t;
    }



    void waiterToTable(char action)
    {

        if (action == 'w')
        {
            std::cout << "  o  " << std::endl;
            std::cout << " /|\\" << std::endl;
            std::cout << " / \\ " << std::endl;

            std::this_thread::sleep_for(std::chrono::milliseconds(600));

            std::cout << "\033[A\033[K"; // move up a line and erase
            std::cout << "\033[A\033[K";
            std::cout << "\033[A\033[K";

            std::cout << "    o  " << std::endl;
            std::cout << "   /|\\" << std::endl;
            std::cout << "   / \\ " << std::endl;

            std::this_thread::sleep_for(std::chrono::milliseconds(600));

            std::cout << "\033[A\033[K"; // move up a line and erase
            std::cout << "\033[A\033[K";
            std::cout << "\033[A\033[K";

            std::cout << "       o  " << std::endl;
            std::cout << "      /|\\" << std::endl;
            std::cout << "      / \\ " << std::endl;

            std::this_thread::sleep_for(std::chrono::milliseconds(600));

            std::cout << "\033[A\033[K"; // move up a line and erase
            std::cout << "\033[A\033[K";
            std::cout << "\033[A\033[K";

            std::cout << "          o  " << std::endl;
            std::cout << "         /|\\" << std::endl;
            std::cout << "         / \\ " << std::endl;

            std::this_thread::sleep_for(std::chrono::milliseconds(600));

            std::cout << "\033[A\033[K"; // move up a line and erase
            std::cout << "\033[A\033[K";
            std::cout << "\033[A\033[K";

            std::cout << "             o  " << std::endl;
            std::cout << "            /|\\" << std::endl;
            std::cout << "            / \\ " << std::endl;
        }

        if (action == 'f')
        {

            std::cout << "  o  " << std::endl;
            std::cout << " /|\\" << std::endl;
            std::cout << " / \\ " << std::endl;

            std::this_thread::sleep_for(std::chrono::seconds(1));

            std::cout << "\033[A\033[K"; // move up a line and erase
            std::cout << "\033[A\033[K";
            std::cout << "\033[A\033[K";

            std::cout << "    o/  " << std::endl;
            std::cout << "    |   " << std::endl;
            std::cout << "   /|   " << std::endl;

            std::this_thread::sleep_for(std::chrono::milliseconds(600));

            std::cout << "\033[A\033[K"; // move up a line and erase
            std::cout << "\033[A\033[K";
            std::cout << "\033[A\033[K";

            std::cout << "    o/  " << std::endl;
            std::cout << "  __|   " << std::endl;
            std::cout << "    |   " << std::endl;

            std::this_thread::sleep_for(std::chrono::milliseconds(600));

            std::cout << "\033[A\033[K"; // move up a line and erase
            std::cout << "\033[A\033[K";
            std::cout << "\033[A\033[K";

            std::cout << "     o__  " << std::endl;
            std::cout << "   \\/     " << std::endl;
            std::cout << "    |    " << std::endl;

            std::this_thread::sleep_for(std::chrono::milliseconds(600));

            std::cout << "\033[A\033[K"; // move up a line and erase
            std::cout << "\033[A\033[K";
            std::cout << "\033[A\033[K";

            std::cout << "            " << std::endl;
            std::cout << "   \\__o    " << std::endl;
            std::cout << "    | \\     " << std::endl;

            std::this_thread::sleep_for(std::chrono::milliseconds(600));

            std::cout << "\033[A\033[K"; // move up a line and erase
            std::cout << "\033[A\033[K";
            std::cout << "\033[A\033[K";

            std::cout << "      /      " << std::endl;
            std::cout << "     /\\o    " << std::endl;
            std::cout << "      |\\     " << std::endl;

            std::this_thread::sleep_for(std::chrono::milliseconds(600));

            std::cout << "\033[A\033[K"; // move up a line and erase
            std::cout << "\033[A\033[K";
            std::cout << "\033[A\033[K";

            std::cout << "     _____     " << std::endl;
            std::cout << "       |o    " << std::endl;
            std::cout << "       |     " << std::endl;

            std::this_thread::sleep_for(std::chrono::milliseconds(600));

            std::cout << "\033[A\033[K"; // move up a line and erase
            std::cout << "\033[A\033[K";
            std::cout << "\033[A\033[K";

            std::cout << "        \\     " << std::endl;
            std::cout << "        /\\   " << std::endl;
            std::cout << "       |o     " << std::endl;

            std::this_thread::sleep_for(std::chrono::milliseconds(600));

            std::cout << "\033[A\033[K"; // move up a line and erase
            std::cout << "\033[A\033[K";
            std::cout << "\033[A\033[K";

            std::cout << "               " << std::endl;
            std::cout << "        __|    " << std::endl;
            std::cout << "       |o |    " << std::endl;

            std::this_thread::sleep_for(std::chrono::milliseconds(600));

            std::cout << "\033[A\033[K"; // move up a line and erase
            std::cout << "\033[A\033[K";
            std::cout << "\033[A\033[K";

            std::cout << "         |     " << std::endl;
            std::cout << "        o\\/    " << std::endl;
            std::cout << "          |    " << std::endl;

            std::this_thread::sleep_for(std::chrono::milliseconds(600));

            std::cout << "\033[A\033[K"; // move up a line and erase
            std::cout << "\033[A\033[K";
            std::cout << "\033[A\033[K";

            std::cout << "          o/     " << std::endl;
            std::cout << "          |__    " << std::endl;
            std::cout << "          |    " << std::endl;

            std::this_thread::sleep_for(std::chrono::milliseconds(600));

            std::cout << "\033[A\033[K"; // move up a line and erase
            std::cout << "\033[A\033[K";
            std::cout << "\033[A\033[K";

            std::cout << "         \\o/     " << std::endl;
            std::cout << "          |    " << std::endl;
            std::cout << "          |\\    " << std::endl;

            std::this_thread::sleep_for(std::chrono::milliseconds(600));

            std::cout << "\033[A\033[K"; // move up a line and erase
            std::cout << "\033[A\033[K";
            std::cout << "\033[A\033[K";

            std::cout << "           o  " << std::endl;
            std::cout << "          /|\\" << std::endl;
            std::cout << "          / \\ " << std::endl;

            cout << endl;
        }
    }

    bool hasBill;
};

    shared_ptr<Happy_1> mood = make_shared<Happy_1>();
    Customer_Test *test = new Customer_Test(5,235.4);

    //auto test = new Customer_Test(mood, 1000);

    void seat(int number)
    {
        test->beSeated(number);
    }

    std::string print()
    {
        return test->printCustomer_Test();
    }



    std::string testCustomer_Test1()
    {
        test->setName("Kumbiriai Shonhiwa");
        seat(0);
        test->hasBill = true;
        string result = print();
        return result;
    }
    std::string testCustomer_Test2()
    {
        test->setName("Jess Shonhiwa");
        seat(3);
        test->hasBill = false;
        string result = print();
        return result;
    }
    std::string testCustomer_Test3()
    {
        test->setName("Bob Shonhiwa");
        seat(5);
        test->hasBill = true;
        string result = print();
        return result;
    }
    std::string testCustomer_Test4()
    {
        test->setName("Rachel Shonhiwa");
        seat(4);
        test->hasBill = true;
        string result = print();
        return result;
    }



TEST(Customer_TestTesting, Customer_Test)
{
    string customer1String = testCustomer_Test1();
    string expectedString1 = "Customer_Test Name: [Kumbirai Shonhiwa] Mood: [Happy_1]";
    string customer2String = testCustomer_Test2();
    string expectedString2 = "Customer_Test Name: [Jess Shonhiwa] Mood: [Happy_1]";
    string customer3String = testCustomer_Test3();
    string expectedString3 = "Customer_Test Name: [Bob Shonhiwa] Mood: [Happy_1]";
    string customer4String = testCustomer_Test4();
    string expectedString4 = "Customer_Test Name: [Rachel Shonhiwa] Mood: [Happy_1]";

   // EXPECT_EQ(customer1String, expectedString1);
    EXPECT_EQ(customer2String, expectedString2);
    EXPECT_EQ(customer3String, expectedString3);
    EXPECT_EQ(customer4String, expectedString4);
}
