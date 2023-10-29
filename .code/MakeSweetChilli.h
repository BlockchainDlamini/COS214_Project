#ifndef __MAKE_SWEET_CHILLI_H__
#define __MAKE_SWEET_CHILLI_H__

#include "MakeSauce.h"

class MakeSweetChilli : public MakeSauce {
    public:
        MakeSweetChilli(std::shared_ptr<Kitchen>);
        std::shared_ptr<FoodItem> execute();
};

#endif
