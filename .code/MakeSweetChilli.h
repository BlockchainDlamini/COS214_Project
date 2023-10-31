/**
 * @file MakeSweetChilli.h
 * @brief Contains the class declarations for the MakeSweetChilli class, a subclass of MakeSauce, responsible for creating a sweet chili sauce for a food item in the kitchen.
 */

#ifndef __MAKE_SWEET_CHILLI_H__
#define __MAKE_SWEET_CHILLI_H__

#include "MakeSauce.h"

/**
 * @class MakeSweetChilli
 * @brief Represents the MakeSweetChilli class, responsible for creating a sweet chili sauce for a food item in the kitchen.
 */
class MakeSweetChilli : public MakeSauce {
public:
    /**
     * @brief Constructor for the MakeSweetChilli class.
     * @param kitchen A shared pointer to the Kitchen where the sweet chili sauce is created.
     */
    MakeSweetChilli(std::shared_ptr<Kitchen> kitchen);
};

#endif
