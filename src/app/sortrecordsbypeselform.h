#ifndef SORTRECORDSBYPESELFORM_H
#define SORTRECORDSBYPESELFORM_H

#include <QDialog>

namespace Ui {
class SortRecordsByPeselForm;
}

class SortRecordsByPeselForm : public QDialog
{
  Q_OBJECT

public:
  explicit SortRecordsByPeselForm(QWidget* parent = nullptr);
  ~SortRecordsByPeselForm();

private slots:
  void on_pushButton_clicked();

private:
  Ui::SortRecordsByPeselForm* ui;
};

#endif // SORTRECORDSBYPESELFORM_H
