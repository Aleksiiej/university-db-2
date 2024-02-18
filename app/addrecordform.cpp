#include "addrecordform.h"
#include "ui_addrecordform.h"

AddRecordForm::AddRecordForm(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddRecordForm)
    , PESELValidatorPtr_(std::make_unique<PESELValidator>())
{
    ui->setupUi(this);
    ui->label_invalidpesel->setHidden(true);
}

AddRecordForm::~AddRecordForm()
{

}

void AddRecordForm::on_pushButton_addrecord_clicked()
{
    QString name = ui->lineEdit_name->text();
    QString surname = ui->lineEdit_surname->text();
    QString address = ui->lineEdit_address->text();
    QString position = ui->lineEdit_position->text();
    QString pesel = ui->lineEdit_pesel->text();
    QString sex = ui->lineEdit_sex->text();

    if(PESELValidatorPtr_->validatePESEL(pesel.toStdString()))
    {
        ui->label_invalidpesel->setHidden(true);
    }
    else ui->label_invalidpesel->setHidden(false);

    qDebug() << "Name " << name;
    qDebug() << "Surname " << surname;
    qDebug() << "Address " << address;
    qDebug() << "Position " << position;
    qDebug() << "PESEL " << pesel;
    qDebug() << "Sex " << sex;
}

void AddRecordForm::on_pushButton_close_clicked()
{
    close();
}

