#include "mybutton.h"
#include <QMouseEvent>
#include <QDebug>

MyButton::MyButton(QWidget *parent) : QPushButton(parent)
{

}

void MyButton::mousePressEvent(QMouseEvent *ev)
{
    if(ev->button() == Qt::LeftButton)          // 事件的接收
    {
        qDebug()<<"左键被按下";

        ev->ignore();           // 事件的忽略，事件继续往下传播。
                                // 不往父类传，往父组件传
    }
    else
    {
        QPushButton::mousePressEvent(ev);           // 事件的忽略
//        ev->ignore();
    }

//    QPushButton::mousePressEvent(ev);           // 调用父类的处理函数
}
