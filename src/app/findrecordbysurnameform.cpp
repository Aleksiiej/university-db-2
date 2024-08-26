#include "findrecordbysurnameform.h"

#include "mainwindow.h"
#include "ui_findrecordbysurnameform.h"

FindRecordBySurnameForm::FindRecordBySurnameForm(QWidget *parent) : QDialog(parent), ui(new Ui::FindRecordBySurnameForm)
{
    ui->setupUi(this);
}

FindRecordBySurnameForm::~FindRecordBySurnameForm()
{
}

void FindRecordBySurnameForm::appendTextToLabel(const QString &text)
{
    QString temp = ui->label->text();
    temp.append(text + "\n");
    ui->label->setText(temp);
}

void FindRecordBySurnameForm::setPtrToMainWindow(MainWindow *ptrToMainWindow)
{
    ptrToMainWindow_ = ptrToMainWindow;
}

void FindRecordBySurnameForm::on_pushButton_clicked()
{
    close();
}

void FindRecordBySurnameForm::on_pushButton_2_clicked()
{
    ui->label->setText("");
    QString surname = ui->lineEdit->text();
    std::string records = ptrToMainWindow_->getPtrToDatabase()->returnRecordsWithGivenSurname(surname.toStdString());
    if (records.empty())
    {
        appendTextToLabel("no records found with the given surname");
    }
    appendTextToLabel(QString::fromStdString(records));
}
