#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "apple.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_exit_clicked();          // 点击按钮，实现退出，直接在ui设计师中指定，就不需要使用connect函数了

    void on_pushButton_apple_clicked();

private:
    Ui::MainWindow *ui;
    Apple *apple;
};

#endif // MAINWINDOW_H
