#include "mainwindow.h"

#include <QApplication>

#include "Database.hpp"
#include "Menu.hpp"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    Database database;
    Menu menu{database};

    return a.exec();
}
