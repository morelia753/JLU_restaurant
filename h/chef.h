#ifndef CHEF_H
#define CHEF_H

#include <QDialog>

namespace Ui {
class Chef;
}

class Chef : public QDialog
{
    Q_OBJECT

public:
    explicit Chef(QString& context, QWidget *parent = nullptr);
    ~Chef();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Chef *ui;

};

#endif // CHEF_H
