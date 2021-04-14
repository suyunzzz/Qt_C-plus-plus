#include "subwidget.h"

SubWidget::SubWidget(QWidget *parent) : QWidget(parent)
{
    setWindowTitle("小弟");
    resize(400,400);

    // 按钮
    b1 = new QPushButton("返回父窗口",this);
    b1->move(200,200);

    // 信号与槽
    // 点击按钮，链接一个槽函数，槽函数内部发出一个信号，然后再widget类中捕捉这个信号
    connect(b1,QPushButton::clicked,this,SubWidget::sendSlot);

}

void SubWidget::sendSlot()
{
    emit my_signal();
    emit my_signal(250,"我是小弟，请求切换到大哥\n");
}
