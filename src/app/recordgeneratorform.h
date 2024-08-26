#ifndef RECORDGENERATORFORM_H
#define RECORDGENERATORFORM_H

#include <QDialog>

#include "informationform.h"

class MainWindow;

namespace Ui
{
class RecordGeneratorForm;
}

class RecordGeneratorForm : public QDialog
{
    Q_OBJECT

  public:
    explicit RecordGeneratorForm(QWidget *parent = nullptr);
    ~RecordGeneratorForm();

    void setPtrToMainWindow(MainWindow *ptrToMainWindow);

  private slots:
    void on_generate_records_pushButton_clicked();
    void on_close_pushButton_2_clicked();

  private:
    std::unique_ptr<Ui::RecordGeneratorForm> ui;
    MainWindow *ptrToMainWindow_;
    std::unique_ptr<InformationForm> ptrToInformationForm_;
};

#endif // RECORDGENERATORFORM_H
