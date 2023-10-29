/*@file MakeBase.h
*@brief contains the MakeBase class
*       which is a subclass of MenuItemCommand
*       and creates a base for a food item
*       in the kitchen
*@bug No known bugs.
*/
#ifndef __MAKE_BASE_H__
#define __MAKE_BASE_H__

#include "MenuItemCommand.h"
#include <memory>

class MakeBase : public MenuItemCommand {
    public:
        MakeBase(std::shared_ptr<Kitchen>);
        std::shared_ptr<FoodItem> execute();
};

#endif