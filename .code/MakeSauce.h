/*@file MakeSauce.h
 *@brief contains the MakeSauce class
 *       which is a subclass of MenuItemCommand
 *       and creates a sauce for a food item
 *       in the kitchen
 @bug No known bugs.
*/
#ifndef __MAKE_SAUCE_H__
#define __MAKE_SAUCE_H__

#include "MenuItemCommand.h"

class MakeSauce : public MenuItemCommand {
    public:
        /*@brief constructor for MakeSauce
         *@param std::shared_ptr<Kitchen> state
         *@return none
        */
        MakeSauce(std::shared_ptr<Kitchen>);
        /*@brief execute instruction for command
         *@param none
         *@return std::shared_ptr<FoodItem> foodItem
        */
        std::shared_ptr<FoodItem> execute();
};

#endif