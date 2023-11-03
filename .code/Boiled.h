#ifndef BOILED_H
#define BOILED_H

#include "DoubleDecker.h"//BOBS ADDITION

/**
 * @class Boiled
 * @brief A class representing a boiled base, derived from Base.
 *
 * This class is used to represent a base food item that is boiled, such as a boiled potato or egg.
 */
class Boiled : public Base
{
public:
    /**
     * @brief Constructor for the Boiled class.
     * @param name The name of the boiled base.
     */
    Boiled(string name);
};

#endif
