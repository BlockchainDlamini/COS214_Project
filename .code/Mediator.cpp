//
// Created by User on 24/10/2023.
//

#include "gameElement.h"
#include "Mediator.h"
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

// For testing ----- Remove later!
/*    class Kitchen;
    class waiter;
    class Order;
    class Pizza;
class RegularWaiter : public gameElement {
public:
    //RegularWaiter(int Id, std::vector<int> assignedTables, Floor floorObj);
    //void assignTable(std::shared_ptr<table> table);
    void takeOrder(int tableId);
    std::pair<int, std::vector<std::shared_ptr<Order>>> getForKitchen();
    void takeOrderToTable(std::vector<std::shared_ptr<Pizza>> pizzasForTable);

    //void takeOrderToTable(std::vector<std::shared_ptr<Pizza>> pizzasForTable);
    void payBill();

    virtual string get();
    void changed();
    void setOperation(string op);

private:
   // Floor floorObject;
   // std::vector<shared_ptr<Pizza>> pizzasForTable;
    int Id;
    // std::vector<std::shared_ptr<table>> assignedTables;
    std::vector<int> assignedTables; // all the ids of the tables assigned to waiter
    // std::vector<std::shared_ptr<table>> tables;
    int tableID;
    std::vector<shared_ptr<Order>> ordersForATable;
    std::pair<int, std::vector<std::shared_ptr<Order>>> forKitchen;
};
class Kitchen : public gameElement {
public:
    //RegularWaiter(int Id, std::vector<int> assignedTables, Floor floorObj);
    //void assignTable(std::shared_ptr<table> table);
    virtual void handleOrder(pair<int, vector<shared_ptr<Order>>>);
    int getWaiterID();
    std::vector<std::shared_ptr<Pizza>> getPizzas();
    void takeOrder(int tableId);
    std::pair<int, std::vector<std::shared_ptr<Order>>> getForKitchen();
    //void takeOrderToTable(std::vector<std::shared_ptr<Pizza>> pizzasForTable);
    void payBill();

    virtual string get();
    void changed();
    void setOperation(string op);

private:
    // Floor floorObject;
    // std::vector<shared_ptr<Pizza>> pizzasForTable;
    int Id;
    // std::vector<std::shared_ptr<table>> assignedTables;
    std::vector<int> assignedTables; // all the ids of the tables assigned to waiter
    // std::vector<std::shared_ptr<table>> tables;
    int tableID;
    std::vector<shared_ptr<Order>> ordersForATable;
    std::pair<int, std::vector<std::shared_ptr<Order>>> forKitchen;
};*/

//

void Mediator::addGameElement(std::shared_ptr<gameElement>element) {
    listOfElements.push_back(element);
}

void Mediator::addGameElements(std::vector<std::shared_ptr<gameElement>> elements) {
    for (const auto& element:elements) {
        listOfElements.push_back(element);
    }
}

void Mediator::notify(std::shared_ptr<gameElement> element) {
    string temp = element->get();
    transform(temp.begin(), temp.end(), temp.begin(), ::toupper);

    shared_ptr<Kitchen> theKitchen;
    for (int i = 0; i < listOfElements.size(); ++i) {
        theKitchen = dynamic_pointer_cast<Kitchen>(listOfElements[i]);
        if (theKitchen != nullptr) {
            break;
        }
    }

    if (theKitchen == nullptr) {
        errorMessage(noKitchenFound);
        return;
    }

    if (temp == "SENDTOKITCHEN") {
        for (int i = 0; i < listOfElements.size(); ++i) {  //There should only be one
            shared_ptr<RegularWaiter> theWaiter = dynamic_pointer_cast<RegularWaiter>(element);
            if (theWaiter != nullptr) {
                auto order = theWaiter->getForKitchen();
                theKitchen->handleOrder(order); //Ask Thando
                return;
            }
        }
        errorMessage("The wrong class attempted to call sendToKitchen/waiter not found");
        return;
    }

    if (temp == "COLLECTORDER") {
        //bool waiterFound = false;
        shared_ptr<RegularWaiter> desiredWaiter = nullptr;

        theKitchen = dynamic_pointer_cast<Kitchen>(element);
        if (theKitchen == nullptr) {
            errorMessage("Invalid call to Collect an Order");
            return;
        }

        int wantedID = theKitchen->getWaiterID();

        for (int i = 0; i < listOfElements.size(); ++i) {
            shared_ptr<RegularWaiter> aWaiter = dynamic_pointer_cast<RegularWaiter>(element);
            if (aWaiter != nullptr) {
                if (aWaiter->getMyId() == wantedID) {
                    //waiterFound = true;
                    vector<shared_ptr<Pizza>> theOrder = theKitchen->getPizzas(); //Ask Thando
                    aWaiter->takeOrderToTable(theOrder);
                    return;
                }
            }
        }

        errorMessage("Order was not collected");
        return;
    }

    //GIVEORDER: Called by customer to assign waiter to this
}

void Mediator::removeGameElement(std::shared_ptr<gameElement> element) {  //Still to be tested
    auto it = listOfElements.begin();
    while (it != listOfElements.end())
    {
        // remove odd numbers
        if (*it == element){
            it = listOfElements.erase(it);
        }
        else {
            ++it;
        }
    }

}

void Mediator::errorMessage(const string& message) {
    cerr << "Error: " << message << "!";
}
