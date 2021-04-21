/********************************************************************************
** Form generated from reading UI file 'submainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUBMAINWINDOW_H
#define UI_SUBMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SubMainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer_4;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SubMainWindow)
    {
        if (SubMainWindow->objectName().isEmpty())
            SubMainWindow->setObjectName(QStringLiteral("SubMainWindow"));
        SubMainWindow->resize(412, 572);
        centralwidget = new QWidget(SubMainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QStringLiteral("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(122, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setMaximumSize(QSize(200, 200));

        horizontalLayout->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(122, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        gridLayout->addWidget(widget, 0, 0, 1, 1);

        widget_2 = new QWidget(centralwidget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(48, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        pushButton = new QPushButton(widget_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_2->addWidget(pushButton);

        horizontalSpacer_5 = new QSpacerItem(49, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        pushButton_2 = new QPushButton(widget_2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout_2->addWidget(pushButton_2);

        horizontalSpacer_4 = new QSpacerItem(48, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        gridLayout->addWidget(widget_2, 1, 0, 1, 1);

        SubMainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(SubMainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 412, 26));
        SubMainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(SubMainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        SubMainWindow->setStatusBar(statusbar);

        retranslateUi(SubMainWindow);

        QMetaObject::connectSlotsByName(SubMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *SubMainWindow)
    {
        SubMainWindow->setWindowTitle(QApplication::translate("SubMainWindow", "MainWindow", Q_NULLPTR));
        label->setText(QApplication::translate("SubMainWindow", "SubMainWindow", Q_NULLPTR));
        pushButton->setText(QApplication::translate("SubMainWindow", "\350\277\224\345\233\236", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("SubMainWindow", "Exit", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SubMainWindow: public Ui_SubMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUBMAINWINDOW_H
