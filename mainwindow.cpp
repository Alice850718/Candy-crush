#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    srand(time(NULL));
    ui->setupUi(this);
    for(int i = 0; i < 8; i ++)
    {
        for(int j = 0; j < 8; j ++)
        {
            b[ i ][ j ] = new Blank(i,j, this);
            connect(b[ i ][ j ], SIGNAL(Click(int,int)),
                    this, SLOT(button_clicked(int,int)));
            connect(b[ i ][ j ], SIGNAL(movedone()),
                    this, SLOT(killzero()));
        }
    }
    gamestart();
}
void MainWindow::set_click_pic(Blank *b)
{
    if(!isClick)
    {
        switch(b -> value)
        {
        case 1:
            b -> button ->setIcon(QIcon(QPixmap(":/B1_normal.png")));
            break;
        case 2:
            b -> button ->setIcon(QIcon(QPixmap(":/B2_normal.png")));
            break;
        case 3:
            b -> button ->setIcon(QIcon(QPixmap(":/B3_normal.png")));
            break;
        case 4:
            b -> button ->setIcon(QIcon(QPixmap(":/B4_normal.png")));
            break;
        case 6:
            b -> button ->setIcon(QIcon(QPixmap(":/B1_row.png")));
            break;
        case 7:
            b -> button ->setIcon(QIcon(QPixmap(":/B2_row.png")));
            break;
        case 8:
            b -> button ->setIcon(QIcon(QPixmap(":/B3_row.png")));
            break;
        case 9:
            b -> button ->setIcon(QIcon(QPixmap(":/B4_row.png")));
            break;
        case 11:
            b -> button ->setIcon(QIcon(QPixmap(":/B1_col.png")));
            break;
        case 12:
            b -> button ->setIcon(QIcon(QPixmap(":/B2_col.png")));
            break;
        case 13:
            b -> button ->setIcon(QIcon(QPixmap(":/B3_col.png")));
            break;
        case 14:
            b -> button ->setIcon(QIcon(QPixmap(":/B4_col.png")));
            break;
        case 16:
            b -> button ->setIcon(QIcon(QPixmap(":/B1_b.png")));
            break;
        case 17:
            b -> button ->setIcon(QIcon(QPixmap(":/B2_b.png")));
            break;
        case 18:
            b -> button ->setIcon(QIcon(QPixmap(":/B3_b.png")));
            break;
        case 19:
            b -> button ->setIcon(QIcon(QPixmap(":/B4_b.png")));
            break;
        case 20:
            b -> button ->setIcon(QIcon(QPixmap(":/star.png")));
            break;
        case 0:
            b -> button ->setIcon(QIcon(QPixmap("NOPIC")));
            break;
        }
    isClick = true;
    }
    else
    {
        b -> show_pic();
    }
}

