#ifndef MODIFYSALARYINEMPLOYEERECORDFORM_H
#define MODIFYSALARYINEMPLOYEERECORDFORM_H

#include <QDialog>

class MainWindow;

namespace Ui
{
class ModifySalaryInEmployeeRecordForm;
}

class ModifySalaryInEmployeeRecordForm : public QDialog
{
    Q_OBJECT

  public:
    explicit ModifySalaryInEmployeeRecordForm(QWidget *parent = nullptr);
    ~ModifySalaryInEmployeeRecordForm();

    void setPtrToMainWindow(MainWindow *ptrToMainWindow);

  private slots:
    void on_pushButton_clicked();

  private:
    Ui::ModifySalaryInEmployeeRecordForm *ui;
    MainWindow *ptrToMainWindow_;
};

#endif // MODIFYSALARYINEMPLOYEERECORDFORM_H
