#ifndef STAR_H
#define STAR_H

#include "kill.h"
#include "blank.h"
#include "mainwindow.h"

class Star:public kill
{
public:
    Star();
    virtual int check(Blank *b[8][8], Blank *click);        //檢查需要消除的格子
    virtual void elimlnate(Blank *b[8][8], Blank *click);       //消除本身的格子
    virtual void special_combine(Blank *b[8][8], Blank *click);       //處理特殊的格子
    virtual ~Star();
};

#endif // STAR_H