int MainWindow::creat_type(int r, int c)
{
    if((c > 1 && b[r][c-2] -> value%5 == b[r][c] -> value%5 && b[r][c-1] -> value%5 == b[r][c] -> value%5) || (c < 6 && b[r][c+2] -> value%5 == b[r][c] -> value%5 && b[r][c+1] -> value%5 == b[r][c] -> value%5))
    {       //三格(橫)
        if((r > 1 && b[r-2][c] -> value%5 == b[r][c] -> value%5 && b[r-1][c] -> value%5 == b[r][c] -> value%5) || (r < 6 && b[r+2][c] -> value%5 == b[r][c] -> value%5 && b[r+1][c] -> value%5 == b[r][c] -> value%5))
        {       //L型
            if(c > 1 && c < 6 && b[r][c-2] -> value%5 == b[r][c+2] -> value%5 && b[r][c-1] -> value%5 == b[r][c+1] -> value%5)
            {       //五格(大T字)
                return 20;      //星星
            }
            else
            {       //三格(橫)
                return (3*5+ b[r][c]-> value%5);       //九宮格炸彈
            }
        }
        else if((c > 1 && c < 7 && b[r][c-2] -> value%5 == b[r][c+1] -> value%5) || ( c > 0 && c < 6 && b[r][c-1] -> value%5 == b[r][c+2] -> value%5))
        {        //四格(橫)
            if(c > 1 && c < 6 && b[r][c-2] -> value%5 == b[r][c+2] -> value%5 && b[r][c-1] -> value%5 == b[r][c+1] -> value%5)
            {       //五格(一字)
                return 20;      //星星
            }
            else
            {
                return (1*5+ b[r][c]-> value%5);       //水平炸彈
            }
        }
        else
        {
            if(c > 1 && b[r][c-2] -> value%5 == b[r][c] -> value%5 && b[r][c-1] -> value%5 == b[r][c] -> value%5)
            {       //三格(橫)
                b[r][c-2] -> value = b[r][c-2] -> value/5;
                b[r][c-1] -> value = b[r][c-1] -> value/5;
            }
            if(c < 6 && b[r][c+2] -> value%5 == b[r][c] -> value%5 && b[r][c+1] -> value%5 == b[r][c] -> value%5)
            {       //三格(橫)
                b[r][c+2] -> value = b[r][c+2] -> value/5;
                b[r][c+1] -> value = b[r][c+1] -> value/5;
            }
            return b[r][c] -> value/5;
        }

    }
    else if(c > 0 && c < 7 && b[r][c-1] -> value%5 == b[r][c] -> value%5 && b[r][c+1] -> value%5 == b[r][c] -> value%5)
    {       //三格(橫)左右皆同
        if(c > 1 && c < 6 && b[r][c-2] -> value%5 == b[r][c] -> value%5 && b[r][c+2] -> value%5 == b[r][c] -> value%5)
        {
            return 20;      //星星
        }
        else if((r > 1 && b[r-2][c] -> value%5 == b[r][c] -> value%5 && b[r-1][c] -> value%5 == b[r][c] -> value%5) || (r < 6 && b[r+2][c] -> value%5 == b[r][c] -> value%5 && b[r+1][c] -> value%5 == b[r][c] -> value%5))
        {       //T字型
            return (3*5+ b[r][c]-> value%5);       //九宮格炸彈
        }
        else
        {       //三格(橫)
            b[r][c-1] -> value = b[r][c-1] -> value/5;
            b[r][c+1] -> value = b[r][c+1] -> value/5;
            return b[r][c] -> value/5;
        }
    }
    else if((r > 1 && b[r-2][c] -> value%5 == b[r][c] -> value%5 && b[r-1][c] -> value%5 == b[r][c] -> value%5) || (r < 6 && b[r+2][c] -> value%5 == b[r][c] -> value%5 && b[r+1][c] -> value%5 == b[r][c] -> value%5))
    {       //三格(直)
        if((c > 1 && b[r][c-2] -> value%5 == b[r][c] -> value%5 && b[r][c-1] -> value%5 == b[r][c] -> value%5) || (c < 6 && b[r][c+2] -> value%5 == b[r][c] -> value%5 && b[r][c+1] -> value%5 == b[r][c] -> value%5))
        {       //L型
            if(r > 1 && r < 6 && b[r-2][c] -> value%5 == b[r+2][c] -> value%5 && b[r-1][c] -> value%5 == b[r+1][c] -> value%5)
            {       //五格(大T字)
                return 20;      //星星
            }
            return (3*5+ b[r][c]-> value%5);       //九宮格炸彈
        }
        else if((r > 1 && r < 7 && b[r-2][c] -> value%5 == b[r+1][c] -> value%5) || (r > 0 && r < 6 && b[r-1][c] -> value%5 == b[r+2][c] -> value%5))
        {        //四格(直)
            if(r > 1 && r < 6 && b[r-2][c] -> value%5 == b[r+2][c] -> value%5 && b[r-1][c] -> value%5 == b[r+1][c] -> value%5)
            {       //五格(一字)
                return 20;      //星星
            }
            return (2*5+ b[r][c]-> value%5);       //垂直炸彈
        }
        else
        {
            if(r > 1 && b[r-2][c] -> value%5 == b[r-1][c] -> value%5)
            {       //三格(直)
                b[r-2][c] -> value = b[r-2][c] -> value/5;
                b[r-1][c] -> value = b[r-1][c] -> value/5;
            }
            if(r < 6 && b[r+2][c] -> value%5 == b[r+1][c] -> value%5)
            {       //三格(直)
                b[r+2][c] -> value = b[r+2][c] -> value/5;
                b[r+1][c] -> value = b[r+1][c] -> value/5;
                return b[r][c] -> value/5;
            }
        }
    }
    else if(r > 0 && r < 7 && b[r-1][c] -> value%5 == b[r][c] -> value%5 && b[r+1][c] -> value%5 == b[r][c] -> value%5)
    {       //三格(直)上下皆同
        if(r > 1 && r < 6 && b[r-2][c] -> value%5 == b[r][c] -> value%5 && b[r+2][c] -> value%5 == b[r][c] -> value%5)
        {
            return 20;      //星星
        }
        else if((c > 1 && b[r][c-2] -> value%5 == b[r][c] -> value%5 && b[r][c-1] -> value%5 == b[r][c] -> value%5) || (c < 6 && b[r][c+2] -> value%5 == b[r][c] -> value%5 && b[r][c+1] -> value%5 == b[r][c] -> value%5))
        {       //T字型
            return (3*5+ b[r][c]-> value%5);       //九宮格炸彈
        }
        else
        {
            b[r-1][c] -> value = b[r-1][c] -> value/5;
            b[r+1][c] -> value = b[r+1][c] -> value/5;
            return b[r][c] -> value/5;
        }
    }
    else
    {       //都無法消除則移回來
        return 5;
    }
}

