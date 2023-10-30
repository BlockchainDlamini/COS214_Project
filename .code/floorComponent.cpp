#include "floorComponent.h"
#include <iostream>

floorComponent::floorComponent(int newID)
{
    id = newID;
    //std::cout<<"In floorComponent constructor. ID: "<<id<<std::endl;
}

int floorComponent::getID()
{
    return id;
}