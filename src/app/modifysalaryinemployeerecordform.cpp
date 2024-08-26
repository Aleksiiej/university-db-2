#include "modifysalaryinemployeerecordform.h"

#include "mainwindow.h"
#include "ui_modifysalaryinemployeerecordform.h"

ModifySalaryInEmployeeRecordForm::ModifySalaryInEmployeeRecordForm(
  QWidget* parent)
  : QDialog(parent)
  , ui(new Ui::ModifySalaryInEmployeeRecordForm)
{
  ui->setupUi(this);
}

void
ModifySalaryInEmployeeRecordForm::setPtrToMainWindow(
  MainWindow* ptrToMainWindow)
{
  ptrToMainWindow_ = ptrToMainWindow;
}

ModifySalaryInEmployeeRecordForm::~ModifySalaryInEmployeeRecordForm()
{
  delete ui;
}

void
ModifySalaryInEmployeeRecordForm::on_pushButton_clicked()
{
  close();
}
