#include "recordgeneratorform.h"
#include "ui_recordgeneratorform.h"

RecordGeneratorForm::RecordGeneratorForm(QWidget *parent)
    : QDialog(parent), ui(new Ui::RecordGeneratorForm) {
  ui->setupUi(this);
}

RecordGeneratorForm::~RecordGeneratorForm() {}

void RecordGeneratorForm::setPtrToMainWindow(MainWindow *ptrToMainWindow) {
  ptrToMainWindow_ = ptrToMainWindow;
}

void RecordGeneratorForm::on_generate_records_pushButton_clicked() {}

void RecordGeneratorForm::on_close_pushButton_2_clicked() { close(); }
