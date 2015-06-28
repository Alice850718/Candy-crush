#ifndef STAR_H
#define STAR_H

#include "kill.h"
#include "blank.h"
#include "mainwindow.h"

class Star:public kill
{
public:
    Star();
    virtual void eliminate(Blank *b[8][8], int r, int c);       //消除本身的格子
    virtual ~Star();
};

#endif // STAR_H
