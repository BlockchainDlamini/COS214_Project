/**
 * @file MakeChutneySauce.h
 * @brief Contains the class declarations for the MakeChutneySauce class, a subclass of MakeSauce, responsible for creating a chutney sauce for a food item in the kitchen.
 */

#ifndef __MAKE_CHUTNEY_SAUCE_H__
#define __MAKE_CHUTNEY_SAUCE_H__

#include "MakeChicken.h"//BOBS ADDITION

/**
 * @class MakeChutneySauce
 * @brief Represents the MakeChutneySauce class, responsible for creating a chutney sauce for a food item in the kitchen.
 */
class MakeChutneySauce : public MakeSauce {
public:
    /**
     * @brief Constructor for the MakeChutneySauce class.
     * @param kitchen A shared pointer to the Kitchen where the chutney sauce is created.
     */
    MakeChutneySauce(std::shared_ptr<Kitchen> kitchen);
};

#endif
