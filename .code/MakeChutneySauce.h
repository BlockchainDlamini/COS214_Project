/**
 * @file MakeChutneySauce.h
 * @brief Contains the class declarations for the MakeChutneySauce class, a subclass of MakeSauce, responsible for creating a chutney sauce for a food item in the kitchen.
 */

#ifndef __MAKE_CHUTNEY_SAUCE_H__
#define __MAKE_CHUTNEY_SAUCE_H__

#include "MakeSauce.h"

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

    /**
     * @brief Execute the MakeChutneySauce command, creating and returning a shared pointer to the FoodItem representing the chutney sauce.
     * @return A shared pointer to the created FoodItem object.
     */
    std::shared_ptr<FoodItem> execute();
};

#endif
