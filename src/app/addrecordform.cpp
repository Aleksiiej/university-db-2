#include "addrecordform.h"
#include "mainwindow.h"
#include "ui_addrecordform.h"

AddRecordForm::AddRecordForm(QWidget *parent)
    : QDialog(parent), ui(std::make_unique<Ui::AddRecordForm>()),
      PESELValidatorPtr_(std::make_unique<PESELValidator>()) {
  ui->setupUi(this);
  ui->label_invalidpesel->setHidden(true);
  ui->label_studentEmployeeValue->setHidden(true);
}

AddRecordForm::~AddRecordForm() {}

void AddRecordForm::setPtrToMainWindow(MainWindow *ptrToMainWindow) {
  ptrToMainWindow_ = ptrToMainWindow;
}

void AddRecordForm::on_pushButton_addrecord_clicked() {
  QString name = ui->lineEdit_name->text();
  QString surname = ui->lineEdit_surname->text();
  QString address = ui->lineEdit_address->text();
  QString studentEmployeeValue = ui->lineEdit_studentEmployeeValue->text();
  QString pesel = ui->lineEdit_pesel->text();

  Sex sex;
  if (ui->radioButton_male->isChecked()) {
    sex = Sex::male;
  } else
    sex = Sex::female;

  Position position;
  if (ui->radioButton_student->isChecked()) {
    position = Position::Student;
  } else
    position = Position::Employee;

  if (PESELValidatorPtr_->validatePESEL(pesel.toStdString())) {
    ui->label_invalidpesel->setHidden(true);
  } else
    ui->label_invalidpesel->setHidden(false);

  qDebug() << "Name " << name;
  qDebug() << "Surname " << surname;
  qDebug() << "Address " << address;
  qDebug() << "Position" << static_cast<int>(position);
  qDebug() << "StudentEmployeeValue " << studentEmployeeValue;
  qDebug() << "PESEL " << pesel;
  qDebug() << "Sex " << static_cast<int>(sex);

  if (position == Position::Student) {
    ptrToMainWindow_->getPtrToDatabase()->addStudent(
        name.toStdString(), surname.toStdString(), address.toStdString(),
        studentEmployeeValue.toFloat(), pesel.toStdString(), sex, position);
  } else {
    ptrToMainWindow_->getPtrToDatabase()->addEmployee(
        name.toStdString(), surname.toStdString(), address.toStdString(),
        studentEmployeeValue.toFloat(), pesel.toStdString(), sex, position);
  }
}

void AddRecordForm::on_pushButton_close_clicked() { close(); }

void AddRecordForm::on_radioButton_student_clicked() {
  ui->label_studentEmployeeValue->setText("Index");
  ui->label_studentEmployeeValue->show();
}

void AddRecordForm::on_radioButton_employee_clicked() {
  ui->label_studentEmployeeValue->setText("Salary");
  ui->label_studentEmployeeValue->show();
}
