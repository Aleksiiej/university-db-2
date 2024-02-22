#ifndef SHOWALLFORM_H
#define SHOWALLFORM_H

#include <QDialog>

class MainWindow;

namespace Ui {
class ShowAllForm;
}

class ShowAllForm : public QDialog
{
    Q_OBJECT

public:
    explicit ShowAllForm(QWidget *parent = nullptr);
    ~ShowAllForm();

    void setPtrToMainWindow(std::shared_ptr<MainWindow> ptrToMainWindow);

private:
    std::unique_ptr<Ui::ShowAllForm> ui;
    std::shared_ptr<MainWindow> ptrToMainWindow_;
};

#endif // SHOWALLFORM_H
