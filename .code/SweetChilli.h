#ifndef SWEETCHILLI_H
#define SWEETCHILLI_H
#include "Sauce.h"
class SweetChilli :
    public Sauce
{
public:
    SweetChilli();
};
#endif
SweetChilli::SweetChilli():Sauce("SweetChilli",76) {}