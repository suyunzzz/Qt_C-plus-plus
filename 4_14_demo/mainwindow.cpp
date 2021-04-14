#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_exit_clicked()
{
    exit(0);
}

void MainWindow::on_pushButton_apple_clicked()
{
    apple = new Apple();            // 指针赋值
    apple->show();
}
