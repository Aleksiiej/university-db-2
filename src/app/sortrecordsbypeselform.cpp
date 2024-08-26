#include "sortrecordsbypeselform.h"
#include "ui_sortrecordsbypeselform.h"

SortRecordsByPeselForm::SortRecordsByPeselForm(QWidget *parent) : QDialog(parent), ui(std::make_unique<Ui::SortRecordsByPeselForm>())
{
    ui->setupUi(this);
}

SortRecordsByPeselForm::~SortRecordsByPeselForm()
{
}

void SortRecordsByPeselForm::on_pushButton_clicked()
{
    close();
}
