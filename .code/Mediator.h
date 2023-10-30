//
// Created by User on 24/10/2023.
//

#ifndef CODE_MEDIATOR_H
#define CODE_MEDIATOR_H

#include <string>
#include <memory>
#include <vector>
class gameElement;

/**
 * @class Mediator
 * @brief A class to represent a mediator.
 */
class Mediator {
public:
    /**
    * @brief Notify a game element.
    * @param element The game element to be notified.
    */
    virtual void notify(std::shared_ptr<gameElement> element);

    /**
    * @brief Add a game element to the list of elements.
    * @param element The game element to be added.
    */
    void addGameElement(std::shared_ptr<gameElement> element);

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
};
#endif //CODE_MEDIATOR_H
