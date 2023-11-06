//
// Created by User on 15/10/2023.
//
#include <limits.h>
#include <memory>

#include "lib/googletest/include/gtest/gtest.h"
//#include "gameElement_Test.h"
using namespace std;
class Mediator;
//
class gameElement_Test :public std::enable_shared_from_this<gameElement_Test> {
public:
    gameElement_Test(const shared_ptr<Mediator>& myGameEngine, int id) : gameEngine(myGameEngine), myID(id) {}

    gameElement_Test(const shared_ptr<Mediator>& myGameEngine) : gameEngine(myGameEngine) { }

    gameElement_Test() {  }

    ~gameElement_Test() {}


    void changed() {
//    if (gameEngine) {
//        gameEngine->notify(this);
//        return;
//    }

        cout << "Object has no mediator" << endl;
    }

    void setGameEngine(const shared_ptr<Mediator>& mediator) {
        gameEngine = mediator;
    }


    int getMyId() const {
        return myID;
    }

    void setMyId(int myId) {
        myID = myId;
    }

    string get() {
        return operation;
    }

    void setOperation(string op) {
        operation = op;
    }

    void doSomethingCool() {}

protected:
    /**
     * @brief A shared pointer to the mediator representing the game engine.
     */
    std::shared_ptr<Mediator> gameEngine;

    /**
     * @brief An integer representing the ID of the game element.
     */
    int myID;

    /**
     * @brief A static integer representing a shared ID across all instances of this class. It is incremented
     * by the constructor, thus guaranteeing that all objects have a unique ID.
     */

    /**
     * @brief A string representing the operation of the game element, used by the Mediator.
     */
    string operation;

};


//
class Mediator {
public:
    void addGameElement(std::shared_ptr<gameElement_Test>element) {
        listOfElements.push_back(element);
    }
//

    void addGameElements(std::vector<std::shared_ptr<gameElement_Test>> elements) {
        cout << "GameElements added" << endl;
        for (const auto& element : elements) {
            listOfElements.push_back(element);
        }
    }
    void notify(gameElement_Test* element){
        string temp = element->get();
        transform(temp.begin(), temp.end(), temp.begin(), ::toupper);

    }

    void removeGameElement(std::shared_ptr<gameElement_Test> element) {  //Still to be tested
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

    void errorMessage(const string& message) {
        cerr << "Error: " << message << "!";
    }

    bool notified(gameElement_Test *element) {
        string temp = element->get();
        return (temp == "TestString");
    }
    bool contains(std::shared_ptr<gameElement_Test> element){
        for (auto i = listOfElements.begin(); i < listOfElements.end(); ++i) {
            if (element == *(i)) {
                return true;
            }
        }
        return false;

    }
//

private:
    /**
    * @brief A vector to hold the list of game elements.
    */
    std::vector<std::shared_ptr<gameElement_Test>> listOfElements;

    const string noKitchenFound = "No kitchen found";
    const string noWaiterFound = "No Waiter found";
    const string specificWaiterNotFound = "Specific waiter not found";


};
//




shared_ptr<gameElement_Test> gm = make_shared<gameElement_Test>();
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
