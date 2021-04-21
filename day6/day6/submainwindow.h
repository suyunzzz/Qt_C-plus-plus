#ifndef SUBMAINWINDOW_H
#define SUBMAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class SubMainWindow;
}

class SubMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SubMainWindow(QWidget *parent = 0);
    ~SubMainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::SubMainWindow *ui;
signals:
    void back_signal();
    void exit_signal();
};

#endif // SUBMAINWINDOW_H
