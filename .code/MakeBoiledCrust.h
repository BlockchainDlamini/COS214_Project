/*@file 
* @brief contains the MakeBoiledCrust class
*/
#ifndef __MAKE_BOILED_CRUST_H__
#define __MAKE_BOILED_CRUST_H__

#include "MakeBase.h"

class MakeBoiledCrust : public MakeBase {
    public:
        MakeBoiledCrust(std::shared_ptr<Kitchen>);
        std::shared_ptr<FoodItem> execute();
};

#endif