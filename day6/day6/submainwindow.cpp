#include "submainwindow.h"
#include "ui_submainwindow.h"

SubMainWindow::SubMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SubMainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("子界面");
}

SubMainWindow::~SubMainWindow()
{
    delete ui;
}

void SubMainWindow::on_pushButton_clicked()
{
    emit back_signal();
}

void SubMainWindow::on_pushButton_2_clicked()
{
    emit exit_signal();
}
