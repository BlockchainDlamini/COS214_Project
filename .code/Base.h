#ifndef BASE_H
#define BASE_H
#include "Peppers.h"
class Base :
    public FoodItem
{
    public:
    Base(string, float, string);

private:
    string size;
};
#endif