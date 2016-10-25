#-------------------------------------------------
#
# Project created by QtCreator 2016-10-22T12:53:12
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BugTrackingSystem
TEMPLATE = app


SOURCES += main.cpp\
        login.cpp \
    profilepage.cpp \
    adminprofile.cpp \
    adduser.cpp \
    enable_disable.cpp \
    buglist.cpp \
    reportbug.cpp \
    developerpage.cpp \
    bugdisplay.cpp

HEADERS  += login.h \
    profilepage.h \
    adminprofile.h \
    adduser.h \
    connect.h \
    enable_disable.h \
    buglist.h \
    reportbug.h \
    developerpage.h \
    bugdisplay.h

FORMS    += login.ui \
    profilepage.ui \
    adminprofile.ui \
    adduser.ui \
    enable_disable.ui \
    buglist.ui \
    reportbug.ui \
    developerpage.ui \
    bugdisplay.ui
