#ifndef ADDRECORDFORM_H
#define ADDRECORDFORM_H

#include <QDialog>
#include <memory.h>
#include "PESELValidator.hpp"

class MainWindow;

namespace Ui {
class AddRecordForm;
}

class AddRecordForm : public QDialog
{
    Q_OBJECT

public:
    explicit AddRecordForm(QWidget *parent = nullptr);
    ~AddRecordForm();

    void setPtrToMainWindow(MainWindow* ptrToMainWindow);

private slots:
    void on_pushButton_addrecord_clicked();
    void on_pushButton_close_clicked();
    void on_radioButton_student_clicked();
    void on_radioButton_employee_clicked();

private:
    std::unique_ptr<Ui::AddRecordForm> ui;
    MainWindow* ptrToMainWindow_;
    std::unique_ptr<PESELValidator> PESELValidatorPtr_;
};

#endif // ADDRECORDFORM_H
