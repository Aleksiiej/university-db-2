#include "showallform.h"
#include "mainwindow.h"
#include "ui_showallform.h"

ShowAllForm::ShowAllForm(QWidget *parent) : QDialog(parent), ui(std::make_unique<Ui::ShowAllForm>())
{
    ui->setupUi(this);
    ui->label->setText("");
}

ShowAllForm::~ShowAllForm()
{
}

void ShowAllForm::appendTextToLabel(const QString &text)
{
    QString temp = ui->label->text();
    temp.append(text + "\n");
    ui->label->setText(temp);
}

void ShowAllForm::setPtrToMainWindow(MainWindow *ptrToMainWindow)
{
    ptrToMainWindow_ = ptrToMainWindow;
}

void ShowAllForm::on_pushButton_clicked()
{
    ui->label->setText("");
    std::string records = ptrToMainWindow_->getPtrToDatabase()->returnRecordsAsString();
    appendTextToLabel(QString::fromStdString(records));
}

void ShowAllForm::on_pushButton_2_clicked()
{
    close();
}
