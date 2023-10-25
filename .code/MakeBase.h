#ifndef __MAKE_BASE_H__
#define __MAKE_BASE_H__

#include "MenuItemCommand.h"

class MakeBase : public MenuItemCommand {
    public:
        MakeBase(shared_ptr<Kitchen>);
        shared_ptr<FoodItem> execute();
};

#endif