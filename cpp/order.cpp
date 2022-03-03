#include "order.h"
#include "ui_order.h"
#include"restmap.h"
#include "logindialog.h"
#include "menu.h"
#include "chef.h"


Order::Order(int *num,int *price,int total,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Order)
{
    ui->setupUi(this);
    //提升窗口等级
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinimizeButtonHint);
    //设置背景
    this->setStyleSheet("QWidget {background-image:url(:/new/bj/6.png)}");
    //设置参数
    //ui->label_1->setText(name+"的订单");
    _count = 0;
    for(int i = 1;i<=10;i++){
        _price[i] = price[i];
        _num[i] = num[i];
        if(_num[i])
            _count++;
    }
    _dishes[1] = "醋溜白菜";
    _dishes[2] = "麻婆豆腐";
    _dishes[3] = "宫保鸡丁";
    _dishes[4] = "干锅菜花";
    _dishes[5] = "鱼香肉丝";
    _dishes[6] = "水煮肉片";
    _dishes[7] = "酸辣土豆丝";
    _dishes[8] = "蒜蓉油麦菜";
    _dishes[9] = "干煸四季豆";
    _dishes[10] = "沸腾水煮鱼";
    generate();
    ui->label_3->setText("总计："+QString::number(total));
}

Order::~Order()
{
    delete ui;
}

void Order::generate()
{
    //自适应
    ui->textBrowser->setGeometry(50,90,231,23.9*_count);
    ui->label_2->setGeometry(50,ui->textBrowser->pos().y()+55+24*_count,231,40);
    ui->label_3->setGeometry(140,99+24*_count,160,40);
    ui->pushButton->setGeometry(210,ui->label_2->pos().y()+60,90,30);
    ui->pushButton_2->setGeometry(40,ui->label_2->pos().y()+60,90,30);
    this->setGeometry(600,300,331,260+24*_count);


    QString context = "";
    for(int i = 1;i<=10;i++)
        if(_num[i])
        {
            context +=_dishes[i]+"   *"+QString::number(_num[i])+"      "+QString::number(_num[i]*_price[i])+"元\n";
        }

    _count /= 1.3;

    context += "米饭(赠送)  *"+QString::number(_count)+"       0元\n";
    //Context += context;
    ui->textBrowser->setText(context);

}


//返回菜单
void Order::on_pushButton_clicked()
{

    this->close();
    emit exitChild();
}
//确定订单
void Order::on_pushButton_2_clicked()
{

    this->hide();
    QMessageBox::about(this,tr("提示信息"),tr("请稍后,您的菜正在烹饪中~"));
    //关闭选菜页面
    //close();

}


