#include "mainwindow.h"
#include "modifysalaryinemployeerecordform.h"
#include "ui_modifysalaryinemployeerecordform.h"

ModifySalaryInEmployeeRecordForm::ModifySalaryInEmployeeRecordForm(QWidget *parent)
    : QDialog(parent), ui(std::make_unique<Ui::ModifySalaryInEmployeeRecordForm>())
{
    ui->setupUi(this);
}

void ModifySalaryInEmployeeRecordForm::setPtrToMainWindow(MainWindow *ptrToMainWindow)
{
    ptrToMainWindow_ = ptrToMainWindow;
}

ModifySalaryInEmployeeRecordForm::~ModifySalaryInEmployeeRecordForm()
{
}

void ModifySalaryInEmployeeRecordForm::on_pushButton_clicked()
{
    close();
}
