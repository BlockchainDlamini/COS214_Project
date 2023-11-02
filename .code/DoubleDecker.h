#ifndef DOUBLEDECKER_H
#define DOUBLEDECKER_H

#include "ThinCrust.h"

/**
 * @class DoubleDecker
 * @brief A class representing a double-decker base, derived from Base.
 *
 * This class is used to represent a double-decker-style base for food items, which typically consists of multiple layers or decks.
 */
class DoubleDecker : public Base
{
public:
    /**
     * @brief Constructor for the DoubleDecker class.
     * @param name The name of the double-decker base.
     */
    DoubleDecker(string name);
};

#endif
