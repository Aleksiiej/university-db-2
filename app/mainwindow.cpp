#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(std::shared_ptr<Database> ptrToDatabase, QWidget *parent)
    : QMainWindow(parent)
    , ui(std::make_unique<Ui::MainWindow>())
    , ptrToDatabase_(ptrToDatabase)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
}

void MainWindow::on_pushButton_clicked()
{
    ptrToAddRecordForm_ = std::make_unique<AddRecordForm>(this);
    ptrToAddRecordForm_->setPtrToMainWindow(this);
    ptrToAddRecordForm_->show();
}


void MainWindow::on_pushButton_2_clicked()
{
    ptrToShowAllForm_ = std::make_unique<ShowAllForm>(this);
    ptrToShowAllForm_->setPtrToMainWindow(this);
    ptrToShowAllForm_->show();
}


void MainWindow::on_pushButton_3_clicked()
{

}


void MainWindow::on_pushButton_4_clicked()
{

}


void MainWindow::on_pushButton_5_clicked()
{

}


void MainWindow::on_pushButton_6_clicked()
{

}


void MainWindow::on_pushButton_7_clicked()
{

}


void MainWindow::on_pushButton_8_clicked()
{

}


void MainWindow::on_pushButton_9_clicked()
{

}


void MainWindow::on_pushButton_10_clicked()
{

}


void MainWindow::on_pushButton_11_clicked()
{

}


void MainWindow::on_pushButton_12_clicked()
{

}


void MainWindow::on_pushButton_13_clicked()
{

}


void MainWindow::on_pushButton_14_clicked()
{
    std::exit(0);
}

