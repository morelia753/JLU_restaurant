#ifndef RESTMAP_H
#define RESTMAP_H


#include <QDialog>

namespace Ui {
class RestMap;
}


class RestMap : public QDialog
{
    Q_OBJECT

public:

    explicit RestMap(QWidget *parent = 0);
    ~RestMap();

private slots:

    //定时器


    void on_pushButton_clicked();


    void on_pushButton_1_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

private:
    Ui::RestMap *ui;

};


#endif // RESTMAP_H
