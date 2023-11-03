//
// Created by User on 24/10/2023.
//
#include "Mediator.h"
#include <algorithm>
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

    shared_ptr<ManagerChef> theKitchen;
    for (int i = 0; i < listOfElements.size(); ++i) {
        theKitchen = dynamic_pointer_cast<ManagerChef>(listOfElements[i]);
        if (theKitchen != nullptr) {
            break;
        }
    }

    if (theKitchen == nullptr) {
        errorMessage(noKitchenFound);
        return;
    }

    if (temp == "SENDTOKITCHEN") {
        shared_ptr<RegularWaiter> theWaiter = dynamic_pointer_cast<RegularWaiter>(element);
        if (theWaiter == nullptr) {
            errorMessage("The wrong class attempted to call sendToKitchen/waiter not found");
            return;
        }

        for (int i = 0; i < listOfElements.size(); ++i) {  //There should only be one
            auto order = theWaiter->getForKitchen();
            theKitchen->handleOrder(order);
            return;
        }
        errorMessage("Waiter not found");
        return;
    }

    if (temp == "COLLECTORDER") {
        //bool waiterFound = false;
        //shared_ptr<RegularWaiter> desiredWaiter = nullptr;

        theKitchen = dynamic_pointer_cast<ManagerChef>(element);
        if (theKitchen == nullptr) {
            errorMessage("Invalid call to Collect an Order");
            return;
        }

        int wantedID = theKitchen->getWaiterID();

        for (int i = 0; i < listOfElements.size(); ++i) {
            shared_ptr<RegularWaiter> aWaiter = dynamic_pointer_cast<RegularWaiter>(element);
            if (aWaiter != nullptr) {
                if (aWaiter->getWaiterID() == wantedID) {
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

    /*if (temp == "CALLWAITER") {
        theKitchen = dynamic_pointer_cast<ManagerChef>(element);
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
    }*/
    if (temp == "GIVEORDER") {
        shared_ptr<Customer> theCustomer = dynamic_pointer_cast<Customer>(element);
        if (theCustomer == nullptr) {
            errorMessage("The wrong class attempted to call sendToKitchen");
            return;
        }
        int tableNum= theCustomer->getTableNum();

        for (int i = 0; i < listOfElements.size(); ++i) {  //There should only be one
            shared_ptr<RegularWaiter> aWaiter = dynamic_pointer_cast<RegularWaiter>(listOfElements[i]);
            if (aWaiter != nullptr) {

                auto theWaiter  = aWaiter->waiterResponsible(tableNum);
                theWaiter->takeOrder(tableNum);
                return;
            }
        }
        errorMessage("The wrong class attempted to call sendToKitchen/waiter not found");
        return;
    }

    if (temp == "REQUESTBILL") {
        shared_ptr<Customer> theCustomer = dynamic_pointer_cast<Customer>(element);
        if (theCustomer == nullptr) {
            errorMessage("The wrong class attempted to call sendToKitchen");
            return;
        }
        int tableNum= theCustomer->getTableNum();

        for (int i = 0; i < listOfElements.size(); ++i) {  //There should only be one
            shared_ptr<RegularWaiter> aWaiter = dynamic_pointer_cast<RegularWaiter>(listOfElements[i]);
            if (aWaiter != nullptr) {
                auto theWaiter  = aWaiter->waiterResponsible(tableNum);
                theWaiter->payBill(tableNum);
                return;
            }
        }
        errorMessage("Waiter not found");
        return;
    }

    if (temp == "LEAVE") {
        shared_ptr<Customer> theCustomer = dynamic_pointer_cast<Customer>(element);
        if (theCustomer == nullptr) {
            errorMessage("The wrong class attempted to call Leave the floor");
            return;
        }
        int tableNum= theCustomer->getTableNum();

        for (int i = 0; i < listOfElements.size(); ++i) {  //There should only be one
            shared_ptr<MaitreD> theMaitreD = dynamic_pointer_cast<MaitreD>(listOfElements[i]);
            if (theMaitreD != nullptr) {
                //auto theWaiter  = theMaitreD->getResponsible(tableNum);
                theMaitreD->customersLeft(tableNum);
                return;
            }
        }
        errorMessage("MaitreD not found");
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
