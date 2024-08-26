#include "validatepeselform.h"
#include "ui_validatepeselform.h"

ValidatePeselForm::ValidatePeselForm(QWidget *parent)
    : QDialog(parent), ui(new Ui::ValidatePeselForm) {
  ui->setupUi(this);
}

ValidatePeselForm::~ValidatePeselForm() { delete ui; }

void ValidatePeselForm::on_pushButton_clicked()
{
  close();
}

void ValidatePeselForm::setPtrToMainWindow(MainWindow *ptrToMainWindow)
{
  ptrToMainWindow_ = ptrToMainWindow;
}