void MainWindow::creat_special()
{       //產生道具

}

void MainWindow::gamestart()
{
isClick = false;
for(int i = 0; i < 8; i ++)
for(int j = 0; j < 8; j ++)
{
    b[ i ][ j ] -> set_pic();
    b[ i ][ j ] -> show_pic();
    if(j > 1 && b[i][j-2] -> value == b[i][j-1] -> value && b[i][j-1] -> value == b[i][j] -> value)
            j --;
    if(i > 1 && b[i-2][j] -> value == b[i-1][j] -> value && b[i-1][j] -> value == b[i][j] -> value)
            j --;
}
}

void MainWindow::load_pic()
{
for(int i = 0; i < 8; i ++)
for(int j = 0; j < 8; j ++)
{
            b[i][j] -> show_pic();
        }
}

void MainWindow::check_kill()
{       //消除可消除的

}
void MainWindow::button_clicked(int r, int c)
{
    if(!isClick)        //若點擊，儲存第一次點擊位置
    {
        set_click_pic(b[r][c]);
        isClick = true;
        pre_R = r;
        pre_C = c;
    }
    else        //第二次點擊
    {
        if(r-1 == pre_R && pre_C == c)  //為前次點擊的上方
        {
            *b[pre_R][pre_C] + b[r][c];
        }
        else if(r+1 == pre_R && pre_C == c) //為前次點擊的下方
        {
            *b[r][c] + b[pre_R][pre_C];

        }
        else if(pre_R == r && c-1 == pre_C) //為前次點擊的左方
        {
            *b[pre_R][pre_C] - b[r][c];

        }
        else if(pre_R == r && c+1 == pre_C) //為前次點擊的右方
        {
            *b[r][c] - b[pre_R][pre_C];

        }
        else    //若亂點擊
        {
            set_click_pic(b[pre_R][pre_C]);
        }
        isClick = false;
        if(creat_type(r,c) == 5 && creat_type(pre_R,pre_C) == 5)
        {
            if(r-1 == pre_R && pre_C == c)  //為前次點擊的上方
            {
                *b[r][c] + b[pre_R][pre_C];
            }
            else if(r+1 == pre_R && pre_C == c) //為前次點擊的下方
            {
                *b[pre_R][pre_C] + b[r][c];
            }
            else if(pre_R == r && c-1 == pre_C) //為前次點擊的左方
            {
                *b[r][c] - b[pre_R][pre_C];
            }
            else if(pre_R == r && c+1 == pre_C) //為前次點擊的右方
            {
                *b[pre_R][pre_C] - b[r][c];
            }
        }
        else
        {
            if(creat_type(r,c) != 5)
             b[r][c]-> value =creat_type(r,c);
            if(creat_type(pre_R, pre_C) != 5)
             b[pre_R][pre_C] -> value = creat_type(pre_R, pre_C);
        }
    }
}

void MainWindow::killzero()
{
    load_pic();
}
MainWindow::~MainWindow()
{
    delete ui;
}
