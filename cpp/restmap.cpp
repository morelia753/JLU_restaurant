#include "restmap.h"
#include "ui_restmap.h"
#include "logindialog.h"
#include "menu.h"
#include <QMessageBox>
#include<QDebug>
#include<stdbool.h>
#include <QTimer>
#include <QDateTime>

RestMap::RestMap(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RestMap)
{

    ui->setupUi(this);
    //设置背景
    this->setStyleSheet("QWidget {background-image:url(:/new/bj/5.png)}");
    //提升窗口等级
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinimizeButtonHint);
}

RestMap::~RestMap()
{
    delete ui;
}



void RestMap::on_pushButton_clicked()
{
    this->hide();
    LoginDialog* log = new LoginDialog();
    log -> show();
}

void RestMap::on_pushButton_1_clicked()
{

    //截取餐桌状态
    QString str = ui->pushButton_1->text().section('\n',1,1);
    if(str == tr("空闲"))//下单
    {
        //更改餐桌状态
        ui->pushButton_1->setText("一号桌\n使用");
        QTimer *timer = new QTimer(this);
        connect(timer, SIGNAL(timeout()), this, SLOT(update()));
        timer->start(5000);
        Menu* m = new Menu(1);
        m->show();
    }else{//再次选桌
        QMessageBox msgBox;
        msgBox.setText("此餐桌正在使用，请另选餐桌！");
        msgBox.exec();

    }

}

void RestMap::on_pushButton_2_clicked()
{

    //截取餐桌状态
    QString str = ui->pushButton_2->text().section('\n',1,1);
    if(str == tr("空闲"))//下单
    {
        //更改餐桌状态
        ui->pushButton_1->setText("二号桌\n使用");
        Menu* m = new Menu(2);
        m->show();
    }else{//再次选桌
        QMessageBox msgBox;
        msgBox.setText("此餐桌正在使用，请另选餐桌！");
        msgBox.exec();

    }


}

void RestMap::on_pushButton_3_clicked()
{

    //截取餐桌状态
    QString str = ui->pushButton_3->text().section('\n',1,1);
    if(str == tr("空闲"))//下单
    {
        //更改餐桌状态
        ui->pushButton_3->setText("三号桌\n使用");
        Menu* m = new Menu(3);
        m->show();
    }else{//再次选桌
        QMessageBox msgBox;
        msgBox.setText("此餐桌正在使用，请另选餐桌！");
        msgBox.exec();

    }

}

void RestMap::on_pushButton_4_clicked()
{

    //截取餐桌状态
    QString str = ui->pushButton_4->text().section('\n',1,1);
    if(str == tr("空闲"))//下单
    {
        //更改餐桌状态
        ui->pushButton_4->setText("四号桌\n使用");
        Menu* m = new Menu(4);
        m->show();
    }else{//再次选桌
        QMessageBox msgBox;
        msgBox.setText("此餐桌正在使用，请另选餐桌！");
        msgBox.exec();

    }

}

void RestMap::on_pushButton_5_clicked()
{


    //截取餐桌状态
    QString str = ui->pushButton_5->text().section('\n',1,1);
    if(str == tr("空闲"))//下单
    {
        //更改餐桌状态
        ui->pushButton_5->setText("五号桌\n使用");
        Menu* m = new Menu(5);
        m->show();
    }else{//再次选桌
        QMessageBox msgBox;
        msgBox.setText("此餐桌正在使用，请另选餐桌！");
        msgBox.exec();

    }
}

void RestMap::on_pushButton_6_clicked()
{

    //截取餐桌状态
    QString str = ui->pushButton_6->text().section('\n',1,1);
    if(str == tr("空闲"))//下单
    {
        //更改餐桌状态
        ui->pushButton_6->setText("六号桌\n使用");
        Menu* m = new Menu(6);
        m->show();
    }else{//再次选桌
        QMessageBox msgBox;
        msgBox.setText("此餐桌正在使用，请另选餐桌！");
        msgBox.exec();

    }

}

