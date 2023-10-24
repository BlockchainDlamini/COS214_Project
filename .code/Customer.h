#ifndef Customer_H
#define Customer_H
#include "EmotionState.h"
#include "OrderProcessState.h"
#include "Order.h"
#include <iostream>
#include <memory>
#include <vector>
class Customer
{
private:
    std::shared_ptr<EmotionState> mood;
    std::shared_ptr<OrderProcessState> orderProcess;
    bool hasOrdered;
    std::vector<std::shared_ptr<Order>> orders;

public:
    Customer();
    void get();
    void changed();
    void set();
    void requestBill();
    bool payBill(char c);
    bool isLoyal();
    void beSeated(int tableNum);
    int getTableNum();
    std::vector<std::shared_ptr<Order>> sendOrder();
    bool receiveOrder();
};
#endif