#ifndef FINDRECORDBYSURNAMEFORM_H
#define FINDRECORDBYSURNAMEFORM_H

#include <QDialog>

class MainWindow;

namespace Ui {
class FindRecordBySurnameForm;
}

class FindRecordBySurnameForm : public QDialog {
  Q_OBJECT

public:
  explicit FindRecordBySurnameForm(QWidget *parent = nullptr);
  ~FindRecordBySurnameForm();

  void appendTextToLabel(const QString &text);
  void setPtrToMainWindow(MainWindow *ptrToMainWindow);

private slots:
  void on_pushButton_clicked();
  void on_pushButton_2_clicked();

private:
  std::unique_ptr<Ui::FindRecordBySurnameForm> ui;
  MainWindow *ptrToMainWindow_;
};

#endif // FINDRECORDBYSURNAMEFORM_H
