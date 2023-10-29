#ifndef __MAKE_THIN_CRUST_H__
#define __MAKE_THIN_CRUST_H__

#include "MakeBase.h"

class MakeThinCrust : public MakeBase{
    public:
        MakeThinCrust(std::shared_ptr<Kitchen>);
        std::shared_ptr<FoodItem> execute();
};

#endif