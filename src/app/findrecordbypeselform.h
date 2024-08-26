#ifndef FINDRECORDBYPESELFORM_H
#define FINDRECORDBYPESELFORM_H

#include <QDialog>

class MainWindow;

namespace Ui {
class FindRecordByPeselForm;
}

class FindRecordByPeselForm : public QDialog
{
  Q_OBJECT

public:
  explicit FindRecordByPeselForm(QWidget* parent = nullptr);
  ~FindRecordByPeselForm();

  void appendTextToLabel(const QString& text);
  void setPtrToMainWindow(MainWindow* ptrToMainWindow);

private slots:
  void on_pushButton_clicked();
  void on_pushButton_2_clicked();

private:
  Ui::FindRecordByPeselForm* ui;
  MainWindow* ptrToMainWindow_;
};

#endif // FINDRECORDBYPESELFORM_H
