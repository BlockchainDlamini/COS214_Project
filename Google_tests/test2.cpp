//
// Created by User on 15/10/2023.
//
#include <limits.h>
#include <memory>

#include "lib/googletest/include/gtest/gtest.h"
#include "Google_tests/gameElement.h"

//
class Mediator {
public:
    void addGameElement(std::shared_ptr<gameElement>element) {
        listOfElements.push_back(element);
    }
//

    void addGameElements(std::vector<std::shared_ptr<gameElement>> elements) {
        cout << "GameElements added" << endl;
        for (const auto& element : elements) {
            listOfElements.push_back(element);
        }
    }
    void notify(gameElement* element){
        string temp = element->get();
        transform(temp.begin(), temp.end(), temp.begin(), ::toupper);

    }

    void removeGameElement(std::shared_ptr<gameElement> element) {  //Still to be tested
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

    bool notified(gameElement *element) {
        string temp = element->get();
        return (temp == "TestString");
    }
    bool contains(std::shared_ptr<gameElement> element){
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
    std::vector<std::shared_ptr<gameElement>> listOfElements;

    const string noKitchenFound = "No kitchen found";
    const string noWaiterFound = "No Waiter found";
    const string specificWaiterNotFound = "Specific waiter not found";


};
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
