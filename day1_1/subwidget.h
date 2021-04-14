#ifndef SUBWIDGET_H
#define SUBWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QString>

class SubWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SubWidget(QWidget *parent = nullptr);
    void sendSlot();


signals:
    void my_signal();
    void my_signal(int a,QString str);          // QString 具有自动回收机制


public slots:

private:
    QPushButton *b1;
};

#endif // SUBWIDGET_H
