#ifndef KILL_H
#define KILL_H

#include "blank.h"

class kill
{
public:
    kill();
    virtual int check(Blank *b[8][8], Blank *click) = 0;
    virtual void elimlnate(Blank *b[8][8], Blank *click) = 0;
    virtual void special_combine(Blank *b[8][8], Blank *click, int mode) = 0;
    virtual ~kill();
};

#endif // KILL_H
