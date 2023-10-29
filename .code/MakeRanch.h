#ifndef __MAKE_RANCH_H__
#define __MAKE_RANCH_H__

#include "MakeSauce.h"

class MakeRanch : public MakeSauce {
    public:
        MakeRanch(std::shared_ptr<Kitchen>);
        std::shared_ptr<FoodItem> execute();
};

#endif
