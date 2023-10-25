#ifndef __MAKE_TOPPING_H__
#define __MAKE_TOPPING_H__

#include "MenuItemCommand.h"

class MakeTopping : public MenuItemCommand {
    public:
        MakeTopping(shared_ptr<Kitchen>);
        shared_ptr<FoodItem> execute();
};

#endif