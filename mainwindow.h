#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "blank.h"
#include <ctime>
#include <cstdlib>
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    int pre_R, pre_C;
    int creat_type(int r, int c);
    void creat_special();
    void gamestart();
    void load_pic();
    void check_kill();
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
