#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QCompleter>
#include <QStringList>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    pSub = new SubMainWindow();         // 子界面指针初始化

    // 设置标题
    this->setWindowTitle("登录界面");
    QStringList list;
    list<<"wang"<<"li"<<"zhang";
    QCompleter *com = new QCompleter(list,this);
    com->setCaseSensitivity(Qt::CaseInsensitive);
    ui->lineEdit->setCompleter(com);
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);

    // 捕捉子窗口的返回信号
    connect(pSub,SubMainWindow::back_signal,this,back_function);

    // 捕捉子窗口的退出信号
    connect(pSub,SubMainWindow::exit_signal,this,[=](){
        pSub->close();
        this->close();
        qDebug()<<"---exit---";

    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
    this->close();
}

void MainWindow::on_pushButton_clicked()
{
    this->hide();
    pSub->show();
}

void MainWindow::back_function()
{
    pSub->hide();
    this->show();
}
