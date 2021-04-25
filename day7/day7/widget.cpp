#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 样式表
    ui->label->setStyleSheet("Qlabel{color:red;"
                        "background-color:white;}");

    // 设置图片
    this->setStyleSheet("QLabel{border-image:url(:/new/prefix1/image/backiee-194871.jpg);"
                               "}");

    // 设置按钮
    ui->pushButton->setStyleSheet("QPushButton{border:2px outset green;"
                                  "color:red;"
                                  "QPushButton::hover{"
                                  "border-image:url(:/new/prefix1/image/bg.jpg);}"
                                  "QPushButton::pressed{"
                                  "border-image:url(:/new/prefix1/image/DSC_6596-scaled.jpg);}");
}

Widget::~Widget()
{
    delete ui;
}
