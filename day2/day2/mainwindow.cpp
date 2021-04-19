#include "mainwindow.h"
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QDebug>
#include <QToolBar>
#include <QPushButton>
#include <QStatusBar>
#include <QTextEdit>
#include <QLabel>
#include <QDockWidget>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    resize(400,400);
//    设置菜单栏
    QMenuBar *mBar = menuBar();
    QMenu *pFile = mBar->addMenu("File");
    QAction* pNew = pFile->addAction("new");
    connect( pNew,QAction::triggered,[]{
        qDebug() <<"create new file";
    });

    // 添加分隔符
    QAction* pSeparator = pFile->addSeparator();

    // 菜单中添加open Action
    QAction* pOpen = pFile->addAction("Open");
    connect(pOpen,QAction::triggered,[pOpen](){         // 传递一个匿名函数作为slot
        pOpen->setText("123Open");
    });


//创建工具栏
    QToolBar *toolBar = addToolBar("toolBar");
    QAction* ppOpen = toolBar->addAction("Open");
    connect(ppOpen,QAction::triggered,[ppOpen](){
       ppOpen->setText("Open222");
    });

    // 创建按钮
    QPushButton *b = new QPushButton("222");
    toolBar->addWidget(b);
    connect(b,QPushButton::released,[b]{
        b->setText("22");
    });

//    创建状态栏
    QStatusBar *pStatusBar = statusBar();
    QLabel *pLable = new QLabel("xxx");
    pStatusBar->addWidget(pLable);
    pStatusBar->addWidget(new QLabel("---"));

    pStatusBar->addPermanentWidget(new QLabel("==="));

//    增加核心控件
    QTextEdit *pQText = new QTextEdit(this);
    setCentralWidget(pQText);
//    浮动窗口
    QDockWidget *pQDockWidget = new QDockWidget("Dock",this);
    addDockWidget(Qt::LeftDockWidgetArea,pQDockWidget,Qt::Horizontal);
    QTextEdit *pQDockEdit = new QTextEdit(this);
    pQDockWidget->setWidget(pQDockEdit);


}

MainWindow::~MainWindow()
{

}
