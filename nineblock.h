#ifndef NINEBLOCK_H
#define NINEBLOCK_H

#include "kill.h"
#include "blank.h"
#include "mainwindow.h"

class Nineblock:public kill
{
public:
    Nineblock();
    virtual void eliminate(Blank *b[8][8], int r, int c);
    virtual ~Nineblock();
};

#endif // NINEBLOCK_H
