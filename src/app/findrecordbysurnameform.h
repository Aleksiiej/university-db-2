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

  void setPtrToMainWindow(MainWindow *ptrToMainWindow);

private:
  std::unique_ptr<Ui::FindRecordBySurnameForm> ui;
  MainWindow *ptrToMainWindow_;
};

#endif // FINDRECORDBYSURNAMEFORM_H
