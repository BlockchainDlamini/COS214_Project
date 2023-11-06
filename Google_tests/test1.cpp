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
