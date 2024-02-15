#include "addrecordform.h"
#include "ui_addrecordform.h"

AddRecordForm::AddRecordForm(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddRecordForm)
{
    ui->setupUi(this);
}

AddRecordForm::~AddRecordForm()
{
    delete ui;
}
