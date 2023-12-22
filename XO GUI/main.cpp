#include "mainwindow.h"

#include <QApplication>
#include <chrono>
#include <thread>
#include "QDebug"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    a.exec();

    return 0;
}
