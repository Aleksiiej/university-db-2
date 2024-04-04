#include "informationform.h"
#include "ui_informationform.h"

InformationForm::InformationForm(QWidget *parent)
    : QDialog(parent), ui(new Ui::InformationForm) {
  ui->setupUi(this);
}

InformationForm::~InformationForm() { delete ui; }

void InformationForm::setRecordConfirmationText() {
  ui->label->setText("Records created");
}

void InformationForm::setRecordDenialText() {
  ui->label->setText("Invalid number");
}

void InformationForm::on_pushButton_clicked() { close(); }
