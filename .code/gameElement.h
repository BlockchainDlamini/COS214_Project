//
// Created by User on 24/10/2023.
//
#ifndef CODE_GAMEELEMENT_H
#define CODE_GAMEELEMENT_H

#include <memory>
#include <utility>
#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <queue>
#include <fstream>
#include <iomanip>

using namespace std;
class Mediator;
/**
 * @class gameElement
 * @brief A class to represent a game element. This class represents
 * Colleagues in the Mediator design pattern.
 */
class gameElement :public enable_shared_from_this<gameElement> {
public:
    /**
     * @brief Creates a new game element object.
     */
    gameElement();

    /**
     * @brief Creates a new game element object in addition to setting the gameEngine attribute.
     * @param myGameEngine The game engine to be used.
     */
    gameElement(const std::shared_ptr<Mediator>& myGameEngine);

    /**
     * @brief Creates a new game element object which sets the Mediator, as well as the object's ID.
     * @param myGameEngine The game engine to be used.
     * @param id The ID of the game element.
     */
    gameElement(const std::shared_ptr<Mediator>& myGameEngine, int id);

    /**
     * @brief Base class destructor.
     */
    virtual ~gameElement();

    /**
     * @brief Set the game engine.
     * @param myGameEngine The game engine to be set.
     */
    void setGameEngine(const shared_ptr<Mediator>& myGameEngine);

    /**
     * @brief Get the ID of the game element.
     * @return The ID of the game element.
     */
    int getMyId() const;

    /**
     * @brief Set the ID of the game element.
     * @param myId The ID to be set.
     */
    void setMyId(int myId);

    //Communication functions

    /**
     * @brief Notify the gameEngine that the gameElement has changed in some way.
     */
    virtual void changed();

    /**
     * @brief Get the operation of the gameElement, which informs the mediator of what message needs to be sent.
     * @return The operation of the game element.
     */
    virtual string get();

    /**
     * @brief Set the operation of the game element.
     * @param op The operation to be set.
     */
    virtual void setOperation(string op);

    virtual void doSomethingCool();
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
    static int sharedID;

    /**
     * @brief A string representing the operation of the game element, used by the Mediator.
     */
    string operation;

};
#endif //CODE_GAMEELEMENT_H
