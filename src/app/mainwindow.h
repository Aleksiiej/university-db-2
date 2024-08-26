#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Database.hpp"
#include "addrecordform.h"
#include "findrecordbypeselform.h"
#include "findrecordbysurnameform.h"
#include "informationform.h"
#include "modifysalaryinemployeerecordform.h"
#include "recordgeneratorform.h"
#include "removestudentrecordbyindexform.h"
#include "showallform.h"
#include "sortemployeesrecordsbysalaryform.h"
#include "sortrecordsbypeselform.h"
#include "sortrecordsbysurnameform.h"
#include "validatepeselform.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  MainWindow(std::shared_ptr<Database> ptrToDatabase,
             QWidget *parent = nullptr);
  ~MainWindow();

  std::shared_ptr<Database> getPtrToDatabase();

private slots:
  void on_pushButton_clicked();

  void on_pushButton_2_clicked();

  void on_pushButton_3_clicked();

  void on_pushButton_4_clicked();

  void on_pushButton_5_clicked();

  void on_pushButton_6_clicked();

  void on_pushButton_7_clicked();

  void on_pushButton_8_clicked();

  void on_pushButton_9_clicked();

  void on_pushButton_10_clicked();

  void on_pushButton_11_clicked();

  void on_pushButton_12_clicked();

  void on_pushButton_13_clicked();

  void on_pushButton_14_clicked();

private:
  std::unique_ptr<Ui::MainWindow> ui;
  std::shared_ptr<Database> ptrToDatabase_;
  std::shared_ptr<RecordGenerator> ptrToRGenerator_;
  std::unique_ptr<AddRecordForm> ptrToAddRecordForm_;
  std::unique_ptr<ShowAllForm> ptrToShowAllForm_;
  std::unique_ptr<FindRecordByPeselForm> ptrToFindRecordByPeselForm_;
  std::unique_ptr<FindRecordBySurnameForm> ptrToFindRecordBySurnameForm_;
  std::unique_ptr<SortEmployeesRecordsBySalaryForm> ptrToSortEmployeedRecordsBySalaryForm_;
  std::unique_ptr<SortRecordsByPeselForm> ptrToSortRecordsByPeselForm_;
  std::unique_ptr<SortRecordsBySurnameForm> ptrToSortRecordsBySurnameForm_;
  std::unique_ptr<RemoveStudentRecordByIndexForm> ptrToRemoveStudentRecordByIndexForm_;
  std::unique_ptr<ModifySalaryInEmployeeRecordForm> ptrToModifySalaryInEmployeeRecordForm_;
  std::unique_ptr<ValidatePeselForm> ptrToValidatePeselForm_;
  std::unique_ptr<RecordGeneratorForm> ptrToRGeneratorForm_;
  std::unique_ptr<InformationForm> ptrToInformationForm_;
};
#endif // MAINWINDOW_H
