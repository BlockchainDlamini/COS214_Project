#ifndef __MAKE_CHEESE_H__
#define __MAKE_CHEESE_H__

#include "MenuItemCommand.h"

class MakeCheese : public MenuItemCommand {
    public:
        MakeCheese(shared_ptr<Kitchen>);
        shared_ptr<FoodItem> execute();
};

#endif