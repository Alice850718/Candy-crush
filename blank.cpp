#include "blank.h"

Blank::Blank(int r, int c, QWidget *parent):
    row(r), column(c), QObject(parent)
{
    shift = 1;
    time = new QTimer();
    button = new QPushButton(parent);
    button->setGeometry(column*50,row*50,50,50);
    connect(button, SIGNAL(clicked()), this, SLOT(click()));
}
void Blank::click()
{
    emit Click(row,column);
}
void Blank::moveup()        //向上移動
{
    button -> setGeometry(column*50, row*50 - shift*10, 50, 50);
    shift ++;
    if(shift == 5)
    {
        shift = 1;
        disconnect(time, SIGNAL(timeout()),
                   this, SLOT(moveup()));
        button -> setGeometry(column*50, row*50, 50, 50);
        show_pic();
        emit movedone();
    }

}

void Blank::movedown()      //向下移動
{
    button -> setGeometry(column*50, row*50 + shift*10, 50, 50);
    shift ++;
    if(shift == 5)
    {
        shift = 1;
        disconnect(time, SIGNAL(timeout()),
                   this, SLOT(movedown()));
        button -> setGeometry(column*50, row*50, 50, 50);
        show_pic();
        emit movedone();
    }
}

void Blank::moveleft()      //向左移動
{
    button -> setGeometry(column*50 - shift*10, row*50, 50, 50);
    shift ++;
    if(shift == 5)
    {
        shift = 1;
        disconnect(time, SIGNAL(timeout()),
                   this, SLOT(moveleft()));
        button -> setGeometry(column*50, row*50, 50, 50);
        show_pic();
        emit movedone();
    }
}

void Blank::moveright()     //向右移動
{
    button -> setGeometry(column*50 + shift*10, row*50, 50, 50);
    shift ++;
    if(shift == 5)
    {
        shift = 1;
        disconnect(time, SIGNAL(timeout()),
                   this, SLOT(moveright()));
        button -> setGeometry(column*50, row*50, 50, 50);
        show_pic();
        emit movedone();
    }
}

void Blank::set_pic()
{
    value = rand()%4+1;
}

void Blank::show_pic()
{
    switch(value)
    {
        case 1:
            button ->setIcon(QIcon(QPixmap(":/1_normal.png")));
            break;
        case 2:
            button ->setIcon(QIcon(QPixmap(":/2_normal.png")));
            break;
        case 3:
            button ->setIcon(QIcon(QPixmap(":/3_normal.png")));
            break;
        case 4:
            button ->setIcon(QIcon(QPixmap(":/4_normal.png")));
            break;
        case 6:
            button ->setIcon(QIcon(QPixmap(":/1_row.png")));
            break;
        case 7:
            button ->setIcon(QIcon(QPixmap(":/2_row.png")));
            break;
        case 8:
            button ->setIcon(QIcon(QPixmap(":/3_row.png")));
            break;
        case 9:
            button ->setIcon(QIcon(QPixmap(":/4_row.png")));
            break;
        case 11:
            button ->setIcon(QIcon(QPixmap(":/1_col.png")));
            break;
        case 12:
            button ->setIcon(QIcon(QPixmap(":/2_col.png")));
            break;
        case 13:
            button ->setIcon(QIcon(QPixmap(":/3_col.png")));
            break;
        case 14:
            button ->setIcon(QIcon(QPixmap(":/4_col.png")));
            break;
        case 16:
            button ->setIcon(QIcon(QPixmap(":/:/1_b.png")));
            break;
        case 17:
            button ->setIcon(QIcon(QPixmap(":/2_b.png")));
            break;
        case 18:
            button ->setIcon(QIcon(QPixmap(":/3_b.png")));
            break;
        case 19:
            button ->setIcon(QIcon(QPixmap(":/4_b.png")));
            break;
        case 20:
            button ->setIcon(QIcon(QPixmap(":/star.png")));
            break;
        case 0:
            button ->setIcon(QIcon(QPixmap("NOPIC")));
            break;
    }
}
void Blank::operator -(Blank *b)        //交換位置(左右)
{
    int temp_num = b -> value;
    b -> value = value;
    value = temp_num;
    connect(time, SIGNAL(timeout()),
            this, SLOT(moveright()));
    connect(b -> time, SIGNAL(timeout()),
            b, SLOT(moveleft()));
    time -> start(100);
    b -> time -> start(100);
}



void Blank::operator +(Blank *b)        //交換位置(上下)
{
    int temp_num = b -> value;
    b -> value = value;
    value = temp_num;
    connect(time, SIGNAL(timeout()),
            this, SLOT(movedown()));
    connect(b -> time, SIGNAL(timeout()),
            b, SLOT(moveup()));
    time -> start(100);
    b -> time -> start(100);
}

Blank::~Blank()
{

}
