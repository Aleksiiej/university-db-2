#include "informationform.h"
#include "ui_informationform.h"

InformationForm::InformationForm(QWidget *parent)
    : QDialog(parent), ui(new Ui::InformationForm) {
  ui->setupUi(this);
}

InformationForm::~InformationForm() { delete ui; }

void InformationForm::setRecordCreationSuccesText() {
  ui->label->setText("Records created");
}

void InformationForm::setRecordCreationFailureText() {
  ui->label->setText("Invalid number");
}

void InformationForm::setSaveSuccesText() {
  ui->label->setText("Save succesful");
}

void InformationForm::setSavefailureText() {
  ui->label->setText("Save failed");
}

void InformationForm::on_pushButton_clicked() { close(); }
