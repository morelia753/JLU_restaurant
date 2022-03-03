#ifndef MENU_H
#define MENU_H

#include <QDialog>
#include"order.h"
#include <QMessageBox>
#include <QSqlQuery>
namespace Ui {
class Menu;
}

class Menu : public QDialog
{
    Q_OBJECT

public:
    //void create_table(QString& desk,QString& foods);//创建点餐数据表

    //bool IsTableExist(QSqlQuery &query,QString table);

    //QString Context;
    explicit Menu(int desk,QWidget *parent = 0);
    void start();
    ~Menu();

private slots:
    //20个button（-|+）的槽函数
    void on_pushButton_l11_clicked();

    void on_pushButton_l12_clicked();

    void on_pushButton_r11_clicked();

    void on_pushButton_r12_clicked();

    void on_pushButton_l21_clicked();

    void on_pushButton_l22_clicked();

    void on_pushButton_r21_clicked();

    void on_pushButton_r22_clicked();

    void on_pushButton_l31_clicked();

    void on_pushButton_l32_clicked();

    void on_pushButton_r31_clicked();

    void on_pushButton_r32_clicked();

    void on_pushButton_l41_clicked();

    void on_pushButton_l42_clicked();

    void on_pushButton_r41_clicked();

    void on_pushButton_r42_clicked();

    void on_pushButton_l51_clicked();

    void on_pushButton_l52_clicked();

    void on_pushButton_r51_clicked();

    void on_pushButton_r52_clicked();

    int calculateMoney();
    void on_pushButton_e1_2_clicked();

    void on_pushButton_e1_clicked();
    void on_pushButton_clicked();


    void on_pushButton_2_clicked();

private:
    Ui::Menu *ui;
    QString _dishes[11];
    int _price[11];
    int _num[11];
    int _desk;
    Order *_order;
    int _total;
};

#endif // MENU_H
