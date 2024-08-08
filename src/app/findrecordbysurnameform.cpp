#include "findrecordbysurnameform.h"
#include "mainwindow.h"
#include "ui_findrecordbysurnameform.h"

FindRecordBySurnameForm::FindRecordBySurnameForm(QWidget *parent)
    : QDialog(parent), ui(new Ui::FindRecordBySurnameForm) {
  ui->setupUi(this);
}

FindRecordBySurnameForm::~FindRecordBySurnameForm() {}

void FindRecordBySurnameForm::setPtrToMainWindow(MainWindow *ptrToMainWindow)
{
  ptrToMainWindow_ = ptrToMainWindow;
}
