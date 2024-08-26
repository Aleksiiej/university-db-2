#ifndef SORTRECORDSBYSURNAMEFORM_H
#define SORTRECORDSBYSURNAMEFORM_H

#include <QDialog>

namespace Ui {
class SortRecordsBySurnameForm;
}

class SortRecordsBySurnameForm : public QDialog
{
  Q_OBJECT

public:
  explicit SortRecordsBySurnameForm(QWidget* parent = nullptr);
  ~SortRecordsBySurnameForm();

private slots:
  void on_pushButton_clicked();

private:
  Ui::SortRecordsBySurnameForm* ui;
};

#endif // SORTRECORDSBYSURNAMEFORM_H
