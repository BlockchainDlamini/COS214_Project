#ifndef __MAKE_BEEF_H__
#define __MAKE_BEEF_H__

#include "MakeTopping.h"

class MakeBeef : public MakeTopping {
    public:
        MakeBeef(std::shared_ptr<Kitchen>);
        std::shared_ptr<FoodItem> execute();
};

#endif

