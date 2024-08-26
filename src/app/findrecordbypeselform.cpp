#include "findrecordbypeselform.h"
#include "mainwindow.h"
#include "ui_findrecordbypeselform.h"

FindRecordByPeselForm::FindRecordByPeselForm(QWidget *parent) : QDialog(parent), ui(std::make_unique<Ui::FindRecordByPeselForm>())
{
    ui->setupUi(this);
}

FindRecordByPeselForm::~FindRecordByPeselForm()
{
}

void FindRecordByPeselForm::appendTextToLabel(const QString &text)
{
    QString temp = ui->label->text();
    temp.append(text + "\n");
    ui->label->setText(temp);
}

void FindRecordByPeselForm::setPtrToMainWindow(MainWindow *ptrToMainWindow)
{
    ptrToMainWindow_ = ptrToMainWindow;
}

void FindRecordByPeselForm::on_pushButton_clicked()
{
    close();
}

void FindRecordByPeselForm::on_pushButton_2_clicked()
{
    ui->label->setText("");
    QString pesel = ui->lineEdit->text();
    std::string record = ptrToMainWindow_->getPtrToDatabase()->returnRecordWithGivenPesel(pesel.toStdString());
    if (record.empty())
    {
        appendTextToLabel("no records found with the given surname");
    }
    appendTextToLabel(QString::fromStdString(record));
}
