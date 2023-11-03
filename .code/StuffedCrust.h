#ifndef STUFFEDCRUST_H
#define STUFFEDCRUST_H

#include "Base.h"//BOBS ADDITION

/**
 * @class StuffedCrust
 * @brief A class representing a stuffed crust base, derived from Base.
 *
 * This class is used to represent a stuffed crust-style base for food items, which typically has a filling inside the crust.
 */
class StuffedCrust : public Base
{
public:
    /**
     * @brief Constructor for the StuffedCrust class.
     * @param name The name of the stuffed crust base.
     */
    StuffedCrust(string name);
};

#endif
