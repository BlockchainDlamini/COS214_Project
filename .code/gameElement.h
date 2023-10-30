//
// Created by User on 24/10/2023.
//

#ifndef CODE_GAMEELEMENT_H
#define CODE_GAMEELEMENT_H

#include <memory>
#include <utility>
#include <string>
#include <iostream>

using namespace std;
class Mediator;

class gameElement{
public:
    gameElement();
    gameElement(const std::shared_ptr<Mediator> &myGameEngine);
    gameElement(const std::shared_ptr<Mediator> &myGameEngine,int id);
    virtual ~gameElement();
    void setGameEngine(const std::shared_ptr<Mediator> &gameEngine);
    void setMyGameEngine(const shared_ptr<Mediator> &myGameEngine);
    int getMyId() const;
    void setMyId(int myId);

    //Communication functions
    virtual void changed();
    virtual string get();
    virtual void setOperation(string op);
protected:
    std::shared_ptr<Mediator> gameEngine;
    int myID;
    static int sharedID;
    string operation;
};




#endif //CODE_GAMEELEMENT_H
