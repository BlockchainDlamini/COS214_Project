//
// Created by User on 24/10/2023.
//

#ifndef CODE_MEDIATOR_H
#define CODE_MEDIATOR_H

#include <string>
#include <memory>
#include <vector>
class gameElement;

class Mediator {
public:
    virtual void notify(gameElement* element);
    void addGameElement(std::shared_ptr<gameElement> element);
    void addGameElements(std::vector<std::shared_ptr<gameElement>> elements);
    void removeGameElement(std::shared_ptr<gameElement> element);

private:
    std::vector<std::shared_ptr<gameElement>> listOfElements;
};
#endif //CODE_MEDIATOR_H
