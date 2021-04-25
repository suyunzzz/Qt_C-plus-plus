#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QKeyEvent>
#include <QDebug>
#include <QCloseEvent>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;

    int timerId;
    int timerId2;

protected:
    // 键盘响应
    void keyPressEvent(QKeyEvent* ev);

    // 定时器
    void timerEvent(QTimerEvent* ev);

    // 鼠标单击
    void mousePressEvent(QMouseEvent* ev);

    // 关闭事件
    void closeEvent(QCloseEvent* ev);

    bool event(QEvent *event);

    // 事件过滤器
    bool eventFilter(QObject *watched, QEvent *event);
};

#endif // WIDGET_H
