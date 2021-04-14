#include "apple.h"
#include "ui_apple.h"

Apple::Apple(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Apple)
{
    ui->setupUi(this);
}

Apple::~Apple()
{
    delete ui;
}

void Apple::on_pushButton_exit_clicked()
{
    close();
}

void Apple::on_pushButton_add_clicked()
{
    // 获取两个lineEdit的内容
    int first,second;
    QString result;
    first = ui->lineEdit_first->text().toInt();
    second = ui->lineEdit_second->text().toInt();
    result = QString::number(first+second);
    ui->lineEdit_result->setText(result);

}

void Apple::on_lineEdit_second_textEdited(const QString &arg1)
{
    printf("second: %s\t",arg1.toStdString().data());
    ui->lineEdit_result->setText("");       // 归零
    on_pushButton_add_clicked();
}

void Apple::on_lineEdit_first_textChanged(const QString &arg1)
{
    printf("first: %s\t",arg1.toStdString().data());                // Qstring转String类型
    ui->lineEdit_result->setText("");
    on_pushButton_add_clicked();
}
