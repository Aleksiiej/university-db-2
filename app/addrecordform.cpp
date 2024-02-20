#include "addrecordform.h"
#include "mainwindow.h"
#include "ui_addrecordform.h"

AddRecordForm::AddRecordForm(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddRecordForm)
    , PESELValidatorPtr_(std::make_unique<PESELValidator>())
{
    ui->setupUi(this);
    ui->label_invalidpesel->setHidden(true);
}

AddRecordForm::~AddRecordForm()
{

}

void AddRecordForm::setPtrToMainWindow(std::shared_ptr<MainWindow> ptrToMainWindow)
{
    ptrToMainWindow_ = ptrToMainWindow;
}

void AddRecordForm::on_pushButton_addrecord_clicked()
{
    QString name = ui->lineEdit_name->text();
    QString surname = ui->lineEdit_surname->text();
    QString address = ui->lineEdit_address->text();
    QString studentEmployeeValue = ui->lineEdit_studentEmployeeValue->text();
    QString pesel = ui->lineEdit_pesel->text();

    Sex sex;
    if(ui->radioButton_male->isChecked())
    {
        sex = Sex::male;
    }
    else if(ui->radioButton_female->isChecked())
    {
        sex = Sex::female;
    }

    Position position;
    if(ui->radioButton_student->isChecked())
    {
        position = Position::Student;
    }
    else if(ui->radioButton_employee->isChecked())
    {
        position = Position::Employee;
    }

    if(PESELValidatorPtr_->validatePESEL(pesel.toStdString()))
    {
        ui->label_invalidpesel->setHidden(true);
    }
    else ui->label_invalidpesel->setHidden(false);

    qDebug() << "Name " << name;
    qDebug() << "Surname " << surname;
    qDebug() << "Address " << address;
    qDebug() << "StudentEmployeeValue " << studentEmployeeValue;
    qDebug() << "PESEL " << pesel;
    // qDebug() << "Sex " << sex;

    ptrToMainWindow_->ptrToDatabase_->addEmployee(name.toStdString(),
                                                  surname.toStdString(),
                                                  address.toStdString(),
                                                  studentEmployeeValue.toFloat(),
                                                  pesel.toStdString(),
                                                  sex,
                                                  position);
}

void AddRecordForm::on_pushButton_close_clicked()
{
    close();
}

void AddRecordForm::on_radioButton_student_clicked()
{
    ui->label_studentEmployeeValue->setText("Index");
}

void AddRecordForm::on_radioButton_employee_clicked()
{
    ui->label_studentEmployeeValue->setText("Salary");
}

