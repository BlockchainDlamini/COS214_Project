#ifndef __MAKE_CHUTNEY_SAUCE_H__
#define __MAKE_CHUTNEY_SAUCE_H__

#include "MakeSauce.h"

class MakeChutneySauce : public MakeSauce {
    public:
        MakeChutneySauce(std::shared_ptr<Kitchen>);
        std::shared_ptr<FoodItem> execute();
};

#endif
