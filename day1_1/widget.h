#ifndef WIDGET_H
#define WIDGET_H
#include <iostream>
#include <QWidget>
#include <QPushButton>
#include <QDebug>
#include "subwidget.h"


class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
    void myslot();
    void changeWin();
//    void changeWin2();          //
    void dealSub();             // 恢复主窗口、最小化子窗口的函数

private:
    QPushButton b;
    QPushButton b_exit;
    SubWidget *subPtr;
};

#endif // WIDGET_H
