#ifndef REMOVESTUDENTRECORDBYINDEXFORM_H
#define REMOVESTUDENTRECORDBYINDEXFORM_H

#include <QDialog>

class MainWindow;

namespace Ui
{
class RemoveStudentRecordByIndexForm;
}

class RemoveStudentRecordByIndexForm : public QDialog
{
    Q_OBJECT

  public:
    explicit RemoveStudentRecordByIndexForm(QWidget *parent = nullptr);
    ~RemoveStudentRecordByIndexForm();

    void setPtrToMainWindow(MainWindow *ptrToMainWindow);

  private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

  private:
    Ui::RemoveStudentRecordByIndexForm *ui;
    MainWindow *ptrToMainWindow_;
};

#endif // REMOVESTUDENTRECORDBYINDEXFORM_H
