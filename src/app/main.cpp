#include "Database.hpp"
#include "mainwindow.h"
#include "RecordGenerator.hpp"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    std::shared_ptr<Database> ptrToDatabase = std::make_shared<Database>();
    std::shared_ptr<RecordGenerator> ptrToRGenerator = std::make_shared<RecordGenerator>();
    MainWindow w{ptrToDatabase, ptrToRGenerator};
    w.show();

    return a.exec();
}
