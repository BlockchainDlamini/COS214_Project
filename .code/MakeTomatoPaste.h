/**
 * @file MakeTomatoPaste.h
 * @brief Contains the class declarations for the MakeTomatoPaste class, a subclass of MakeSauce, responsible for creating tomato paste sauce for a food item in the kitchen.
 */

#ifndef __MAKE_TOMATO_PASTE_H__
#define __MAKE_TOMATO_PASTE_H__

#include "MakeThinCrust.h"//BOBS ADDITION

/**
 * @class MakeTomatoPaste
 * @brief Represents the MakeTomatoPaste class, responsible for creating tomato paste sauce for a food item in the kitchen.
 */
class MakeTomatoPaste : public MakeSauce {
public:
    /**
     * @brief Constructor for the MakeTomatoPaste class.
     * @param kitchen A shared pointer to the Kitchen where the tomato paste sauce is created.
     */
    MakeTomatoPaste(std::shared_ptr<Kitchen> kitchen);
};

#endif
