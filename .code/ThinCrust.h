#ifndef THINCRUST_H
#define THINCRUST_H

#include "StuffedCrust.h"

/**
 * @class ThinCrust
 * @brief A class representing a thin crust base, derived from Base.
 *
 * This class is used to represent a thin crust-style base for food items, which is typically thin and crispy.
 */
class ThinCrust : public Base
{
public:
    /**
     * @brief Constructor for the ThinCrust class.
     * @param name The name of the thin crust base.
     */
    ThinCrust(string name);
};

#endif
