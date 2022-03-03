#include "chef.h"
#include "ui_chef.h"

Chef::Chef(QString& context,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Chef)
{
    ui->setupUi(this);
    //提升窗口等级
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinimizeButtonHint);
    //后厨端读入数据
    ui->textBrowser->insertPlainText(context);
}

Chef::~Chef()
{
    delete ui;
}

void Chef::on_pushButton_clicked()//关闭
{
    this->close();
}
