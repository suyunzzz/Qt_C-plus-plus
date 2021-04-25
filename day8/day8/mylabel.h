#ifndef MYLABEL_H
#define MYLABEL_H

#include <QWidget>
#include <QLabel>

class MyLabel : public QLabel
{
    Q_OBJECT
public:
    explicit MyLabel(QWidget *parent = nullptr);

protected:
    void mousePressEvent(QMouseEvent* ev);

    void mouseReleaseEvent(QMouseEvent* ev);

    void mouseMoveEvent(QMouseEvent* ev);

//    void closeEvent(QCloseEvent* cev);

    void enterEvent(QEvent* ev);

    void leaveEvent(QEvent* ev);

    // 键盘事件
    void keyPressEvent(QKeyEvent* ev);

    // 计时器


signals:

public slots:
};

#endif // MYLABEL_H
