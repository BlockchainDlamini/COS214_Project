//
// Created by User on 24/10/2023.
//

#include "Mediator.h"
#include "gameElement.h"
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

//
//    class Kitchen;
//    class waiter;
//    class regularWaiter;


//

void Mediator::addGameElement(std::shared_ptr<gameElement>element) {
    listOfElements.push_back(element);
}

void Mediator::addGameElements(std::vector<std::shared_ptr<gameElement>> elements) {
    for (const auto& element:elements) {
        listOfElements.push_back(element);
    }
}

void Mediator::notify(gameElement* element) {
    string temp = element->get();
    transform(temp.begin(), temp.end(), temp.begin(), ::toupper);
    //if (...)  //Mediator logic using get():string
/*    if (temp == "SENDTOKITCHEN") {
        for (int i = 0; i < listOfElements.size(); ++i) {  //There should only be one
            if (dynamic_cast<Kitchen*>(listOfElements[i])) {
               auto a = dynamic_cast<regularWaiter*>(element)->getForKitchen();
                dynamic_cast<Kitchen*>(listOfElements[i])->
            }
        }
    } //else if () {}*/
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
