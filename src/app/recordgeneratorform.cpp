#include "recordgeneratorform.h"
#include "ui_recordgeneratorform.h"

recordgeneratorform::recordgeneratorform(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::recordgeneratorform)
{
    ui->setupUi(this);
}

recordgeneratorform::~recordgeneratorform()
{
    delete ui;
}
