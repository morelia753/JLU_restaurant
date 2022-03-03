#ifndef ORDER_H
#define ORDER_H

#include <QDialog>
#include <QMessageBox>

namespace Ui {
class Order;
}

static QString Context;
class Order : public QDialog
{
    Q_OBJECT

public:

    explicit Order(int *num,int *price,int total,QWidget *parent = 0);
    void generate();
    ~Order();
signals:
    void exitChild();//新建一个信号槽
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();



private:
    Ui::Order *ui;

    QString _dishes[11];
    int _num[11];
    int _price[11];
    int _name;
    int _count;

};

#endif // ORDER_H
