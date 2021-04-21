#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QAction>
#include <QDebug>
#include <QPushButton>
#include <QCompleter>
#include <QStringList>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->actionclose->setText("^^");
    connect(ui->actionclose,QAction::triggered,this,[](){
        qDebug()<<"---------";
    });

    connect(ui->pushButton,QPushButton::released,this,[=]{
        this->close();
        qDebug()<<"close";
    });


    // QlineEdit
    QString str  = ui->lineEdit->text();
    qDebug()<<str;
    ui->lineEdit->setTextMargins(15,0,0,0);
//    ui->lineEdit->setEchoMode(QLineEdit::Password);     // 密码设置

    // 设置账号提示
    QStringList list;
    list<<"he"<<"li"<<"wang";
    QCompleter *com = new QCompleter( list,this);
    com->setCaseSensitivity(Qt::CaseInsensitive);   // 设置大小写不敏感
    ui->lineEdit->setCompleter(com);

    // 设置label
    ui->text->setText("**");
    // 设置image
    ui->image->setPixmap(QPixmap("://C:/Users/11604/Pictures/p2575454565.jpg"));
    ui->image->setScaledContents(true);

    //设置Url
//    ui->Url->setText();


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    qDebug()<<"clicker";
}

void MainWindow::on_change_clicked()
{
    static int i = 0;
    ui->stackedWidget->setCurrentIndex(++i%2);
}
