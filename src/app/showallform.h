#ifndef SHOWALLFORM_H
#define SHOWALLFORM_H

#include <QDialog>

class MainWindow;

namespace Ui {
class ShowAllForm;
}

class ShowAllForm : public QDialog {
  Q_OBJECT

public:
  explicit ShowAllForm(QWidget *parent = nullptr);
  ~ShowAllForm();

  void appendTextToLabel(const QString &text);
  void setPtrToMainWindow(MainWindow *ptrToMainWindow);

private slots:
  void on_pushButton_clicked();
  void on_pushButton_2_clicked();

private:
  std::unique_ptr<Ui::ShowAllForm> ui;
  MainWindow *ptrToMainWindow_;
};

#endif // SHOWALLFORM_H
