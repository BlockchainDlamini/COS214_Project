#ifndef __MAKE_SAUCE_H__
#define __MAKE_SAUCE_H__

#include "MenuItemCommand.h"

class MakeSauce : public MenuItemCommand {
    public:
        MakeSauce(shared_ptr<Kitchen>);
        shared_ptr<FoodItem> execute();
};

#endif