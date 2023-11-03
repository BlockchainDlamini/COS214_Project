/**
 * @file MakeThinCrust.h
 * @brief Contains the class declarations for the MakeThinCrust class, a subclass of MakeBase, responsible for creating a thin crust for a food item in the kitchen.
 */

#ifndef __MAKE_THIN_CRUST_H__
#define __MAKE_THIN_CRUST_H__

#include "MakeSweetChilli.h"//BOBS ADDITION

/**
 * @class MakeThinCrust
 * @brief Represents the MakeThinCrust class, responsible for creating a thin crust for a food item in the kitchen.
 */
class MakeThinCrust : public MakeBase {
public:
    /**
     * @brief Constructor for the MakeThinCrust class.
     * @param kitchen A shared pointer to the Kitchen where the thin crust is created.
     */
    MakeThinCrust(std::shared_ptr<Kitchen> kitchen, string);
};

#endif
