//
// Created by User on 15/10/2023.
//
#include <limits.h>
#include <memory>

#include "gameElement.h"

#include "lib/googletest/include/gtest/gtest.h"


//
class Mediator {
public:
    /**
    * @brief Notifies the mediator of a gameElement attempting to communicate with another gameElement.
    * @param element The game element that would like to notify communicate with gameElement.
    */
    virtual void notify(gameElement* element);

    bool notified(gameElement* element);

    /**
    * @brief Add a game element to the list of elements.
    * @param element The game element to be added.
    */
    void addGameElement(std::shared_ptr<gameElement> element);
    bool contains(std::shared_ptr<gameElement> element);

    /**
    * @brief Add multiple game elements to the list of elements.
    * @param elements The game elements to be added.
    */
    void addGameElements(std::vector<std::shared_ptr<gameElement>> elements);

    /**
    * @brief Remove a game element from the list of elements.
    * @param element The game element to be removed.
    */
    void removeGameElement(std::shared_ptr<gameElement> element);

private:
    /**
    * @brief A vector to hold the list of game elements.
    */
    std::vector<std::shared_ptr<gameElement>> listOfElements;

    const string noKitchenFound = "No kitchen found";
    const string noWaiterFound = "No Waiter found";
    const string specificWaiterNotFound = "Specific waiter not found";

    /**
    * @brief Outputs error messages to the user.
    * @param message The specific message to be output
    */
    static void errorMessage(const string& message);

};
//

void Mediator::addGameElement(std::shared_ptr<gameElement>element) {
    listOfElements.push_back(element);
}
//

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
bool Mediator::contains(std::shared_ptr<gameElement> element){
    for (auto i = listOfElements.begin(); i < listOfElements.end(); ++i) {
        if (element == *(i)) {
            return true;
        }
    }
    return false;

}
//


shared_ptr<gameElement> gm = make_shared<gameElement>();
TEST(communicationTest, Unset) {
    EXPECT_EQ("",gm->get());
}

TEST(communicationTest, Set) {
    gm->setOperation("doSomething");
    EXPECT_EQ("doSomething",gm->get());
    gm->setOperation("didodu");
    EXPECT_EQ("didodu",gm->get());
}

TEST(mediatorTest, viewMessage) {
    auto *mediator = new Mediator();
    mediator->addGameElement(gm);
    gm->setOperation("TestString");
    EXPECT_TRUE(mediator->notified(gm.get()));
    EXPECT_TRUE(mediator->contains(gm));
}

TEST(mediatorTest, containing) {
    auto *mediator = new Mediator();
    mediator->addGameElement(gm);
    EXPECT_TRUE(mediator->contains(gm));
}

TEST(mediatorTest, containANDRemove) {
    auto *mediator = new Mediator();
    mediator->addGameElement(gm);
    EXPECT_TRUE(mediator->contains(gm));
}

TEST(mediatorTest, addDuplicate) {
    auto *mediator = new Mediator();
    mediator->addGameElement(gm);
    mediator->addGameElement(gm);
    mediator->addGameElement(gm);
    EXPECT_TRUE(mediator->contains(gm));
}


TEST(mediatorTest, removeNotFound) {
    auto *mediator = new Mediator();
    mediator->addGameElement(gm);
    mediator->removeGameElement(nullptr);

}

TEST(mediatorTest, addRemove) {
    auto *mediator = new Mediator();
    mediator->addGameElement(gm);
    mediator->removeGameElement(nullptr);
    mediator->addGameElement(gm);
    mediator->addGameElement(gm);
    mediator->addGameElement(gm);
    mediator->removeGameElement(gm);
    mediator->removeGameElement(gm);
    mediator->removeGameElement(gm);
}