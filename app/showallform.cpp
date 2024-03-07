#include "mainwindow.h"
#include "showallform.h"
#include "ui_showallform.h"

ShowAllForm::ShowAllForm(QWidget *parent)
    : QDialog(parent)
    , ui(std::make_unique<Ui::ShowAllForm>())
{
    ui->setupUi(this);
}

ShowAllForm::~ShowAllForm()
{
}

void ShowAllForm::setPtrToMainWindow(MainWindow* ptrToMainWindow)
{
    ptrToMainWindow_ = ptrToMainWindow;
}

void ShowAllForm::on_pushButton_clicked()
{
    std::string records = ptrToMainWindow_->ptrToDatabase_->returnRecordsAsString();
}

void ShowAllForm::on_pushButton_2_clicked()
{
    close();
}
