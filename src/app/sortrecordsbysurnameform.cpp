#include "sortrecordsbysurnameform.h"

#include "ui_sortrecordsbysurnameform.h"

SortRecordsBySurnameForm::SortRecordsBySurnameForm(QWidget *parent)
    : QDialog(parent), ui(new Ui::SortRecordsBySurnameForm)
{
    ui->setupUi(this);
}

SortRecordsBySurnameForm::~SortRecordsBySurnameForm()
{
    delete ui;
}

void SortRecordsBySurnameForm::on_pushButton_clicked()
{
    close();
}
