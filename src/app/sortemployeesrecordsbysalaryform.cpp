#include "sortemployeesrecordsbysalaryform.h"

#include "mainwindow.h"
#include "ui_sortemployeesrecordsbysalaryform.h"

SortEmployeesRecordsBySalaryForm::SortEmployeesRecordsBySalaryForm(
  QWidget* parent)
  : QDialog(parent)
  , ui(new Ui::SortEmployeesRecordsBySalaryForm)
{
  ui->setupUi(this);
}

SortEmployeesRecordsBySalaryForm::~SortEmployeesRecordsBySalaryForm()
{
  delete ui;
}

void
SortEmployeesRecordsBySalaryForm::appendTextToLabel(const QString& text)
{
  QString temp = ui->label_2->text();
  temp.append(text + "\n");
  ui->label_2->setText(temp);
}

void
SortEmployeesRecordsBySalaryForm::setPtrToMainWindow(
  MainWindow* ptrToMainWindow)
{
  ptrToMainWindow_ = ptrToMainWindow;
}

void
SortEmployeesRecordsBySalaryForm::on_pushButton_clicked()
{
  close();
}
