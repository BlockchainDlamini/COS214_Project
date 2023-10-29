#ifndef REGULARWAITER_H
#define REGULARWAITER_H

#include <vector>
#include <memory>
#include <string>
#include "table.h"
#include "Waiter.h"
#include "Floor.h"
#include "Order.h"
#include "Pizza.h"

class regularWaiter : public Waiter {
public:
    regularWaiter(int Id, std::vector<int> assignedTables, Floor floorObj);
    void assignTable(std::shared_ptr<table> table);
    void takeOrder(int tableId);
    std::pair<int, std::vector<std::shared_ptr<Order>>> getForKitchen();
    void takeOrderToTable(std::vector<std::shared_ptr<Pizza>> pizzasForTable);
    void payBill();

    virtual string get();
    void changed();
    void setOperation(string op);

private:
    Floor floorObject;
    std::vector<shared_ptr<Pizza>> pizzasForTable;
    int Id;
    // std::vector<std::shared_ptr<table>> assignedTables;
    std::vector<int> assignedTables; // all the ids of the tables assigned to waiter
    // std::vector<std::shared_ptr<table>> tables;
    int tableID;
    std::vector<shared_ptr<Order>> ordersForATable;
    std::pair<int, std::vector<std::shared_ptr<Order>>> forKitchen;
};

#endif  // REGULARWAITER_H
