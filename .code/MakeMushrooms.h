#ifndef __MAKE_MUSHROOMS_H__
#define __MAKE_MUSHROOMS_H__

#include "MakeTopping.h"

class MakeMushrooms : public MakeTopping {
    public:
        MakeMushrooms(std::shared_ptr<Kitchen>);
        std::shared_ptr<FoodItem> execute();
};

#endif

