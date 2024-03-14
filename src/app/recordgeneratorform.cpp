#include "recordgeneratorform.h"
#include "QIntValidator"
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
  // QString number = ui->lineEdit->text();

  int number = std::stoi(ui->lineEdit->text().toStdString());
  ptrToMainWindow_->getPtrToDatabase()->generateData(number);
}

void RecordGeneratorForm::on_close_pushButton_2_clicked() { close(); }
