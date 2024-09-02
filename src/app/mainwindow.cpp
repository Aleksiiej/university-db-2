#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(std::make_unique<Ui::MainWindow>()), ptrToDatabase_(std::make_shared<Database>())
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
}

void MainWindow::showAllRecords()
{
    ui->label->setText(QString::fromStdString(ptrToDatabase_->returnRecordsAsString()));
}

std::shared_ptr<Database>& MainWindow::getPtrToDatabase()
{
    return ptrToDatabase_;
}

void MainWindow::on_pushButton_clicked()
{
    ptrToAddRecordForm_ = std::make_unique<AddRecordForm>(this);
    ptrToAddRecordForm_->setPtrToMainWindow(this);
    ptrToAddRecordForm_->show();
}

void MainWindow::on_pushButton_2_clicked()
{
    showAllRecords();
}

void MainWindow::on_pushButton_3_clicked()
{
    ptrToFindRecordBySurnameForm_ = std::make_unique<FindRecordBySurnameForm>(this);
    ptrToFindRecordBySurnameForm_->setPtrToMainWindow(this);
    ptrToFindRecordBySurnameForm_->show();
}

void MainWindow::on_pushButton_4_clicked()
{
    ptrToFindRecordByPeselForm_ = std::make_unique<FindRecordByPeselForm>(this);
    ptrToFindRecordByPeselForm_->setPtrToMainWindow(this);
    ptrToFindRecordByPeselForm_->show();
}

void MainWindow::on_pushButton_5_clicked()
{
    ptrToDatabase_->sortBySurname();
    showAllRecords();
}

void MainWindow::on_pushButton_6_clicked()
{
    ptrToDatabase_->sortByPESEL();
    showAllRecords();
}

void MainWindow::on_pushButton_7_clicked()
{
    ui->label->setText(QString::fromStdString(ptrToDatabase_->returnEmployeesSortedBySalary()));
}

void MainWindow::on_pushButton_8_clicked()
{
    ptrToRemoveStudentRecordByIndexForm_ = std::make_unique<RemoveStudentRecordByIndexForm>();
    ptrToRemoveStudentRecordByIndexForm_->setPtrToMainWindow(this);
    ptrToRemoveStudentRecordByIndexForm_->show();
}

void MainWindow::on_pushButton_9_clicked()
{
    ptrToModifySalaryInEmployeeRecordForm_ = std::make_unique<ModifySalaryInEmployeeRecordForm>();
    ptrToModifySalaryInEmployeeRecordForm_->setPtrToMainWindow(this);
    ptrToModifySalaryInEmployeeRecordForm_->show();
}

void MainWindow::on_pushButton_10_clicked()
{
    ptrToValidatePeselForm_ = std::make_unique<ValidatePeselForm>();
    ptrToValidatePeselForm_->setPtrToMainWindow(this);
    ptrToValidatePeselForm_->show();
};
void MainWindow::on_pushButton_11_clicked()
{
    getPtrToDatabase()->loadToJson();
    ptrToInformationForm_ = std::make_unique<InformationForm>();
    ptrToInformationForm_->setLoadSuccesText();
    ptrToInformationForm_->show();
    showAllRecords();
}

void MainWindow::on_pushButton_12_clicked()
{
    getPtrToDatabase()->saveToJson();
    ptrToInformationForm_ = std::make_unique<InformationForm>();
    ptrToInformationForm_->setSaveSuccesText();
    ptrToInformationForm_->show();
}

void MainWindow::on_pushButton_13_clicked()
{
    ptrToRecordGeneratorForm_ = std::make_unique<RecordGeneratorForm>();
    ptrToRecordGeneratorForm_->setPtrToMainWindow(this);
    ptrToRecordGeneratorForm_->show();
}

void MainWindow::on_pushButton_14_clicked()
{
    std::exit(0);
}
