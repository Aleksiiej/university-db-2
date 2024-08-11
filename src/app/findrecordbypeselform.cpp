#include "findrecordbypeselform.h"
#include "mainwindow.h"
#include "ui_findrecordbypeselform.h"

FindRecordByPeselForm::FindRecordByPeselForm(QWidget *parent)
    : QDialog(parent), ui(new Ui::FindRecordByPeselForm) {
  ui->setupUi(this);
}

FindRecordByPeselForm::~FindRecordByPeselForm() { delete ui; }

// void FindRecordByPeselForm::appendTextToLabel(const QString &text) {
//   QString temp = ui->label->text();
//   temp.append(text + "\n");
//   ui->label->setText(temp);
// }

void FindRecordByPeselForm::setPtrToMainWindow(MainWindow *ptrToMainWindow)
{
  ptrToMainWindow_ = ptrToMainWindow;
}

void FindRecordByPeselForm::on_pushButton_clicked()
{
  close();
}
