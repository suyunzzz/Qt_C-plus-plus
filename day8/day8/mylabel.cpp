#include "mylabel.h"
#include <QMouseEvent>
#include <QDebug>
#include <QKeyEvent>

MyLabel::MyLabel(QWidget *parent) : QLabel(parent)
{
    this->setMouseTracking(true);
}

void MyLabel::mousePressEvent(QMouseEvent *ev)
{
    if(ev->button()==Qt::LeftButton)
    {
        qDebug()<<"LeftButton";
    }
    int i = ev->x();
    int j = ev->y();
    this->setText(QString("<center><h1>Mouse Press: %1 %2</h1></center>").arg(i).arg(j));

}

void MyLabel::mouseReleaseEvent(QMouseEvent *ev)
{
    int i = ev->x();
    int j = ev->y();
    this->setText(QString("<center><h1>Mouse Release: %1 %2</h1></center>").arg(i).arg(j));

}

void MyLabel::mouseMoveEvent(QMouseEvent *ev)
{
    int i = ev->x();
    int j = ev->y();
    this->setText(QString("<center><h1>Mouse Move: %1 %2</h1></center>").arg(i).arg(j));

}

//void MyLabel::closeEvent(QCloseEvent *cev)
//{
//    qDebug()<<"close";
//}

void MyLabel::enterEvent(QEvent *ev)
{
    qDebug()<<"enter Event";

}

void MyLabel::leaveEvent(QEvent *ev)
{
    qDebug()<<"leave Event";

}

void MyLabel::keyPressEvent(QKeyEvent *ev)
{
    qDebug()<<ev->key();
}


