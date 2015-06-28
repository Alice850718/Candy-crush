#ifndef BLANK_H
#define BLANK_H

#include <QTimer>
#include <QPushButton>
#include <QObject>

class Blank:public QObject
{
    Q_OBJECT
public:
    int value, shift;
    const int row;
    const int column;
    void set_pic();
    void show_pic();
    void operator +(Blank *b);
    void operator -(Blank *b);
    Blank(int row, int column, QWidget *parent);
    QPushButton *button;
    QTimer *time;
    ~Blank();
public slots:
    void click();
    void moveup();
    void movedown();
    void moveleft();
    void moveright();
signals:
    void Click(int r, int c);
    void movedone();
};

#endif // BLANK_H
