#ifndef __MAKE_GOUDA_H__
#define __MAKE_GOUDA_H__

#include "MakeCheese.h"

class MakeGouda : public MakeCheese {
    public:
        MakeGouda(std::shared_ptr<Kitchen>);
        std::shared_ptr<FoodItem> execute();
};

#endif

