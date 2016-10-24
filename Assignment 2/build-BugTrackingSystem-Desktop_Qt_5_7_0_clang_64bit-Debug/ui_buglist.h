<<<<<<< HEAD:Assignment 2/build-BugTrackingSystem-Desktop_Qt_5_7_0_MinGW_32bit-Debug/ui_buglist.h
/********************************************************************************
** Form generated from reading UI file 'buglist.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BUGLIST_H
#define UI_BUGLIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BugList
{
public:
    QWidget *centralwidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *newBugButton;
    QLineEdit *searchBox;
    QPushButton *searchButton;
    QScrollArea *bugList;
    QWidget *scrollAreaWidgetContents;
    QMenuBar *menubar;
    QMenu *menuBug_List;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *BugList)
    {
        if (BugList->objectName().isEmpty())
            BugList->setObjectName(QStringLiteral("BugList"));
        BugList->resize(948, 668);
        centralwidget = new QWidget(BugList);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 0, 381, 80));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        newBugButton = new QPushButton(horizontalLayoutWidget);
        newBugButton->setObjectName(QStringLiteral("newBugButton"));

        horizontalLayout->addWidget(newBugButton);

        searchBox = new QLineEdit(horizontalLayoutWidget);
        searchBox->setObjectName(QStringLiteral("searchBox"));

        horizontalLayout->addWidget(searchBox);

        searchButton = new QPushButton(horizontalLayoutWidget);
        searchButton->setObjectName(QStringLiteral("searchButton"));

        horizontalLayout->addWidget(searchButton);

        bugList = new QScrollArea(centralwidget);
        bugList->setObjectName(QStringLiteral("bugList"));
        bugList->setGeometry(QRect(10, 80, 931, 541));
        bugList->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 929, 539));
        bugList->setWidget(scrollAreaWidgetContents);
        BugList->setCentralWidget(centralwidget);
        menubar = new QMenuBar(BugList);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 948, 21));
        menuBug_List = new QMenu(menubar);
        menuBug_List->setObjectName(QStringLiteral("menuBug_List"));
        BugList->setMenuBar(menubar);
        statusbar = new QStatusBar(BugList);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        BugList->setStatusBar(statusbar);

        menubar->addAction(menuBug_List->menuAction());

        retranslateUi(BugList);

        QMetaObject::connectSlotsByName(BugList);
    } // setupUi

    void retranslateUi(QMainWindow *BugList)
    {
        BugList->setWindowTitle(QApplication::translate("BugList", "MainWindow", 0));
        newBugButton->setText(QApplication::translate("BugList", "New Bug", 0));
        searchButton->setText(QApplication::translate("BugList", "Search", 0));
        menuBug_List->setTitle(QApplication::translate("BugList", "Bug List", 0));
    } // retranslateUi

};

namespace Ui {
    class BugList: public Ui_BugList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BUGLIST_H
=======
/********************************************************************************
** Form generated from reading UI file 'buglist.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BUGLIST_H
#define UI_BUGLIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BugList
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menuBug_List;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *BugList)
    {
        if (BugList->objectName().isEmpty())
            BugList->setObjectName(QStringLiteral("BugList"));
        BugList->resize(800, 600);
        centralwidget = new QWidget(BugList);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        BugList->setCentralWidget(centralwidget);
        menubar = new QMenuBar(BugList);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        menuBug_List = new QMenu(menubar);
        menuBug_List->setObjectName(QStringLiteral("menuBug_List"));
        BugList->setMenuBar(menubar);
        statusbar = new QStatusBar(BugList);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        BugList->setStatusBar(statusbar);

        menubar->addAction(menuBug_List->menuAction());

        retranslateUi(BugList);

        QMetaObject::connectSlotsByName(BugList);
    } // setupUi

    void retranslateUi(QMainWindow *BugList)
    {
        BugList->setWindowTitle(QApplication::translate("BugList", "MainWindow", 0));
        menuBug_List->setTitle(QApplication::translate("BugList", "Bug List", 0));
    } // retranslateUi

};

namespace Ui {
    class BugList: public Ui_BugList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BUGLIST_H
>>>>>>> 56c400bf7f6505a0fe4933dd0a8e6ab20e231996:Assignment 2/build-BugTrackingSystem-Desktop_Qt_5_7_0_clang_64bit-Debug/ui_buglist.h
