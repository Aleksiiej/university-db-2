#include "removestudentrecordbyindexform.h"

#include "mainwindow.h"
#include "ui_removestudentrecordbyindexform.h"

RemoveStudentRecordByIndexForm::RemoveStudentRecordByIndexForm(QWidget *parent)
    : QDialog(parent), ui(new Ui::RemoveStudentRecordByIndexForm)
{
    ui->setupUi(this);
}

RemoveStudentRecordByIndexForm::~RemoveStudentRecordByIndexForm()
{
    delete ui;
}

void RemoveStudentRecordByIndexForm::setPtrToMainWindow(MainWindow *ptrToMainWindow)
{
    ptrToMainWindow_ = ptrToMainWindow;
}

void RemoveStudentRecordByIndexForm::on_pushButton_clicked()
{
    close();
}

void RemoveStudentRecordByIndexForm::on_pushButton_2_clicked()
{
    int index = ui->lineEdit->text().replace(" ", "").toInt();
    if (ptrToMainWindow_->getPtrToDatabase()->checkIfGivenIndexExist(index))
    {
        ptrToMainWindow_->getPtrToDatabase()->removeByIndex(index);
        ui->label->setText("Record removed");
    }
    else
    {
        ui->label->setText("No record with given index");
    }
}
