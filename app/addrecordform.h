#ifndef ADDRECORDFORM_H
#define ADDRECORDFORM_H

#include <QDialog>
#include <memory.h>

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
    std::unique_ptr<Ui::AddRecordForm> ui;
};

#endif // ADDRECORDFORM_H
