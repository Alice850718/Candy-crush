#ifndef COLUMN_H
#define COLUMN_H

#include "kill.h"
#include "blank.h"
#include "mainwindow.h"

class Column:public kill
{
public:
    Column();
    virtual void eliminate(Blank *b[8][8], int r, int c);
    virtual ~Column();
};

#endif // COLUMN_H
