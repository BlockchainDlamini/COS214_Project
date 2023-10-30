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


/**
 * @class gameElement
 * @brief A class to represent a game element.
 */
class gameElement{
public:
    /**
     * @brief Construct a new game element object.
     */
    gameElement();

    /**
     * @brief Construct a new game element object.
     * @param myGameEngine The game engine to be used.
     */
    gameElement(const std::shared_ptr<Mediator> &myGameEngine);

    /**
     * @brief Construct a new game element object.
     * @param myGameEngine The game engine to be used.
     * @param id The ID of the game element.
     */
    gameElement(const std::shared_ptr<Mediator> &myGameEngine,int id);

    /**
     * @brief Destroy the game element object.
     */
    virtual ~gameElement();

    /**
     * @brief Set the game engine.
     * @param gameEngine The game engine to be set.
     */
    void setGameEngine(const std::shared_ptr<Mediator> &gameEngine);

    /**
     * @brief Set the game engine.
     * @param myGameEngine The game engine to be set.
     */
    void setMyGameEngine(const shared_ptr<Mediator> &myGameEngine);

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
     * @brief Notify that the game element has changed.
     */
    virtual void changed();

    /**
     * @brief Get the operation of the game element.
     * @return The operation of the game element.
     */
    virtual string get();

    /**
     * @brief Set the operation of the game element.
     * @param op The operation to be set.
     */
    virtual void setOperation(string op);

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
     * @brief A static integer representing a shared ID across all instances of this class.
     */
    static int sharedID;

    /**
     * @brief A string representing the operation of the game element.
     */
    string operation;
};






#endif //CODE_GAMEELEMENT_H
