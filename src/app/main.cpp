#include "Database.hpp"
#include "RecordGenerator.hpp"
#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  std::shared_ptr<Database> ptrToDatabase = std::make_shared<Database>();
  MainWindow w{ptrToDatabase};
  w.show();

  return a.exec();
}
