#include "modifysalaryinemployeerecordform.h"
#include "QIntValidator"
#include "RecordGenerator.hpp"
#include "mainwindow.h"
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

void ModifySalaryInEmployeeRecordForm::on_pushButton_2_clicked()
{
    QString pesel = ui->lineEdit->text();
    if (ptrToMainWindow_->getPtrToDatabase()->validatePESEL(pesel.toStdString()))
    {
        ui->label_3->setText("");
        ui->lineEdit_2->setValidator(new QIntValidator(minSalary, maxSalary, this));
        QString newSalary = ui->lineEdit_2->text();
        int pos = 0;
        if (ui->lineEdit_2->validator()->validate(newSalary, pos) == 2)
        {
            ptrToMainWindow_->getPtrToDatabase()->modifySalary(pesel.toStdString(), newSalary.toFloat());
        }
        else
        {
            ui->label_3->setText("invalid salary value");
        }
    }
    else
    {
        ui->label_3->setText("no records found with the given PESEL");
    }
}
