#include "sortrecordsbypeselform.h"
#include "ui_sortrecordsbypeselform.h"

SortRecordsByPeselForm::SortRecordsByPeselForm(QWidget *parent)
    : QDialog(parent), ui(new Ui::SortRecordsByPeselForm) {
  ui->setupUi(this);
}

SortRecordsByPeselForm::~SortRecordsByPeselForm() { delete ui; }

void SortRecordsByPeselForm::on_pushButton_clicked()
{
  close();
}

