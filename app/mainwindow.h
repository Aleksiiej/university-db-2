#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <memory>
#include "addrecordform.h"
#include "Database.hpp"
#include "showallform.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    friend class AddRecordForm;
    friend class ShowAllForm;

public:
    MainWindow(std::shared_ptr<Database> ptrToDatabase, QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

private:
    std::unique_ptr<Ui::MainWindow> ui;
    std::shared_ptr<Database> ptrToDatabase_;
    std::unique_ptr<AddRecordForm> ptrToAddRecordForm_;
    std::unique_ptr<ShowAllForm> ptrToShowAllForm_;
};
#endif // MAINWINDOW_H
