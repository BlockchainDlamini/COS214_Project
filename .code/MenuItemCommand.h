/*@file MenuItemCommand.h
 *@brief contains the MenuItemCommand class
 *       which is the base class for all the
 *       commands that can be executed by the
 *       kitchen
 @author Thando Dlamini
 @bug No known bugs.
*/
#ifndef __MENU_ITEM_COMMAND_H__
#define __MENU_ITEM_COMMAND_H__

#include "Kitchen.h"
#include "FoodItem.h"
#include "gameElement.h"
#include <memory>

class MenuItemCommand : gameElement {
    public:
        /*@brief constructor for MenuItemCommand
         *@param std::shared_ptr<Kitchen> state
         *@return none
        */
        MenuItemCommand(std::shared_ptr<Kitchen>);
        /*@brief destructor for MenuItemCommand
         *@param none
         *@return none
        */
        std::shared_ptr<FoodItem> virtual execute() = 0;
        /*@brief returns the state of the kitchen
         *@param none
         *@return std::shared_ptr<Kitchen> state
        */
        std::shared_ptr<Kitchen> getState();
    protected: 
        std::shared_ptr<Kitchen> state;
};

#endif