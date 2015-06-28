#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "row.h"
#include "column.h"
#include "nineblock.h"
#include "blank.h"
#include "kill.h"
#include <ctime>
#include <cstdlib>
#include <QMainWindow>
#include <QLCDNumber>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    int pre_R, pre_C, type, star, score, count;
//    int st, sc;
    int creat_type(int r, int c);
//    int getStar(){return star;}
//    int getScore(){return score;}
//    void setStar(int st){star = st;}
//    void setScore(int sc){score = sc;}
    void check_type(int r, int c);
    void gamestart();
    void load_pic();
    void check_kill(int r, int c);
    void set_click_pic(Blank *b);
    bool isClick;
    ~MainWindow();
signals:
    void movedone();
public slots:
    void button_clicked(int r, int c);
    void killzero();
private:
    Ui::MainWindow *ui;
    Blank *b[8][8];
};

#endif // MAINWINDOW_H
