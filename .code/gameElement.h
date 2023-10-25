//
// Created by User on 24/10/2023.
//

#ifndef CODE_GAMEELEMENT_H
#define CODE_GAMEELEMENT_H

#include <memory>

//#include "gameEngine.h" //This will be uncommented soon
class gameEngine;

class gameElement {
public:
    gameElement();
    explicit gameElement(const std::shared_ptr<gameEngine> &myGameEngine);
    virtual ~gameElement();
    void setGameEngine(const std::shared_ptr<gameEngine> &gameEngine);
private:
    std::shared_ptr<gameEngine> myGameEngine= nullptr;
};


#endif //CODE_GAMEELEMENT_H
