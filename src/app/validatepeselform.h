#ifndef VALIDATEPESELFORM_H
#define VALIDATEPESELFORM_H

#include "PESELValidator.hpp"
#include <QDialog>

class MainWindow;

namespace Ui {
class ValidatePeselForm;
}

class ValidatePeselForm : public QDialog {
  Q_OBJECT

public:
  explicit ValidatePeselForm(QWidget *parent = nullptr);
  ~ValidatePeselForm();

  void setPtrToMainWindow(MainWindow *ptrToMainWindow);

private slots:
  void on_pushButton_clicked();

  void on_pushButton_2_clicked();

private:
  Ui::ValidatePeselForm *ui;
  MainWindow *ptrToMainWindow_;
  std::unique_ptr<PESELValidator> PESELValidatorPtr_;
};

#endif // VALIDATEPESELFORM_H