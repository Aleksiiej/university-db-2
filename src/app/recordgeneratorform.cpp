#include "recordgeneratorform.h"
#include "QIntValidator"
#include "QString"
#include "mainwindow.h"
#include "ui_recordgeneratorform.h"

RecordGeneratorForm::RecordGeneratorForm(QWidget *parent)
    : QDialog(parent), ui(new Ui::RecordGeneratorForm) {
  ui->setupUi(this);
}

RecordGeneratorForm::~RecordGeneratorForm() {}

void RecordGeneratorForm::setPtrToMainWindow(MainWindow *ptrToMainWindow) {
  ptrToMainWindow_ = ptrToMainWindow;
}

void RecordGeneratorForm::on_generate_records_pushButton_clicked() {
  ui->lineEdit->setValidator(new QIntValidator(0, 100, this));
  int pos = 0;
  QString number = ui->lineEdit->text();
  if (ui->lineEdit->validator()->validate(number, pos) == 2) {
    ptrToMainWindow_->getPtrToDatabase()->generateData(number.toInt());
    ptrToInformationForm_ = std::make_unique<InformationForm>();
    ptrToInformationForm_->setRecordCreationSuccesText();
    ptrToInformationForm_->show();
  } else {
    ptrToInformationForm_ = std::make_unique<InformationForm>();
    ptrToInformationForm_->setRecordCreationFailureText();
    ptrToInformationForm_->show();
  }
}

void RecordGeneratorForm::on_close_pushButton_2_clicked() { close(); }
