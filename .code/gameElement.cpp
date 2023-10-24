//
// Created by User on 24/10/2023.
//

#include "../../COS214_Project/.code/gameElement.h"
using namespace std;
void gameElement::setGameEngine(const shared_ptr<gameEngine> &gameEngine) {
    this->myGameEngine = gameEngine;
}

gameElement::gameElement(const shared_ptr<gameEngine> &myGameEngine) : myGameEngine(myGameEngine) {}

gameElement::gameElement() {}

gameElement::~gameElement() {

}
