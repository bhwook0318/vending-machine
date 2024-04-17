#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->coffee->setEnabled(false);
    ui->tea->setEnabled(false);
    ui->milk->setEnabled(false);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::add_money(int num)
{
    money += num;
    ui->lcdNumber->display(money);
    ui->coffee->setEnabled(100<=money);
    ui->tea->setEnabled(150<=money);
    ui->milk->setEnabled(200<=money);
}

void Widget::on_coin10_clicked()
{
    add_money(10);
}

void Widget::on_coin50_clicked()
{
    add_money(50);
}

void Widget::on_coin100_clicked()
{
    add_money(100);
}

void Widget::on_coin500_clicked()
{
    add_money(500);
}


void Widget::on_coffee_clicked()
{
    add_money(-100);
}


void Widget::on_tea_clicked()
{
    add_money(-150);
}


void Widget::on_milk_clicked()
{
    add_money(-200);
}

void Widget::on_reset_clicked()
{
    int coin[4] = {500, 100 , 50, 10};
    int cnt[4] = {0, 0, 0, 0};
    for(int i = 0; i < 4; i++)
    {
        cnt[i] = money / coin[i];
        money %= coin[i];
    }
    QString text = "500원 " + QString::number(cnt[0]) + "개, " + "100원 " + QString::number(cnt[1]) + "개, " + "50원 " + QString::number(cnt[2]) + "개, " + "10원 " + QString::number(cnt[3]) + "개";
    QMessageBox::information(this, "잔돈", text);
    add_money(0);
}

