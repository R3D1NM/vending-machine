#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->pbCoffee->setEnabled(false);
    ui->pbTea->setEnabled(false);
    ui->pbMilk->setEnabled(false);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeMoney(int diff){
    if(money+diff<0) return;
    money += diff;
    ui->lcdNumber->display(money);
    if(money>=100) ui->pbCoffee->setEnabled(true);
    if(money>=150) ui->pbTea->setEnabled(true);
    if(money>=200) ui->pbMilk->setEnabled(true);
}

void Widget::on_pb10_clicked()
{
    changeMoney(10);
}


void Widget::on_pb50_clicked()
{
    changeMoney(50);
}


void Widget::on_pb100_clicked()
{
    changeMoney(100);
}


void Widget::on_pb500_clicked()
{
    changeMoney(500);
}


void Widget::on_pbCoffee_clicked()
{
    changeMoney(-100);
}


void Widget::on_pbTea_clicked()
{
    changeMoney(-150);
}


void Widget::on_pbMilk_clicked()
{
    changeMoney(-200);
}


void Widget::on_pbReset_clicked()
{
    QMessageBox mb;
    QString changeMessage;
    int coins[4] = {10, 50, 100, 500};
    int changes[4] ={0, 0, 0, 0};

    for (int i = 3; i >= 0; i--){
        changes[i]=money/coins[i];
        money%=coins[i];
    }

    for (int i = 0; i < 4; i++){
        changeMessage += QString::number(coins[i]) +" : " + QString::number(changes[i])+"\n";
    }

    mb.information(this,"Change",changeMessage);
}

