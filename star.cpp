#include "star.h"

Star::Star()
{

}

int Star::check(Blank *b[8][8], Blank *click)
{

}

void Star::elimlnate(Blank *b[8][8], Blank *click)
{
    int row = click -> row;
    int col = click -> column;
    int val = click -> value;
    if(val != 0 && val != 17)       //除了零和星星
    {

        if(row > 1 && val == b[row-2][col] -> value && val == b[row-1][col] -> value && val == b[row+1][col] -> value && val == b[row+2][col] -> value)
        {

        }
    }
}
void Star::special_combine(Blank *b[8][8], Blank *click)
{

}

Star::~Star()
{

}

