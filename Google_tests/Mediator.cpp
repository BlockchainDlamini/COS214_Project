//
// Created by User on 24/10/2023.
//

//#include "KitchenInterface.h"
#include "gameElement.h"
#include "Mediator.h"
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

void Mediator::addGameElement(std::shared_ptr<gameElement>element) {
    listOfElements.push_back(element);
}

void Mediator::addGameElements(std::vector<std::shared_ptr<gameElement>> elements) {
    cout << "GameElements added" << endl;
    for (const auto& element : elements) {
        listOfElements.push_back(element);
    }
}
void Mediator::notify(gameElement* element){
    string temp = element->get();
    transform(temp.begin(), temp.end(), temp.begin(), ::toupper);

}
/*void Mediator::notify(gameElement* element) {
    string temp = element->get();
    transform(temp.begin(), temp.end(), temp.begin(), ::toupper);

    shared_ptr<KitchenInterface> theKitchen;
    for (unsigned int i = 0; i < listOfElements.size(); ++i) {
        theKitchen = dynamic_pointer_cast<KitchenInterface>(listOfElements[i]);
        if (theKitchen != nullptr) {
            break;
        }
    }

    if (theKitchen == nullptr) {
        errorMessage(noKitchenFound);
        //return;
    }

    if (temp == "SENDTOKITCHEN") {  //Invoked by Regular waiter
        RegularWaiter* theWaiter = dynamic_cast<RegularWaiter*>(element);
        if (theWaiter == nullptr) {
            errorMessage("The wrong class attempted to call sendToKitchen");
            return;
        }

        for (unsigned int i = 0; i < listOfElements.size(); ++i) {
            auto order = theWaiter->getForKitchen();
            theKitchen->delegateOrderProcess(order);
            return;
        }

        errorMessage("Waiter not found");  //Impossible
        return;
    }

    if (temp == "COLLECTORDER") {
        HeadChef* headChef = dynamic_cast<HeadChef*>(element);
        //auto headChef = dynamic_pointer_cast<HeadChef>(element);
        if (headChef == nullptr) {
            errorMessage("Invalid call to Collect an Order");
            return;
        }

        auto temp = theKitchen->collectOrder();
        int wantedID = temp.first;


        for (unsigned int i = 0; i < listOfElements.size(); ++i) {
            RegularWaiter* aWaiter = dynamic_cast<RegularWaiter*>(element);
            //shared_ptr<RegularWaiter> aWaiter = dynamic_pointer_cast<RegularWaiter>(element);
            if (aWaiter != nullptr) {
                if (aWaiter->getWaiterID() == wantedID) {
                    auto theOrder = temp.second;
                    aWaiter->takeOrderToTable(theOrder);
                    return;
                }
            }
        }

        errorMessage("Order was not collected");
        return;
    }

    if (temp == "GIVEORDER") {
        auto* theCustomer = dynamic_cast<Customer*>(element);
        //shared_ptr<Customer> theCustomer = dynamic_pointer_cast<Customer>(element);
        if (theCustomer == nullptr) {
            errorMessage("The wrong class attempted to call sendToKitchen");
            return;
        }
        int tableNum = theCustomer->getTableNum();

        for (unsigned int i = 0; i < listOfElements.size(); ++i) {  //There should only be one
            shared_ptr<RegularWaiter> aWaiter = dynamic_pointer_cast<RegularWaiter>(listOfElements[i]);
            if (aWaiter != nullptr) {
                auto theWaiter = aWaiter->waiterResponsible(tableNum);
                theWaiter->takeOrder(tableNum);
                return;
            }
        }
        errorMessage("The wrong class attempted to call sendToKitchen/waiter not found");
        return;
    }

    if (temp == "REQUESTBILL") {
        auto* theCustomer = dynamic_cast<Customer*>(element);
        //shared_ptr<Customer> theCustomer = dynamic_pointer_cast<Customer>(element);
        if (theCustomer == nullptr) {
            errorMessage("The wrong class attempted to call sendToKitchen");
            return;
        }
        int tableNum = theCustomer->getTableNum();

        for (unsigned int i = 0; i < listOfElements.size(); ++i) {  //There should only be one
            shared_ptr<RegularWaiter> aWaiter = dynamic_pointer_cast<RegularWaiter>(listOfElements[i]);
            if (aWaiter != nullptr) {
                auto theWaiter = aWaiter->waiterResponsible(tableNum);
                theWaiter->payBill(tableNum);
                return;
            }
        }
        errorMessage("Waiter not found");
        return;
    }

    if (temp == "LEAVE") {
        auto* theCustomer = dynamic_cast<Customer*>(element);
        //shared_ptr<Customer> theCustomer = dynamic_pointer_cast<Customer>(element);
        if (theCustomer == nullptr) {
            errorMessage("You shall not leave:), The wrong class attempted to call Leave the floor");
            return;
        }
        int tableNum = theCustomer->getTableNum();

        for (unsigned int i = 0; i < listOfElements.size(); ++i) {
            shared_ptr<MaitreD> theMaitreD = dynamic_pointer_cast<MaitreD>(listOfElements[i]);
            if (theMaitreD != nullptr) {
                theMaitreD->customersLeft(tableNum);
                return;
            }
        }
        errorMessage("MaitreD not found");
        return;
    }

    if (temp == "GETKITCHENREFERENCE") {  //Only a Customer can call this.
        auto* theCustomer = dynamic_cast<Customer*>(element);
        //auto theCustomer = dynamic_pointer_cast<Customer>(element);

        cout << "Returning reference" <<endl;
        if (theCustomer == nullptr) {
            errorMessage("Invalid call to getKitchen Reference");
            return;
        }

        for (unsigned int i = 0; i < listOfElements.size(); ++i) {  //There should only be one
            shared_ptr<KitchenInterface> theInterface = dynamic_pointer_cast<KitchenInterface>(listOfElements[i]);
            if (theInterface != nullptr) {
                auto reference = theInterface->getKitchenReference();
                theCustomer->setKitchenReference(reference);
                cout << "Done" <<endl;
                return;
            }
        }
        errorMessage("The wrong class attempted to call sendToKitchen/waiter not found");
        return;
    }


}*/

void Mediator::removeGameElement(std::shared_ptr<gameElement> element) {  //Still to be tested
    auto it = listOfElements.begin();
    while (it != listOfElements.end())
    {
        // remove odd numbers
        if (*it == element) {
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

bool Mediator::notified(gameElement *element) {
    string temp = element->get();
    return (temp == "TestString");
}
