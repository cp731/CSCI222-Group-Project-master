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
    sqlite3.c \
    profilepage.cpp \
    adminprofile.cpp \
    adduser.cpp \
    firstwindow.cpp

HEADERS  += login.h \
    sqlite3.h \
    profilepage.h \
    adminprofile.h \
    adduser.h \
    connect.h \
    firstwindow.h \
    currentuser.h

FORMS    += login.ui \
    profilepage.ui \
    adminprofile.ui \
    adduser.ui \
    firstwindow.ui
