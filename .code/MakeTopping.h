/*@file MakeTopping.h
 *@brief contains the MakeTopping class
 *       which is a subclass of MenuItemCommand
 *       and creates a topping for a food item
 *       in the kitchen
 @bug No known bugs.
*/
#ifndef __MAKE_TOPPING_H__
#define __MAKE_TOPPING_H__

#include "MenuItemCommand.h"

class MakeTopping : public MenuItemCommand {
    public:
        /*@brief constructor for MakeTopping
         *@param std::shared_ptr<Kitchen> state
         *@return none
        */
        MakeTopping(std::shared_ptr<Kitchen>);
        /*@brief execute instruction for command
         *@param none
         *@return std::shared_ptr<FoodItem> foodItem
        */
        std::shared_ptr<FoodItem> execute();
};

#endif