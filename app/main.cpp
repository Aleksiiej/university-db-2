#include "Database.hpp"
#include "mainwindow.h"

#include <QApplication>

// void startapp()
// {

// }

int main(int argc, char *argv[])
{   std::shared_ptr<Database> ptrToDatabase = std::make_shared<Database>();
    QApplication a(argc, argv);
    MainWindow w{ptrToDatabase};
    w.show();

    return a.exec();
}
