//
// Created by User on 24/10/2023.
//

#include "gameElement.h"

#include <utility>
#include "Mediator.h"
using namespace std;

int gameElement::sharedID = 0;

gameElement::gameElement(const shared_ptr<Mediator> &myGameEngine, int id): gameEngine(myGameEngine), myID(id) {}

gameElement::gameElement(const shared_ptr<Mediator> &myGameEngine) : gameEngine(myGameEngine) {myID=sharedID++;}

gameElement::gameElement() {myID=sharedID++;}

gameElement::~gameElement() {}

void gameElement::setGameEngine(const shared_ptr<Mediator> &mediator) {
    this->gameEngine = mediator;
}

void gameElement::changed() {
    if (gameEngine) {
        gameEngine->notify(this);
        return;
    }

    cout << "Object has no mediator" << endl;
}

void gameElement::setMyGameEngine(const shared_ptr<Mediator> &mediator) {
    gameEngine = mediator;
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
    operation = op;
}
