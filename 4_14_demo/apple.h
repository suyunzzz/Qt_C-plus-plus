#ifndef APPLE_H
#define APPLE_H

#include <QMainWindow>

#include <QString>
namespace Ui {
class Apple;
}

class Apple : public QMainWindow
{
    Q_OBJECT

public:
    explicit Apple(QWidget *parent = 0);
    ~Apple();

private slots:
    void on_pushButton_exit_clicked();

    void on_pushButton_add_clicked();

    void on_lineEdit_second_textEdited(const QString &arg1);

    void on_lineEdit_first_textChanged(const QString &arg1);

private:
    Ui::Apple *ui;
};

#endif // APPLE_H
