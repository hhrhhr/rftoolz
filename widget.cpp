#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_toolButtonReloadActivationKey_clicked()
{
    QString keyG = ui->lineEditSimulatorKey->text();
    QString keyI = ui->lineEditControllerKey->text();
    emit keysChanged(keyG, keyI);

    quint32 serial = emit reloadActivationKey();

    QString actKey = QString::number(serial);

    ui->lineEditActivationKey->setText(actKey);
}
