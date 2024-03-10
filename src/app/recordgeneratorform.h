#ifndef RECORDGENERATORFORM_H
#define RECORDGENERATORFORM_H

#include <QDialog>

namespace Ui {
class recordgeneratorform;
}

class recordgeneratorform : public QDialog {
  Q_OBJECT

public:
  explicit recordgeneratorform(QWidget *parent = nullptr);
  ~recordgeneratorform();

private:
  Ui::recordgeneratorform *ui;
};

#endif // RECORDGENERATORFORM_H
