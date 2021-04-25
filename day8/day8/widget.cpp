#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    timerId = this->startTimer(1000);       // ms为单位，代表1s
    timerId2 = this->startTimer(500);


    // 按钮的信号与槽
    connect(ui->pushButton,QPushButton::clicked,this,[=]()
    {
        qDebug()<<"按钮被按下";
    });

    // 安装事件过滤器
    ui->label_3->installEventFilter(this);
    ui->pushButton->installEventFilter(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::keyPressEvent(QKeyEvent *ev)
{
    qDebug()<<char(ev->key());
    ui->label->setText(QString("<center><h1> Key Press:%1</center></h1>").arg(char(ev->key())));
//    this->setText(QString("<center><h1>Mouse Press: %1 %2</h1></center>").arg(i).arg(j));

}

void Widget::timerEvent(QTimerEvent *ev)
{
    if(ev->timerId() == timerId)
    {
        static int sec= 0;
        ui->label_2->setText(QString("<center><h1>Timer Out : %1 </h1></center>").arg(sec++));
    }

    if(ev->timerId() == timerId2)
    {
        static int sec2= 0;
        ui->label_3->setText(QString("<center><h1>Timer Out : %1 </h1></center>").arg(sec2++));
        if(sec2==5)
        {
            this->killTimer(timerId2);          // 关闭计时器
        }
    }


}

void Widget::mousePressEvent(QMouseEvent *)
{
    qDebug()<<"*******";
}

void Widget::closeEvent(QCloseEvent *ev)
{
    qDebug()<<"---close---";

    int ret = QMessageBox::question(this,"Question","Do you wangt to close?");
    if(ret==QMessageBox::Yes)
    {
        ev->accept();           // 事件的接收，不往下传递
    }
    else
    {
        ev->ignore();           // 事件的忽略，往父组件传递
    }


}

bool Widget::event(QEvent *event)
{
    // 事件分发
    switch (event->type()) {
    case QEvent::MouseButtonPress:
        mousePressEvent(static_cast<QMouseEvent*>(event));
        break;
    case QEvent::MouseMove:
        mouseMoveEvent(static_cast<QMouseEvent*>(event));
        break;
    default:
        break;
    }

    // 事件过滤
    if(event->type()==QEvent::Timer)
    {
        return true;            // 停止计时器，事件已处理
    }
    else if(event->type()==QEvent::KeyPress)
    {
        QKeyEvent* env = static_cast<QKeyEvent*>(event);
        if(env->key()==Qt::Key_A)
        {
            return QWidget::event(event);
        }
        return true;
    }
    else
    {
        QWidget::event(event);
    }

}

bool Widget::eventFilter(QObject *watched, QEvent *event)
{

    if(watched==ui->label_3)
    {
        QMouseEvent* env = static_cast<QMouseEvent*>(event);

        if(env->type()==QMouseEvent::MouseButtonRelease)
        {
            ui->label_3->setText(QString("<center><h1>Mouse Release: %1 %2</h1></center>").arg(env->x()).arg(env->y()));
            return true;            // 被处理了
        }

        else if(env->type() == QMouseEvent::MouseButtonPress)
        {
            ui->label_3->setText(QString("<center><h1>Mouse Press: %1 %2</h1></center>").arg(env->x()).arg(env->y()));
            return true;            // 被处理了
        }
        else if(env->type() == QMouseEvent::MouseMove)
        {
            ui->label_3->setText(QString("<center><h1>Mouse Move: %1 %2</h1></center>").arg(env->x()).arg(env->y()));
            return true;            // 被处理了
        }

//        QWidget::eventFilter(watched,event);            // 未处理

    }

    if(watched==ui->pushButton)
    {
        QMouseEvent* env = static_cast<QMouseEvent*>(event);
        if(env->button()==Qt::RightButton)
        {
            qDebug()<<"右键被按下";
            QWidget::eventFilter(watched,event);
//            return true;
        }
        else
        {
            QWidget::eventFilter(watched,event);            // 未处理
        }

    }

    QWidget::eventFilter(watched,event);            // 未处理



}



