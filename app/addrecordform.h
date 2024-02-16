#ifndef ADDRECORDFORM_H
#define ADDRECORDFORM_H

#include <QDialog>

namespace Ui {
class AddRecordForm;
}

class AddRecordForm : public QDialog
{
    Q_OBJECT

public:
    explicit AddRecordForm(QWidget *parent = nullptr);
    ~AddRecordForm();

private slots:
    void on_pushButton_addrecord_clicked();

private:
    Ui::AddRecordForm *ui;
};

#endif // ADDRECORDFORM_H
