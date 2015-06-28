#ifndef ROW_H
#define ROW_H

#include "kill.h"
#include "blank.h"
#include "mainwindow.h"

class Row:public kill
{
public:
    Row();
    virtual void eliminate(Blank *b[8][8], int r, int c);
    virtual ~Row();
};

#endif // ROW_H
