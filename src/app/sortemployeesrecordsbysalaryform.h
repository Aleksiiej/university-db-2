#ifndef SORTEMPLOYEESRECORDSBYSALARYFORM_H
#define SORTEMPLOYEESRECORDSBYSALARYFORM_H

#include <QDialog>

class MainWindow;

namespace Ui {
class SortEmployeesRecordsBySalaryForm;
}

class SortEmployeesRecordsBySalaryForm : public QDialog {
  Q_OBJECT

public:
  explicit SortEmployeesRecordsBySalaryForm(QWidget *parent = nullptr);
  ~SortEmployeesRecordsBySalaryForm();

  void appendTextToLabel(const QString &text);
  void setPtrToMainWindow(MainWindow *ptrToMainWindow);

private slots:
  void on_pushButton_clicked();

private:
  Ui::SortEmployeesRecordsBySalaryForm *ui;
  MainWindow *ptrToMainWindow_;
};

#endif // SORTEMPLOYEESRECORDSBYSALARYFORM_H
