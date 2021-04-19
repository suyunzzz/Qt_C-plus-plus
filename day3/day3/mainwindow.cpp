// day3 创建对话框
#include "mainwindow.h"
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QDialog>

#include <QToolBar>
#include <QString>
#include <QDebug>
#include <QMessageBox>          // 关于对话框
#include <QFileDialog>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    resize(300,300);
    // 创建菜单栏
    QMenuBar *pMenuBar = menuBar();
    setMenuBar(pMenuBar);

    // 创建菜单
    QMenu* pMenu = pMenuBar->addMenu("对话框");

// 模态对话框，不能切换父窗口
    QAction *b1 = pMenu->addAction("模态对话框");
    connect(b1,QAction::triggered,this,[=](){

        QDialog dlg;
        dlg.exec();
        qDebug()<<"---";
    });

// 非模态对话框，可以切换父窗口
    QAction *b2 = pMenu->addAction("非模态对话框");
    connect(b2,QAction::triggered,[=](){
        QDialog *pDlg = new QDialog();
        pDlg->resize(100,100);
        pDlg->setAttribute(Qt::WA_DeleteOnClose);           // 关闭对话框的时候内存释放

        pDlg->show();
        qDebug()<<"+++";
    });

    pMenu->addSeparator();

// 标准对话框
    QAction *b3 = pMenu->addAction("关于对话框");
    connect(b3,QAction::triggered,[=]{
        QMessageBox::about(this,"about","this is about");
    });

    QAction *b4 = pMenu->addAction("问题对话框");
    connect(b4,QAction::triggered,[=]{
        int ret = QMessageBox::question(this,"问题对话框","this is question",QMessageBox::Ok|QMessageBox::Cancel);
        switch (ret) {
        case QMessageBox::Ok:
            qDebug()<<"this is OK";
            break;
        case QMessageBox::Cancel:
            qDebug()<<"this is Cancel";
            break;
        default:
            qDebug()<<"this is default";
            break;
        }
    });

// 文件对话框
    QAction *b5 = pMenu->addAction("文件对话框");
    connect(b5,QAction::triggered,[=]{
        QString filename = QFileDialog::getOpenFileName(this,"打开文件","../",
                                     tr("source (*.cpp *.c *.h);;Text (*.txt);;"
                                        "all (*.*)"));
        qDebug()<<filename;

    });

    // 创建关闭按钮
    QPushButton *p1 = new QPushButton(this);
    p1->setText("close");
    p1->move(200,200);
    connect(p1,QPushButton::released,this,[=]{
        this->close();
        qDebug()<<"close";
    });
}

MainWindow::~MainWindow()
{

}
