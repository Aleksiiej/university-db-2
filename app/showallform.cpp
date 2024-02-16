#include "showallform.h"
#include "ui_showallform.h"

ShowAllForm::ShowAllForm(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ShowAllForm)
{
    ui->setupUi(this);
}

ShowAllForm::~ShowAllForm()
{
    delete ui;
}
