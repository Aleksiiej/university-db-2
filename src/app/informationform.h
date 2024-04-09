#ifndef INFORMATIONFORM_H
#define INFORMATIONFORM_H

#include <QDialog>

namespace Ui {
class InformationForm;
}

class InformationForm : public QDialog {
  Q_OBJECT

public:
  explicit InformationForm(QWidget *parent = nullptr);
  ~InformationForm();

  void setRecordCreationSuccesText();
  void setRecordCreationFailureText();
  void setSaveSuccesText();
  void setLoadSuccesText();

private slots:
  void on_pushButton_clicked();

private:
  Ui::InformationForm *ui;
};

#endif // INFORMATIONFORM_H
