//
// Created by User on 24/10/2023.
//

#ifndef CODE_MEDIATOR_H
#define CODE_MEDIATOR_H

#include "MaitreD.h"
#include <string>
#include <memory>
#include <vector>

class gameElement;

/**
 * @class Mediator
 * @brief A class to represent the mediator in the Mediator Design Pattern.
 */
class Mediator {
public:
    /**
    * @brief Notifies the mediator of a gameElement attempting to communicate with another gameElement.
    * @param element The game element that would like to notify communicate with gameElement.
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

    const string noKitchenFound = "Error: No kitchen found";
    const string noWaiterFound = "Error: No Waiter found";
    const string specificWaiterNotFound = "Error: Specific waiter not found";

    /**
    * @brief Outputs error messages to the user.
    * @param message The specific message to be output
    */
    static void errorMessage(const string& message);

};
#endif //CODE_MEDIATOR_H
