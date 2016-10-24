/********************************************************************************
** Form generated from reading UI file 'profilepage.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROFILEPAGE_H
#define UI_PROFILEPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProfilePage
{
public:
    QMenuBar *menubar;
    QWidget *centralwidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ProfilePage)
    {
        if (ProfilePage->objectName().isEmpty())
            ProfilePage->setObjectName(QStringLiteral("ProfilePage"));
        ProfilePage->resize(800, 600);
        menubar = new QMenuBar(ProfilePage);
        menubar->setObjectName(QStringLiteral("menubar"));
        ProfilePage->setMenuBar(menubar);
        centralwidget = new QWidget(ProfilePage);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        ProfilePage->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(ProfilePage);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        ProfilePage->setStatusBar(statusbar);

        retranslateUi(ProfilePage);

        QMetaObject::connectSlotsByName(ProfilePage);
    } // setupUi

    void retranslateUi(QMainWindow *ProfilePage)
    {
        ProfilePage->setWindowTitle(QApplication::translate("ProfilePage", "MainWindow", 0));
    } // retranslateUi

};

namespace Ui {
    class ProfilePage: public Ui_ProfilePage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROFILEPAGE_H
