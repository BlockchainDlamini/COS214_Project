/**
 * @file MakeRanch.h
 * @brief Contains the class declarations for the MakeRanch class, a subclass of MakeSauce, responsible for creating a ranch sauce for a food item in the kitchen.
 */

#ifndef __MAKE_RANCH_H__
#define __MAKE_RANCH_H__

#include "MakeSauce.h"

/**
 * @class MakeRanch
 * @brief Represents the MakeRanch class, responsible for creating a ranch sauce for a food item in the kitchen.
 */
class MakeRanch : public MakeSauce {
public:
    /**
     * @brief Constructor for the MakeRanch class.
     * @param kitchen A shared pointer to the Kitchen where the ranch sauce is created.
     */
    MakeRanch(std::shared_ptr<Kitchen> kitchen);

    /**
     * @brief Execute the MakeRanch command, creating and returning a shared pointer to the FoodItem representing the ranch sauce.
     * @return A shared pointer to the created FoodItem object.
     */
    std::shared_ptr<FoodItem> execute();
};

#endif
