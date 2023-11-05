/*
//
// Created by User on 15/10/2023.
//
#include <limits.h>
#include "gameElement.h"
//#include "gtest/gtest.h"
#include "lib/googletest/include/gtest/gtest.h"

//
class Meditator_temp {
public:
    */
/**
    * @brief Notifies the mediator of a gameElement attempting to communicate with another gameElement.
    * @param element The game element that would like to notify communicate with gameElement.
    *//*

    virtual void notify(gameElement* element);

    bool notified(gameElement* element);

    */
/**
    * @brief Add a game element to the list of elements.
    * @param element The game element to be added.
    *//*

    void addGameElement(std::shared_ptr<gameElement> element);
    bool contains(std::shared_ptr<gameElement> element);

    */
/**
    * @brief Add multiple game elements to the list of elements.
    * @param elements The game elements to be added.
    *//*

    void addGameElements(std::vector<std::shared_ptr<gameElement>> elements);

    */
/**
    * @brief Remove a game element from the list of elements.
    * @param element The game element to be removed.
    *//*

    void removeGameElement(std::shared_ptr<gameElement> element);

private:
    */
/**
    * @brief A vector to hold the list of game elements.
    *//*

    std::vector<std::shared_ptr<gameElement>> listOfElements;

    const string noKitchenFound = "No kitchen found";
    const string noWaiterFound = "No Waiter found";
    const string specificWaiterNotFound = "Specific waiter not found";

    */
/**
    * @brief Outputs error messages to the user.
    * @param message The specific message to be output
    *//*

    static void errorMessage(const string& message);

};
//

//
void Meditator_temp::addGameElements(std::vector<std::shared_ptr<gameElement>> elements) {
    cout << "GameElements added" << endl;
    for (const auto& element : elements) {
        listOfElements.push_back(element);
    }
}
void Meditator_temp::notify(gameElement* element){
    string temp = element->get();
    transform(temp.begin(), temp.end(), temp.begin(), ::toupper);

}

void Meditator_temp::removeGameElement(std::shared_ptr<gameElement> element) {  //Still to be tested
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

void Meditator_temp::errorMessage(const string& message) {
    cerr << "Error: " << message << "!";
}

bool Meditator_temp::notified(gameElement *element) {
    string temp = element->get();
    return (temp == "TestString");
}
bool Meditator_temp::contains(std::shared_ptr<gameElement> element){
    for (auto i = listOfElements.begin(); i < listOfElements.end(); ++i) {
        if (element == *(i)) {
            return true;
        }
    }
    return false;

}
//

TEST(simpleArithmetic,OneEqualOne){
    EXPECT_TRUE(1==1);
}

TEST(regularWaiterTest,OneEqualOne){
    EXPECT_TRUE(1==1);
}

*/
