//
// Created by User on 24/10/2023.
//

#ifndef CODE_MEDIATOR_H
#define CODE_MEDIATOR_H

class gameElement;

class Mediator { //gameElement will be a concreteMediator
public:
    virtual void notify(gameElement* element)=0;
};


#endif //CODE_MEDIATOR_H
