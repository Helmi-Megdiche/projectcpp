#include "messengerconnection.h"
#include "ui_messengerconnection.h"

MessengerConnection::MessengerConnection(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MessengerConnection)
{
    ui->setupUi(this);
}

MessengerConnection::~MessengerConnection()
{
    delete ui;
}

void MessengerConnection::on_ok_clicked()
{
mHostname=ui->hostname->text();
mPort=ui->port->value();
accept();
}

void MessengerConnection::on_cancel_clicked()
{
 reject();
}

