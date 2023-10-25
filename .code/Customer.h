#ifndef Customer_H
#define Customer_H
#include "EmotionState.h"
#include "OrderProcessState.h"
#include "Happy.h"
#include "Ordering.h"
#include "Preorder.h"
#include "Waiting.h"
#include "Satisfied.h"
#include "Disgruntaled.h"
#include "DinnerDone.h"
#include "Disgruntaled.h"
#include "OrderReceived.h"
#include "Order.h"
#include "Frustrated.h"
#include "gameElement.h"
#include "Tab.h"
#include <iostream>
#include <memory>
#include <vector>
using namespace std;
class OrderProcessState;
class EmotionState;
class Customer : public enable_shared_from_this<Customer>, public gameElement
{
private:
    int ID;
    std::shared_ptr<EmotionState> mood;
    std::shared_ptr<OrderProcessState> orderProcess;
    int bankAccountAmount;
    std::shared_ptr<Tab> tab;
    int tableNum;
    std::vector<std::shared_ptr<Order>> orders;

public:
    Customer();
    Customer(std::shared_ptr<EmotionState>, int);
    void get();
    void changed();
    void set();
    void changeMood();
    void changedOrderProcessState();
    void setID(int);
    void requestBill();
    bool payBill(char c);
    bool isLoyal();
    void startTab();
    void payTab();
    void createOrder(int orderID, vector<shared_ptr<MenuItemOrderCommand>> command);
    void beSeated(int tableNum);
    int getTableNum();
    void setEmotionState(std::shared_ptr<EmotionState> mood);
    void setOrderProcessState(std::shared_ptr<OrderProcessState> orderProcess);
    std::shared_ptr<EmotionState> getMood();
    std::shared_ptr<OrderProcessState> getOrderProcessState();
    std::vector<std::shared_ptr<Order>> getOrder();
    bool receiveOrder(std::vector<std::shared_ptr<Order>>);
    std::string printCustomer();
    bool hasOrdered;
    bool hasBill;
    bool hasFood = false;
    bool has;
};
#endif
