#ifndef __MAKE_TOMATO_PASTE_H__
#define __MAKE_TOMATO_PASTE_H__

#include "MakeSauce.h"

class MakeTomatoPaste : public MakeSauce {
    public:
        MakeTomatoPaste(std::shared_ptr<Kitchen>);
        std::shared_ptr<FoodItem> execute();
};

#endif
