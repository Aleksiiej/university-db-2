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

void ShowAllForm::setPtrToMainWindow(std::shared_ptr<MainWindow> ptrToMainWindow)
{
    ptrToMainWindow_ = ptrToMainWindow;
}
