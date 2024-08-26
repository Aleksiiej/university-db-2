#include "sortrecordsbysurnameform.h"
#include "ui_sortrecordsbysurnameform.h"

SortRecordsBySurnameForm::SortRecordsBySurnameForm(QWidget *parent)
    : QDialog(parent), ui(std::make_unique<Ui::SortRecordsBySurnameForm>())
{
    ui->setupUi(this);
}

SortRecordsBySurnameForm::~SortRecordsBySurnameForm()
{
}

void SortRecordsBySurnameForm::on_pushButton_clicked()
{
    close();
}
