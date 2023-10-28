#ifndef REGULARWAITER_H
#define REGULARWAITER_H

#include <vector>
#include <memory>
#include <string>
#include "table.h"
#include "Waiter.h"

class regularWaiter : public Waiter {
public:
    regularWaiter(int Id, std::vector<std::shared_ptr<table>> assignedTables);
    void assignTable(std::shared_ptr<table> table);
    void takeOrder(int tableId);
    std::pair<int, std::vector<std::shared_ptr<orders>>> getForKitchen();
    void takeOrderToTable(std::vector<std::shared_ptr<pizza>> pizzasForTable);
    void payBill();
    
    void get();
    void changed();
    void set(string op);

private:
    std::vector<shared_ptr<pizza>> pizzasForTables;
    int Id;
    std::vector<std::shared_ptr<table>> assignedTables;
    // std::vector<std::shared_ptr<table>> tables;
    int tableID;
    std::vector<shared_ptr<orders>> ordersForATable;
    std::pair<int, std::vector<std::shared_ptr<orders>>> forKitchen;
};

#endif  // REGULARWAITER_H
