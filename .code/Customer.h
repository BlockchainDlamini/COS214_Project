#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "EmotionState.h"
#include "OrderProcessState.h"
#include "Preorder.h"
#include "Order.h"
#include "gameElement.h"
#include "Pizza.h"
#include "Tab.h"
#include <iostream>
#include <memory>
#include <vector>
using namespace std;
// class OrderProcessState;
// class EmotionState;
class Customer : public enable_shared_from_this<Customer>, public gameElement
{
private:
    int ID;
    std::shared_ptr<EmotionState> mood = nullptr;
    std::shared_ptr<OrderProcessState> orderProcess = make_shared<Preorder>();
    float bankAccountAmount;
    std::shared_ptr<Tab> tab = nullptr;
    int tableNum;
    std::shared_ptr<Pizza> pizza = nullptr;
    std::vector<std::shared_ptr<Order>> orders;

public:
    Customer(int, int);
    Customer(std::shared_ptr<EmotionState>, int);
    gameElement *get();
    void changed();
    void set();
    void changeMood();
    void changedOrderProcessState();
    void setID(int);
    void requestBill();
    bool payBill(char c,float t); // if the passed in char is P, the customer will pay. If it is T the customer wants to add to the Tab.
    bool isLoyal();
    void startTab();
    void payTab();
    string printBill();
    void createOrder(int orderID, vector<shared_ptr<MenuItemOrderCommand>> command);
    void beSeated(int tableNum);
    int getTableNum();
    void setEmotionState(std::shared_ptr<EmotionState> mood);
    void setOrderProcessState(std::shared_ptr<OrderProcessState> orderProcess);
    std::shared_ptr<EmotionState> getMood();
    std::shared_ptr<OrderProcessState> getOrderProcessState();
    std::vector<std::shared_ptr<Order>> getOrders();
    bool receiveOrder(std::shared_ptr<Pizza>);
    std::string printCustomer();
    bool hasOrdered = false;
    bool hasBill = false;
    bool hasFood();
};
#endif
