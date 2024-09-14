#include "validatepeselform.h"
#include "mainwindow.h"
#include "ui_validatepeselform.h"

ValidatePeselForm::ValidatePeselForm(QWidget *parent)
    : QDialog(parent), ui(std::make_unique<Ui::ValidatePeselForm>()),
      PESELValidatorPtr_(std::make_unique<PESELValidator>())
{
    ui->setupUi(this);
}

ValidatePeselForm::~ValidatePeselForm()
{
}

void ValidatePeselForm::on_pushButton_clicked()
{
    close();
}

void ValidatePeselForm::setPtrToMainWindow(MainWindow *ptrToMainWindow)
{
    ptrToMainWindow_ = ptrToMainWindow;
}

void ValidatePeselForm::on_pushButton_2_clicked()
{
    QString pesel = ui->lineEdit->text();
    if (PESELValidatorPtr_->validatePESEL(pesel.toStdString()))
    {
        ui->label->setText("PESEL is valid");
    }
    else
    {
        ui->label->setText("PESEL is invalid");
    }
    ui->label->show();
}
