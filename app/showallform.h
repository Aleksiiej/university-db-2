#ifndef SHOWALLFORM_H
#define SHOWALLFORM_H

#include <QDialog>

namespace Ui {
class ShowAllForm;
}

class ShowAllForm : public QDialog
{
    Q_OBJECT

public:
    explicit ShowAllForm(QWidget *parent = nullptr);
    ~ShowAllForm();

private:
    Ui::ShowAllForm *ui;
};

#endif // SHOWALLFORM_H
