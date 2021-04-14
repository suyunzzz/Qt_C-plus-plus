#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    subPtr = new SubWidget();       // 子窗口的指针赋予初值

    setWindowTitle("大哥");
    resize(600,600);
    // 第一个按钮
    b.setParent(this);
    b.setText("123");
    b.move(100,100);
    connect(&b,&QPushButton::pressed,this,&myslot);         // 修改button的值

    // 第二个按钮
    b_exit.setParent(this);
    b_exit.setText("exit");
    b_exit.move(150,150);
    b_exit.resize(50,50);
    connect(&b_exit,&QPushButton::pressed,this,&close);

    // 第三个按钮
    // 如果直接在这创建对象，属于临时变量，构造函数结束，内存消失，所以 这个是不存在的
    QPushButton b3;
    b3.setParent(this);
    b3.setText("new");
    // 如果是在堆中分配内存（new），那么可以运行
    QPushButton *b3_ptr = new QPushButton("b_3_ptr",this);


    // 第四个按钮，切换到子窗口
    QPushButton *b4 = new QPushButton("切换到子窗口",this);
    b4->move(200,200);
    connect(b4,QPushButton::clicked,this,&changeWin);


    // 接收第一个子窗口信号
    void(SubWidget::*funcPtr0)() = SubWidget::my_signal;        // 子窗口的第一种信号
    connect(subPtr,funcPtr0,this,dealSub);

    // 接收第二个子窗口信号
    void(SubWidget::*funcPtr)(int,QString) = SubWidget::my_signal;      // 子窗口发布的第二种信号
    connect(subPtr,funcPtr,this,[](int a,QString str)                   // 匿名函数 lamda表达式
    {
        qDebug()<<"收到："<<a<<' '<<str;
//        subPtr->hide();
//        this->show();
    }


    );
}



void Widget::myslot()
{
    b.setText("999");
}

void Widget::changeWin()
{
    this->hide();
    subPtr->show();
}

void Widget::dealSub()
{
    subPtr->hide();
    this->show();

}

Widget::~Widget()
{

}
