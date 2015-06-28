#ifndef KILL_H
#define KILL_H

#include "blank.h"

class kill
{
public:
    kill();
    virtual void eliminate(Blank *b[8][8], int r, int c) = 0;
    virtual ~kill();
};

#endif // KILL_H
