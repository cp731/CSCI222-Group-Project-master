#include "buglist.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BugList start;
    start.show();

    return a.exec();
}
