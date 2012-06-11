/********************************************************************************
** Form generated from reading UI file 'test.ui'
**
** Created: Mon 11. Jun 16:23:38 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEST_H
#define UI_TEST_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGraphicsView>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab_2;
    QGridLayout *gridLayout_3;
    QGraphicsView *graphicsView_5;
    QGraphicsView *graphicsView_7;
    QGraphicsView *graphicsView_8;
    QGraphicsView *graphicsView_6;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(584, 340);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tab_2->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tab_2->sizePolicy().hasHeightForWidth());
        tab_2->setSizePolicy(sizePolicy);
        gridLayout_3 = new QGridLayout(tab_2);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setSizeConstraint(QLayout::SetMinimumSize);
        graphicsView_5 = new QGraphicsView(tab_2);
        graphicsView_5->setObjectName(QString::fromUtf8("graphicsView_5"));
        graphicsView_5->setMinimumSize(QSize(100, 100));
        graphicsView_5->setMaximumSize(QSize(100, 100));

        gridLayout_3->addWidget(graphicsView_5, 0, 0, 1, 1);

        graphicsView_7 = new QGraphicsView(tab_2);
        graphicsView_7->setObjectName(QString::fromUtf8("graphicsView_7"));
        graphicsView_7->setMinimumSize(QSize(0, 100));
        graphicsView_7->setMaximumSize(QSize(16777215, 100));

        gridLayout_3->addWidget(graphicsView_7, 1, 1, 1, 1);

        graphicsView_8 = new QGraphicsView(tab_2);
        graphicsView_8->setObjectName(QString::fromUtf8("graphicsView_8"));
        graphicsView_8->setMinimumSize(QSize(0, 100));
        graphicsView_8->setMaximumSize(QSize(16777215, 100));

        gridLayout_3->addWidget(graphicsView_8, 0, 1, 1, 1);

        graphicsView_6 = new QGraphicsView(tab_2);
        graphicsView_6->setObjectName(QString::fromUtf8("graphicsView_6"));
        graphicsView_6->setMinimumSize(QSize(100, 100));
        graphicsView_6->setMaximumSize(QSize(100, 100));

        gridLayout_3->addWidget(graphicsView_6, 1, 0, 1, 1);

        tabWidget->addTab(tab_2, QString());

        verticalLayout->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 584, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Tab 2", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEST_H
