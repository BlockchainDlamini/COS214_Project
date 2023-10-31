#include "Customer.h"

Customer::Customer(int bankAmount, int tableNum)
{ 
    bankAccountAmount = bankAmount; // each customer brings R1000 when they come to restaurant
    this->tableNum = tableNum;
}

