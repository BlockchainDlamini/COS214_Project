//
// Created by User on 24/10/2023.
//

#include "gameElement.h"

#include <utility>
#include "Mediator.h"
using namespace std;


gameElement::gameElement(const shared_ptr<Mediator> &myGameEngine, int id): gameEngine(myGameEngine), myID(id) {

}

gameElement::gameElement(const shared_ptr<Mediator> &myGameEngine) : gameEngine(myGameEngine) {}

gameElement::gameElement() {}

gameElement::~gameElement() {}

void gameElement::setGameEngine(const shared_ptr<Mediator> &mediator) {
    this->gameEngine = mediator;
}

void gameElement::changed() {
    if (gameEngine) {
        gameEngine->notify(shared_from_this());
        return;
    }

    cout << "Object has no mediator" << endl;
}

void gameElement::setMyGameEngine(const shared_ptr<Mediator> &mediator) {
    shared_from_this()->gameEngine = mediator;
}


int gameElement::getMyId() const {
    return myID;
}

void gameElement::setMyId(int myId) {
    myID = myId;
}

string gameElement::get() {
    return operation;
}

void gameElement::setOperation(string op) {
    shared_from_this()->operation = op;
}

