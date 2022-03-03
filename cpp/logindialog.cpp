#include "logindialog.h"
#include "restmap.h"
#include "ui_logindialog.h"

#include <QDialogButtonBox>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QPixmap>

LoginDialog::LoginDialog(QWidget *parent) ://构造函数
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    //设置背景
    this->setStyleSheet("QWidget {background-image:url(:/new/bj/19.png)}");
}

LoginDialog::~LoginDialog()//析构函数
{
    delete ui;
}

void LoginDialog::on_pushButton_clicked()
{
    //添加数据库驱动
    QSqlDatabase db;
    if(QSqlDatabase::contains("qt_sql_default_connection"))//默认的连接名是否存在
      db = QSqlDatabase::database("qt_sql_default_connection");
    else //默认连接名不存在，头次连接
      db = QSqlDatabase::addDatabase("QSQLITE");
    //设置数据库名称
    db.setDatabaseName("user.db");
    //打开数据库
    if(!db.open())
    {
        //打开失败
        QMessageBox::critical(this, "错误", "数据库访问错误！");
        return;
    }

    //以下执行相关sql语句
    QSqlQuery query;

    //判断user表是否存在
    if(!IsTableExist(query, "user")){
//        //新建user表，id设置为主键
//        query.exec("create table user(_id INTEGER PRIMARY KEY AUTOINCREMENT, username varchar, password varchar, name varchar)");
        QMessageBox::critical(this, "错误", "没有注册用户，请先注册再登录！");
        return;
    }
    //查找用户名及密码
    query.exec("select * from user where username='" + ui->lineEdit->text() + "' and password='" + ui->lineEdit_2->text() + "'");
    if(query.next()){
        RestMap *m = new RestMap();
        m->show();  //跳到RestMap页面
        this->hide();
    }else{
        QMessageBox::critical(this, "错误", "没有注册用户，请先注册再登录！");
    }
}

void LoginDialog::on_pushButton_2_clicked()//注册用户
{
    QDialog dialog(this);
    QFormLayout layout(&dialog);
    QLabel usernameLabel(&dialog);
    usernameLabel.setText("用户名");
    QLabel passwordLabel(&dialog);
    passwordLabel.setText("密码");

    QLabel nameLabel(&dialog);
    nameLabel.setText("姓名");
    QLineEdit usernameLineEdit(&dialog);
    QLineEdit passwordLineEdit(&dialog);
    QLineEdit nameLineEdit(&dialog);

    QDialogButtonBox box(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, Qt::Horizontal, &dialog);
    layout.addRow(&usernameLabel, &usernameLineEdit);
    layout.addRow(&passwordLabel, &passwordLineEdit);
    layout.addRow(&nameLabel, &nameLineEdit);
    layout.addRow(&box);
    connect(&box, SIGNAL(accepted()), &dialog, SLOT(accept()));
    connect(&box, SIGNAL(rejected()), &dialog, SLOT(reject()));
    if(dialog.exec() == QDialog::Accepted){
        //添加数据库驱动
        QSqlDatabase db;
        if(QSqlDatabase::contains("qt_sql_default_connection"))//默认的连接名是否存在
          db = QSqlDatabase::database("qt_sql_default_connection");
        else //默认连接名不存在，头次连接
          db = QSqlDatabase::addDatabase("QSQLITE");

        //设置数据库名称
        db.setDatabaseName("user.db");
        //打开数据库
        if(!db.open())
        {
            QMessageBox::critical(this, "错误", "数据库访问错误！");
            return;
        }

        //以下执行相关sql语句
        QSqlQuery query;

        //判断user表是否存在
        if(!IsTableExist(query, "user")){
            //新建user表，id设置为主键
            query.exec("create table user(_id INTEGER PRIMARY KEY AUTOINCREMENT, username varchar, password varchar, name varchar)");
        }
        // 添加记录
        query.exec("insert into user values(null,'" + usernameLineEdit.text() + "','" + passwordLineEdit.text() + "','" + nameLineEdit.text() + "')");
    }
}
bool LoginDialog::IsTableExist(QSqlQuery &query,QString table) //判断user表是否存在
{
    QString sql = QString("select * from sqlite_master where name='%1'").arg(table);
    query.exec(sql);
    return query.next();
}
